import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as Channel from '@em.link.ble/Channel.em'
import * as Common from '@em.mcu/Common.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'

import * as Registry from '@em.link/Registry.em'
import * as TL from '@em.link/Types.em'
import * as Idle from '@ti.mcu.cc27xx/Idle.em'
import * as RfCtrl from '@ti.radio.cc27xx/RfCtrl.em'
import * as RfFifo from '@ti.radio.cc27xx/RfFifo.em'
import * as RfFreq from '@ti.radio.cc27xx/RfFreq.em'
import * as RfPatch from '@ti.radio.cc27xx/RfPatch.em'
import * as RfPower from '@ti.radio.cc27xx/RfPower.em'
import * as RfRegs from '@ti.radio.cc27xx/RfRegs.em'
import * as RfTrim from '@ti.radio.cc27xx/RfTrim.em'
import * as Rtc from '@ti.mcu.cc27xx/Rtc.em'
import * as RfXtal from '@ti.radio.cc27xx/RfXtal.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

const handler = $config<RadioDriverI.Handler>()
const pause_fiber = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('LRFD_IRQ0')
        pause_fiber.$$val = FiberMgr.em$meta.create($cb(pauseFB))
    }
    export function bindHandler(h: RadioDriverI.Handler) {
        handler.$$val = h
    }
}

enum State { OFF, READY, TX, RX }
var state: volatile_t<State> = State.OFF
var prepared: TL.BufFrame = $null
var old_ipeak: u32
var prepared_tx_power: u16
var rx_connected: bool_t
var tx_channel: u8
var cur_params: $$<TL.Params>
var cur_rx_buf: TL.BufPtr = $null
var rx_timeout: bool_t
var rx_end_time: u32
var tx_chained: bool_t = false
var tx_start: u32
var pause_handler: RadioDriverI.Handler = $null
const EVENT_RX_OK = 1 << 8
const EVENT_TIMEOUT = 1 << 30
// CC23xx scan-response timing; phone scan responses verified on CC27xx.
const TX_CHAIN_DELAY_US = 47

function setIpeak(value: u32): void {
    const key = GlobalInterrupts.disable()
    const reg = ($reg32[$R.SYS0_BASE + $R.SYS0_O_TMUTE4] & ~$R.SYS0_TMUTE4_IPEAK_M)
        | (value << $R.SYS0_TMUTE4_IPEAK_S)
    $reg32[$R.SYS0_BASE + $R.SYS0_O_MUNLOCK] = $R.SYS0_MUNLOCK_KEY_UNLOCK
    $reg32[$R.SYS0_BASE + $R.SYS0_O_TMUTE4] = reg
    $reg32[$R.SYS0_BASE + $R.SYS0_O_MUNLOCK] = $R.SYS0_MUNLOCK_KEY_LOCK
    GlobalInterrupts.restore(key)
}

export function enable(): void {
    startEnable()
    waitReady()
}

export function startEnable(): void {
    if (state != State.OFF && state != State.READY) fail()
    const params = Registry.getParams()
    cur_params = params
    if (params.$$.radio_phy != TL.Phy.BLE_1M
        || params.$$.radio_power != 0
        || params.$$.ble_tx_encrypted || params.$$.ble_rx_encrypted) {
        printf`CC27xx requires BLE 1M, 0 dBm, unencrypted packets\n`()
        fail()
    }
    // CC23xx transition from CONNECT_IND to the connection profile:
    // update AA/CRC without power-cycling a READY radio.
    if (state == State.READY) {
        configureProfile()
        if (handler != $null) handler()
        return
    }
    Idle.setLevel(1)
    RfXtal.enable()
    RfCtrl.enableClocks()
    RfCtrl.resetBlocks()
    RfPatch.loadAll()
    RfRegs.setup()
    RfTrim.apply()
    // CC23xx controller baseline: reset RX once while PBE is stopped,
    // retaining the profile's RX auto-deallocation/commit configuration.
    $R.LRFDPBE.FCMD.$$ = $R.LRFDPBE_FCMD_DATA_RXFIFO_RESET >> $R.LRFDPBE_FCMD_DATA_S
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD] = <u16>(($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD) & 0x0fff) >> 2
    old_ipeak = ($reg32[$R.SYS0_BASE + $R.SYS0_O_TMUTE4] & $R.SYS0_TMUTE4_IPEAK_M) >> $R.SYS0_TMUTE4_IPEAK_S
    setIpeak(3)
    configureProfile()
    state = State.READY
    if (handler != $null) handler()
}

function configureProfile(): void {
    prepared_tx_power = RfPower.calculate(cur_params.$$.radio_power)
    const acc_adr = cur_params.$$.ble_acc_adr
    const crc_init = cur_params.$$.ble_crc_init
    $reg32[$R.LRFDRFE_BASE + $R.LRFDRFE_O_RSSI] = 127
    $reg32[$R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA] = acc_adr != 0 ? acc_adr : 0x8e89bed6
    $reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_CRCINITL] = (crc_init != 0 ? crc_init : 0x555555) << 8
}

export function prepareTx(buf: TL.BufFrame): void {
    if (state != State.READY || buf.$len < 2 || buf.$len > 39) fail()
    prepared = buf
}

export function startTx(chan: u8): void {
    if (state != State.READY || prepared == $null || chan > 39) fail()
    const key = GlobalInterrupts.disable()
    state = State.TX
    tx_channel = chan
    $R.LRFDRFE.SPARE5.$$ = prepared_tx_power
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] =
        (2 << $R.PBE_GENERIC_RAM_OPCFG_TXFCMD_S) | (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S)

        | ((cur_params.$$.ble_chain != $null ? 1 : 0) << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_WHITEINIT] = chan | 0x40
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
    $reg32[$R.LRFDRFE32_BASE + $R.LRFDRFE32_O_ATSTREF] |= $R.LRFDRFE32_ATSTREF_BIAS_M
    if (!tx_chained) {
        RfFreq.program(Channel.getFrequency(chan))
        Common.BusyWait.wait(30)
    }
    RfCtrl.enableImages()
    $R.LRFDDBELL.ICLR0.$$ = 0xffffffff
    $R.LRFDDBELL.IMASK0.$$ = $R.LRFDDBELL_IMASK0_PBE0 | $R.LRFDDBELL_IMASK0_PBE15
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    let tries: u32 = 0
    while ($reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) {
        if (tries++ == 10000) {
            GlobalInterrupts.restore(key)
            printf`CC27xx PBE startup timeout\n`()
            fail()
        }
        Common.BusyWait.wait(1)
    }
    RfFifo.writePkt(prepared, cur_params.$$.ble_acc_adr != 0)
    prepared = $null
    // Allow PBE to accept OP_TX before its scheduled start event.
    $R.LRFDDBELL.ICLR0.$$ = $R.LRFDDBELL_ICLR0_SYSTIM0
    $R.SYSTIM.CH2CC.$$ = tx_chained ? tx_start : $R.SYSTIM.TIME250N.$$ + 400
    $R.LRFDPBE.API.$$ = $R.PBE_GENERIC_REGDEF_API_OP_TX
    tx_chained = false
    GlobalInterrupts.restore(key)
}

export function waitReady(): void {
    while (true) {
        const key = GlobalInterrupts.disable()
        if (state == State.READY) {
            GlobalInterrupts.restore(key)
            return
        }
        Idle.exec()
        GlobalInterrupts.restore(key)
    }
}

export function LRFD_IRQ0_isr$$(): void {
    const mis = $R.LRFDDBELL.MIS0.$$
    $R.LRFDDBELL.ICLR0.$$ = mis
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    if (mis & $R.LRFDDBELL_IMASK0_PBE15) {
        printf`CC27xx radio error %04x, channel=%d, state=%d\n`(
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_ENDCAUSE], tx_channel, state)
        fail()
    }
    if (state == State.RX) {

        if (mis & EVENT_RX_OK) {
            rx_end_time = nowTimeUs()
            tx_start = $R.SYSTIM.TIME250N.$$ + TX_CHAIN_DELAY_US * 4
            if (RfFifo.readPkt(cur_rx_buf, rx_connected, false) == 0) cur_rx_buf = $null
        } else if (mis & EVENT_TIMEOUT) {
            rx_timeout = true
        } else {
            return
        }

        $R.LRFDDBELL.IMASK0.$$ = 0
        state = State.READY
        if (!rx_timeout && cur_rx_buf != $null && cur_params.$$.ble_chain != $null) {
            const reply = cur_params.$$.ble_chain(cur_rx_buf)
            if (reply != $null) {
                tx_chained = true
                prepareTx(reply)
                startTx(tx_channel)
                return
            }
        }
    } else if (state == State.TX) {
        if (!(mis & $R.LRFDDBELL_IMASK0_PBE0)) return

        $R.LRFDDBELL.IMASK0.$$ = 0
        state = State.READY
        if (cur_params.$$.ble_exch_buf != $null) {
            startRx(cur_params.$$.ble_exch_buf, tx_channel, cur_params.$$.ble_exch_end_ms)
            return
        }
    } else {
        return
    }
    if (handler != $null) handler()
}
export function disable(): void {
    const key = GlobalInterrupts.disable()
    Rtc.disableAux()
    pause_handler = $null
    prepared = $null
    tx_chained = false
    // Controller.start()/stop() may shut down an already-off radio.
    // Avoid touching unclocked LRFD registers or restoring an unsaved IPEAK.
    if (state == State.OFF) {
        GlobalInterrupts.restore(key)
        return
    }
    IntrVec.NVIC_disable(e$`LRFD_IRQ0_IRQn`)
    $R.LRFDDBELL.IMASK0.$$ = 0
    $R.LRFDDBELL.ICLR0.$$ = 0xffffffff
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    RfCtrl.disable()
    RfCtrl.disableSynthRefsys()
    setIpeak(old_ipeak)
    RfXtal.disable()
    state = State.OFF
    Idle.setLevel(0)
    GlobalInterrupts.restore(key)
}
export function nowTimeUs(): u32 {
    return Rtc.getRawUsecs()
}
export function getRxBuf(): TL.BufPtr {
    return rx_timeout ? $null : cur_rx_buf
}
export function getRxEndTimeUs(): u32 {
    return rx_end_time
}
export function pause(usecs: u32, h: RadioDriverI.Handler): void {
    pause_handler = h
    Rtc.enableAuxDelay(usecs, $cb(pauseDone))
}
function pauseDone(): void {
    // Controller may wink an LED through Poller/OneShot. Never run that
    // blocking path inside the RTC ISR, where equal-priority IRQs cannot run.
    pause_fiber.$$.post()
}
function pauseFB(_: arg_t): void {
    const h = pause_handler
    pause_handler = $null
    if (h != $null) h()
}

export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16): void {
    if (state != State.READY || buf == $null || chan > 39) fail()
    if (cur_params.$$.ble_rx_encrypted) fail()
    const key = GlobalInterrupts.disable()
    state = State.RX
    rx_connected = cur_params.$$.ble_acc_adr != 0
    RfCtrl.enableImages()
    tx_channel = chan
    cur_rx_buf = buf
    rx_timeout = false
    rx_end_time = 0
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] =
        (1 << $R.PBE_GENERIC_RAM_OPCFG_RXINCLUDEHDR_S)
        | (1 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATNOK_S)
        | (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S)

        | (1 << $R.PBE_GENERIC_RAM_OPCFG_NEXTOP_S)
        | (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_WHITEINIT] = chan | 0x40
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_MAXLEN] = 256
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_RXTIMEOUT] = 0
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_FIRSTRXTIMEOUT] = 0
    let dem = $R.LRFDMDM.DEMC1BE1.$$
    dem = (dem & ~$R.LRFDMDM_DEMC1BE1_THRESHOLDB_M) | (0x7f << $R.LRFDMDM_DEMC1BE1_THRESHOLDB_S)
    $R.LRFDMDM.DEMC1BE1.$$ = dem
    $reg32[$R.LRFDRFE32_BASE + $R.LRFDRFE32_O_ATSTREF] |= $R.LRFDRFE32_ATSTREF_BIAS_M
    RfFreq.program(Channel.getFrequency(chan))
    let tries: u32 = 0
    while ($reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) {
        if (tries++ == 10000) {
            printf`CC27xx RX startup timeout\n`()
            fail()
        }
        Common.BusyWait.wait(1)
    }
    // FIFO ownership and effective size follow the CC23xx profile.
    $R.LRFDDBELL.ICLR0.$$ = 0xffffffff
    $R.LRFDDBELL.IMASK0.$$ = $R.LRFDDBELL_IMASK0_PBE15 | 0x01f5 | (timeout > 0 ? EVENT_TIMEOUT : 0)
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    const start = $R.SYSTIM.TIME250N.$$ + 200 // CC23xx: 50 us command lead
    $R.SYSTIM.CH2CC.$$ = start
    if (timeout > 0) $R.SYSTIM.CH3CC.$$ = start + <u32>timeout * 4000
    $R.LRFDPBE.API.$$ = $R.PBE_GENERIC_REGDEF_API_OP_RX
    GlobalInterrupts.restore(key)
}

