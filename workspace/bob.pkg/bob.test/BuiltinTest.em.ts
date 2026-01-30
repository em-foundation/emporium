import em from '@$$emscript'
export const $U = em.$declare('MODULE')

export const c = $config<u8>(3)

/*

export const Buf = em.Array(em.U8(), 5)
var my_buf = Buf.$make()

export function em$run() {
    let p = my_buf.$ptr()
    foo(p)
}

function foo(p: ptr_t<u8>) {
    p.$$ = 10
    p.$inc()
}

*/
