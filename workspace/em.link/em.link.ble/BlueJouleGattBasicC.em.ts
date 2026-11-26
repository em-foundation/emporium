import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BlueJouleGattP from '@em.link.ble/BlueJouleGattP.em'
import * as Controller from '@em.link.ble/Controller.em'

export namespace em$meta {
    export function em$configure() {
        Controller.security_enabled.$$val = false
        $using(BlueJouleGattP)
    }
}
