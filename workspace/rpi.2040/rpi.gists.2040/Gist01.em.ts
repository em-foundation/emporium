import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_LED_PIN = 5

export function em$run() {
    const pid = APP_LED_PIN
    const mask = 1 << pid
    // makeOutput
    $R.SIO.GPIO_OE_SET.$$ = mask
    $reg32[e$`IO_BANK0_CTRL_get(pid)`] = 5
    // set
    $R.SIO.GPIO_OUT_SET.$$ = mask

}
