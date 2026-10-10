import '@$$emscript'
export const $U = $declare('MODULE')

import * as L2Cap from '@em.link.ble/L2Cap.em'
import * as LnkTx from '@em.link.ble/LnkTx.em'
import * as TB from '@em.link.ble/Types.em'

const PAIRING_REQ = 0x01
const PAIRING_RSP = 0x02
const PUBLIC_KEY = 0x0c

var pair_rsp_sent: bool_t
var pair_rsp_tx_seen: bool_t

export function accept(req: $$<TB.LnkHdr>): bool_t {
    const llid = req.$$.lnkFlags & 0x03
    if (L2Cap.active() && llid == TB.LL_CONT) {
        if (L2Cap.append(req)) dumpReassembled()
        return true
    }
    if (req.$$.isCtrl() || llid != TB.LL_START) return false
    const l2 = req.$$.l2capPkt()
    if (l2.$$.cid16() != TB.L2CAP_CID_SMP) return false
    const pdu = req.$$.pduPtr()
    if (pdu[4] == PAIRING_REQ) {
        sendPairRsp()
        return true
    }
    if (pdu[4] == PUBLIC_KEY && pair_rsp_tx_seen) {
        if (L2Cap.begin(req)) dumpReassembled()
        return true
    }
    unexpected(req)
    return true
}

export function reset() {
    pair_rsp_sent = false
    pair_rsp_tx_seen = false
    L2Cap.reset()
}

export function txChosen() {
    if (pair_rsp_sent && !pair_rsp_tx_seen) pair_rsp_tx_seen = true
}

export function unexpected(req: $$<TB.LnkHdr>) {
    const pdu = req.$$.pduPtr()
    printf`SMP opcode=%02x\n`(pdu[4])
    req.$$.print()
    fail()
}

function dumpReassembled() {
    const data = L2Cap.data()
    const len = L2Cap.len()
    printf`REASSEMBLED SMP len=%d\n`(len)
    for (const i of $range(len)) printf`%02x `(data[i])
    printf`\n`()
    fail()
}

function sendPairRsp() {
    const rsp = LnkTx.getAttPkt()
    if (rsp == $null) {
        printf`SMP Pairing Response: no TX buffer\n`()
        fail()
    }
    rsp.$$.init(TB.LL_START)
    const out = rsp.$$.pduPtr()
    out[0] = 0x07
    out[1] = 0x00
    out[2] = 0x06
    out[3] = 0x00
    out[4] = PAIRING_RSP
    out[5] = 0x03
    out[6] = 0x00
    out[7] = 0x08
    out[8] = 0x10
    out[9] = 0x00
    out[10] = 0x00
    rsp.$$.pduLen = 11
    LnkTx.setAttReady()
    pair_rsp_sent = true
}
