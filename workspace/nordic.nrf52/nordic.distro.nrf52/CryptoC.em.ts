import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Aes128Ecb from '@nordic.mcu.nrf52/Aes128Ecb.em'
import * as CmacEngine from '@em.crypto.cmac/Engine.em'
import * as Crypto from '@em.crypto/Crypto.em'
import * as MathOpsArmM4 from '@em.crypto.p256/MathOpsArmM4.em'
import * as P256Engine from '@em.crypto.p256/Engine.em'

export function em$configure() {
    CmacEngine.Aes.$$dlg = Aes128Ecb
    Crypto.Cmac.$$dlg = CmacEngine
    Crypto.P256.$$dlg = P256Engine
    P256Engine.MathOps.$$dlg = MathOpsArmM4
}
