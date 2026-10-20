/*
 * Copyright (c) 2022-2024 Nordic Semiconductor ASA
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 *
 * Bounded EMS translation of the NCS v3.0.2 CRACEN/SilexPK P-256 path.
 * See CRACEN-port.md for source provenance and bring-up limitations.
 */
import '@$$emscript'
export const $U = $declare('MODULE', P256ProviderI)

import * as $R from '@nordic.distro.nrf54/REGS.em'
import * as Common from '@em.mcu/Common.em'
import * as Microcode from '@nordic.mcu.nrf54/CracenMicrocode.em'
import * as P256ProviderI from '@em.crypto.p256/P256ProviderI.em'
import * as T from '@em.crypto.p256/Types.em'

// Keep readback diagnostics in the correctness harness; disable for energy runs.
export const verify_microcode = $config<bool_t>(true)
export const light_pause = $config<bool_t>(false)

const RAM_BASE = 0x51808000
const MICROCODE_BASE = 0x5180c000
const BUSY_MASK = 0x10000
const STATUS_MASK = 0x1fff0
const POLL_LIMIT = 10000000
const P256_COMMAND = 0x10101f00 // big endian, predefined P-256, 32-byte operands
const OP_MULT = 0x22
const OP_CHECK = 0x26
const G_X = $config<T.U256>()
const G_Y = $config<T.U256>()
const ORDER = $config<T.U256>()

export namespace em$meta {
    export function em$construct() {
        if (light_pause.$$val) Common.Irq.em$meta.useIntr('CRACEN')
        T.em$meta.initU256(G_X.$$val, '6b17d1f2_e12c4247_f8bce6e5_63a440f2_77037d81_2deb33a0_f4a13945_d898c296')
        T.em$meta.initU256(G_Y.$$val, '4fe342e2_fe1a7f9b_8ee7eb4a_7c0f9e16_2bce3357_6b315ece_cbb64068_37bf51f5')
        T.em$meta.initU256(ORDER.$$val, 'ffffffff_00000000_ffffffff_ffffffff_bce6faad_a7179e84_f3b9cac2_fc632551')
    }
}

//>> ---- em$targ ---- <<//

var initialized: bool_t = false
var active: bool_t = false
var slot_bytes: u32
var done: volatile_t<bool_t> = false

// Explicit initialization lets a standalone test measure microcode loading
// separately. Provider calls also initialize lazily and shut down on completion.
// Disabling loses microcode; keep power only across internal steps of an operation.
export function initialize() {
    if (initialized) return
    acquire()
    const features = $R.CRACENCORE.PK.HWCONFIG.$$
    const max_bytes = features & 0xfff
    if ((features & 0x10000) == 0 || (features & 0xf00000) != 0xf00000 || max_bytes < 32) {
        stopWithError(t$`capabilities`, features)
        return
    }
    slot_bytes = max_bytes > 0x200 ? 0x400 : 0x200
    for (const i of $range(Microcode.words.$len)) {
        $reg32[MICROCODE_BASE + <u32>i * 4] = Microcode.words[i]
    }
    e$`__DMB()`
    if (verify_microcode) {
        for (const i of $range(Microcode.words.$len)) {
            if ($reg32[MICROCODE_BASE + <u32>i * 4] != Microcode.words[i]) {
                stopWithError(t$`microcode readback`, <u32>i)
                return
            }
        }
    }
    initialized = true
    release()
}

export function makePublicKey(sk: T.U256, pk_OUT: $$<T.PubKey>) {
    checkScalar(sk.$ptr())
    initialize()
    acquire()
    prepareCommand(OP_MULT)
    writeOperand(8, sk.$ptr())
    writeOperand(12, G_X.$ptr())
    writeOperand(13, G_Y.$ptr())
    const status = run()
    if (status != 0) {
        stopWithError(t$`makePublicKey`, status)
        return
    }
    readOperand(pk_OUT.$$.x.$ptr(), 10)
    readOperand(pk_OUT.$$.y.$ptr(), 11)
    release()
    shutdown() // FIX: public-key generation must not leave CRACEN powered
}

export function validatePublicKey(pk: $$<T.PubKey>): bool_t {
    const valid = checkPublicKey(pk)
    shutdown()
    return valid
}

function checkPublicKey(pk: $$<T.PubKey>): bool_t {
    initialize()
    acquire()
    prepareCommand(OP_CHECK)
    writeOperand(12, pk.$$.x.$ptr())
    writeOperand(13, pk.$$.y.$ptr())
    const status = run()
    release()
    // Only invalid-point/range results are ordinary validation failures.
    if (status == 0x10 || status == 0x40) return false
    if (status != 0) {
        printf`CRACEN validatePublicKey FAIL status=%08x\n`(status)
        fail()
        return false
    }
    return true
}

export function ecdh(sk: T.U256, peer_pk: $$<T.PubKey>, secret_OUT: T.U256_Ref) {
    checkScalar(sk.$ptr())
    if (!checkPublicKey(peer_pk)) {
        shutdown()
        printf`CRACEN invalid peer public key\n`()
        fail()
        return
    }
    acquire()
    prepareCommand(OP_MULT)
    writeOperand(8, sk.$ptr())
    writeOperand(12, peer_pk.$$.x.$ptr())
    writeOperand(13, peer_pk.$$.y.$ptr())
    const status = run()
    if (status != 0) {
        stopWithError(t$`ecdh`, status)
        return
    }
    readOperand(secret_OUT, 10)
    release()
    shutdown() // FIX: ECDH is complete; release CRACEN before returning to the caller
}

function acquire() {
    if (active) {
        printf`CRACEN reentrant operation FAIL\n`()
        fail()
        return
    }
    active = true
    // This provider exclusively owns CRACEN; arm its IRQ only for an operation.
    $R.CRACEN.INTENCLR.$$ = 7
    // Match NCS cracen_acquire while isolating first-operation bring-up.
    if ($R.CRACEN.ENABLE.$$ == 0) {
        $R.CRACEN.ENABLE.$$ = $R.CRACEN_ENABLE_CRYPTOMASTER_Msk
            | $R.CRACEN_ENABLE_RNG_Msk | $R.CRACEN_ENABLE_PKEIKG_Msk
    }
    e$`__DMB()`
    let polls: u32 = 0
    while (($R.CRACENCORE.PK.STATUS.$$ & BUSY_MASK) != 0 && polls < POLL_LIMIT) polls += 1
    if (($R.CRACENCORE.PK.STATUS.$$ & BUSY_MASK) != 0) stopWithError(t$`acquire timeout`, $R.CRACENCORE.PK.STATUS.$$)
    if (initialized && verify_microcode) {
        for (const i of $range(Microcode.words.$len)) {
            if ($reg32[MICROCODE_BASE + <u32>i * 4] != Microcode.words[i]) {
                stopWithError(t$`microcode retention`, <u32>i)
                return
            }
        }
    }
}

function release() {
    if (light_pause) {
        Common.Irq.disable(e$`CRACEN_IRQn`)
        $R.CRACEN.INTENCLR.$$ = $R.CRACEN_INTENCLR_PKEIKG_Msk
    }
    // Clear private operands and results using volatile register writes.
    if (initialized) {
        for (const slot of $range(8, 14)) {
            const addr = operandAddress(<u32>slot)
            for (const i of $range(T.U256_LEN)) $reg32[addr + <u32>i * 4] = 0
        }
    }
    $R.CRACENCORE.PK.CONTROL.$$ = 2 // clear accelerator IRQ
    $R.CRACEN.EVENTS_PKEIKG.$$ = 0
    e$`__DMB()`
    active = false
}

// Power down after a public operation or explicit initialization session. The next use reloads microcode.
export function shutdown() {
    if (active) {
        printf`CRACEN shutdown during operation FAIL\n`()
        fail()
        return
    }
    $R.CRACEN.ENABLE.$$ = 0
    initialized = false
}

// Nordic selects command/byte-order mode before any operand RAM access.
function prepareCommand(op: u32) {
    $R.CRACENCORE.PK.COMMAND.$$ = P256_COMMAND | op
    e$`__DMB()`
}

function run(): u32 {
    $R.CRACENCORE.PK.POINTERS.$$ = 12 | (8 << 8) | (10 << 16)
    // Only thread-context callers with interrupts enabled can pause. Keep the
    // original polling path for startup/ISR/interrupt-masked callers.
    const pause_wait = light_pause && Common.GlobalInterrupts.isEnabled() && e$`(__get_IPSR() == 0)`
    if (pause_wait) {
        const key = Common.GlobalInterrupts.disable()
        done = false
        $R.CRACENCORE.PK.CONTROL.$$ = 2
        $R.CRACEN.EVENTS_PKEIKG.$$ = 0
        Common.Irq.clear(e$`CRACEN_IRQn`)
        $R.CRACEN.INTENSET.$$ = $R.CRACEN_INTENSET_PKEIKG_Msk
        Common.Irq.enable(e$`CRACEN_IRQn`)
        e$`__DMB()`
        $R.CRACENCORE.PK.CONTROL.$$ = 3
        e$`__DSB()`
        Common.GlobalInterrupts.restore(key)
        waitDone()
        Common.Irq.disable(e$`CRACEN_IRQn`)
        $R.CRACEN.INTENCLR.$$ = $R.CRACEN_INTENCLR_PKEIKG_Msk
    } else {
        e$`__DMB()`
        $R.CRACENCORE.PK.CONTROL.$$ = 3 // START | CLEAR_IRQ
        e$`__DSB()`
        let polls: u32 = 0
        while (($R.CRACENCORE.PK.STATUS.$$ & BUSY_MASK) != 0 && polls < POLL_LIMIT) polls += 1
    }
    const status = $R.CRACENCORE.PK.STATUS.$$ & STATUS_MASK
    if ((status & BUSY_MASK) != 0) {
        stopWithError(t$`operation timeout`, status)
        return status
    }
    e$`__DMB()`
    return status
}

function waitDone() {
    const level = Common.Idle.getLevel()
    Common.Idle.setLevel(1) // pause: preserve peripheral power and clocks
    while (true) {
        // Mask across the predicate and WFI entry. A completion arriving in
        // this gap remains pending and wakes WFI instead of being lost.
        const key = Common.GlobalInterrupts.disable()
        if (done) {
            Common.GlobalInterrupts.restore(key)
            break
        }
        Common.Idle.exec()
        Common.GlobalInterrupts.restore(key)
        // Radio/timer IRQs can also wake us. Only our ISR sets done.
    }
    Common.Idle.setLevel(level)
}

export function CRACEN_isr$$() {
    if ($R.CRACEN.EVENTS_PKEIKG.$$ != 0) {
        const status = $R.CRACENCORE.PK.STATUS.$$
        $R.CRACENCORE.PK.CONTROL.$$ = 2
        $R.CRACEN.EVENTS_PKEIKG.$$ = 0
        e$`__DMB()`
        if ((status & BUSY_MASK) == 0) done = true
    }
    Common.Irq.clear(e$`CRACEN_IRQn`)
}

function operandAddress(slot: u32): u32 {
    return RAM_BASE + slot * slot_bytes + slot_bytes - 32
}

function swapBytes(w: u32): u32 {
    return (w >> 24) | ((w >> 8) & 0x0000ff00) | ((w << 8) & 0x00ff0000) | (w << 24)
}

function writeOperand(slot: u32, src: T.U256_Ref) {
    const addr = operandAddress(slot)
    for (const i of $range(T.U256_LEN)) $reg32[addr + <u32>i * 4] = swapBytes(src[T.U256_LEN - 1 - i])
}

function readOperand(dst: T.U256_Ref, slot: u32) {
    const addr = operandAddress(slot)
    for (const i of $range(T.U256_LEN)) dst[T.U256_LEN - 1 - i] = swapBytes($reg32[addr + <u32>i * 4])
}

function checkScalar(sk: T.U256_Ref) {
    let nonzero: u32 = 0
    for (const i of $range(T.U256_LEN)) nonzero |= sk[i]
    if (nonzero != 0) {
        for (const i of $range(T.U256_LEN - 1, -1, -1)) {
            if (sk[i] < ORDER[i]) return
            if (sk[i] > ORDER[i]) break
        }
    }
    printf`CRACEN private scalar out of range\n`()
    fail()
}

function stopWithError(where: text_t, status: u32) {
    // Stop access before reporting a fatal hardware error. On timeout, do not
    // touch operand RAM while the accelerator may still be operating.
    printf`CRACEN hw=%08x slots=%d enable=%08x command=%08x pointers=%08x raw=%08x\n`(
        $R.CRACENCORE.PK.HWCONFIG.$$, slot_bytes, $R.CRACEN.ENABLE.$$,
        $R.CRACENCORE.PK.COMMAND.$$, $R.CRACENCORE.PK.POINTERS.$$, $R.CRACENCORE.PK.STATUS.$$)
    $R.CRACEN.ENABLE.$$ = 0
    active = false
    printf`CRACEN %s FAIL status=%08x\n`(where, status)
    fail()
}