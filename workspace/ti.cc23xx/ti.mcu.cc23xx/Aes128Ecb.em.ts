import '@$$emscript'
export const $U = $declare('MODULE', Aes128I)

import * as $R from '@ti.distro.cc23xx/REGS.em'
import * as Aes128I from '@em.hal/Aes128I.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as Mem from '@em.utils/Mem.em'

// Packet sessions amortize hardware setup across CCM's AES blocks.
// Interrupts stay masked until endSession(), protecting the key from ISR users.
var session_irq_key: u32
var session_clock_was_on: bool_t

export function beginSession(key: Aes128I.Key_Ref) {
    session_irq_key = GlobalInterrupts.disable()
    session_clock_was_on = ($R.CLKCTL.CLKCFG0.$$ & $R.CLKCTL_CLKCFG0_LAES_M) != 0
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_LAES
    $R.CLKCTL.CLKCFG0.$$ // complete clock enable before AES access
    $R.AES.AUTOCFG.$$ = 0
    for (const i of $range(4)) {
        $reg32[$R.AES_BASE + $R.AES_O_KEY0 + (i << 2)] = Mem.scan32($$(key[i << 2]))
    }
    // WRBUF3S is one-shot; WRBUF3 triggers every block in this session.
    $R.AES.AUTOCFG.$$ = $R.AES_AUTOCFG_AESSRC_BUF | $R.AES_AUTOCFG_TRGAES_WRBUF3
}

// Aligned CCM keys use four native little-endian words, matching scan32().
// Byte-oriented callers retain beginSession() above.
export function beginSessionWords(key: ptr_t<u32>) {
    session_irq_key = GlobalInterrupts.disable()
    session_clock_was_on = ($R.CLKCTL.CLKCFG0.$$ & $R.CLKCTL_CLKCFG0_LAES_M) != 0
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_LAES
    $R.CLKCTL.CLKCFG0.$$ // complete clock enable before AES access
    $R.AES.AUTOCFG.$$ = 0
    $R.AES.KEY0.$$ = key[0]
    $R.AES.KEY1.$$ = key[1]
    $R.AES.KEY2.$$ = key[2]
    $R.AES.KEY3.$$ = key[3]
    // WRBUF3S is one-shot; WRBUF3 triggers every block in this session.
    $R.AES.AUTOCFG.$$ = $R.AES_AUTOCFG_AESSRC_BUF | $R.AES_AUTOCFG_TRGAES_WRBUF3
}

export function encryptBlock(src: Aes128I.Block_Ref, dst: Aes128I.Block_Ref) {
    // Read all source words before writing any output; unaligned aliasing is safe.
    for (const i of $range(4)) {
        $reg32[$R.AES_BASE + $R.AES_O_BUF0 + (i << 2)] = Mem.scan32($$(src[i << 2]))
    }
    let remaining: u16 = 256
    while (($R.AES.STA.$$ & $R.AES_STA_STATE_M) != 0 && remaining != 0) remaining -= 1
    if (($R.AES.STA.$$ & $R.AES_STA_STATE_M) != 0) {
        endSession()
        printf`TI AES timeout FAIL\n`()
        fail()
        return
    }
    for (const i of $range(4)) {
        Mem.pack32($$(dst[i << 2]), $reg32[$R.AES_BASE + $R.AES_O_TXT0 + (i << 2)])
    }
}

// CCM supplies u32-backed blocks; retain encryptBlock() for unaligned callers.
export function encryptBlockWords(src: ptr_t<u32>, dst: ptr_t<u32>) {
    encryptBlockWordsKeep(src)
    readBlockWords(dst)
}

// Complete AES synchronously, leaving its result in TXT for hardware chaining.
export function encryptBlockWordsKeep(src: ptr_t<u32>) {
    $R.AES.BUF0.$$ = src[0]
    $R.AES.BUF1.$$ = src[1]
    $R.AES.BUF2.$$ = src[2]
    $R.AES.BUF3.$$ = src[3]
    let remaining: u16 = 256
    while (($R.AES.STA.$$ & $R.AES_STA_STATE_M) != 0 && remaining != 0) remaining -= 1
    if (($R.AES.STA.$$ & $R.AES_STA_STATE_M) != 0) {
        endSession()
        printf`TI AES timeout FAIL\n`()
        fail()
        return
    }
}

// Call after a completed block, before starting another AES operation.
export function readBlockWords(dst: ptr_t<u32>) {
    dst[0] = $R.AES.TXT0.$$
    dst[1] = $R.AES.TXT1.$$
    dst[2] = $R.AES.TXT2.$$
    dst[3] = $R.AES.TXT3.$$
}

// Continue CBC-MAC using the previous AES TXT value as the chaining state.
export function macBlockWords(src: ptr_t<u32>, dst: ptr_t<u32>) {
    $R.AES.AUTOCFG.$$ = $R.AES_AUTOCFG_AESSRC_TXTXBUF | $R.AES_AUTOCFG_TRGAES_WRBUF3
    encryptBlockWords(src, dst)
    $R.AES.AUTOCFG.$$ = $R.AES_AUTOCFG_AESSRC_BUF | $R.AES_AUTOCFG_TRGAES_WRBUF3
}

// Continue CBC-MAC without copying an intermediate result into RAM.
export function macBlockWordsKeep(src: ptr_t<u32>) {
    $R.AES.AUTOCFG.$$ = $R.AES_AUTOCFG_AESSRC_TXTXBUF | $R.AES_AUTOCFG_TRGAES_WRBUF3
    encryptBlockWordsKeep(src)
    $R.AES.AUTOCFG.$$ = $R.AES_AUTOCFG_AESSRC_BUF | $R.AES_AUTOCFG_TRGAES_WRBUF3
}

// Encrypt one counter, then XOR keystream with payload bytes in software.
// Payload pointers may be unaligned; no payload packing or AES XOR writes.
export function counterBlockWords(ctr: ptr_t<u32>, src: ptr_t<u8>, dst: ptr_t<u8>, len: u8) {
    $R.AES.BUF0.$$ = ctr[0]
    $R.AES.BUF1.$$ = ctr[1]
    $R.AES.BUF2.$$ = ctr[2]
    $R.AES.BUF3.$$ = ctr[3]
    let remaining: u16 = 256
    while (($R.AES.STA.$$ & $R.AES_STA_STATE_M) != 0 && remaining != 0) remaining -= 1
    if (($R.AES.STA.$$ & $R.AES_STA_STATE_M) != 0) {
        endSession()
        printf`TI AES timeout FAIL\n`()
        fail()
        return
    }
    if (len == 1) {
        dst[0] = src[0] ^ <u8>$R.AES.TXT0.$$
        return
    }
    let offset: u8 = 0
    while (offset < len) {
        let stream = $reg32[$R.AES_BASE + $R.AES_O_TXT0 + offset]
        const count: u8 = len - offset > 4 ? 4 : len - offset
        for (const i of $range(count)) {
            dst[offset + i] = src[offset + i] ^ <u8>stream
            stream >>= 8
        }
        offset += 4
    }
}

export function endSession() {
    $R.AES.AUTOCFG.$$ = 0
    // Four words per register bank: clear explicitly, without loop bookkeeping.
    $R.AES.KEY0.$$ = 0
    $R.AES.BUF0.$$ = 0
    $R.AES.TXT0.$$ = 0
    $R.AES.KEY1.$$ = 0
    $R.AES.BUF1.$$ = 0
    $R.AES.TXT1.$$ = 0
    $R.AES.KEY2.$$ = 0
    $R.AES.BUF2.$$ = 0
    $R.AES.TXT2.$$ = 0
    $R.AES.KEY3.$$ = 0
    $R.AES.BUF3.$$ = 0
    $R.AES.TXT3.$$ = 0
    if (!session_clock_was_on) $R.CLKCTL.CLKENCLR0.$$ = $R.CLKCTL_CLKENCLR0_LAES
    GlobalInterrupts.restore(session_irq_key)
}

export function encrypt(key: Aes128I.Key_Ref, src: Aes128I.Block_Ref, dst: Aes128I.Block_Ref): void {
    beginSession(key)
    encryptBlock(src, dst)
    endSession()
}