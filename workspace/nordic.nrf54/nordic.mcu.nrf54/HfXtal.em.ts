import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'
import * as Common from '@em.mcu/Common.em'


export namespace em$meta { }

//>> ---- em$targ ---- <<//

const POLL_LIMIT = 1000000

export function start() {
    $R.CLOCK.INTENCLR.$$ = $R.CLOCK_INTENSET_XOSTARTED_Msk | $R.CLOCK_INTENSET_XOTUNED_Msk
    $R.CLOCK.EVENTS_XOSTARTED.$$ = 0
    $R.CLOCK.EVENTS_XOTUNED.$$ = 0
    $R.CLOCK.TASKS_PLLSTART.$$ = 1
    $R.CLOCK.TASKS_XOSTART.$$ = 1
    let polls: u32 = 0
    while ($R.CLOCK.EVENTS_XOSTARTED.$$ == 0 && polls < POLL_LIMIT) polls += 1
    if ($R.CLOCK.EVENTS_XOSTARTED.$$ == 0) {
        printf`BLE HF: XOSTARTED timeout; XO=%08x PLL=%08x\n`($R.CLOCK.XO.STAT.$$, $R.CLOCK.PLL.STAT.$$)
        fail()
        return
    }
    $R.CLOCK.TASKS_XOTUNE.$$ = 1
}

export function wait() {
    Common.BusyWait.wait(400) // blocking enable() retains the original settling delay
    waitSettled()
}

// Caller has already allowed the 400 us settling interval to elapse.
export function waitSettled() {
    let polls: u32 = 0
    while ($R.CLOCK.EVENTS_XOTUNED.$$ == 0 && polls < POLL_LIMIT) polls += 1
    if ($R.CLOCK.EVENTS_XOTUNED.$$ == 0) {
        printf`BLE HF: XOTUNED timeout; XO=%08x PLL=%08x\n`($R.CLOCK.XO.STAT.$$, $R.CLOCK.PLL.STAT.$$)
        fail()
        return
    }
}

export function stop() {
    $R.CLOCK.TASKS_XOTUNEABORT.$$ = 1
    $R.CLOCK.TASKS_XOSTOP.$$ = 1
    $R.CLOCK.TASKS_PLLSTOP.$$ = 1
    let polls: u32 = 0
    while ($R.CLOCK.PLL.STAT.$$ != 0 && polls < POLL_LIMIT) polls += 1
    if ($R.CLOCK.PLL.STAT.$$ != 0) {
        printf`BLE HF: PLL stop timeout\n`()
        fail()
        return
    }
    $R.CLOCK.EVENTS_XOTUNED.$$ = 0
}
