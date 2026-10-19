import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Crypto from '@em.crypto/Crypto.em'
import * as CmacN from '@em.crypto.cmac/CmacN.em'
import * as P256Cracen from '@nordic.mcu.nrf54/P256Cracen.em'

// First checkpoint: standalone P-256. AES/CMAC and packet crypto follow.
export function em$configure() {
    Crypto.Cmac.$$dlg = CmacN // Unsupported until the AES/CMAC checkpoint.
    Crypto.P256.$$dlg = P256Cracen
}