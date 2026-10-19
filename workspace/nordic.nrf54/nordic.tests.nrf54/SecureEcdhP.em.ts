import '@$$emscript'
export const $U = $declare('MODULE')

import * as BlueJouleGattP from '@em.link.ble/BlueJouleGattP.em'
import * as Smp from '@em.link.ble/Smp.em'
import * as P256Cracen from '@nordic.mcu.nrf54/P256Cracen.em'

export namespace em$meta {
    export function em$configure() {
        Smp.halt_after_key_exchange.$$val = true
        P256Cracen.light_pause.$$val = false
    }
}

export function em$run() {
    printf`BLE bring-up: connect, then request pairing; halt after public-key exchange/ECDH\n`()
    BlueJouleGattP.em$run()
}
