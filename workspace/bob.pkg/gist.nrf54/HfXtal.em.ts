import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var ready: volatile_t<bool_t> = false

export function start() {
    ready = false
    $R.CLOCK.EVENTS_XOTUNED.$$ = 0
    e$`asm volatile ("dsb sy")`
    $R.CLOCK.TASKS_PLLSTART.$$ = 1
    e$`asm volatile ("dsb sy")`
    $R.CLOCK.TASKS_XOSTART.$$ = 1
    e$`asm volatile ("dsb sy")`
    $R.CLOCK.TASKS_XOTUNE.$$ = 1
}

export function stop() {
    $R.CLOCK.TASKS_XOTUNEABORT.$$ = 1
    e$`asm volatile ("dsb sy")`
    $R.CLOCK.TASKS_XOSTOP.$$ = 1
    e$`asm volatile ("dsb sy")`
    $R.CLOCK.TASKS_PLLSTOP.$$ = 1
    e$`asm volatile ("dsb sy")`
    $R.CLOCK.EVENTS_XOTUNED.$$ = 0
    while ($R.CLOCK.PLL.STAT.$$ != 0) { }
}

export function wait() {
    while (!ready) {
        ready = $R.CLOCK.EVENTS_XOTUNED.$$ != 0
    }
}
