import '@$$emscript'
export const $U = $declare('MODULE')

import * as Heap from '@em.utils/Heap.em'
import * as Mem from '@em.utils/Mem.em'
import * as TB from '@em.link.ble/Types.em'
import * as TL from '@em.link/Types.em'

const rx_adr = $config<Heap.Adr>()

export namespace em$meta {
    export function allocRx(size: u16) {
        rx_adr.$$val = Heap.em$meta.alloc(size)
    }
}

//>> ---- em$targ ---- <<//

const LL_PAYLOAD_MAX = 27
const rx_buf = <TL.BufPtr>Heap.opaq(rx_adr)

class RxState extends $struct {
    active: bool_t
    len: u16
    need: u16
}
class TxState extends $struct {
    active: bool_t
    pending: bool_t
    len: u16
    off: u16
}

var rx: RxState
var tx: TxState

export function active(): bool_t {
    return rx.active
}

export function append(req: $$<TB.LnkHdr>): bool_t {
    const pdu = req.$$.pduPtr()
    Mem.cpy($$(rx_buf[rx.len]), $$(pdu[0]), req.$$.pduLen)
    rx.len += req.$$.pduLen
    if (rx.len < rx.need) return false
    rx.active = false
    return true
}

export function begin(req: $$<TB.LnkHdr>): bool_t {
    const pdu = req.$$.pduPtr()
    rx.need = (pdu[0] | (pdu[1] << 8)) + 4
    rx.len = req.$$.pduLen
    Mem.cpy($$(rx_buf[0]), $$(pdu[0]), rx.len)
    rx.active = rx.len < rx.need
    return !rx.active
}

export function beginTx(len: u16): TL.BufPtr {
    tx.active = true
    tx.pending = false
    tx.len = len
    tx.off = 0
    return rx_buf
}

export function data(): TL.BufPtr {
    return rx_buf
}

export function len(): u16 {
    return rx.len
}

export function reset() {
    rx.active = false
    rx.len = 0
    rx.need = 0
    tx.active = false
    tx.pending = false
    tx.len = 0
    tx.off = 0
}

export function stageTx(pkt: $$<TB.LnkHdr>): bool_t {
    if (!tx.active || tx.pending) return false
    const remain = tx.len - tx.off
    const frag_len = remain > LL_PAYLOAD_MAX ? LL_PAYLOAD_MAX : <u8>remain
    pkt.$$.init(tx.off == 0 ? TB.LL_START : TB.LL_CONT)
    Mem.cpy(pkt.$$.pduPtr(), $$(rx_buf[tx.off]), frag_len)
    pkt.$$.pduLen = frag_len
    tx.off += frag_len
    tx.pending = true
    return true
}

export function txAcked(): bool_t {
    if (!tx.pending) return false
    tx.pending = false
    if (tx.off < tx.len) return false
    tx.active = false
    return true
}

export function txActive(): bool_t {
    return tx.active
}
