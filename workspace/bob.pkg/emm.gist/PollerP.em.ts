import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as Poller from '@em.mcu/Poller.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    // Common.GlobalInterrupts.enable()
    $['%%d']
    Poller.pause(200)
    $['%%d']
}