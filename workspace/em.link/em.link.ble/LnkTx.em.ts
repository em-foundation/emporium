import '@$$emscript'
export const $U = $declare('MODULE')

import * as Heap from '@em.utils/Heap.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

class CtrlRsp extends $struct {
    hdr: TB.LnkHdr
    pdu: vec_t<u8, 16>
}

const att_adr = $config<Heap.Adr>()

export namespace em$meta {
    export function bindAttBuf(adr: Heap.Adr) {
        att_adr.$$val = adr
    }
}

//>> ---- em$targ ---- <<//

enum TxKind {
    NONE,
    EMPTY,
    CTRL,
    ATT,
}

const att_rsp = <$$<TB.LnkHdr>>Heap.opaq(att_adr)

var ctrl_rsp: CtrlRsp
var empty_rsp: TB.LnkHdr

var att_flag: bool_t
var ctrl_flag: bool_t
var tx_kind: TxKind = TxKind.NONE
var tx_sn: u8

export function ack(req: $$<TB.LnkHdr>) {
    if (tx_kind != TxKind.NONE && req.$$.updateTxAck($$(tx_sn))) {
        tx_kind = TxKind.NONE
    }
}

export function choose(req: $$<TB.LnkHdr>): TL.BufFrame {
    if (tx_kind == TxKind.NONE) {
        if (ctrl_flag) {
            ctrl_flag = false
            tx_kind = TxKind.CTRL
        } else if (att_flag) {
            att_flag = false
            tx_kind = TxKind.ATT
        } else {
            empty_rsp.init(TB.LL_CONT)
            tx_kind = TxKind.EMPTY
        }
    }
    const pkt = getTxPkt()
    pkt.$$.setSeq(req.$$.lnkFlags, tx_sn)
    return pkt.$$.frame()
}

export function getAttPkt(): $$<TB.LnkHdr> {
    return isAttFree() ? att_rsp : $null
}

export function getCtrlPkt(): $$<TB.LnkHdr> {
    return isCtrlFree() ? $$(ctrl_rsp.hdr) : $null
}

export function reset() {
    tx_kind = TxKind.NONE
    ctrl_flag = false
    att_flag = false
    tx_sn = 0
    empty_rsp.init(TB.LL_CONT)
}

export function setAttReady() {
    att_flag = true
}

export function setCtrlReady() {
    ctrl_flag = true
}

function getTxPkt(): $$<TB.LnkHdr> {
    switch (tx_kind) {
        case TxKind.EMPTY: return $$(empty_rsp)
        case TxKind.CTRL: return $$(ctrl_rsp.hdr)
        case TxKind.ATT: return att_rsp
        default: return $null
    }
}

function isAttFree(): bool_t {
    return !att_flag && tx_kind != TxKind.ATT
}

function isCtrlFree(): bool_t {
    return !ctrl_flag && tx_kind != TxKind.CTRL
}
