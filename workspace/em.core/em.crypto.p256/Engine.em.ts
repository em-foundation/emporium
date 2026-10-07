import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as FieldI from '@em.crypto.p256/FieldI.em'
import * as T from '@em.crypto.p256/Types.em'

export const Field = $proxy<FieldI.$I>()

const G_X = $config<T.U256>()
const G_Y = $config<T.U256>()
const MONT_R = $config<T.U256>()
const MONT_R2 = $config<T.U256>()
const MONT_ONE = $config<T.U256>()

export namespace em$meta {
    export function em$construct() {
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
    Field.copy(p.x.$ptr(), G_X.$ptr())
    Field.copy(p.y.$ptr(), G_Y.$ptr())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Field.copy(p.z.$ptr(), MONT_R.$ptr())
    pointMul(sk.$ptr(), $$(p))
    pointToAffine($$(p))
    Field.copy(pk_OUT.$$.x.$ptr(), p.x.$ptr())
    Field.copy(pk_OUT.$$.y.$ptr(), p.y.$ptr())
}

export function ecdh(sk: T.U256, peer_pk: $$<T.PubKey>, secret_OUT: T.U256_Ref) {
    let p = T.PointJ.$make()
    Field.copy(p.x.$ptr(), peer_pk.$$.x.$ptr())
    Field.copy(p.y.$ptr(), peer_pk.$$.y.$ptr())
    fieldToMont(p.x.$ptr())
    fieldToMont(p.y.$ptr())
    Field.copy(p.z.$ptr(), MONT_R.$ptr())
    pointMul(sk.$ptr(), $$(p))
    pointToAffine($$(p))
    Field.copy(secret_OUT, p.x.$ptr())
}

// FIELD FUNCTIONS

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
    Field.copy(z1z1.$ptr(), p.$$.z.$ptr())
    fieldSquare(z1z1.$ptr())

    let u2 = T.U256.$make()
    Field.copy(u2.$ptr(), q.$$.x.$ptr())
    Field.mul(u2.$ptr(), z1z1.$ptr())

    let s2 = T.U256.$make()
    Field.copy(s2.$ptr(), q.$$.y.$ptr())
    Field.mul(s2.$ptr(), p.$$.z.$ptr())
    Field.mul(s2.$ptr(), z1z1.$ptr())

    let h = T.U256.$make()
    Field.copy(h.$ptr(), u2.$ptr())
    Field.sub(h.$ptr(), p.$$.x.$ptr())

    let hh = T.U256.$make()
    Field.copy(hh.$ptr(), h.$ptr())
    fieldSquare(hh.$ptr())

    // Z3 = (Z1 + H)^2 - Z1^2 - H^2.  Original Z1 is now dead.
    Field.add(p.$$.z.$ptr(), h.$ptr())
    fieldSquare(p.$$.z.$ptr())
    Field.sub(p.$$.z.$ptr(), z1z1.$ptr())
    Field.sub(p.$$.z.$ptr(), hh.$ptr())

    // I = 4*HH, reusing hh.
    Field.times2(hh.$ptr())
    Field.times2(hh.$ptr())

    // J = H*I, reusing u2.
    Field.copy(u2.$ptr(), h.$ptr())
    Field.mul(u2.$ptr(), hh.$ptr())

    // r = 2*(S2 - Y1), reusing s2.
    Field.sub(s2.$ptr(), p.$$.y.$ptr())
    Field.times2(s2.$ptr())

    // 2*Y1*J, reusing z1z1.  Original Y1 is then dead.
    Field.copy(z1z1.$ptr(), p.$$.y.$ptr())
    Field.mul(z1z1.$ptr(), u2.$ptr())
    Field.times2(z1z1.$ptr())

    // V = X1*I, directly into p.y.  Original X1 is then dead.
    Field.copy(p.$$.y.$ptr(), p.$$.x.$ptr())
    Field.mul(p.$$.y.$ptr(), hh.$ptr())

    // X3 = r^2 - J - 2V, directly into p.x.
    Field.copy(p.$$.x.$ptr(), s2.$ptr())
    fieldSquare(p.$$.x.$ptr())
    Field.sub(p.$$.x.$ptr(), u2.$ptr())
    Field.copy(h.$ptr(), p.$$.y.$ptr())
    Field.times2(h.$ptr())
    Field.sub(p.$$.x.$ptr(), h.$ptr())

    // Y3 = r*(V - X3) - 2*Y1*J, directly into p.y.
    Field.sub(p.$$.y.$ptr(), p.$$.x.$ptr())
    Field.mul(p.$$.y.$ptr(), s2.$ptr())
    Field.sub(p.$$.y.$ptr(), z1z1.$ptr())
}

function pointDouble(p: $$<T.PointJ>) {
    // ePrint 2014/130 algorithm 10, arranged like Emil Lenngren's P256_double_j.
    // This trades two field squares for one multiply plus one modular half.

    // t1 = Z1^2
    let t1 = T.U256.$make()
    T.copyU256(t1.$ptr(), p.$$.z.$ptr())
    fieldSquare(t1.$ptr())

    // Z2 = Y1 * Z1
    Field.mul(p.$$.z.$ptr(), p.$$.y.$ptr())

    // t2 = X1 + t1
    let t2 = T.U256.$make()
    T.copyU256(t2.$ptr(), p.$$.x.$ptr())
    Field.add(t2.$ptr(), t1.$ptr())

    // t1 = (X1 - t1) * t2
    let t3 = T.U256.$make()
    T.copyU256(t3.$ptr(), p.$$.x.$ptr())
    Field.sub(t3.$ptr(), t1.$ptr())
    Field.mul(t3.$ptr(), t2.$ptr())

    // t3 = 3/2 * t3; t1 becomes the later Y^4 scratch.
    T.copyU256(t1.$ptr(), t3.$ptr())
    Field.half(t1.$ptr())
    Field.add(t3.$ptr(), t1.$ptr())

    // t2 = t3^2
    T.copyU256(t2.$ptr(), t3.$ptr())
    fieldSquare(t2.$ptr())

    // Y2 = Y1^2; t1 = Y2^2
    fieldSquare(p.$$.y.$ptr())
    T.copyU256(t1.$ptr(), p.$$.y.$ptr())
    fieldSquare(t1.$ptr())

    // Y2 = X1 * Y2
    Field.mul(p.$$.y.$ptr(), p.$$.x.$ptr())

    // X2 = t2 - 2*Y2
    T.copyU256(p.$$.x.$ptr(), p.$$.y.$ptr())
    Field.times2(p.$$.x.$ptr())
    Field.sub(t2.$ptr(), p.$$.x.$ptr())
    T.copyU256(p.$$.x.$ptr(), t2.$ptr())

    // Y2 = t1 * (Y2 - X2) - t3
    Field.sub(p.$$.y.$ptr(), p.$$.x.$ptr())
    Field.mul(p.$$.y.$ptr(), t3.$ptr())
    Field.sub(p.$$.y.$ptr(), t1.$ptr())
}

function pointAddJacobian(p: $$<T.PointJ>, q: $$<T.PointJ>) {
    // Rearranged like Emil Lenngren's P256_add_j, but aggressively reuse
    // p.{x,y,z} and only three U256 temporaries.

    // t1 = Z1^2
    let t1 = T.U256.$make()
    Field.copy(t1.$ptr(), q.$$.z.$ptr())
    fieldSquare(t1.$ptr())

    // X2 = U2 = X2 * Z1^2
    Field.mul(p.$$.x.$ptr(), t1.$ptr())

    // Y2 = S2 = Y2 * Z1^3
    Field.mul(t1.$ptr(), q.$$.z.$ptr())
    Field.mul(p.$$.y.$ptr(), t1.$ptr())

    // t1 = Z2^2
    Field.copy(t1.$ptr(), p.$$.z.$ptr())
    fieldSquare(t1.$ptr())

    // t2 = U1 = X1 * Z2^2
    let t2 = T.U256.$make()
    Field.copy(t2.$ptr(), q.$$.x.$ptr())
    Field.mul(t2.$ptr(), t1.$ptr())

    // t1 = S1 = Y1 * Z2^3
    Field.mul(t1.$ptr(), p.$$.z.$ptr())
    Field.mul(t1.$ptr(), q.$$.y.$ptr())

    // X2 = H = U2 - U1
    Field.sub(p.$$.x.$ptr(), t2.$ptr())

    // t3 = HH = H^2
    let t3 = T.U256.$make()
    Field.copy(t3.$ptr(), p.$$.x.$ptr())
    fieldSquare(t3.$ptr())

    // Z3 = Z2 * H * Z1
    Field.mul(p.$$.z.$ptr(), p.$$.x.$ptr())
    Field.mul(p.$$.z.$ptr(), q.$$.z.$ptr())

    // X2 = HHH = H * HH
    Field.mul(p.$$.x.$ptr(), t3.$ptr())

    // Y2 = r = S2 - S1
    Field.sub(p.$$.y.$ptr(), t1.$ptr())

    // t2 = V = U1 * HH
    Field.mul(t2.$ptr(), t3.$ptr())

    // t3 = r^2
    Field.copy(t3.$ptr(), p.$$.y.$ptr())
    fieldSquare(t3.$ptr())

    // t1 = S1 * HHH
    Field.mul(t1.$ptr(), p.$$.x.$ptr())

    // t3 = r^2 - HHH - 2V = X3
    Field.sub(t3.$ptr(), p.$$.x.$ptr())
    Field.copy(p.$$.x.$ptr(), t2.$ptr())
    Field.times2(p.$$.x.$ptr())
    Field.sub(t3.$ptr(), p.$$.x.$ptr())
    Field.copy(p.$$.x.$ptr(), t3.$ptr())

    // Y3 = r * (V - X3) - S1*HHH
    Field.copy(t3.$ptr(), t2.$ptr())
    Field.sub(t3.$ptr(), p.$$.x.$ptr())
    Field.mul(t3.$ptr(), p.$$.y.$ptr())
    Field.sub(t3.$ptr(), t1.$ptr())
    Field.copy(p.$$.y.$ptr(), t3.$ptr())
}

function pointMul(k: T.U256_Ref, p: $$<T.PointJ>) {
    // Width-5 signed NAF.  The odd-multiple table lives here because it is
    // scalar-multiplication policy rather than a field/backend concern.

    let p1 = T.PointJ.$make()
    Field.copy(p1.x.$ptr(), p.$$.x.$ptr())
    Field.copy(p1.y.$ptr(), p.$$.y.$ptr())
    Field.copy(p1.z.$ptr(), p.$$.z.$ptr())

    let twoP = T.PointJ.$make()
    Field.copy(twoP.x.$ptr(), p1.x.$ptr())
    Field.copy(twoP.y.$ptr(), p1.y.$ptr())
    Field.copy(twoP.z.$ptr(), p1.z.$ptr())
    pointDouble($$(twoP))

    let p3 = T.PointJ.$make()
    Field.copy(p3.x.$ptr(), p1.x.$ptr())
    Field.copy(p3.y.$ptr(), p1.y.$ptr())
    Field.copy(p3.z.$ptr(), p1.z.$ptr())
    pointAddJacobian($$(p3), $$(twoP))

    let p5 = T.PointJ.$make()
    Field.copy(p5.x.$ptr(), p3.x.$ptr())
    Field.copy(p5.y.$ptr(), p3.y.$ptr())
    Field.copy(p5.z.$ptr(), p3.z.$ptr())
    pointAddJacobian($$(p5), $$(twoP))

    let p7 = T.PointJ.$make()
    Field.copy(p7.x.$ptr(), p5.x.$ptr())
    Field.copy(p7.y.$ptr(), p5.y.$ptr())
    Field.copy(p7.z.$ptr(), p5.z.$ptr())
    pointAddJacobian($$(p7), $$(twoP))

    let p9 = T.PointJ.$make()
    Field.copy(p9.x.$ptr(), p7.x.$ptr())
    Field.copy(p9.y.$ptr(), p7.y.$ptr())
    Field.copy(p9.z.$ptr(), p7.z.$ptr())
    pointAddJacobian($$(p9), $$(twoP))

    let p11 = T.PointJ.$make()
    Field.copy(p11.x.$ptr(), p9.x.$ptr())
    Field.copy(p11.y.$ptr(), p9.y.$ptr())
    Field.copy(p11.z.$ptr(), p9.z.$ptr())
    pointAddJacobian($$(p11), $$(twoP))

    let p13 = T.PointJ.$make()
    Field.copy(p13.x.$ptr(), p11.x.$ptr())
    Field.copy(p13.y.$ptr(), p11.y.$ptr())
    Field.copy(p13.z.$ptr(), p11.z.$ptr())
    pointAddJacobian($$(p13), $$(twoP))

    let p15 = T.PointJ.$make()
    Field.copy(p15.x.$ptr(), p13.x.$ptr())
    Field.copy(p15.y.$ptr(), p13.y.$ptr())
    Field.copy(p15.z.$ptr(), p13.z.$ptr())
    pointAddJacobian($$(p15), $$(twoP))

    let naf = T.NAF257.$make()
    let nbits: u32 = 0

    // Direct width-5 wNAF recoding from the original scalar limbs.
    // carry represents the signed correction from previously emitted digits;
    // no 256-bit working scalar or whole-value right shifts are required.
    let carry: i32 = 0

    for (let bit: u32 = 0; bit < 257; bit += 1) {
        let qbits: u32 = 0

        if (bit < 256) {
            const wi = bit >> 5
            const sh = bit & 31
            qbits = k[wi] >> sh

            if (sh > 27 && wi < 7) {
                qbits |= k[wi + 1] << (32 - sh)
            }

            qbits &= 0x1f
        }

        let d: i8 = 0
        const x = $cast2<i32>(qbits) + carry

        if ((x & 1) != 0) {
            d = $cast2<i8>(x & 0x1f)
            if (d >= 16) d -= 32
        }

        naf[bit] = d
        if (d != 0) nbits = bit + 1

        carry = ($cast2<i32>(qbits & 1) + carry - $cast2<i32>(d)) >> 1
    }

    let r = T.PointJ.$make()
    let have = false
    let q = T.PointJ.$make()

    for (let i = $cast2<i32>(nbits) - 1; i >= 0; i -= 1) {
        if (have) pointDouble($$(r))
        const d = naf[i]
        if (d == 0) continue

        const ad = d < 0 ? -d : d
        if (ad == 1) {
            Field.copy(q.x.$ptr(), p1.x.$ptr())
            Field.copy(q.y.$ptr(), p1.y.$ptr())
            Field.copy(q.z.$ptr(), p1.z.$ptr())
        } else if (ad == 3) {
            Field.copy(q.x.$ptr(), p3.x.$ptr())
            Field.copy(q.y.$ptr(), p3.y.$ptr())
            Field.copy(q.z.$ptr(), p3.z.$ptr())
        } else if (ad == 5) {
            Field.copy(q.x.$ptr(), p5.x.$ptr())
            Field.copy(q.y.$ptr(), p5.y.$ptr())
            Field.copy(q.z.$ptr(), p5.z.$ptr())
        } else if (ad == 7) {
            Field.copy(q.x.$ptr(), p7.x.$ptr())
            Field.copy(q.y.$ptr(), p7.y.$ptr())
            Field.copy(q.z.$ptr(), p7.z.$ptr())
        } else if (ad == 9) {
            Field.copy(q.x.$ptr(), p9.x.$ptr())
            Field.copy(q.y.$ptr(), p9.y.$ptr())
            Field.copy(q.z.$ptr(), p9.z.$ptr())
        } else if (ad == 11) {
            Field.copy(q.x.$ptr(), p11.x.$ptr())
            Field.copy(q.y.$ptr(), p11.y.$ptr())
            Field.copy(q.z.$ptr(), p11.z.$ptr())
        } else if (ad == 13) {
            Field.copy(q.x.$ptr(), p13.x.$ptr())
            Field.copy(q.y.$ptr(), p13.y.$ptr())
            Field.copy(q.z.$ptr(), p13.z.$ptr())
        } else {
            Field.copy(q.x.$ptr(), p15.x.$ptr())
            Field.copy(q.y.$ptr(), p15.y.$ptr())
            Field.copy(q.z.$ptr(), p15.z.$ptr())
        }

        if (d < 0) {
            let ny = T.U256.$make()
            for (const j of $range(T.U256_LEN)) ny[j] = 0
            Field.sub(ny.$ptr(), q.y.$ptr())
            Field.copy(q.y.$ptr(), ny.$ptr())
        }

        if (!have) {
            Field.copy(r.x.$ptr(), q.x.$ptr())
            Field.copy(r.y.$ptr(), q.y.$ptr())
            Field.copy(r.z.$ptr(), q.z.$ptr())
            have = true
        } else {
            pointAddJacobian($$(r), $$(q))
        }
    }

    Field.copy(p.$$.x.$ptr(), r.x.$ptr())
    Field.copy(p.$$.y.$ptr(), r.y.$ptr())
    Field.copy(p.$$.z.$ptr(), r.z.$ptr())
}

function scalarAddSmall(a: T.U256_Ref, v: u32) {
    let carry: u64 = v
    for (const i of $range(T.U256_LEN)) {
        if (carry == 0) return
        const s = $cast2<u64>(a[i]) + carry
        a[i] = $cast2<u32>(s)
        carry = s >> 32
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

function scalarSubSmall(a: T.U256_Ref, v: u32) {
    let borrow: u64 = v
    for (const i of $range(T.U256_LEN)) {
        if (borrow == 0) return
        const ai = $cast2<u64>(a[i])
        a[i] = $cast2<u32>(ai - borrow)
        borrow = ai < borrow ? 1 : 0
    }
}

function pointToAffine(p: $$<T.PointJ>) {
    let zi = T.U256.$make()
    Field.copy(zi.$ptr(), p.$$.z.$ptr())
    Field.inv(zi.$ptr())
    let zi2 = T.U256.$make()
    Field.copy(zi2.$ptr(), zi.$ptr())
    fieldSquare(zi2.$ptr())
    Field.mul(p.$$.x.$ptr(), zi2.$ptr())
    Field.mul(zi2.$ptr(), zi.$ptr())
    Field.mul(p.$$.y.$ptr(), zi2.$ptr())
    fieldFromMont(p.$$.x.$ptr())
    fieldFromMont(p.$$.y.$ptr())
    for (const i of $range(T.U256_LEN)) p.$$.z[i] = 0
    p.$$.z[0] = 1
}
