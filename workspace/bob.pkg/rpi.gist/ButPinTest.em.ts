import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@rpi.distro.2040/BoardC.em'

export const AppButPin = $delegate(BoardC.AppButPin)

export namespace em$meta {
}

//>> ---- em$targ ---- <<//

export function em$run() {
    const pid = AppButPin.pinId()
    AppButPin.makeInput()
    AppButPin.setInternalPullup(true)
    AppButPin.setInternalPulldown(false)
    printf`but = %d\n`(AppButPin.get())
    while (AppButPin.get()) { }
}
