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
    export function em$configure() {
        Registry.DEFAULT_PARAMS.$$val.radio_phy = TL.Phy.BLE_1M
        Registry.DEFAULT_PARAMS.$$val.radio_power = 0
    }
    export function em$construct() {
        ticker.$$val = TickerMgr.em$meta.create()
        let bytes = [
            // 0x22, 25,
            0x00, 9,
            0x23, 0x1A, 0xA7, 0x6D, 0x54, 0xE0,
            // 0xCC, 0xCC, 0xBB, 0xBB, 0xAA, 0xAA,
            0x2, 0x01, 0x06,
            // 0xA, 0x08, c$`B`, c$`l`, c$`u`, c$`e`, c$`J`, c$`o`, c$`u`, c$`l`, c$`e`,
            // 0x4, 0xFF, 0xD3, 0x08, 0xFF
        ]
        for (const b of bytes) {
            adv_pkt.$$add(b)
        }
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    ticker.$$.start(TT.Secs30p2_initMsecs(500), $cb(tickCb))
    FiberMgr.run()
}

function tickCb() {
    RadioDriver.enable()
    for (const chan of $range(37, 38)) {
        RadioDriver.startTx(adv_pkt.$frame(0), chan)
        RadioDriver.waitReady()
    }
    RadioDriver.disable()
}