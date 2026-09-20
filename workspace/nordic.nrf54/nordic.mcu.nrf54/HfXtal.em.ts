import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as Rtc from '@nordic.mcu.nrf54/Rtc.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var ready: volatile_t<bool_t> = false

export function start() {
    ready = false
    $R.CLOCK.EVENTS_XOTUNED.$$ = 0
    $R.CLOCK.TASKS_PLLSTART.$$ = 1
    $R.CLOCK.TASKS_XOSTART.$$ = 1
    while ($R.CLOCK.EVENTS_XOSTARTED.$$ == 0) { }
    $R.CLOCK.TASKS_XOTUNE.$$ = 1
}

export function stop() {
    $R.CLOCK.TASKS_XOTUNEABORT.$$ = 1
    $R.CLOCK.TASKS_XOSTOP.$$ = 1
    $R.CLOCK.TASKS_PLLSTOP.$$ = 1
    $R.CLOCK.EVENTS_XOTUNED.$$ = 0
    while ($R.CLOCK.PLL.STAT.$$ != 0) { }
}

export function wait() {
    const usecs = Rtc.getRawUsecs()
    Rtc.enableAux(usecs + 400, $cb(rtcHandler))
    while (!ready) {
        Common.Idle.exec()
    }
    // $['%%c+']
    while ($R.CLOCK.EVENTS_XOTUNED.$$ == 0) { }
    // $['%%c-']
}

function rtcHandler() {
    ready = true
    Rtc.disableAux()
}


