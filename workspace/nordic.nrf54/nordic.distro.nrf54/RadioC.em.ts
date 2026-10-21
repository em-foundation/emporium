import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Controller from '@em.link.ble/Controller.em'
import * as HfXtal from '@nordic.mcu.nrf54/HfXtal.em'
import * as Idle from '@nordic.mcu.nrf54/Idle.em'
import * as PacketCrypto from '@nordic.radio.nrf54/PacketCrypto.em'
import * as RadioDriver from '@nordic.radio.nrf54/RadioDriver.em'

// Hardware CCM packet protection; the controller supplies counters and encryption state.
export { PacketCrypto, RadioDriver }

// TEMP: JS220 markers: A=connection window, B=CPU, C=crystal, D=RX; active low.
const ENERGY_TRACE = true // TEMP: match the saved V0 Saleae timing capture

export function em$configure() {
    Idle.energy_trace.$$val = ENERGY_TRACE
    HfXtal.energy_trace.$$val = ENERGY_TRACE
    RadioDriver.energy_trace.$$val = ENERGY_TRACE
    RadioDriver.timing_trace.$$val = false // TEMP: isolate timestamp collection from the retained diagnostic code
    RadioDriver.hardware_tifs.$$val = true // TEMP: restore hardware turnaround with legacy ramp; verify long-run connections
    RadioDriver.scheduled_rx.$$val = true // scheduled RX with the driver startup guard
    Controller.connection_trace.$$val = true // TEMP: A low from accepted CONNECT_IND through CLOSED/HANGUP
    Controller.hfclk_guard_us.$$val = 750 // TEMP: restore RX startup margin for hardware TIFS legacy ramp
}
