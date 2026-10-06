import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as FieldI from '@em.crypto/P256_FieldI.em'
import * as FieldPortable from '@em.crypto/P256_FieldPortable.em'
import * as T from '@em.crypto/P256_Types.em'

export const Field = $proxy<FieldI.$I>()

const FIELD_PRIME_M2 = $config<T.U256>()
const MONT_R = $config<T.U256>()
const MONT_R2 = $config<T.U256>()
const MONT_ONE = $config<T.U256>()
const A_TEST = $config<T.U256>()
const B_TEST = $config<T.U256>()
const G_X_TEST = $config<T.U256>()
const G_Y_TEST = $config<T.U256>()
const K_TEST = $config<T.U256>()
const PEER_X_TEST = $config<T.U256>()
const PEER_Y_TEST = $config<T.U256>()

export namespace em$meta {

    export function em$configure() {
        if (Field.$U === null) Field.$$dlg = FieldPortable
    }

    export function em$construct() {
        T.em$meta.initU256(FIELD_PRIME_M2.$$val, 'ffffffff_00000001_00000000_00000000_00000000_ffffffff_ffffffff_fffffffd')
        T.em$meta.initU256(MONT_R.$$val, '00000000_fffffffe_ffffffff_ffffffff_ffffffff_00000000_00000000_00000001')
        T.em$meta.initU256(MONT_R2.$$val, '00000004_fffffffd_ffffffff_fffffffe_fffffffb_ffffffff_00000000_00000003')
        T.em$meta.initU256(MONT_ONE.$$val, '00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000001')
        T.em$meta.initU256(A_TEST.$$val, '11111111_22222222_33333333_44444444_55555555_66666666_77777777_88888888')
        T.em$meta.initU256(B_TEST.$$val, '01020304_05060708_090a0b0c_0d0e0f10_11121314_15161718_191a1b1c_1d1e1f20')
        T.em$meta.initU256(G_X_TEST.$$val, '6b17d1f2_e12c4247_f8bce6e5_63a440f2_77037d81_2deb33a0_f4a13945_d898c296')
        T.em$meta.initU256(G_Y_TEST.$$val, '4fe342e2_fe1a7f9b_8ee7eb4a_7c0f9e16_2bce3357_6b315ece_cbb64068_37bf51f5')
        T.em$meta.initU256(K_TEST.$$val, 'c88f01f5_10d9ac3f_70a292da_a2316de5_44e9aab8_afe84049_c62a9c57_862d1433')
        T.em$meta.initU256(PEER_X_TEST.$$val, 'd12dfb52_89c8d4f8_1208b702_70398c34_2296970a_0bccb74c_736fc755_4494bf63')
        T.em$meta.initU256(PEER_Y_TEST.$$val, '56fbf3ca_366cc23e_8157854c_13c58d6a_ac23f046_ada30f83_53e74f33_039872ab')
    }
}

//>> ---- em$targ ---- <<//

export function validatePublicKey(pk: $$<T.PubKey>): bool_t {
    return true
}

export function makePublicKey(sk: T.U256, pk_OUT: $$<T.PubKey>) {
    let p = T.PointJ.$make()
    Mem.cpy(p.x.$ptr(), G_X_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<T.U256>())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())
    pointMul(sk.$ptr(), $$(p))
    pointToAffine($$(p))
    Mem.cpy(pk_OUT.$$.x.$ptr(), p.x.$ptr(), $sizeof<T.U256>())
    Mem.cpy(pk_OUT.$$.y.$ptr(), p.y.$ptr(), $sizeof<T.U256>())
}

export function ecdh(sk: T.U256, peer_pk: $$<T.PubKey>, secret_OUT: T.U256_Ref) {
    let p = T.PointJ.$make()
    Mem.cpy(p.x.$ptr(), peer_pk.$$.x.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.y.$ptr(), peer_pk.$$.y.$ptr(), $sizeof<T.U256>())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())
    pointMul(sk.$ptr(), $$(p))
    pointToAffine($$(p))
    Mem.cpy(secret_OUT, p.x.$ptr(), $sizeof<T.U256>())
}

export function print(uref: T.U256_Ref, lab: text_t = t$``) {
    if (lab.$len > 0) {
        printf`%s = `(lab)
    }
    let sep = t$``
    for (const i of $range(T.U256_LEN - 1, -1, -1)) {
        printf`%s%08x`(sep, uref[i])
        sep = t$`_`
    }
    printf`\n`()
}

// FIELD FUNCTIONS

function fieldInv(a: T.U256_Ref) {
    let x = T.U256.$make()
    Mem.cpy(x.$ptr(), a, $sizeof<T.U256>())
    let x2 = T.U256.$make()
    Mem.cpy(x2.$ptr(), x.$ptr(), $sizeof<T.U256>())
    fieldSquare(x2.$ptr())
    let x4 = T.U256.$make()
    Mem.cpy(x4.$ptr(), x2.$ptr(), $sizeof<T.U256>())
    fieldSquare(x4.$ptr())
    let x8 = T.U256.$make()
    Mem.cpy(x8.$ptr(), x4.$ptr(), $sizeof<T.U256>())
    fieldSquare(x8.$ptr())
    let x13 = T.U256.$make()
    Mem.cpy(x13.$ptr(), x8.$ptr(), $sizeof<T.U256>())
    Field.mul(x13.$ptr(), x4.$ptr())
    Field.mul(x13.$ptr(), x.$ptr())
    let x15 = T.U256.$make()
    Mem.cpy(x15.$ptr(), x13.$ptr(), $sizeof<T.U256>())
    Field.mul(x15.$ptr(), x2.$ptr())
    let r = T.U256.$make()
    Mem.cpy(r.$ptr(), x15.$ptr(), $sizeof<T.U256>())
    let first = true
    for (const i of $range(T.U256_LEN - 1, -1, -1)) {
        for (const j of $range(7, -1, -1)) {
            if (first) {
                first = false
                continue
            }
            fieldSquare(r.$ptr())
            fieldSquare(r.$ptr())
            fieldSquare(r.$ptr())
            fieldSquare(r.$ptr())
            const n = (FIELD_PRIME_M2[i] >> (j * 4)) & 0xf
            if (n == 1) {
                Field.mul(r.$ptr(), x.$ptr())
            } else if (n == 13) {
                Field.mul(r.$ptr(), x13.$ptr())
            } else if (n == 15) {
                Field.mul(r.$ptr(), x15.$ptr())
            }
        }
    }
    Mem.cpy(a, r.$ptr(), $sizeof<T.U256>())
}

function fieldToMont(a: T.U256_Ref) {
    Field.mul(a, MONT_R2.$ptr())
}

function fieldFromMont(a: T.U256_Ref) {
    Field.mul(a, MONT_ONE.$ptr())
}

// Cortex-M4 Montgomery multiplication.
// Based on the 230-cycle P-256 Montgomery kernel from Emil Lenngren's
// P256-cortex-ecdh speed-optimized Cortex-M4 implementation.
// Standard EM•Script signature: a := a*b*R^-1 mod p.
function fieldMontMulM4(a: T.U256_Ref, b: T.U256_Ref) {
    e$`
        register uint32_t *ra asm("r0") = a.p_;
        register uint32_t *rb asm("r1") = b.p_;

        asm volatile (
        R"(
            /* Save the public ABI operands; the kernel uses a custom register ABI. */
            push    {r0,r1}
            mov     r2,r1
            mov     r1,r0

            /* Original P256_mulmod custom ABI:
             *   r1 = in1, r2 = in2
             *   result = r0-r7
             */
            push    {r2,r12}
            sub     sp,#36
            ldm     r2,{r2,r3,r4,r5}

            ldm     r1!,{r0,r10,lr}
            umull   r6,r11,r2,r0

            umull   r7,r12,r3,r0
            umaal   r7,r11,r2,r10

            push    {r6,r7}

            umull   r8,r6,r4,r0
            umaal   r8,r11,r3,r10

            umull   r9,r7,r5,r0
            umaal   r9,r11,r4,r10

            umaal   r11,r7,r5,r10

            umaal   r8,r12,r2,lr
            umaal   r9,r12,r3,lr
            umaal   r11,r12,r4,lr
            umaal   r12,r7,r5,lr

            ldm     r1!,{r0,r10,lr}

            umaal   r9,r6,r2,r0
            umaal   r11,r6,r3,r0
            umaal   r12,r6,r4,r0
            umaal   r6,r7,r5,r0

            strd    r8,r9,[sp,#8]

            mov     r9,#0
            umaal   r11,r9,r2,r10
            umaal   r12,r9,r3,r10
            umaal   r6,r9,r4,r10
            umaal   r7,r9,r5,r10

            mov     r10,#0
            umaal   r12,r10,r2,lr
            umaal   r6,r10,r3,lr
            umaal   r7,r10,r4,lr
            umaal   r9,r10,r5,lr

            ldr     r8,[r1],#4
            mov     lr,#0
            umaal   lr,r6,r2,r8
            umaal   r7,r6,r3,r8
            umaal   r9,r6,r4,r8
            umaal   r10,r6,r5,r8

            ldr     r8,[r1],#-28
            mov     r0,#0
            umaal   r7,r0,r2,r8
            umaal   r9,r0,r3,r8
            umaal   r10,r0,r4,r8
            umaal   r6,r0,r5,r8

            push    {r0}

            ldr     r2,[sp,#48]
            adds    r2,r2,#16
            ldm     r2,{r2,r3,r4,r5}

            ldr     r8,[r1],#4
            mov     r0,#0
            umaal   r11,r0,r2,r8
            str     r11,[sp,#20]
            umaal   r12,r0,r3,r8
            umaal   lr,r0,r4,r8
            umaal   r0,r7,r5,r8

            ldr     r8,[r1],#4
            mov     r11,#0
            umaal   r12,r11,r2,r8
            str     r12,[sp,#24]
            umaal   lr,r11,r3,r8
            umaal   r0,r11,r4,r8
            umaal   r11,r7,r5,r8

            ldr     r8,[r1],#4
            mov     r12,#0
            umaal   lr,r12,r2,r8
            str     lr,[sp,#28]
            umaal   r0,r12,r3,r8
            umaal   r11,r12,r4,r8
            umaal   r10,r12,r5,r8

            ldr     r8,[r1],#4
            mov     lr,#0
            umaal   r0,lr,r2,r8
            str     r0,[sp,#32]
            umaal   r11,lr,r3,r8
            umaal   r10,lr,r4,r8
            umaal   r6,lr,r5,r8

            ldm     r1!,{r0,r8}
            umaal   r11,r9,r2,r0
            str     r11,[sp,#36]
            umaal   r9,r10,r3,r0
            umaal   r10,r6,r4,r0
            pop     {r11}
            umaal   r11,r6,r5,r0

            umaal   r9,r7,r2,r8
            umaal   r10,r7,r3,r8
            umaal   r11,r7,r4,r8
            umaal   r6,r7,r5,r8

            ldm     r1!,{r0,r8}
            umaal   r10,r12,r2,r0
            umaal   r11,r12,r3,r0
            umaal   r6,r12,r4,r0
            umaal   r7,r12,r5,r0

            umaal   r11,lr,r2,r8
            umaal   lr,r6,r3,r8
            umaal   r6,r7,r4,r8
            umaal   r7,r12,r5,r8

            strd    r6,r7,[sp,#36]
            str     r12,[sp,#44]
            pop     {r0-r8}

            mov     r12,#0

            adds    r3,r0
            adcs    r4,r1
            adcs    r5,r2
            adcs    r6,r0
            adcs    r7,r1
            adcs    r8,r0
            adcs    r9,r1
            adcs    r10,#0
            adcs    r11,#0
            adcs    r12,#0

            adds    r6,r3
            adcs    r7,r4
            adcs    r8,r2
            adcs    r9,r3
            adcs    r10,r2
            adcs    r11,r3
            adcs    r12,#0

            subs    r7,r0
            sbcs    r8,r1
            sbcs    r9,r2
            sbcs    r10,r3
            sbcs    r11,#0
            sbcs    r12,#0

            pop     {r1-r3}

            adds    r0,lr,r12
            adcs    r1,#0
            mov     r12,#0
            adcs    r12,#0

            adcs    r8,r5
            adcs    r9,r6
            adcs    r10,r4
            adcs    r11,r5
            adcs    r0,r4
            adcs    r1,r5
            adcs    r2,r12
            adcs    r3,#0
            mov     r12,#0
            adcs    r12,#0

            adcs    r10,r7
            adcs    r11,#0
            adcs    r0,r6
            adcs    r1,r7
            adcs    r2,r6
            adcs    r3,r7
            adcs    r12,#0

            subs    r11,r4
            sbcs    r0,r5
            sbcs    r1,r6
            sbcs    r2,r7
            sbcs    r3,#0
            sbcs    r12,#0

            /* Conditional subtraction of p. */
            subs    r8,r8,#0xffffffff
            sbcs    r9,r9,#0xffffffff
            sbcs    r10,r10,#0xffffffff
            sbcs    r11,r11,#0
            sbcs    r4,r0,#0
            sbcs    r5,r1,#0
            sbcs    r6,r2,#1
            sbcs    r7,r3,#0xffffffff
            sbc     r12,r12,#0

            adds    r0,r8,r12
            adcs    r1,r9,r12
            adcs    r2,r10,r12
            adcs    r3,r11,#0
            adcs    r4,r4,#0
            adcs    r5,r5,#0
            adcs    r6,r6,r12,lsr #31
            adcs    r7,r7,r12

            /* Discard the kernel's saved filler word (reference kernel returned here). */
            pop     {r12}

            /* Store r0-r7 through the original destination pointer. */
            ldr     r8,[sp,#0]
            stm     r8,{r0-r7}
            add     sp,#8
        )"
            : "+r" (ra), "+r" (rb)
            :
            : "r2", "r3", "r4", "r5", "r6", "r7",
              "r8", "r9", "r10", "r11", "r12", "lr", "cc", "memory"
        );
    `
}

function fieldSquare(a: T.U256_Ref) {
    Field.mul(a, a)
}

// POINT FUNCTIONS
function pointAdd(p: $$<T.PointJ>, q: $$<T.PointJ>) {
    let z1z1 = T.U256.$make()
    Mem.cpy(z1z1.$ptr(), p.$$.z.$ptr(), $sizeof<T.U256>())
    fieldSquare(z1z1.$ptr())
    let z2z2 = T.U256.$make()
    Mem.cpy(z2z2.$ptr(), q.$$.z.$ptr(), $sizeof<T.U256>())
    fieldSquare(z2z2.$ptr())
    let u1 = T.U256.$make()
    Mem.cpy(u1.$ptr(), p.$$.x.$ptr(), $sizeof<T.U256>())
    Field.mul(u1.$ptr(), z2z2.$ptr())
    let u2 = T.U256.$make()
    Mem.cpy(u2.$ptr(), q.$$.x.$ptr(), $sizeof<T.U256>())
    Field.mul(u2.$ptr(), z1z1.$ptr())
    let s1 = T.U256.$make()
    Mem.cpy(s1.$ptr(), z2z2.$ptr(), $sizeof<T.U256>())
    Field.mul(s1.$ptr(), q.$$.z.$ptr())
    Field.mul(s1.$ptr(), p.$$.y.$ptr())
    let s2 = T.U256.$make()
    Mem.cpy(s2.$ptr(), z1z1.$ptr(), $sizeof<T.U256>())
    Field.mul(s2.$ptr(), p.$$.z.$ptr())
    Field.mul(s2.$ptr(), q.$$.y.$ptr())
    let h = T.U256.$make()
    Mem.cpy(h.$ptr(), u2.$ptr(), $sizeof<T.U256>())
    Field.sub(h.$ptr(), u1.$ptr())
    let i = T.U256.$make()
    Mem.cpy(i.$ptr(), h.$ptr(), $sizeof<T.U256>())
    Field.add(i.$ptr(), i.$ptr())
    fieldSquare(i.$ptr())
    let j = T.U256.$make()
    Mem.cpy(j.$ptr(), h.$ptr(), $sizeof<T.U256>())
    Field.mul(j.$ptr(), i.$ptr())
    let r = T.U256.$make()
    Mem.cpy(r.$ptr(), s2.$ptr(), $sizeof<T.U256>())
    Field.sub(r.$ptr(), s1.$ptr())
    Field.add(r.$ptr(), r.$ptr())
    let v = T.U256.$make()
    Mem.cpy(v.$ptr(), u1.$ptr(), $sizeof<T.U256>())
    Field.mul(v.$ptr(), i.$ptr())
    let x3 = T.U256.$make()
    Mem.cpy(x3.$ptr(), r.$ptr(), $sizeof<T.U256>())
    fieldSquare(x3.$ptr())
    Field.sub(x3.$ptr(), j.$ptr())
    let t = T.U256.$make()
    Mem.cpy(t.$ptr(), v.$ptr(), $sizeof<T.U256>())
    Field.add(t.$ptr(), t.$ptr())
    Field.sub(x3.$ptr(), t.$ptr())
    let y3 = T.U256.$make()
    Mem.cpy(y3.$ptr(), v.$ptr(), $sizeof<T.U256>())
    Field.sub(y3.$ptr(), x3.$ptr())
    Field.mul(y3.$ptr(), r.$ptr())
    Mem.cpy(t.$ptr(), s1.$ptr(), $sizeof<T.U256>())
    Field.mul(t.$ptr(), j.$ptr())
    Field.add(t.$ptr(), t.$ptr())
    Field.sub(y3.$ptr(), t.$ptr())
    let z3 = T.U256.$make()
    Mem.cpy(z3.$ptr(), p.$$.z.$ptr(), $sizeof<T.U256>())
    Field.add(z3.$ptr(), q.$$.z.$ptr())
    fieldSquare(z3.$ptr())
    Field.sub(z3.$ptr(), z1z1.$ptr())
    Field.sub(z3.$ptr(), z2z2.$ptr())
    Field.mul(z3.$ptr(), h.$ptr())
    Mem.cpy(p.$$.x.$ptr(), x3.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.$$.y.$ptr(), y3.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.$$.z.$ptr(), z3.$ptr(), $sizeof<T.U256>())
}

function pointAddAffine(p: $$<T.PointJ>, q: $$<T.PointJ>) {
    let z1z1 = T.U256.$make()
    Mem.cpy(z1z1.$ptr(), p.$$.z.$ptr(), $sizeof<T.U256>())
    fieldSquare(z1z1.$ptr())

    let u2 = T.U256.$make()
    Mem.cpy(u2.$ptr(), q.$$.x.$ptr(), $sizeof<T.U256>())
    Field.mul(u2.$ptr(), z1z1.$ptr())

    let s2 = T.U256.$make()
    Mem.cpy(s2.$ptr(), q.$$.y.$ptr(), $sizeof<T.U256>())
    Field.mul(s2.$ptr(), p.$$.z.$ptr())
    Field.mul(s2.$ptr(), z1z1.$ptr())

    let h = T.U256.$make()
    Mem.cpy(h.$ptr(), u2.$ptr(), $sizeof<T.U256>())
    Field.sub(h.$ptr(), p.$$.x.$ptr())

    let hh = T.U256.$make()
    Mem.cpy(hh.$ptr(), h.$ptr(), $sizeof<T.U256>())
    fieldSquare(hh.$ptr())

    // Z3 = (Z1 + H)^2 - Z1^2 - H^2.  Original Z1 is now dead.
    Field.add(p.$$.z.$ptr(), h.$ptr())
    fieldSquare(p.$$.z.$ptr())
    Field.sub(p.$$.z.$ptr(), z1z1.$ptr())
    Field.sub(p.$$.z.$ptr(), hh.$ptr())

    // I = 4*HH, reusing hh.
    Field.add(hh.$ptr(), hh.$ptr())
    Field.add(hh.$ptr(), hh.$ptr())

    // J = H*I, reusing u2.
    Mem.cpy(u2.$ptr(), h.$ptr(), $sizeof<T.U256>())
    Field.mul(u2.$ptr(), hh.$ptr())

    // r = 2*(S2 - Y1), reusing s2.
    Field.sub(s2.$ptr(), p.$$.y.$ptr())
    Field.add(s2.$ptr(), s2.$ptr())

    // 2*Y1*J, reusing z1z1.  Original Y1 is then dead.
    Mem.cpy(z1z1.$ptr(), p.$$.y.$ptr(), $sizeof<T.U256>())
    Field.mul(z1z1.$ptr(), u2.$ptr())
    Field.add(z1z1.$ptr(), z1z1.$ptr())

    // V = X1*I, directly into p.y.  Original X1 is then dead.
    Mem.cpy(p.$$.y.$ptr(), p.$$.x.$ptr(), $sizeof<T.U256>())
    Field.mul(p.$$.y.$ptr(), hh.$ptr())

    // X3 = r^2 - J - 2V, directly into p.x.
    Mem.cpy(p.$$.x.$ptr(), s2.$ptr(), $sizeof<T.U256>())
    fieldSquare(p.$$.x.$ptr())
    Field.sub(p.$$.x.$ptr(), u2.$ptr())
    Mem.cpy(h.$ptr(), p.$$.y.$ptr(), $sizeof<T.U256>())
    Field.add(h.$ptr(), h.$ptr())
    Field.sub(p.$$.x.$ptr(), h.$ptr())

    // Y3 = r*(V - X3) - 2*Y1*J, directly into p.y.
    Field.sub(p.$$.y.$ptr(), p.$$.x.$ptr())
    Field.mul(p.$$.y.$ptr(), s2.$ptr())
    Field.sub(p.$$.y.$ptr(), z1z1.$ptr())
}

function pointDouble(p: $$<T.PointJ>) {
    // delta = Z^2, gamma = Y^2
    let delta = T.U256.$make()
    Mem.cpy(delta.$ptr(), p.$$.z.$ptr(), $sizeof<T.U256>())
    fieldSquare(delta.$ptr())
    let gamma = T.U256.$make()
    Mem.cpy(gamma.$ptr(), p.$$.y.$ptr(), $sizeof<T.U256>())
    fieldSquare(gamma.$ptr())

    // Z3 = (Y + Z)^2 - gamma - delta.  Z is dead after this.
    Field.add(p.$$.z.$ptr(), p.$$.y.$ptr())
    fieldSquare(p.$$.z.$ptr())
    Field.sub(p.$$.z.$ptr(), gamma.$ptr())
    Field.sub(p.$$.z.$ptr(), delta.$ptr())

    // Reuse Y storage for beta = X * gamma.  Original Y is now dead.
    Mem.cpy(p.$$.y.$ptr(), p.$$.x.$ptr(), $sizeof<T.U256>())
    Field.mul(p.$$.y.$ptr(), gamma.$ptr())

    // alpha = 3 * (X - delta) * (X + delta).
    let alpha = T.U256.$make()
    Mem.cpy(alpha.$ptr(), p.$$.x.$ptr(), $sizeof<T.U256>())
    Field.sub(alpha.$ptr(), delta.$ptr())
    Field.add(delta.$ptr(), p.$$.x.$ptr())
    Field.mul(alpha.$ptr(), delta.$ptr())
    Mem.cpy(delta.$ptr(), alpha.$ptr(), $sizeof<T.U256>())
    Field.add(alpha.$ptr(), alpha.$ptr())
    Field.add(alpha.$ptr(), delta.$ptr())

    // X3 = alpha^2 - 8*beta.  Original X is now dead.
    Mem.cpy(p.$$.x.$ptr(), alpha.$ptr(), $sizeof<T.U256>())
    fieldSquare(p.$$.x.$ptr())
    Mem.cpy(delta.$ptr(), p.$$.y.$ptr(), $sizeof<T.U256>())
    Field.add(delta.$ptr(), delta.$ptr())
    Field.add(delta.$ptr(), delta.$ptr())
    Field.add(delta.$ptr(), delta.$ptr())
    Field.sub(p.$$.x.$ptr(), delta.$ptr())

    // Y3 = alpha * (4*beta - X3) - 8*gamma^2.
    Field.add(p.$$.y.$ptr(), p.$$.y.$ptr())
    Field.add(p.$$.y.$ptr(), p.$$.y.$ptr())
    Field.sub(p.$$.y.$ptr(), p.$$.x.$ptr())
    Field.mul(p.$$.y.$ptr(), alpha.$ptr())
    fieldSquare(gamma.$ptr())
    Field.add(gamma.$ptr(), gamma.$ptr())
    Field.add(gamma.$ptr(), gamma.$ptr())
    Field.add(gamma.$ptr(), gamma.$ptr())
    Field.sub(p.$$.y.$ptr(), gamma.$ptr())
}

function pointMul(k: T.U256_Ref, p: $$<T.PointJ>) {
    let base = T.PointJ.$make()
    Mem.cpy(base.x.$ptr(), p.$$.x.$ptr(), $sizeof<T.U256>())
    Mem.cpy(base.y.$ptr(), p.$$.y.$ptr(), $sizeof<T.U256>())
    Mem.cpy(base.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())
    let neg = T.PointJ.$make()
    Mem.cpy(neg.x.$ptr(), base.x.$ptr(), $sizeof<T.U256>())
    for (const i of $range(T.U256_LEN)) neg.y[i] = 0
    Field.sub(neg.y.$ptr(), base.y.$ptr())
    Mem.cpy(neg.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())
    let n = T.U256.$make()
    Mem.cpy(n.$ptr(), k, $sizeof<T.U256>())
    let naf = T.NAF257.$make()
    let nbits: u32 = 0
    while (!scalarIsZero(n.$ptr())) {
        if ((n[0] & 1) != 0) {
            const d: i8 = ((n[0] & 3) == 1) ? 1 : -1
            naf[nbits] = d
            if (d > 0) scalarSubOne(n.$ptr())
            else scalarAddOne(n.$ptr())
        }
        scalarShiftRight(n.$ptr())
        nbits += 1
    }
    let r = T.PointJ.$make()
    let have = false
    for (let i = $cast2<i32>(nbits) - 1; i >= 0; i -= 1) {
        if (have) pointDouble($$(r))
        const d = naf[i]
        if (d == 0) continue
        const q = d > 0 ? $$(base) : $$(neg)
        if (!have) {
            Mem.cpy(r.x.$ptr(), q.$$.x.$ptr(), $sizeof<T.U256>())
            Mem.cpy(r.y.$ptr(), q.$$.y.$ptr(), $sizeof<T.U256>())
            Mem.cpy(r.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())
            have = true
        } else {
            pointAddAffine($$(r), q)
        }
    }
    Mem.cpy(p.$$.x.$ptr(), r.x.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.$$.y.$ptr(), r.y.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.$$.z.$ptr(), r.z.$ptr(), $sizeof<T.U256>())
}

function scalarAddOne(a: T.U256_Ref) {
    for (const i of $range(T.U256_LEN)) {
        a[i] += 1
        if (a[i] != 0) return
    }
}

function scalarIsZero(a: T.U256_Ref): bool_t {
    for (const i of $range(T.U256_LEN)) if (a[i] != 0) return false
    return true
}

function scalarShiftRight(a: T.U256_Ref) {
    let carry: u32 = 0
    for (const i of $range(T.U256_LEN - 1, -1, -1)) {
        const next = a[i] << 31
        a[i] = (a[i] >> 1) | carry
        carry = next
    }
}

function scalarSubOne(a: T.U256_Ref) {
    for (const i of $range(T.U256_LEN)) {
        const v = a[i]
        a[i] -= 1
        if (v != 0) return
    }
}

function pointToAffine(p: $$<T.PointJ>) {
    let zi = T.U256.$make()
    Mem.cpy(zi.$ptr(), p.$$.z.$ptr(), $sizeof<T.U256>())
    fieldInv(zi.$ptr())
    let zi2 = T.U256.$make()
    Mem.cpy(zi2.$ptr(), zi.$ptr(), $sizeof<T.U256>())
    fieldSquare(zi2.$ptr())
    Field.mul(p.$$.x.$ptr(), zi2.$ptr())
    Field.mul(zi2.$ptr(), zi.$ptr())
    Field.mul(p.$$.y.$ptr(), zi2.$ptr())
    fieldFromMont(p.$$.x.$ptr())
    fieldFromMont(p.$$.y.$ptr())
    for (const i of $range(T.U256_LEN)) p.$$.z[i] = 0
    p.$$.z[0] = 1
}

// TEST FUNCTIONS
function testField() {
    let a = T.U256.$make()
    let b = T.U256.$make()
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(b.$ptr(), B_TEST.$ptr(), $sizeof<T.U256>())
    print(a.$ptr(), t$`a0`)
    print(b.$ptr(), t$`b0`)
    Field.add(a.$ptr(), b.$ptr())
    print(a.$ptr(), t$`a1`)
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<T.U256>())
    Field.sub(a.$ptr(), b.$ptr())
    print(a.$ptr(), t$`a2`)
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<T.U256>())
    Field.mul(a.$ptr(), b.$ptr())
    print(a.$ptr(), t$`a3`)
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<T.U256>())
    fieldSquare(a.$ptr())
    print(a.$ptr(), t$`a4`)
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<T.U256>())
    fieldInv(a.$ptr())
    print(a.$ptr(), t$`a5`)
}

function testPoint() {
    let sk = T.U256.$make()
    Mem.cpy(sk.$ptr(), K_TEST.$ptr(), $sizeof<T.U256>())
    let peer = T.PubKey.$make()
    Mem.cpy(peer.x.$ptr(), PEER_X_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(peer.y.$ptr(), PEER_Y_TEST.$ptr(), $sizeof<T.U256>())
    let secret = T.U256.$make()
    $['%%d+']
    ecdh(sk, $$(peer), secret.$ptr())
    $['%%d-']
    print(secret.$ptr(), t$`secret`)
}


function testMontMulM4() {
    let a = T.U256.$make()
    let b = T.U256.$make()
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(b.$ptr(), B_TEST.$ptr(), $sizeof<T.U256>())

    fieldToMont(a.$ptr())
    fieldToMont(b.$ptr())

    $['%%d+']
    for (const i of $range(4096)) {
        fieldMontMulM4(a.$ptr(), b.$ptr())
    }
    $['%%d-']

    print(a.$ptr(), t$`mont4096`)
}


function testPointOps() {
    let p = T.PointJ.$make()
    let q = T.PointJ.$make()

    Mem.cpy(p.x.$ptr(), G_X_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<T.U256>())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())

    Mem.cpy(q.x.$ptr(), G_X_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(q.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<T.U256>())
    fieldToMont(q.x.$ptr())
    fieldToMont(q.y.$ptr())
    Mem.cpy(q.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())

    $['%%d+']
    for (const i of $range(1024)) {
        pointDouble($$(p))
    }
    $['%%d-']
    print(p.x.$ptr(), t$`double1024`)

    // Reinitialize p so the add benchmark starts from a stable valid point.
    Mem.cpy(p.x.$ptr(), G_X_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<T.U256>())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())

    $['%%d+']
    for (const i of $range(1024)) {
        pointAddAffine($$(p), $$(q))
    }
    $['%%d-']
    print(p.x.$ptr(), t$`add1024`)
}


function testFieldOps() {
    let a = T.U256.$make()
    let b = T.U256.$make()

    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(b.$ptr(), B_TEST.$ptr(), $sizeof<T.U256>())
    fieldToMont(a.$ptr())
    fieldToMont(b.$ptr())

    $['%%d+']
    for (const i of $range(16384)) {
        Field.add(a.$ptr(), b.$ptr())
    }
    $['%%d-']
    print(a.$ptr(), t$`add16384`)

    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<T.U256>())
    fieldToMont(a.$ptr())

    $['%%d+']
    for (const i of $range(16384)) {
        Field.sub(a.$ptr(), b.$ptr())
    }
    $['%%d-']
    print(a.$ptr(), t$`sub16384`)
}

function testPointOpsValid() {
    let p = T.PointJ.$make()
    let q = T.PointJ.$make()

    // q = G, in Montgomery form.
    Mem.cpy(q.x.$ptr(), G_X_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(q.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<T.U256>())
    fieldToMont(q.x.$ptr())
    fieldToMont(q.y.$ptr())
    Mem.cpy(q.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())

    // p = G, then make p = 2G before the timed add loop.
    Mem.cpy(p.x.$ptr(), q.x.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.y.$ptr(), q.y.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())

    $['%%d+']
    for (const i of $range(1024)) {
        pointDouble($$(p))
    }
    $['%%d-']
    print(p.x.$ptr(), t$`double1024`)

    // Reinitialize and form 2G outside the timed region.
    Mem.cpy(p.x.$ptr(), q.x.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.y.$ptr(), q.y.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<T.U256>())
    pointDouble($$(p))

    $['%%d+']
    for (const i of $range(1024)) {
        pointAddAffine($$(p), $$(q))
    }
    $['%%d-']
    print(p.x.$ptr(), t$`add1024`)
}

export function em$run() {
    testFieldOps()
    testPointOpsValid()
}
