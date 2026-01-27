import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as BoardC from '@rpi.distro.2040/BoardC.em'

export const AppButPin = $delegate(BoardC.AppButPin)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    AppButPin.makeInput()
    AppButPin.setInternalPulldown(true)
    printf`waiting...\n`()
    while (!AppButPin.get()) {}
    printf`but = %d\n`(AppButPin.get())
}
