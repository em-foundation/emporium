import '@$$emscript'
export const $U = $declare('MODULE')

import * as Ccm from '@ti.radio.cc23xx/PacketCrypto.em'
import * as Mem from '@em.utils/Mem.em'

// Independent OpenSSL AES-128-CCM reference, 13-byte nonce and 4-byte MIC.
const EXPECT_16 = $table<u8>([
    0xa2, 0x67, 0xa0, 0xf1, 0xd8, 0xa5, 0x0c, 0x8c,
    0xc2, 0xc3, 0xa2, 0x2c, 0x91, 0xbd, 0xdd, 0xfd,
    0x44, 0xea, 0x3a, 0x48
])
const EXPECT_27 = $table<u8>([
    0x5d, 0x04, 0x58, 0x77, 0xdb, 0x5b, 0x7f, 0x36,
    0x56, 0xed, 0x9f, 0x9b, 0x4d, 0x0d, 0xda, 0x62,
    0x30, 0x0c, 0xef, 0x05, 0xe4, 0x69, 0x61, 0x6d,
    0x21, 0xc1, 0xf3, 0xce, 0xb6, 0xcf, 0x4d
])
// One-byte control payload at counters zero and one; no handshake special case.
const EXPECT_START = $table<u8>([0xdc, 0x11, 0x32, 0x15, 0xd4])
const EXPECT_START_NEXT = $table<u8>([0xc5, 0xbb, 0xc1, 0x1a, 0x2a])
class Key extends $vector<u8> { $len = 16 }
class Iv extends $vector<u8> { $len = 8 }
class Packet extends $vector<u8> { $len = 34 }

export function em$run() {
    test(16, 0x10, 1, 0, 1, EXPECT_16.$frame(0), 2)
    test(27, 0, 0x89abcdef, 0x12, 0, EXPECT_27.$frame(0), 2)
    test(1, 6, 0, 0, 0, EXPECT_START.$frame(0), 3)
    test(1, 6, 1, 0, 0, EXPECT_START_NEXT.$frame(0), 3)
    Ccm.disable()
    printf`CCM: PASS\n`()
}

function test(len: u8, start: u8, lo: u32, hi: u8, direction: u8, expected: frame_t<u8>, header: u8) {
    let key = Key.$make()
    let iv = Iv.$make()
    let plain = Packet.$make()
    let cipher = Packet.$make()
    for (const i of $range(16)) key[i] = i
    for (const i of $range(8)) iv[i] = 0xa0 + i
    plain[0] = header
    plain[1] = len
    plain[2] = 0
    for (const i of $range(len)) plain[3 + i] = start + i
    Ccm.configure(key.$ptr(), iv.$ptr(), direction)
    const encrypted = Ccm.prepareTx(plain.$ptr(), lo, hi)
    Ccm.completeTx()
    if (encrypted[0] != header || encrypted[1] != len + 4 || encrypted[2] != 0
        || Mem.cmp($$(encrypted[3]), $$(expected[0]), expected.$len) != 0) {
        Mem.prB(t$`actual`, encrypted, len + 7)
        printf`CCM-%d encrypt FAIL\n`(len)
        fail()
    }
    Mem.cpy(cipher.$ptr(), encrypted, len + 7)
    printf`CCM-%d encrypt PASS\n`(len)
    plain[0] ^= 0x1c // NESN, SN and MD do not change authenticated data.
    const masked = Ccm.prepareTx(plain.$ptr(), lo, hi)
    if (Mem.cmp($$(masked[3]), $$(expected[0]), expected.$len) != 0) fail()
    plain[0] = header
    Ccm.configure(key.$ptr(), iv.$ptr(), direction ^ 1)
    Ccm.prepareRx(cipher.$ptr(), lo, hi)
    const restored = Ccm.completeRx()
    if (restored == $null || Mem.cmp(restored, plain.$ptr(), len + 3) != 0) {
        printf`CCM-%d decrypt FAIL\n`(len)
        fail()
    }
    printf`CCM-%d decrypt PASS\n`(len)
    cipher[len + 6] ^= 1
    Ccm.prepareRx(cipher.$ptr(), lo, hi)
    if (Ccm.completeRx() != $null) {
        printf`CCM bad MIC accepted FAIL\n`()
        fail()
    }
    printf`CCM-%d bad MIC rejected PASS\n`(len)
    cipher[1] = 0
    Ccm.prepareRx(cipher.$ptr(), lo, hi)
    if (Ccm.completeRx() == $null) fail()
    plain[1] = 0
    const empty = Ccm.prepareTx(plain.$ptr(), lo, hi)
    if (empty[1] != 0) fail()
    printf`CCM-%d header mask and empty PDU PASS\n`(len)
}
