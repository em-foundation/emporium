import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    $['%%a+']
    $R.CLOCK.TASKS_HFCLKSTART.$$ = 1
    while ($R.CLOCK.EVENTS_HFCLKSTARTED.$$ == 0) { }
    $['%%a-']
}