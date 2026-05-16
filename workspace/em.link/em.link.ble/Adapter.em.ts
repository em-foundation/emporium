import '@$$emscript'
export const $U = $declare('MODULE', AdapterI)

import * as AdapterI from '@em.link/AdapterI.em'
import * as Connection from '@em.link.ble/Connection.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Heap from '@em.utils/Heap.em'
import * as LedI from '@em.hal/LedI.em'
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
const lnk_rsp = <$$<TB.LnkHdr>>Heap.opaq(tx_adr)

const scan_rsp = <$$<TB.ScanRsp>>Heap.opaq(tx_adr)

enum State {
    ADV_PAUSE, ADV_SCAN, CONN, CONN_PAUSE, EXCH, IDLE
}

var adv_con_flag: bool_t
var adv_count: u16
var adv_inter: u16
var adv_mask: u8
var adv_power: i8
var cur_adv_mask: u8
var cur_state: State = State.IDLE
var lnk_rsp_flag: bool_t
var msg_rsp_flag: bool_t
var null_pkt_cnt: u8
var recv_done: TL.RecvDoneFxn
var upd_flag: bool_t

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
                    } else {
                        null_pkt_cnt = 0
                    }
                }
                const t1 = MsCounter.stop()
                const ci = Connection.params().$$.interval
                const dt = (t1 == 0) ? ci : (t1 > ci) ? ((ci * 2) - t1) : ci - (ci - t1)
                // printf`t1 = %d, ci = %d, dt = %d\n`(t1, ci, dt)
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
                // printf`upd = %d, chan = %d\n`(upd_flag, Connection.channel())
                // TB.dumpPkt($cast2<opaq_t>(lnk_rsp))
                // halt()
                doExch(upd_flag ? 1000 : TB.INTERVAL_FUDGE * 3)
                setState(State.CONN_PAUSE)
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

var exch_cnt = 0

function exchChain(in_buf: TL.BufPtr): TL.BufFrame {
    exch_cnt += 1
    if (lnk_req.$$.pduLen > 0) {
        reqF.$$.post()
    }
    // else if (!lnk_rsp_flag) {
    //     rspF.$$.post()
    // }
    if (!lnk_rsp_flag) {
        lnk_rsp.$$.init(TB.LL_CONT)
    }
    lnk_rsp_flag = false
    lnk_rsp.$$.setAck(lnk_req.$$.lnkFlags)
    return lnk_rsp.$$.frame()
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
    // Led.off()
}

function radioOn() {
    Led.wink(1)
    RadioDriver.enable()
    // Led.on()
}

function reqCtrl() {
    const req_pdu = lnk_req.$$.pduPtr()
    let tab = TB.LL_REJECT_DATA.$frame(0)
    let rsp_data = tab
    switch (req_pdu[0]) {
        case TB.LL_CONN_UPDATE_IND: {
            const upd = $cast2<$$<TB.ConnUpdData>>($$(req_pdu[1]))
            Connection.update(upd)
            return
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
            radioOff()
            recv_done(TL.ConnectionStatus.CLOSED)
            return
        }
        case TB.LL_UNKNOWN_RSP: {
            return
        }
        default: {
            printf`reqCtrl: %02x\n`(req_pdu[0])
            fail()
        }
    }
    lnk_rsp.$$.init(TB.LL_CTRL)
    lnk_rsp.$$.addPdu(rsp_data)
    lnk_rsp_flag = true
}

function reqFB(_: arg_t) {
    if (lnk_req.$$.isCtrl()) {
        reqCtrl()
    } else {
        reqGatt()
    }

}

function reqGatt() {
    printf`reqGatt\n`()
    fail()
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
