import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Aes128Ecb from '@ti.mcu.cc23xx/Aes128Ecb.em'
import * as CmacEngine from '@em.crypto.cmac/Engine.em'
import * as Crypto from '@em.crypto/Crypto.em'
import * as MathOpsArmM0 from '@em.crypto.p256/MathOpsArmM0.em'
import * as P256Engine from '@em.crypto.p256/Engine.em'

// Shared CMAC uses hardware AES; P256 uses the validated M0 math provider.
export function em$configure() {
    CmacEngine.Aes.$$dlg = Aes128Ecb
    Crypto.Cmac.$$dlg = CmacEngine
    Crypto.P256.$$dlg = P256Engine
    P256Engine.MathOps.$$dlg = MathOpsArmM0
}
