import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Crypto from '@em.crypto/Crypto.em'
import * as Engine from '@em.crypto.p256/Engine.em'
import * as MathOpsArmM4 from '@em.crypto.p256/MathOpsArmM4.em'

export function em$configure() {
    Engine.MathOps.$$dlg = MathOpsArmM4
    Crypto.P256.$$dlg = Engine
}
