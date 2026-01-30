import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Console from '@em.lang/Console.em'

class Buf extends $vector<u8> { $len = 5 }

// export namespace em$meta {
//     let ptr = buf.$ptr()
//     for (let i = 0; i < buf.$len; i++) {
//         ptr.$$ = i + 10
//         ptr.$inc()
//     }
//     console.log(buf)
//     // for (let e of buf) e.$$ *= 2
//     // console.log(buf)
// }

export function em$run() {
    let buf = Buf.$make()
    for (let i = 0; i < buf.$len; i++) {
        buf[i] = i + 10
    }
    let ptr = buf.$ptr()
    // $['%%a']
    // Console.wrU32(ptr.$cur())
    // ptr.$inc()
    // $['%%a']
    // Console.wrU32(ptr.$cur())

    for (let i = 0; i < buf.$len; i++) {
        $['%%a']
        printf`%d `(ptr.$$)
        ptr.$inc()
    }

    // let a = <u32>0
    // 'a = (em::u32)&buf[0]'
    // $['%%a']
    // Console.wrU32(a)
    // let ptr = buf.$ptr()
    // $['%%a']
    // Console.wrU32(ptr.$cur())


    // for (let i = 0; i < buf.$len; i++) {
    //     buf[i] = i + 10
    // }
    // $['%%a']
    // for (let b of buf) Console.putb(b.$$)
    // for (let b of buf) b.$$ *= 2
    // $['%%a']
    // for (let b of buf) Console.putb(b.$$)
    // let ptr = buf.$ptr()
    // Console.wrU32(ptr.$cur())
    // for (let i = 0; i < buf.$len; i++) {
    //     ptr.$$ = i + 10
    //     ptr.$inc()
    // }

    // Console.wrU8(buf[0])
    // buf[0] = 20
    // Console.wrU8(buf[0])
    // let ptr = buf.$ptr()
    // ptr.$$ += 10
    // Console.wrU8(buf[0])
    // em.$reg32[0xAA] = ptr.$$
    // ptr.$inc()

}
