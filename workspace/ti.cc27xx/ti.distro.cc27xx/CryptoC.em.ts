import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as CmacN from '@em.crypto.cmac/CmacN.em'
import * as Crypto from '@em.crypto/Crypto.em'
import * as MathOpsArmM4 from '@em.crypto.p256/MathOpsArmM4.em'

import * as P256Engine from '@em.crypto.p256/Engine.em'

// Smp computes its public key at startup, even for a scan-only bench test.
// Use shared software P256; CMAC and packet protection remain unsupported.
export function em$configure() {
    Crypto.Cmac.$$dlg = CmacN
    Crypto.P256.$$dlg = P256Engine
    P256Engine.MathOps.$$dlg = MathOpsArmM4
}


