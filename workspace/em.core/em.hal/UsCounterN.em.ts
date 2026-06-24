import '@$$emscript'
export const $U = $declare('MODULE', UsCounterI)

import * as UsCounterI from '@em.hal/UsCounterI.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function set(time_us: u32) { }

export function spin() { }

export function start() { }

export function stop(): u32 { return 0 }
