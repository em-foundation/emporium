import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'

const NUM_DESCS = 8
const MSG_SIZE = 0x40
const MSG_WORDS = MSG_SIZE / 4
const CTRL_SIZE = 0x4E8

const CTRL_VERSION = 0x00010000
const DESC_FREE = 3

class Msg extends $vector<u32> {
    $len = MSG_WORDS
}

class MsgVec extends $vector<Msg> {
    $len = NUM_DESCS
}

class Desc extends $struct {
    state: u32
    msg: $$<Msg>
}

class DescVec extends $vector<Desc> {
    $len = NUM_DESCS
}

class RpcList extends $struct {
    count: u32
    descs: DescVec
}

class HostHdr extends $struct {
    version: u32
    data_base: u32
    data_size: u32
    list_a: $$<RpcList>
    list_b: $$<RpcList>
    modem_hdr: u32
    reserved0: u32
    reserved1: u32
}

class ModemHdrRest extends $vector<u32> {
    $len = 13
}

class ModemHdr extends $struct {
    state: u32
    ptr0: u32
    ptr1: u32
    rest: ModemHdrRest
}

class Ctrl extends $struct {
    host: HostHdr          // +0x000, size 0x20
    modem: ModemHdr        // +0x020, size 0x40
    list_a: RpcList        // +0x060, size 0x44
    list_b: RpcList        // +0x0A4, size 0x44
    msgs_a: MsgVec         // +0x0E8, size 0x200
    msgs_b: MsgVec         // +0x2E8, size 0x200
}

var ctrl_tab = $table<Ctrl>()

export namespace em$meta {
    export function em$construct() {
        const ctrl = ctrl_tab.$$add()
        ctrl.$$.host.version = CTRL_VERSION
        ctrl.$$.list_a.count = NUM_DESCS
        ctrl.$$.list_b.count = NUM_DESCS
        for (const i of $range(NUM_DESCS)) {
            ctrl.$$.list_a.descs[i].state = DESC_FREE
            ctrl.$$.list_b.descs[i].state = DESC_FREE
        }
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    const sz = $sizeof<Ctrl>()
    Mem.prW(t$`ctrl_tab`, $cast2<ptr_t<u32>>($$(ctrl_tab)), sz / 4)
}
