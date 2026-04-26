import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Registry from '@em.link/Registry.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as TL from '@em.link/Types.em'
import * as TT from '@em.utils/TimeTypes.em'

export const RadioDriver = $delegate(BoardC.RadioDriver)

const ticker = $config<TickerMgr.Obj>()

var adv_pkt = $table<u8>()

export namespace em$meta {
    export function em$construct() {
        ticker.$$val = TickerMgr.em$meta.create()
        let bytes = [
            0x22, 25, 0xCC, 0xCC, 0xBB, 0xBB, 0xAA, 0xAA,
            0x2, 0x01, 0x06,
            0xA, 0x08, c$`B`, c$`l`, c$`u`, c$`e`, c$`J`, c$`o`, c$`u`, c$`l`, c$`e`,
            0x4, 0xFF, 0xD3, 0x08, 0xFF]
        for (const b of bytes) {
            adv_pkt.$$add(b)
        }
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    Registry.setupParams($cb(setup))
    ticker.$$.start(TT.Secs30p2_initMsecs(1000), $cb(tickCb))
    FiberMgr.run()
}

function setup(params: $$<TL.Params>) {
    params.$$.radio_phy = TL.Phy.BLE_1M
    params.$$.radio_power = 0
}

function tickCb() {
    RadioDriver.enable(Registry.getParams())
    for (const chan of $range(37, 40)) {
        RadioDriver.startTx(adv_pkt.$frame(0), chan)
        RadioDriver.waitReady()
    }
    RadioDriver.disable()
}