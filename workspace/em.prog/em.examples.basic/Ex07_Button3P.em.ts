import '@$$emscr ipt'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'

export const AppBut = $delegate(BoardC.AppBut)
export const AppLed = $delegate(BoardC.AppLed)
export const SysLed = $delegate(BoardC.SysLed)

//>> ---- em$targ ---- <<//

export function em$run() {
    AppBut.onPressed($cb(onPressedH), 100, 4000)
    FiberMgr.run()
}

function onPressedH() {
    $['%%c']
    if (AppBut.isPressed()) {
        SysLed.wink(40)
    } else {
        AppLed.wink(5)
    }
}
