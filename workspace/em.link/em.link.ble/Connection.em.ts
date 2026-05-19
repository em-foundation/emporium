import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

export class Params extends $struct {
    accAdr: u32
    crcInit: u32
    interval: u16
    latency: u16
    winOff: u16
    winSize: u16
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
    $['%%>'](chan_num)
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
    paramsA.interval = ((Mem.scan16($$(pkt.$$.interval[0])) * 5) / 4) - TB.INTERVAL_FUDGE
    paramsA.winOff = Mem.scan16($$(pkt.$$.winOff[0]))
    paramsA.winSize = pkt.$$.winSize
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
    paramsB.interval = ((Mem.scan16($$(data.$$.interval[0])) * 5) / 4) - TB.INTERVAL_FUDGE
    paramsB.winOff = Mem.scan16($$(data.$$.winOff[0]))
    paramsB.winSize = data.$$.winSize
    instant = Mem.scan16($$(data.$$.instant[0]))
}

/*
module Connection

    type Params: struct
        accAdr: uint32
        crcInit: uint32
        interval: uint16
        latency: uint16
        winOff: uint16
        winSize: uint16
    end

    function channel(): uint8
    function close()
    function next(): bool
    function open(pkt: Types.ConnPkt&)
    function params(): Params&
    function update(data: Types.ConnUpdData&)



def channel()
    return chanNum
end

def close()
    current = null
end

def next()
    auto ch = chanNum + chanHop
    chanNum = ch > 36 ? (ch - 37) : ch
    evtCount += 1
    return false if evtCount != instant
    paramsA := paramsB
    instant = 0
    return true
end

def open(pkt)
    auto params = &paramsA
    params.accAdr = Types.parse32(&pkt.accAdr[0])
    params.crcInit = Types.parse32(&pkt.crcInit[0])
    params.interval = ((Types.parse16(&pkt.interval[0]) * 5) / 4) - Types.INTERVAL_FUDGE
    params.winOff = Types.parse16(&pkt.winOff[0])
    params.winSize = pkt.winSize
    chanHop = pkt.hopSca & 0x1F
    chanNum = chanHop
    current = params
    instant = 0
end

def params()
    return current
end

def update(data)
    auto params = &paramsB
    params := paramsA
    params.interval = ((Types.parse16(&data.interval[0]) * 5) / 4) - Types.INTERVAL_FUDGE
    params.winOff = Types.parse16(&data.winOff[0])
    params.winSize = data.winSize
    instant = Types.parse16(&data.instant[0])
end
*/
