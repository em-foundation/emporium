import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as IdleI from '@em.hal/IdleI.em'

export namespace em$meta {
    export function addSleepEnter(cb: IdleI.SleepCB) { }
    export function addSleepLeave(cb: IdleI.SleepCB) { }
}

//>> ---- em$targ ---- <<//

export function exec() { }
export function setPauseOnly(pause_only: bool_t) { }
export function wakeup() { }
