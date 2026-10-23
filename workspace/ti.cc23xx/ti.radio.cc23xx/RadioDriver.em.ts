import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@ti.distro.cc23xx/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as Idle from '@ti.mcu.cc23xx/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LRF from '@ti.radio.cc23xx/LRF.em'
import * as Mem from '@em.utils/Mem.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as RfCtrl from '@ti.radio.cc23xx/RfCtrl.em'
import * as RfFifo from '@ti.radio.cc23xx/RfFifo.em'
import * as RfFreq from '@ti.radio.cc23xx/RfFreq.em'
import * as RfPatch from '@ti.radio.cc23xx/RfPatch.em'
import * as RfPower from '@ti.radio.cc23xx/RfPower.em'
import * as RfRegs from '@ti.radio.cc23xx/RfRegs.em'
import * as RfTrim from '@ti.radio.cc23xx/RfTrim.em'
import * as RfXtal from '@ti.radio.cc23xx/RfXtal.em'
import * as Rtc from '@ti.mcu.cc23xx/Rtc.em'
import * as TL from '@em.link/Types.em'

enum State {
    IDLE, SETUP, READY, RX, TX, CS, CW
}

// TEMP diagnostic: immediate RX while checking reception during foreground ECDH.
export const scheduled_rx = $config<bool_t>(false)
// TEMP isolation test: retain powered radio between completed events.
export const retain_radio = $config<bool_t>(false)

const handler = $config<RadioDriverI.Handler>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('LRFD_IRQ0')
    }
    export function bindHandler(h: RadioDriverI.Handler) {
        handler.$$val = h
    }
}

//>> ---- em$targ ---- <<//

const TX_CHAIN_DELAY = 47
// Allow synthesizer/RX ramp-up before the controller's receive-ready target.
// Conservative initial allowance; retain the controller's separate 50 us lead.
const RX_RAMP_GUARD_US = 200
// TI RCL_Scheduler uses a 50 us future trigger for start-now commands.
const RX_IMMEDIATE_LEAD_US = 50
const RX_SCHEDULE_MIN_US = RX_IMMEDIATE_LEAD_US
const RX_SCHEDULE_MAX_US = 10000

var cur_chan: u8
var cur_params: $$<TL.Params>
var cur_rx_buf: TL.BufPtr
var cur_state: volatile_t<State> = State.IDLE
var pause_handler: RadioDriverI.Handler = $null
var rx_end_time: u32
var rx_timeout: volatile_t<bool_t> = false
var tx_chained = false
var tx_start = 0
var enable_notify: bool_t

export function disable() {
    const key = GlobalInterrupts.disable()
    const can_retain = retain_radio && cur_state != State.IDLE && cur_state != State.SETUP
    setState(State.IDLE)
    enable_notify = false
    pause_handler = $null
    tx_chained = false
    Rtc.disableAux()
    IntrVec.NVIC_disable(e$`LRFD_IRQ0_IRQn`)
    $R.LRFDDBELL.IMASK0.$$ = 0
    $R.LRFDDBELL.ICLR0.$$ = 0xffff_ffff
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    if (can_retain) {
        // Leave clocks/crystal and radio configuration alive. startRx/startTx
        // still initialize the engines and program the next channel.
        setState(State.READY)
        $['%%c-']
        $['%%d-']
        Idle.setLevel(1) // prevent standby from undoing the diagnostic retention
        GlobalInterrupts.restore(key)
        return
    }
    RfCtrl.disable()
    RfXtal.disable()
    $['%%c-']
    $['%%d-']
    Idle.setLevel(0)
    GlobalInterrupts.restore(key)
}

// Legacy foreground entry point. The controller uses startEnable(), never this wait.
export function enable() {
    beginEnable(false)
    waitReady()
}

function beginEnable(notify: bool_t) {
    const key = GlobalInterrupts.disable()
    cur_params = Registry.getParams()
    if (cur_params.$$.radio_phy != TL.Phy.BLE_1M
        || cur_params.$$.ble_rx_encrypted || cur_params.$$.ble_tx_encrypted) {
        printf`TI RadioDriver supports nonsecure BLE_1M only\n`()
        fail()
    }
    enable_notify = notify
    Idle.setLevel(1) // retain radio RAM/clocks until disable(), including crystal startup
    if (cur_state == State.IDLE) {
        setState(State.SETUP)
        RfXtal.start($cb(hfReadyHandler))
        RfCtrl.enableClocks()
        RfCtrl.resetBlocks()
        RfPatch.loadAll()
        // CPUIRQ3 cannot enter the ready callback until this setup is complete.
    } else {
        configureProfile()
        setState(State.READY)
        if (notify && handler != $null) handler()
    }
    GlobalInterrupts.restore(key)
}

function hfReadyHandler() {
    if (cur_state != State.SETUP) return
    RfRegs.setup()
    // Each enable starts a fresh receive operation. Standby used to hide
    // retained FIFO state; reset explicitly while PBE is still stopped.
    // Preserve the profile's RX auto-deallocation configuration.
    $R.LRFDPBE.FCMD.$$ = $R.LRFDPBE_FCMD_DATA_RXFIFO_RESET >> $R.LRFDPBE_FCMD_DATA_S
    RfTrim.apply()
    configureProfile()
    setState(State.READY)
    if (enable_notify && handler != $null) handler()
}

function configureProfile() {
    const acc_adr = cur_params.$$.ble_acc_adr
    const crc_init = cur_params.$$.ble_crc_init
    $reg32[$R.LRFDRFE_BASE + $R.LRFDRFE_O_RSSI] = 127
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD] = <u16>(($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD) & 0x0FFF) >> 2
    $reg32[$R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA] = acc_adr != 0 ? acc_adr : 0x8E89_BED6
    $reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_CRCINITL] = (crc_init != 0 ? crc_init : 0x555555) << 8
}

export function getRxBuf(): TL.BufPtr {
    return rx_timeout ? $null : cur_rx_buf
}

export function getRxEndTimeUs(): u32 {
    return rx_end_time
}

export function nowTimeUs(): u32 {
    return Rtc.getRawUsecs()
}

export function pause(usecs: u32, handler: RadioDriverI.Handler) {
    pause_handler = handler
    Rtc.enableAuxUsecs(Rtc.getRawUsecs() + usecs, $cb(rtcHandler))
}

export function startEnable() {
    beginEnable(true)
}

export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16) {
    const key = GlobalInterrupts.disable()
    setState(State.RX)
    cur_rx_buf = buf
    cur_chan = chan
    RfCtrl.enableImages()
    rx_timeout = false
    rx_end_time = 0
    const whiten_init = chan | 0x40
    let op = 0
    // cur_phy
    // const keep_fs = cur_params.$$.ble_chain != $null
    const cfg_val: u32 =
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RXFILTEROP_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_RXINCLUDEHDR_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATNOK_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_START_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_FS_NOCAL_S) |
        // ((keep_fs ? 1 : 0) << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_NEXTOP_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_IFSPERIOD_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATOK_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RFINTERVAL_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] = <u16>cfg_val
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_WHITEINIT] = whiten_init
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_MAXLEN] = 256 // TODO
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_RXTIMEOUT] = 0
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_FIRSTRXTIMEOUT] = 0
    let demc1be1 = $R.LRFDMDM.DEMC1BE1.$$
    demc1be1 = (demc1be1 & ~$R.LRFDMDM_DEMC1BE1_THRESHOLDB_M) | (0x7F << $R.LRFDMDM_DEMC1BE1_THRESHOLDB_S)
    $R.LRFDMDM.DEMC1BE1.$$ = demc1be1
    op = $R.PBE_GENERIC_REGDEF_API_OP_RX
    RfFreq.program(Channel.getFrequency(chan))
    $R.LRFDDBELL.ICLR0.$$ = 0xffff_ffff
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    $R.LRFDDBELL.IMASK0.$$ =
        LRF.EventOpDone |
        LRF.EventOpError |
        LRF.EventRxCtrl |
        LRF.EventRxNok |
        LRF.EventRxIgnored |
        LRF.EventRxEmpty |
        LRF.EventRxBufFull |
        LRF.EventRxOk |
        (timeout > 0 ? LRF.EventSystim1 : 0)
    // $R.LRFDDBELL.IMASK0.$$ = LRF.EventOpDone | LRF.EventOpError | LRF.EventRxOk | LRF.EventSystim1
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    // RTC and SYSTIM have different epochs. Translate only the remaining
    // interval, with signed subtraction to handle wrapping microsecond time.
    const now_us = nowTimeUs()
    const now_ticks = $R.SYSTIM.TIME250N.$$
    // Submit the RX command before its start trigger can fire.
    let rx_start_ticks = now_ticks + (RX_IMMEDIATE_LEAD_US * 4)
    if (scheduled_rx && cur_params.$$.ble_acc_adr != 0 && cur_params.$$.ble_rx_start_valid) {
        const remaining = <i32>(cur_params.$$.ble_rx_start_us - now_us) - RX_RAMP_GUARD_US
        if (remaining >= RX_SCHEDULE_MIN_US && remaining <= RX_SCHEDULE_MAX_US) {
            rx_start_ticks = now_ticks + (<u32>remaining * 4)
        }
    }
    // PBE waits for this hardware trigger; the CPU need not busy-wait.
    $R.SYSTIM.CH2CC.$$ = rx_start_ticks
    if (timeout > 0) {
        $R.LRFDDBELL.ICLR0.$$ = $R.LRFDDBELL_ICLR0_SYSTIM1_M
        $R.SYSTIM.CH3CC.$$ = rx_start_ticks + (<u32>timeout * 4000)
    }

    $['%%c+'] // TEMP: RX submitted through receive/timeout interrupt
    $R.LRFDPBE.API.$$ = op

    GlobalInterrupts.restore(key)

}

export function startTx(buf: TL.BufFrame, chan: u8) {
    const key = GlobalInterrupts.disable()
    $['%%d+'] // TEMP: TX preparation through completion interrupt
    setState(State.TX)
    cur_chan = chan

    RfFifo.writePkt(buf, cur_params.$$.ble_acc_adr != 0)
    RfPower.program(cur_params.$$.radio_power)
    RfCtrl.enableImages()
    let op = 0
    const whiten_init = chan | 0x40
    // cur_phy
    op = $R.PBE_GENERIC_REGDEF_API_OP_TX
    const keep_fs = cur_params.$$.ble_chain != $null
    const cfg_val =
        (0 << $R.PBE_GENERIC_RAM_OPCFG_TXINFINITE_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_TXPATTERN_S) |
        (2 << $R.PBE_GENERIC_RAM_OPCFG_TXFCMD_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_START_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_FS_NOCAL_S) |
        ((keep_fs ? 1 : 0) << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATOK_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_NEXTOP_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_IFSPERIOD_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RFINTERVAL_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] = cfg_val
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_WHITEINIT] = whiten_init
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
    if (!tx_chained) {
        RfFreq.program(Channel.getFrequency(chan))
    }
    $R.LRFDDBELL.ICLR0.$$ = 0xffff_ffff
    $R.LRFDDBELL.IMASK0.$$ = LRF.EventOpDone | LRF.EventOpError
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = tx_chained ? tx_start : $R.SYSTIM.TIME250N.$$
    $R.LRFDPBE.API.$$ = op
    tx_chained = false
    GlobalInterrupts.restore(key)
}

export function waitReady() {
    while (true) {
        const key = GlobalInterrupts.disable()
        if (cur_state == State.READY) {
            GlobalInterrupts.restore(key)
            break
        }
        Idle.exec()
        GlobalInterrupts.restore(key)
    }
}

export function LRFD_IRQ0_isr$$() {
    const mis = $R.LRFDDBELL.MIS0.$$
    $R.LRFDDBELL.ICLR0.$$ = mis
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    switch (cur_state) {
        case State.RX: {
            if ((mis & LRF.EventSystim1) != 0 && (mis & LRF.EventRxOk) == 0) {
                $['%%c-']
                rx_timeout = true
                break
            }
            if ((mis & LRF.EventOpError) != 0) {
                const cause = $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_ENDCAUSE]
                printf`OpError: %04x\n`(cause)
                printf`FCFG0: %08x\n`($R.LRFDPBE.FCFG0.$$)
                printf`RXFRP: %08x\n`($R.LRFDPBE.RXFRP.$$)
                printf`RXFWP: %08x\n`($R.LRFDPBE.RXFWP.$$)
                printf`RXFREADABLE: %08x\n`($R.LRFDPBE.RXFREADABLE.$$)
                printf`RXFWRITABLE: %08x\n`($R.LRFDPBE.RXFWRITABLE.$$)
                fail()
            }
            if ((mis & LRF.EventRxOk) == 0) {
                return
            }
            rx_end_time = nowTimeUs()
            tx_start = $R.SYSTIM.TIME250N.$$ + (TX_CHAIN_DELAY * 4)
            $['%%c-']
            if (RfFifo.readPkt(cur_rx_buf, cur_params.$$.ble_acc_adr != 0) == 0) {
                cur_rx_buf = $null
                break
            }
            if (cur_params.$$.ble_chain != $null) {
                const tx_buf = cur_params.$$.ble_chain(cur_rx_buf)
                if (tx_buf != $null) {
                    tx_chained = true
                    startTx(tx_buf, cur_chan)
                    return
                }
            }
            break
        }
        case State.TX: {
            if ((mis & LRF.EventOpError) != 0) {
                const cause = $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_ENDCAUSE]
                $['%%>'](cause)
                fail()
            }


            if ((mis & LRF.EventOpDone) == 0) {
                return
            }
            $['%%d-']
            if (cur_params.$$.ble_exch_buf != $null) {
                startRx(cur_params.$$.ble_exch_buf, cur_chan, cur_params.$$.ble_exch_end_ms)
                return
            }
            break
        }
        default: {
            return
        }
    }
    $R.LRFDDBELL.IMASK0.$$ = 0
    setState(State.READY)
    if (handler != $null) handler()
}

function rtcHandler() {
    Rtc.disableAux()
    if (pause_handler != $null) {
        const h = pause_handler
        pause_handler = $null
        h()
        return
    }
}

function setState(s: State) {
    // $['%%>'](s)
    cur_state = s
}
