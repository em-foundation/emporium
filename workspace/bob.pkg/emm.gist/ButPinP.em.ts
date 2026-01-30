import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'

const AppButPin = $delegate(BoardC.AppButPin)
const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta {

}

//>> ---- em$targ ---- <<//

export function em$run() {
    AppButPin.makeInput()
    AppButPin.setInternalPullup(true)

    // printf`but = %d\n`(AppButPin.get())
    // halt()

    for (const _ of $range(3)) {
        AppLed.on()
        while (AppButPin.get()) { }
        AppLed.off()
        Common.BusyWait.wait(1_000_000)
        $['%%c']
    }
    halt()
}

function handler() {
    $['%%c']
}
