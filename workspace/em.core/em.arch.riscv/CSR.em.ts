import '@$$emscript'
export const $U = $declare('MODULE')

export const MSTATUS: u16 = 0x300
export const MISA: u16 = 0x301
export const MIE: u16 = 0x304
export const MTVEC: u16 = 0x305
export const MTVT: u16 = 0x307
export const MEPC: u16 = 0x341
export const MCAUSE: u16 = 0x342
export const MTVAL: u16 = 0x343
export const MIP: u16 = 0x344
export const MCYCLE: u16 = 0xB00
export const MINSTRET: u16 = 0xB02
export const MHARTID: u16 = 0xF14

export const MSTATUS_MIE: u32 = 0x00000008

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function clear(csr: u16, mask: u32) {
    e$`asm volatile ("csrc %0, %1" :: "i"(csr), "r"(mask) : "memory")`
}

export function read(csr: u16): u32 {
    let val: u32 = 0
    e$`asm volatile ("csrr %0, %1" : "=r"(val) : "i"(csr) : "memory")`
    return val
}

export function set(csr: u16, mask: u32) {
    e$`asm volatile ("csrs %0, %1" :: "i"(csr), "r"(mask) : "memory")`
}

export function write(csr: u16, val: u32) {
    e$`asm volatile ("csrw %0, %1" :: "i"(csr), "r"(val) : "memory")`
}
