import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@nordic.distro.nrf52/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
import * as HfXtal from '@nordic.mcu.nrf52/HfXtal.em'
import * as Idle from '@nordic.mcu.nrf52/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as Rtc from '@nordic.mcu.nrf52/Rtc.em'
import * as TimeFence from '@em.utils/TimeFence.em'
import * as TL from '@em.link/Types.em'

enum State {
    IDLE, SETUP, READY, RX, TX, CS, CW
}

const radio_handler = $config<RadioDriverI.Handler>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('RADIO')
    }
    export function bindHandler(h: RadioDriverI.Handler) {
        radio_handler.$$val = h
    }
}

//>> ---- em$targ ---- <<//

var cur_chan: u8
var cur_params: $$<TL.Params>
var cur_phy: TL.Phy
var cur_state: volatile_t<State> = State.IDLE
var cur_rx_buf: TL.BufPtr
var pause_handler: RadioDriverI.Handler = $null
var rx_end_time: u32
var rx_timeout: volatile_t<bool_t> = false

export function disable() {
    Rtc.disableAux()
    IntrVec.NVIC_disable(e$`RADIO_IRQn`)
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    $R.RADIO.TASKS_DISABLE.$$ = 1
    while ($R.RADIO.EVENTS_DISABLED.$$ == 0) { }
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    $R.RADIO.SHORTS.$$ = 0
    HfXtal.stop()
    setState(State.IDLE)
}

export function enable() {
    HfXtal.start()
    cur_params = Registry.getParams()
    cur_phy = cur_params.$$.radio_phy
    const acc_adr = cur_params.$$.ble_acc_adr
    const crc_init = cur_params.$$.ble_crc_init
    setState(State.SETUP)
    switch (cur_phy) {
        case TL.Phy.PROP_1M: {
            $R.RADIO.MODE.$$ = $R.RADIO_MODE_MODE_Nrf_1Mbit
            $R.RADIO.PCNF0.$$ = (8 << $R.RADIO_PCNF0_LFLEN_Pos)
            $R.RADIO.PCNF1.$$ = (240 << $R.RADIO_PCNF1_MAXLEN_Pos) | (3 << $R.RADIO_PCNF1_BALEN_Pos) | $R.RADIO_PCNF1_WHITEEN_Msk
            $R.RADIO.BASE0.$$ = 0xAAAABBBB
            $R.RADIO.PREFIX0.$$ = 0xCC
            break
        }
        case TL.Phy.BLE_1M: {
            $R.RADIO.MODE.$$ = $R.RADIO_MODE_MODE_Ble_1Mbit
            $R.RADIO.MODECNF0.$$ |= $R.RADIO_MODECNF0_RU_Msk
            // $R.RADIO.PCNF0.$$ = (8 << $R.RADIO_PCNF0_LFLEN_Pos) | (1 << $R.RADIO_PCNF0_S0LEN_Pos) | $R.RADIO_PCNF0_S1INCL_Msk
            $R.RADIO.PCNF0.$$ = (8 << $R.RADIO_PCNF0_LFLEN_Pos) | (1 << $R.RADIO_PCNF0_S0LEN_Pos)
            $R.RADIO.PCNF1.$$ = (37 << $R.RADIO_PCNF1_MAXLEN_Pos) | (3 << $R.RADIO_PCNF1_BALEN_Pos) | $R.RADIO_PCNF1_WHITEEN_Msk
            $R.RADIO.BASE0.$$ = acc_adr != 0 ? ((acc_adr << 8) & 0xffffff00) : 0x89bed600
            $R.RADIO.PREFIX0.$$ = acc_adr != 0 ? ((acc_adr >> 24) & 0xff) : 0x8e
            $R.RADIO.CRCCNF.$$ = (3 << $R.RADIO_CRCCNF_LEN_Pos) | $R.RADIO_CRCCNF_SKIPADDR_Msk
            $R.RADIO.CRCPOLY.$$ = 0x65b
            $R.RADIO.CRCINIT.$$ = crc_init != 0 ? crc_init : 0x555555
            break
        }
        default: fail()
    }
    $R.RADIO.SHORTS.$$ = $R.RADIO_SHORTS_READY_START_Msk | $R.RADIO_SHORTS_END_DISABLE_Msk
    // Common.BusyWait.wait(10) // TODO: needed for SRAM setup
    HfXtal.wait()
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

export function startCw(chan: u8, power: i8) {
    setState(State.CW)
    $R.RADIO.TXPOWER.$$ = $R.RADIO_TXPOWER_TXPOWER_Pos4dBm
    $R.RADIO.FREQUENCY.$$ = 40
    $R.RADIO.TASKS_TXEN.$$ = 1
}

export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16) {
    // $['%%d:'](2)
    setState(State.RX)
    cur_rx_buf = buf
    cur_chan = chan
    rx_end_time = 0
    rx_timeout = false
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>(buf)
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITEIV.$$ = chan
    $R.RADIO.RXADDRESSES.$$ = $R.RADIO_RXADDRESSES_ADDR0_Msk
    $R.RADIO.INTENSET.$$ = $R.RADIO_INTENSET_END_Msk
    IntrVec.NVIC_enable(e$`RADIO_IRQn`)
    if (timeout > 0) {
        const usecs = Rtc.getRawUsecs()
        Rtc.enableAuxUsecs(usecs + (timeout * 1000), $cb(rtcHandler))
    }
    $R.RADIO.TASKS_RXEN.$$ = 1
}

export function startTx(buf: TL.BufFrame, chan: u8) {
    setState(State.TX)
    cur_chan = chan
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>($$(buf[0]))
    $R.RADIO.TXPOWER.$$ = $R.RADIO_TXPOWER_TXPOWER_0dBm
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITEIV.$$ = chan
    $R.RADIO.TXADDRESS.$$ = 0
    $R.RADIO.INTENSET.$$ = $R.RADIO_INTENSET_END_Msk
    TimeFence.wait()
    IntrVec.NVIC_enable(e$`RADIO_IRQn`)
    // $['%%d:'](1)
    $R.RADIO.TASKS_TXEN.$$ = 1
}

export function waitReady() {
    Idle.setLevel(1)
    while (cur_state != State.READY) {
        Idle.exec()
    }
    Idle.setLevel(0)
}

export function RADIO_isr$$() {
    // $['%%a']
    // $['%%>'](<u8>$R.RADIO.STATE.$$)
    // $['%%>'](<u16>$R.RADIO.INTENSET.$$)
    IntrVec.NVIC_clear(e$`RADIO_IRQn`)
    $R.RADIO.INTENCLR.$$ = $R.RADIO.INTENSET.$$
    $R.RADIO.EVENTS_END.$$ = 0
    TimeFence.enable(81)
    switch (cur_state) {
        case State.RX: {
            if (rx_timeout) break
            rx_end_time = nowTimeUs()
            Rtc.disableAux()
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
    TimeFence.disable()
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function rtcHandler() {
    Rtc.disableAux()
    if (pause_handler != $null) {
        const h = pause_handler
        pause_handler = $null
        h()
        return
    }
    rx_timeout = true
    $R.RADIO.TASKS_DISABLE.$$ = 1
    /// TODO -- track RADIO END event
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function setState(s: State) {
    // $['%%d:'](s)
    cur_state = s
}
