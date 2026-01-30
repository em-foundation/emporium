import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'

const AppButPin = $delegate(BoardC.AppButPin)
const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    AppButPin.makeInput()
    AppButPin.setInternalPullup(true)
    for (const i of $range(100)) {
        Common.BusyWait.wait(1_000_000)
        AppLed.on()
        Common.BusyWait.wait(20_000)
        AppLed.off()
        printf`%02d: pin = %d\n`(i, AppButPin.get())
    }
}