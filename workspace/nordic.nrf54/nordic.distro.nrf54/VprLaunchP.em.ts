import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Common from '@em.mcu/Common.em'

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
    e$`asm("nop")`
    e$`asm("nop")`
    e$`asm("nop")`
    e$`asm("nop")`
    const desc = $cast2<$$<Desc>>(DESC_ADDR)
    const dst = desc.$$.loadAddr
    const src = $cast2<ptr_t<u32>>(DESC_ADDR + $sizeof<Desc>())
    printf`dst = %08x, src = %08x\n`(dst, src)
    for (const i of $range(desc.$$.loadSize)) {
        dst[i] = src[i]
    }
    const bss = desc.$$.bssAddr
    printf`bss = %08x, sz = %d\n`(bss, desc.$$.bssSize)
    for (const i of $range(desc.$$.bssSize)) {
        bss[i] = 0
    }
    printf`start...\n`()
    e$`asm("nop")`
    e$`asm("nop")`
    e$`asm("nop")`
    e$`asm("nop")`
    e$`asm("nop")`
    $reg32[0x50040530] |= 0x10
    $R.VPR00.INITPC.$$ = $cast2<u32>(desc.$$.loadAddr)
    $R.VPR00.CPURUN.$$ = 1
    printf`INITPC = %08x, CPURUN = %08x\n`($R.VPR00.INITPC.$$, $R.VPR00.CPURUN.$$)
    e$`asm("nop")`
    e$`asm("nop")`
    Common.BusyWait.wait(10000)
    printf`%x %x\n`($reg32[0x20028100], $reg32[0x20030000])
}
