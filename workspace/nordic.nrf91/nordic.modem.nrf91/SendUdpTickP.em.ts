import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@nordic.distro.nrf91/BoardC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Modem from '@nordic.modem.nrf91/Modem.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'

import * as TT from '@em.utils/TimeTypes.em'

const AppLed = $delegate(BoardC.AppLed)

const send_ticker = $config<TickerMgr.Obj>()

var payload = $table<u8>()

export namespace em$meta {
    export function em$construct() {
        for (const _ of $range(20)) {
            payload.$$add()
        }
        send_ticker.$$val = TickerMgr.em$meta.create()
    }
}

//>> ---- em$targ ---- <<//

const SERVER_ADDR = 0x08080808
const SERVER_PORT = 2469

export function em$run() {
    Modem.init()
    if (!Modem.enable()) fail()
    if (!Modem.openUdp(SERVER_ADDR, SERVER_PORT)) fail()
    send_ticker.$$.start(TT.Secs30p2_initMsecs(5000), $cb(sendTickCb))
    FiberMgr.run()
}

function sendTickCb() {
    for (const _ of $range(1)) {
        $['%%c']
        AppLed.wink(10)
        if (!Modem.send(payload.$ptr(), payload.$len)) fail()
    }
}

