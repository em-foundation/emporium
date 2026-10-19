import '@$$emscript'
export const $U = $declare('MODULE')

import * as BlueJouleGattP from '@em.link.ble/BlueJouleGattP.em'
import * as Controller from '@em.link.ble/Controller.em'
import * as P256Cracen from '@nordic.mcu.nrf54/P256Cracen.em'
import * as RadioDriver from '@nordic.radio.nrf54/RadioDriver.em'

export namespace em$meta {
    export function em$configure() {
        RadioDriver.hardware_tifs.$$val = true
        Controller.hfclk_guard_us.$$val = 1500 // Allow cold crystal start plus hardware-TIFS RX ramp-up.
        P256Cracen.light_pause.$$val = false
    }
}

export function em$run() {
    printf`BLE secure GATT: connect, request pairing, then read/write\n`()
    BlueJouleGattP.em$run()
}
