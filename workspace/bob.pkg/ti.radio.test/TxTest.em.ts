import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as RadioConfig from '@ti.radio.cc23xx/RadioConfig.em'
import * as RadioDriver from '@ti.radio.cc23xx/RadioDriver.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as TimeTypes from '@em.utils/TimeTypes.em'

export const AppLed = $delegate(BoardC.AppLed)

const tx_ticker = $config<TickerMgr.Obj>()

let pktbuf = $table<u8>('rw')

export namespace em$meta {
    export function em$configure() {
        RadioConfig.phy.$$ = RadioConfig.Phy.BLE_1M
    }
    export function em$construct() {
        tx_ticker.$$ = TickerMgr.em$meta.create()
        for (const _ of $range(5)) pktbuf.$add(0)
    }
}

//>> ---- em$targ ---- <<//

let dat = <u8>0

export function em$run() {
    pktbuf[0] = <u8>pktbuf.$len - 1
    tx_ticker.$$.$$.start(TimeTypes.Secs24p8_initMsecs(1_000), $cb(txTickCb))
    FiberMgr.run()
}

function txTickCb() {
    AppLed.$$.wink(5);
    RadioDriver.enable()
    for (const i of $range(1, pktbuf.$len)) {
        pktbuf[i] = dat
        dat += 1
    }
    RadioDriver.startTx(pktbuf.$frame(0), 17, 5)
    RadioDriver.waitReady()
    RadioDriver.disable()
}