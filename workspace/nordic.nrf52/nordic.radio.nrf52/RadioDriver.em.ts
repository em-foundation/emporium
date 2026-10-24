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
const PPI_RX_START = 1 << 4
const PPI_RX_TRACE = (1 << 0) | (1 << 2) | (1 << 3) | PPI_RX_START
const RADIO_DISABLE_POLL_LIMIT = 1000000
const RADIO_RX_RAMP_US = 140
const RTC_COUNTER_MASK = 0x00ffffff
const RTC_PERIOD_US = 512000000
const RTC_TRACE_LEAD_TICKS = 4
const RX_SCHEDULE_MAX_US = 5000
const RX_SCHEDULE_MIN_US = 20
const TIFS_US = 150

enum State {
    IDLE, SETUP, READY, RX, TX, CS, CW
}

var cur_chan: u8
var cur_params: $$<TL.Params>
var cur_phy: TL.Phy
var cur_rx_buf: TL.BufPtr
var prepared_tx_buf: TL.BufPtr = $null
var prepared_tx_len: u16
var cur_state: volatile_t<State> = State.IDLE
var pause_handler: RadioDriverI.Handler = $null
var rx_crypto: bool_t = false
var rx_end_time: u32
var rx_timeout: volatile_t<bool_t> = false
var rx_trace_active: bool_t = false
var rx_trace_epoch_tick: u32
var rx_trace_pause_level: u32
var tifs_pending: bool_t = false
var tx_crypto: bool_t = false

export function disable() {
    stopRxTrace()
    const key = GlobalInterrupts.disable()
    prepared_tx_buf = $null
    const starting = cur_state == State.SETUP
    setState(State.IDLE)
    tifs_pending = false
    $R.RADIO.SHORTS.$$ = 0
    if (starting) HfXtal.stop()
    GlobalInterrupts.restore(key)
    Rtc.disableAux()
    IntrVec.NVIC_disable(e$`RADIO_IRQn`)
    const state_before: u32 = $R.RADIO.STATE.$$
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    if (state_before != $R.RADIO_STATE_STATE_Disabled) $R.RADIO.TASKS_DISABLE.$$ = 1
    let polls: u32 = 0
    while (state_before != $R.RADIO_STATE_STATE_Disabled
        && $R.RADIO.EVENTS_DISABLED.$$ == 0 && polls < RADIO_DISABLE_POLL_LIMIT) {
        polls += 1
    }
    if (state_before != $R.RADIO_STATE_STATE_Disabled && $R.RADIO.EVENTS_DISABLED.$$ == 0) {
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

export function em$startup() {
    if (($R.PPI.CHEN.$$ & PPI_RX_TRACE) != 0
        || ($R.RTC0.INTENSET.$$ & $R.RTC_INTENSET_COMPARE2_Msk) != 0
        || ($R.RTC0.EVTEN.$$ & $R.RTC_EVTEN_COMPARE2_Msk) != 0) {
        printf`RadioDriver RX trace resource unavailable FAIL\n`()
        fail()
        return
    }
    $R.PPI.CH[0].EEP.$$ = e$`(uint32_t)&NRF_RADIO->EVENTS_READY`
    $R.PPI.CH[0].TEP.$$ = e$`(uint32_t)&NRF_TIMER1->TASKS_CAPTURE[0]`
    $R.PPI.FORK[0].TEP.$$ = 0
    $R.PPI.CH[2].EEP.$$ = e$`(uint32_t)&NRF_RADIO->EVENTS_END`
    $R.PPI.CH[2].TEP.$$ = e$`(uint32_t)&NRF_TIMER1->TASKS_CAPTURE[2]`
    $R.PPI.CH[3].EEP.$$ = e$`(uint32_t)&NRF_RTC0->EVENTS_COMPARE[2]`
    $R.PPI.CH[3].TEP.$$ = e$`(uint32_t)&NRF_TIMER1->TASKS_START`
    $R.PPI.FORK[3].TEP.$$ = e$`(uint32_t)&NRF_TIMER1->TASKS_CLEAR`
    $R.PPI.CH[4].EEP.$$ = e$`(uint32_t)&NRF_TIMER1->EVENTS_COMPARE[3]`
    $R.PPI.CH[4].TEP.$$ = e$`(uint32_t)&NRF_RADIO->TASKS_RXEN`
    $R.TIMER1.TASKS_STOP.$$ = 1
    $R.TIMER1.INTENCLR.$$ = $R.TIMER_INTENCLR_COMPARE0_Msk | $R.TIMER_INTENCLR_COMPARE1_Msk
        | $R.TIMER_INTENCLR_COMPARE2_Msk | $R.TIMER_INTENCLR_COMPARE3_Msk
    $R.TIMER1.SHORTS.$$ = 0
    $R.TIMER1.MODE.$$ = $R.TIMER_MODE_MODE_Timer
    $R.TIMER1.BITMODE.$$ = $R.TIMER_BITMODE_BITMODE_32Bit
    $R.TIMER1.PRESCALER.$$ = 4
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
    const automatic = tifs_pending && cur_state == State.TX
    setState(State.RX)
    cur_rx_buf = buf
    cur_chan = chan
    rx_end_time = 0
    rx_timeout = false
    rx_crypto = cur_params.$$.ble_rx_encrypted
    if (cur_phy == TL.Phy.BLE_1M) setPacketFormat(rx_crypto)
    if (rx_crypto) {
        if (cur_phy != TL.Phy.BLE_1M || cur_params.$$.ble_acc_adr == 0) {
            printf`RadioDriver startRx crypto profile FAIL phy=%d access=%08x\n`(<u32>cur_phy, cur_params.$$.ble_acc_adr)
            fail()
        }
        Link.PacketCrypto.prepareRx(buf, cur_params.$$.ble_rx_ctr_lo, cur_params.$$.ble_rx_ctr_hi)
    }
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>(buf)
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITEIV.$$ = chan
    $R.RADIO.RXADDRESSES.$$ = $R.RADIO_RXADDRESSES_ADDR0_Msk
    if (timeout > 0) {
        const usecs = Rtc.getRawUsecs()
        Rtc.enableAuxUsecs(usecs + (timeout * 1000), $cb(rtcHandler))
    }
    let shorts: u32 = $R.RADIO_SHORTS_READY_START_Msk | $R.RADIO_SHORTS_END_DISABLE_Msk
    if (cur_phy == TL.Phy.BLE_1M && cur_params.$$.ble_chain != $null) {
        shorts |= $R.RADIO_SHORTS_DISABLED_TXEN_Msk
    }
    if (automatic) {
        if (!armTifs(shorts, $R.RADIO_STATE_STATE_RxRu, $R.RADIO_STATE_STATE_Rx)) {
            rx_timeout = true
            cancelExchange()
        }
    } else {
        $R.RADIO.EVENTS_DISABLED.$$ = 0
        $R.RADIO.EVENTS_READY.$$ = 0
        $R.RADIO.EVENTS_ADDRESS.$$ = 0
        $R.RADIO.SHORTS.$$ = shorts
        enableEndInterrupt()
        startRxTrace()
    }
}

// Retain packet storage only; RX may still own radio registers and FIFOs.
export function prepareTx(buf: TL.BufFrame) {
    prepared_tx_len = buf.$len
    prepared_tx_buf = <TL.BufPtr>$$(buf[0])
}

export function startTx(chan: u8) {
    if (prepared_tx_buf == $null) {
        printf`RadioDriver TX not prepared FAIL\n`()
        fail()
        return
    }
    const buf = prepared_tx_buf.$frame(prepared_tx_len)
    prepared_tx_buf = $null
    const automatic = tifs_pending && cur_state == State.RX
    setState(State.TX)
    cur_chan = chan
    let tx_buf = $cast2<TL.BufPtr>($$(buf[0]))
    const encrypted = cur_params.$$.ble_tx_encrypted
    tx_crypto = encrypted && buf[1] != 0
    if (cur_phy == TL.Phy.BLE_1M) setPacketFormat(encrypted)
    if (encrypted) {
        if (cur_phy != TL.Phy.BLE_1M || cur_params.$$.ble_acc_adr == 0 || buf[1] > MAX_PLAIN_LEN) {
            printf`RadioDriver startTx crypto profile FAIL phy=%d access=%08x len=%d\n`(<u32>cur_phy, cur_params.$$.ble_acc_adr, buf[1])
            fail()
        }
    }
    if (tx_crypto) {
        tx_buf = Link.PacketCrypto.prepareTx(tx_buf, cur_params.$$.ble_tx_ctr_lo, cur_params.$$.ble_tx_ctr_hi)
    }
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>(tx_buf)
    $R.RADIO.TXPOWER.$$ = $R.RADIO_TXPOWER_TXPOWER_0dBm
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITEIV.$$ = chan
    $R.RADIO.TXADDRESS.$$ = 0
    let shorts: u32 = $R.RADIO_SHORTS_READY_START_Msk | $R.RADIO_SHORTS_END_DISABLE_Msk
    if (cur_phy == TL.Phy.BLE_1M && cur_params.$$.ble_exch_buf != $null) {
        shorts |= $R.RADIO_SHORTS_DISABLED_RXEN_Msk
    }
    if (automatic) {
        if (!armTifs(shorts, $R.RADIO_STATE_STATE_TxRu, $R.RADIO_STATE_STATE_Tx)) cancelExchange()
    } else {
        TimeFence.wait()
        $R.RADIO.EVENTS_DISABLED.$$ = 0
        $R.RADIO.EVENTS_READY.$$ = 0
        $R.RADIO.SHORTS.$$ = shorts
        enableEndInterrupt()
        $R.RADIO.TASKS_TXEN.$$ = 1
    }
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
    if ($R.RADIO.EVENTS_END.$$ == 0) return
    const shorts: u32 = $R.RADIO.SHORTS.$$
    let captured_end_us: u32 = 0
    let captured_end_valid: bool_t = false
    $R.RADIO.INTENCLR.$$ = $R.RADIO.INTENSET.$$
    $R.RADIO.EVENTS_END.$$ = 0
    e$`__DSB()`
    IntrVec.NVIC_clear(e$`RADIO_IRQn`)
    if (cur_state == State.RX && rx_trace_active) {
        stopRxTrace()
        if (cur_phy == TL.Phy.BLE_1M && cur_params.$$.ble_acc_adr != 0
            && $R.RADIO.CRCSTATUS.$$ != 0 && $R.RADIO.EVENTS_ADDRESS.$$ != 0) {
            if ($R.RTC0.EVENTS_COMPARE[2].$$ != 0 && $R.TIMER1.CC[0].$$ != 0
                && $R.TIMER1.CC[2].$$ >= $R.TIMER1.CC[0].$$) {
                captured_end_us = getCapturedRxEndTime()
                captured_end_valid = true
            }
        }
    }
    tifs_pending = cur_phy == TL.Phy.BLE_1M
        && ((cur_state == State.RX && (shorts & $R.RADIO_SHORTS_DISABLED_TXEN_Msk) != 0)
            || (cur_state == State.TX && (shorts & $R.RADIO_SHORTS_DISABLED_RXEN_Msk) != 0))
    if (tifs_pending) {
        $R.RADIO.SHORTS.$$ = shorts & ~$R.RADIO_SHORTS_READY_START_Msk
        $R.RADIO.EVENTS_READY.$$ = 0
        if (!waitDisabled()) {
            printf`RadioDriver ISR TIFS disable timeout FAIL driver=%d radio=%d ready=%d shorts=%08x\n`(<u32>cur_state, $R.RADIO.STATE.$$, $R.RADIO.EVENTS_READY.$$, $R.RADIO.SHORTS.$$)
            fail()
            return
        }
        $R.RADIO.SHORTS.$$ = $R.RADIO_SHORTS_END_DISABLE_Msk
    } else {
        TimeFence.enable(81)
    }
    switch (cur_state) {
        case State.RX: {
            if (rx_timeout) break
            rx_end_time = captured_end_valid ? captured_end_us : nowTimeUs()
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
                    if (plain[1] > MAX_PLAIN_LEN) {
                        printf`RadioDriver decrypted RX length FAIL len=%d\n`(plain[1])
                        fail()
                    }
                    Mem.cpy(cur_rx_buf, plain, 3 + plain[1])
                }
            }
            if (cur_params.$$.ble_chain != $null) {
                const tx_buf = cur_params.$$.ble_chain(cur_rx_buf)
                if (tx_buf != $null) {
                    prepareTx(tx_buf)
                    startTx(cur_chan)
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
    stopTifs()
    TimeFence.disable()
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function armTifs(shorts: u32, ramp_state: u32, active_state: u32): bool_t {
    const key = GlobalInterrupts.disable()
    if ($R.RADIO.EVENTS_READY.$$ != 0 || $R.RADIO.STATE.$$ != ramp_state) {
        GlobalInterrupts.restore(key)
        return false
    }
    enableEndInterrupt()
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    $R.RADIO.SHORTS.$$ = shorts
    const armed = $R.RADIO.EVENTS_READY.$$ == 0 || $R.RADIO.STATE.$$ == active_state
    if (armed) tifs_pending = false
    GlobalInterrupts.restore(key)
    return armed
}

function cancelExchange() {
    Rtc.disableAux()
    stopCrypto()
    stopTifs()
    TimeFence.disable()
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function enableEndInterrupt() {
    const key = GlobalInterrupts.disable()
    $R.RADIO.INTENCLR.$$ = $R.RADIO_INTENCLR_END_Msk
    $R.RADIO.EVENTS_END.$$ = 0
    e$`(void)NRF_RADIO->EVENTS_END`
    e$`__DSB()`
    IntrVec.NVIC_clear(e$`RADIO_IRQn`)
    $R.RADIO.INTENSET.$$ = $R.RADIO_INTENSET_END_Msk
    IntrVec.NVIC_enable(e$`RADIO_IRQn`)
    GlobalInterrupts.restore(key)
}

function getCapturedRxEndTime(): u32 {
    const ticks = rx_trace_epoch_tick
    const rtc_us = rtcTicksToUsecs(ticks)
    let end_us: u32 = rtc_us + $R.TIMER1.CC[2].$$
    if (end_us >= RTC_PERIOD_US) end_us -= RTC_PERIOD_US
    return end_us
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
    tifs_pending = false
    stopRxTrace()
    $R.RADIO.SHORTS.$$ = 0
    $R.RADIO.TASKS_DISABLE.$$ = 1
    stopCrypto()
    TimeFence.disable()
    /// TODO -- track RADIO END event
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function rtcTicksToUsecs(ticks: u32): u32 {
    return ((ticks >> 9) * 15625) + (((ticks & 0x1ff) * 15625) >> 9)
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
    tifs_pending = false
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
            $R.RADIO.MODECNF0.$$ &= ~$R.RADIO_MODECNF0_RU_Msk
            $R.RADIO.TIFS.$$ = TIFS_US
            $R.RADIO.PCNF0.$$ = (8 << $R.RADIO_PCNF0_LFLEN_Pos) | (1 << $R.RADIO_PCNF0_S0LEN_Pos) | (acc_adr != 0 ? $R.RADIO_PCNF0_S1INCL_Msk : 0)
            $R.RADIO.PCNF1.$$ = (37 << $R.RADIO_PCNF1_MAXLEN_Pos) | (3 << $R.RADIO_PCNF1_BALEN_Pos) | $R.RADIO_PCNF1_WHITEEN_Msk
            $R.RADIO.BASE0.$$ = acc_adr != 0 ? ((acc_adr << 8) & 0xffffff00) : 0x89bed600
            $R.RADIO.PREFIX0.$$ = acc_adr != 0 ? ((acc_adr >> 24) & 0xff) : 0x8e
            $R.RADIO.CRCCNF.$$ = (3 << $R.RADIO_CRCCNF_LEN_Pos) | $R.RADIO_CRCCNF_SKIPADDR_Msk
            $R.RADIO.CRCPOLY.$$ = 0x65b
            $R.RADIO.CRCINIT.$$ = crc_init != 0 ? crc_init : 0x555555
            break
        }
        default: {
            printf`RadioDriver setup PHY unsupported FAIL phy=%d\n`(<u32>cur_phy)
            fail()
        }
    }
    $R.RADIO.SHORTS.$$ = $R.RADIO_SHORTS_READY_START_Msk | $R.RADIO_SHORTS_END_DISABLE_Msk
}

function startRxTrace() {
    const key = GlobalInterrupts.disable()
    $R.TIMER1.TASKS_STOP.$$ = 1
    $R.TIMER1.TASKS_CLEAR.$$ = 1
    $R.TIMER1.CC[0].$$ = 0
    $R.TIMER1.CC[2].$$ = 0
    $R.TIMER1.CC[3].$$ = 0
    $R.TIMER1.EVENTS_COMPARE[3].$$ = 0
    $R.RTC0.EVTENCLR.$$ = $R.RTC_EVTEN_COMPARE2_Msk
    $R.RTC0.EVENTS_COMPARE[2].$$ = 0
    rx_trace_epoch_tick = ($R.RTC0.COUNTER.$$ + RTC_TRACE_LEAD_TICKS) & RTC_COUNTER_MASK
    $R.RTC0.CC[2].$$ = rx_trace_epoch_tick
    let scheduled: bool_t = false
    const schedule_requested = cur_phy == TL.Phy.BLE_1M && cur_params.$$.ble_acc_adr != 0
        && cur_params.$$.ble_rx_start_valid
    if (schedule_requested) {
        const start_us = cur_params.$$.ble_rx_start_us % RTC_PERIOD_US
        const epoch_us = rtcTicksToUsecs(rx_trace_epoch_tick)
        let remaining: i32 = <i32>start_us - <i32>epoch_us
        if (remaining > RTC_PERIOD_US / 2) remaining -= RTC_PERIOD_US
        if (remaining < -RTC_PERIOD_US / 2) remaining += RTC_PERIOD_US
        remaining -= RADIO_RX_RAMP_US
        if (remaining >= RX_SCHEDULE_MIN_US && remaining <= RX_SCHEDULE_MAX_US) {
            $R.TIMER1.CC[3].$$ = <u32>remaining
            scheduled = true
        }
    }
    const counter: u32 = $R.RTC0.COUNTER.$$
    const lead: u32 = (rx_trace_epoch_tick - counter) & RTC_COUNTER_MASK
    if (lead < 2 || lead >= 0x00800000) {
        scheduled = false
        rx_trace_epoch_tick = (counter + RTC_TRACE_LEAD_TICKS) & RTC_COUNTER_MASK
        $R.RTC0.CC[2].$$ = rx_trace_epoch_tick
        $R.RTC0.EVENTS_COMPARE[2].$$ = 0
    }
    rx_trace_active = true
    rx_trace_pause_level = Idle.getLevel()
    Idle.setLevel(1)
    $R.PPI.CHENSET.$$ = scheduled ? PPI_RX_TRACE : PPI_RX_TRACE & ~PPI_RX_START
    $R.RTC0.EVTENSET.$$ = $R.RTC_EVTEN_COMPARE2_Msk
    if (!scheduled) $R.RADIO.TASKS_RXEN.$$ = 1
    GlobalInterrupts.restore(key)
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

function stopRxTrace() {
    if (!rx_trace_active) return
    $R.PPI.CHENCLR.$$ = PPI_RX_TRACE
    $R.RTC0.EVTENCLR.$$ = $R.RTC_EVTEN_COMPARE2_Msk
    $R.TIMER1.TASKS_STOP.$$ = 1
    rx_trace_active = false
    Idle.setLevel(rx_trace_pause_level)
}

function stopTifs() {
    $R.RADIO.SHORTS.$$ = 0
    if (!tifs_pending) return
    tifs_pending = false
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    $R.RADIO.TASKS_DISABLE.$$ = 1
    if (!waitDisabled()) {
        printf`RadioDriver stopTifs disable timeout FAIL driver=%d radio=%d ready=%d shorts=%08x\n`(<u32>cur_state, $R.RADIO.STATE.$$, $R.RADIO.EVENTS_READY.$$, $R.RADIO.SHORTS.$$)
        fail()
    }
}

function waitDisabled(): bool_t {
    let polls: u32 = 0
    while ($R.RADIO.EVENTS_DISABLED.$$ == 0 && polls < RADIO_DISABLE_POLL_LIMIT) {
        polls += 1
    }
    return $R.RADIO.EVENTS_DISABLED.$$ != 0
}
