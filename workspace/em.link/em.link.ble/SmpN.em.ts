import '@$$emscript'
export const $U = $declare('MODULE', SmpI)

import * as SmpI from '@em.link.ble/SmpI.em'
import * as TB from '@em.link.ble/Types.em'

export namespace em$meta { }

// The controller handles Pairing Not Supported without a pairing engine.
export function accept(req: $$<TB.LnkHdr>): bool_t { return false }
export function deriveSessionKey(skd: ptr_t<u8>): ptr_t<u8> { return $null }
export function publicKeyTxActive(): bool_t { return false }
export function reset() { }
export function setAddresses(central: ptr_t<u8>, peripheral: ptr_t<u8>) { }
export function txAcked() { }
export function txChosen() { }
export function unexpected(req: $$<TB.LnkHdr>) { }
