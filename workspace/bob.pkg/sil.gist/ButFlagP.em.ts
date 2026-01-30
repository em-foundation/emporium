import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'

const AppButPin = $delegate(BoardC.AppButPin)
const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    AppButPin.makeInput()
    $R.GPIO.EXTIPSELL_SET.$$ = $R.GPIO_EXTIPSELL_EXTIPSEL0_PORTA
    $R.GPIO.EXTIPINSELL_SET.$$ = $R.GPIO_EXTIPINSELL_EXTIPINSEL0_OFFSET0
    $R.GPIO.EXTIFALL_SET.$$ = 1
    $R.GPIO.IEN_SET.$$ = $R.GPIO_IEN_EXTIEN0
    $R.GPIO.IF_CLR.$$ = $R.GPIO_IF_EXTIF0
    // printf`PSELL = %08x, PINSELL = %08x\n`($R.GPIO.EXTIPSELL.$$, $R.GPIO.EXTIPINSELL.$$)
    // printf`IEN = %08x, IF = %08x\n`($R.GPIO.IEN.$$, $R.GPIO.IF.$$)
    AppLed.on()
    while (($R.GPIO.IF.$$ & $R.GPIO_IF_EXTIF0) == 0) { }
    // Common.BusyWait.wait(3_000_000)
    AppLed.off()
    printf`IEN = %08x, IF = %08x\n`($R.GPIO.IEN.$$, $R.GPIO.IF.$$)


}