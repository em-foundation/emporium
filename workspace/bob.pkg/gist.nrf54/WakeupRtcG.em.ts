import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Common from '@em.mcu/Common.em'

export function em$run() {
    $R.GRTC.TASKS_STOP.$$ = 1
    $R.GRTC.MODE.$$ = $R.GRTC_MODE_SYSCOUNTEREN_Msk
    $R.GRTC.TASKS_START.$$ = 1
    $R.GRTC.CC[0].CCL.$$ = 100000
    $R.GRTC.CC[0].CCH.$$ = 0
    $R.GRTC.CC[0].CCEN.$$ = 1
    $R.GRTC.INTENSET0.$$ = 1
    $R.GRTC.EVENTS_COMPARE[0].$$ = 0
    $['%%a+']
    while ($R.GRTC.EVENTS_COMPARE[0].$$ == 0) { }
    $['%%a-']
}