import '@$$emscript'
export const $U = $declare('MODULE')

export type Adr = u16

const top = $config<Adr>(0)

export namespace em$meta {
    export function alloc(size: u16): Adr {
        const adr = top.$$val
        top.$$val += size
        return adr
    }
    export function size(): Adr {
        return top.$$val
    }
}

//>> ---- em$targ ---- <<//

e$`extern "C" uint32_t __heap_addr__`

export function base(): opaq_t {
    return <opaq_t>(e$`&__heap_addr__`)
}

export function opaq(a: Adr): opaq_t {
    return <opaq_t>(e$`a + (uint8_t *)(&__heap_addr__)`)

}

export function size(): Adr {
    return top
}
