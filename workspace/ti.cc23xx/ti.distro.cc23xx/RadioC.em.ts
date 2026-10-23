import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as PacketCrypto from '@em.link/PacketCryptoN.em'
import * as RadioDriver from '@ti.radio.cc23xx/RadioDriver.em'

// Basic unencrypted BLE bring-up. Packet encryption is explicitly unsupported.
export { PacketCrypto, RadioDriver }
