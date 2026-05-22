import '@$$emscript'
export const $U = $declare('MODULE')

import * as SchemaC from '@em.link/SchemaC.em'
import * as SchemaI from '@em.link/SchemaI.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

export const AppSchema = $proxy<SchemaI.$I>()

const ADV_DATA = $table<u8>()
const ATT_ERROR_DATA = $table<u8>()
const CHARACTERISTIC_DATA = $table<u8>()
const FIND_INFO_DATA = $table<u8>()
const FIND_INFO_ERROR_DATA = $table<u8>()
const MTU_DATA = $table<u8>()
const PRIMARY_SERVICE_DATA = $table<u8>()
const SCAN_RSP_DATA = $table<u8>()

export namespace em$meta {

    var sch_info: SchemaC.Info

    export function em$construct() {
        sch_info = SchemaC.makeInfo(AppSchema.$U!.uid)
        TB.em$meta.addAdvFlags(ADV_DATA)
        TB.em$meta.addAdvUuid128(ADV_DATA, sch_info.uuid)
        TB.em$meta.addAdvName(SCAN_RSP_DATA, sch_info.name)
        //
        TB.em$meta.addGattPrimaryService(PRIMARY_SERVICE_DATA, sch_info.uuid, 0x0001, 0x0005)
        TB.em$meta.addGattCharacteristics(CHARACTERISTIC_DATA, sch_info.resources)
        //
        TB.em$meta.addAttError(ATT_ERROR_DATA, 0, 0x0001, TB.ATT_ATTR_NOT_FOUND)
        TB.em$meta.addAttError(FIND_INFO_ERROR_DATA, TB.ATT_FIND_INFORMATION_REQ, 0x0001, TB.ATT_ATTR_NOT_FOUND)
        TB.em$meta.addGattFindInfo(FIND_INFO_DATA)
        TB.em$meta.addAttMtu(MTU_DATA)
    }

    export function getTxBufSize(): u16 {
        return 100
    }

    export function getRxBufSize(): u16 {
        return 100
    }
}

//>> ---- em$targ ---- <<//

var find_req: TB.GattFindReq
var type_req: TB.GattTypeReq

export function initAdvPkt(pkt: $$<TB.AdvHdr>) {
    pkt.$$.init(TB.ADV_IND)
    pkt.$$.addData(ADV_DATA.$frame(0))
}

export function initScanRspPkt(pkt: $$<TB.AdvHdr>) {
    pkt.$$.init(TB.ADV_SCAN_RSP)
    pkt.$$.addData(SCAN_RSP_DATA.$frame(0))
}

export function reqGatt(att_pkt: $$<TB.AttPkt>, rsp_pkt: $$<TB.LnkHdr>): bool_t {
    let att_rsp_op = 0
    let att_rsp_data = <TL.BufFrame>$null
    switch (att_pkt.$$.opcode) {
        case TB.ATT_READ_BY_GROUP_TYPE_REQ: {
            type_req.init(att_pkt)
            if (type_req.typeId == TB.GATT_PRIMARY_SERVICE) {
                att_rsp_op = TB.ATT_READ_BY_GROUP_TYPE_RSP
                att_rsp_data = PRIMARY_SERVICE_DATA.$frame(0)
            }
            break
        }
        case TB.ATT_READ_BY_TYPE_REQ: {
            type_req.init(att_pkt)
            if (type_req.typeId == TB.GATT_CHARACTERISTIC) {
                att_rsp_op = TB.ATT_READ_BY_TYPE_RSP
                att_rsp_data = CHARACTERISTIC_DATA.$frame(0)
            }
            break
        }
        case TB.ATT_EXCHANGE_MTU_REQ: {
            att_rsp_op = TB.ATT_EXCHANGE_MTU_RSP
            att_rsp_data = MTU_DATA.$frame(0)
            break
        }
        case TB.ATT_FIND_INFORMATION_REQ: {
            find_req.init(att_pkt)

            if (find_req.startHandle <= 0x0001 && find_req.endHandle >= 0x0001) {
                att_rsp_op = TB.ATT_FIND_INFORMATION_RSP
                att_rsp_data = FIND_INFO_DATA.$frame(0)
            } else {
                att_rsp_op = TB.ATT_ERROR_RESPONSE
                att_rsp_data = FIND_INFO_ERROR_DATA.$frame(0)
            }
            break
        }
        default: {
            return false
        }
    }
    if (att_rsp_data.$len == 0) {
        return false
    }
    rsp_pkt.$$.init(TB.LL_START)
    rsp_pkt.$$.addAttPkt(att_rsp_op, att_rsp_data)

    // rsp_pkt.$$.print()
    // halt()

    return true
}
