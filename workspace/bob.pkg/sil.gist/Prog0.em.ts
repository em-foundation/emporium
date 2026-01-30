import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    const port = 0
    const pin = 4
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_HFRCO0
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_GPIO
    $R.GPIO.P[port].MODEL.$$ = $R.GPIO_P_MODEL_MODE0_PUSHPULL << (pin * 4)
    $R.GPIO.P_SET[port].DOUT.$$ = 1 << pin
}