import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as IdleI from '@em.hal/IdleI.em'

export namespace em$meta {
    export function addSleepEnter(cb: IdleI.SleepCB) { }
    export function addSleepLeave(cb: IdleI.SleepCB) { }
}

//>> ---- em$targ ---- <<//

export function exec() { }
export function getLevel(): IdleI.SleepLevel { return 0 }
export function setLevel(level: IdleI.SleepLevel) { }
export function wakeup() { }
