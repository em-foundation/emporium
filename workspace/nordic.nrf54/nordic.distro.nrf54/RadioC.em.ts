import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Controller from '@em.link.ble/Controller.em'
import * as PacketCrypto from '@nordic.radio.nrf54/PacketCrypto.em'
import * as RadioDriver from '@nordic.radio.nrf54/RadioDriver.em'

// Hardware CCM packet protection; the controller supplies counters and encryption state.
export { PacketCrypto, RadioDriver }

export function em$configure() {
    RadioDriver.hardware_tifs.$$val = true // FIX: enforce connected BLE turnaround in hardware, as on nRF52
    Controller.hfclk_guard_us.$$val = 1500 // FIX: allow cold crystal start and hardware-TIFS RX ramp-up
}
