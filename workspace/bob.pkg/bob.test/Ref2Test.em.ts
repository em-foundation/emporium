import em from '@$$emscript'
export const $U = em.$declare('MODULE')

class Pair extends $struct {
    x: u8
    y: u8
}

export var pair = Pair.$make()
export const pref = $ref<Pair>(pair)

export namespace em$meta {
    export function em$init() {
        console.log(pref.$$)
        pref.$$.x = 10
        pref.$$.y = 20
        console.log(pair)
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    printf`x = %d, y = %d\n`(pref.$$.x, pref.$$.y)
}