import '@$$emscript'
export const $U = $declare('MODULE')

import * as AlarmMgr from '@em.utils/AlarmMgr.em'
import * as BoardC from '@$distro/BoardC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Registry from '@em.link/Registry.em'
import * as TL from '@em.link/Types.em'
import * as TT from '@em.utils/TimeTypes.em'

export const AppLed = $delegate(BoardC.AppLed)
export const RadioDriver = $delegate(BoardC.RadioDriver)

const alarm = $config<AlarmMgr.Obj>()
const fiber = $config<FiberMgr.Obj>()

var pktbuf = $table<u8>()

export namespace em$meta {
    export function em$init() {
        for (const _ of $range(50)) pktbuf.$$add(0)
    }
    export function em$configure() {
        Registry.DEFAULT_PARAMS.$$val.radio_phy = TL.Phy.BLE_1M
    }
    export function em$construct() {
        fiber.$$val = FiberMgr.em$meta.create($cb(fiberF))
        alarm.$$val = AlarmMgr.em$meta.create(fiber)
    }
}

//>> ---- em$targ ---- <<//

const CHAN = 37
const RATE = 1000

export function em$run() {
    fiber.$$.post()
    FiberMgr.run()
}

function fiberF(_: arg_t) {
    RadioDriver.enable()
    RadioDriver.startRx(pktbuf.$ptr(), CHAN, 0)
    RadioDriver.waitReady()
    AppLed.wink(5)
    for (const b of pktbuf.$frame(0)) printf`%02x `(b)
    printf`\n`()
    RadioDriver.disable()
    alarm.$$.wakeup(TT.Secs30p2_initMsecs(RATE))
}