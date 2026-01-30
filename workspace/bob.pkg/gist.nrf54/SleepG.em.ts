import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as BusyWait from '@nordic.mcu.nrf54/BusyWait.em'

//>> ---- em$targ ---- <<//

export function em$run() {
    $R.REGULATORS.VREGMAIN.DCDCEN.$$ = 1
    // const mask = 1 << 14
    // const pn = 1
    // $R.P[pn].DIRSET.$$ = mask
    // $R.P[pn].OUTSET.$$ = mask
    BusyWait.wait(5_000_000)
    // $R.P[pn].OUTCLR.$$ = mask
    // $R.P[pn].PIN_CNF[14].$$ = $R.GPIO_PIN_CNF_INPUT_Msk
    // $R.POWER.TASKS_LOWPWR.$$ = 1
    e$`__disable_irq()`
    e$`__set_BASEPRI(0)`
    e$`asm volatile ("isb")`
    e$`asm volatile ("dsb sy")`
    e$`asm volatile ("wfi")`
}
