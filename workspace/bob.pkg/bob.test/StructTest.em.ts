import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Types from '@bob.test/Types.em'

// class Pair extends $struct {
//     x: i16 = 10
//     y: i16 = 20
// }

let pair_tab = $table<Types.Pair>('rw')

export namespace em$meta {

    var p = Types.Pair.$make()
    pair_tab.$add(p)

    // interface factory_t<T> {
    //     $make(): T
    // }
    // 
    // function $structD<T>(obj: T): factory_t<T> {
    //     return { $make: () => { return <T>{} } }
    // }
    // 
    // const Pair_t = $structD({
    //     x: <i16>10,
    //     y: <i16>20
    // })
    // 
    // const p = Pair_t.$make()
    // console.log(p)


    // class S {
    //     static $make(): S { return new this }
    //     x: i16
    // }
    // const s = S.$make()
    // console.log(s)

    // console.log($sizeof<Pair>)


    //    const Pair = $struct({
    //        x: $i16(),
    //        y: $i16()
    //    })
    //    // console.log(Pair)
    //    // console.log(Pair.$sizeof)
    //
    //    const p = Pair.$make()
    //    p.x = 10
    //    p.y = 20
    //    console.log(p)
    //    console.log(p.x)
    //    console.log(p.$sizeof)

    // console.log(Pair)

    // const PairPT = em.proto({
    //     x: em.U8(),
    //     y: em.U8()
    // })
    // 
    // const p1 = em.struct_t(PairPT)
    // const p2 = em.struct_t(PairPT)
    // 
    // // const p2 = em.struct_t(Pair)
    // // console.log(p2)
    // // const p2 = em.struct_t(Pair)
    // 
    // p1.x.$$ = 10
    // p2.x.$$ = 20
    // 
    // console.log(p1.$sizeof, p1.x.$$ + p2.x.$$)
    // console.log(p1.$sizeof)
    // 
    // console.log(p1)
}


export function em$run() {
    printf`x = %d\n`(pair_tab[0].x)
    // p.x += 10
    // printf`x = %d, sz = %d\n`(p.x, $sizeof<Pair>)
}
