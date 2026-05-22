import '@$$emscript'
export const $U = $declare('MODULE')

import * as SchemaC from '@em.link/SchemaC.em'
import * as SchemaI from '@em.link/SchemaI.em'
import * as TB from '@em.link.ble/Types.em'

export const AppSchema = $proxy<SchemaI.$I>()

const ADV_DATA = $table<u8>()
const SCAN_RSP_DATA = $table<u8>()

export namespace em$meta {

    var sch_info: SchemaC.Info

    export function em$construct() {
        sch_info = SchemaC.makeInfo(AppSchema.$U!.uid)
        TB.em$meta.addAdvFlags(ADV_DATA)
        TB.em$meta.addAdvUuid128(ADV_DATA, sch_info.uuid)
        TB.em$meta.addAdvName(SCAN_RSP_DATA, sch_info.name)
    }

    export function getTxBufSize(): u16 {
        return 40
    }

    export function getRxBufSize(): u16 {
        return 40
    }
}

//>> ---- em$targ ---- <<//

export function initAdvPkt(pkt: $$<TB.AdvHdr>) {
    pkt.$$.init(TB.ADV_IND)
    pkt.$$.addData(ADV_DATA.$frame(0))
}

export function initScanRspPkt(pkt: $$<TB.AdvHdr>) {
    pkt.$$.init(TB.ADV_SCAN_RSP)
    pkt.$$.addData(SCAN_RSP_DATA.$frame(0))
}
