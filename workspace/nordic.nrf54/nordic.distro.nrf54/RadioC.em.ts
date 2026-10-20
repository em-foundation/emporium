import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Controller from '@em.link.ble/Controller.em'
import * as HfXtal from '@nordic.mcu.nrf54/HfXtal.em'
import * as Idle from '@nordic.mcu.nrf54/Idle.em'
import * as PacketCrypto from '@nordic.radio.nrf54/PacketCrypto.em'
import * as RadioDriver from '@nordic.radio.nrf54/RadioDriver.em'

// Hardware CCM packet protection; the controller supplies counters and encryption state.
export { PacketCrypto, RadioDriver }

// TEMP: synchronized JS220 markers on B (CPU), C (crystal), D (RX); all active low.
const ENERGY_TRACE = false

export function em$configure() {
    Idle.energy_trace.$$val = ENERGY_TRACE
    HfXtal.energy_trace.$$val = ENERGY_TRACE
    RadioDriver.energy_trace.$$val = ENERGY_TRACE
    RadioDriver.hardware_tifs.$$val = true // FIX: enforce connected BLE turnaround in hardware, as on nRF52
    RadioDriver.scheduled_rx.$$val = true // scheduled RX with the driver startup guard
    Controller.hfclk_guard_us.$$val = 1500 // FIX: allow cold crystal start and hardware-TIFS RX ramp-up
}
