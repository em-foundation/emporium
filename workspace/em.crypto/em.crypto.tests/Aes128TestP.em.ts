import '@$$emscript'
export const $U = $declare('MODULE')

import * as Aes128I from '@em.hal/Aes128I.em'
import * as Common from '@em.mcu/Common.em'
import * as Mem from '@em.utils/Mem.em'

const EXPECT = $config<Aes128I.Block>()
const KEY = $config<Aes128I.Key>()
const SRC = $config<Aes128I.Block>()

export namespace em$meta {
    export function em$construct() {
        initHex(EXPECT.$$val, '69c4e0d8_6a7b0430_d8cdb780_70b4c55a')
        initHex(KEY.$$val, '00010203_04050607_08090a0b_0c0d0e0f')
        initHex(SRC.$$val, '00112233_44556677_8899aabb_ccddeeff')
    }

    function initHex(dst: index_t<u8>, text: string) {
        const hex = text.replace(/[^0-9a-fA-F]/g, '')
        for (const i of $range(hex.length / 2)) {
            dst[i] = Number.parseInt(hex.substring(i * 2, i * 2 + 2), 16)
        }
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    let dst = Aes128I.Block.$make()
    Common.Aes128.encrypt(KEY.$ptr(), SRC.$ptr(), dst.$ptr())
    const pass = Mem.cmp(dst.$ptr(), EXPECT.$ptr(), Aes128I.BLOCK_LEN) == 0
    printf`AES-128: %s\n`(pass ? t$`PASS` : t$`FAIL`)
    if (!pass) {
        Mem.prB(t$`key`, KEY.$ptr(), Aes128I.KEY_LEN)
        Mem.prB(t$`src`, SRC.$ptr(), Aes128I.BLOCK_LEN)
        Mem.prB(t$`actual`, dst.$ptr(), Aes128I.BLOCK_LEN)
        Mem.prB(t$`expect`, EXPECT.$ptr(), Aes128I.BLOCK_LEN)
        fail()
    }
}
