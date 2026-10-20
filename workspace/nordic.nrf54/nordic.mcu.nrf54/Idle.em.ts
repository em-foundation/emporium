import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Debug from '@em.lang/Debug.em'
import * as IdleI from '@em.hal/IdleI.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export const energy_trace = $config<bool_t>(false) // TEMP: retain marker levels and use B low=awake, high=WFI

export type SleepCB = cb_t<[]>

const sleep_enter_tab = $table<SleepCB>()
const sleep_leave_tab = $table<SleepCB>()

export namespace em$meta {
    export function addSleepEnter(cb: SleepCB) {
        sleep_enter_tab.$$add(cb)
    }

    export function addSleepLeave(cb: SleepCB) {
        sleep_leave_tab.$$add(cb)
    }
}

//>> ---- em$targ ---- <<//

var cur_level: IdleI.SleepLevel = 0

export function em$startup() {
    $['%%b+']
}

function doPause() {
    if (!energy_trace) $['%%b:'](1)
    $['%%b-']
    IntrVec.PRIMASK_set(1)
    e$`asm volatile ("wfi")`
    $['%%b+']
    IntrVec.PRIMASK_set(0)
}

function doSleep() {
    for (let cb of sleep_enter_tab) cb()
    if (!energy_trace) $['%%b:'](2)
    $['%%b-']
    if (!energy_trace) Debug.reset() // TEMP: keep C/D driven across WFI while capturing digital markers
    IntrVec.PRIMASK_set(1)
    // TEMP: cache stays enabled; Mcu retains ICACHE RAM across System ON sleep
    e$`asm volatile ("wfi")`
    // TEMP: cache stays enabled; Mcu retains ICACHE RAM across System ON sleep
    if (energy_trace) {
        Debug.DbgB.clear() // awake again; preserve C/D instead of resetting every marker
    } else {
        Debug.startup()
        $['%%b']
    }
    for (let cb of sleep_leave_tab) cb()
    IntrVec.PRIMASK_set(0)
}

export function exec() {
    if (cur_level > 0) {
        doPause()
    } else {
        doSleep()
    }
}

export function shutdown() {
    for (let cb of sleep_enter_tab) cb()
    $['%%b:'](3)
    $['%%b-']
    Debug.reset()
    $R.RESET.RESETREAS.$$ = ~0
    $R.REGULATORS.SYSTEMOFF.$$ = 1
    e$`__DSB()`

}

export function getLevel(): IdleI.SleepLevel {
    return cur_level
}

export function setLevel(level: IdleI.SleepLevel) {
    cur_level = level
}

export function wakeup() { }
