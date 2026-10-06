import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'

const U256_LEN = 8
type U256_BASE = u32

export class U256 extends $vector<U256_BASE> { $len = U256_LEN }
class NAF257 extends $vector<i8> { $len = 257 }

export type U256_Ref = ptr_t<U256_BASE>
export type MontMulFxn = cb_t<[U256_Ref, U256_Ref]>

export const montMul = $config<MontMulFxn>()

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
const MONT_R = $config<U256>()
const MONT_R2 = $config<U256>()
const MONT_ONE = $config<U256>()
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
        initU256(MONT_R.$$val, '00000000_fffffffe_ffffffff_ffffffff_ffffffff_00000000_00000000_00000001')
        initU256(MONT_R2.$$val, '00000004_fffffffd_ffffffff_fffffffe_fffffffb_ffffffff_00000000_00000003')
        initU256(MONT_ONE.$$val, '00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000001')
        initU256(A_TEST.$$val, '11111111_22222222_33333333_44444444_55555555_66666666_77777777_88888888')
        initU256(B_TEST.$$val, '01020304_05060708_090a0b0c_0d0e0f10_11121314_15161718_191a1b1c_1d1e1f20')
        initU256(G_X_TEST.$$val, '6b17d1f2_e12c4247_f8bce6e5_63a440f2_77037d81_2deb33a0_f4a13945_d898c296')
        initU256(G_Y_TEST.$$val, '4fe342e2_fe1a7f9b_8ee7eb4a_7c0f9e16_2bce3357_6b315ece_cbb64068_37bf51f5')
        initU256(K_TEST.$$val, 'c88f01f5_10d9ac3f_70a292da_a2316de5_44e9aab8_afe84049_c62a9c57_862d1433')
        initU256(PEER_X_TEST.$$val, 'd12dfb52_89c8d4f8_1208b702_70398c34_2296970a_0bccb74c_736fc755_4494bf63')
        initU256(PEER_Y_TEST.$$val, '56fbf3ca_366cc23e_8157854c_13c58d6a_ac23f046_ada30f83_53e74f33_039872ab')
        if ((montMul.$$val as any).fname === undefined) montMul.$$val = $cb(fieldMontMulM4)
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
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<U256>())
    pointMul(sk.$ptr(), $$(p))
    pointToAffine($$(p))
    Mem.cpy(pk_OUT.$$.x.$ptr(), p.x.$ptr(), $sizeof<U256>())
    Mem.cpy(pk_OUT.$$.y.$ptr(), p.y.$ptr(), $sizeof<U256>())
}

export function ecdh(sk: U256, peer_pk: $$<PubKey>, secret_OUT: U256_Ref) {
    let p = PointJ.$make()
    Mem.cpy(p.x.$ptr(), peer_pk.$$.x.$ptr(), $sizeof<U256>())
    Mem.cpy(p.y.$ptr(), peer_pk.$$.y.$ptr(), $sizeof<U256>())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<U256>())
    pointMul(sk.$ptr(), $$(p))
    pointToAffine($$(p))
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
    let carry: u64 = 0
    for (const i of $range(U256_LEN)) {
        const s = $cast2<u64>(a[i]) + $cast2<u64>(b[i]) + carry
        a[i] = $cast2<u32>(s)
        carry = s >> 32
    }
    let reduce = carry != 0
    if (!reduce) {
        for (const i of $range(U256_LEN - 1, -1, -1)) {
            if (a[i] != FIELD_PRIME[i]) {
                reduce = a[i] > FIELD_PRIME[i]
                break
            }
            if (i == 0) reduce = true
        }
    }
    if (reduce) {
        let borrow: u64 = 0
        for (const i of $range(U256_LEN)) {
            const ai = $cast2<u64>(a[i])
            const pi = $cast2<u64>(FIELD_PRIME[i])
            const d = ai - pi - borrow
            a[i] = $cast2<u32>(d)
            borrow = ai < (pi + borrow) ? 1 : 0
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

function fieldToMont(a: U256_Ref) {
    fieldMul(a, MONT_R2.$ptr())
}

function fieldFromMont(a: U256_Ref) {
    fieldMul(a, MONT_ONE.$ptr())
}

function fieldMul(a: U256_Ref, b: U256_Ref) {
    montMul(a, b)
}

// Portable CIOS Montgomery multiplication.
// Inputs/outputs are Montgomery residues; n0' = 1 because p[0] = 0xffffffff.
function fieldMontMulPortable(a: U256_Ref, b: U256_Ref) {
    let t0: u32 = 0
    let t1: u32 = 0
    let t2: u32 = 0
    let t3: u32 = 0
    let t4: u32 = 0
    let t5: u32 = 0
    let t6: u32 = 0
    let t7: u32 = 0
    let t8: u32 = 0
    let t9: u32 = 0

    let carry: u64 = 0
    let z: u64 = 0
    let m: u32 = 0

    // Round 0
    const bi0 = b[0]
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(a[0]) * $cast2<u64>(bi0) + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(a[1]) * $cast2<u64>(bi0) + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(a[2]) * $cast2<u64>(bi0) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + $cast2<u64>(a[3]) * $cast2<u64>(bi0) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + $cast2<u64>(a[4]) * $cast2<u64>(bi0) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + $cast2<u64>(a[5]) * $cast2<u64>(bi0) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(a[6]) * $cast2<u64>(bi0) + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(a[7]) * $cast2<u64>(bi0) + carry
    t7 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t8 = $cast2<u32>(z)
    t9 = $cast2<u32>(z >> 32)

    m = t0
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(m) * 0xffffffff + carry
    carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(m) * 0xffffffff + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(m) * 0xffffffff + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(m) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(m) * 0xffffffff + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t7 = $cast2<u32>(z)
    t8 = t9 + $cast2<u32>(z >> 32)
    t9 = 0

    // Round 1
    const bi1 = b[1]
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(a[0]) * $cast2<u64>(bi1) + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(a[1]) * $cast2<u64>(bi1) + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(a[2]) * $cast2<u64>(bi1) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + $cast2<u64>(a[3]) * $cast2<u64>(bi1) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + $cast2<u64>(a[4]) * $cast2<u64>(bi1) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + $cast2<u64>(a[5]) * $cast2<u64>(bi1) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(a[6]) * $cast2<u64>(bi1) + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(a[7]) * $cast2<u64>(bi1) + carry
    t7 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t8 = $cast2<u32>(z)
    t9 = $cast2<u32>(z >> 32)

    m = t0
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(m) * 0xffffffff + carry
    carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(m) * 0xffffffff + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(m) * 0xffffffff + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(m) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(m) * 0xffffffff + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t7 = $cast2<u32>(z)
    t8 = t9 + $cast2<u32>(z >> 32)
    t9 = 0

    // Round 2
    const bi2 = b[2]
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(a[0]) * $cast2<u64>(bi2) + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(a[1]) * $cast2<u64>(bi2) + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(a[2]) * $cast2<u64>(bi2) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + $cast2<u64>(a[3]) * $cast2<u64>(bi2) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + $cast2<u64>(a[4]) * $cast2<u64>(bi2) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + $cast2<u64>(a[5]) * $cast2<u64>(bi2) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(a[6]) * $cast2<u64>(bi2) + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(a[7]) * $cast2<u64>(bi2) + carry
    t7 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t8 = $cast2<u32>(z)
    t9 = $cast2<u32>(z >> 32)

    m = t0
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(m) * 0xffffffff + carry
    carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(m) * 0xffffffff + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(m) * 0xffffffff + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(m) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(m) * 0xffffffff + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t7 = $cast2<u32>(z)
    t8 = t9 + $cast2<u32>(z >> 32)
    t9 = 0

    // Round 3
    const bi3 = b[3]
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(a[0]) * $cast2<u64>(bi3) + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(a[1]) * $cast2<u64>(bi3) + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(a[2]) * $cast2<u64>(bi3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + $cast2<u64>(a[3]) * $cast2<u64>(bi3) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + $cast2<u64>(a[4]) * $cast2<u64>(bi3) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + $cast2<u64>(a[5]) * $cast2<u64>(bi3) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(a[6]) * $cast2<u64>(bi3) + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(a[7]) * $cast2<u64>(bi3) + carry
    t7 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t8 = $cast2<u32>(z)
    t9 = $cast2<u32>(z >> 32)

    m = t0
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(m) * 0xffffffff + carry
    carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(m) * 0xffffffff + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(m) * 0xffffffff + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(m) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(m) * 0xffffffff + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t7 = $cast2<u32>(z)
    t8 = t9 + $cast2<u32>(z >> 32)
    t9 = 0

    // Round 4
    const bi4 = b[4]
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(a[0]) * $cast2<u64>(bi4) + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(a[1]) * $cast2<u64>(bi4) + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(a[2]) * $cast2<u64>(bi4) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + $cast2<u64>(a[3]) * $cast2<u64>(bi4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + $cast2<u64>(a[4]) * $cast2<u64>(bi4) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + $cast2<u64>(a[5]) * $cast2<u64>(bi4) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(a[6]) * $cast2<u64>(bi4) + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(a[7]) * $cast2<u64>(bi4) + carry
    t7 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t8 = $cast2<u32>(z)
    t9 = $cast2<u32>(z >> 32)

    m = t0
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(m) * 0xffffffff + carry
    carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(m) * 0xffffffff + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(m) * 0xffffffff + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(m) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(m) * 0xffffffff + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t7 = $cast2<u32>(z)
    t8 = t9 + $cast2<u32>(z >> 32)
    t9 = 0

    // Round 5
    const bi5 = b[5]
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(a[0]) * $cast2<u64>(bi5) + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(a[1]) * $cast2<u64>(bi5) + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(a[2]) * $cast2<u64>(bi5) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + $cast2<u64>(a[3]) * $cast2<u64>(bi5) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + $cast2<u64>(a[4]) * $cast2<u64>(bi5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + $cast2<u64>(a[5]) * $cast2<u64>(bi5) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(a[6]) * $cast2<u64>(bi5) + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(a[7]) * $cast2<u64>(bi5) + carry
    t7 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t8 = $cast2<u32>(z)
    t9 = $cast2<u32>(z >> 32)

    m = t0
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(m) * 0xffffffff + carry
    carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(m) * 0xffffffff + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(m) * 0xffffffff + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(m) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(m) * 0xffffffff + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t7 = $cast2<u32>(z)
    t8 = t9 + $cast2<u32>(z >> 32)
    t9 = 0

    // Round 6
    const bi6 = b[6]
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(a[0]) * $cast2<u64>(bi6) + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(a[1]) * $cast2<u64>(bi6) + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(a[2]) * $cast2<u64>(bi6) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + $cast2<u64>(a[3]) * $cast2<u64>(bi6) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + $cast2<u64>(a[4]) * $cast2<u64>(bi6) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + $cast2<u64>(a[5]) * $cast2<u64>(bi6) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(a[6]) * $cast2<u64>(bi6) + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(a[7]) * $cast2<u64>(bi6) + carry
    t7 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t8 = $cast2<u32>(z)
    t9 = $cast2<u32>(z >> 32)

    m = t0
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(m) * 0xffffffff + carry
    carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(m) * 0xffffffff + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(m) * 0xffffffff + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(m) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(m) * 0xffffffff + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t7 = $cast2<u32>(z)
    t8 = t9 + $cast2<u32>(z >> 32)
    t9 = 0

    // Round 7
    const bi7 = b[7]
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(a[0]) * $cast2<u64>(bi7) + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(a[1]) * $cast2<u64>(bi7) + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(a[2]) * $cast2<u64>(bi7) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + $cast2<u64>(a[3]) * $cast2<u64>(bi7) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + $cast2<u64>(a[4]) * $cast2<u64>(bi7) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + $cast2<u64>(a[5]) * $cast2<u64>(bi7) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(a[6]) * $cast2<u64>(bi7) + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(a[7]) * $cast2<u64>(bi7) + carry
    t7 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t8 = $cast2<u32>(z)
    t9 = $cast2<u32>(z >> 32)

    m = t0
    carry = 0
    z = $cast2<u64>(t0) + $cast2<u64>(m) * 0xffffffff + carry
    carry = z >> 32
    z = $cast2<u64>(t1) + $cast2<u64>(m) * 0xffffffff + carry
    t0 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t2) + $cast2<u64>(m) * 0xffffffff + carry
    t1 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t3) + carry
    t2 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t4) + carry
    t3 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t5) + carry
    t4 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t6) + $cast2<u64>(m) + carry
    t5 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t7) + $cast2<u64>(m) * 0xffffffff + carry
    t6 = $cast2<u32>(z); carry = z >> 32
    z = $cast2<u64>(t8) + carry
    t7 = $cast2<u32>(z)
    t8 = t9 + $cast2<u32>(z >> 32)
    t9 = 0

    // CIOS result is < 2p. Reduce once, including the ninth limb.
    let reduce = t8 != 0
    if (!reduce) {
        if (t7 != FIELD_PRIME[7]) reduce = t7 > FIELD_PRIME[7]
        else if (t6 != FIELD_PRIME[6]) reduce = t6 > FIELD_PRIME[6]
        else if (t5 != FIELD_PRIME[5]) reduce = t5 > FIELD_PRIME[5]
        else if (t4 != FIELD_PRIME[4]) reduce = t4 > FIELD_PRIME[4]
        else if (t3 != FIELD_PRIME[3]) reduce = t3 > FIELD_PRIME[3]
        else if (t2 != FIELD_PRIME[2]) reduce = t2 > FIELD_PRIME[2]
        else if (t1 != FIELD_PRIME[1]) reduce = t1 > FIELD_PRIME[1]
        else reduce = t0 >= FIELD_PRIME[0]
    }

    if (reduce) {
        let borrow: u64 = 0
        let d: u64 = 0
        let ti: u64 = 0
        let pi: u64 = 0

        ti = $cast2<u64>(t0); pi = $cast2<u64>(FIELD_PRIME[0])
        d = ti - pi - borrow; t0 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t1); pi = $cast2<u64>(FIELD_PRIME[1])
        d = ti - pi - borrow; t1 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t2); pi = $cast2<u64>(FIELD_PRIME[2])
        d = ti - pi - borrow; t2 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t3); pi = $cast2<u64>(FIELD_PRIME[3])
        d = ti - pi - borrow; t3 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t4); pi = $cast2<u64>(FIELD_PRIME[4])
        d = ti - pi - borrow; t4 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t5); pi = $cast2<u64>(FIELD_PRIME[5])
        d = ti - pi - borrow; t5 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t6); pi = $cast2<u64>(FIELD_PRIME[6])
        d = ti - pi - borrow; t6 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t7); pi = $cast2<u64>(FIELD_PRIME[7])
        d = ti - pi - borrow; t7 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        t8 -= $cast2<u32>(borrow)
    }

    a[0] = t0
    a[1] = t1
    a[2] = t2
    a[3] = t3
    a[4] = t4
    a[5] = t5
    a[6] = t6
    a[7] = t7

}


// Cortex-M4 Montgomery multiplication.
// Based on the 230-cycle P-256 Montgomery kernel from Emil Lenngren's
// P256-cortex-ecdh speed-optimized Cortex-M4 implementation.
// Standard EM•Script signature: a := a*b*R^-1 mod p.
function fieldMontMulM4(a: U256_Ref, b: U256_Ref) {
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

function fieldSquare(a: U256_Ref) {
    fieldMul(a, a)
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

    // Z3 = (Z1 + H)^2 - Z1^2 - H^2.  Original Z1 is now dead.
    fieldAdd(p.$$.z.$ptr(), h.$ptr())
    fieldSquare(p.$$.z.$ptr())
    fieldSub(p.$$.z.$ptr(), z1z1.$ptr())
    fieldSub(p.$$.z.$ptr(), hh.$ptr())

    // I = 4*HH, reusing hh.
    fieldAdd(hh.$ptr(), hh.$ptr())
    fieldAdd(hh.$ptr(), hh.$ptr())

    // J = H*I, reusing u2.
    Mem.cpy(u2.$ptr(), h.$ptr(), $sizeof<U256>())
    fieldMul(u2.$ptr(), hh.$ptr())

    // r = 2*(S2 - Y1), reusing s2.
    fieldSub(s2.$ptr(), p.$$.y.$ptr())
    fieldAdd(s2.$ptr(), s2.$ptr())

    // 2*Y1*J, reusing z1z1.  Original Y1 is then dead.
    Mem.cpy(z1z1.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    fieldMul(z1z1.$ptr(), u2.$ptr())
    fieldAdd(z1z1.$ptr(), z1z1.$ptr())

    // V = X1*I, directly into p.y.  Original X1 is then dead.
    Mem.cpy(p.$$.y.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    fieldMul(p.$$.y.$ptr(), hh.$ptr())

    // X3 = r^2 - J - 2V, directly into p.x.
    Mem.cpy(p.$$.x.$ptr(), s2.$ptr(), $sizeof<U256>())
    fieldSquare(p.$$.x.$ptr())
    fieldSub(p.$$.x.$ptr(), u2.$ptr())
    Mem.cpy(h.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    fieldAdd(h.$ptr(), h.$ptr())
    fieldSub(p.$$.x.$ptr(), h.$ptr())

    // Y3 = r*(V - X3) - 2*Y1*J, directly into p.y.
    fieldSub(p.$$.y.$ptr(), p.$$.x.$ptr())
    fieldMul(p.$$.y.$ptr(), s2.$ptr())
    fieldSub(p.$$.y.$ptr(), z1z1.$ptr())
}

function pointDouble(p: $$<PointJ>) {
    // delta = Z^2, gamma = Y^2
    let delta = U256.$make()
    Mem.cpy(delta.$ptr(), p.$$.z.$ptr(), $sizeof<U256>())
    fieldSquare(delta.$ptr())
    let gamma = U256.$make()
    Mem.cpy(gamma.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    fieldSquare(gamma.$ptr())

    // Z3 = (Y + Z)^2 - gamma - delta.  Z is dead after this.
    fieldAdd(p.$$.z.$ptr(), p.$$.y.$ptr())
    fieldSquare(p.$$.z.$ptr())
    fieldSub(p.$$.z.$ptr(), gamma.$ptr())
    fieldSub(p.$$.z.$ptr(), delta.$ptr())

    // Reuse Y storage for beta = X * gamma.  Original Y is now dead.
    Mem.cpy(p.$$.y.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    fieldMul(p.$$.y.$ptr(), gamma.$ptr())

    // alpha = 3 * (X - delta) * (X + delta).
    let alpha = U256.$make()
    Mem.cpy(alpha.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    fieldSub(alpha.$ptr(), delta.$ptr())
    fieldAdd(delta.$ptr(), p.$$.x.$ptr())
    fieldMul(alpha.$ptr(), delta.$ptr())
    Mem.cpy(delta.$ptr(), alpha.$ptr(), $sizeof<U256>())
    fieldAdd(alpha.$ptr(), alpha.$ptr())
    fieldAdd(alpha.$ptr(), delta.$ptr())

    // X3 = alpha^2 - 8*beta.  Original X is now dead.
    Mem.cpy(p.$$.x.$ptr(), alpha.$ptr(), $sizeof<U256>())
    fieldSquare(p.$$.x.$ptr())
    Mem.cpy(delta.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    fieldAdd(delta.$ptr(), delta.$ptr())
    fieldAdd(delta.$ptr(), delta.$ptr())
    fieldAdd(delta.$ptr(), delta.$ptr())
    fieldSub(p.$$.x.$ptr(), delta.$ptr())

    // Y3 = alpha * (4*beta - X3) - 8*gamma^2.
    fieldAdd(p.$$.y.$ptr(), p.$$.y.$ptr())
    fieldAdd(p.$$.y.$ptr(), p.$$.y.$ptr())
    fieldSub(p.$$.y.$ptr(), p.$$.x.$ptr())
    fieldMul(p.$$.y.$ptr(), alpha.$ptr())
    fieldSquare(gamma.$ptr())
    fieldAdd(gamma.$ptr(), gamma.$ptr())
    fieldAdd(gamma.$ptr(), gamma.$ptr())
    fieldAdd(gamma.$ptr(), gamma.$ptr())
    fieldSub(p.$$.y.$ptr(), gamma.$ptr())
}

function pointMul(k: U256_Ref, p: $$<PointJ>) {
    let base = PointJ.$make()
    Mem.cpy(base.x.$ptr(), p.$$.x.$ptr(), $sizeof<U256>())
    Mem.cpy(base.y.$ptr(), p.$$.y.$ptr(), $sizeof<U256>())
    Mem.cpy(base.z.$ptr(), MONT_R.$ptr(), $sizeof<U256>())
    let neg = PointJ.$make()
    Mem.cpy(neg.x.$ptr(), base.x.$ptr(), $sizeof<U256>())
    for (const i of $range(U256_LEN)) neg.y[i] = 0
    fieldSub(neg.y.$ptr(), base.y.$ptr())
    Mem.cpy(neg.z.$ptr(), MONT_R.$ptr(), $sizeof<U256>())
    let n = U256.$make()
    Mem.cpy(n.$ptr(), k, $sizeof<U256>())
    let naf = NAF257.$make()
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
    let r = PointJ.$make()
    let have = false
    for (let i = $cast2<i32>(nbits) - 1; i >= 0; i -= 1) {
        if (have) pointDouble($$(r))
        const d = naf[i]
        if (d == 0) continue
        const q = d > 0 ? $$(base) : $$(neg)
        if (!have) {
            Mem.cpy(r.x.$ptr(), q.$$.x.$ptr(), $sizeof<U256>())
            Mem.cpy(r.y.$ptr(), q.$$.y.$ptr(), $sizeof<U256>())
            Mem.cpy(r.z.$ptr(), MONT_R.$ptr(), $sizeof<U256>())
            have = true
        } else {
            pointAddAffine($$(r), q)
        }
    }
    Mem.cpy(p.$$.x.$ptr(), r.x.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.y.$ptr(), r.y.$ptr(), $sizeof<U256>())
    Mem.cpy(p.$$.z.$ptr(), r.z.$ptr(), $sizeof<U256>())
}

function scalarAddOne(a: U256_Ref) {
    for (const i of $range(U256_LEN)) {
        a[i] += 1
        if (a[i] != 0) return
    }
}

function scalarIsZero(a: U256_Ref): bool_t {
    for (const i of $range(U256_LEN)) if (a[i] != 0) return false
    return true
}

function scalarShiftRight(a: U256_Ref) {
    let carry: u32 = 0
    for (const i of $range(U256_LEN - 1, -1, -1)) {
        const next = a[i] << 31
        a[i] = (a[i] >> 1) | carry
        carry = next
    }
}

function scalarSubOne(a: U256_Ref) {
    for (const i of $range(U256_LEN)) {
        const v = a[i]
        a[i] -= 1
        if (v != 0) return
    }
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
    fieldFromMont(p.$$.x.$ptr())
    fieldFromMont(p.$$.y.$ptr())
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


function testMontMulM4() {
    let a = U256.$make()
    let b = U256.$make()
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<U256>())
    Mem.cpy(b.$ptr(), B_TEST.$ptr(), $sizeof<U256>())

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
    let p = PointJ.$make()
    let q = PointJ.$make()

    Mem.cpy(p.x.$ptr(), G_X_TEST.$ptr(), $sizeof<U256>())
    Mem.cpy(p.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<U256>())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<U256>())

    Mem.cpy(q.x.$ptr(), G_X_TEST.$ptr(), $sizeof<U256>())
    Mem.cpy(q.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<U256>())
    fieldToMont(q.x.$ptr())
    fieldToMont(q.y.$ptr())
    Mem.cpy(q.z.$ptr(), MONT_R.$ptr(), $sizeof<U256>())

    $['%%d+']
    for (const i of $range(1024)) {
        pointDouble($$(p))
    }
    $['%%d-']
    print(p.x.$ptr(), t$`double1024`)

    // Reinitialize p so the add benchmark starts from a stable valid point.
    Mem.cpy(p.x.$ptr(), G_X_TEST.$ptr(), $sizeof<U256>())
    Mem.cpy(p.y.$ptr(), G_Y_TEST.$ptr(), $sizeof<U256>())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Mem.cpy(p.z.$ptr(), MONT_R.$ptr(), $sizeof<U256>())

    $['%%d+']
    for (const i of $range(1024)) {
        pointAddAffine($$(p), $$(q))
    }
    $['%%d-']
    print(p.x.$ptr(), t$`add1024`)
}

export function em$run() {
    testPointOps()
}
