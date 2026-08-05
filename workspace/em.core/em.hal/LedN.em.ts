import '@$$emscript'
export const $U = $declare('MODULE', LedI)

import * as LedI from '@em.hal/OneShotI.em'

//>> ---- em$targ ---- <<//

export function off(): void { }
export function on(): void { }
export function toggle(): void { }
export function wink(msecs: u32): void { }
