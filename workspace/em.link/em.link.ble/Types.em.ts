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

export const MAN_ID_LO = 0x4C
export const MAN_ID_HI = 0x0B

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

const ADV_LEG_INIT = $config<AdvHdr>()
const MY_ADDR = $config<TL.Addr>()
const TYPE_MASK = 0x07

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
            ADV_LEG_INIT.$$val.advA[i] = 0xaa
            MY_ADDR.$$val[i] = 0xaa
        }
    }
}

//>> ---- em$targ ---- <<//


AdvHdr.prototype.addData = function (this: AdvHdr, src: opaq_t, len: u16): void {
    const bp = $cast2<TL.BufPtr>($$(this))
    const off = this.pduLen + 2
    Mem.cpy($$(bp[off]), src, len)
    this.pduLen += len
    this.manLen += len
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
    for (const b of this.frame()) {
        printf`%02x `(b.$$)
    }
    printf`\n`()
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
