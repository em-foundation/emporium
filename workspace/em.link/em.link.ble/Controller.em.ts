import '@$$emscript'
export const $U = $declare('MODULE')

import * as Binder from '@em.link.ble/Binder.em'
import * as Connection from '@em.link.ble/Connection.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Heap from '@em.utils/Heap.em'
import * as LedI from '@em.hal/LedI.em'
import * as LnkTx from '@em.link.ble/LnkTx.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

export const Led = $proxy<LedI.$I>()
export const RadioDriver = $proxy<RadioDriverI.$I>()

const rx_adr = $config<Heap.Adr>()
const tx_adr = $config<Heap.Adr>()

const controllerF = $config<FiberMgr.Obj>()
const reqF = $config<FiberMgr.Obj>()
const status_cb = $config<TL.RecvDoneFxn>()

export namespace em$meta {

    export function bindStatusHandler(h: TL.RecvDoneFxn) {
        status_cb.$$val = h
    }

    export function em$construct() {
        controllerF.$$val = FiberMgr.em$meta.create($cb(controllerFB))
        reqF.$$val = FiberMgr.em$meta.create($cb(reqFB))
        RadioDriver.em$meta.bindHandler($cb(radioHandler))
        rx_adr.$$val = Heap.em$meta.alloc(Binder.em$meta.getRxBufSize())
        tx_adr.$$val = Heap.em$meta.alloc(Binder.em$meta.getTxBufSize())
        LnkTx.em$meta.bindAttBuf(tx_adr.$$val)
    }
}

//>> ---- em$targ ---- <<//

const ALL_ADV_CHANS = 0x7
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

class Anchor extends $struct {
    usecs: u32
    valid: bool_t
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
var upd_flag: bool_t

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
    setState(State.ADV_PAUSE)
    controller()
}

export function stop() {
    radioOff()
    setState(State.IDLE)
}

function controller() {
    $['%%c:'](cur_state)
    while (true) {
        switch (cur_state) {
            case State.ADV_PAUSE: {
                radioOff()
                if (adv_count-- == 0) {
                    setState(State.IDLE)
                    status_cb(TL.ConnectionStatus.TIMEOUT)
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
                status_cb(TL.ConnectionStatus.OPENING)
                anchor.reset()
                LnkTx.reset()
                doExch(1000)
                setState(State.CONN_PAUSE)
                return
            }

            case State.CONN_PAUSE: {
                radioOff()
                const air_us = (RadioDriver.getRxBuf() != $null) ? rxAirtimeUs(lnk_req) : 0
                if (air_us == 0) {
                    if (++null_pkt_cnt >= NULL_PKT_LIMIT) {
                        status_cb(TL.ConnectionStatus.HANGUP)
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
                status_cb(TL.ConnectionStatus.CLOSED)
                return
            }

            case State.IDLE: {
                return
            }
        }
    }
}

function controllerFB(_: arg_t) {
    controller()
}

function doAdvScan(chan: u8) {
    Binder.initAdvPkt(adv_hdr)
    Registry.setupParams($cb(scanProf))
    radioOn()
    RadioDriver.startTx(adv_hdr.$$.frame(), chan)
}

function doExch(end_ms: u16) {
    Registry.setupParams($cb(exchProf))
    radioOn()
    RadioDriver.startRx(rx_buf, Connection.channel(), end_ms)
}

function exchChain(in_buf: TL.BufPtr): TL.BufFrame {
    LnkTx.ack(lnk_req)
    if (lnk_req.$$.pduLen > 0) {
        reqF.$$.post()
    }
    return LnkTx.choose(lnk_req)
}

function exchProf(params: $$<TL.Params>) {
    params.$$.ble_enable = true
    params.$$.radio_phy = TL.Phy.BLE_1M
    params.$$.radio_power = adv_power
    params.$$.ble_acc_adr = Connection.params().$$.accAdr
    params.$$.ble_crc_init = Connection.params().$$.crcInit
    params.$$.ble_exch_buf = $null
    params.$$.ble_chain = $cb(exchChain)
}

function radioHandler() {
    controllerF.$$.post()
}

function radioOff() {
    RadioDriver.disable()
}

function radioOn() {
    if (cur_state == State.ADV_SCAN) {
        Led.wink(1)
    }
    RadioDriver.enable()
}

function reqCtrl(rsp_pkt: $$<TB.LnkHdr>): bool_t {
    const req_pdu = lnk_req.$$.pduPtr()
    let rsp_data = TB.LL_REJECT_DATA.$frame(0)
    let unk_flag = false
    const opcode = req_pdu[0]
    switch (opcode) {
        case TB.LL_CONN_UPDATE_IND: {
            const upd = $cast2<$$<TB.ConnUpdData>>($$(req_pdu[1]))
            Connection.update(upd)
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
        if (reqCtrl(rsp)) {
            LnkTx.setCtrlReady()
        }
    } else {
        const rsp = LnkTx.getAttPkt()
        if (Binder.reqGatt(lnk_req.$$.attPkt(), rsp)) {
            LnkTx.setAttReady()
        }
    }
}

function rxAirtimeUs(pkt: $$<TB.LnkHdr>): u32 {
    return (10 + pkt.$$.pduLen) * 8
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
    RadioDriver.pause(usecs, $cb(timerHandler))
}

function timerHandler() {
    controllerF.$$.post()
}

const HFCLK_GUARD_US = 650
const RX_GUARD_US = 0

Anchor.prototype.nextPause = function (this: Anchor, air_us: u32): u32 {
    const interval_us = Connection.params().$$.interval_us
    if (air_us != 0) {
        const rx_end_us = RadioDriver.getRxEndTimeUs()
        this.usecs = rx_end_us - air_us
        this.valid = true
    } else if (this.valid) {
        this.usecs += interval_us
    } else {
        return interval_us
    }
    const wake_us = this.usecs + interval_us - HFCLK_GUARD_US - RX_GUARD_US
    const now_us = RadioDriver.nowTimeUs()
    return wake_us > now_us ? wake_us - now_us : 0
}

Anchor.prototype.reset = function (this: Anchor): void {
    this.valid = false
}
