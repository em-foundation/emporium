import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as Debug from '@em.lang/Debug.em'
import * as IdleI from '@em.hal/IdleI.em'

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

let cur_level: IdleI.SleepLevel = 0

export function em$startup() {
    $['%%b+']
}

function doPause() {
    e$`asm volatile ("csrs mstatus, 8" ::: "memory")`
    $['%%b:'](1)
    $['%%b-']
    e$`asm volatile ("wfi" ::: "memory")`
    $['%%b+']
}

function doSleep() {
    for (let cb of sleep_enter_tab) cb()
    e$`asm volatile ("csrs mstatus, 8" ::: "memory")`
    $['%%b:'](2)
    $['%%b-']
    Debug.reset()
    e$`asm volatile ("wfi" ::: "memory")`
    Debug.startup()
    $['%%b+']
    for (let cb of sleep_leave_tab) cb()
}

export function exec() {
    if (cur_level > 0) {
        doPause()
    } else {
        doSleep()
    }
}

export function getLevel(): IdleI.SleepLevel { return cur_level }

export function setLevel(level: IdleI.SleepLevel) { cur_level = level }

export function wakeup() { }
