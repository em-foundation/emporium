import '@$$emscript'
export const $U = $declare('MODULE', GlobalInterruptsI)

import * as GlobalInterruptsI from '@em.hal/GlobalInterruptsI.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function disable(): GlobalInterruptsI.Key {
    return 0
}

export function enable() {
    return
}

export function isEnabled(): bool_t {
    return false
}

export function restore(key: GlobalInterruptsI.Key) {
    return
}
