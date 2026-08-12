import '@$$emscript'
export const $U = $declare('MODULE', OneShotI)

import * as Common from '@em.mcu/Common.em'
import * as OneShotI from '@em.hal/OneShotI.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function disable(): void {
}

export function enable(msecs: u32, handler: OneShotI.Handler, arg: arg_t): void {
    uenable(msecs * 1000, handler, arg)
}

export function uenable(usecs: u32, handler: OneShotI.Handler, arg: arg_t): void {
    Common.BusyWait.wait(usecs)
    handler(arg)
}

