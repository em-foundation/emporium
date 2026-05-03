import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as T from '@em.link/Types.em'

export type Handler = cb_t<[]>

export interface em$meta {
    bindHandler(h: Handler): void
}

export interface $I {
    em$meta: em$meta
    disable(): void
    enable(): void
    startRx(buf: T.BufFrame, chan: u8, timeout: u16): void
    startTx(buf: T.BufFrame, chan: u8): void

}