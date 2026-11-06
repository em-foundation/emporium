import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as IdleI from '@em.hal/IdleI.em'

export namespace em$meta {
    export function addSleepEnter(cb: IdleI.SleepCB): void { }
    export function addSleepLeave(cb: IdleI.SleepCB): void { }
}

var cur_level: volatile_t<IdleI.SleepLevel> = 0

export function em$startup(): void {
    $['%%b+']
}

export function exec(): void {
    IntrVec.PRIMASK_set(1)
    if (cur_level > 0) {
        $['%%b:'](1)
        $['%%b-']
        e$`asm volatile ("wfi" ::: "memory")`
        $['%%b+']
    }
    IntrVec.PRIMASK_set(0)
}

export function getLevel(): IdleI.SleepLevel {
    return cur_level
}

export function setLevel(level: IdleI.SleepLevel): void {
    cur_level = level
}

export function wakeup(): void { }
