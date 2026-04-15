import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Idle from '@nordic.mcu.nrf54/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as Poller from '@em.mcu/Poller.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function start() {
    $R.CLOCK.EVENTS_XOTUNED.$$ = 0
    e$`asm volatile ("dsb sy")`
    $R.CLOCK.TASKS_PLLSTART.$$ = 1
    e$`asm volatile ("dsb sy")`
    $R.CLOCK.TASKS_XOSTART.$$ = 1
    e$`asm volatile ("dsb sy")`
    while ($R.CLOCK.EVENTS_XOSTARTED.$$ == 0) { }
    // $R.CLOCK.TASKS_XOTUNE.$$ = 1
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
    $['%%c+']
    while ($R.CLOCK.EVENTS_XOTUNED.$$ == 0) { }
    $['%%c-']
}
