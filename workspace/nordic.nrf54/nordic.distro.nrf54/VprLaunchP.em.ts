import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const DESC_ADDR = 0x0000_8000

class Desc extends $struct {
    codeAddr: ptr_t<u32>
    codeSize: u32
    dataAddr: ptr_t<u32>
    dataSize: u32
    bssAddr: ptr_t<u32>
    bssSize: u32
}

export function em$run() {
    const base = DESC_ADDR + $sizeof<Desc>()
    const desc = $cast2<$$<Desc>>(DESC_ADDR)
    const code_src = $cast2<ptr_t<u32>>(base)
    const code_dst = desc.$$.codeAddr
    for (const i of $range(desc.$$.codeSize)) {
        code_dst[i] = code_src[i]
    }
    const data_src = $cast2<ptr_t<u32>>(base + (desc.$$.codeSize * 4))
    const data_dst = desc.$$.dataAddr
    for (const i of $range(desc.$$.dataSize)) {
        data_dst[i] = data_src[i]
    }
    const bss_dst = desc.$$.bssAddr
    for (const i of $range(desc.$$.bssSize)) {
        bss_dst[i] = 0
    }
    //
    $R.RRAMC.POWER.LOWPOWERCONFIG.$$ = $R.RRAMC_POWER_LOWPOWERCONFIG_MODE_PowerOff
    e$`NRF_GLITCHDET_S->CONFIG = (GLITCHDET_CONFIG_ENABLE_Disable << GLITCHDET_CONFIG_ENABLE_Pos)`
    $R.REGULATORS.VREGMAIN.DCDCEN.$$ = 1
    //
    $reg32[0x50040530] |= 0x10
    $R.VPR00.INITPC.$$ = $cast2<u32>(desc.$$.codeAddr)
    $R.VPR00.CPURUN.$$ = 1
    e$`asm volatile ("wfi")`
    e$`__builtin_unreachable()`
}
