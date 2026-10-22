import '@$$emscript'
export const $U = $declare('MODULE')

import * as CmacProviderI from '@em.crypto.cmac/CmacProviderI.em'
import * as Crypto from '@em.crypto/Crypto.em'
import * as Mem from '@em.utils/Mem.em'

class Message extends $vector<u8> { $len = 64 }

const EXPECT_0 = $config<CmacProviderI.Mac>()
const EXPECT_16 = $config<CmacProviderI.Mac>()
const EXPECT_40 = $config<CmacProviderI.Mac>()
const EXPECT_64 = $config<CmacProviderI.Mac>()
const KEY = $config<CmacProviderI.Key>()
const MESSAGE = $config<Message>()

export namespace em$meta {
    export function em$construct() {
        initHex(EXPECT_0.$$val, 'bb1d6929_e9593728_7fa37d12_9b756746')
        initHex(EXPECT_16.$$val, '070a16b4_6b4d4144_f79bdd9d_d04a287c')
        initHex(EXPECT_40.$$val, 'dfa66747_de9ae630_30ca3261_1497c827')
        initHex(EXPECT_64.$$val, '51f0bebf_7e3b9d92_fc497417_79363cfe')
        initHex(KEY.$$val, '2b7e1516_28aed2a6_abf71588_09cf4f3c')
        initHex(MESSAGE.$$val,
            '6bc1bee2_2e409f96_e93d7e11_7393172a_' +
            'ae2d8a57_1e03ac9c_9eb76fac_45af8e51_' +
            '30c81c46_a35ce411_e5fbc119_1a0a52ef_' +
            'f69f2445_df4f9b17_ad2b417b_e66c3710'
        )
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
    test(t$`CMAC-0`, MESSAGE.$frame(MESSAGE.$len), EXPECT_0.$ptr())
    test(t$`CMAC-16`, MESSAGE.$frame(0, 16), EXPECT_16.$ptr())
    test(t$`CMAC-40`, MESSAGE.$frame(0, 40), EXPECT_40.$ptr())
    test(t$`CMAC-64`, MESSAGE.$frame(0, 64), EXPECT_64.$ptr())
    printf`CMAC: PASS\n`()
}

function test(label: text_t, msg: frame_t<u8>, expect: CmacProviderI.Mac_Ref) {
    let mac = CmacProviderI.Mac.$make()
    Crypto.Cmac.compute(KEY.$ptr(), msg, mac.$ptr())
    const pass = Mem.cmp(mac.$ptr(), expect, CmacProviderI.MAC_LEN) == 0
    printf`%s: %s\n`(label, pass ? t$`PASS` : t$`FAIL`)
    if (!pass) {
        Mem.prB(t$`actual`, mac.$ptr(), CmacProviderI.MAC_LEN)
        Mem.prB(t$`expect`, expect, CmacProviderI.MAC_LEN)
        fail()
    }
}
