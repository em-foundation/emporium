import '@$$emscript'
export const $U = $declare('MODULE', AdapterI)

import * as AdapterI from '@em.link/AdapterI.em'
import * as Connection from '@em.link.ble/Connection.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Heap from '@em.utils/Heap.em'
import * as LedI from '@em.hal/LedI.em'
import * as LnkTx from '@em.link.ble/LnkTx.em'
import * as MsCounter from '@em.utils/MsCounter.em'
import * as OneShotI from '@em.hal/OneShotI.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

export const Led = $proxy<LedI.$I>()
export const OneShot = $proxy<OneShotI.$I>()
export const RadioDriver = $proxy<RadioDriverI.$I>()

const controllerF = $config<FiberMgr.Obj>()
const reqF = $config<FiberMgr.Obj>()
const rspF = $config<FiberMgr.Obj>()

const rx_adr = $config<Heap.Adr>()
const tx_adr = $config<Heap.Adr>()

export namespace em$meta {
    export function em$construct() {
        controllerF.$$val = FiberMgr.em$meta.create($cb(controllerFB))
        reqF.$$val = FiberMgr.em$meta.create($cb(reqFB))
        rspF.$$val = FiberMgr.em$meta.create($cb(rspFB))
        RadioDriver.em$meta.bindHandler($cb(radioHandler))
        rx_adr.$$val = Heap.em$meta.alloc(40)
        tx_adr.$$val = Heap.em$meta.alloc(40)
        LnkTx.em$meta.bindAttBuf(tx_adr.$$val)
    }
}

//>> ---- em$targ ---- <<//

const ALL_ADV_CHANS = 0x7
const NULL_PKT_LIMIT = 6
const NUM_ADV_CHANS = 3

const rx_buf = <TL.BufPtr>Heap.opaq(rx_adr)
const tx_buf = <TL.BufPtr>Heap.opaq(tx_adr)

const adv_hdr = <$$<TB.AdvHdr>>Heap.opaq(tx_adr)
const adv_req = <$$<TB.AdvReqHdr>>Heap.opaq(rx_adr)

const conn_pkt = <$$<TB.ConnPkt>>Heap.opaq(rx_adr)

const lnk_req = <$$<TB.LnkHdr>>Heap.opaq(rx_adr)

const scan_rsp = <$$<TB.ScanRsp>>Heap.opaq(tx_adr)

enum State {
    ADV_PAUSE, ADV_SCAN, CONN, CONN_PAUSE, EXCH, CLOSING, IDLE
}

var find_req: TB.GattFindReq
var type_req: TB.GattTypeReq

var adv_con_flag: bool_t
var adv_count: u16
var adv_inter: u16
var adv_mask: u8
var adv_power: i8
var cur_adv_mask: u8
var cur_state: State = State.IDLE
var msg_rsp_flag: bool_t
var null_pkt_cnt: u8
var recv_done: TL.RecvDoneFxn
var upd_flag: bool_t

var exch_cnt: u8 = 0

export function recvMsg(on_done: TL.RecvDoneFxn) {
    recv_done = on_done
    if (cur_state == State.IDLE) {
        const params = Registry.getParams()
        adv_con_flag = params.$$.ble_connectible
        adv_count = params.$$.send_count
        adv_mask = params.$$.ble_adv_chan_mask ? params.$$.ble_adv_chan_mask : ALL_ADV_CHANS
        adv_inter = params.$$.send_interval_ms
        adv_power = params.$$.radio_power
        cur_adv_mask = 0
        setState(State.ADV_PAUSE)
        controller()
    }
}

function controller() {
    $['%%c:'](cur_state)
    while (true) {
        switch (cur_state) {
            case State.ADV_PAUSE: {
                radioOff()
                if (adv_count-- == 0) {
                    recv_done(TL.ConnectionStatus.TIMEOUT)
                    return
                }
                setTimeout(adv_inter)
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
                if (!(adv_mask & (1 << idx))) continue
                doAdvScan(TB.ADV_CHAN + idx)
                return
            }
            case State.CONN: {
                Connection.open(conn_pkt)
                recv_done(TL.ConnectionStatus.OPENING)
                LnkTx.reset()
                doExch(1000)
                setState(State.CONN_PAUSE)
                return
            }
            case State.CONN_PAUSE: {
                radioOff()
                if (RadioDriver.getRxBuf() == null) {
                    if (++null_pkt_cnt >= NULL_PKT_LIMIT) {
                        recv_done(TL.ConnectionStatus.HANGUP)
                        return
                    }
                } else {
                    null_pkt_cnt = 0
                }
                const t1 = MsCounter.stop()
                const ci = Connection.params().$$.interval
                const dt = (t1 == 0) ? ci : (t1 > ci) ? ((ci * 2) - t1) : ci - (ci - t1)
                MsCounter.start()
                setTimeout(dt)
                setState(State.EXCH)
                return
            }
            case State.EXCH: {
                upd_flag = Connection.next()
                if (upd_flag) {
                    MsCounter.stop()
                }
                doExch(upd_flag ? 1000 : TB.INTERVAL_FUDGE * 3)
                setState(State.CONN_PAUSE)
                return
            }
            case State.CLOSING: {
                radioOff()
                setState(State.IDLE)
                recv_done(TL.ConnectionStatus.CLOSED)
                return
            }
        }
    }
}

function controllerFB(_: arg_t) {
    controller()
}

function doAdvScan(chan: u8) {
    adv_hdr.$$.init((adv_con_flag ? (TB.ADV_IND | 0x40) : TB.ADV_NONCONN_IND))
    // adv_hdr.$$.addData(Registry.getSchemaHash(), $sizeof<TL.SchemaHash>())
    // adv_hdr.$$.addName(t$`EMS`)

    // const nid = Registry.getNodeId()
    // adv_hdr.$$.addData(nid.$$.devAddr, $sizeof<T.Addr>())
    // adv_hdr.$$.print()
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
    let tab = TB.LL_REJECT_DATA.$frame(0)
    let rsp_data = tab
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
    $['%%a']
    if (lnk_req.$$.isCtrl()) {
        const rsp = LnkTx.getCtrlPkt()
        // assert(rsp != $null)
        if (reqCtrl(rsp)) {
            LnkTx.setCtrlReady()
        }
    } else {
        const rsp = LnkTx.getAttPkt()
        // assert(rsp != $null)
        if (reqGatt(rsp)) {
            LnkTx.setAttReady()
        }
    }
}

function reqGatt(rsp_pkt: $$<TB.LnkHdr>): bool_t {
    const att_pkt = lnk_req.$$.attPkt()
    let att_rsp_op = 0
    let att_rsp_data = <TL.BufFrame>$null
    switch (att_pkt.$$.opcode) {
        case TB.ATT_EXCHANGE_MTU_REQ: {
            att_rsp_op = TB.ATT_EXCHANGE_MTU_RSP
            att_rsp_data = TB.ATT_EXCHANGE_MTU_DATA.$frame(0)
            break
        }
        case TB.ATT_READ_BY_GROUP_TYPE_REQ:
        case TB.ATT_READ_BY_TYPE_REQ: {
            type_req.init(att_pkt)
            switch (type_req.typeId) {
                case TB.GATT_CHARACTERISTIC: {
                    if (type_req.startHandle == 0x0001) {
                        att_rsp_data = TB.GATT_CHARACTERISTIC_DATA.$frame(0)
                    }
                    break
                }
                case TB.GATT_PRIMARY_SERVICE: {
                    att_rsp_data = TB.GATT_PRIMARY_SERVICE_DATA.$frame(0)
                    break
                }
            }
            if (att_rsp_data.$len == 0) {
                att_rsp_op = TB.ATT_ERROR_RESPONSE
                att_rsp_data = TB.ATT_ERROR_DATA.$frame(0)
            } else {
                att_rsp_op = att_pkt.$$.opcode + 1
            }
            break
        }
        case TB.ATT_FIND_INFORMATION_REQ: {
            find_req.init(att_pkt)
            if (find_req.startHandle <= 0x0001 && find_req.endHandle >= 0x0001) {
                att_rsp_op = TB.ATT_FIND_INFORMATION_RSP
                att_rsp_data = TB.GATT_FIND_INFO_HANDLE1_DATA.$frame(0)
            } else {
                att_rsp_op = TB.ATT_ERROR_RESPONSE
                att_rsp_data = TB.ATT_ERROR_DATA.$frame(0)
            }
            break
        }
        case TB.ATT_WRITE_CMD: {
            recv_done(TL.ConnectionStatus.ACTIVE)
            break
        }
        default: {
            printf`reqGatt: %d\n`(att_pkt.$$.opcode)
            fail()
        }
    }
    if (att_rsp_data.$len == 0) return false
    rsp_pkt.$$.init(TB.LL_START)
    rsp_pkt.$$.addAttPkt(att_rsp_op, att_rsp_data)
    return true
}

function rspFB(_: arg_t) {
    msg_rsp_flag = false
    printf`rspFB\n`()
    fail()


    /*
        msgRspFlag = false
        lnkRsp.init(Types.LL_START)
        lnkRsp.addAttPkt(Types.ATT_HANDLE_VALUE_NTF, Types.GATT_NOTIFY_DATA)
        lnkRsp.addGattVal(&msg, msg.hdr.size)
        lnkRspFlag = true
        sendDone()
    */

}

function scanChain(in_buf: TL.BufPtr): TL.BufFrame {
    if (adv_req.$$.isScan()) {
        const params = Registry.getParams()
        params.$$.ble_exch_buf = $null
        params.$$.ble_chain = $null
        scan_rsp.$$.init()
        // adv_hdr.$$.addName(t$`EMS`)
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
    if (!adv_con_flag) return
    params.$$.ble_chain = $cb(scanChain)
    params.$$.ble_exch_buf = rx_buf
    params.$$.ble_exch_end_ms = 50
}

function setState(s: State) {
    cur_state = s
}

function setTimeout(msecs: u32) {
    OneShot.disable()
    OneShot.enable(msecs, $cb(timerHandler), 0)
}

function timerHandler(_: arg_t) {
    controllerF.$$.post()
}
