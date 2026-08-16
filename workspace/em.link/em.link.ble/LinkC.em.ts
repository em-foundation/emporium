import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Adapter from '@em.link.ble/Adapter.em'
import * as BoardC from '@$distro/BoardC.em'
import * as Registry from '@em.link/Registry.em'
import * as TL from '@em.link/Types.em'

export function em$configure() {
    Adapter.Led.$$dlg = $delegate(BoardC.AppLed)
    Adapter.OneShot.$$dlg = $delegate(BoardC.OneShot)
    Adapter.RadioDriver.$$dlg = $delegate(BoardC.RadioDriver)
}

export { Adapter }

export function em$construct() {
    //
    let sh = TL.SchemaHash.$make()
    for (const i of $range(sh.$len)) {
        sh[i] = 0x20 + i
    }
    Registry.em$meta.bindSchemaHash(sh)
    //
    let nid = TL.NodeId.$make()
    nid.schemaNumber = 0x1122
    Registry.em$meta.bindNodeId(nid)
}