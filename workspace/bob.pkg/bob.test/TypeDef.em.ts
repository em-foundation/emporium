import em from '@$$emscript'
export const $U = em.$declare('MODULE')

// import * as GlobalInterruptsI from '@em.hal/GlobalInterruptsI.em'
// 
// export type Key = GlobalInterruptsI.Key
// export type MyKey = Key
// 
// class Tab extends $vector<u32> { $len = 10 }

class S extends $struct {
    x: u16
    y: u8
}

export namespace em$meta {
    export function em$construct() {
        console.log($$tdefs)
        console.log($sizeof<S>())
    }
}


// const sz = $sizeof<GlobalInterruptsI.Key>()

// export function em$run() {
//     key = 0
// }
