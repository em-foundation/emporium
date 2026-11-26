import '@$$emscript'
export const $U = $declare('MODULE')

import * as BlueJouleGattP from '@em.link.ble/BlueJouleGattP.em'
import * as Controller from '@em.link.ble/Controller.em'

export namespace em$meta {
    export function em$configure() {
        Controller.security_enabled.$$val = true
    }
}

export function em$run() {
    printf`BLE secure GATT: connect, request pairing, then read/write\n`()
    BlueJouleGattP.em$run()
}
