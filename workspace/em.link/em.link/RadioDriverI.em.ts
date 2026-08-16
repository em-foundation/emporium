import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as TL from '@em.link/Types.em'

export type Handler = cb_t<[]>

export interface em$meta {
    bindHandler(h: Handler): void
}

export interface $I {
    em$meta: em$meta
    disable(): void
    enable(): void
    getRxBuf(): TL.BufPtr
    getRxEndTimeUs(): u32
    nowTimeUs(): u32
    pause(usecs: u32, handler: Handler): void
    startRx(buf: TL.BufPtr, chan: u8, timeout: u16): void
    startTx(buf: TL.BufFrame, chan: u8): void

}