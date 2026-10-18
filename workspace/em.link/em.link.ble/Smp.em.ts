import '@$$emscript'
export const $U = $declare('MODULE')

import * as Aes128I from '@em.hal/Aes128I.em'
import * as CmacProviderI from '@em.crypto.cmac/CmacProviderI.em'
import * as Common from '@em.mcu/Common.em'
import * as Crypto from '@em.crypto/Crypto.em'
import * as T from '@em.crypto.p256/Types.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as L2Cap from '@em.link.ble/L2Cap.em'
import * as LnkTx from '@em.link.ble/LnkTx.em'
import * as Mem from '@em.utils/Mem.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

const DHKEY_CHECK = 0x0d
const F4_MSG_LEN = 65
const F5_MSG_LEN = 53
const F6_MSG_LEN = 65
const ADDR_LEN = 7
const NONCE_LEN = 16
const PAIRING_CONFIRM = 0x03
const PAIRING_CONFIRM_LEN = 21
const PAIRING_RANDOM = 0x04
const PAIRING_REQ = 0x01
const PAIRING_RSP = 0x02
const PUBLIC_KEY = 0x0c
const PUBLIC_KEY_LEN = 69

class F4Msg extends $vector<u8> { $len = F4_MSG_LEN }
class F5Msg extends $vector<u8> { $len = F5_MSG_LEN }
class DhkeyBytes extends $vector<u8> { $len = 32 }
class F6Msg extends $vector<u8> { $len = F6_MSG_LEN }
class Addr extends $vector<u8> { $len = ADDR_LEN }
class Nonce extends $vector<u8> { $len = NONCE_LEN }

const F5_SALT = $config<Nonce>()
const LOCAL_NB = $config<Nonce>()
const LOCAL_SK = $config<T.U256>()
const work_f = $config<FiberMgr.Obj>()
const verify_f = $config<FiberMgr.Obj>()
const ack_f = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        work_f.$$val = FiberMgr.em$meta.create($cb(workFB))
        verify_f.$$val = FiberMgr.em$meta.create($cb(verifyFB))
        ack_f.$$val = FiberMgr.em$meta.create($cb(ackFB))
        const salt = [0x6c, 0x88, 0x83, 0x91, 0xaa, 0xf5, 0xa5, 0x38, 0x60, 0x37, 0x0b, 0xdb, 0x5a, 0x60, 0x83, 0xbe]
        for (const i of $range(NONCE_LEN)) F5_SALT.$$val[i] = salt[i]
        for (const i of $range(NONCE_LEN)) LOCAL_NB.$$val[i] = i
        T.em$meta.initU256(LOCAL_SK.$$val, 'c88f01f5_10d9ac3f_70a292da_a2316de5_44e9aab8_afe84049_c62a9c57_862d1433')
    }
}

//>> ---- em$targ ---- <<//

var local_pk_tx_done: bool_t
var pair_confirm_sent: bool_t
var pair_random_sent: bool_t
var pair_rsp_sent: bool_t
var pair_rsp_tx_seen: bool_t
var peer_pk: T.PubKey
var local_pk: T.PubKey
var confirm_b: CmacProviderI.Mac
var peer_na: Nonce
var secret: T.U256
var central_addr: Addr
var peripheral_addr: Addr
var central_io: Addr
var peer_check: Nonce
var mac_key: CmacProviderI.Mac
var ltk: CmacProviderI.Mac
var session_key: Aes128I.Block
var addresses_ready: bool_t
var responder_check_sent: bool_t
var responder_check_acked: bool_t
var peer_check_seen: bool_t
var secret_ready: bool_t

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
    if (pair_confirm_sent && !pair_random_sent && pdu[4] == PAIRING_RANDOM) {
        loadLe128(peer_na.$ptr(), <TL.BufPtr>$$(pdu[5]))
        sendPairRandom()
        return true
    }
    if (pair_random_sent && pdu[4] == DHKEY_CHECK) {
        if (peer_check_seen) return true
        if (pdu[0] != 0x11 || pdu[1] != 0x00) {
            printf`BAD SMP DHKey Check length\n`()
            fail()
        }
        peer_check_seen = true
        loadLe128(peer_check.$ptr(), <TL.BufPtr>$$(pdu[5]))
        if (secret_ready) verify_f.$$.post()
        return true
    }
    if (pdu[4] == PAIRING_REQ) {
        if (pair_rsp_sent) return true
        central_io[0] = pdu[7] // AuthReq
        central_io[1] = pdu[6] // OOB
        central_io[2] = pdu[5] // IOcap
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

// Supply connection-setup addresses in f5/f6 order: type (0 public, 1 random),
// then six address bytes most significant first. Call after reset, before DHKey Check.
export function setAddresses(central: ptr_t<u8>, peripheral: ptr_t<u8>) {
    for (const i of $range(ADDR_LEN)) {
        central_addr[i] = central[i]
        peripheral_addr[i] = peripheral[i]
    }
    addresses_ready = true
}

// Input is SKDm || SKDs in Link Layer wire byte order.
// AES-128 provider consumes cryptographic byte order.
export function deriveSessionKey(skd: ptr_t<u8>): ptr_t<u8> {
    let block = Aes128I.Block.$make()
    for (const i of $range(Aes128I.BLOCK_LEN)) block[i] = skd[Aes128I.BLOCK_LEN - 1 - i]
    Common.Aes128.encrypt(ltk.$ptr(), block.$ptr(), session_key.$ptr())
    return session_key.$ptr()
}

export function em$startup() {
    let sk = T.U256.$make()
    Mem.cpy(sk.$ptr(), LOCAL_SK.$ptr(), $sizeof<T.U256>())
    Crypto.P256.makePublicKey(sk, $$(local_pk))
}

export function publicKeyTxActive(): bool_t {
    return !local_pk_tx_done && L2Cap.txActive()
}

export function reset() {
    addresses_ready = false
    local_pk_tx_done = false
    pair_confirm_sent = false
    pair_random_sent = false
    pair_rsp_sent = false
    pair_rsp_tx_seen = false
    responder_check_sent = false
    responder_check_acked = false
    peer_check_seen = false
    secret_ready = false
    L2Cap.reset()
}

export function txAcked() {
    if (!LnkTx.takeAttAck()) return
    if (!L2Cap.txActive()) return
    if (L2Cap.txAcked()) {
        if (responder_check_sent && !responder_check_acked) {
            responder_check_acked = true
            ack_f.$$.post()
        }
        if (!local_pk_tx_done) {
            local_pk_tx_done = true
            sendPairConfirm()
        }
        return
    }
    stageTx()
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

function f4(u: T.U256_Ref, v: T.U256_Ref, x: ptr_t<u8>, out: ptr_t<u8>) {
    let msg = F4Msg.$make()
    storeBeU256(msg.$ptr(), u)
    storeBeU256(<TL.BufPtr>$$(msg[32]), v)
    msg[64] = 0
    Crypto.Cmac.compute(x, msg.$frame(), out)
}

function f5() {
    let key = DhkeyBytes.$make()
    let t = Nonce.$make()
    let msg = F5Msg.$make()
    storeBeU256(key.$ptr(), secret.$ptr())
    Crypto.Cmac.compute(F5_SALT.$ptr(), key.$frame(0, 32), t.$ptr())
    msg[1] = 0x62 // "btle"
    msg[2] = 0x74
    msg[3] = 0x6c
    msg[4] = 0x65
    for (const i of $range(NONCE_LEN)) {
        msg[5 + i] = peer_na[i]
        msg[21 + i] = LOCAL_NB.$ptr()[i]
    }
    for (const i of $range(ADDR_LEN)) {
        msg[37 + i] = central_addr[i]
        msg[44 + i] = peripheral_addr[i]
    }
    msg[51] = 0x01 // length = 256 bits, big-endian
    msg[52] = 0x00
    msg[0] = 0
    Crypto.Cmac.compute(t.$ptr(), msg.$frame(), mac_key.$ptr())
    msg[0] = 1
    Crypto.Cmac.compute(t.$ptr(), msg.$frame(), ltk.$ptr())
}

function f6(out: ptr_t<u8>, responder: bool_t) {
    let msg = F6Msg.$make()
    for (const i of $range(NONCE_LEN)) {
        msg[i] = responder ? LOCAL_NB.$ptr()[i] : peer_na[i]
        msg[16 + i] = responder ? peer_na[i] : LOCAL_NB.$ptr()[i]
        msg[32 + i] = 0 // Just Works R
    }
    for (const i of $range(3)) msg[48 + i] = responder ? (i == 0 ? 0x08 : (i == 2 ? 0x03 : 0)) : central_io[i]
    for (const i of $range(ADDR_LEN)) {
        msg[51 + i] = responder ? peripheral_addr[i] : central_addr[i]
        msg[58 + i] = responder ? central_addr[i] : peripheral_addr[i]
    }
    Crypto.Cmac.compute(mac_key.$ptr(), msg.$frame(), out)
}

function loadLe128(dst: ptr_t<u8>, src: TL.BufPtr) {
    for (const i of $range(NONCE_LEN)) dst[i] = src[NONCE_LEN - 1 - i]
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

function sendPairConfirm() {
    const out = L2Cap.beginTx(PAIRING_CONFIRM_LEN)
    out[0] = 0x11
    out[1] = 0x00
    out[2] = 0x06
    out[3] = 0x00
    out[4] = PAIRING_CONFIRM
    storeLe128(<TL.BufPtr>$$(out[5]), confirm_b.$ptr())
    stageTx()
    pair_confirm_sent = true
}

function sendPairRandom() {
    const out = L2Cap.beginTx(PAIRING_CONFIRM_LEN)
    out[0] = 0x11
    out[1] = 0x00
    out[2] = 0x06
    out[3] = 0x00
    out[4] = PAIRING_RANDOM
    storeLe128(<TL.BufPtr>$$(out[5]), LOCAL_NB.$ptr())
    stageTx()
    pair_random_sent = true
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

function storeBeU256(dst: ptr_t<u8>, src: T.U256_Ref) {
    for (const i of $range(T.U256_LEN)) {
        const w = src[T.U256_LEN - 1 - i]
        const j = i << 2
        dst[j] = w >> 24
        dst[j + 1] = w >> 16
        dst[j + 2] = w >> 8
        dst[j + 3] = w
    }
}

function storeLe128(dst: TL.BufPtr, src: ptr_t<u8>) {
    for (const i of $range(NONCE_LEN)) dst[i] = src[NONCE_LEN - 1 - i]
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
    // fixed nonce for bring-up; replace with fresh random Nb
    f4(local_pk.x.$ptr(), peer_pk.x.$ptr(), LOCAL_NB.$ptr(), confirm_b.$ptr())
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
    Crypto.P256.ecdh(sk, $$(peer_pk), secret.$ptr())
    const key = Common.GlobalInterrupts.disable()
    secret_ready = true
    if (peer_check_seen) verify_f.$$.post()
    Common.GlobalInterrupts.restore(key)
}

function ackFB(_: arg_t) {
}

function verifyFB(_: arg_t) {
    if (!addresses_ready) {
        printf`SMP missing connection addresses: call setAddresses()\n`()
        fail()
    }
    f5()
    let expected = Nonce.$make()
    f6(expected.$ptr(), false)
    for (const i of $range(NONCE_LEN)) {
        if (expected[i] != peer_check[i]) {
            printf`SMP DHKey Check FAIL byte=%d expected=%02x got=%02x\n`(i, expected[i], peer_check[i])
            fail()
        }
    }
    let responder_check = Nonce.$make()
    f6(responder_check.$ptr(), true)
    const out = L2Cap.beginTx(PAIRING_CONFIRM_LEN)
    out[0] = 0x11
    out[1] = 0x00
    out[2] = 0x06
    out[3] = 0x00
    out[4] = DHKEY_CHECK
    storeLe128(<TL.BufPtr>$$(out[5]), responder_check.$ptr())
    stageTx()
    responder_check_sent = true
}
