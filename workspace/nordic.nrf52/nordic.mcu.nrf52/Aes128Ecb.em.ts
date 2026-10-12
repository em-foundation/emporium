import '@$$emscript'
export const $U = $declare('MODULE', Aes128I)

import * as $R from '@nordic.distro.nrf52/REGS.em'

import * as Aes128I from '@em.hal/Aes128I.em'
import * as Mem from '@em.utils/Mem.em'

const CLEAR_OFF = 16
const CIPHER_OFF = 32
const ECB_DATA_LEN = 48
const KEY_OFF = 0

class EcbData extends $vector<u8> { $len = ECB_DATA_LEN }

var ecb_data: EcbData

export function encrypt(key: Aes128I.Key_Ref, src: Aes128I.Block_Ref, dst: Aes128I.Block_Ref): void {
    Mem.cpy($$(ecb_data[KEY_OFF]), key, Aes128I.KEY_LEN)
    Mem.cpy($$(ecb_data[CLEAR_OFF]), src, Aes128I.BLOCK_LEN)
    $R.ECB.EVENTS_ENDECB.$$ = 0
    $R.ECB.EVENTS_ERRORECB.$$ = 0
    $R.ECB.ECBDATAPTR.$$ = $cast2<u32>($$(ecb_data[0]))
    $R.ECB.TASKS_STARTECB.$$ = 1
    while ($R.ECB.EVENTS_ENDECB.$$ == 0 && $R.ECB.EVENTS_ERRORECB.$$ == 0) { }
    if ($R.ECB.EVENTS_ERRORECB.$$ != 0) {
        $R.ECB.EVENTS_ERRORECB.$$ = 0
        fail()
    }
    $R.ECB.EVENTS_ENDECB.$$ = 0
    Mem.cpy(dst, $$(ecb_data[CIPHER_OFF]), Aes128I.BLOCK_LEN)
}
