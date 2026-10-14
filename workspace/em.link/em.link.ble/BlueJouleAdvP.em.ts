import '@$$emscript'
export const $U = $declare('MODULE')

import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Heap from '@em.utils/Heap.em'
import * as Link from '@em.link/Link.em'
import * as LinkC from '@em.link/LinkC.em'
import * as Registry from '@em.link/Registry.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'
import * as TT from '@em.utils/TimeTypes.em'

const ticker = $config<TickerMgr.Obj>()
const tx_adr = $config<Heap.Adr>()

var adv_pkt = $table<u8>()
const ADV_DATA = $table<u8>()

export namespace em$meta {
    export function em$configure() {
        $using(LinkC)
        Registry.DEFAULT_PARAMS.$$val.radio_phy = TL.Phy.BLE_1M
        Registry.DEFAULT_PARAMS.$$val.radio_power = 0
    }
    export function em$construct() {
        ticker.$$val = TickerMgr.em$meta.create()
        TB.em$meta.addAdvFlags(ADV_DATA)
        TB.em$meta.addAdvName(ADV_DATA, 'BlueJoule')
        TB.em$meta.addAdvManufacturerData(ADV_DATA, 0x08d3, [0xff])
        tx_adr.$$val = Heap.em$meta.alloc($sizeof<TB.AdvHdr>() + ADV_DATA.$len)
    }
}

//>> ---- em$targ ---- <<//

const adv_hdr = <$$<TB.AdvHdr>>Heap.opaq(tx_adr)

export function em$startup() {
    adv_hdr.$$.init(TB.ADV_NONCONN_IND)
    adv_hdr.$$.addData(ADV_DATA.$frame(0))
}

export function em$run() {
    adv_hdr.$$.print()
    ticker.$$.start(TT.Secs30p2_initMsecs(1000), $cb(tickCb))
    FiberMgr.run()
}

function tickCb() {
    Link.RadioDriver.enable()
    for (const chan of $range(37, 40)) {
        Link.RadioDriver.startTx(adv_hdr.$$.frame(), chan)
        Link.RadioDriver.waitReady()
    }
    Link.RadioDriver.disable()
}