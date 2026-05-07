import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
import * as HfXtal from '@nordic.mcu.nrf54/HfXtal.em'
import * as Idle from '@nordic.mcu.nrf54/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as T from '@em.link/Types.em'

enum State {
    IDLE, SETUP, READY, RX, TX, CS, CW
}

const handler = $config<RadioDriverI.Handler>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('RADIO_0')
    }
    export function bindHandler(h: RadioDriverI.Handler) {
        handler.$$val = h
    }
}

//>> ---- em$targ ---- <<//

var cur_chan: u8
var cur_params: $$<T.Params>
var cur_phy: T.Phy
var cur_rx_buf: T.BufPtr
var cur_state: volatile_t<State> = State.IDLE
var rx_timeout = false

export function disable() {
    HfXtal.stop()
    IntrVec.NVIC_disable(e$`RADIO_0_IRQn`)
    $R.RADIO.TASKS_DISABLE.$$ = 1
    while ($R.RADIO.EVENTS_DISABLED.$$ == 0) { } // TODO -- remove
    setState(State.IDLE)
}

export function enable() {
    HfXtal.start()
    cur_params = Registry.getParams()
    cur_phy = cur_params.$$.radio_phy
    setState(State.SETUP)
    switch (cur_phy) {
        case T.Phy.PROP_1M: {
            $R.RADIO.MODE.$$ = $R.RADIO_MODE_MODE_Nrf_1Mbit
            $R.RADIO.PCNF0.$$ = (8 << $R.RADIO_PCNF0_LFLEN_Pos)
            $R.RADIO.PCNF1.$$ = (240 << $R.RADIO_PCNF1_MAXLEN_Pos) | (3 << $R.RADIO_PCNF1_BALEN_Pos) | $R.RADIO_PCNF1_WHITEEN_Msk
            $R.RADIO.BASE0.$$ = 0xAAAABBBB
            $R.RADIO.PREFIX0.$$ = 0xCC
            break
        }
        case T.Phy.BLE_1M: {
            $R.RADIO.MODE.$$ = $R.RADIO_MODE_MODE_Ble_1Mbit
            $R.RADIO.PCNF0.$$ = (8 << $R.RADIO_PCNF0_LFLEN_Pos) | (1 << $R.RADIO_PCNF0_S0LEN_Pos)
            $R.RADIO.PCNF1.$$ = (37 << $R.RADIO_PCNF1_MAXLEN_Pos) | (3 << $R.RADIO_PCNF1_BALEN_Pos) | $R.RADIO_PCNF1_WHITEEN_Msk
            $R.RADIO.BASE0.$$ = 0x89bed600
            $R.RADIO.PREFIX0.$$ = 0x8e
            $R.RADIO.CRCCNF.$$ = (3 << $R.RADIO_CRCCNF_LEN_Pos) | ($R.RADIO_CRCCNF_SKIPADDR_Skip << $R.RADIO_CRCCNF_SKIPADDR_Pos)
            $R.RADIO.CRCPOLY.$$ = 0x65b
            $R.RADIO.CRCINIT.$$ = 0x555555
            break
        }
        default: fail()
    }
    $R.RADIO.SHORTS.$$ = $R.RADIO_SHORTS_READY_START_Msk | $R.RADIO_SHORTS_PHYEND_DISABLE_Msk
    HfXtal.wait()
    setState(State.READY)
}

function setState(s: State) {
    $['%%a']
    $['%%>'](s)
    cur_state = s
}

export function startCw(chan: u8, power: i8) {
    setState(State.CW)
    $R.RADIO.TXPOWER.$$ = $R.RADIO_TXPOWER_TXPOWER_Pos5dBm
    $R.RADIO.FREQUENCY.$$ = 40
    $R.RADIO.TASKS_TXEN.$$ = 1
}

export function startRx(buf: T.BufPtr, chan: u8, timeout: u16) {
    setState(State.RX)
    cur_rx_buf = buf
    cur_chan = chan
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>(buf)
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITE.$$ = chan | $R.RADIO_DATAWHITE_ResetValue
    $R.RADIO.RXADDRESSES.$$ = $R.RADIO_RXADDRESSES_ADDR0_Msk
    $R.RADIO.INTENSET00.$$ = $R.RADIO_INTENSET00_PHYEND_Msk
    IntrVec.NVIC_enable(e$`RADIO_0_IRQn`)
    $R.RADIO.TASKS_RXEN.$$ = 1
}

export function startTx(buf: T.BufFrame, chan: u8) {
    setState(State.TX)
    cur_chan = chan
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>($$(buf[0]))
    $R.RADIO.TXPOWER.$$ = $R.RADIO_TXPOWER_TXPOWER_0dBm
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITE.$$ = chan | $R.RADIO_DATAWHITE_ResetValue
    $R.RADIO.TXADDRESS.$$ = 0
    $R.RADIO.INTENSET00.$$ = $R.RADIO_INTENSET00_PHYEND_Msk
    IntrVec.NVIC_enable(e$`RADIO_0_IRQn`)
    $R.RADIO.TASKS_TXEN.$$ = 1
}

export function waitReady() {
    while (cur_state != State.READY) {
        Idle.exec()
    }
}

export function RADIO_0_isr$$() {
    // $['%%a']
    // $['%%>'](<u8>$R.RADIO.STATE.$$)
    IntrVec.NVIC_clear(e$`RADIO_0_IRQn`)
    $R.RADIO.INTENCLR00.$$ = $R.RADIO.INTENSET00.$$
    $R.RADIO.EVENTS_PHYEND.$$ = 0
    if (cur_state == State.TX && cur_params.$$.ble_exch_buf != $null) {
        startRx(cur_params.$$.ble_exch_buf, cur_chan, cur_params.$$.ble_exch_end_ms)
        return
    }
    setState(State.READY)
    if (handler != $null) handler()
}
