import '@$$emscript'
export const $U = $declare('MODULE', Aes128I)

import * as $R from '@ti.distro.cc23xx/REGS.em'
import * as Aes128I from '@em.hal/Aes128I.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as Mem from '@em.utils/Mem.em'

// Single-block hardware ECB; AES registers and fields come from REGS.

export function encrypt(key: Aes128I.Key_Ref, src: Aes128I.Block_Ref, dst: Aes128I.Block_Ref): void {
    // One short transaction also protects against later ISR users of AES.
    const irq_key = GlobalInterrupts.disable()
    const clock_was_on = ($R.CLKCTL.CLKCFG0.$$ & $R.CLKCTL_CLKCFG0_LAES_M) != 0
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_LAES
    $R.CLKCTL.CLKCFG0.$$ // complete the clock-enable write before AES access
    $R.AES.AUTOCFG.$$ = 0
    for (const i of $range(4)) {
        $reg32[$R.AES_BASE + $R.AES_O_KEY0 + (i << 2)] = Mem.scan32($$(key[i << 2]))
    }
    $R.AES.AUTOCFG.$$ = ($R.AES_AUTOCFG_AESSRC_BUF | $R.AES_AUTOCFG_TRGAES_WRBUF3S)
    // Writing BUF3 triggers encryption. Read every source byte before any
    // output byte, so src and dst may alias and need not be word-aligned.
    for (const i of $range(4)) {
        $reg32[$R.AES_BASE + $R.AES_O_BUF0 + (i << 2)] = Mem.scan32($$(src[i << 2]))
    }
    let remaining: u16 = 256
    while (($R.AES.STA.$$ & $R.AES_STA_STATE_M) != 0 && remaining != 0) remaining -= 1
    const completed = ($R.AES.STA.$$ & $R.AES_STA_STATE_M) == 0
    if (completed) {
        for (const i of $range(4)) {
            Mem.pack32($$(dst[i << 2]), $reg32[$R.AES_BASE + $R.AES_O_TXT0 + (i << 2)])
        }
        $R.AES.AUTOCFG.$$ = 0
        for (const i of $range(4)) {
            $reg32[$R.AES_BASE + $R.AES_O_KEY0 + (i << 2)] = 0
            $reg32[$R.AES_BASE + $R.AES_O_BUF0 + (i << 2)] = 0
            $reg32[$R.AES_BASE + $R.AES_O_TXT0 + (i << 2)] = 0
        }
    }
    if (!clock_was_on) $R.CLKCTL.CLKENCLR0.$$ = $R.CLKCTL_CLKENCLR0_LAES
    GlobalInterrupts.restore(irq_key)
    if (!completed) {
        printf`TI AES timeout FAIL\n`()
        fail()
    }
}
