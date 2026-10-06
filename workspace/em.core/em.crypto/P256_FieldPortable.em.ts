import '@$$emscript'
export const $U = $declare('MODULE', FieldI)

import * as FieldI from '@em.crypto/P256_FieldI.em'
import * as T from '@em.crypto/P256_Types.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function add(a: T.U256_Ref, b: T.U256_Ref) {
    let carry: u64 = 0
    for (const i of $range(T.U256_LEN)) {
        const s = $cast2<u64>(a[i]) + $cast2<u64>(b[i]) + carry
        a[i] = $cast2<u32>(s)
        carry = s >> 32
    }
    let reduce = carry != 0
    if (!reduce) {
        for (const i of $range(T.U256_LEN - 1, -1, -1)) {
            if (a[i] != T.FIELD_PRIME[i]) {
                reduce = a[i] > T.FIELD_PRIME[i]
                break
            }
            if (i == 0) reduce = true
        }
    }
    if (reduce) {
        let borrow: u64 = 0
        for (const i of $range(T.U256_LEN)) {
            const ai = $cast2<u64>(a[i])
            const pi = $cast2<u64>(T.FIELD_PRIME[i])
            const d = ai - pi - borrow
            a[i] = $cast2<u32>(d)
            borrow = ai < (pi + borrow) ? 1 : 0
        }
    }
}

export function mul(a: T.U256_Ref, b: T.U256_Ref) {
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
        if (t7 != T.FIELD_PRIME[7]) reduce = t7 > T.FIELD_PRIME[7]
        else if (t6 != T.FIELD_PRIME[6]) reduce = t6 > T.FIELD_PRIME[6]
        else if (t5 != T.FIELD_PRIME[5]) reduce = t5 > T.FIELD_PRIME[5]
        else if (t4 != T.FIELD_PRIME[4]) reduce = t4 > T.FIELD_PRIME[4]
        else if (t3 != T.FIELD_PRIME[3]) reduce = t3 > T.FIELD_PRIME[3]
        else if (t2 != T.FIELD_PRIME[2]) reduce = t2 > T.FIELD_PRIME[2]
        else if (t1 != T.FIELD_PRIME[1]) reduce = t1 > T.FIELD_PRIME[1]
        else reduce = t0 >= T.FIELD_PRIME[0]
    }

    if (reduce) {
        let borrow: u64 = 0
        let d: u64 = 0
        let ti: u64 = 0
        let pi: u64 = 0

        ti = $cast2<u64>(t0); pi = $cast2<u64>(T.FIELD_PRIME[0])
        d = ti - pi - borrow; t0 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t1); pi = $cast2<u64>(T.FIELD_PRIME[1])
        d = ti - pi - borrow; t1 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t2); pi = $cast2<u64>(T.FIELD_PRIME[2])
        d = ti - pi - borrow; t2 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t3); pi = $cast2<u64>(T.FIELD_PRIME[3])
        d = ti - pi - borrow; t3 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t4); pi = $cast2<u64>(T.FIELD_PRIME[4])
        d = ti - pi - borrow; t4 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t5); pi = $cast2<u64>(T.FIELD_PRIME[5])
        d = ti - pi - borrow; t5 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t6); pi = $cast2<u64>(T.FIELD_PRIME[6])
        d = ti - pi - borrow; t6 = $cast2<u32>(d); borrow = ti < (pi + borrow) ? 1 : 0
        ti = $cast2<u64>(t7); pi = $cast2<u64>(T.FIELD_PRIME[7])
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

export function sub(a: T.U256_Ref, b: T.U256_Ref) {
    let borrow: u64 = 0
    for (const i of $range(T.U256_LEN)) {
        const ai = $cast2<u64>(a[i])
        const bi = $cast2<u64>(b[i])
        const d = ai - bi - borrow
        a[i] = $cast2<u32>(d)
        borrow = ai < (bi + borrow) ? 1 : 0
    }
    if (borrow != 0) {
        let carry: u64 = 0
        for (const i of $range(T.U256_LEN)) {
            const s = $cast2<u64>(a[i]) + $cast2<u64>(T.FIELD_PRIME[i]) + carry
            a[i] = $cast2<u32>(s)
            carry = s >> 32
        }
    }
}
