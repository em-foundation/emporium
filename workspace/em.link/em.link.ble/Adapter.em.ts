import '@$$emscript'
export const $U = $declare('MODULE', AdapterI)

import * as AdapterI from '@em.link/AdapterI.em'
import * as BLE from '@em.link.ble/Types.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Heap from '@em.utils/Heap.em'
import * as LedI from '@em.hal/LedI.em'
import * as OneShotI from '@em.hal/OneShotI.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as T from '@em.link/Types.em'

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

const rx_buf = <T.BufPtr>Heap.opaq(rx_adr)
const tx_buf = <T.BufPtr>Heap.opaq(tx_adr)

const adv_hdr = <$$<BLE.AdvHdr>>Heap.opaq(tx_adr)

enum State {
    ADV_PAUSE, ADV_SCAN, CONN, CONN_PAUSE, EXCH, IDLE
}

var adv_con_flag: bool_t
var adv_count: u16
var adv_inter: u16
var adv_mask: u8
var adv_power: i8
var cur_adv_chan: u8
var cur_state: State = State.IDLE
var recv_done: T.RecvDoneFxn

export function recvMsg(on_done: T.RecvDoneFxn) {
    recv_done = on_done
    if (cur_state == State.IDLE) {
        const params = Registry.getParams()
        adv_con_flag = params.$$.ble_connectible
        adv_count = params.$$.send_count
        adv_mask = params.$$.ble_adv_chan_mask ? params.$$.ble_adv_chan_mask : ALL_ADV_CHANS
        adv_inter = params.$$.send_interval_ms
        adv_power = params.$$.radio_power
        cur_adv_chan = 0
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
                    recv_done(T.ConnectionStatus.TIMEOUT)
                    return
                }
                setState(State.ADV_SCAN)
                setTimeout(adv_inter)
                return
            }
            case State.ADV_SCAN: {
                if (cur_adv_chan == NUM_ADV_CHANS) {
                    cur_adv_chan = 0
                    setState(State.ADV_PAUSE)
                    continue
                }
                const idx = cur_adv_chan++
                if (!(adv_mask & (1 << idx))) continue
                doAdvScan(BLE.ADV_CHAN + idx)
                return
            }
        }
    }
}

function controllerFB(_: arg_t) {
    controller()
}

function doAdvScan(chan: u8) {
    adv_hdr.$$.init((adv_con_flag ? BLE.ADV_IND : BLE.ADV_NONCONN_IND))
    adv_hdr.$$.addData(Registry.getSchemaHash(), $sizeof<T.SchemaHash>())
    // const nid = Registry.getNodeId()
    // adv_hdr.$$.addData(nid.$$.devAddr, $sizeof<T.Addr>())
    // adv_hdr.$$.print()
    Registry.setupParams($cb(scanProf))
    radioOn()
    RadioDriver.startTx(adv_hdr.$$.frame(), chan)
}

function radioHandler() {
    controllerF.$$.post()
}

function radioOff() {
    RadioDriver.disable()
    Led.off()
}

function radioOn() {
    RadioDriver.enable()
    Led.on()
}

function scanChain(in_buf: T.BufPtr): T.BufFrame {
    return $null
}

function scanProf(params: $$<T.Params>) {
    params.$$.ble_enable = true
    params.$$.radio_phy = T.Phy.BLE_1M
    params.$$.radio_power = adv_power
    if (!adv_con_flag) return
    params.$$.ble_chain = $cb(scanChain)
    params.$$.ble_exch_buf = rx_buf
    params.$$.ble_exch_end_ms = 20
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
