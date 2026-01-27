import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    const addr: u32 = e$`PADS_BANK0_GPIO_get(28)`
    printf`addr = %08x\n`(addr)
}
