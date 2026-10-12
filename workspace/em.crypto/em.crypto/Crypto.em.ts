import '@$$emscript'
export const $U = $declare('MODULE')

import * as EngineC from '@em.crypto.p256/EngineC.em'
import * as P256I from '@em.crypto.p256/P256ProviderI.em'

const Engine = $delegate(EngineC.Engine)

export const P256 = $proxy<P256I.$I>()

export namespace em$meta {
    export function em$configure() {
        if (P256.$U === null) P256.$$dlg = Engine
    }
}
