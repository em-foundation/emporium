import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as FieldI from '@em.crypto.p256/FieldI.em'
import * as T from '@em.crypto.p256/Types.em'

export const Field = $proxy<FieldI.$I>()

const FIELD_PRIME_M2 = $config<T.U256>()
const G_X = $config<T.U256>()
const G_Y = $config<T.U256>()
const MONT_R = $config<T.U256>()
const MONT_R2 = $config<T.U256>()
const MONT_ONE = $config<T.U256>()

export namespace em$meta {
    export function em$construct() {
        T.em$meta.initU256(FIELD_PRIME_M2.$$val, 'ffffffff_00000001_00000000_00000000_00000000_ffffffff_ffffffff_fffffffd')
        T.em$meta.initU256(G_X.$$val, '6b17d1f2_e12c4247_f8bce6e5_63a440f2_77037d81_2deb33a0_f4a13945_d898c296')
        T.em$meta.initU256(G_Y.$$val, '4fe342e2_fe1a7f9b_8ee7eb4a_7c0f9e16_2bce3357_6b315ece_cbb64068_37bf51f5')
        T.em$meta.initU256(MONT_R.$$val, '00000000_fffffffe_ffffffff_ffffffff_ffffffff_00000000_00000000_00000001')
        T.em$meta.initU256(MONT_R2.$$val, '00000004_fffffffd_ffffffff_fffffffe_fffffffb_ffffffff_00000000_00000003')
        T.em$meta.initU256(MONT_ONE.$$val, '00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000001')
    }
}

//>> ---- em$targ ---- <<//

export function validatePublicKey(pk: $$<T.PubKey>): bool_t {
    return true
}

export function makePublicKey(sk: T.U256, pk_OUT: $$<T.PubKey>) {
    let p = T.PointJ.$make()
    Mem.cpy(p.x.$ptr(), G_X.$ptr(), $sizeof<T.U256>())
    Mem.cpy(p.y.$ptr(), G_Y.$ptr(), $sizeof<T.U256>())
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

function fieldSquare(a: T.U256_Ref) {
    Field.square(a)
}

// POINT FUNCTIONS

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
