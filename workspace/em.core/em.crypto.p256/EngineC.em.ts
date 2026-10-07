import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Engine from '@em.crypto.p256/Engine.em'
import * as FieldArmM4 from '@em.crypto.p256/FieldArmM4.em'
import * as FieldPortable from '@em.crypto.p256/FieldPortable.em'

export { Engine }

export function em$configure() {
    // Engine.Field.$$dlg = FieldPortable
    Engine.Field.$$dlg = FieldArmM4
}
