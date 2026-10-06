import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as Mem from '@em.utils/Mem.em'

const U256_LEN = 8
type U256_BASE = u32

export class U256 extends $vector<U256_BASE> { $len = U256_LEN }
class U512 extends $vector<U256_BASE> { $len = 16 }
export type U256_Ref = ptr_t<U256_BASE>

export class PubKey extends $struct {
    x: U256
    y: U256
}

class PointJ extends $struct {
    x: U256
    y: U256
    z: U256
}

const FIELD_PRIME = $config<U256>()
const FIELD_PRIME_M2 = $config<U256>()
const A_TEST = $config<U256>()
const B_TEST = $config<U256>()
const G_X_TEST = $config<U256>()
const G_Y_TEST = $config<U256>()
const K_TEST = $config<U256>()
const PEER_X_TEST = $config<U256>()
const PEER_Y_TEST = $config<U256>()

export namespace em$meta {
    export function em$construct() {
        initU256(FIELD_PRIME.$$val, 'ffffffff_00000001_00000000_00000000_00000000_ffffffff_ffffffff_ffffffff')
        initU256(FIELD_PRIME_M2.$$val, 'ffffffff_00000001_00000000_00000000_00000000_ffffffff_ffffffff_fffffffd')
        initU256(A_TEST.$$val, '11111111_22222222_33333333_44444444_55555555_66666666_77777777_88888888')
        initU256(B_TEST.$$val, '01020304_05060708_090a0b0c_0d0e0f10_11121314_15161718_191a1b1c_1d1e1f20')
        initU256(G_X_TEST.$$val, '6b17d1f2_e12c4247_f8bce6e5_63a440f2_77037d81_2deb33a0_f4a13945_d898c296')
        initU256(G_Y_TEST.$$val, '4fe342e2_fe1a7f9b_8ee7eb4a_7c0f9e16_2bce3357_6b315ece_cbb64068_37bf51f5')
        initU256(K_TEST.$$val, 'c88f01f5_10d9ac3f_70a292da_a2316de5_44e9aab8_afe84049_c62a9c57_862d1433')
        initU256(PEER_X_TEST.$$val, 'd12dfb52_89c8d4f8_1208b702_70398c34_2296970a_0bccb74c_736fc755_4494bf63')
        initU256(PEER_Y_TEST.$$val, '56fbf3ca_366cc23e_8157854c_13c58d6a_ac23f046_ada30f83_53e74f33_039872ab')
    }
    function initU256(u: U256, val: string) {
        let limbs = val.split('_')
        for (const i of $range(U256_LEN)) {
            u[U256_LEN - i - 1] = Number.parseInt(limbs[i], 16) >>> 0
        }
    }
}

//>> ---- em$targ ---- <<//

export function validatePublicKey(pk: $$<PubKey>): bool_t {
    return true
}

export function makePublicKey(sk: U256, pk_OUT: $$<PubKey>) {
    let p = PointJ.$make()
    Mem.cpy(p.x.$ptr(), G_X_TEST.$ptr(), $sizeof<U256>())
    Mem.cpy(p.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<U256>())
    p.z[0] = 1
    pointMul(sk.$ptr(), $$(p))
    pointToAffine($$(p))
    Mem.cpy(pk_OUT.$$.x.$ptr(), p.x.$ptr(), $sizeof<U256>())
    Mem.cpy(pk_OUT.$$.y.$ptr(), p.y.$ptr(), $sizeof<U256>())
}

export function ecdh(sk: U256, peer_pk: $$<PubKey>, secret_OUT: U256_Ref) {
    let p = PointJ.$make()
    Mem.cpy(p.x.$ptr(), peer_pk.$$.x.$ptr(), $sizeof<U256>())
    Mem.cpy(p.y.$ptr(), peer_pk.$$.y.$ptr(), $sizeof<U256>())
    p.z[0] = 1
    $['%%a+']
    pointMul(sk.$ptr(), $$(p))
    $['%%a-']
    $['%%c+']
    pointToAffine($$(p))
    $['%%c-']
    Mem.cpy(secret_OUT, p.x.$ptr(), $sizeof<U256>())
}

export function print(uref: U256_Ref, lab: text_t = t$``) {
    if (lab.$len > 0) {
        printf`%s = `(lab)
    }
    let sep = t$``
    for (const i of $range(U256_LEN - 1, -1, -1)) {
        printf`%s%08x`(sep, uref[i])
        sep = t$`_`
    }
    printf`\n`()
}

// FIELD FUNCTIONS
function fieldAdd(a: U256_Ref, b: U256_Ref) {
    let t = U256.$make()
    let borrow: u64 = 0
    for (const i of $range(U256_LEN)) {
        const pi = $cast2<u64>(FIELD_PRIME[i])
        const bi = $cast2<u64>(b[i])
        const d = pi - bi - borrow
        t[i] = $cast2<u32>(d)
        borrow = pi < (bi + borrow) ? 1 : 0
    }
    let ge = true
    let decided = false
    for (const i of $range(U256_LEN - 1, -1, -1)) {
        if (!decided && a[i] != t[i]) {
            ge = a[i] > t[i]
            decided = true
        }
    }
    if (ge) {
        borrow = 0
        for (const i of $range(U256_LEN)) {
            const ai = $cast2<u64>(a[i])
            const ti = $cast2<u64>(t[i])
            const d = ai - ti - borrow
            a[i] = $cast2<u32>(d)
            borrow = ai < (ti + borrow) ? 1 : 0
        }
    } else {
        let carry: u64 = 0
        for (const i of $range(U256_LEN)) {
            const s = $cast2<u64>(a[i]) + $cast2<u64>(b[i]) + carry
            a[i] = $cast2<u32>(s)
            carry = s >> 32
        }
    }
}

function fieldInv(a: U256_Ref) {
    let x = U256.$make()
    Mem.cpy(x.$ptr(), a, $sizeof<U256>())
    let x2 = U256.$make()
    Mem.cpy(x2.$ptr(), x.$ptr(), $sizeof<U256>())
    fieldSquare(x2.$ptr())
    let x4 = U256.$make()
    Mem.cpy(x4.$ptr(), x2.$ptr(), $sizeof<U256>())
    fieldSquare(x4.$ptr())
    let x8 = U256.$make()
    Mem.cpy(x8.$ptr(), x4.$ptr(), $sizeof<U256>())
    fieldSquare(x8.$ptr())
    let x13 = U256.$make()
    Mem.cpy(x13.$ptr(), x8.$ptr(), $sizeof<U256>())
    fieldMul(x13.$ptr(), x4.$ptr())
    fieldMul(x13.$ptr(), x.$ptr())
    let x15 = U256.$make()
    Mem.cpy(x15.$ptr(), x13.$ptr(), $sizeof<U256>())
    fieldMul(x15.$ptr(), x2.$ptr())
    let r = U256.$make()
    Mem.cpy(r.$ptr(), x15.$ptr(), $sizeof<U256>())
    let first = true
    for (const i of $range(U256_LEN - 1, -1, -1)) {
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
                fieldMul(r.$ptr(), x.$ptr())
            } else if (n == 13) {
                fieldMul(r.$ptr(), x13.$ptr())
            } else if (n == 15) {
                fieldMul(r.$ptr(), x15.$ptr())
            }
        }
    }
    Mem.cpy(a, r.$ptr(), $sizeof<U256>())
}

function fieldMul(a: U256_Ref, b: U256_Ref) {
    let aa = U256.$make()
    let bb = U256.$make()
    let prod = U512.$make()
    Mem.cpy(aa.$ptr(), a, $sizeof<U256>())
    Mem.cpy(bb.$ptr(), b, $sizeof<U256>())
    for (const i of $range(U256_LEN)) {
        let carry: u64 = 0
        for (const j of $range(U256_LEN)) {
            const k = i + j
            const z = $cast2<u64>(prod[k]) + $cast2<u64>(aa[i]) * $cast2<u64>(bb[j]) + carry
            prod[k] = $cast2<u32>(z)
            carry = z >> 32
        }
        prod[i + U256_LEN] = $cast2<u32>(carry)
    }
    for (const i of $range(U256_LEN)) a[i] = prod[i]
    let t = U256.$make()
    t[0] = 0; t[1] = 0; t[2] = 0; t[3] = prod[11]
    t[4] = prod[12]; t[5] = prod[13]; t[6] = prod[14]; t[7] = prod[15]
    fieldAdd(a, t.$ptr())
    fieldAdd(a, t.$ptr())
    t[0] = 0; t[1] = 0; t[2] = 0; t[3] = prod[12]
    t[4] = prod[13]; t[5] = prod[14]; t[6] = prod[15]; t[7] = 0
    fieldAdd(a, t.$ptr())
    fieldAdd(a, t.$ptr())
    t[0] = prod[8]; t[1] = prod[9]; t[2] = prod[10]; t[3] = 0
    t[4] = 0; t[5] = 0; t[6] = prod[14]; t[7] = prod[15]
    fieldAdd(a, t.$ptr())
    t[0] = prod[9]; t[1] = prod[10]; t[2] = prod[11]; t[3] = prod[13]
    t[4] = prod[14]; t[5] = prod[15]; t[6] = prod[13]; t[7] = prod[8]
    fieldAdd(a, t.$ptr())
    t[0] = prod[11]; t[1] = prod[12]; t[2] = prod[13]; t[3] = 0
    t[4] = 0; t[5] = 0; t[6] = prod[8]; t[7] = prod[10]
    fieldSub(a, t.$ptr())
    t[0] = prod[12]; t[1] = prod[13]; t[2] = prod[14]; t[3] = prod[15]
    t[4] = 0; t[5] = 0; t[6] = prod[9]; t[7] = prod[11]
    fieldSub(a, t.$ptr())
    t[0] = prod[13]; t[1] = prod[14]; t[2] = prod[15]; t[3] = prod[8]
    t[4] = prod[9]; t[5] = prod[10]; t[6] = 0; t[7] = prod[12]
    fieldSub(a, t.$ptr())
    t[0] = prod[14]; t[1] = prod[15]; t[2] = 0; t[3] = prod[9]
    t[4] = prod[10]; t[5] = prod[11]; t[6] = 0; t[7] = prod[13]
    fieldSub(a, t.$ptr())
}

function fieldSquare(a: U256_Ref) {
    let t = U256.$make()
    Mem.cpy(t.$ptr(), a, $sizeof<U256>())
    fieldMul(a, t.$ptr())
}

function fieldSub(a: U256_Ref, b: U256_Ref) {
    let borrow: u64 = 0
    for (const i of $range(U256_LEN)) {
        const ai = $cast2<u64>(a[i])
        const bi = $cast2<u64>(b[i])
        const d = ai - bi - borrow
        a[i] = $cast2<u32>(d)
        borrow = ai < (bi + borrow) ? 1 : 0
    }
    if (borrow != 0) {
        let carry: u64 = 0
        for (const i of $range(U256_LEN)) {
            const s = $cast2<u64>(a[i]) + $cast2<u64>(FIELD_PRIME[i]) + carry
            a[i] = $cast2<u32>(s)
            carry = s >> 32
        }
    }
}

// POINT FUNCTIONS
function pointAdd(p: $$<PointJ>, q: $$<PointJ>) {
    let z1z1 = U256.$make()
    Mem.cpy(z1z1.$ptr(), p.$$.z.$ptr(), $sizeof<U256>())
    fieldSquare(z1z1.$ptr())
    let z2z2 = U256.$make()
    Mem.cpy(z2z2.$ptr(), q.$$.z.$ptr(), $sizeof<U256>())
    fieldSquare(z2z2.$ptr())
    let u1 = U256.$make()
    Mem.cpy(u1.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    fieldMul(u1.$ptr(), z2z2.$ptr())
    let u2 = U256.$make()
    Mem.cpy(u2.$ptr(), q.$$.x.$ptr(), $sizeof<U256>())
    fieldMul(u2.$ptr(), z1z1.$ptr())
    let s1 = U256.$make()
    Mem.cpy(s1.$ptr(), z2z2.$ptr(), $sizeof<U256>())
    fieldMul(s1.$ptr(), q.$$.z.$ptr())
    fieldMul(s1.$ptr(), p.$$.y.$ptr())
    let s2 = U256.$make()
    Mem.cpy(s2.$ptr(), z1z1.$ptr(), $sizeof<U256>())
    fieldMul(s2.$ptr(), p.$$.z.$ptr())
    fieldMul(s2.$ptr(), q.$$.y.$ptr())
    let h = U256.$make()
    Mem.cpy(h.$ptr(), u2.$ptr(), $sizeof<U256>())
    fieldSub(h.$ptr(), u1.$ptr())
    let i = U256.$make()
    Mem.cpy(i.$ptr(), h.$ptr(), $sizeof<U256>())
    fieldAdd(i.$ptr(), i.$ptr())
    fieldSquare(i.$ptr())
    let j = U256.$make()
    Mem.cpy(j.$ptr(), h.$ptr(), $sizeof<U256>())
    fieldMul(j.$ptr(), i.$ptr())
    let r = U256.$make()
    Mem.cpy(r.$ptr(), s2.$ptr(), $sizeof<U256>())
    fieldSub(r.$ptr(), s1.$ptr())
    fieldAdd(r.$ptr(), r.$ptr())
    let v = U256.$make()
    Mem.cpy(v.$ptr(), u1.$ptr(), $sizeof<U256>())
    fieldMul(v.$ptr(), i.$ptr())
    let x3 = U256.$make()
    Mem.cpy(x3.$ptr(), r.$ptr(), $sizeof<U256>())
    fieldSquare(x3.$ptr())
    fieldSub(x3.$ptr(), j.$ptr())
    let t = U256.$make()
    Mem.cpy(t.$ptr(), v.$ptr(), $sizeof<U256>())
    fieldAdd(t.$ptr(), t.$ptr())
    fieldSub(x3.$ptr(), t.$ptr())
    let y3 = U256.$make()
    Mem.cpy(y3.$ptr(), v.$ptr(), $sizeof<U256>())
    fieldSub(y3.$ptr(), x3.$ptr())
    fieldMul(y3.$ptr(), r.$ptr())
    Mem.cpy(t.$ptr(), s1.$ptr(), $sizeof<U256>())
    fieldMul(t.$ptr(), j.$ptr())
    fieldAdd(t.$ptr(), t.$ptr())
    fieldSub(y3.$ptr(), t.$ptr())
    let z3 = U256.$make()
    Mem.cpy(z3.$ptr(), p.$$.z.$ptr(), $sizeof<U256>())
    fieldAdd(z3.$ptr(), q.$$.z.$ptr())
    fieldSquare(z3.$ptr())
    fieldSub(z3.$ptr(), z1z1.$ptr())
    fieldSub(z3.$ptr(), z2z2.$ptr())
    fieldMul(z3.$ptr(), h.$ptr())
    Mem.cpy(p.$$.x.$ptr(), x3.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.y.$ptr(), y3.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.z.$ptr(), z3.$ptr(), $sizeof<U256>())
}

function pointAddAffine(p: $$<PointJ>, q: $$<PointJ>) {
    let z1z1 = U256.$make()
    Mem.cpy(z1z1.$ptr(), p.$$.z.$ptr(), $sizeof<U256>())
    fieldSquare(z1z1.$ptr())
    let u2 = U256.$make()
    Mem.cpy(u2.$ptr(), q.$$.x.$ptr(), $sizeof<U256>())
    fieldMul(u2.$ptr(), z1z1.$ptr())
    let s2 = U256.$make()
    Mem.cpy(s2.$ptr(), q.$$.y.$ptr(), $sizeof<U256>())
    fieldMul(s2.$ptr(), p.$$.z.$ptr())
    fieldMul(s2.$ptr(), z1z1.$ptr())
    let h = U256.$make()
    Mem.cpy(h.$ptr(), u2.$ptr(), $sizeof<U256>())
    fieldSub(h.$ptr(), p.$$.x.$ptr())
    let hh = U256.$make()
    Mem.cpy(hh.$ptr(), h.$ptr(), $sizeof<U256>())
    fieldSquare(hh.$ptr())
    let i = U256.$make()
    Mem.cpy(i.$ptr(), hh.$ptr(), $sizeof<U256>())
    fieldAdd(i.$ptr(), i.$ptr())
    fieldAdd(i.$ptr(), i.$ptr())
    let j = U256.$make()
    Mem.cpy(j.$ptr(), h.$ptr(), $sizeof<U256>())
    fieldMul(j.$ptr(), i.$ptr())
    let r = U256.$make()
    Mem.cpy(r.$ptr(), s2.$ptr(), $sizeof<U256>())
    fieldSub(r.$ptr(), p.$$.y.$ptr())
    fieldAdd(r.$ptr(), r.$ptr())
    let v = U256.$make()
    Mem.cpy(v.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    fieldMul(v.$ptr(), i.$ptr())
    let x3 = U256.$make()
    Mem.cpy(x3.$ptr(), r.$ptr(), $sizeof<U256>())
    fieldSquare(x3.$ptr())
    fieldSub(x3.$ptr(), j.$ptr())
    let t = U256.$make()
    Mem.cpy(t.$ptr(), v.$ptr(), $sizeof<U256>())
    fieldAdd(t.$ptr(), t.$ptr())
    fieldSub(x3.$ptr(), t.$ptr())
    let y3 = U256.$make()
    Mem.cpy(y3.$ptr(), v.$ptr(), $sizeof<U256>())
    fieldSub(y3.$ptr(), x3.$ptr())
    fieldMul(y3.$ptr(), r.$ptr())
    Mem.cpy(t.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    fieldMul(t.$ptr(), j.$ptr())
    fieldAdd(t.$ptr(), t.$ptr())
    fieldSub(y3.$ptr(), t.$ptr())
    let z3 = U256.$make()
    Mem.cpy(z3.$ptr(), p.$$.z.$ptr(), $sizeof<U256>())
    fieldAdd(z3.$ptr(), h.$ptr())
    fieldSquare(z3.$ptr())
    fieldSub(z3.$ptr(), z1z1.$ptr())
    fieldSub(z3.$ptr(), hh.$ptr())
    Mem.cpy(p.$$.x.$ptr(), x3.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.y.$ptr(), y3.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.z.$ptr(), z3.$ptr(), $sizeof<U256>())
}

function pointDouble(p: $$<PointJ>) {
    let delta = U256.$make()
    Mem.cpy(delta.$ptr(), p.$$.z.$ptr(), $sizeof<U256>())
    fieldSquare(delta.$ptr())
    let gamma = U256.$make()
    Mem.cpy(gamma.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    fieldSquare(gamma.$ptr())
    let beta = U256.$make()
    Mem.cpy(beta.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    fieldMul(beta.$ptr(), gamma.$ptr())
    let alpha = U256.$make()
    Mem.cpy(alpha.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    fieldSub(alpha.$ptr(), delta.$ptr())
    let t = U256.$make()
    Mem.cpy(t.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    fieldAdd(t.$ptr(), delta.$ptr())
    fieldMul(alpha.$ptr(), t.$ptr())
    Mem.cpy(t.$ptr(), alpha.$ptr(), $sizeof<U256>())
    fieldAdd(alpha.$ptr(), alpha.$ptr())
    fieldAdd(alpha.$ptr(), t.$ptr())
    let x3 = U256.$make()
    Mem.cpy(x3.$ptr(), alpha.$ptr(), $sizeof<U256>())
    fieldSquare(x3.$ptr())
    let beta8 = U256.$make()
    Mem.cpy(beta8.$ptr(), beta.$ptr(), $sizeof<U256>())
    fieldAdd(beta8.$ptr(), beta8.$ptr())
    fieldAdd(beta8.$ptr(), beta8.$ptr())
    fieldAdd(beta8.$ptr(), beta8.$ptr())
    fieldSub(x3.$ptr(), beta8.$ptr())
    let z3 = U256.$make()
    Mem.cpy(z3.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    fieldAdd(z3.$ptr(), p.$$.z.$ptr())
    fieldSquare(z3.$ptr())
    fieldSub(z3.$ptr(), gamma.$ptr())
    fieldSub(z3.$ptr(), delta.$ptr())
    let beta4 = U256.$make()
    Mem.cpy(beta4.$ptr(), beta.$ptr(), $sizeof<U256>())
    fieldAdd(beta4.$ptr(), beta4.$ptr())
    fieldAdd(beta4.$ptr(), beta4.$ptr())
    fieldSub(beta4.$ptr(), x3.$ptr())
    fieldMul(alpha.$ptr(), beta4.$ptr())
    let gamma8 = U256.$make()
    Mem.cpy(gamma8.$ptr(), gamma.$ptr(), $sizeof<U256>())
    fieldSquare(gamma8.$ptr())
    fieldAdd(gamma8.$ptr(), gamma8.$ptr())
    fieldAdd(gamma8.$ptr(), gamma8.$ptr())
    fieldAdd(gamma8.$ptr(), gamma8.$ptr())
    fieldSub(alpha.$ptr(), gamma8.$ptr())
    Mem.cpy(p.$$.x.$ptr(), x3.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.y.$ptr(), alpha.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.z.$ptr(), z3.$ptr(), $sizeof<U256>())
}

function pointMul(k: U256_Ref, p: $$<PointJ>) {
    let base = PointJ.$make()
    Mem.cpy(base.x.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    Mem.cpy(base.y.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    base.z[0] = 1
    let r = PointJ.$make()
    let have = false
    for (const i of $range(U256_LEN - 1, -1, -1)) {
        for (const j of $range(31, -1, -1)) {
            const bit = (k[i] & (1 << j)) != 0
            if (!have) {
                if (bit) {
                    Mem.cpy(r.x.$ptr(), base.x.$ptr(), $sizeof<U256>())
                    Mem.cpy(r.y.$ptr(), base.y.$ptr(), $sizeof<U256>())
                    r.z[0] = 1
                    have = true
                }
                continue
            }
            pointDouble($$(r))
            if (bit) pointAddAffine($$(r), $$(base))
        }
    }
    Mem.cpy(p.$$.x.$ptr(), r.x.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.y.$ptr(), r.y.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.z.$ptr(), r.z.$ptr(), $sizeof<U256>())
}

function pointToAffine(p: $$<PointJ>) {
    let zi = U256.$make()
    Mem.cpy(zi.$ptr(), p.$$.z.$ptr(), $sizeof<U256>())
    fieldInv(zi.$ptr())
    let zi2 = U256.$make()
    Mem.cpy(zi2.$ptr(), zi.$ptr(), $sizeof<U256>())
    fieldSquare(zi2.$ptr())
    fieldMul(p.$$.x.$ptr(), zi2.$ptr())
    fieldMul(zi2.$ptr(), zi.$ptr())
    fieldMul(p.$$.y.$ptr(), zi2.$ptr())
    for (const i of $range(U256_LEN)) p.$$.z[i] = 0
    p.$$.z[0] = 1
}

// TEST FUNCTIONS
function testField() {
    let a = U256.$make()
    let b = U256.$make()
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<U256>())
    Mem.cpy(b.$ptr(), B_TEST.$ptr(), $sizeof<U256>())
    print(a.$ptr(), t$`a0`)
    print(b.$ptr(), t$`b0`)
    fieldAdd(a.$ptr(), b.$ptr())
    print(a.$ptr(), t$`a1`)
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<U256>())
    fieldSub(a.$ptr(), b.$ptr())
    print(a.$ptr(), t$`a2`)
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<U256>())
    fieldMul(a.$ptr(), b.$ptr())
    print(a.$ptr(), t$`a3`)
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<U256>())
    fieldSquare(a.$ptr())
    print(a.$ptr(), t$`a4`)
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<U256>())
    fieldInv(a.$ptr())
    print(a.$ptr(), t$`a5`)
}

function testPoint() {
    let sk = U256.$make()
    Mem.cpy(sk.$ptr(), K_TEST.$ptr(), $sizeof<U256>())
    let peer = PubKey.$make()
    Mem.cpy(peer.x.$ptr(), PEER_X_TEST.$ptr(), $sizeof<U256>())
    Mem.cpy(peer.y.$ptr(), PEER_Y_TEST.$ptr(), $sizeof<U256>())
    let secret = U256.$make()
    $['%%d+']
    ecdh(sk, $$(peer), secret.$ptr())
    $['%%d-']
    print(secret.$ptr(), t$`secret`)
}

export function em$run() {
    testPoint()
}
