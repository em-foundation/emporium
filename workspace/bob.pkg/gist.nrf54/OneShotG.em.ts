import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'
import * as Common from '@em.mcu/Common.em'

export function em$run() {
    exec(2000)
    Common.BusyWait.$$.wait(100_000)
    exec(1000)
}

function exec(usecs: u32) {
    $R.TIMER20.MODE.$$ = $R.TIMER_MODE_MODE_Timer
    $R.TIMER20.BITMODE.$$ = $R.TIMER_BITMODE_BITMODE_32Bit
    $R.TIMER20.CC[0].$$ = usecs
    $R.TIMER20.INTENSET.$$ = $R.TIMER_INTENSET_COMPARE0_Enabled
    $R.TIMER20.TASKS_CLEAR.$$ = 1
    $R.TIMER20.EVENTS_COMPARE[0].$$ = 0
    $R.TIMER20.TASKS_START.$$ = 1
    $['%%a+']
    while ($R.TIMER20.EVENTS_COMPARE[0].$$ == 0) { }
    $['%%a-']
    $R.TIMER20.TASKS_STOP.$$ = 1
}