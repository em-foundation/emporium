import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Controller from '@em.link.ble/Controller.em'
import * as Smp from '@em.link.ble/Smp.em'
import * as PacketCrypto from '@em.link/PacketCryptoN.em'
import * as RadioDriver from '@ti.radio.cc23xx/RadioDriver.em'

// Basic unencrypted BLE bring-up. Packet encryption is explicitly unsupported.
export { PacketCrypto, RadioDriver }

// TI bring-up: avoid extra work in the RX-to-TX turnaround path.
export function em$configure() {
    // TEMP: wake 2.5 ms early to test whether reception is starting late.
    Controller.hfclk_guard_us.$$val = 800
    Controller.public_key_chaining.$$val = false
    Smp.ecdh_busywait_test.$$val = false // run real ECDH with the TI crypto provider
}
