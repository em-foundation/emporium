import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as AppLed from '@bob.scratch/AppLed.em'
import * as AppLedPin from '@bob.scratch/AppLedPin.em'

export namespace em$meta {
    export function em$configure() {
        AppLed.Pin.$$ = AppLedPin
    }
}

export function em$run() {
    AppLed.on()
    halt()
}
