import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const app_led = 8
const sys_led = 6

export function em$run() {
    $R.GPIO.RegGPIOOutputEn.$$ |= 1 << app_led
    $R.GPIO.RegGPIODataOutSet.$$ = 1 << app_led
    $R.GPIO.RegGPIOOutputEn.$$ |= 1 << sys_led
    $R.GPIO.RegGPIODataOutClr.$$ = 1 << sys_led
}
