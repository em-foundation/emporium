import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@ti.distro.cc23xx/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_LED_PIN = 15

export function em$run() {
    const pin = APP_LED_PIN
    const mask = 1 << pin
    $R.GPIO.DOESET31_0.$$ = mask
    $R.IOC.IOC0.$[pin].$$ &= ~$R.IOC_IOC0_INPEN
    $R.GPIO.DOUTSET31_0.$$ = mask
}
