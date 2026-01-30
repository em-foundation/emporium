import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Dev from '@em.rf.core/Dev.em'

class S extends $struct {
    adr: Dev.Addr
}

// class Struct extends $struct {
//     a: u16
//     b: u8
// }
// 
// export namespace em$meta {
//     export function em$construct() {
//         console.log($sizeof<Struct>())
//     }
// }
// 
// var s1: Struct
// var s2: Struct
// 
// //>> ---- em$targ ---- <<//
// 
// export function em$run() {
//     let p1 = $ref(s1)
//     let p2 = $ref(s2)
//     // e$`memcpy(p1, p2, sizeof(Struct))`
//     printf`%08x %08x %d\n`(p1, p2, $sizeof<Struct>())
// }