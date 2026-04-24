import '@$$emscript'
export const $U = $declare('INTERFACE')

export type Handler = cb_t<[]>

export interface em$meta {
    bindHandler(h: Handler): void
}

export interface $I {
    em$meta: em$meta
    disable(): void
    enable(): void
    startTx(tx_buf: frame_t<u8>, chan: u8): void
}