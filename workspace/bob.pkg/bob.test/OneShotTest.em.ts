import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as OneShot from '@adi.mcu.max326xx/OneShotTmr0.em'

export namespace em$meta { }

export function em$run() {
    Common.GlobalInterrupts.$$.enable()
    OneShot.enable(100, $cb(handler), 0)
    $['%%a+']
    while (true) Common.Idle.$$.exec()
}

function handler(a: arg_t) {
    $['%%a-']
    halt()
}
