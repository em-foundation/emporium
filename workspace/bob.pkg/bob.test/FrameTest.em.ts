import em from '@$$emscript'
export const $U = em.$declare('MODULE')

export const Buf = $array($u8(), 5)

export namespace em$meta {
    //     let buf = Buf.$make()
    //     for (let i = 0; i < buf.$len; i++) buf[i] = 10 + i
    // 
    //     // for (let e of buf) e.$$ *= 2
    //     // for (let e of buf) console.log(e.$$)
    //     // let ptr = buf.$ptr()
    //     // for (let i = 0; i < buf.$len; i++) { ptr.$$ *= 2; ptr.$inc() }
    // 
    //     let frm_a = buf.$frame(-5, 3)
    //     for (let e of frm_a) e.$$ *= 2
    //     for (let e of buf) console.log(e.$$)
    // 
    //     // for (let e of frm_a) e.$$ *= 2
    //     // for (let e of buf) console.log(e.$$)
    //     // let frm_b = frm_a.$frame(1)
    //     // for (let e of frm_b) console.log(e.$$)

}

export function em$run() {
    let buf = Buf.$make()
    // for (let i = 0; i < buf.$len; i++) buf[i] = 10 + i
    let frm = buf.$frame(2)
    foo(frm)
    // em.$reg32[0xAA] = <u32>frm.$start
    // em.$reg32[0xBB] = frm.$len
}

function foo(frm: frame_t<u8>) {
    for (let b of frm) em.$reg32[0xAA] = b.$$
}
