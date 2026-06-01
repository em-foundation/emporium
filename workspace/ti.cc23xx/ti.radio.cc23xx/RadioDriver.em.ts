import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@ti.distro.cc23xx/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
import * as Idle from '@ti.mcu.cc23xx/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LRF from '@ti.radio.cc23xx/LRF.em'
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

var cur_chan: u8
var cur_params: $$<TL.Params>
var cur_phy: TL.Phy
var cur_rx_buf: TL.BufPtr
var cur_state: volatile_t<State> = State.IDLE
var pause_handler: RadioDriverI.Handler = $null
var rx_end_time: u32
var rx_timeout = false

export function disable() {
    Idle.setPauseOnly(false)
    setState(State.IDLE)
    RfCtrl.disable()
    RfXtal.disable()
}

export function enable() {
    cur_params = Registry.getParams()
    cur_phy = cur_params.$$.radio_phy
    setState(State.SETUP)
    RfXtal.enable()
    RfCtrl.enableClocks()
    RfPatch.loadAll(cur_phy)
    RfXtal.waitReady() // latest possible sync point
    RfRegs.setup()
    $reg32[$R.LRFDRFE_BASE + $R.LRFDRFE_O_RSSI] = 127
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD] = <u16>(($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD) & 0x0FFF) >> 2
    RfTrim.apply()
    switch (cur_phy) {
        case TL.Phy.BLE_1M:
            $reg32[$R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA] = 0x8E89_BED6
            $reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_CRCINITL] = (0x555555 << 8)
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_EXTRABYTES] = 6 // stat + rssi + timestamp
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRTYPE] = 0 // public
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRL] = 0xAAAA
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRM] = 0xAAAA
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRH] = 0xC0AA
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_ADVCFG] = $R.PBE_BLE5_RAM_ADVCFG_SCANNABLE | $R.PBE_BLE5_RAM_ADVCFG_CONNECTABLE
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_FILTPOLICY] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_RPACONNECT] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_RPACONNECT] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_FL1MASK] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_FL2MASK] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OPCFG] = 0
            break
    }
    Idle.setPauseOnly(true)
    setState(State.READY)
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

/// TODO: merge into current APIs
// export function readPkt(pkt: frame_t<u8>): u8 {
//     if (rx_timeout) return 0
//     const sz = RfFifo.readPkt(pkt);
//     return sz
// }

export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16) {
    $['%%d:'](2)
    setState(State.RX)
    cur_rx_buf = buf
    cur_chan = chan
    RfFifo.prepareRX()
    RfCtrl.enableImages()
    rx_timeout = false
    const whiten_init = chan | 0x40
    let op = 0
    switch (cur_phy) {
        case TL.Phy.BLE_1M:
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_MAXLEN] = 255
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OPCFG] = 1 << $R.PBE_BLE5_RAM_OPCFG_REPEAT_S
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_WHITEINIT] = whiten_init
            // $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRL] = 0xDDDD
            // $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRM] = 0xEEEE
            // $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRH] = 0xFFFF

            // hal_setup_sync_found_cap
            $R.LRFDMDM.SYSTIMEVTMUX0.$$ = (21 << $R.LRFDMDM_SYSTIMEVTMUX0_SEL0_S)
            $R.LRFDDBELL.SYSTIMOEV.$$ = $R.LRFDDBELL_SYSTIMOEV_SRC2_MCESYSTIM0
            $R.SYSTIM.CH4CFG.$$ |= $R.SYSTIM_CH4CFG_INP_RISE | $R.SYSTIM_CH4CFG_MODE_CAPT | $R.SYSTIM_CH4CFG_REARM_EN;

            // reg($R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA).* = 0x8E89_BED6 ^ (em.as(u32, whiten_init) << 24)

            // reg($R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA).* = 0x7176_4129
            // var demc1be0 = reg($R.LRFDMDM_BASE + $R.LRFDMDM_O_DEMC1BE0).*
            // var demc1be2 = reg($R.LRFDMDM_BASE + $R.LRFDMDM_O_DEMC1BE2).*
            // demc1be0 |= $R.LRFDMDM_DEMC1BE0_MASKA_M | $R.LRFDMDM_DEMC1BE0_MASKB_M
            // demc1be2 = (demc1be2 & ~$R.LRFDMDM_DEMC1BE2_THRESHOLDC_M) | (0x7F << $R.LRFDMDM_DEMC1BE2_THRESHOLDC_S)
            // reg($R.LRFDMDM_BASE + $R.LRFDMDM_O_DEMC1BE0).* = demc1be0
            // reg($R.LRFDMDM_BASE + $R.LRFDMDM_O_DEMC1BE2).* = demc1be2
            op = $R.PBE_BLE5_REGDEF_API_OP_RXRAW
            break
    }
    RfFreq.program(Channel.getFrequency(chan), cur_phy)

    // $R.LRFDDBELL.IMASK0.$$ =
    //     LRF.EventOpDone |
    //     LRF.EventOpError |
    //     LRF.EventRxCtrl |
    //     LRF.EventRxNok |
    //     LRF.EventRxIgnored |
    //     LRF.EventRxEmpty |
    //     LRF.EventRxBufFull |
    //     LRF.EventRxOk |
    //     LRF.EventRxfifo |
    //     LRF.EventSystim1


    $R.LRFDDBELL.IMASK0.$$ = LRF.EventOpDone | LRF.EventOpError | LRF.EventRxOk | LRF.EventSystim1
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = $R.SYSTIM.TIME250N.$$
    if (timeout > 0) {
        $R.LRFDDBELL.ICLR0.$$ = $R.LRFDDBELL_ICLR0_SYSTIM1_M
        $R.SYSTIM.CH3CC.$$ = $R.SYSTIM.TIME250N.$$ + (<u32>timeout * 4000)
    }
    $R.LRFDPBE.API.$$ = op
}

export function startTx(buf: TL.BufFrame, chan: u8) {
    $['%%d:'](1)
    setState(State.TX)
    cur_chan = chan
    // _ = pkt
    RfFifo.writePkt(buf)
    // reg($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD).* = ($R.LRFDPBE_FCMD_DATA_TXFIFO_RETRY >> $R.LRFDPBE_FCMD_DATA_S)
    RfPower.program(cur_params.$$.radio_power)
    RfCtrl.enableImages()
    let op = 0
    switch (cur_phy) {
        case TL.Phy.BLE_1M:
            op = $R.PBE_BLE5_REGDEF_API_OP_TXRAW
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OPCFG] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_WHITEINIT] = chan | 0x40
            break
    }
    RfFreq.program(Channel.getFrequency(chan), cur_phy)
    $R.LRFDDBELL.IMASK0.$$ = LRF.EventOpDone | LRF.EventOpError
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = $R.SYSTIM.TIME250N.$$
    $R.LRFDPBE.API.$$ = op
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
            if ((mis & LRF.EventRxOk) == 0) {
                // printf`RX fail: %08x\n`(mis)
                // fail()
                return
            }
            rx_end_time = nowTimeUs()
            RfFifo.readPkt(cur_rx_buf)
            if (cur_params.$$.ble_chain != $null) {
                const tx_buf = cur_params.$$.ble_chain(cur_rx_buf)
                if (tx_buf != $null) {
                    startTx(tx_buf, cur_chan)
                    return
                }
            }
            break
        }
        case State.TX: {
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
