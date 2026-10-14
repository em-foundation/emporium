import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_LED_PIN = 17

export function em$run() {
    const mask = 1 << APP_LED_PIN
    $R.P0.DIRSET.$$ = mask
    $R.P0.OUTCLR.$$ = mask
}