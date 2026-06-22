import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const DESC_ADDR = 0x0000_8000

class Desc extends $struct {
    loadAddr: ptr_t<u32>
    loadSize: u32
    bssAddr: ptr_t<u32>
    bssSize: u32
}

export function em$run() {
    const desc = $cast2<$$<Desc>>(DESC_ADDR)
    const dst = desc.$$.loadAddr
    const src = $cast2<ptr_t<u32>>(DESC_ADDR + $sizeof<Desc>())
    for (const i of $range(desc.$$.loadSize)) {
        dst[i] = src[i]
    }
    const bss = desc.$$.bssAddr
    for (const i of $range(desc.$$.bssSize)) {
        bss[i] = 0
    }
    $R.VPR00.INITPC.$$ = $cast2<u32>(desc.$$.loadAddr)
    $R.VPR00.CPURUN.$$ = 1
}
