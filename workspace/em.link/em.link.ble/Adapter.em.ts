import '@$$emscript'
export const $U = $declare('MODULE', AdapterI)

import * as AdapterI from '@em.link/AdapterI.em'
import * as Connection from '@em.link.ble/Connection.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Heap from '@em.utils/Heap.em'
import * as LedI from '@em.hal/LedI.em'
import * as OneShotI from '@em.hal/OneShotI.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

export const Led = $proxy<LedI.$I>()
export const OneShot = $proxy<OneShotI.$I>()
export const RadioDriver = $proxy<RadioDriverI.$I>()

const controllerF = $config<FiberMgr.Obj>()

const rx_adr = $config<Heap.Adr>()
const tx_adr = $config<Heap.Adr>()

export namespace em$meta {
    export function em$construct() {
        controllerF.$$val = FiberMgr.em$meta.create($cb(controllerFB))
        RadioDriver.em$meta.bindHandler($cb(radioHandler))
        rx_adr.$$val = Heap.em$meta.alloc(40)
        tx_adr.$$val = Heap.em$meta.alloc(40)
    }
}

//>> ---- em$targ ---- <<//

const ALL_ADV_CHANS = 0x7
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
var recv_done: TL.RecvDoneFxn

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
    while (true) {
        $['%%c:'](cur_state)
        switch (cur_state) {
            case State.ADV_PAUSE: {
                radioOff()
                if (adv_count-- == 0) {
                    recv_done(TL.ConnectionStatus.TIMEOUT)
                    return
                }
                setState(State.ADV_SCAN)
                setTimeout(adv_inter)
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
                setState(State.CONN_PAUSE)
                doExch(1000)
                return
            }
            case State.CONN_PAUSE: {
                radioOff()
                halt()
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

    // const bf = adv_hdr.$$.frame()
    // printf`len = %d: `(bf.$len)
    // for (const b of bf) {
    //     printf`%02x `(b.$$)
    // }
    // printf`\n`()
    // halt()

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
    printf`flag = %02x, len = %d\n`(lnk_req.$$.lnkFlags, lnk_req.$$.pduLen)
    halt()
    /*
        auto req = <Types.LnkHdr&>inPkt     ## must copy
        if req.pduLen > 0
            reqP.post()
        elif msgRspFlag
            rspP.post()
        end
        lnkRsp.init(Types.LL_CONT) if !lnkRspFlag
        lnkRspFlag = false
        lnkRsp.setAck(lnkReq.lnkFlags)
        return <uint8*>lnkRsp
    */
    return $null
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

function scanChain(in_buf: TL.BufPtr): TL.BufFrame {

    /*
        auto req = <Types.AdvReqHdr&>inPkt
        if req.isScan()
            auto params = SysSupport.getParams()
            params.bleExchBuf = null
            params.bleTrain = null
            SysSupport.setupParams(null)
            auto rsp = <Types.ScanRspHdr&>(txPtr)
            rsp.init()
            return <uint8*>rsp
        end
        setState(State.CONN) if req.isMine() && req.isConn()
        return null
    */


    if (adv_req.$$.isScan()) {
        // $['%%d']
        // printf`scanReq: `()
        // TL.printAddr(adv_req.$$.reqA)
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
