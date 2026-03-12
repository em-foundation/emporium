import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Poller from '@em.mcu/Poller.em'

export const AppLed = $delegate(BoardC.AppLed)
export const OneShot = $delegate(BoardC.OneShot)

const blinkF = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        blinkF.$$val = FiberMgr.em$meta.create($cb(blinkFB))
    }
}

//>> ---- em$targ ---- <<//

var count = <u8>5

export function em$run() {
    blinkF.$$.post()
    FiberMgr.run()
}

function blinkFB(a: arg_t) {
    $['%%d']
    if (count-- == 0) halt()
    AppLed.on()
    Poller.upause(5_000)
    AppLed.off()
    OneShot.uenable(1_000_000, $cb(handler), 0)
}

function handler(arg: arg_t) {
    $['%%c']
    blinkF.$$.post()
}
