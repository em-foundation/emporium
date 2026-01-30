import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Console from '@em.lang/Console.em'

const Buf = $array($u8(), 25)
var my_buf = Buf.$make()

export namespace em$meta {
    // console.log(Buf)
}

export function em$run() {
    for (let i = 0; i < my_buf.$len; i++) my_buf[i] = i + 10
    let p = my_buf.$ptr()
    printf`p[2] = %d\n`(p[2])
    // for (let e of my_buf) Console.wrU8(e.$$)
    // em.$reg32[0xAA] = my_buf[2]
    // for (let e of my_buf) e.$$ *= 2
    // em.$reg32[0xBB] = my_buf[4]
    // for (let e of my_buf) em.$reg32[0xCC] = e.$$
    // my_buf[2] = em.$reg32[0xAA]
    // em.$reg32[0xBB] = my_buf.$len
}
