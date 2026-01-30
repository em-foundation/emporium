import em from '@$$emscript'
export const $U = em.$declare('MODULE')

class Pair extends $struct {
    x: u8
    y: u8
}

type PairO = ref_t<Pair>

const pair = $param<PairO>()

export namespace em$meta {
    export function em$init() {
        console.log(pair.$val)
        // pair.$$.x = 10
        // pair.$$.y = 20
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    printf`x = %d, y = %d\n`(pair.$$.x, pair.$$.y)
}

// const max = $param<u8>(20)
// 
// export namespace em$meta {
//     export function em$init() {
//         printf`max = %d\n`(max)
//         max.$set(max + 10)
//         printf`max = %d\n`(max)
//     }
// }
// 
// //>> ---- em$targ ---- <<//
// 
// export function em$run() {
//     printf`max = %d\n`(max)
// }
