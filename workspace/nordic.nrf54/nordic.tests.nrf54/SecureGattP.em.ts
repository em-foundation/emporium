import '@$$emscript'
export const $U = $declare('MODULE')

import * as BlueJouleGattP from '@em.link.ble/BlueJouleGattP.em'

export namespace em$meta { }

export function em$run() {
    printf`BLE secure GATT: connect, request pairing, then read/write\n`()
    BlueJouleGattP.em$run()
}
