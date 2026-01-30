import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BusyWait from '@em.utils/BusyWait.em'

class Elem extends $struct {
    data: u8
    link: $$<Elem>
}

var elem_tab = $table<Elem>()

const head = $config<$$<Elem>>()

export namespace em$meta {
    export function em$init() {
        let prev = elem_tab.$null()
        for (const i of $range(3)) {
            const e = elem_tab.$$add()
            e.$$.data = i + 10
            e.$$.link = prev
            prev = e
        }
        head.$$val = prev
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    // printf`%d\n`(BusyWait.scalar)            // Y
    printf`data = %d\n`(head.$$.data)           // Y

    // em.$reg32[100] = elem_tab[1].data           // Y

    // em.$reg32[100] = elem_tab.$ptr().$$.data    // Y

    // let er = elem_tab.$ref(1)                   // Y
    // printf`data = %d\n`(er.$$.data)

    // printf`data = %d\n`(head.$$.data)           // Y

    // let e1 = elem_tab[1]
    // let er = $ref(e1)                           // N (Iterator)
    // printf`data = %d\n`(er.$$.data)

    // let efg = elem_tab.$ptr()                   // Y
    // let e = efg.$$
    // printf`data = %d\n`(e.data)

    // for (const efg of elem_tab) {
    //     printf`link = %x\n`(efg.$$.link)     // N (any)
    // }
}