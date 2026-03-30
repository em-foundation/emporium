import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'

export const AppLed = $delegate(BoardC.AppLed)

const blinkF = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        blinkF.$$val = FiberMgr.em$meta.create($cb(blinkFB))
    }
}

//>> ---- em$targ ---- <<//

var count = 10

export function em$run() {
    blinkF.$$.post()
    FiberMgr.run()
}

function blinkFB(a: arg_t) {
    $['%%d-']
    if (count-- == 0) halt()
    Common.BusyWait.wait(500_000)
    AppLed.toggle()
    $['%%d+']
    blinkF.$$.post()
}
