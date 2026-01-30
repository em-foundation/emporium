import em from '@$$emscript'
export const $U = em.$declare('MODULE')

class Tab extends $vector<u8> { $len = 3 }

class S extends $struct {
    x: u32
    t: Tab
}

const cfg = $config<S>()

export namespace em$meta {
    export function em$construct() {
        console.log(cfg.$$)
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    em.halt()
}