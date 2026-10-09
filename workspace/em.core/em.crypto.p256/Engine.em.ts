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
const ORDER = $config<T.U256>()

export namespace em$meta {
    export function em$construct() {
        T.em$meta.initU256(G_X.$$val, '6b17d1f2_e12c4247_f8bce6e5_63a440f2_77037d81_2deb33a0_f4a13945_d898c296')
        T.em$meta.initU256(G_Y.$$val, '4fe342e2_fe1a7f9b_8ee7eb4a_7c0f9e16_2bce3357_6b315ece_cbb64068_37bf51f5')
        T.em$meta.initU256(MONT_R.$$val, '00000000_fffffffe_ffffffff_ffffffff_ffffffff_00000000_00000000_00000001')
        T.em$meta.initU256(MONT_R2.$$val, '00000004_fffffffd_ffffffff_fffffffe_fffffffb_ffffffff_00000000_00000003')
        T.em$meta.initU256(MONT_ONE.$$val, '00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000001')
        T.em$meta.initU256(ORDER.$$val, 'ffffffff_00000000_ffffffff_ffffffff_bce6faad_a7179e84_f3b9cac2_fc632551')
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
    Field.doublePoint(p)
}

function pointAddJacobian(p: $$<T.PointJ>, q: $$<T.PointJ>) {
    Field.addPointJacobian(p, q)
}

function ctEqMask(a: u32, b: u32): u32 {
    const x = a ^ b
    const nz = (x | ($cast2<u32>(0) - x)) >> 31
    return $cast2<u32>(0) - (nz ^ 1)
}


function packTablePoint(table: $$<T.PointTableWords>, slot: u32, p: $$<T.PointJ>) {
    const base = slot * T.POINT_WORDS
    for (const i of $range(T.U256_LEN)) {
        table.$$[base + i] = p.$$.x[i]
        table.$$[base + T.U256_LEN + i] = p.$$.y[i]
        table.$$[base + 2 * T.U256_LEN + i] = p.$$.z[i]
    }
}


function ctSelectPoint(out: $$<T.PointJ>, idx: u32, table: $$<T.PointTableWords>) {
    // Constant-time scan of a contiguous P,3P,...,15P table.
    // This mirrors Emil's P256_select organization much more closely than
    // passing eight independent PointJ arguments.
    for (const i of $range(T.POINT_WORDS)) {
        let v: u32 = 0

        for (let slot: u32 = 0; slot < T.TABLE_POINTS; slot += 1) {
            const mask = ctEqMask(idx, slot)
            v |= table.$$[slot * T.POINT_WORDS + i] & mask
        }

        if (i < T.U256_LEN) out.$$.x[i] = v
        else if (i < 2 * T.U256_LEN) out.$$.y[i - T.U256_LEN] = v
        else out.$$.z[i - 2 * T.U256_LEN] = v
    }
}


function pointNegateYIf(p: $$<T.PointJ>, neg: u32) {
    // Always form -Y, then select Y or -Y with a full-word mask.
    let ny = T.U256.$make()
    for (const i of $range(T.U256_LEN)) ny[i] = 0
    Field.sub(ny.$ptr(), p.$$.y.$ptr())

    const mask = $cast2<u32>(0) - neg
    for (const i of $range(T.U256_LEN)) {
        p.$$.y[i] ^= (p.$$.y[i] ^ ny[i]) & mask
    }
}


function scalarNormalizeOdd(k: T.U256_Ref, out: T.U256_Ref): u32 {
    // Emil's point multiplier uses k when k is odd and n-k when k is even.
    // Return 1 when n-k was selected so the final Y can be negated back.
    const useNeg = (k[0] & 1) ^ 1

    let nk = T.U256.$make()
    let borrow: u64 = 0

    for (const i of $range(T.U256_LEN)) {
        const d = $cast2<u64>(ORDER[i]) - $cast2<u64>(k[i]) - borrow
        nk[i] = $cast2<u32>(d)
        borrow = d >> 63
    }

    const mask = $cast2<u32>(0) - useNeg
    for (const i of $range(T.U256_LEN)) {
        out[i] = k[i] ^ ((k[i] ^ nk[i]) & mask)
    }

    return useNeg
}


function scalarRewriteFixed4(k: T.U256_Ref, win: $$<T.Window64>) {
    // Same signed 4-bit rewrite used by Emil: every emitted digit is odd,
    // so each of the 63 main-loop windows performs exactly one point add.
    let cur: i32 = $cast2<i32>(k[0] & 0x0f)

    for (let w: u32 = 1; w < 64; w += 1) {
        const wi = w >> 3
        const sh = (w & 7) << 2
        const nib = (k[wi] >> sh) & 0x0f
        const even = (nib & 1) ^ 1

        win.$$[w - 1] = $cast2<i8>(cur - $cast2<i32>(even << 4))
        cur = $cast2<i32>(nib | 1)
    }

    win.$$[63] = $cast2<i8>(cur)
}


function pointMul(k: T.U256_Ref, p: $$<T.PointJ>) {
    // Emil-style constant-operation scalar path:
    //   - normalize scalar to odd k or n-k
    //   - rewrite into 64 signed 4-bit odd windows
    //   - precompute P,3P,...,15P
    //   - fixed 63 iterations of four doubles + one add
    //   - constant-time table selection and sign handling

    let kk = T.U256.$make()
    const flipResult = scalarNormalizeOdd(k, kk.$ptr())

    let win = T.Window64.$make()
    scalarRewriteFixed4(kk.$ptr(), $$(win))

    let p1 = T.PointJ.$make()
    Field.copy(p1.x.$ptr(), p.$$.x.$ptr())
    Field.copy(p1.y.$ptr(), p.$$.y.$ptr())
    Field.copy(p1.z.$ptr(), p.$$.z.$ptr())

    // Match Emil's table construction closely: use the future 15P slot as
    // temporary 2P storage, then overwrite it with 15P at the end.
    let p15 = T.PointJ.$make()
    Field.copy(p15.x.$ptr(), p1.x.$ptr())
    Field.copy(p15.y.$ptr(), p1.y.$ptr())
    Field.copy(p15.z.$ptr(), p1.z.$ptr())
    pointDouble($$(p15))

    let p3 = T.PointJ.$make()
    Field.copy(p3.x.$ptr(), p15.x.$ptr())
    Field.copy(p3.y.$ptr(), p15.y.$ptr())
    Field.copy(p3.z.$ptr(), p15.z.$ptr())
    pointAddJacobian($$(p3), $$(p1))

    let p5 = T.PointJ.$make()
    Field.copy(p5.x.$ptr(), p15.x.$ptr())
    Field.copy(p5.y.$ptr(), p15.y.$ptr())
    Field.copy(p5.z.$ptr(), p15.z.$ptr())
    pointAddJacobian($$(p5), $$(p3))

    let p7 = T.PointJ.$make()
    Field.copy(p7.x.$ptr(), p15.x.$ptr())
    Field.copy(p7.y.$ptr(), p15.y.$ptr())
    Field.copy(p7.z.$ptr(), p15.z.$ptr())
    pointAddJacobian($$(p7), $$(p5))

    let p9 = T.PointJ.$make()
    Field.copy(p9.x.$ptr(), p15.x.$ptr())
    Field.copy(p9.y.$ptr(), p15.y.$ptr())
    Field.copy(p9.z.$ptr(), p15.z.$ptr())
    pointAddJacobian($$(p9), $$(p7))

    let p11 = T.PointJ.$make()
    Field.copy(p11.x.$ptr(), p15.x.$ptr())
    Field.copy(p11.y.$ptr(), p15.y.$ptr())
    Field.copy(p11.z.$ptr(), p15.z.$ptr())
    pointAddJacobian($$(p11), $$(p9))

    let p13 = T.PointJ.$make()
    Field.copy(p13.x.$ptr(), p15.x.$ptr())
    Field.copy(p13.y.$ptr(), p15.y.$ptr())
    Field.copy(p13.z.$ptr(), p15.z.$ptr())
    pointAddJacobian($$(p13), $$(p11))

    // p15 still contains 2P here.
    pointAddJacobian($$(p15), $$(p13))

    // Pack the odd multiples contiguously for the hot constant-time selector.
    let table = T.PointTableWords.$make()
    packTablePoint($$(table), 0, $$(p1))
    packTablePoint($$(table), 1, $$(p3))
    packTablePoint($$(table), 2, $$(p5))
    packTablePoint($$(table), 3, $$(p7))
    packTablePoint($$(table), 4, $$(p9))
    packTablePoint($$(table), 5, $$(p11))
    packTablePoint($$(table), 6, $$(p13))
    packTablePoint($$(table), 7, $$(p15))

    let r = T.PointJ.$make()
    let q = T.PointJ.$make()

    let d = win[63]
    let sign = $cast2<u32>(d) >> 31
    let ad = $cast2<u32>(d < 0 ? -d : d)
    ctSelectPoint($$(r), ad >> 1, $$(table))
    pointNegateYIf($$(r), sign)

    for (let w: i32 = 62; w >= 0; w -= 1) {
        pointDouble($$(r))
        pointDouble($$(r))
        pointDouble($$(r))
        pointDouble($$(r))

        d = win[w]
        sign = $cast2<u32>(d) >> 31
        ad = $cast2<u32>(d < 0 ? -d : d)

        ctSelectPoint($$(q), ad >> 1, $$(table))
        pointNegateYIf($$(q), sign)
        pointAddJacobian($$(r), $$(q))
    }

    // If even input k was replaced by n-k, -(n-k)P = kP.
    pointNegateYIf($$(r), flipResult)

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
