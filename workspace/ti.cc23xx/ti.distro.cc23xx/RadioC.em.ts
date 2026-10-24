import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Controller from '@em.link.ble/Controller.em'
import * as Smp from '@em.link.ble/Smp.em'
import * as PacketCrypto from '@ti.radio.cc23xx/PacketCrypto.em'
import * as RadioDriver from '@ti.radio.cc23xx/RadioDriver.em'

// BLE packet protection uses hardware AES with complete-packet CCM.
export { PacketCrypto, RadioDriver }

// TI connection scheduling and secure pairing configuration.
export function em$configure() {
    // Allow 800 us for crystal and radio startup before the next anchor.
    Controller.hfclk_guard_us.$$val = 800
    Controller.public_key_chaining.$$val = false
    Smp.ecdh_busywait_test.$$val = false // run real ECDH with the TI crypto provider
}
