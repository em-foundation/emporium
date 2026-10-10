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

const rx_buf = <TL.BufPtr>Heap.opaq(rx_adr)

var rx_active: bool_t
var rx_len: u16
var rx_need: u16

export function active(): bool_t {
    return rx_active
}

export function append(req: $$<TB.LnkHdr>): bool_t {
    const pdu = req.$$.pduPtr()
    Mem.cpy($$(rx_buf[rx_len]), $$(pdu[0]), req.$$.pduLen)
    rx_len += req.$$.pduLen
    if (rx_len < rx_need) return false
    rx_active = false
    return true
}

export function begin(req: $$<TB.LnkHdr>): bool_t {
    const pdu = req.$$.pduPtr()
    rx_need = (pdu[0] | (pdu[1] << 8)) + 4
    rx_len = req.$$.pduLen
    Mem.cpy($$(rx_buf[0]), $$(pdu[0]), rx_len)
    rx_active = rx_len < rx_need
    return !rx_active
}

export function data(): TL.BufPtr {
    return rx_buf
}

export function len(): u16 {
    return rx_len
}

export function reset() {
    rx_active = false
    rx_len = 0
    rx_need = 0
}
