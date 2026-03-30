import '@$$emscript'
export const $U = $declare('MODULE')

import * as AlarmMgr from '@em.utils/AlarmMgr.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as T from '@em.utils/TimeTypes.em'

export type Callback = cb_t<[]>
export type Obj = $$<Ticker>

class Ticker extends $struct {
    _alarm: AlarmMgr.Obj
    _fiber: FiberMgr.Obj
    _rate: T.Secs30p2
    _tick_cb: Callback
}
interface Ticker {
    start(this: Ticker, rate: T.Secs30p2, tick_cb: Callback): void
    stop(this: Ticker): void
}

var ticker_tab = $table<Ticker>()

export namespace em$meta {
    export function create(): Obj {
        const ticker = ticker_tab.$$add()
        const fiber = FiberMgr.em$meta.create($cb(alarmFB), ticker_tab.$len - 1)
        const alarm = AlarmMgr.em$meta.create(fiber)
        ticker.$$._alarm = alarm
        ticker.$$._fiber = fiber
        return ticker
    }
}

//>> ---- em$targ ---- <<//

function alarmFB(a: arg_t) {
    const ticker = $ref(ticker_tab[<u16>a])
    if (ticker.$$._tick_cb == $null) return
    ticker.$$._tick_cb()
    ticker.$$._alarm.$$.wakeupAligned(ticker.$$._rate)
}

Ticker.prototype.start = function (this: Ticker, rate_qs: T.Secs30p2, tick_cb: Callback) {
    this._rate = rate_qs
    this._tick_cb = tick_cb
    this._alarm.$$.wakeupAligned(rate_qs)
}

Ticker.prototype.stop = function (this: Ticker) {
    this._tick_cb = $null
    this._alarm.$$.cancel()
}
