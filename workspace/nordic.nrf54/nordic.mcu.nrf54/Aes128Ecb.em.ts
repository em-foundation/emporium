import '@$$emscript'
export const $U = $declare('MODULE', Aes128I)

import * as $R from '@nordic.distro.nrf54/REGS.em'
import * as Aes128I from '@em.hal/Aes128I.em'
import * as Mem from '@em.utils/Mem.em'

// Key order and byte-swap DMA jobs follow NCS v3.0.2's Nordic ECB path:
// zephyr/subsys/bluetooth/controller/ll_sw/nordic/hal/nrf5/ecb.c.
const POLL_LIMIT = 100000
const JOB_CONFIG = (7 << 24) | Aes128I.BLOCK_LEN

class BlockWords extends $vector<u32> { $len = 4 }
class JobList extends $vector<u32> { $len = 4 }

export function encrypt(key: Aes128I.Key_Ref, src: Aes128I.Block_Ref, dst: Aes128I.Block_Ref): void {
    let input = BlockWords.$make()
    let output = BlockWords.$make()
    let in_jobs = JobList.$make()
    let out_jobs = JobList.$make()
    Mem.cpy(input.$ptr(), src, Aes128I.BLOCK_LEN)
    in_jobs[0] = $cast2<u32>(input.$ptr())
    in_jobs[1] = JOB_CONFIG
    in_jobs[2] = in_jobs[3] = 0
    out_jobs[0] = $cast2<u32>(output.$ptr())
    out_jobs[1] = JOB_CONFIG
    out_jobs[2] = out_jobs[3] = 0
    $R.ECB00.TASKS_STOP.$$ = 1
    $R.ECB00.INTENCLR.$$ = $R.ECB_INTENCLR_END_Msk | $R.ECB_INTENCLR_ERROR_Msk
    for (const i of $range(4)) {
        const off = i * 4
        $R.ECB00.KEY.VALUE[3 - i].$$ = (<u32>key[off] << 24) | (<u32>key[off + 1] << 16)
            | (<u32>key[off + 2] << 8) | <u32>key[off + 3]
    }
    $R.ECB00.IN.PTR.$$ = $cast2<u32>(in_jobs.$ptr())
    $R.ECB00.OUT.PTR.$$ = $cast2<u32>(out_jobs.$ptr())
    $R.ECB00.EVENTS_END.$$ = 0
    $R.ECB00.EVENTS_ERROR.$$ = 0
    e$`__DMB()`
    $R.ECB00.TASKS_START.$$ = 1
    let polls: u32 = 0
    while ($R.ECB00.EVENTS_END.$$ == 0 && $R.ECB00.EVENTS_ERROR.$$ == 0 && polls < POLL_LIMIT) polls += 1
    const complete = $R.ECB00.EVENTS_END.$$ != 0 && $R.ECB00.EVENTS_ERROR.$$ == 0
    const error = $R.ECB00.ERRORSTATUS.$$
    $R.ECB00.TASKS_STOP.$$ = 1
    e$`__DMB()`
    $R.ECB00.IN.PTR.$$ = 0
    $R.ECB00.OUT.PTR.$$ = 0
    for (const i of $range(4)) $R.ECB00.KEY.VALUE[i].$$ = 0
    $R.ECB00.EVENTS_END.$$ = 0
    $R.ECB00.EVENTS_ERROR.$$ = 0
    if (!complete) {
        printf`NRF54 AES-128 FAIL error=%08x polls=%d\n`(error, polls)
        fail()
        return
    }
    Mem.cpy(dst, output.$ptr(), Aes128I.BLOCK_LEN)
}
