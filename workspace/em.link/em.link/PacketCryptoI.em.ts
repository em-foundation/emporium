import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as TL from '@em.link/Types.em'

export interface $I {
    completeRx(): TL.BufPtr  // plaintext buffer; $null if MIC verification fails
    completeTx(): void

    // Begin/end packet protection for one radio connection.
    // key: 16 bytes; iv: 8 bytes; tx_direction: BLE direction bit (0 or 1).
    configure(key: ptr_t<u8>, iv: ptr_t<u8>, tx_direction: u8): void
    disable(): void

    // Packet counter: low 32 bits plus 7 significant bits in high byte.
    // These hooks may arm hardware for on-the-fly processing or perform
    // synchronous software processing, depending on the supplier.
    prepareRx(buf: TL.BufPtr, ctr_lo: u32, ctr_hi: u8): void
    prepareTx(buf: TL.BufPtr, ctr_lo: u32, ctr_hi: u8): TL.BufPtr  // radio TX buffer
}
