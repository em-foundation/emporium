import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as $R from '@nordic.distro.nrf54.flpr/REGS.em'

import * as CSR from '@em.arch.riscv/CSR.em'
import * as Debug from '@em.lang/Debug.em'
import * as IdleI from '@em.hal/IdleI.em'

export type SleepCB = cb_t<[]>

const sleep_enter_tab = $table<SleepCB>()
const sleep_leave_tab = $table<SleepCB>()

const CSR_NORDIC_SLEEP = 0x7c1

const NORDIC_SLEEP_WAIT = 0x00000000
const NORDIC_SLEEP_RESET = 0x00000002
const NORDIC_SLEEP_SLEEP = 0x00000005
const NORDIC_SLEEP_DEEPSLEEP = 0x00000007
const NORDIC_SLEEP_HIBERNATE = 0x0000000f

const RETURNTOSLEEP = 0x00010000
const STACKONSLEEP = 0x00020000

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
    $['%%b:'](1)
    $['%%b-']
    CSR.write(CSR_NORDIC_SLEEP, NORDIC_SLEEP_DEEPSLEEP)
    e$`asm volatile ("wfi" ::: "memory")`
    $['%%b+']
    e$`asm volatile ("csrs mstatus, 8" ::: "memory")`
}

function doSleep() {
    for (let cb of sleep_enter_tab) cb()
    $['%%b:'](2)
    $['%%b-']
    Debug.reset()
    CSR.write(CSR_NORDIC_SLEEP, NORDIC_SLEEP_HIBERNATE)
    $R.MEMCONF.POWER[1].RET.$$ = 0x1
    e$`asm volatile ("wfi" ::: "memory")`
    $R.MEMCONF.POWER[1].RET.$$ = 0x0
    Debug.startup()
    $['%%b+']
    for (let cb of sleep_leave_tab) cb()
    e$`asm volatile ("csrs mstatus, 8" ::: "memory")`
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
