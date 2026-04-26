import '@$$emscript'
export const $U = $declare('MODULE', AdapterI)

import * as AdapterI from '@em.link/AdapterI.em'
import * as BLE from '@em.link.ble/Types.em'
import * as Heap from '@em.utils/Heap.em'
import * as LedI from '@em.hal/LedI.em'
import * as OneShotI from '@em.hal/OneShotI.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as T from '@em.link/Types.em'

export const Led = $proxy<LedI.$I>()
export const OneShot = $proxy<OneShotI.$I>()
export const RadioDriver = $proxy<RadioDriverI.$I>()

const rx_adr = $config<Heap.Adr>()
const tx_adr = $config<Heap.Adr>()

export namespace em$meta {
    export function em$construct() {
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
    while (true) {
        switch (cur_state) {
            case State.ADV_PAUSE: {
                if (--adv_count == 0) {
                    recv_done(T.ConnectionStatus.TIMEOUT)
                    return
                }
                radioOff()
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

function doAdvScan(chan: u8) {
    adv_hdr.$$.init(adv_con_flag ? BLE.ADV_IND : BLE.ADV_NONCONN_IND)
    adv_hdr.$$.addData(Registry.getSchemaHash(), $sizeof<T.SchemaHash>())

    /*
        auto hdr = <Types.AdvHdr&>(txPtr)
        hdr.init(advConFlag ? Types.ADV_IND : Types.ADV_NONCONN_IND)
        hdr.addData(SysSupport.getSchemaHash(), sizeof<Dev.SchemaHash>)
        auto nodeId = SysSupport.getNodeId()    
        hdr.addData(&nodeId.devAddr, sizeof<Dev.Addr>)
        SysSupport.setupParams(mix_SCAN)
        radioOn()
        RadioDriver.setup(RadioDriver.Mode.TX, chan)
        RadioDriver.startTx(txPtr, *(txPtr + 1) + 2, false)
    */

}

function radioHandler() {
    controller()
}

function radioOff() {
    RadioDriver.disable()
    Led.off()
    $['%%a-']
}

function radioOn() {
    RadioDriver.enable()
    Led.on()
    $['%%a+']
}

function setState(s: State) {
    cur_state = s
}

function setTimeout(msecs: u32) {
    OneShot.disable()
    OneShot.enable(msecs, $cb(controller), 0)
}
