import '@$$emscript'
export const $U = $declare('MODULE', PacketCryptoI)

import * as Aes from '@ti.mcu.cc23xx/Aes128Ecb.em'
import * as Mem from '@em.utils/Mem.em'
import * as PacketCryptoI from '@em.link/PacketCryptoI.em'
import * as TL from '@em.link/Types.em'

// BLE CCM: 13-byte nonce, one masked header byte of AAD, 4-byte MIC, L=2.
// AES block operations use the TI hardware provider; packet processing is synchronous.
const MAX_PLAIN = 27
const MIC_LEN = 4
// Native words contain the same byte order previously produced by Mem.scan32.
class Key extends $vector<u32> { $len = 4 }
class Iv extends $vector<u8> { $len = 8 }
class BlockWords extends $vector<u32> { $len = 4 }
class Packet extends $vector<u8> { $len = 34 }
export namespace em$meta { }

//>> ---- em$targ ---- <<//
var session_key: Key
var session_iv: Iv
var configured: bool_t
var tx_direction: u8
var rx_buf: TL.BufPtr = $null
var rx_lo: u32
var rx_hi: u8
var rx_plain: Packet
var tx_cipher: Packet
export function configure(key: ptr_t<u8>, iv: ptr_t<u8>, direction: u8) {
    disable()
    // Convert an externally supplied, possibly unaligned byte key once per session.
    session_key[0] = Mem.scan32($$(key[0]))
    session_key[1] = Mem.scan32($$(key[4]))
    session_key[2] = Mem.scan32($$(key[8]))
    session_key[3] = Mem.scan32($$(key[12]))
    Mem.cpy(session_iv.$ptr(), iv, 8)
    tx_direction = direction & 1
    configured = true
}

export function disable() {
    configured = false
    rx_buf = $null
    session_key[0] = 0
    session_key[1] = 0
    session_key[2] = 0
    session_key[3] = 0
    Mem.set(session_iv.$ptr(), 0, 8)
    Mem.set(rx_plain.$ptr(), 0, 34)
    Mem.set(tx_cipher.$ptr(), 0, 34)
}

function requireConfigured() {
    if (!configured) {
        printf`TI CCM unconfigured FAIL\n`()
        fail()
    }
}

export function prepareRx(buf: TL.BufPtr, lo: u32, hi: u8) {
    requireConfigured()
    rx_buf = buf
    rx_lo = lo
    rx_hi = hi
}

export function completeRx(): TL.BufPtr {
    requireConfigured()
    if (rx_buf == $null) {
        fail()
        return $null
    }
    const len = rx_buf[1]
    if (len == 0) return rx_buf
    if (len <= MIC_LEN || len > MAX_PLAIN + MIC_LEN) return $null
    $['%%a+'] // DbgA: CCM decryption and MIC verification
    const valid = crypt(true, rx_buf, rx_plain.$ptr(), rx_lo, rx_hi, tx_direction ^ 1)
    $['%%a-']
    if (!valid) return $null
    return rx_plain.$ptr()
}

export function prepareTx(buf: TL.BufPtr, lo: u32, hi: u8): TL.BufPtr {
    requireConfigured()
    if (buf[1] > MAX_PLAIN) {
        printf`TI CCM TX length FAIL len=%d\n`(buf[1])
        fail()
        return $null
    }
    if (buf[1] == 0) return buf
    $['%%a+'] // DbgA: CCM encryption and MIC generation
    crypt(false, buf, tx_cipher.$ptr(), lo, hi, tx_direction)
    $['%%a-']
    return tx_cipher.$ptr()
}

export function completeTx() {
    // Encryption is complete before the packet is copied to the radio FIFO.
}

function nonce(block: ptr_t<u8>, lo: u32, hi: u8, direction: u8) {
    Mem.pack32($$(block[1]), lo)
    block[5] = (hi & 0x7f) | (direction << 7)
    Mem.cpy($$(block[6]), session_iv.$ptr(), 8)
}

function crypt(dec: bool_t, src: TL.BufPtr, dst: TL.BufPtr, lo: u32, hi: u8, direction: u8): bool_t {
    const len: u8 = dec ? src[1] - MIC_LEN : src[1]
    let ctr_words = BlockWords.$make()
    const ctr = <ptr_t<u8>>ctr_words.$ptr()
    let mac_words = BlockWords.$make()
    const mac = <ptr_t<u8>>mac_words.$ptr()
    let tag_words = BlockWords.$make()
    const tag = <ptr_t<u8>>tag_words.$ptr()
    let block_words = BlockWords.$make()
    const block = <ptr_t<u8>>block_words.$ptr()
    Mem.set(ctr, 0, 16)
    ctr[0] = 1 // L-1
    nonce(ctr, lo, hi, direction)
    dst[0] = src[0]
    dst[1] = dec ? len : len + MIC_LEN
    dst[2] = 0
    Aes.beginSessionWords(session_key.$ptr())
    // CTR decrypts to private scratch before authenticating; never expose it on failure.
    let offset: u8 = 0
    let counter: u8 = 1
    while (offset < len) {
        ctr[15] = counter
        const count: u8 = len - offset > 16 ? 16 : len - offset
        Aes.counterBlockWords(ctr_words.$ptr(), <ptr_t<u8>>$$(src[3 + offset]), <ptr_t<u8>>$$(dst[3 + offset]), count)
        offset += count
        counter += 1
    }
    // B0: associated-data flag, MIC=4, L=2; payload length is big-endian.
    Mem.cpy(block, ctr, 16)
    block[0] = 0x49
    block[14] = 0
    block[15] = len
    Aes.encryptBlockWordsKeep(block_words.$ptr())
    Mem.set(block, 0, 16)
    block[1] = 1 // encoded AAD length
    block[2] = src[0] & 0xe3 // mask NESN, SN, MD
    Aes.macBlockWordsKeep(block_words.$ptr())
    offset = 0
    while (offset < len) {
        Mem.set(block, 0, 16)
        const count: u8 = len - offset > 16 ? 16 : len - offset
        for (const i of $range(count)) block[i] = dec ? dst[3 + offset + i] : src[3 + offset + i]
        Aes.macBlockWordsKeep(block_words.$ptr())
        offset += count
    }
    // Only the final authentication state is needed outside AES.
    Aes.readBlockWords(mac_words.$ptr())
    ctr[15] = 0
    Aes.encryptBlockWords(ctr_words.$ptr(), tag_words.$ptr())
    Aes.endSession()
    let diff: u8 = 0
    for (const i of $range(MIC_LEN)) {
        const value: u8 = mac[i] ^ tag[i]
        if (dec) diff |= value ^ src[3 + len + i]
        else dst[3 + len + i] = value
    }
    Mem.set(ctr, 0, 16)
    Mem.set(mac, 0, 16)
    Mem.set(tag, 0, 16)
    Mem.set(block, 0, 16)
    if (dec && diff != 0) {
        Mem.set(dst, 0, 34)
        return false
    }
    return true
}