import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as T from '@em.utils/TimeTypes.em'

export const AppLed = $delegate(BoardC.AppLed)
export const SysLed = $delegate(BoardC.SysLed)

const app_ticker = $config<TickerMgr.Obj>()
const sys_ticker = $config<TickerMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        app_ticker.$$val = TickerMgr.em$meta.create()
        sys_ticker.$$val = TickerMgr.em$meta.create()
    }
}

//>> ---- em$targ ---- <<//

var count = 5

export function em$run() {
    if (!Common.Mcu.isWarm()) {
        app_ticker.$$.start(T.Secs30p2_initMsecs(1_500), $cb(appTickCb))
        sys_ticker.$$.start(T.Secs30p2_initMsecs(1_000), $cb(sysTickCb))
    }
    FiberMgr.run()
}

function appTickCb() {
    if (count-- == 0) halt()
    $['%%c']
    AppLed.wink(100)
}

function sysTickCb() {
    $['%%d']
    SysLed.wink(100)
}
