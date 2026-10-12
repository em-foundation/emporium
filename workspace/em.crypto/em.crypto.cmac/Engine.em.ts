import '@$$emscript'
export const $U = $declare('MODULE', CmacProviderI)

import * as Aes128I from '@em.hal/Aes128I.em'
import * as CmacProviderI from '@em.crypto.cmac/CmacProviderI.em'
import * as Mem from '@em.utils/Mem.em'

export const Aes = $proxy<Aes128I.$I>()

const RB = 0x87

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function compute(key: CmacProviderI.Key_Ref, msg: frame_t<u8>, mac_OUT: CmacProviderI.Mac_Ref): void {
    let k1 = Aes128I.Block.$make()
    let k2 = Aes128I.Block.$make()
    let last = Aes128I.Block.$make()
    let l = Aes128I.Block.$make()
    let x = Aes128I.Block.$make()
    let y = Aes128I.Block.$make()
    Mem.set(x.$ptr(), 0, Aes128I.BLOCK_LEN)
    Aes.encrypt(key, x.$ptr(), l.$ptr())
    dbl(k1.$ptr(), l.$ptr())
    dbl(k2.$ptr(), k1.$ptr())
    const len = msg.$len
    const n: u16 = len == 0 ? 1 : ((len + Aes128I.BLOCK_LEN - 1) / Aes128I.BLOCK_LEN)
    const complete = len != 0 && (len % Aes128I.BLOCK_LEN) == 0
    for (const bi of $range(n - 1)) {
        const off = bi * Aes128I.BLOCK_LEN
        for (const i of $range(Aes128I.BLOCK_LEN)) y[i] = x[i] ^ msg[off + i]
        Aes.encrypt(key, y.$ptr(), x.$ptr())
    }
    Mem.set(last.$ptr(), 0, Aes128I.BLOCK_LEN)
    const off = (n - 1) * Aes128I.BLOCK_LEN
    if (complete) {
        Mem.cpy(last.$ptr(), $$(msg[off]), Aes128I.BLOCK_LEN)
        xorBlock(last.$ptr(), k1.$ptr())
    } else {
        const rem = len - off
        if (rem > 0) Mem.cpy(last.$ptr(), $$(msg[off]), rem)
        last[rem] = 0x80
        xorBlock(last.$ptr(), k2.$ptr())
    }
    for (const i of $range(Aes128I.BLOCK_LEN)) y[i] = x[i] ^ last[i]
    Aes.encrypt(key, y.$ptr(), mac_OUT)
}

function dbl(dst: Aes128I.Block_Ref, src: Aes128I.Block_Ref) {
    let carry: u8 = 0
    for (const i of $range(Aes128I.BLOCK_LEN - 1, -1, -1)) {
        const b = src[i]
        dst[i] = ((b << 1) & 0xff) | carry
        carry = (b >> 7) & 1
    }
    if (carry != 0) dst[Aes128I.BLOCK_LEN - 1] ^= RB
}

function xorBlock(dst: Aes128I.Block_Ref, src: Aes128I.Block_Ref) {
    for (const i of $range(Aes128I.BLOCK_LEN)) dst[i] ^= src[i]
}
