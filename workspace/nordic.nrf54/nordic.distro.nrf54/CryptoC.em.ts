import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Aes128Ecb from '@nordic.mcu.nrf54/Aes128Ecb.em'
import * as CmacEngine from '@em.crypto.cmac/Engine.em'
import * as Common from '@em.mcu/Common.em'
import * as Crypto from '@em.crypto/Crypto.em'
import * as P256Cracen from '@nordic.mcu.nrf54/P256Cracen.em'

export function em$configure() {
    Common.Aes128.$$dlg = Aes128Ecb
    CmacEngine.Aes.$$dlg = Aes128Ecb
    Crypto.Cmac.$$dlg = CmacEngine
    Crypto.P256.$$dlg = P256Cracen
}
