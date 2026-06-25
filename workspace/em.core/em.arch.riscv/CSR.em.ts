import '@$$emscript'
export const $U = $declare('MODULE')

export const MSTATUS: u16 = 0x300
export const MISA: u16 = 0x301
export const MIE: u16 = 0x304
export const MTVEC: u16 = 0x305
export const MTVT: u16 = 0x307
export const MCOUNTINHIBIT: u16 = 0x320
export const MHPMEVENT3: u16 = 0x323
export const MHPMEVENT4: u16 = 0x324
export const MHPMEVENT5: u16 = 0x325
export const MHPMEVENT6: u16 = 0x326
export const MHPMEVENT7: u16 = 0x327
export const MHPMEVENT8: u16 = 0x328
export const MHPMEVENT9: u16 = 0x329
export const MHPMEVENT10: u16 = 0x32A
export const MHPMEVENT11: u16 = 0x32B
export const MHPMEVENT12: u16 = 0x32C
export const MHPMEVENT13: u16 = 0x32D
export const MHPMEVENT14: u16 = 0x32E
export const MHPMEVENT15: u16 = 0x32F
export const MHPMEVENT16: u16 = 0x330
export const MHPMEVENT17: u16 = 0x331
export const MHPMEVENT18: u16 = 0x332
export const MHPMEVENT19: u16 = 0x333
export const MHPMEVENT20: u16 = 0x334
export const MHPMEVENT21: u16 = 0x335
export const MHPMEVENT22: u16 = 0x336
export const MHPMEVENT23: u16 = 0x337
export const MHPMEVENT24: u16 = 0x338
export const MHPMEVENT25: u16 = 0x339
export const MHPMEVENT26: u16 = 0x33A
export const MHPMEVENT27: u16 = 0x33B
export const MHPMEVENT28: u16 = 0x33C
export const MHPMEVENT29: u16 = 0x33D
export const MHPMEVENT30: u16 = 0x33E
export const MHPMEVENT31: u16 = 0x33F
export const MSCRATCH: u16 = 0x340
export const MEPC: u16 = 0x341
export const MCAUSE: u16 = 0x342
export const MTVAL: u16 = 0x343
export const MIP: u16 = 0x344
export const MSECCFG: u16 = 0x390
export const MSECCFGH: u16 = 0x391
export const PMPCFG0: u16 = 0x3A0
export const PMPCFG1: u16 = 0x3A1
export const PMPCFG2: u16 = 0x3A2
export const PMPCFG3: u16 = 0x3A3
export const PMPADDR0: u16 = 0x3B0
export const PMPADDR1: u16 = 0x3B1
export const PMPADDR2: u16 = 0x3B2
export const PMPADDR3: u16 = 0x3B3
export const PMPADDR4: u16 = 0x3B4
export const PMPADDR5: u16 = 0x3B5
export const PMPADDR6: u16 = 0x3B6
export const PMPADDR7: u16 = 0x3B7
export const PMPADDR8: u16 = 0x3B8
export const PMPADDR9: u16 = 0x3B9
export const PMPADDR10: u16 = 0x3BA
export const PMPADDR11: u16 = 0x3BB
export const PMPADDR12: u16 = 0x3BC
export const PMPADDR13: u16 = 0x3BD
export const PMPADDR14: u16 = 0x3BE
export const PMPADDR15: u16 = 0x3BF
export const TSELECT: u16 = 0x7A0
export const TDATA1: u16 = 0x7A1
export const TDATA2: u16 = 0x7A2
export const TDATA3: u16 = 0x7A3
export const MCONTEXT: u16 = 0x7A8
export const SCONTEXT: u16 = 0x7AA
export const DCSR: u16 = 0x7B0
export const DPC: u16 = 0x7B1
export const DSCRATCH0: u16 = 0x7B2
export const DSCRATCH1: u16 = 0x7B3
export const CPUCTRL: u16 = 0x7C0
export const SECURESEED: u16 = 0x7C1
export const MCYCLE: u16 = 0xB00
export const MINSTRET: u16 = 0xB02
export const MHPMCOUNTER3: u16 = 0xB03
export const MHPMCOUNTER4: u16 = 0xB04
export const MHPMCOUNTER5: u16 = 0xB05
export const MHPMCOUNTER6: u16 = 0xB06
export const MHPMCOUNTER7: u16 = 0xB07
export const MHPMCOUNTER8: u16 = 0xB08
export const MHPMCOUNTER9: u16 = 0xB09
export const MHPMCOUNTER10: u16 = 0xB0A
export const MHPMCOUNTER11: u16 = 0xB0B
export const MHPMCOUNTER12: u16 = 0xB0C
export const MHPMCOUNTER13: u16 = 0xB0D
export const MHPMCOUNTER14: u16 = 0xB0E
export const MHPMCOUNTER15: u16 = 0xB0F
export const MHPMCOUNTER16: u16 = 0xB10
export const MHPMCOUNTER17: u16 = 0xB11
export const MHPMCOUNTER18: u16 = 0xB12
export const MHPMCOUNTER19: u16 = 0xB13
export const MHPMCOUNTER20: u16 = 0xB14
export const MHPMCOUNTER21: u16 = 0xB15
export const MHPMCOUNTER22: u16 = 0xB16
export const MHPMCOUNTER23: u16 = 0xB17
export const MHPMCOUNTER24: u16 = 0xB18
export const MHPMCOUNTER25: u16 = 0xB19
export const MHPMCOUNTER26: u16 = 0xB1A
export const MHPMCOUNTER27: u16 = 0xB1B
export const MHPMCOUNTER28: u16 = 0xB1C
export const MHPMCOUNTER29: u16 = 0xB1D
export const MHPMCOUNTER30: u16 = 0xB1E
export const MHPMCOUNTER31: u16 = 0xB1F
export const MCYCLEH: u16 = 0xB80
export const MINSTRETH: u16 = 0xB82
export const MHPMCOUNTER3H: u16 = 0xB83
export const MHPMCOUNTER4H: u16 = 0xB84
export const MHPMCOUNTER5H: u16 = 0xB85
export const MHPMCOUNTER6H: u16 = 0xB86
export const MHPMCOUNTER7H: u16 = 0xB87
export const MHPMCOUNTER8H: u16 = 0xB88
export const MHPMCOUNTER9H: u16 = 0xB89
export const MHPMCOUNTER10H: u16 = 0xB8A
export const MHPMCOUNTER11H: u16 = 0xB8B
export const MHPMCOUNTER12H: u16 = 0xB8C
export const MHPMCOUNTER13H: u16 = 0xB8D
export const MHPMCOUNTER14H: u16 = 0xB8E
export const MHPMCOUNTER15H: u16 = 0xB8F
export const MHPMCOUNTER16H: u16 = 0xB90
export const MHPMCOUNTER17H: u16 = 0xB91
export const MHPMCOUNTER18H: u16 = 0xB92
export const MHPMCOUNTER19H: u16 = 0xB93
export const MHPMCOUNTER20H: u16 = 0xB94
export const MHPMCOUNTER21H: u16 = 0xB95
export const MHPMCOUNTER22H: u16 = 0xB96
export const MHPMCOUNTER23H: u16 = 0xB97
export const MHPMCOUNTER24H: u16 = 0xB98
export const MHPMCOUNTER25H: u16 = 0xB99
export const MHPMCOUNTER26H: u16 = 0xB9A
export const MHPMCOUNTER27H: u16 = 0xB9B
export const MHPMCOUNTER28H: u16 = 0xB9C
export const MHPMCOUNTER29H: u16 = 0xB9D
export const MHPMCOUNTER30H: u16 = 0xB9E
export const MHPMCOUNTER31H: u16 = 0xB9F
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
