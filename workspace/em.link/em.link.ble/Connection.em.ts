import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

export class Params extends $struct {
    accAdr: u32
    crcInit: u32
    interval_us: u32
    winOff_us: u32
    winSize_us: u32
    latency: u16
}

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var chan_hop: u8
var chan_num: u8
var cur_params: $$<Params>
var evt_cnt: u16
var instant: u16
var paramsA: Params
var paramsB: Params

// TODO: consider smaller struct for paramsB

export function channel(): u8 {
    // $['%%>'](chan_num)
    return chan_num
}

export function close() {
    cur_params = $null
}

export function next(): bool_t {
    const ch = chan_num + chan_hop
    chan_num = ch > 36 ? (ch - 37) : ch
    evt_cnt += 1
    if (evt_cnt != instant) return false
    Mem.cpy($$(paramsA), $$(paramsB), $sizeof<Params>())
    instant = 0
    return true
}

export function open(pkt: $$<TB.ConnPkt>) {
    paramsA.accAdr = Mem.scan32($$(pkt.$$.accAdr[0]))
    paramsA.crcInit = Mem.scan32($$(pkt.$$.crcInit[0])) & 0x00ffffff
    const upd = $cast2<$$<TB.ConnUpdData>>($$(pkt.$$.winSize))      /// TODO: add conversions in TB
    scanTiming(upd)
    paramsA.interval_us = (((Mem.scan16($$(pkt.$$.interval[0])) * 5) / 4) - TB.INTERVAL_FUDGE) * 1000
    paramsA.winOff_us = Mem.scan16($$(pkt.$$.winOff[0])) * 1250
    paramsA.winSize_us = pkt.$$.winSize * 1250
    chan_hop = pkt.$$.hopSca & 0x1f
    chan_num = chan_hop
    instant = 0
    cur_params = $$(paramsA)
}

export function params(): $$<Params> {
    return cur_params
}

export function update(data: $$<TB.ConnUpdData>) {
    Mem.cpy($$(paramsB), $$(paramsA), $sizeof<Params>())
    scanTiming(data)
    instant = Mem.scan16($$(data.$$.instant[0]))
}

function scanTiming(data: $$<TB.ConnUpdData>) {
    paramsA.interval_us = (((Mem.scan16($$(data.$$.interval[0])) * 5) / 4) - TB.INTERVAL_FUDGE) * 1000
    paramsA.winOff_us = Mem.scan16($$(data.$$.winOff[0])) * 1250
    paramsA.winSize_us = data.$$.winSize * 1250
}
