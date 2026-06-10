import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@ti.distro.cc23xx/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
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

const TX_CHAIN_DELAY = 42

var cur_chan: u8
var cur_params: $$<TL.Params>
var cur_rx_buf: TL.BufPtr
var cur_state: volatile_t<State> = State.IDLE
var pause_handler: RadioDriverI.Handler = $null
var rx_end_time: u32
var rx_timeout = false
var tx_chained = false
var tx_start = 0

export function disable() {
    $['%%d:'](3)
    Idle.setPauseOnly(false)
    setState(State.IDLE)
    RfCtrl.disable()
    RfXtal.disable()
}

export function enable() {
    $['%%d:'](0)
    cur_params = Registry.getParams()
    if (cur_params.$$.radio_phy != TL.Phy.BLE_1M) {
        printf`*** bad phy\n`()
    }
    const acc_adr = cur_params.$$.ble_acc_adr
    const crc_init = cur_params.$$.ble_crc_init
    if (cur_state == State.IDLE) {
        setState(State.SETUP)
        RfXtal.enable()
        RfCtrl.enableClocks()
        RfPatch.loadAll()
        RfXtal.waitReady() // latest possible sync point
        RfRegs.setup()
        RfTrim.apply()
        setState(State.READY)
    }
    // cur_phy
    $reg32[$R.LRFDRFE_BASE + $R.LRFDRFE_O_RSSI] = 127
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD] = <u16>(($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD) & 0x0FFF) >> 2
    $reg32[$R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA] = acc_adr != 0 ? acc_adr : 0x8E89_BED6
    $reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_CRCINITL] = (crc_init != 0 ? crc_init : 0x555555) << 8
    Idle.setPauseOnly(true)
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

export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16) {
    $['%%d:'](2)
    setState(State.RX)
    cur_rx_buf = buf
    cur_chan = chan
    RfCtrl.enableImages()
    rx_timeout = false
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
    $R.LRFDDBELL.IMASK0.$$ =
        LRF.EventOpDone |
        LRF.EventOpError |
        LRF.EventRxCtrl |
        LRF.EventRxNok |
        LRF.EventRxIgnored |
        LRF.EventRxEmpty |
        LRF.EventRxBufFull |
        LRF.EventRxOk |
        LRF.EventSystim1
    // $R.LRFDDBELL.IMASK0.$$ = LRF.EventOpDone | LRF.EventOpError | LRF.EventRxOk | LRF.EventSystim1
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = $R.SYSTIM.TIME250N.$$
    if (timeout > 0) {
        $R.LRFDDBELL.ICLR0.$$ = $R.LRFDDBELL_ICLR0_SYSTIM1_M
        $R.SYSTIM.CH3CC.$$ = $R.SYSTIM.TIME250N.$$ + (<u32>timeout * 4000)
    }

    $R.LRFDPBE.API.$$ = op

    if (chan < 37) {
    }

}

export function startTx(buf: TL.BufFrame, chan: u8) {
    $['%%d:'](1)
    setState(State.TX)
    cur_chan = chan
    RfFifo.writePkt(buf)
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
}

export function waitReady() {
    while (cur_state != State.READY) {
        Idle.exec()
    }
}

export function LRFD_IRQ0_isr$$() {
    const mis = $R.LRFDDBELL.MIS0.$$
    $R.LRFDDBELL.ICLR0.$$ = mis
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    switch (cur_state) {
        case State.RX: {
            if ((mis & LRF.EventSystim1) != 0) {
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
            RfFifo.readPkt(cur_rx_buf)
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
