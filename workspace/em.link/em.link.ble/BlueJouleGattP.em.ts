import '@$$emscript'
export const $U = $declare('MODULE')

import * as AppSchema from '@em.link.ble/BlueJouleGattS.em'
import * as Binder from '@em.link.ble/Binder.em'
import * as BoardC from '@$distro/BoardC.em'
import * as Controller from '@em.link.ble/Controller.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as LinkC from '@em.link/LinkC.em'
import * as Registry from '@em.link/Registry.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as TL from '@em.link/Types.em'
import * as TT from '@em.utils/TimeTypes.em'

const CacheStats = $delegate(BoardC.CacheStats)

const ticker = $config<TickerMgr.Obj>()

export namespace em$meta {
    export function em$configure() {
        $using(LinkC)
        Binder.AppSchema.$$dlg = AppSchema
        Controller.Led.$$dlg = $delegate(BoardC.AppLed)
        Registry.DEFAULT_PARAMS.$$val.ble_connectible = true
        Registry.DEFAULT_PARAMS.$$val.ble_adv_chan_mask = 0x1
        Registry.DEFAULT_PARAMS.$$val.send_count = 10
        Registry.DEFAULT_PARAMS.$$val.send_interval_ms = 30
    }
    export function em$construct() {
        ticker.$$val = TickerMgr.em$meta.create()
        Controller.em$meta.bindStatusHandler($cb(statusHandler))
    }
}

//>> ---- em$targ ---- <<//

const CACHE_STATS = false

export function em$run() {
    ticker.$$.start(TT.Secs30p2_initMsecs(500), $cb(tickCb))
    FiberMgr.run()
}

function tickCb() {
    Controller.start()
}

function statusHandler(stat: TL.ConnectionStatus) {
    switch (stat) {
        case TL.ConnectionStatus.OPENING:
            if (CACHE_STATS) CacheStats.start()
            break
        case TL.ConnectionStatus.CLOSED:
            if (CACHE_STATS) CacheStats.stop()
            if (CACHE_STATS) CacheStats.print()
        // fall thru
        case TL.ConnectionStatus.TIMEOUT:
        case TL.ConnectionStatus.HANGUP:
            // halt()
            Controller.stop()
            break
    }
}
