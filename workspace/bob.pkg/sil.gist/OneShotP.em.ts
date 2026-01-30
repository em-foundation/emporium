import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as OneShot from '@silabs.mcu.efr32x/OneShotTimer0.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    for (const i of $range(5)) {
        OneShot.enable(500, handler, 0)
        Common.GlobalInterrupts.enable()
        Common.Idle.exec()
        OneShot.disable()
    }
}

function handler(a: arg_t) {
    $['%%d']
}