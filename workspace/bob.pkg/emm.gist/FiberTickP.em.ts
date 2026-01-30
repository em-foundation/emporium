import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'

export const AppLed = $delegate(BoardC.AppLed)
export const OneShot = $delegate(BoardC.OneShot)

const blinkF = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        blinkF.$$val = FiberMgr.em$meta.create($cb(blinkFB))
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    // blinkF.$$.post()
    // Common.GlobalInterrupts.enable()
    OneShot.enable(500, tickHandler, 0)
    // Common.Idle.exec()
    FiberMgr.run()
}

function blinkFB(a: arg_t) {
    // AppLed.on()
    // Common.BusyWait.wait(500_000)
    // AppLed.off()
    AppLed.wink(500)
    halt()
}

function tickHandler(a: arg_t) {
    blinkF.$$.post()
}