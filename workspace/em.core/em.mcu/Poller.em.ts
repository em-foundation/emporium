import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as OneShotI from '@em.hal/OneShotI.em'

export const OneShot = $proxy<OneShotI.$I>()

//>> ---- em$targ ---- <<//

var done_flag: volatile_t<bool_t>

export function pause(time_ms: u32) {
    upause(time_ms * 1000)
}

export function upause(time_us: u32) {
    if (time_us == 0) return
    OneShot.uenable(time_us, $cb(handler), 0)
    done_flag = false
    while (!done_flag) Common.Idle.exec()
}

function handler(a: arg_t) {
    done_flag = true
}
