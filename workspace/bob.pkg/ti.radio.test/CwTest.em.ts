import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as RadioConfig from '@ti.radio.cc23xx/RadioConfig.em'
import * as RadioDriver from '@ti.radio.cc23xx/RadioDriver.em'

export const AppLed = $delegate(BoardC.AppLed)

const hailF = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$configure() {
        RadioConfig.phy.$$ = RadioConfig.Phy.PROP_250K
    }
    export function em$construct() {
        hailF.$$ = FiberMgr.em$meta.create($cb(hailFB))
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    hailF.$$.$$.post()
    FiberMgr.run()
}

function hailFB(a: arg_t) {
    RadioDriver.enable()
    RadioDriver.startCw(17, 5)
    AppLed.$$.on()
    RadioDriver.waitReady()
    halt()
}