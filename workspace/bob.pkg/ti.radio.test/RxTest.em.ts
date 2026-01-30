import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Config from '@em.rf.driver/Config.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as RadioDriver from '@ti.radio.cc23xx/RadioDriver.em'

export const AppLed = $delegate(BoardC.AppLed)

const rx_fiberF = $config<FiberMgr.Obj>()

var pktbuf = $table<u8>('rw', 16)

export namespace em$meta {
    export function em$configure() {
        Config.phy.$$ = Config.Phy.BLE_1M
    }
    export function em$construct() {
        rx_fiberF.$$ = FiberMgr.em$meta.create($cb(rxFiberFB))
        for (const _ of $range(32)) {
            pktbuf.$add(0)
        }
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    rx_fiberF.$$.$$.post()
    FiberMgr.run()
}

function rxFiberFB(a: arg_t) {
    RadioDriver.enable()
    RadioDriver.startRx(17, 0)
    RadioDriver.waitReady()
    const sz = RadioDriver.readPkt(pktbuf.$frame(0))
    if (sz == 0) {
        printf`*** timeout\n`()
    } else {
        for (const b of pktbuf.$frame(0, sz)) {
            printf`%02x `(b)
        }
        printf`\n`()
    }
    RadioDriver.disable()
    halt()
}