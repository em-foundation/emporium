import '@$$emscript'
export const $U = $declare('MODULE')

import * as Binder from '@em.link.ble/Binder.em'
import * as Connection from '@em.link.ble/Connection.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Heap from '@em.utils/Heap.em'
import * as L2Cap from '@em.link.ble/L2Cap.em'
import * as LedI from '@em.hal/LedI.em'
import * as LnkTx from '@em.link.ble/LnkTx.em'
import * as Link from '@em.link/Link.em'
import * as Registry from '@em.link/Registry.em'
import * as Smp from '@em.link.ble/Smp.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

export const Led = $proxy<LedI.$I>()

const rx_adr = $config<Heap.Adr>()
const tx_adr = $config<Heap.Adr>()
const reqF = $config<FiberMgr.Obj>()
const statusF = $config<FiberMgr.Obj>()
const encAckF = $config<FiberMgr.Obj>()
const status_cb = $config<TL.RecvDoneFxn>()

export namespace em$meta {
    export function bindStatusHandler(h: TL.RecvDoneFxn) {
        status_cb.$$val = h
    }
    export function em$construct() {
        reqF.$$val = FiberMgr.em$meta.create($cb(reqFB))
        statusF.$$val = FiberMgr.em$meta.create($cb(statusFB))
        encAckF.$$val = FiberMgr.em$meta.create($cb(encAckFB))
        Link.RadioDriver.em$meta.bindHandler($cb(radioHandler))
        rx_adr.$$val = Heap.em$meta.alloc(40)
        tx_adr.$$val = Heap.em$meta.alloc(40)
        L2Cap.em$meta.allocRx(Binder.em$meta.getRxBufSize())
        LnkTx.em$meta.bindAttBuf(tx_adr.$$val)
    }
}

//>> ---- em$targ ---- <<//

const ALL_ADV_CHANS = 0x7
const LL_ENC_REQ = 0x03
const LL_ENC_REQ_LEN = 23
const LL_ENC_RSP = 0x04
const LL_START_ENC_REQ = 0x05
const LL_START_ENC_RSP = 0x06
const SMP_ADDR_LEN = 7
const NULL_PKT_LIMIT = 6
const NUM_ADV_CHANS = 3

const adv_hdr = <$$<TB.AdvHdr>>Heap.opaq(tx_adr)
const adv_req = <$$<TB.AdvReqHdr>>Heap.opaq(rx_adr)
const conn_pkt = <$$<TB.ConnPkt>>Heap.opaq(rx_adr)
const lnk_req = <$$<TB.LnkHdr>>Heap.opaq(rx_adr)
const rx_buf = <TL.BufPtr>Heap.opaq(rx_adr)
const scan_rsp = <$$<TB.AdvHdr>>Heap.opaq(tx_adr)

enum State {
    ADV_PAUSE,
    ADV_SCAN,
    CONN,
    CONN_PAUSE,
    EXCH,
    CLOSING,
    IDLE,
}

class Iv extends $vector<u8> { $len = 8 }
class Skd extends $vector<u8> { $len = 16 }
class SmpAddr extends $vector<u8> { $len = SMP_ADDR_LEN }

class Anchor extends $struct {
    usecs: u32
}
interface Anchor {
    nextPause(this: Anchor, air_us: u32): u32
    reset(this: Anchor): void
}

var anchor: Anchor

var adv_con_flag: bool_t
var adv_count: u16
var adv_inter: u16
var adv_mask: u8
var adv_power: i8
var cur_adv_mask: u8
var cur_state: State = State.IDLE
var null_pkt_cnt: u8
var pending_status: TL.ConnectionStatus
var upd_flag: bool_t
var enc_rsp_pending: bool_t
var enc_rsp_acked: bool_t
var enc_rx_enabled: bool_t
var enc_start_pending: bool_t
var enc_tx_enabled: bool_t
var enc_tx_pending: bool_t
var enc_tx_sn: u8
var rx_ctr_hi: u8
var rx_ctr_lo: u32
var rx_next_sn: u8
var session_iv: Iv
var session_skd: Skd
var tx_ctr_hi: u8
var tx_ctr_lo: u32

export function start() {
    if (cur_state != State.IDLE) {
        return
    }
    const params = Registry.getParams()
    adv_con_flag = params.$$.ble_connectible
    adv_count = params.$$.send_count
    adv_mask = params.$$.ble_adv_chan_mask ? params.$$.ble_adv_chan_mask : ALL_ADV_CHANS
    adv_inter = params.$$.send_interval_ms
    adv_power = params.$$.radio_power
    cur_adv_mask = 0
    null_pkt_cnt = 0
    Smp.reset()
    enc_rsp_pending = false
    enc_rsp_acked = false
    enc_rx_enabled = false
    enc_start_pending = false
    enc_tx_enabled = false
    enc_tx_pending = false
    rx_ctr_hi = 0
    rx_ctr_lo = 0
    rx_next_sn = 0
    tx_ctr_hi = 0
    tx_ctr_lo = 0
    setState(State.ADV_PAUSE)
    controller()
}

export function stop() {
    radioOff()
    setState(State.IDLE)
}

function chooseEncryptedTx(): TL.BufFrame {
    let tx = LnkTx.choose(lnk_req)
    tx[0] = (tx[0] & ~0x04) | (rx_next_sn >> 1)
    const params = Registry.getParams()
    params.$$.ble_tx_ctr_hi = tx_ctr_hi
    params.$$.ble_tx_ctr_lo = tx_ctr_lo
    params.$$.ble_tx_encrypted = true
    if (tx[1] != 0) {
        enc_tx_pending = true
        enc_tx_sn = tx[0] & 0x08
    }
    Smp.txChosen()
    return tx
}

function controller() {
    while (true) {
        switch (cur_state) {
            case State.ADV_PAUSE: {
                radioOff()
                if (adv_count-- == 0) {
                    setState(State.IDLE)
                    notifyStatus(TL.ConnectionStatus.TIMEOUT)
                    return
                }
                setTimeout(adv_inter * 1000)
                setState(State.ADV_SCAN)
                return
            }
            case State.ADV_SCAN: {
                if (cur_adv_mask == NUM_ADV_CHANS) {
                    cur_adv_mask = 0
                    setState(State.ADV_PAUSE)
                    continue
                }
                const idx = cur_adv_mask++
                if (!(adv_mask & (1 << idx))) {
                    continue
                }
                doAdvScan(TB.ADV_CHAN + idx)
                return
            }
            case State.CONN: {
                Connection.open(conn_pkt)
                enc_rsp_pending = false
                enc_rsp_acked = false
                setSmpAddresses()
                notifyStatus(TL.ConnectionStatus.OPENING)
                anchor.reset()
                LnkTx.reset()
                doExch(1000)
                setState(State.CONN_PAUSE)
                return
            }
            case State.CONN_PAUSE: {
                radioOff()
                const air_us = (Link.RadioDriver.getRxBuf() != $null) ? rxAirtimeUs(lnk_req) : 0
                if (air_us == 0) {
                    if (++null_pkt_cnt >= NULL_PKT_LIMIT) {
                        notifyStatus(TL.ConnectionStatus.HANGUP)
                        return
                    }
                } else {
                    null_pkt_cnt = 0
                }
                setTimeout(anchor.nextPause(air_us))
                setState(State.EXCH)
                return
            }
            case State.EXCH: {
                upd_flag = Connection.next()
                doExch(upd_flag ? 1000 : TB.INTERVAL_FUDGE * 3)
                setState(State.CONN_PAUSE)
                return
            }
            case State.CLOSING: {
                radioOff()
                setState(State.IDLE)
                notifyStatus(TL.ConnectionStatus.CLOSED)
                return
            }
            case State.IDLE: {
                return
            }
        }
    }
}

function setSmpAddresses() {
    let central = SmpAddr.$make()
    let peripheral = SmpAddr.$make()
    central[0] = (conn_pkt.$$.advType & 0x40) ? 1 : 0
    peripheral[0] = (conn_pkt.$$.advType & 0x80) ? 1 : 0
    for (const i of $range(TL.ADDR_SIZE)) {
        central[i + 1] = conn_pkt.$$.initA[TL.ADDR_SIZE - 1 - i]
        peripheral[i + 1] = conn_pkt.$$.advA[TL.ADDR_SIZE - 1 - i]
    }
    Smp.setAddresses(central.$ptr(), peripheral.$ptr())
}

function doAdvScan(chan: u8) {
    Binder.initAdvPkt(adv_hdr)
    Registry.setupParams($cb(scanProf))
    radioOn()
    Link.RadioDriver.startTx(adv_hdr.$$.frame(), chan)
}

function doExch(end_ms: u16) {
    Registry.setupParams($cb(exchProf))
    radioOn()
    const deadline = anchor.usecs + Connection.params().$$.interval_us - HFCLK_GUARD_US
    const remaining = <i32>(deadline - Link.RadioDriver.nowTimeUs())
    const limit_ms: u16 = remaining >= 1000 ? <u16>(remaining / 1000) : 1
    if (end_ms > limit_ms) end_ms = limit_ms
    Link.RadioDriver.startRx(rx_buf, Connection.channel(), end_ms)
}

function exchChain(in_buf: TL.BufPtr): TL.BufFrame {
    const fresh = (lnk_req.$$.lnkFlags & 0x08) == rx_next_sn
    if (enc_tx_pending && (lnk_req.$$.lnkFlags & 0x04) != (enc_tx_sn >> 1)) {
        tx_ctr_lo += 1
        if (tx_ctr_lo == 0) tx_ctr_hi += 1
        if (tx_ctr_hi > 0x7f) fail()
        enc_tx_pending = false
    }
    LnkTx.ack(lnk_req)
    if (enc_rx_enabled && !enc_tx_enabled && lnk_req.$$.pduLen > 0) {
        if (!lnk_req.$$.isCtrl() || lnk_req.$$.pduLen != 1 || lnk_req.$$.pduPtr()[0] != LL_START_ENC_RSP) {
            printf`SMP expected encrypted LL_START_ENC_RSP FAIL\n`()
            fail()
            return $null
        }
        const rsp = LnkTx.getCtrlPkt()
        if (rsp == $null) {
            printf`SMP START_ENC_RSP buffer unavailable FAIL\n`()
            fail()
            return $null
        }
        rsp.$$.init(TB.LL_CTRL)
        rsp.$$.pduPtr()[0] = LL_START_ENC_RSP
        rsp.$$.pduLen = 1
        LnkTx.setCtrlReady()
        rx_ctr_lo = 1
        rx_next_sn = (lnk_req.$$.lnkFlags & 0x08) ^ 0x08
        enc_tx_enabled = true
        return chooseEncryptedTx()
    }
    if (fresh) {
        rx_next_sn ^= 0x08
        if (enc_rx_enabled && lnk_req.$$.pduLen > 0) {
            rx_ctr_lo += 1
            if (rx_ctr_lo == 0) rx_ctr_hi += 1
            if (rx_ctr_hi > 0x7f) fail()
        }
    }
    if (LnkTx.takeCtrlAck() && enc_rsp_pending && !enc_rsp_acked) {
        enc_rsp_pending = false
        enc_rsp_acked = true
        encAckF.$$.post()
    }
    if (fresh && lnk_req.$$.pduLen > 0 && !Smp.accept(lnk_req)) {
        reqF.$$.post()
    }
    if (enc_tx_enabled) return chooseEncryptedTx()
    const tx = LnkTx.choose(lnk_req)
    if (enc_start_pending && tx[1] == 1 && (tx[0] & 0x03) == TB.LL_CTRL && tx[3] == LL_START_ENC_REQ) {
        enc_rx_enabled = true
        enc_start_pending = false
    }
    Smp.txChosen()
    return tx
}

function exchProf(params: $$<TL.Params>) {
    params.$$.ble_enable = true
    params.$$.radio_phy = TL.Phy.BLE_1M
    params.$$.radio_power = adv_power
    params.$$.ble_acc_adr = Connection.params().$$.accAdr
    params.$$.ble_crc_init = Connection.params().$$.crcInit
    params.$$.ble_exch_buf = $null
    params.$$.ble_chain = $cb(exchChain)
    params.$$.ble_rx_ctr_hi = rx_ctr_hi
    params.$$.ble_rx_ctr_lo = rx_ctr_lo
    params.$$.ble_rx_encrypted = enc_rx_enabled
    params.$$.ble_rx_next_sn = rx_next_sn
    params.$$.ble_tx_ctr_hi = tx_ctr_hi
    params.$$.ble_tx_ctr_lo = tx_ctr_lo
    params.$$.ble_tx_encrypted = enc_tx_enabled
}

function radioHandler() {
    controller()
}


function notifyStatus(status: TL.ConnectionStatus) {
    pending_status = status
    statusF.$$.post()
}

function statusFB(_: arg_t) {
    if (pending_status == TL.ConnectionStatus.OPENING) printf`BLE CONNECTION OPEN\n`()
    if (pending_status == TL.ConnectionStatus.HANGUP) printf`BLE CONNECTION HANGUP (RX timeout)\n`()
    if (pending_status == TL.ConnectionStatus.CLOSED) printf`BLE CONNECTION CLOSED\n`()
    status_cb(pending_status)
}

function encAckFB(_: arg_t) {
    printf`BLE LL_ENC_RSP ACK\n`()
    const key = Smp.deriveSessionKey(session_skd.$ptr())
    Link.PacketCrypto.configure(key, session_iv.$ptr(), 0)
    const rsp = LnkTx.getCtrlPkt()
    if (rsp == $null) {
        printf`SMP START_ENC_REQ buffer unavailable FAIL\n`()
        fail()
        return
    }
    rsp.$$.init(TB.LL_CTRL)
    rsp.$$.pduPtr()[0] = LL_START_ENC_REQ
    rsp.$$.pduLen = 1
    enc_start_pending = true
    LnkTx.setCtrlReady()
    printf`SMP session key configured; LL_START_ENC_REQ queued\n`()
}

function radioOff() {
    Link.RadioDriver.disable()
}

function radioOn() {
    if (cur_state == State.ADV_SCAN) {
        Led.wink(1)
    }
    Link.RadioDriver.enable()
}

function reqCtrl(rsp_pkt: $$<TB.LnkHdr>): bool_t {
    const req_pdu = lnk_req.$$.pduPtr()
    let rsp_data = TB.LL_REJECT_DATA.$frame(0)
    let unk_flag = false
    const opcode = req_pdu[0]
    printf`BLE LL_CTRL opcode=%02x len=%d\n`(opcode, lnk_req.$$.pduLen)
    switch (opcode) {
        case TB.LL_CONN_UPDATE_IND: {
            const upd = $cast2<$$<TB.ConnUpdData>>($$(req_pdu[1]))
            Connection.update(upd)
            return false
        }
        case LL_ENC_REQ: {
            if (lnk_req.$$.pduLen != LL_ENC_REQ_LEN) {
                printf`SMP bad LL_ENC_REQ len=%d\n`(lnk_req.$$.pduLen)
                fail()
            }
            for (const i of $range(8)) session_skd[i] = req_pdu[11 + i]
            for (const i of $range(4)) session_iv[i] = req_pdu[19 + i]
            // Fixed SKDs/IVs for packet-at-a-time bring-up only.
            rsp_pkt.$$.init(TB.LL_CTRL)
            const out = rsp_pkt.$$.pduPtr()
            out[0] = LL_ENC_RSP
            for (const i of $range(8)) {
                out[1 + i] = i
                session_skd[8 + i] = i
            }
            for (const i of $range(4)) {
                out[9 + i] = 8 + i
                session_iv[4 + i] = 8 + i
            }
            rsp_pkt.$$.pduLen = 13
            enc_rsp_pending = true
            return true
        }
        case LL_START_ENC_REQ: {
            if (lnk_req.$$.pduLen != 1) {
                printf`SMP bad LL_START_ENC_REQ len=%d\n`(lnk_req.$$.pduLen)
                fail()
            }
            printf`SMP LL_START_ENC_REQ\n`()
            lnk_req.$$.print()
            halt()
            return false
        }
        case TB.LL_FEATURE_REQ: {
            rsp_data = TB.LL_FEATURE_RSP_DATA.$frame(0)
            break
        }
        case TB.LL_LENGTH_REQ: {
            rsp_data = TB.LL_LENGTH_RSP_DATA.$frame(0)
            break
        }
        case TB.LL_VERSION_IND: {
            rsp_data = TB.LL_VERSION_IND_DATA.$frame(0)
            break
        }
        case TB.LL_TERMINATE_IND: {
            if (lnk_req.$$.pduLen >= 2) printf`BLE LL_TERMINATE reason=%02x\n`(req_pdu[1])
            setState(State.CLOSING)
            return false
        }
        case TB.LL_UNKNOWN_RSP: {
            return false
        }
        default: {
            unk_flag = true
        }
    }
    rsp_pkt.$$.init(TB.LL_CTRL)
    if (unk_flag) {
        rsp_pkt.$$.addUnkRsp(opcode)
    } else {
        rsp_pkt.$$.addPdu(rsp_data)
    }
    return true
}

function reqFB(_: arg_t) {
    if (lnk_req.$$.isCtrl()) {
        const rsp = LnkTx.getCtrlPkt()
        if (rsp == $null) return
        if (reqCtrl(rsp)) {
            LnkTx.setCtrlReady()
        }
    } else {
        const l2 = lnk_req.$$.l2capPkt()
        switch (l2.$$.cid16()) {
            case TB.L2CAP_CID_ATT: {
                const rsp = LnkTx.getAttPkt()
                if (rsp == $null) return
                if (Binder.reqGatt(lnk_req.$$.attPkt(), rsp)) {
                    LnkTx.setAttReady()
                }
                break
            }
            case TB.L2CAP_CID_LE_SIG: {
                const rsp = LnkTx.getAttPkt()
                if (rsp == $null) return
                rsp.$$.init(TB.LL_START)
                switch (l2.$$.code) {
                    case TB.L2CAP_LE_CREDIT_BASED_CONNECTION_REQ: {
                        const data = l2.$$.cmdDataPtr()
                        const scid = (data[3] << 8) | data[2]
                        if (scid >= 0x0040) {
                            rsp.$$.addL2capLeCreditConnRsp(
                                l2.$$.ident,
                                TB.L2CAP_LE_CB_RESULT_NO_RESOURCES
                            )
                        } else {
                            rsp.$$.addL2capCmdReject(
                                l2.$$.ident,
                                TB.L2CAP_REJ_CMD_NOT_UNDERSTOOD
                            )
                        }
                        break
                    }
                    default: {
                        rsp.$$.addL2capCmdReject(
                            l2.$$.ident,
                            TB.L2CAP_REJ_CMD_NOT_UNDERSTOOD
                        )
                        break
                    }
                }
                LnkTx.setAttReady()
                break
            }
            case TB.L2CAP_CID_SMP: {
                Smp.unexpected(lnk_req)
                break
            }
            default: {
                // Unsupported fixed/dynamic CID: ignore.
                break
            }
        }
    }
}

function rxAirtimeUs(pkt: $$<TB.LnkHdr>): u32 {
    const mic_len = enc_rx_enabled && pkt.$$.pduLen > 0 ? 4 : 0
    return (10 + pkt.$$.pduLen + mic_len) * 8
}

var cnt = 0

function scanChain(in_buf: TL.BufPtr): TL.BufFrame {
    if (adv_req.$$.isScan()) {
        Binder.initScanRspPkt(scan_rsp)
        return scan_rsp.$$.frame()
    }
    if (adv_req.$$.isConn()) {
        setState(State.CONN)
    }
    return $null
}

function scanProf(params: $$<TL.Params>) {
    params.$$.ble_enable = true
    params.$$.radio_phy = TL.Phy.BLE_1M
    params.$$.radio_power = adv_power
    if (!adv_con_flag) {
        return
    }
    params.$$.ble_chain = $cb(scanChain)
    params.$$.ble_exch_buf = rx_buf
    params.$$.ble_exch_end_ms = 1
}

function setState(s: State) {
    cur_state = s
}

function setTimeout(usecs: u32) {
    Link.RadioDriver.pause(usecs, $cb(timerHandler))
}

function timerHandler() {
    controller()
}

const HFCLK_GUARD_US = 650
const RX_GUARD_US = 0

Anchor.prototype.nextPause = function (this: Anchor, air_us: u32): u32 {
    const interval_us = Connection.params().$$.interval_us
    if (air_us != 0) {
        const rx_end_us = Link.RadioDriver.getRxEndTimeUs()
        this.usecs = rx_end_us - air_us
    }
    this.usecs += interval_us
    const wake_us = this.usecs - HFCLK_GUARD_US - RX_GUARD_US
    const now_us = Link.RadioDriver.nowTimeUs()
    const remaining = <i32>(wake_us - now_us)
    return remaining > 0 ? <u32>remaining : 0
}

Anchor.prototype.reset = function (this: Anchor): void {
    this.usecs = Link.RadioDriver.getRxEndTimeUs() + 1250 + Connection.params().$$.winOff_us
}
