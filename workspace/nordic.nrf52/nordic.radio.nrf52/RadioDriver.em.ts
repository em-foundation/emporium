import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@nordic.distro.nrf52/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as HfXtal from '@nordic.mcu.nrf52/HfXtal.em'
import * as Idle from '@nordic.mcu.nrf52/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as Link from '@em.link/Link.em'
import * as Mem from '@em.utils/Mem.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as Rtc from '@nordic.mcu.nrf52/Rtc.em'
import * as TimeFence from '@em.utils/TimeFence.em'
import * as TL from '@em.link/Types.em'

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

const CCM_POLL_LIMIT = 10000
const MAX_PLAIN_LEN = 27
const PPI_CCM = (1 << 24) | (1 << 25)
const RADIO_DISABLE_POLL_LIMIT = 1000000

enum State {
    IDLE, SETUP, READY, RX, TX, CS, CW
}

var cur_chan: u8
var cur_params: $$<TL.Params>
var cur_phy: TL.Phy
var cur_rx_buf: TL.BufPtr
var cur_state: volatile_t<State> = State.IDLE
var pause_handler: RadioDriverI.Handler = $null
var rx_crypto: bool_t = false
var rx_end_time: u32
var rx_timeout: volatile_t<bool_t> = false
var tx_crypto: bool_t = false

export function disable() {
    const key = GlobalInterrupts.disable()
    const starting = cur_state == State.SETUP
    setState(State.IDLE)
    if (starting) HfXtal.stop()
    GlobalInterrupts.restore(key)
    Rtc.disableAux()
    IntrVec.NVIC_disable(e$`RADIO_IRQn`)
    const state_before: u32 = $R.RADIO.STATE.$$
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    $R.RADIO.TASKS_DISABLE.$$ = 1
    let polls: u32 = 0
    while ($R.RADIO.EVENTS_DISABLED.$$ == 0 && polls < RADIO_DISABLE_POLL_LIMIT) {
        polls += 1
    }
    if ($R.RADIO.EVENTS_DISABLED.$$ == 0) {
        const state_after: u32 = $R.RADIO.STATE.$$
        const end: u32 = $R.RADIO.EVENTS_END.$$
        const ready: u32 = $R.RADIO.EVENTS_READY.$$
        const shorts: u32 = $R.RADIO.SHORTS.$$
        const driver_state: u32 = cur_state
        const timed_out: u32 = rx_timeout ? 1 : 0
        stopCrypto()
        printf`RADIO disable timeout FAIL before=%d after=%d driver=%d rx_timeout=%d\n`(state_before, state_after, driver_state, timed_out)
        printf`RADIO events end=%d ready=%d shorts=%08x polls=%d\n`(end, ready, shorts, polls)
        fail()
        return
    }
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    $R.RADIO.SHORTS.$$ = 0
    stopCrypto()
    HfXtal.stop()
    setState(State.IDLE)
}

export function enable() {
    HfXtal.start($null)
    setup()
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

export function startEnable() {
    const key = GlobalInterrupts.disable()
    setup()
    HfXtal.start($cb(hfReadyHandler))
    GlobalInterrupts.restore(key)
}

export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16) {
    setState(State.RX)
    cur_rx_buf = buf
    cur_chan = chan
    rx_end_time = 0
    rx_timeout = false
    rx_crypto = cur_params.$$.ble_rx_encrypted
    if (cur_phy == TL.Phy.BLE_1M) setPacketFormat(rx_crypto)
    if (rx_crypto) {
        if (cur_phy != TL.Phy.BLE_1M || cur_params.$$.ble_acc_adr == 0) fail()
        Link.PacketCrypto.prepareRx(buf, cur_params.$$.ble_rx_ctr_lo, cur_params.$$.ble_rx_ctr_hi)
    }
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
    let tx_buf = $cast2<TL.BufPtr>($$(buf[0]))
    const encrypted = cur_params.$$.ble_tx_encrypted
    tx_crypto = encrypted && buf[1] != 0
    if (cur_phy == TL.Phy.BLE_1M) setPacketFormat(encrypted)
    if (encrypted) {
        if (cur_phy != TL.Phy.BLE_1M || cur_params.$$.ble_acc_adr == 0 || buf[1] > MAX_PLAIN_LEN) fail()
    }
    if (tx_crypto) {
        tx_buf = Link.PacketCrypto.prepareTx(tx_buf, cur_params.$$.ble_tx_ctr_lo, cur_params.$$.ble_tx_ctr_hi)
    }
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>(tx_buf)
    $R.RADIO.TXPOWER.$$ = $R.RADIO_TXPOWER_TXPOWER_0dBm
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITEIV.$$ = chan
    $R.RADIO.TXADDRESS.$$ = 0
    $R.RADIO.INTENSET.$$ = $R.RADIO_INTENSET_END_Msk
    TimeFence.wait()
    IntrVec.NVIC_enable(e$`RADIO_IRQn`)
    $R.RADIO.TASKS_TXEN.$$ = 1
}

export function waitReady() {
    Idle.setLevel(1)
    while (true) {
        const key = GlobalInterrupts.disable()
        if (cur_state == State.READY) {
            GlobalInterrupts.restore(key)
            break
        }
        Idle.exec()
        GlobalInterrupts.restore(key)
    }
    Idle.setLevel(0)
}

export function RADIO_isr$$() {
    IntrVec.NVIC_clear(e$`RADIO_IRQn`)
    $R.RADIO.INTENCLR.$$ = $R.RADIO.INTENSET.$$
    $R.RADIO.EVENTS_END.$$ = 0
    TimeFence.enable(81)
    switch (cur_state) {
        case State.RX: {
            if (rx_timeout) break
            rx_end_time = nowTimeUs()
            Rtc.disableAux()
            if (cur_phy == TL.Phy.BLE_1M) {
                const max_len: u32 = ($R.RADIO.PCNF1.$$ & $R.RADIO_PCNF1_MAXLEN_Msk) >> $R.RADIO_PCNF1_MAXLEN_Pos
                if ($R.RADIO.CRCSTATUS.$$ == 0 || cur_rx_buf[1] > max_len) {
                    stopCrypto()
                    cur_rx_buf = $null
                    break
                }
            }
            if (rx_crypto) {
                if (cur_rx_buf[1] == 0) {
                    stopCrypto()
                } else {
                    let polls: u32 = 0
                    while ($R.CCM.EVENTS_ENDCRYPT.$$ == 0 && $R.CCM.EVENTS_ERROR.$$ == 0 && polls < CCM_POLL_LIMIT) {
                        polls += 1
                    }
                    let plain = Link.PacketCrypto.completeRx()
                    rx_crypto = false
                    if ((cur_rx_buf[0] & 0x08) != cur_params.$$.ble_rx_next_sn
                        && (cur_params.$$.ble_rx_ctr_lo != 0 || cur_params.$$.ble_rx_ctr_hi != 0)) {
                        plain = retryRx()
                    }
                    if (plain == $null) {
                        cur_rx_buf = $null
                        break
                    }
                    if (plain[1] > MAX_PLAIN_LEN) fail()
                    Mem.cpy(cur_rx_buf, plain, 3 + plain[1])
                }
            }
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
            if (tx_crypto) {
                Link.PacketCrypto.completeTx()
                tx_crypto = false
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
    TimeFence.disable()
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function hfReadyHandler() {
    if (cur_state != State.SETUP) return
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function retryRx(): TL.BufPtr {
    let counter_hi = cur_params.$$.ble_rx_ctr_hi
    let counter_lo = cur_params.$$.ble_rx_ctr_lo
    if (counter_lo == 0) counter_hi -= 1
    counter_lo -= 1
    Link.PacketCrypto.prepareRx(cur_rx_buf, counter_lo, counter_hi)
    $R.PPI.CHENCLR.$$ = PPI_CCM
    $R.CCM.TASKS_KSGEN.$$ = 1
    let polls: u32 = 0
    while ($R.CCM.EVENTS_ENDKSGEN.$$ == 0 && $R.CCM.EVENTS_ERROR.$$ == 0 && polls < CCM_POLL_LIMIT) {
        polls += 1
    }
    if ($R.CCM.EVENTS_ENDKSGEN.$$ == 0 || $R.CCM.EVENTS_ERROR.$$ != 0) {
        return Link.PacketCrypto.completeRx()
    }
    $R.CCM.TASKS_CRYPT.$$ = 1
    polls = 0
    while ($R.CCM.EVENTS_ENDCRYPT.$$ == 0 && $R.CCM.EVENTS_ERROR.$$ == 0 && polls < CCM_POLL_LIMIT) {
        polls += 1
    }
    return Link.PacketCrypto.completeRx()
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
    stopCrypto()
    /// TODO -- track RADIO END event
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function setPacketFormat(encrypted: bool_t) {
    const connection = cur_params.$$.ble_acc_adr != 0
    $R.RADIO.PCNF0.$$ = ((encrypted ? 5 : 8) << $R.RADIO_PCNF0_LFLEN_Pos)
        | (1 << $R.RADIO_PCNF0_S0LEN_Pos)
        | (encrypted ? (3 << $R.RADIO_PCNF0_S1LEN_Pos) : 0)
        | (connection ? $R.RADIO_PCNF0_S1INCL_Msk : 0)
    $R.RADIO.PCNF1.$$ = ((encrypted ? 31 : 37) << $R.RADIO_PCNF1_MAXLEN_Pos)
        | (3 << $R.RADIO_PCNF1_BALEN_Pos) | $R.RADIO_PCNF1_WHITEEN_Msk
}

function setState(s: State) {
    cur_state = s
}

function setup() {
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
            $R.RADIO.PCNF0.$$ = (8 << $R.RADIO_PCNF0_LFLEN_Pos) | (1 << $R.RADIO_PCNF0_S0LEN_Pos) | (acc_adr != 0 ? $R.RADIO_PCNF0_S1INCL_Msk : 0)
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
}

function stopCrypto() {
    if (!rx_crypto && !tx_crypto) return
    $R.PPI.CHENCLR.$$ = PPI_CCM
    $R.CCM.SHORTS.$$ = 0
    $R.CCM.TASKS_STOP.$$ = 1
    $R.CCM.ENABLE.$$ = 0
    rx_crypto = false
    tx_crypto = false
}
