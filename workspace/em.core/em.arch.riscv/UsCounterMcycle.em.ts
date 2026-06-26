import '@$$emscript'
export const $U = $declare('MODULE', UsCounterI)

import * as CSR from '@em.arch.riscv/CSR.em'
import * as UsCounterI from '@em.hal/UsCounterI.em'

export const MHZ_P = $config<u16>(48)
export const MHZ_Q = $config<u16>(1)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

let cur_thresh = <u32>0

export function set(time_us: u32) {
    cur_thresh = time_us * MHZ_P / MHZ_Q
    CSR.clear(CSR.MCOUNTINHIBIT, 0x1)
}

export function spin() {
    let val: volatile_t<u32> = 0
    while (val < cur_thresh) val = CSR.read(CSR.MCYCLE)
    CSR.set(CSR.MCOUNTINHIBIT, 0x1)
}

export function start() {
    CSR.clear(CSR.MCOUNTINHIBIT, 0x1)
}

export function stop(): u32 {
    const dt = CSR.read(CSR.MCYCLE) * MHZ_Q / MHZ_P
    CSR.set(CSR.MCOUNTINHIBIT, 0x1)
    return dt
}
