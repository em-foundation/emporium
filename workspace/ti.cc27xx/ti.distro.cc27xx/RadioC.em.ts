import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Controller from '@em.link.ble/Controller.em'
import * as PacketCrypto from '@em.link/PacketCryptoN.em'
import * as RadioDriver from '@ti.radio.cc27xx/RadioDriver.em'

export { PacketCrypto, RadioDriver }

export function em$configure() {
    Controller.hfclk_guard_us.$$val = 800
    Controller.public_key_chaining.$$val = false
}
