import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    $R.CLOCK.TASKS_XOSTART.$$ = 1
    $R.CLOCK.TASKS_XOTUNE.$$ = 1
    $['%%c+']
    // while ($R.CLOCK.EVENTS_XOSTARTED.$$ == 0) { }
    // $['%%c-']
    // $['%%d+']
    while ($R.CLOCK.EVENTS_XOTUNED.$$ == 0) { }
    $['%%c-']
}