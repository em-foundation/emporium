import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'

const U256_LEN = 8
type U256_BASE = u32

export class U256 extends $vector<U256_BASE> { $len = U256_LEN }

export type U256_Ref = ptr_t<U256_BASE>

export class PubKey extends $struct {
    x: U256
    y: U256
}

const FIELD_PRIME = $config<U256>()
const A_TEST = $config<U256>()
const B_TEST = $config<U256>()

export namespace em$meta {

    export function em$construct() {
        initU256(FIELD_PRIME.$$val, 'ffffffff_00000001_00000000_00000000_00000000_ffffffff_ffffffff_ffffffff')
        initU256(A_TEST.$$val, '11111111_22222222_33333333_44444444_55555555_66666666_77777777_88888888')
        initU256(B_TEST.$$val, '01020304_05060708_090a0b0c_0d0e0f10_11121314_15161718_191a1b1c_1d1e1f20')
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

}

export function ecdh(sk: U256, peer_pk: $$<PubKey>, secret_OUT: U256) {

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

function fieldAdd(a: U256_Ref, b: U256_Ref) {
    let carry: u64 = 0
    for (const i of $range(U256_LEN)) {
        const s = $cast2<u64>(a[i]) + $cast2<u64>(b[i]) + carry
        a[i] = $cast2<u32>(s)
        carry = s >> 32
    }
    let borrow: u64 = 0
    let t = U256.$make()
    for (const i of $range(U256_LEN)) {
        const ai = $cast2<u64>(a[i])
        const pi = $cast2<u64>(FIELD_PRIME[i])
        const d = ai - pi - borrow
        t[i] = $cast2<u32>(d)
        borrow = ai < (pi + borrow) ? 1 : 0
    }
    if (carry != 0 || borrow == 0) {
        Mem.cpy(a, t.$ptr(), $sizeof<U256>())
    }
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

function fieldMul(a: U256_Ref, b: U256_Ref) {
    let x = U256.$make()
    Mem.cpy(x.$ptr(), a, $sizeof<U256>())
    for (const i of $range(U256_LEN)) a[i] = 0
    for (const i of $range(U256_LEN)) {
        for (const j of $range(32)) {
            if ((b[i] & (1 << j)) != 0) fieldAdd(a, x.$ptr())
            fieldAdd(x.$ptr(), x.$ptr())
        }
    }
}

export function em$run() {
    let a = U256.$make()
    Mem.cpy(a.$ptr(), A_TEST.$ptr(), $sizeof<U256>())
    let b = U256.$make()
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
}
