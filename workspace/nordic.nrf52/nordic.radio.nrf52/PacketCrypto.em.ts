import '@$$emscript'
export const $U = $declare('MODULE', PacketCryptoI)

import * as $R from '@nordic.distro.nrf52/REGS.em'

import * as Mem from '@em.utils/Mem.em'
import * as PacketCryptoI from '@em.link/PacketCryptoI.em'
import * as TL from '@em.link/Types.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

// nRF52832 BLE CCM, PPI-driven on-the-fly packet encryption/decryption.
// Initial implementation uses the CCM default 5-bit length mode.
// Packet RAM: S0 | LENGTH | S1 | PAYLOAD [| MIC].
// In connection mode, RADIO must use LFLEN=5, S1LEN=3, S1INCL=1.
// This bounds plaintext to 27 bytes and encrypted payload+MIC to 31 bytes.
// RadioDriver must enforce that mode/limit before encrypted traffic begins.
// Not yet wired to RadioDriver or Controller.
// PPI 24: RADIO.READY   -> CCM.KSGEN (both directions)
// PPI 25: RADIO.ADDRESS -> CCM.CRYPT (RX only)

const CONFIG_LEN = 33
const MAX_PLAIN_LEN = 27
const MIC_LEN = 4
const PACKET_LEN = 3 + MAX_PLAIN_LEN + MIC_LEN
const SCRATCH_LEN = 43

// PPI channels and their combined mask.
const PPI_CRYPT = 1 << 25
const PPI_KSGEN = 1 << 24
const PPI_CCM = PPI_CRYPT | PPI_KSGEN

class Config extends $vector<u8> { $len = CONFIG_LEN }
class Packet extends $vector<u8> { $len = PACKET_LEN }
class Scratch extends $vector<u8> { $len = SCRATCH_LEN }

var config: Config
var configured = false
var rx_plain: Packet
var scratch: Scratch
var tx_cipher: Packet
var tx_direction: u8

export function completeRx(): TL.BufPtr {
    if (!configured) fail()
    $R.PPI.CHENCLR.$$ = PPI_CCM
    const err = $R.CCM.EVENTS_ERROR.$$
    const done = $R.CCM.EVENTS_ENDCRYPT.$$
    const mic_ok = $R.CCM.MICSTATUS.$$
    $R.CCM.ENABLE.$$ = 0
    if (err != 0) fail()
    if (done == 0 || mic_ok == 0) return $null
    return rx_plain.$ptr()
}

export function completeTx() {
    if (!configured) fail()
    $R.PPI.CHENCLR.$$ = PPI_CCM
    const err = $R.CCM.EVENTS_ERROR.$$
    const done = $R.CCM.EVENTS_ENDCRYPT.$$
    $R.CCM.ENABLE.$$ = 0
    if (err != 0 || done == 0) fail()
}

export function configure(key: ptr_t<u8>, iv: ptr_t<u8>, direction: u8) {
    $R.PPI.CHENCLR.$$ = PPI_CCM
    $R.CCM.ENABLE.$$ = 0
    Mem.cpy(config.$ptr(), key, 16)
    Mem.cpy($$(config[25]), iv, 8)
    for (const i of $range(21, 24)) config[i] = 0
    tx_direction = direction & 1
    configured = true
}

export function disable() {
    $R.PPI.CHENCLR.$$ = PPI_CCM
    $R.CCM.SHORTS.$$ = 0
    $R.CCM.TASKS_STOP.$$ = 1
    $R.CCM.ENABLE.$$ = 0
    configured = false
}

export function prepareRx(buf: TL.BufPtr, ctr_lo: u32, ctr_hi: u8) {
    if (!configured || buf == $null) fail()
    setNonce(ctr_lo, ctr_hi, tx_direction ^ 1)
    arm(true, buf, rx_plain.$ptr())
    $R.PPI.CHENSET.$$ = PPI_KSGEN | PPI_CRYPT
}

export function prepareTx(buf: TL.BufPtr, ctr_lo: u32, ctr_hi: u8): TL.BufPtr {
    if (!configured || buf == $null) fail()
    if (buf[1] > MAX_PLAIN_LEN) fail()
    setNonce(ctr_lo, ctr_hi, tx_direction)
    arm(false, buf, tx_cipher.$ptr())
    $R.PPI.CHENSET.$$ = PPI_KSGEN
    return tx_cipher.$ptr()
}

// Private helpers.

function arm(decrypt: bool_t, src: ptr_t<u8>, dst: ptr_t<u8>) {
    $R.PPI.CHENCLR.$$ = PPI_CCM
    $R.CCM.ENABLE.$$ = 0
    $R.CCM.SHORTS.$$ = decrypt ? 0 : 1  // ENDKSGEN -> CRYPT, TX only
    $R.CCM.EVENTS_ENDKSGEN.$$ = 0
    $R.CCM.EVENTS_ENDCRYPT.$$ = 0
    $R.CCM.EVENTS_ERROR.$$ = 0
    $R.CCM.MODE.$$ = decrypt ? 1 : 0    // BLE 1M, default 5-bit length
    $R.CCM.CNFPTR.$$ = $cast2<u32>(config.$ptr())
    $R.CCM.INPTR.$$ = $cast2<u32>(src)
    $R.CCM.OUTPTR.$$ = $cast2<u32>(dst)
    $R.CCM.SCRATCHPTR.$$ = $cast2<u32>(scratch.$ptr())
    $R.CCM.ENABLE.$$ = 2
}

function setNonce(ctr_lo: u32, ctr_hi: u8, direction: u8) {
    for (const i of $range(4)) config[16 + i] = <u8>(ctr_lo >> (i * 8))
    config[20] = ctr_hi & 0x7f
    config[24] = direction & 1
}

