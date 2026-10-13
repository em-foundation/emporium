import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'
import * as Mem from '@em.utils/Mem.em'

// nRF52832 CCM, standalone short-packet mode (no RADIO or PPI).
// Packet RAM format: S0 | LENGTH | S1 | PAYLOAD [| 4-byte MIC].
// Default MODE.LENGTH uses 5 length bits: at most 27 plaintext bytes plus MIC.

const CONFIG_LEN = 33
const SCRATCH_LEN = 43
const KEY_LEN = 16
const IV_LEN = 8
const MAX_PLAIN_LEN = 27
const MIC_LEN = 4

class Config extends $vector<u8> { $len = CONFIG_LEN }
class Scratch extends $vector<u8> { $len = SCRATCH_LEN }

var config: Config
var scratch: Scratch

export function configure(key: ptr_t<u8>, iv: ptr_t<u8>, counter_lo: u32, counter_hi: u8, direction: u8) {
    Mem.cpy(config.$ptr(), key, KEY_LEN)
    for (const i of $range(4)) config[16 + i] = counter_lo >> (i * 8)
    config[20] = counter_hi & 0x7f
    config[21] = 0
    config[22] = 0
    config[23] = 0
    config[24] = direction & 1
    Mem.cpy($$(config[25]), iv, IV_LEN)
}

export function encrypt(src: ptr_t<u8>, dst: ptr_t<u8>) {
    if (src[1] == 0 || src[1] > MAX_PLAIN_LEN) {
        printf`CCM invalid encrypt length=%d\n`(src[1])
        halt()
    }
    crypt(false, src, dst)
}

export function decrypt(src: ptr_t<u8>, dst: ptr_t<u8>): bool_t {
    if (src[1] <= MIC_LEN || src[1] > MAX_PLAIN_LEN + MIC_LEN) {
        printf`CCM invalid decrypt length=%d\n`(src[1])
        halt()
    }
    return crypt(true, src, dst)
}

function crypt(dec: bool_t, src: ptr_t<u8>, dst: ptr_t<u8>): bool_t {
    // Use the Nordic generated register facade, as in RadioDriver and Aes128Ecb.
    // Do not use while AAR is active: AAR and CCM share peripheral ID 15.
    $R.CCM.ENABLE.$$ = 0
    $R.CCM.SHORTS.$$ = 0
    $R.CCM.EVENTS_ENDKSGEN.$$ = 0
    $R.CCM.EVENTS_ENDCRYPT.$$ = 0
    $R.CCM.EVENTS_ERROR.$$ = 0
    $R.CCM.MODE.$$ = dec ? 1 : 0 // 1 Mbit, default (5-bit) length
    $R.CCM.CNFPTR.$$ = $cast2<u32>(config.$ptr())
    $R.CCM.INPTR.$$ = $cast2<u32>(src)
    $R.CCM.OUTPTR.$$ = $cast2<u32>(dst)
    $R.CCM.SCRATCHPTR.$$ = $cast2<u32>(scratch.$ptr())
    $R.CCM.ENABLE.$$ = 2

    // Take MMIO snapshots into ordinary u32 scalars before printf.
    // Snapshot register values before printing diagnostics.
    const en: u32 = $R.CCM.ENABLE.$$
    const mode: u32 = $R.CCM.MODE.$$
    const cnf: u32 = $R.CCM.CNFPTR.$$
    const scr: u32 = $R.CCM.SCRATCHPTR.$$
    const end_before: u32 = $R.CCM.EVENTS_ENDKSGEN.$$
    const err_before: u32 = $R.CCM.EVENTS_ERROR.$$
    printf`CCM enable=%08x\n`(en)
    printf`CCM mode=%08x\n`(mode)
    printf`CCM cfgptr=%08x\n`(cnf)
    printf`CCM scratchptr=%08x\n`(scr)
    printf`CCM initial events end=%d error=%d\n`(end_before, err_before)
    if (en != 2 || mode != (dec ? 1 : 0) || cnf != $cast2<u32>(config.$ptr()) || scr != $cast2<u32>(scratch.$ptr()) || end_before != 0 || err_before != 0) {
        printf`CCM register setup FAIL (before KSGEN)\n`()
        halt()
    }

    printf`CCM KSGEN start\n`()
    $R.CCM.TASKS_KSGEN.$$ = 1
    while ($R.CCM.EVENTS_ENDKSGEN.$$ == 0 && $R.CCM.EVENTS_ERROR.$$ == 0) { }
    if ($R.CCM.EVENTS_ERROR.$$ != 0) {
        const end_after: u32 = $R.CCM.EVENTS_ENDKSGEN.$$
        const err_after: u32 = $R.CCM.EVENTS_ERROR.$$
        printf`CCM KSGEN end=%d error=%d\n`(end_after, err_after)
        printf`CCM ERROR during KSGEN\n`()
        halt()
    }
    printf`CCM KSGEN done\n`()
    $R.CCM.EVENTS_ENDKSGEN.$$ = 0

    printf`CCM CRYPT start mode=%d\n`(dec ? 1 : 0)
    $R.CCM.TASKS_CRYPT.$$ = 1
    while ($R.CCM.EVENTS_ENDCRYPT.$$ == 0 && $R.CCM.EVENTS_ERROR.$$ == 0) { }
    if ($R.CCM.EVENTS_ERROR.$$ != 0) {
        printf`CCM ERROR during CRYPT\n`()
        halt()
    }
    printf`CCM CRYPT done\n`()
    const mic_ok = !dec || $R.CCM.MICSTATUS.$$ == 1
    $R.CCM.ENABLE.$$ = 0
    return mic_ok
}
