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
const RadioDriver = $delegate(BoardC.RadioDriver) // TEMP: deferred timing diagnostic

const ticker = $config<TickerMgr.Obj>()

export namespace em$meta {
    export function em$configure() {
        $using(LinkC)
        Binder.AppSchema.$$dlg = AppSchema
        Controller.Led.$$dlg = $delegate(BoardC.AppLed)
        Registry.DEFAULT_PARAMS.$$val.ble_connectible = true
        Registry.DEFAULT_PARAMS.$$val.ble_adv_chan_mask = 0x1
        Registry.DEFAULT_PARAMS.$$val.send_count = 15
        Registry.DEFAULT_PARAMS.$$val.send_interval_ms = 25 // spread discovery opportunities across the benchmark cycle
    }
    export function em$construct() {
        ticker.$$val = TickerMgr.em$meta.create()
        Controller.em$meta.bindStatusHandler($cb(statusHandler))
    }
}

//>> ---- em$targ ---- <<//

const CACHE_STATS = false

var cycle_active: bool_t = false
var timing_connected: bool_t = false // TEMP: report the first attempted connection, including hangup
var timing_reported: bool_t = false

export function em$run() {
    ticker.$$.start(TT.Secs30p2_initMsecs(1000), $cb(tickCb))
    FiberMgr.run()
}

function tickCb() {
    if (cycle_active) return
    cycle_active = true
    Controller.start()
}

function statusHandler(stat: TL.ConnectionStatus) {
    switch (stat) {
        case TL.ConnectionStatus.OPENING:
            timing_connected = true
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
            if (timing_connected && !timing_reported) {
                timing_reported = true
                printf`BLE timing connection status=%d\n`(stat)
                RadioDriver.printTimingTrace()
            }
            cycle_active = false
            break
    }
}
