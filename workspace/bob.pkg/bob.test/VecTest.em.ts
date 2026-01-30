import em from '@$$emscript'
export const $U = em.$declare('MODULE')

class Tab extends $vector<u8> { $len = 3 }

class S extends $struct {
    tab: Tab
}

var s = S.$make()

export namespace em$meta {
    export function em$construct() {
        console.log(s.tab[1])
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
}