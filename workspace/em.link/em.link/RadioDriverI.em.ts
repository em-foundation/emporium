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
    startEnable(): void
    startRx(buf: TL.BufPtr, chan: u8, timeout: u16): void
    // Prepare one packet in RAM without starting RF activity; a later call may
    // replace the candidate. Storage must remain valid through TX completion.
    // Link-layer selection/retransmission ownership stays with the caller.
    prepareTx(buf: TL.BufFrame): void
    // Transmit the prepared packet on this channel; consumes the prepared slot.
    startTx(chan: u8): void
    waitReady(): void

}
