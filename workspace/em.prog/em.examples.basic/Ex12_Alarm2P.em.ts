import '@$$emscript'
export const $U = $declare('MODULE')

import * as AlarmMgr from '@em.utils/AlarmMgr.em'
import * as BoardC from '@$distro/BoardC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as T from '@em.utils/TimeTypes.em'

export const AppLed = $delegate(BoardC.AppLed)

const alarm = $config<AlarmMgr.Obj>()
const blinkF = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        blinkF.$$val = FiberMgr.em$meta.create($cb(blinkFB))
        alarm.$$val = AlarmMgr.em$meta.create(blinkF)
    }
}

//>> ---- em$targ ---- <<//

var count = <u32>5

export function em$run() {
    blinkF.$$.post()
    FiberMgr.run()
}

function blinkFB(a: arg_t) {
    $['%%c']
    if (count-- == 0) halt()
    const msecs = (count & 0x1) != 0 ? 100 : 5
    AppLed.wink(msecs)
    alarm.$$.wakeupAligned(T.Secs30p2_initMsecs(1_500))
}
