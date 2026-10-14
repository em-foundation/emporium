import '@$$emscript'
export const $U = $declare('MODULE')

import * as PacketCryptoI from '@em.link/PacketCryptoI.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'

export const PacketCrypto = $proxy<PacketCryptoI.$I>()
export const RadioDriver = $proxy<RadioDriverI.$I>()
