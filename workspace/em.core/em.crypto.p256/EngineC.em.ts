import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Engine from '@em.crypto.p256/Engine.em'
import * as MathOpsArmM4 from '@em.crypto.p256/MathOpsArmM4.em'
import * as MathOpsPortable from '@em.crypto.p256/MathOpsPortable.em'

export { Engine }

export function em$configure() {
    // Engine.Field.$$dlg = FieldPortable
    Engine.MathOps.$$dlg = MathOpsArmM4
}
