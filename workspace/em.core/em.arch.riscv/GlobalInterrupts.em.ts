import '@$$emscript'
export const $U = $declare('MODULE', GlobalInterruptsI)

import * as GlobalInterruptsI from '@em.hal/GlobalInterruptsI.em'

function MSTATUS_get(): u32 {
    let key: u32 = 0
    e$`asm volatile ("csrr %0, mstatus" : "=r"(key) :: "memory")`
    return key
}

export function disable(): GlobalInterruptsI.Key {
    const key = MSTATUS_get()
    e$`asm volatile ("csrc mstatus, 8" ::: "memory")`
    return <GlobalInterruptsI.Key>key
}

export function enable() {
    e$`asm volatile ("csrs mstatus, 8" ::: "memory")`
}

export function isEnabled(): bool_t {
    return (MSTATUS_get() & 8) != 0
}

export function restore(key: GlobalInterruptsI.Key) {
    if ((<u32>key & 8) != 0) enable()
}
