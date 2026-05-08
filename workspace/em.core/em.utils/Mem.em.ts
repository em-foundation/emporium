import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function cmp(dst: arg_t, src: arg_t, len: u16): i32 {
    return <i32>e$`memcpy((uint8_t*)dst, (uint8_t*)src, len)`
}

export function cpy(dst: arg_t, src: arg_t, len: u16) {
    e$`memcpy((uint8_t*)dst, (uint8_t*)src, len)`
}

export function prB(label: text_t, ptr: arg_t, size: u32) {
    printf`%s:\n`(label)
    let p8 = <ptr_t<u8>>(ptr)
    const cnt = size
    const wid = 16
    let nl: text_t = t$``
    for (const i of $range(cnt)) {
        if ((i % wid) == 0) {
            printf`%s  %08x: `(nl, p8);
            nl = t$``;
        } else {
            nl = t$`\n`;
        }
        printf`%02x `(p8.$$)
        p8.$inc()
    }
    printf`%s\n`(nl)
}

export function prW(label: text_t, p32: ptr_t<u32>, size: u32) {
    printf`%s:\n`(label)
    const cnt = size / 4
    const wid = 4
    let nl: text_t = t$``
    for (const i of $range(cnt)) {
        if ((i % wid) == 0) {
            printf`%s  %06x: `(nl, p32);
            nl = t$``;
        } else {
            nl = t$`\n`;
        }
        printf`%08x `(p32.$$)
        p32.$inc()
    }
    printf`%s\n`(nl)
}

export function set(dst: arg_t, val: u8, len: u16) {
    e$`memset((uint8_t*)dst, val, len)`
}

