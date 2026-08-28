import '@$$emscript'
export const $U = $declare('MODULE')

export const NUM_DESCS = 8
export const MSG_SIZE = 0x40
export const MSG_WORDS = MSG_SIZE / 4
export const CTRL_SIZE = 0x4E8

export const CTRL_VERSION = 0x00010000
export const DESC_DONE = 0
export const DESC_BUSY = 1
export const DESC_FREE = 3

export const IPC_SEND_RPC = 3
export const IPC_RECV_RPC = 4

export const RPC_PREAMBLE_REQ = 0x00050003
export const RPC_PREAMBLE_RSP = 0x00020003
export const RPC_KIND_REQ = 2
export const RPC_CTRL_SIZE_AT_INIT = 4
export const RPC_OP_AT_INIT = 0xA7

export class Msg extends $vector<u32> {
    $len = MSG_WORDS
}

export class MsgVec extends $vector<Msg> {
    $len = NUM_DESCS
}

export class Desc extends $struct {
    state: u32
    msg: $$<Msg>
}

export class DescVec extends $vector<Desc> {
    $len = NUM_DESCS
}

export class RpcList extends $struct {
    count: u32
    descs: DescVec
}

export class HostHdr extends $struct {
    version: u32
    data_base: u32
    data_size: u32
    list_a: $$<RpcList>
    list_b: $$<RpcList>
    modem_hdr: u32
    reserved0: u32
    reserved1: u32
}

export class ModemHdrRest extends $vector<u32> {
    $len = 13
}

export class ModemHdr extends $struct {
    state: u32
    ptr0: u32
    ptr1: u32
    rest: ModemHdrRest
}

export class Ctrl extends $struct {
    host: HostHdr          // +0x000, size 0x20
    modem: ModemHdr        // +0x020, size 0x40
    list_a: RpcList        // +0x060, size 0x44
    list_b: RpcList        // +0x0A4, size 0x44
    msgs_a: MsgVec         // +0x0E8, size 0x200
    msgs_b: MsgVec         // +0x2E8, size 0x200
}

export const SHMEM_SIZE = 0x2000
export const SHMEM_WORDS = SHMEM_SIZE / 4
export const TX_RX_PAD_SIZE = 0x80
export const TX_RX_PAD_WORDS = TX_RX_PAD_SIZE / 4

export class ShmemArea extends $vector<u32> {
    $len = SHMEM_WORDS
}

export class TxRxPad extends $vector<u32> {
    $len = TX_RX_PAD_WORDS
}

export class SharedMem extends $struct {
    ctrl: Ctrl             // +0x0000, size 0x04E8
    tx: ShmemArea          // +0x04E8, size 0x2000
    pad: TxRxPad           // +0x24E8, size 0x0080
    rx: ShmemArea          // +0x2568, size 0x2000
}

export namespace em$meta { }

//>> ---- em$targ ---- <<//
