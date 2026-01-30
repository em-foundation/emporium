import em from '@$$emscript'
export const $U = em.$declare('MODULE')

class Pair extends $struct {
    x: u8
    y: u8
}

class Adr extends $vector<Pair> { $len = 6 }

class Pkt extends $struct {
    kind: u8
    adr: Adr
}

let adr: Adr

// class Pkt extends $struct {
//     kind: u8
//     buf: vec_t<u8, 16>
//     pair: Pair
// }

export namespace em$meta {
    export function em$construct() {
        // console.log($sizeof<Adr>())
        adr = Adr.$make()
        for (const i of $range(adr.$len)) {
            adr[i].x = i
        }
        for (const e of adr.$frame(0)) console.log(e.$$.x)
        // let pkt = Pkt.$make()
        // console.log(pkt.adr)
    }
}
// 
// //>> ---- em$targ ---- <<//
// 
// export function em$run() {
//     em.halt()
// }