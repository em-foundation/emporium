import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as CmacN from '@em.crypto.cmac/CmacN.em'
import * as Crypto from '@em.crypto/Crypto.em'
import * as MathOpsArmM0 from '@em.crypto.p256/MathOpsArmM0.em'
import * as P256Engine from '@em.crypto.p256/Engine.em'

// The shared SMP module generates its local public key at startup even for
// basic GATT. Reuse the validated M0 provider; CMAC/security are not enabled yet.
export function em$configure() {
    Crypto.Cmac.$$dlg = CmacN
    Crypto.P256.$$dlg = P256Engine
    P256Engine.MathOps.$$dlg = MathOpsArmM0
}
