import '@$$emscript'
export const $U = $declare('MODULE')

import * as Ccm from '@nordic.mcu.nrf52/Ccm.em'
import * as Mem from '@em.utils/Mem.em'

// Independent reference: AES-128-CCM, 4-byte tag; nonce = packet counter
// LE (5 octets, direction in bit 7 of octet 4) || IV LE (8 octets),
// one AAD octet = S0 & 0xe3. Computed using Python cryptography AESCCM.
const EXPECTED = $table<u8>([
    0x02, 0x14, 0x00,
    0xa2, 0x67, 0xa0, 0xf1, 0xd8, 0xa5, 0x0c, 0x8c,
    0xc2, 0xc3, 0xa2, 0x2c, 0x91, 0xbd, 0xdd, 0xfd,
    0x44, 0xea, 0x3a, 0x48
])

class Key extends $vector<u8> { $len = 16 }
class Iv extends $vector<u8> { $len = 8 }
class Packet extends $vector<u8> { $len = 34 } // 3 + 27 + MIC(4)

export function em$run() {
    printf`CCM TEST START\n`()
    let key = Key.$make()
    let iv = Iv.$make()
    let plain = Packet.$make()
    let cipher = Packet.$make()
    let restored = Packet.$make()
    let bad = Packet.$make()

    for (const i of $range(16)) key[i] = i
    for (const i of $range(8)) iv[i] = 0xa0 + i
    plain[0] = 0x02 // LLID = start; authenticated S0 octet
    plain[1] = 16
    plain[2] = 0 // S1 RAM-only byte
    for (const i of $range(16)) plain[3 + i] = 0x10 + i

    // Packet counter 1, direction 1; nonce = 01 00 00 00 80 a0 ... a7.
    printf`CCM configure\n`()
    Ccm.configure(key.$ptr(), iv.$ptr(), 1, 0, 1)
    printf`CCM encrypt test\n`()
    Ccm.encrypt(plain.$ptr(), cipher.$ptr())
    if (Mem.cmp(cipher.$ptr(), EXPECTED.$ptr(), EXPECTED.$len) != 0) {
        Mem.prB(t$`actual`, cipher.$ptr(), EXPECTED.$len)
        Mem.prB(t$`expected`, EXPECTED.$ptr(), EXPECTED.$len)
        printf`CCM encrypt FAIL\n`()
        fail()
    }
    printf`CCM encrypt PASS\n`()

    printf`CCM decrypt test\n`()
    if (!Ccm.decrypt(cipher.$ptr(), restored.$ptr())) {
        printf`CCM decrypt MIC FAIL\n`()
        fail()
    }
    if (Mem.cmp(plain.$ptr(), restored.$ptr(), 19) != 0) {
        printf`CCM decrypt plaintext FAIL\n`()
        fail()
    }
    printf`CCM decrypt PASS\n`()

    Mem.cpy(bad.$ptr(), cipher.$ptr(), EXPECTED.$len)
    bad[EXPECTED.$len - 1] ^= 1 // corrupt MIC, preserve ciphertext
    printf`CCM bad MIC test\n`()
    if (Ccm.decrypt(bad.$ptr(), restored.$ptr())) {
        printf`CCM bad MIC unexpectedly accepted\n`()
        fail()
    }
    printf`CCM bad MIC rejected PASS\n`()
}
