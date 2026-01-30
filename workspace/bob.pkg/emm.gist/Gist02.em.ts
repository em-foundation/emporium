import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'

const AppLedPin = $delegate(BoardC.AppLedPin)
const SysLedPin = $delegate(BoardC.SysLedPin)

export namespace em$meta {
}

//>> ---- em$targ ---- <<//

export function em$run() {
    AppLedPin.makeOutput()
    AppLedPin.set()
    SysLedPin.makeOutput()
    SysLedPin.clear()
}