import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'

const AppButPin = $delegate(BoardC.AppButPin)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    AppButPin.makeInput()
    const b = AppButPin.get()
    printf`b = %d\n`(b)
}