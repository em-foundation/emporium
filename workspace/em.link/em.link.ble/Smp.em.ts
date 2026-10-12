import '@$$emscript'
export const $U = $declare('MODULE')

import * as Crypto from '@em.crypto/Crypto.em'
import * as T from '@em.crypto.p256/Types.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as L2Cap from '@em.link.ble/L2Cap.em'
import * as LnkTx from '@em.link.ble/LnkTx.em'
import * as Mem from '@em.utils/Mem.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

const PAIRING_REQ = 0x01
const PAIRING_RSP = 0x02
const PUBLIC_KEY = 0x0c
const PUBLIC_KEY_LEN = 69

const LOCAL_SK = $config<T.U256>()
const work_f = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        work_f.$$val = FiberMgr.em$meta.create($cb(workFB))
        T.em$meta.initU256(LOCAL_SK.$$val, 'c88f01f5_10d9ac3f_70a292da_a2316de5_44e9aab8_afe84049_c62a9c57_862d1433')
    }
}

//>> ---- em$targ ---- <<//

var pair_rsp_sent: bool_t
var pair_rsp_tx_seen: bool_t
var peer_pk: T.PubKey
var local_pk: T.PubKey
var secret: T.U256

export function accept(req: $$<TB.LnkHdr>): bool_t {
    const llid = req.$$.lnkFlags & 0x03
    if (L2Cap.active() && llid == TB.LL_CONT) {
        if (L2Cap.append(req)) publicKeyReady()
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
        if (L2Cap.begin(req)) publicKeyReady()
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
    if (!LnkTx.takeAttAck()) return
    if (!L2Cap.txActive()) return
    if (L2Cap.txAcked()) halt()
    stageTx()
}

export function unexpected(req: $$<TB.LnkHdr>) {
    const pdu = req.$$.pduPtr()
    printf`SMP opcode=%02x\n`(pdu[4])
    req.$$.print()
    fail()
}

function loadLeU256(dst: T.U256_Ref, src: TL.BufPtr) {
    for (const i of $range(T.U256_LEN)) {
        const j = i << 2
        dst[i] = <u32>src[j] | (<u32>src[j + 1] << 8) | (<u32>src[j + 2] << 16) | (<u32>src[j + 3] << 24)
    }
}

function publicKeyReady() {
    const data = L2Cap.data()
    if (L2Cap.len() != PUBLIC_KEY_LEN || data[4] != PUBLIC_KEY) {
        printf`BAD SMP PUBLIC KEY len=%d op=%02x\n`(L2Cap.len(), data[4])
        fail()
    }
    loadLeU256(peer_pk.x.$ptr(), <TL.BufPtr>$$(data[5]))
    loadLeU256(peer_pk.y.$ptr(), <TL.BufPtr>$$(data[37]))
    work_f.$$.post()
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

function stageTx() {
    const pkt = LnkTx.getAttPkt()
    if (pkt == $null) return
    if (L2Cap.stageTx(pkt)) LnkTx.setAttReady()
}

function storeLeU256(dst: TL.BufPtr, src: T.U256_Ref) {
    for (const i of $range(T.U256_LEN)) {
        const j = i << 2
        const w = src[i]
        dst[j] = w
        dst[j + 1] = w >> 8
        dst[j + 2] = w >> 16
        dst[j + 3] = w >> 24
    }
}

function workFB(_: arg_t) {
    let sk = T.U256.$make()
    Mem.cpy(sk.$ptr(), LOCAL_SK.$ptr(), $sizeof<T.U256>())
    Crypto.P256.makePublicKey(sk, $$(local_pk))
    Crypto.P256.ecdh(sk, $$(peer_pk), secret.$ptr())
    // stage local public key
    const out = L2Cap.beginTx(PUBLIC_KEY_LEN)
    out[0] = 0x41
    out[1] = 0x00
    out[2] = 0x06
    out[3] = 0x00
    out[4] = PUBLIC_KEY
    storeLeU256(<TL.BufPtr>$$(out[5]), local_pk.x.$ptr())
    storeLeU256(<TL.BufPtr>$$(out[37]), local_pk.y.$ptr())
    stageTx()
}
