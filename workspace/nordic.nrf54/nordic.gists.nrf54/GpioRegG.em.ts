import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_LED_PORT = 2
const APP_LED_PIN = 9

export function em$run() {
    const pn = APP_LED_PORT
    const mask = 1 << APP_LED_PIN
    $R.P[pn].DIRSET.$$ = mask
    $R.P[pn].OUTSET.$$ = mask
}