import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as SchemaC from '@em.link/SchemaC.em'
import * as SchemaI from '@em.link/SchemaI.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

export const AppSchema = $proxy<SchemaI.$I>()

type ResourceReadCb = cb_t<[TL.BufPtr], u8>
type ResourceWriteCb = cb_t<[TL.BufPtr]>

const ADV_DATA = $table<u8>()
const ATT_ERROR_DATA = $table<u8>()
const CHARACTERISTIC_DATA = $table<u8>()
const EMPTY_DATA = $table<u8>()
const FIND_BY_TYPE_ERROR_DATA = $table<u8>()
const FIND_INFO_DATA = $table<u8>()
const DESCRIPTOR_FIND_INFO_DATA = $table<u8>()
const FIND_INFO_ERROR_DATA = $table<u8>()
const GROUP_TYPE_ERROR_DATA = $table<u8>()
const MTU_DATA = $table<u8>()
const PRIMARY_SERVICE_DATA = $table<u8>()
const READ_FUNCS = $table<ResourceReadCb>()
const SCAN_RSP_DATA = $table<u8>()
const TYPE_ERROR_DATA = $table<u8>()
const WRITE_FUNCS = $table<ResourceWriteCb>()

export namespace em$meta {

    var sch_info: SchemaC.Info

    export function em$construct() {
        sch_info = SchemaC.makeInfo(AppSchema.$U!.uid)
        const schema_cname = AppSchema.$U!.uid.replaceAll('.', '_').replace('/', '_')
        TB.em$meta.addAdvFlags(ADV_DATA)
        TB.em$meta.addAdvUuid128(ADV_DATA, sch_info.uuid)
        TB.em$meta.addAdvName(SCAN_RSP_DATA, sch_info.name)
        //
        TB.em$meta.addGattPrimaryService(PRIMARY_SERVICE_DATA, sch_info.uuid, 0x0001, 0x0006)
        addGattCharacteristicData(CHARACTERISTIC_DATA, sch_info.resources)
        //
        for (let r of sch_info.resources) {
            READ_FUNCS.$$add(r.canRead ? $cb(`${r.name}_read`, schema_cname) : $cb(null))
            WRITE_FUNCS.$$add(r.canWrite ? $cb(`${r.name}_write`, schema_cname) : $cb(null))
        }
        //  
        TB.em$meta.addAttError(ATT_ERROR_DATA, 0, 0x0001, TB.ATT_ATTR_NOT_FOUND)
        TB.em$meta.addAttError(FIND_BY_TYPE_ERROR_DATA, TB.ATT_FIND_BY_TYPE_VALUE_REQ, 0x0001, TB.ATT_ATTR_NOT_FOUND)
        TB.em$meta.addAttError(FIND_INFO_ERROR_DATA, TB.ATT_FIND_INFORMATION_REQ, 0x0001, TB.ATT_ATTR_NOT_FOUND)
        TB.em$meta.addAttError(GROUP_TYPE_ERROR_DATA, TB.ATT_READ_BY_GROUP_TYPE_REQ, 0x0007, TB.ATT_ATTR_NOT_FOUND)
        TB.em$meta.addAttError(TYPE_ERROR_DATA, TB.ATT_READ_BY_TYPE_REQ, 0x0001, TB.ATT_ATTR_NOT_FOUND)
        TB.em$meta.addGattFindInfo(FIND_INFO_DATA)
        addGattUserDescriptionFindInfo(DESCRIPTOR_FIND_INFO_DATA, 0x0006)
        TB.em$meta.addAttMtu(MTU_DATA)
    }

    export function getTxBufSize(): u16 {
        return 100
    }

    export function getRxBufSize(): u16 {
        return 100
    }

    function addGattCharacteristicData(data: TB.PduData, resources: SchemaC.Resource[]) {
        var h: u16 = 0x0002
        for (let r of resources) {
            data.$$add(0x15)
            addU16(data, h)
            addProps(data, r)
            addU16(data, h + 1)
            addUuid128(data, r.uuid!)
            h += 2
        }
    }


    function addGattUserDescriptionFindInfo(data: TB.PduData, handle: u16) {
        // ATT Find Information Response, format 0x01 = handle + 16-bit UUID pairs.
        // 0x2901 is Characteristic User Description.  It is attached to the
        // preceding characteristic value handle, currently Command at 0x0005.
        data.$$add(0x01)
        addU16(data, handle)
        addU16(data, 0x2901)
    }

    function addProps(data: TB.PduData, r: SchemaC.Resource) {
        var props = 0
        if (r.canRead) props |= TB.GATT_CHARACTERISTIC_READ
        if (r.canWrite) props |= TB.GATT_CHARACTERISTIC_WRITE
        data.$$add(props)
    }

    function addU16(data: TB.PduData, value: u16) {
        data.$$add(value & 0xff)
        data.$$add(value >> 8)
    }

    function addUuid128(data: TB.PduData, uuid: string) {
        const hex = uuid.replaceAll('-', '')
        for (let i = 15; i >= 0; i--) {
            data.$$add(parseInt(hex.substring(i * 2, i * 2 + 2), 16))
        }
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
        case TB.ATT_FIND_BY_TYPE_VALUE_REQ: {
            type_req.init(att_pkt)
            if (type_req.typeId == TB.GATT_PRIMARY_SERVICE && type_req.startHandle <= 0x0001 && type_req.endHandle >= 0x0001) {
                att_rsp_op = att_pkt.$$.opcode + 1
                att_rsp_data = PRIMARY_SERVICE_DATA.$frame(1, 4)
            } else {
                att_rsp_op = TB.ATT_ERROR_RESPONSE
                att_rsp_data = FIND_BY_TYPE_ERROR_DATA.$frame(0)
            }
            break
        }
        case TB.ATT_READ_BY_GROUP_TYPE_REQ: {
            type_req.init(att_pkt)
            if (type_req.typeId == TB.GATT_PRIMARY_SERVICE && type_req.startHandle <= 0x0001 && type_req.endHandle >= 0x0001) {
                att_rsp_op = att_pkt.$$.opcode + 1
                att_rsp_data = PRIMARY_SERVICE_DATA.$frame(0)
            } else {
                att_rsp_op = TB.ATT_ERROR_RESPONSE
                att_rsp_data = GROUP_TYPE_ERROR_DATA.$frame(0)
            }
            break
        }
        case TB.ATT_READ_BY_TYPE_REQ: {
            type_req.init(att_pkt)
            if (type_req.typeId == TB.GATT_CHARACTERISTIC) {
                att_rsp_data = getCharacteristicRspData(type_req.startHandle, type_req.endHandle)
                if (att_rsp_data.$len != 0) {
                    att_rsp_op = att_pkt.$$.opcode + 1
                } else {
                    att_rsp_op = TB.ATT_ERROR_RESPONSE
                    att_rsp_data = TYPE_ERROR_DATA.$frame(0)
                }
            } else {
                att_rsp_op = TB.ATT_ERROR_RESPONSE
                att_rsp_data = TYPE_ERROR_DATA.$frame(0)
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
            } else if (find_req.startHandle <= 0x0006 && find_req.endHandle >= 0x0006) {
                att_rsp_op = TB.ATT_FIND_INFORMATION_RSP
                att_rsp_data = DESCRIPTOR_FIND_INFO_DATA.$frame(0)
            } else {
                att_rsp_op = TB.ATT_ERROR_RESPONSE
                att_rsp_data = FIND_INFO_ERROR_DATA.$frame(0)
            }
            break
        }
        case TB.ATT_READ_REQ: {
            const data = <TL.BufPtr>att_pkt.$$.dataPtr()
            const handle = Mem.scan16($$(data[0]))
            return readValue(handle, rsp_pkt)
        }
        case TB.ATT_WRITE_REQ: {
            const data = <TL.BufPtr>att_pkt.$$.dataPtr()
            const handle = Mem.scan16($$(data[0]))
            if (!writeValue(handle, <TL.BufPtr>$$(data[2]))) {
                return false
            }
            rsp_pkt.$$.init(TB.LL_START)
            rsp_pkt.$$.addAttPkt(TB.ATT_WRITE_RSP, EMPTY_DATA.$frame(0))
            return true
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

function getCharacteristicRspData(start: u16, end: u16): TL.BufFrame {
    if (end < 0x0002) {
        return $null
    }
    var idx: u16 = 0
    if (start > 0x0002) {
        idx = (start - 0x0001) >> 1
    }
    const decl: u16 = 0x0002 + (idx << 1)
    if (decl > end) {
        return $null
    }
    const off: u16 = idx * 0x16
    if (off >= CHARACTERISTIC_DATA.$len) {
        return $null
    }
    return CHARACTERISTIC_DATA.$frame(off, 0x16)
}

function isValueHandle(handle: u16): bool_t {
    return handle >= 0x0003 && (handle & 0x0001) != 0
}

function resourceIndex(handle: u16): u16 {
    return (handle - 0x0003) >> 1
}

function readResource(handle: u16, dst: TL.BufPtr): u8 {
    if (!isValueHandle(handle)) {
        return 0
    }
    const idx = resourceIndex(handle)
    if (idx >= READ_FUNCS.$len) {
        return 0
    }
    const read_fxn = READ_FUNCS[idx]
    if (read_fxn == null) {
        return 0
    }
    return read_fxn(dst)
}

function readValue(handle: u16, rsp_pkt: $$<TB.LnkHdr>): bool_t {
    rsp_pkt.$$.init(TB.LL_START)
    rsp_pkt.$$.addAttPkt(TB.ATT_READ_RSP, EMPTY_DATA.$frame(0))
    const pkt = rsp_pkt.$$.attPkt()
    const len = readResource(handle, <TL.BufPtr>pkt.$$.dataPtr())
    if (len == 0) {
        return false
    }
    pkt.$$.len += len
    rsp_pkt.$$.pduLen += len
    return true
}

function writeResource(handle: u16, src: TL.BufPtr) {
    if (!isValueHandle(handle)) {
        return
    }
    const idx = resourceIndex(handle)
    if (idx >= WRITE_FUNCS.$len) {
        return
    }
    const write_fxn = WRITE_FUNCS[idx]
    if (write_fxn == null) {
        return
    }
    write_fxn(src)
}

function writeValue(handle: u16, src: TL.BufPtr): bool_t {
    if (!isValueHandle(handle)) {
        return false
    }
    writeResource(handle, src)
    return true
}
