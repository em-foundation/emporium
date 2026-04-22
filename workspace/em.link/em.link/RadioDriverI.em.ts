import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as T from '@em.link/Types.em'

type Handler = cb_t<[]>

export interface em$meta {
    bindHandler(h: Handler): void
}

export interface $I {
    em$meta: em$meta
    disable(): void
    enable(): void
    startRx(rx_buf: T.BufPtr, chan: u8): void
    startTx(tx_buf: T.BufPtr, chan: u8): void
}