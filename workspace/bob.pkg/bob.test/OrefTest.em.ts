import em from '@$$emscript'
export const $U = em.$declare('MODULE')

class Elem extends $struct {
    data: i16
    next: ref_t<Elem>
}

let ElemFac = $factory(Elem.$make())

const head = $config<ref_t<Elem>>()

export namespace em$meta {
    let e = ElemFac.$create()
    e.$$.data = 10
    e.$$.next = e
    console.log(e.$$.next.$$.data)
    head.$$ = e
}

export function em$run() {
    let e = head.$$
    printf`%d\n`(e.$$.next.$$.data)
}
