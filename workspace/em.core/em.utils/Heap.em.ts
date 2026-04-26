import '@$$emscript'
export const $U = $declare('MODULE')

const top = $config<u16>(0)

export namespace em$meta {
    export function alloc(size: u16): addr_t {
        const addr = top.$$val
        top.$$val += size
        return addr
    }
    export function size(): u16 {
        return top.$$val
    }
}

//>> ---- em$targ ---- <<//

e$`extern "C" uint32_t __heap_addr__`

export function base(): addr_t {
    return <u32>(e$`&__heap_addr__`)
}

export function opaq(a: addr_t): opaq_t {
    return <opaq_t>(e$`a + (uint8_t *)(&__heap_addr__)`)

}

export function size(): u16 {
    return top
}
