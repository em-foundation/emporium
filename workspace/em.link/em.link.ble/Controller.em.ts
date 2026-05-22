import '@$$emscript'
export const $U = $declare('MODULE')

import * as Binder from '@em.link.ble/Binder.em'
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

const rx_adr = $config<Heap.Adr>()
const tx_adr = $config<Heap.Adr>()

const controllerF = $config<FiberMgr.Obj>()
const status_cb = $config<TL.RecvDoneFxn>()

export namespace em$meta {

    export function bindStatusHandler(h: TL.RecvDoneFxn) {
        status_cb.$$val = h
    }

    export function em$construct() {
        controllerF.$$val = FiberMgr.em$meta.create($cb(controllerFB))
        RadioDriver.em$meta.bindHandler($cb(radioHandler))
        rx_adr.$$val = Heap.em$meta.alloc(Binder.em$meta.getRxBufSize())
        tx_adr.$$val = Heap.em$meta.alloc(Binder.em$meta.getTxBufSize())
    }
}

//>> ---- em$targ ---- <<//

const ALL_ADV_CHANS = 0x7
const NUM_ADV_CHANS = 3

const adv_hdr = <$$<TB.AdvHdr>>Heap.opaq(tx_adr)
const adv_req = <$$<TB.AdvReqHdr>>Heap.opaq(rx_adr)
const rx_buf = <TL.BufPtr>Heap.opaq(rx_adr)
const scan_rsp = <$$<TB.AdvHdr>>Heap.opaq(tx_adr)

enum State {
    ADV_PAUSE,
    ADV_SCAN,
    IDLE,
}

var adv_count: u16
var adv_inter: u16
var adv_mask: u8
var adv_power: i8
var cur_adv_mask: u8
var cur_state: State = State.IDLE

export function start() {
    if (cur_state != State.IDLE) {
        return
    }
    const params = Registry.getParams()
    adv_count = params.$$.send_count
    adv_mask = params.$$.ble_adv_chan_mask ? params.$$.ble_adv_chan_mask : ALL_ADV_CHANS
    adv_inter = params.$$.send_interval_ms
    adv_power = params.$$.radio_power
    cur_adv_mask = 0
    setState(State.ADV_PAUSE)
    controller()
}

export function stop() {
    radioOff()
    setState(State.IDLE)
}

function controller() {
    while (true) {
        switch (cur_state) {
            case State.ADV_PAUSE: {
                radioOff()
                if (adv_count-- == 0) {
                    setState(State.IDLE)
                    status_cb(TL.ConnectionStatus.TIMEOUT)
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
                if (!(adv_mask & (1 << idx))) {
                    continue
                }
                doAdvScan(TB.ADV_CHAN + idx)
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
    Registry.setupParams($cb(scanProf))
    radioOn()
    Binder.initAdvPkt(adv_hdr)
    RadioDriver.startTx(adv_hdr.$$.frame(), chan)
}

function radioHandler() {
    controllerF.$$.post()
}

function radioOff() {
    RadioDriver.disable()
}

function radioOn() {
    Led.wink(1)
    RadioDriver.enable()
}

function scanChain(in_buf: TL.BufPtr): TL.BufFrame {
    if (adv_req.$$.isScan()) {
        Binder.initScanRspPkt(scan_rsp)
        return scan_rsp.$$.frame()
    }
    return $null
}

function scanProf(params: $$<TL.Params>) {
    params.$$.ble_enable = true
    params.$$.radio_phy = TL.Phy.BLE_1M
    params.$$.radio_power = adv_power
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