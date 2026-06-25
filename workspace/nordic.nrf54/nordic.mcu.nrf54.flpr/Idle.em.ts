import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as IdleI from '@em.hal/IdleI.em'

export namespace em$meta {
    export function addSleepEnter(cb: IdleI.SleepCB) { }
    export function addSleepLeave(cb: IdleI.SleepCB) { }
}

//>> ---- em$targ ---- <<//

let cur_level: IdleI.SleepLevel = 0

export function exec() {
    e$`asm volatile ("fence" ::: "memory")`
    e$`asm volatile ("csrs mstatus, 8" ::: "memory")`
    e$`asm volatile ("wfi" ::: "memory")`
}

export function getLevel(): IdleI.SleepLevel { return cur_level }

export function setLevel(level: IdleI.SleepLevel) { cur_level = level }

export function wakeup() { }
