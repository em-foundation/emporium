import '@$$emscript'
export const $U = $declare('MODULE', CmacProviderI)

import * as CmacProviderI from '@em.crypto.cmac/CmacProviderI.em'

// Explicit unsupported supplier, analogous to em.hal/Aes128N.
// Allows a P-256-only target to bind the complete Crypto backplane.
export function compute(key: CmacProviderI.Key_Ref, msg: frame_t<u8>, mac_OUT: CmacProviderI.Mac_Ref): void {
    fail()
}