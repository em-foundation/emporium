import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as TimeTypes from '@em.utils/TimeTypes.em'

export const AppLed = $delegate(BoardC.AppLed)

const ticker = $config<TickerMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        ticker.$$ = TickerMgr.em$meta.create()
    }
}

export function em$run() {
    ticker.$$.$$.start(TimeTypes.Secs24p8_initMsecs(1_000), $cb(tickCb))
    FiberMgr.run()
}

function tickCb() {
    $['%%c']
    AppLed.$$.on()
    Common.BusyWait.$$.wait(2500)
    AppLed.$$.off()
}
