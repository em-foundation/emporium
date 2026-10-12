import '@$$emscript'
export const $U = $declare('MODULE')

import * as CmacProviderI from '@em.crypto.cmac/CmacProviderI.em'
import * as P256ProviderI from '@em.crypto.p256/P256ProviderI.em'

export const Cmac = $proxy<CmacProviderI.$I>()
export const P256 = $proxy<P256ProviderI.$I>()

export namespace em$meta { }

//>> ---- em$targ ---- <<//
