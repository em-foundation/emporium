import em from '@$$emscript'
export const $U = em.$declare('MODULE')

type Fxn = cb_t<[x: u8]>

const fxn = $config<Fxn>()

export namespace em$meta {

    export function em$construct() {
        fxn.$$ = $cb(fooFxn)
    }
}

export function em$run() {
    fxn.$$(10)
}

function fooFxn(x: u8) {
    printf`fooFxn(%d)\n`(x)
}


// export namespace em$meta {
// 
//     type CallA = cb_t<[]>
//     type CallB = cb_t<[u8]>
// 
//     function cb0() { console.log('cb0()') }
//     function cb1(x: u8) { console.log(`cb1(${x})`) }
// 
//     let cb = $cb<CallB>(cb1)
//     cb.$$(10)
// }
