import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    // let reg: u32 = e$`*em::$reg32((uint32_t)&SPIS->RegSPISCtrl)`
    // let reg: u32 = e$`*em::$reg32((uint32_t)&PML->RegPmlCtrl)
    // let reg: u32 = e$`_lr(REG_ICCM_BUILD)`
    // printf`reg = %08x\n`(reg)


    // let sz = <u32>e$`&__code_size__`
    // let src = <ptr_t<u32>>e$`&__code_load__`
    // let dst = <ptr_t<u32>>e$`&__code_addr__`
    // printf`sz = %d, src = %06x, dst = %06x\n`(sz, src, dst)
    // dst.$$ = src.$$
    // printf`s0 = %08x, d0 = %08x\n`(src.$$, dst.$$)
}