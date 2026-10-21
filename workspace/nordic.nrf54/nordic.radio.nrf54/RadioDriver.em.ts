import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
import * as Common from '@em.mcu/Common.em'
import * as Debug from '@em.lang/Debug.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as Heap from '@em.utils/Heap.em'
import * as Link from '@em.link/Link.em'
import * as Mem from '@em.utils/Mem.em'
import * as HfXtal from '@nordic.mcu.nrf54/HfXtal.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as Rtc from '@nordic.mcu.nrf54/Rtc.em'
import * as TimeFence from '@em.utils/TimeFence.em'
import * as TL from '@em.link/Types.em'

export const ifs_fence = $config<u32>()
export const hardware_tifs = $config<bool_t>(false)
export const energy_trace = $config<bool_t>(false)
export const scheduled_rx = $config<bool_t>(false)

enum State {
    IDLE, SETUP, READY, RX, TX, CS, CW
}

const radio_handler = $config<RadioDriverI.Handler>()

const tx_adr = $config<Heap.Adr>()

export namespace em$meta {
    export function em$construct() {
        Common.Irq.em$meta.useIntr('RADIO_0')
        tx_adr.$$val = Heap.em$meta.alloc(40)
    }
    export function bindHandler(h: RadioDriverI.Handler) {
        radio_handler.$$val = h
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
var rx_timeout: volatile_t<bool_t> = false
var rx_crypto: bool_t = false
var tx_crypto: bool_t = false
var tifs_pending: bool_t = false
var hf_pending: bool_t = false
var hf_pause_level: u32
var rx_start_pending: bool_t = false
var rx_timeout_enabled: bool_t = false
var rx_timeout_us: u32


const RX_RAMP_LEGACY_US = 140 // Nordic specifies 134 us typical BLE RX ramp; retain the nRF52 140 us allowance
const RX_RAMP_FAST_US = 40
const RX_START_IRQ_GUARD_US = 80 // allow RX ramp/wakeup margin; 49 us produced long RX waits
const RX_SCHEDULE_MIN_US = 64
const RX_SCHEDULE_MAX_US = 5000

export function disable() {
    const key = GlobalInterrupts.disable()
    cancelRxStart()
    Rtc.disableAux()
    if (hf_pending) {
        hf_pending = false
        Common.Idle.setLevel(hf_pause_level)
    }
    if (energy_trace) Debug.DbgD.set() // TEMP: RX marker inactive when cancelled/disabled
    setState(State.IDLE) // FIX: cancel readiness before stopping the crystal
    $R.RADIO.SHORTS.$$ = 0 // FIX: cancel automatic turnaround before disabling the radio
    tifs_pending = false
    Common.Irq.disable(e$`RADIO_0_IRQn`)
    $R.RADIO.INTENCLR00.$$ = $R.RADIO_INTENSET00_PHYEND_Msk
    // FIX: auxiliary timer was already disabled at entry
    TimeFence.disable()
    rx_crypto = false
    tx_crypto = false
    const state_before = $R.RADIO.STATE.$$
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    if (state_before != $R.RADIO_STATE_STATE_Disabled) { // FIX: an already-disabled radio need not emit a new DISABLED event
        $R.RADIO.TASKS_DISABLE.$$ = 1
        let polls: u32 = 0
        while ($R.RADIO.EVENTS_DISABLED.$$ == 0 && polls < 10000) polls += 1
        if ($R.RADIO.EVENTS_DISABLED.$$ == 0) {
            printf`NRF54 RADIO disable timeout FAIL before=%d after=%d\n`(state_before, $R.RADIO.STATE.$$)
            fail()
            return
        }
    }
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    // FIX: shortcuts remain cleared from before RADIO disable
    HfXtal.stop()
    $R.POWER.TASKS_LOWPWR.$$ = 1 // FIX: release the radio clock/power requirement between events
    GlobalInterrupts.restore(key)
}

export function enable() {
    const cold_start = cur_state == State.IDLE // FIX: retain the running crystal when changing radio profiles
    if (cold_start) HfXtal.start()
    setup()
    if (cold_start) HfXtal.wait()
    setState(State.READY)
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
            $R.RADIO.TIMING.$$ = hardware_tifs && acc_adr != 0 ? $R.RADIO_TIMING_RU_Legacy : $R.RADIO_TIMING_RU_Fast
            $R.RADIO.TIFS.$$ = 150
            $R.RADIO.PCNF0.$$ = (8 << $R.RADIO_PCNF0_LFLEN_Pos) | (1 << $R.RADIO_PCNF0_S0LEN_Pos) | (acc_adr != 0 ? ($R.RADIO_PCNF0_S1INCL_Include << $R.RADIO_PCNF0_S1INCL_Pos) : 0) // FIX: match the shared data-channel S1 RAM byte
            $R.RADIO.PCNF1.$$ = (37 << $R.RADIO_PCNF1_MAXLEN_Pos) | (3 << $R.RADIO_PCNF1_BALEN_Pos) | $R.RADIO_PCNF1_WHITEEN_Msk
            $R.RADIO.BASE0.$$ = acc_adr != 0 ? ((acc_adr << 8) & 0xffffff00) : 0x89bed600
            $R.RADIO.PREFIX0.$$ = acc_adr != 0 ? ((acc_adr >> 24) & 0xff) : 0x8e
            $R.RADIO.CRCCNF.$$ = (3 << $R.RADIO_CRCCNF_LEN_Pos) | ($R.RADIO_CRCCNF_SKIPADDR_Skip << $R.RADIO_CRCCNF_SKIPADDR_Pos)
            $R.RADIO.CRCPOLY.$$ = 0x65b
            $R.RADIO.CRCINIT.$$ = crc_init != 0 ? crc_init : 0x555555
            break
        }
        default: fail()
    }
    $R.RADIO.SHORTS.$$ = $R.RADIO_SHORTS_READY_START_Msk | $R.RADIO_SHORTS_PHYEND_DISABLE_Msk
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
    Rtc.enableAux(Rtc.getRawUsecs() + usecs, $cb(rtcHandler))
}

export function startCw(chan: u8, power: i8) {
    setState(State.CW)
    $R.RADIO.TXPOWER.$$ = $R.RADIO_TXPOWER_TXPOWER_Pos5dBm
    $R.RADIO.FREQUENCY.$$ = 40
    $R.POWER.TASKS_CONSTLAT.$$ = 1 // FIX: apply radio workaround only when RX/TX is actually starting
    $R.RADIO.TASKS_TXEN.$$ = 1
}

export function startEnable() {
    const key = GlobalInterrupts.disable()
    const cold_start = cur_state == State.IDLE
    if (cold_start) HfXtal.start() // retain the proven XOSTARTED polling and XOTUNE sequence
    setup()
    if (cold_start) {
        hf_pause_level = Common.Idle.getLevel()
        hf_pending = true
        Common.Idle.setLevel(1)
        Rtc.enableAux(Rtc.getRawUsecs() + 400, $cb(hfSettledHandler))
    } else {
        setState(State.READY)
        if (radio_handler != $null) radio_handler()
    }
    GlobalInterrupts.restore(key)
}

function hfSettledHandler() {
    if (!hf_pending || cur_state != State.SETUP) return
    hf_pending = false
    HfXtal.waitSettled()
    Common.Idle.setLevel(hf_pause_level)
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16) {
    cancelRxStart()
    const automatic = tifs_pending && cur_state == State.TX
    setState(State.RX)
    cur_rx_buf = buf
    cur_chan = chan
    rx_end_time = 0
    rx_timeout = false
    rx_crypto = cur_params.$$.ble_rx_encrypted
    if (rx_crypto) requireConnectionCrypto()
    setPacketLimit(rx_crypto)
    if (rx_crypto) Link.PacketCrypto.prepareRx(buf, cur_params.$$.ble_rx_ctr_lo, cur_params.$$.ble_rx_ctr_hi)
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>(buf)
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITE.$$ = chan | $R.RADIO_DATAWHITE_ResetValue
    $R.RADIO.RXADDRESSES.$$ = $R.RADIO_RXADDRESSES_ADDR0_Msk
    $R.RADIO.INTENSET00.$$ = $R.RADIO_INTENSET00_PHYEND_Msk
    Common.Irq.enable(e$`RADIO_0_IRQn`)
    rx_timeout_enabled = timeout > 0
    if (rx_timeout_enabled) rx_timeout_us = Rtc.getRawUsecs() + (timeout * 1000)
    let shorts: u32 = $R.RADIO_SHORTS_READY_START_Msk | $R.RADIO_SHORTS_PHYEND_DISABLE_Msk
    if (usesHardwareTifs() && cur_params.$$.ble_chain != $null) shorts |= $R.RADIO_SHORTS_DISABLED_TXEN_Msk
    if (automatic) {
        armRxTimeout()
        if (energy_trace) Debug.DbgD.clear() // TEMP: hardware TIFS RX is armed; this edge is software-timed
        if (!armTifs(shorts, $R.RADIO_STATE_STATE_RxRu, $R.RADIO_STATE_STATE_Rx)) {
            rx_timeout = true
            cancelExchange()
        }
    } else {
        $R.RADIO.EVENTS_DISABLED.$$ = 0
        $R.RADIO.EVENTS_READY.$$ = 0
        $R.RADIO.SHORTS.$$ = shorts
        if (!scheduleRxStart()) {
            if (energy_trace) Debug.DbgD.clear() // TEMP: actual RXEN, after any scheduled delay
            $R.POWER.TASKS_CONSTLAT.$$ = 1 // FIX: apply radio workaround only when RX/TX is actually starting
            $R.RADIO.TASKS_RXEN.$$ = 1
            armRxTimeout()
        }
    }
}

export function startTx(buf: TL.BufFrame, chan: u8) {
    cancelRxStart()
    const automatic = tifs_pending && cur_state == State.RX
    setState(State.TX)
    cur_chan = chan
    let tx_buf = <TL.BufPtr>$$(buf[0])
    tx_crypto = cur_params.$$.ble_tx_encrypted
    if (tx_crypto) {
        requireConnectionCrypto()
        tx_buf = Link.PacketCrypto.prepareTx(tx_buf, cur_params.$$.ble_tx_ctr_lo, cur_params.$$.ble_tx_ctr_hi)
    }
    setPacketLimit(tx_crypto)
    $R.RADIO.PACKETPTR.$$ = $cast2<u32>(tx_buf)
    $R.RADIO.TXPOWER.$$ = $R.RADIO_TXPOWER_TXPOWER_0dBm
    $R.RADIO.FREQUENCY.$$ = Channel.getFreqOff(chan)
    $R.RADIO.DATAWHITE.$$ = chan | $R.RADIO_DATAWHITE_ResetValue
    $R.RADIO.TXADDRESS.$$ = 0
    $R.RADIO.INTENSET00.$$ = $R.RADIO_INTENSET00_PHYEND_Msk
    if (!automatic) TimeFence.wait()
    Common.Irq.enable(e$`RADIO_0_IRQn`)
    let shorts: u32 = $R.RADIO_SHORTS_READY_START_Msk | $R.RADIO_SHORTS_PHYEND_DISABLE_Msk
    if (usesHardwareTifs() && cur_params.$$.ble_exch_buf != $null) shorts |= $R.RADIO_SHORTS_DISABLED_RXEN_Msk
    if (automatic) {
        if (!armTifs(shorts, $R.RADIO_STATE_STATE_TxRu, $R.RADIO_STATE_STATE_Tx)) {
            cancelExchange()
            return
        }
    } else {
        $R.RADIO.EVENTS_DISABLED.$$ = 0
        $R.RADIO.EVENTS_READY.$$ = 0
        $R.RADIO.SHORTS.$$ = shorts
        if (energy_trace) Debug.DbgC.clear() // TEMP: software TXEN request; crystal-ready marker is already high
        $R.POWER.TASKS_CONSTLAT.$$ = 1 // FIX: apply radio workaround only when RX/TX is actually starting
        $R.RADIO.TASKS_TXEN.$$ = 1
    }
}

export function waitReady() {
    const pause_level = hf_pending ? hf_pause_level : Common.Idle.getLevel()
    Common.Idle.setLevel(1)
    while (true) {
        const key = GlobalInterrupts.disable() // FIX: readiness must not arrive between the check and WFI
        if (cur_state == State.READY) {
            GlobalInterrupts.restore(key)
            break
        }
        Common.Idle.exec()
        GlobalInterrupts.restore(key)
    }
    Common.Idle.setLevel(pause_level)
}

export function RADIO_0_isr$$() {
    if ($R.RADIO.EVENTS_PHYEND.$$ == 0) return
    if (energy_trace && cur_state == State.TX) Debug.DbgC.set() // TEMP: TX PHYEND observed by ISR
    if (energy_trace && cur_state == State.RX) Debug.DbgD.set() // TEMP: ISR observation of RX PHYEND
    const shorts: u32 = $R.RADIO.SHORTS.$$
    Common.Irq.clear(e$`RADIO_0_IRQn`)
    $R.RADIO.INTENCLR00.$$ = $R.RADIO.INTENSET00.$$
    $R.RADIO.EVENTS_PHYEND.$$ = 0
    tifs_pending = usesHardwareTifs()
        && ((cur_state == State.RX && (shorts & $R.RADIO_SHORTS_DISABLED_TXEN_Msk) != 0)
            || (cur_state == State.TX && (shorts & $R.RADIO_SHORTS_DISABLED_RXEN_Msk) != 0))
    if (tifs_pending) {
        $R.RADIO.SHORTS.$$ = shorts & ~$R.RADIO_SHORTS_READY_START_Msk
        $R.RADIO.EVENTS_READY.$$ = 0
        if (!waitDisabled()) {
            printf`NRF54 RADIO turnaround disable timeout FAIL\n`()
            fail()
            return
        }
        $R.RADIO.SHORTS.$$ = $R.RADIO_SHORTS_PHYEND_DISABLE_Msk
    } else {
        TimeFence.enable(ifs_fence)
    }
    switch (cur_state) {
        case State.RX: {
            if (rx_timeout) break
            rx_end_time = nowTimeUs()
            Rtc.disableAux()
            if (cur_phy == TL.Phy.BLE_1M && ($R.RADIO.CRCSTATUS.$$ == 0 || cur_rx_buf[1] > (rx_crypto ? 31 : 37))) { // FIX: reject corrupt/oversized BLE RX before callbacks
                cur_rx_buf = $null
                break
            }
            if (rx_crypto) {
                let counter_lo = cur_params.$$.ble_rx_ctr_lo
                let counter_hi = cur_params.$$.ble_rx_ctr_hi
                if (cur_rx_buf[1] != 0 && (cur_rx_buf[0] & 0x08) != cur_params.$$.ble_rx_next_sn
                    && (counter_lo != 0 || counter_hi != 0)) {
                    if (counter_lo == 0) counter_hi -= 1
                    counter_lo -= 1
                    Link.PacketCrypto.prepareRx(cur_rx_buf, counter_lo, counter_hi)
                }
                const plain = Link.PacketCrypto.completeRx()
                rx_crypto = false
                if (plain == $null) {
                    cur_rx_buf = $null
                    break
                }
                if (plain != cur_rx_buf) Mem.cpy(cur_rx_buf, plain, 3 + plain[1])
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
    stopTifs()
    TimeFence.disable()
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

// Honor the controller's RX-ready deadline, as the nRF52 driver does. GRTC is
// already used for crystal settling and RX timeout; these phases do not overlap.
function scheduleRxStart(): bool_t {
    if (!scheduled_rx || cur_phy != TL.Phy.BLE_1M || cur_params.$$.ble_acc_adr == 0
        || !cur_params.$$.ble_rx_start_valid) return false
    const ramp_us: u32 = hardware_tifs ? RX_RAMP_LEGACY_US : RX_RAMP_FAST_US
    const start_us: u32 = cur_params.$$.ble_rx_start_us - ramp_us - RX_START_IRQ_GUARD_US
    const now_us = Rtc.getRawUsecs()
    const remaining = <i32>(start_us - now_us)
    if (remaining < RX_SCHEDULE_MIN_US || remaining > RX_SCHEDULE_MAX_US) return false
    if (rx_timeout_enabled && <i32>(rx_timeout_us - start_us) <= 0) return false
    rx_start_pending = true
    Rtc.enableAux(start_us, $cb(rxStartHandler))
    return true
}

function rxStartHandler() {
    if (!rx_start_pending || cur_state != State.RX) return
    rx_start_pending = false
    if (rx_timeout_enabled && <i32>(rx_timeout_us - Rtc.getRawUsecs()) <= 0) {
        rtcHandler()
        return
    }
    if (energy_trace) Debug.DbgD.clear() // TEMP: actual RXEN from the scheduled callback
    $R.POWER.TASKS_CONSTLAT.$$ = 1 // FIX: apply radio workaround only when RX/TX is actually starting
    $R.RADIO.TASKS_RXEN.$$ = 1
    armRxTimeout() // FIX: retain the original absolute timeout after the delayed start
}

function armRxTimeout() {
    if (!rx_timeout_enabled) return
    if (<i32>(rx_timeout_us - Rtc.getRawUsecs()) <= 0) {
        rtcHandler()
        return
    }
    Rtc.enableAux(rx_timeout_us, $cb(rtcHandler))
}

function cancelRxStart() {
    if (!rx_start_pending) return
    rx_start_pending = false
    Rtc.disableAux()
}
function usesHardwareTifs(): bool_t {
    return hardware_tifs && cur_phy == TL.Phy.BLE_1M && cur_params.$$.ble_acc_adr != 0
}

function armTifs(shorts: u32, ramp_state: u32, active_state: u32): bool_t {
    const key = GlobalInterrupts.disable()
    if ($R.RADIO.EVENTS_READY.$$ != 0 || $R.RADIO.STATE.$$ != ramp_state) {
        GlobalInterrupts.restore(key)
        return false
    }
    $R.RADIO.EVENTS_PHYEND.$$ = 0
    e$`__DSB()`
    Common.Irq.clear(e$`RADIO_0_IRQn`)
    $R.RADIO.INTENSET00.$$ = $R.RADIO_INTENSET00_PHYEND_Msk
    Common.Irq.enable(e$`RADIO_0_IRQn`)
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    $R.RADIO.SHORTS.$$ = shorts
    const armed = $R.RADIO.EVENTS_READY.$$ == 0 || $R.RADIO.STATE.$$ == active_state
    if (armed) tifs_pending = false
    GlobalInterrupts.restore(key)
    return armed
}

function waitDisabled(): bool_t {
    let polls: u32 = 0
    while ($R.RADIO.EVENTS_DISABLED.$$ == 0 && polls < 10000) polls += 1
    return $R.RADIO.EVENTS_DISABLED.$$ != 0
}

function stopTifs() {
    $R.RADIO.SHORTS.$$ = 0
    if (!tifs_pending) return
    tifs_pending = false
    $R.RADIO.EVENTS_DISABLED.$$ = 0
    $R.RADIO.TASKS_DISABLE.$$ = 1
    if (!waitDisabled()) {
        printf`NRF54 RADIO cancel turnaround timeout FAIL\n`()
        fail()
    }
}

function cancelExchange() {
    if (energy_trace) Debug.DbgD.set()
    cancelRxStart()
    Rtc.disableAux()
    stopTifs()
    TimeFence.disable()
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function rtcHandler() {
    rx_start_pending = false
    Rtc.disableAux()
    if (pause_handler != $null) {
        const h = pause_handler
        pause_handler = $null
        h()
        return
    }
    if (energy_trace) Debug.DbgD.set() // TEMP: receive timeout
    rx_timeout = true
    $R.RADIO.SHORTS.$$ = 0 // FIX: an RX timeout must not trigger an automatic transmission
    tifs_pending = false
    $R.RADIO.TASKS_DISABLE.$$ = 1
    /// TODO -- track RADIO END event
    setState(State.READY)
    if (radio_handler != $null) radio_handler()
}

function setState(s: State) {
    cur_state = s
}

function requireConnectionCrypto() {
    if (cur_phy != TL.Phy.BLE_1M || cur_params.$$.ble_acc_adr == 0) {
        printf`NRF54 packet crypto requires a BLE connection FAIL\n`()
        fail()
    }
}

function setPacketLimit(encrypted: bool_t) {
    if (cur_phy != TL.Phy.BLE_1M) return
    $R.RADIO.PCNF1.$$ = ($R.RADIO.PCNF1.$$ & ~$R.RADIO_PCNF1_MAXLEN_Msk)
        | ((encrypted ? 31 : 37) << $R.RADIO_PCNF1_MAXLEN_Pos)
}
