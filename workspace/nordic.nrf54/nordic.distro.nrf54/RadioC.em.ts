import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Controller from '@em.link.ble/Controller.em'
import * as HfXtal from '@nordic.mcu.nrf54/HfXtal.em'
import * as Idle from '@nordic.mcu.nrf54/Idle.em'
import * as PacketCrypto from '@nordic.radio.nrf54/PacketCrypto.em'
import * as RadioDriver from '@nordic.radio.nrf54/RadioDriver.em'

// Hardware CCM packet protection; the controller supplies counters and encryption state.
export { PacketCrypto, RadioDriver }

// Keep only the active-low connection window for energy measurement.
const ENERGY_TRACE = false

export function em$configure() {
    Idle.energy_trace.$$val = ENERGY_TRACE
    Idle.connection_trace.$$val = true
    HfXtal.energy_trace.$$val = ENERGY_TRACE
    RadioDriver.energy_trace.$$val = ENERGY_TRACE
    RadioDriver.hardware_tifs.$$val = true // hardware turnaround uses legacy ramp
    RadioDriver.scheduled_rx.$$val = true // scheduled RX with the driver startup guard
    Controller.connection_trace.$$val = true // A low from accepted CONNECT_IND through CLOSED/HANGUP
    Controller.hfclk_guard_us.$$val = 750 // measured crystal wake lead for legacy ramp
}
