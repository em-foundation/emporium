import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as TB from '@em.link.ble/Types.em'

export interface $I {
    accept(req: $$<TB.LnkHdr>): bool_t
    deriveSessionKey(skd: ptr_t<u8>): ptr_t<u8>
    publicKeyTxActive(): bool_t
    reset(): void
    setAddresses(central: ptr_t<u8>, peripheral: ptr_t<u8>): void
    txAcked(): void
    txChosen(): void
    unexpected(req: $$<TB.LnkHdr>): void
}
