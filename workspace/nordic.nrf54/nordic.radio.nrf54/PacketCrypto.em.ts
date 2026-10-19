import '@$$emscript'
export const $U = $declare('MODULE', PacketCryptoI)

import * as $R from '@nordic.distro.nrf54/REGS.em'
import * as Mem from '@em.utils/Mem.em'
import * as PacketCryptoI from '@em.link/PacketCryptoI.em'
import * as TL from '@em.link/Types.em'

// nRF54L CCM00: complete-packet polling, with BLE RAM layout S0 | LEN | S1 | data.
// Key/nonce ordering and DMA attributes follow Nordic's NCS v3.0.2 radio.c.
const MAX_PLAIN = 27
const MIC_LEN = 4
const POLL_LIMIT = 100000

class Key extends $vector<u8> { $len = 16 }
class Iv extends $vector<u8> { $len = 8 }
class Packet extends $vector<u8> { $len = 34 }
class Jobs extends $vector<u32> { $len = 10 }

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var session_key: Key
var session_iv: Iv
var configured: bool_t = false
var tx_direction: u8
var rx_buf: TL.BufPtr = $null
var rx_lo: u32
var rx_hi: u8
var rx_plain: Packet
var tx_cipher: Packet

export function configure(key: ptr_t<u8>, iv: ptr_t<u8>, direction: u8) {
    disable()
    Mem.cpy(session_key.$ptr(), key, 16)
    Mem.cpy(session_iv.$ptr(), iv, 8)
    tx_direction = direction & 1
    configured = true
}

export function disable() {
    $R.CCM00.INTENCLR.$$ = $R.CCM_INTENCLR_END_Msk | $R.CCM_INTENCLR_ERROR_Msk
    $R.CCM00.TASKS_STOP.$$ = 1
    $R.CCM00.ENABLE.$$ = 0
    $R.CCM00.IN.PTR.$$ = 0
    $R.CCM00.OUT.PTR.$$ = 0
    for (const i of $range(4)) {
        $R.CCM00.KEY.VALUE[i].$$ = 0
        $R.CCM00.NONCE.VALUE[i].$$ = 0
    }
    Mem.set(session_key.$ptr(), 0, 16)
    Mem.set(session_iv.$ptr(), 0, 8)
    configured = false
    rx_buf = $null
}

export function prepareRx(buf: TL.BufPtr, ctr_lo: u32, ctr_hi: u8) {
    requireConfigured()
    rx_buf = buf
    rx_lo = ctr_lo
    rx_hi = ctr_hi
}

export function completeRx(): TL.BufPtr {
    requireConfigured()
    if (rx_buf == $null) {
        fail()
        return $null
    }
    const len = rx_buf[1]
    if (len == 0) return rx_buf // BLE empty PDUs carry no MIC or packet counter.
    if (len <= MIC_LEN || len > MAX_PLAIN + MIC_LEN) return $null
    if (!crypt(true, rx_buf, rx_plain.$ptr(), rx_lo, rx_hi, tx_direction ^ 1)) return $null
    return rx_plain.$ptr()
}

export function prepareTx(buf: TL.BufPtr, ctr_lo: u32, ctr_hi: u8): TL.BufPtr {
    requireConfigured()
    if (buf[1] > MAX_PLAIN) {
        printf`NRF54 CCM TX length FAIL len=%d\n`(buf[1])
        fail()
        return $null
    }
    if (buf[1] == 0) return buf
    crypt(false, buf, tx_cipher.$ptr(), ctr_lo, ctr_hi, tx_direction)
    return tx_cipher.$ptr()
}

export function completeTx() {
    // prepareTx completes encryption synchronously, before RADIO.TXEN.
}

function requireConfigured() {
    if (!configured) {
        printf`NRF54 CCM unconfigured FAIL\n`()
        fail()
    }
}

function be32(p: ptr_t<u8>): u32 {
    return (<u32>p[0] << 24) | (<u32>p[1] << 16) | (<u32>p[2] << 8) | <u32>p[3]
}

function job(list: ptr_t<u32>, slot: u8, ptr: arg_t, len: u16, attr: u8) {
    list[slot * 2] = $cast2<u32>(ptr)
    list[slot * 2 + 1] = (<u32>attr << 24) | len
}

function crypt(dec: bool_t, src: TL.BufPtr, dst: TL.BufPtr, lo: u32, hi: u8, direction: u8): bool_t {
    let input = Jobs.$make()
    let output = Jobs.$make()
    let in_alen: u16 = 1
    let in_mlen: u16 = src[1]
    let out_alen: u16 = 0
    let out_mlen: u16 = 0
    const expected_len: u16 = dec ? in_mlen - MIC_LEN : in_mlen + MIC_LEN
    job(input.$ptr(), 0, $$(in_alen), 2, 11)
    job(input.$ptr(), 1, $$(in_mlen), 2, 12)
    job(input.$ptr(), 2, src, 1, 13)
    job(input.$ptr(), 3, $$(src[3]), in_mlen, 14)
    input[8] = 0
    input[9] = 0
    job(output.$ptr(), 0, $$(out_alen), 2, 11)
    job(output.$ptr(), 1, $$(out_mlen), 2, 12)
    job(output.$ptr(), 2, dst, 1, 13)
    job(output.$ptr(), 3, $$(dst[3]), expected_len, 14)
    output[8] = 0
    output[9] = 0

    $R.CCM00.ENABLE.$$ = 0
    $R.CCM00.ENABLE.$$ = $R.CCM_ENABLE_ENABLE_Enabled
    $R.CCM00.INTENCLR.$$ = $R.CCM_INTENCLR_END_Msk | $R.CCM_INTENCLR_ERROR_Msk
    $R.CCM00.MODE.$$ = ((dec ? $R.CCM_MODE_MODE_FastDecryption : $R.CCM_MODE_MODE_Encryption) << $R.CCM_MODE_MODE_Pos)
        | ($R.CCM_MODE_PROTOCOL_Ble << $R.CCM_MODE_PROTOCOL_Pos)
        | ($R.CCM_MODE_MACLEN_M4 << $R.CCM_MODE_MACLEN_Pos)
        | ($R.CCM_MODE_DATARATE_1Mbit << $R.CCM_MODE_DATARATE_Pos)
    $R.CCM00.ADATAMASK.$$ = 0xe3
    for (const i of $range(4)) $R.CCM00.KEY.VALUE[3 - i].$$ = be32(<TL.BufPtr>$$(session_key[i * 4]))
    $R.CCM00.NONCE.VALUE[3].$$ = lo & 0xff
    $R.CCM00.NONCE.VALUE[2].$$ = ((lo >> 8) & 0xff) << 24 | ((lo >> 16) & 0xff) << 16
        | (lo >> 24) << 8 | (hi & 0x7f) | (<u32>direction << 7)
    $R.CCM00.NONCE.VALUE[1].$$ = be32(<TL.BufPtr>$$(session_iv[0]))
    $R.CCM00.NONCE.VALUE[0].$$ = be32(<TL.BufPtr>$$(session_iv[4]))
    $R.CCM00.IN.PTR.$$ = $cast2<u32>(input.$ptr())
    $R.CCM00.OUT.PTR.$$ = $cast2<u32>(output.$ptr())
    $R.CCM00.EVENTS_END.$$ = 0
    $R.CCM00.EVENTS_ERROR.$$ = 0
    e$`__DMB()`
    $R.CCM00.TASKS_START.$$ = 1
    let polls: u32 = 0
    while ($R.CCM00.EVENTS_END.$$ == 0 && $R.CCM00.EVENTS_ERROR.$$ == 0 && polls < POLL_LIMIT) polls += 1
    const complete = $R.CCM00.EVENTS_END.$$ != 0 && $R.CCM00.EVENTS_ERROR.$$ == 0
    const error = $R.CCM00.ERRORSTATUS.$$
    const valid = !dec || $R.CCM00.MACSTATUS.$$ == $R.CCM_MACSTATUS_MACSTATUS_CheckPassed
    e$`__DMB()`
    $R.CCM00.TASKS_STOP.$$ = 1
    $R.CCM00.ENABLE.$$ = 0
    $R.CCM00.IN.PTR.$$ = 0
    $R.CCM00.OUT.PTR.$$ = 0
    for (const i of $range(4)) {
        $R.CCM00.KEY.VALUE[i].$$ = 0
        $R.CCM00.NONCE.VALUE[i].$$ = 0
    }
    if (!complete) {
        printf`NRF54 CCM FAIL error=%08x polls=%d\n`(error, polls)
        fail()
        return false
    }
    if (!valid) return false
    if (out_alen != 1 || out_mlen != expected_len) {
        printf`NRF54 CCM output length FAIL aad=%d len=%d expected=%d\n`(out_alen, out_mlen, expected_len)
        fail()
        return false
    }
    dst[0] = src[0]
    dst[1] = <u8>out_mlen
    dst[2] = 0
    return true
}
