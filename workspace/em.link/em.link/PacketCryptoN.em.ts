import '@$$emscript'
export const $U = $declare('MODULE', PacketCryptoI)

import * as PacketCryptoI from '@em.link/PacketCryptoI.em'
import * as TL from '@em.link/Types.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function configure(key: ptr_t<u8>, iv: ptr_t<u8>, tx_direction: u8) {
    fail()   // Encryption was requested without a PacketCrypto provider.
}

export function disable() {
    // Safe when an unencrypted connection is shut down.
}

export function prepareRx(buf: TL.BufPtr, ctr_lo: u32, ctr_hi: u8) {
    fail()
}

export function completeRx(): TL.BufPtr {
    fail()
    return $null
}

export function prepareTx(buf: TL.BufPtr, ctr_lo: u32, ctr_hi: u8): TL.BufPtr {
    fail()
    return $null
}

export function completeTx() {
    fail()
}
