import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'

import * as Idle from '@nordic.mcu.nrf52/Idle.em'
import * as Rtc from '@nordic.mcu.nrf52/Rtc.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var ready: volatile_t<bool_t> = false

export function start() {
    ready = false
    $R.CLOCK.INTENSET.$$ = $R.CLOCK_INTENSET_HFCLKSTARTED_Set
    $R.CLOCK.EVENTS_HFCLKSTARTED.$$ = 0
    $R.CLOCK.TASKS_HFCLKSTART.$$ = 1
}

export function stop() {
    $R.CLOCK.TASKS_HFCLKSTOP.$$ = 1
    $R.CLOCK.EVENTS_HFCLKSTARTED.$$ = 0
}

export function wait() {
    const ctr = Rtc.getCounter()
    Rtc.enableAux(ctr + 13, $cb(rtcHandler)) // ~400us
    while (!ready) {
        Idle.exec()
    }
    $['%%c+']
    while ($R.CLOCK.EVENTS_HFCLKSTARTED.$$ == 0) {
    }
    $['%%c-']
}

function rtcHandler() {
    ready = true
    Rtc.disableAux()
}
