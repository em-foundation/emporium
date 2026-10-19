import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as PacketCrypto from '@em.link/PacketCryptoN.em'
import * as RadioDriver from '@nordic.radio.nrf54/RadioDriver.em'

// Unencrypted radio bring-up. PacketCryptoN fails if encryption is requested.
export { PacketCrypto, RadioDriver }
