import '@$$emscript'
export const $U = $declare('MODULE', GpioI)

import * as GpioI from '@em.hal/GpioI.em'

export namespace em$meta {
    export function pinId(): i16 { return -1 }
}

//>> ---- em$targ ---- <<//

export function clear(): void { }
export function functionSelect(select: u8): void { }
export function get(): bool_t { return false }
export function isInput(): bool_t { return false }
export function isOutput(): bool_t { return false }
export function makeInput(): void { }
export function makeOutput(): void { }
export function pinId(): i16 { return -1 }
export function reset(): void { }
export function set(): void { }
export function setInternalPulldown(enable: bool_t): void { }
export function setInternalPullup(enable: bool_t): void { }
export function toggle(): void { }
