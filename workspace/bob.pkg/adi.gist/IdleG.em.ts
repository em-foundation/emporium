import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@adi.distro.max326xx/BoardC.em'
import * as Common from '@em.mcu/Common.em'

export const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    AppLed.$$.on()
    Common.BusyWait.$$.wait(500_000)
    AppLed.$$.off()
    Common.Idle.$$.exec()
}