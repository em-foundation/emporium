import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as TL from '@em.link/Types.em'

export const ADV_CHAN = 37
export const ADV_CHAN_MAX = 39

export const ADV_IND = 0x00
export const ADV_DIRECT_IND = 0x01
export const ADV_NONCONN_IND = 0x02
export const ADV_SCAN_REQ = 0x03
export const ADV_SCAN_RSP = 0x04
export const ADV_CONNECT_IND = 0x05
export const ADV_SCAN_IND = 0x06
export const ADV_EXT_IND = 0x07

export const ATT_ERROR_RESPONSE = 0x01
export const ATT_EXCHANGE_MTU_REQ = 0x02
export const ATT_EXCHANGE_MTU_RSP = 0x03
export const ATT_HANDLE_VALUE_NTF = 0x1B
export const ATT_READ_BY_TYPE_REQ = 0x08
export const ATT_READ_BY_GROUP_TYPE_REQ = 0x10
export const ATT_READ_BY_GROUP_TYPE_RSP = 0x11
export const ATT_WRITE_CMD = 0x52

export const GATT_PRIMARY_SERVICE = 0x2800
export const GATT_CHARACTERISTIC = 0x2803

export const LL_CONT = 0x01
export const LL_START = 0x02
export const LL_CTRL = 0x03

export const LL_CONN_UPDATE_IND = 0x00
export const LL_TERMINATE_IND = 0x02
export const LL_UNKNOWN_RSP = 0x07
export const LL_FEATURE_REQ = 0x08
export const LL_FEATURE_RSP = 0x09
export const LL_VERSION_IND = 0x0C
export const LL_REJECT_IND = 0x0D
export const LL_LENGTH_REQ = 0x14
export const LL_LENGTH_RSP = 0x15

export const MAN_ID_LO = 0x4C
export const MAN_ID_HI = 0x0B

export const INTERVAL_FUDGE = 3

export class AdvHdr extends $struct {
    advType: u8
    pduLen: u8
    advA: TL.Addr
    flagsLen: u8
    flagsCode: u8
    flagsVal: u8
    manLen: u8
    manCode: u8
    manIdLo: u8
    manIdHi: u8
}
export interface AdvHdr {
    addData(this: AdvHdr, src: opaq_t, len: u16): void
    addName(this: AdvHdr, name: text_t): void
    frame(this: AdvHdr): TL.BufFrame
    init(this: AdvHdr, advType: u8): void
    print(this: AdvHdr): void
    // isMine: () => bool_t
}

export class AdvReqHdr extends $struct {
    advType: u8
    pduLen: u8
    reqA: TL.Addr
    advA: TL.Addr
}
export interface AdvReqHdr {
    isConn(): bool_t
    isMine(): bool_t
    isScan(): bool_t
}

export class ConnPkt extends $struct {
    advType: u8
    pduLen: u8
    initA: TL.Addr
    advA: TL.Addr
    accAdr: vec_t<u8, 4>
    crcInit: vec_t<u8, 3>
    winSize: u8
    winOff: vec_t<u8, 2>
    interval: vec_t<u8, 2>
    latency: vec_t<u8, 2>
    timeout: vec_t<u8, 2>
    chMap: vec_t<u8, 5>
    hopSca: u8
}

export class ConnUpdData extends $struct {
    winSize: u8
    winOff: vec_t<u8, 2>
    interval: vec_t<u8, 2>
    latency: vec_t<u8, 2>
    timeout: vec_t<u8, 2>
    instant: vec_t<u8, 2>
}

export class LnkHdr extends $struct {
    lnkFlags: u8
    pduLen: u8
}
export interface LnkHdr {
    addPdu(this: LnkHdr, data: TL.BufFrame): void
    frame(this: LnkHdr): TL.BufFrame
    isCtrl(this: LnkHdr): bool_t
    init(this: LnkHdr, lnk_id: u8): void
    print(this: LnkHdr): void
    pduPtr(this: LnkHdr): TL.BufPtr
    setAck(this: LnkHdr, req_flags: u8): void
}

export class ScanRsp extends $struct {
    advType: u8
    pduLen: u8
    advA: TL.Addr
}
export interface ScanRsp {
    frame(this: ScanRsp): TL.BufFrame
    init(this: ScanRsp): void
}

export const LL_FEATURE_RSP_DATA = $table<u8>([
    LL_FEATURE_RSP, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // *no* length extension
])

export const LL_LENGTH_RSP_DATA = $table<u8>([
    LL_LENGTH_RSP, 0xFB, 0x00, 0x48, 0x08, 0xFB, 0x00, 0x48, 0x08 // not used now
])

export const LL_REJECT_DATA = $table<u8>([
    LL_REJECT_IND, 0x01  // unknown command
])

export const LL_VERSION_IND_DATA = $table<u8>([
    LL_VERSION_IND, 0x08, MAN_ID_LO, MAN_ID_HI, 0x00, 0x00    // 4.2
])

const ADV_LEG_INIT = $config<AdvHdr>()
const MY_ADDR = $config<TL.Addr>()

export namespace em$meta {
    export function em$construct() {
        ADV_LEG_INIT.$$val.pduLen = $sizeof<AdvHdr>() - 2
        ADV_LEG_INIT.$$val.flagsLen = 2
        ADV_LEG_INIT.$$val.flagsCode = 0x1
        ADV_LEG_INIT.$$val.flagsVal = 0x6 // BR_EDR_NOT_SUPPORTED | LE_GENERAL_DISC_MODE
        ADV_LEG_INIT.$$val.manLen = 3
        ADV_LEG_INIT.$$val.manCode = 0xff
        ADV_LEG_INIT.$$val.manIdLo = MAN_ID_LO
        ADV_LEG_INIT.$$val.manIdHi = MAN_ID_HI
        for (const i of $range(TL.ADDR_SIZE)) {
            ADV_LEG_INIT.$$val.advA[i] = MY_ADDR.$$val[i] = 0xaa
        }
        ADV_LEG_INIT.$$val.advA[5] = MY_ADDR.$$val[5] = 0xc0
    }
}

//>> ---- em$targ ---- <<//

const TYPE_MASK = 0x07

const LL_ID_MASK = 0x03
const LL_NESN_MASK = 0x04
const LL_SN_MASK = 0x08

export function dumpPkt(obuf: opaq_t) {
    const bp = <TL.BufPtr>obuf
    for (const i of $range(bp[1] + 2)) printf`%02x `(bp[i])
    printf`\n`()
}

AdvHdr.prototype.addData = function (this: AdvHdr, src: opaq_t, len: u16): void {
    const bp = $cast2<TL.BufPtr>($$(this))
    const off = this.pduLen + 2
    Mem.cpy($$(bp[off]), src, len)
    this.pduLen += len
    this.manLen += len
}

AdvHdr.prototype.addName = function (this: AdvHdr, name: text_t): void {
    const bp = $cast2<TL.BufPtr>($$(this))
    let off = this.pduLen + 2
    bp[off++] = name.$len + 1
    bp[off++] = 0x08 // short name
    Mem.cpy($$(bp[off]), name, name.$len)
    this.pduLen += name.$len + 2
}

AdvHdr.prototype.frame = function (this: AdvHdr): TL.BufFrame {
    const bp = $cast2<TL.BufPtr>($$(this))
    return bp.$frame(this.pduLen + 2)
}

AdvHdr.prototype.init = function (this: AdvHdr, adv_type: u8): void {
    Mem.cpy($$(this), $$(ADV_LEG_INIT), $sizeof<AdvHdr>())
    this.advType = adv_type
}

AdvHdr.prototype.print = function (this: AdvHdr): void {
    dumpPkt($cast2<opaq_t>($$(this)))
}

AdvReqHdr.prototype.isConn = function (this: AdvReqHdr): bool_t {
    return (this.advType & TYPE_MASK) == ADV_CONNECT_IND && this.isMine()
}

AdvReqHdr.prototype.isMine = function (this: AdvReqHdr): bool_t {
    return TL.equalAddr(MY_ADDR, this.advA)
}

AdvReqHdr.prototype.isScan = function (this: AdvReqHdr): bool_t {
    return (this.advType & TYPE_MASK) == ADV_SCAN_REQ && this.isMine()
}

LnkHdr.prototype.addPdu = function (this: LnkHdr, data: TL.BufFrame): void {
    Mem.cpy(this.pduPtr(), $$(data[0]), data.$len)
    this.pduLen += data.$len
}

LnkHdr.prototype.frame = function (this: LnkHdr): TL.BufFrame {
    const bp = $cast2<TL.BufPtr>($$(this))
    return bp.$frame(this.pduLen + 2)
}

LnkHdr.prototype.isCtrl = function (this: LnkHdr): bool_t {
    return (this.lnkFlags & LL_ID_MASK) == LL_CTRL
}

LnkHdr.prototype.init = function (this: LnkHdr, lnk_id: u8) {
    this.lnkFlags = lnk_id
    this.pduLen = 0
}

LnkHdr.prototype.pduPtr = function (this: LnkHdr): TL.BufPtr {
    const bp = $cast2<TL.BufPtr>($$(this))
    const pr = $$(bp[$sizeof<LnkHdr>()])
    return <TL.BufPtr>(pr)
}

LnkHdr.prototype.print = function (this: LnkHdr): void {
    dumpPkt($cast2<opaq_t>($$(this)))
}

LnkHdr.prototype.setAck = function (this: LnkHdr, req_flags: u8) {
    const nesn = (req_flags & LL_NESN_MASK) ^ LL_NESN_MASK
    const sn = req_flags & LL_SN_MASK
    this.lnkFlags |= (nesn | sn)
}

ScanRsp.prototype.frame = function (this: ScanRsp): TL.BufFrame {
    const bp = $cast2<TL.BufPtr>($$(this))
    return bp.$frame(TL.ADDR_SIZE + 2)
}

ScanRsp.prototype.init = function (this: ScanRsp): void {
    this.advType = ADV_SCAN_RSP | 0x40
    this.pduLen = TL.ADDR_SIZE
    Mem.cpy($$(this.advA), $$(MY_ADDR), TL.ADDR_SIZE)
}

