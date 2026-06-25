import '@$$emscript'
export const $U = $declare('MODULE', IrqI)

import * as CSR from '@em.arch.riscv/CSR.em'
import * as IrqI from '@em.hal/IrqI.em'
import * as IsrI from '@em.hal/IsrI.em'

export const IsrDefault = $proxy<IsrI.$I>()

export namespace em$meta {
    const NO_VEC = '<NA>'
    const intr_list = new Array<string>()
    const used_set = new Set<string>()
    const VEC_OFF = 16
    export function em$generate() {
        const len = VEC_OFF + intr_list.length
        let out = $outfile('nordic.distro.nrf54.flpr/intr.cpp')
        out.addFrag(`
                        |-> //
                        |-> #include <stdint.h>
                        |-> 
                        |-> typedef void (*intfunc)(void);
                        |-> 
                        |-> extern "C" void DEFAULT_isr$$(void);
        `)
        for (let i = 0; i < intr_list.length; i++) {
            const name = intr_list[i]
            if (name != NO_VEC && used_set.has(name)) {
                out.addFrag(`
                        |-> extern "C" void ${name}_isr$$(void);
                `)
            }
        }
        out.addFrag(`
                        |-> 
                        |-> extern "C" void __attribute__((interrupt("machine"))) em__riscv_default_irq_entry(void) {
                        |->     DEFAULT_isr$$();
                        |-> }
        `)
        for (let i = 0; i < intr_list.length; i++) {
            const name = intr_list[i]
            if (name != NO_VEC && used_set.has(name)) {
                out.addFrag(`
                        |-> 
                        |-> extern "C" void __attribute__((interrupt, aligned(4))) ${name}_irq_entry(void) {
                        |->     ${name}_isr$$();
                        |-> }
                `)
            }
        }
        out.addFrag(`
                        |-> 
                        |-> extern "C" const intfunc __attribute__((aligned(64))) __riscv_irq_vector_table[${len}] = {
        `)
        for (let i = 0; i < VEC_OFF; i++) {
            out.addFrag(`
                    |->     em__riscv_default_irq_entry,      // ${i}: <CORE>
    `       )
        }
        for (let i = 0; i < intr_list.length; i++) {
            const name = intr_list[i]
            // let entry = '0'
            let entry = 'em__riscv_default_irq_entry'
            if (name != NO_VEC) {
                entry = used_set.has(name) ? `${name}_irq_entry` : 'em__riscv_default_irq_entry'
            }
            out.addFrag(`
                        |->     ${entry},      // ${i}: ${name}
            `)
        }
        out.addFrag(`
                        |-> };
        `)
        out.close()
    }

    export function addIntr(name: string | null) {
        intr_list.push(name ?? NO_VEC)
    }

    export function useIntr(name: string, h?: IrqI.Handler) {
        used_set.add(name)
    }
}

//>> ---- em$targ ---- <<//

const CLIC_BASE: u32 = 0xF0001000
const CLIC_ENABLE: u32 = 0x00000100
const CLIC_PENDING: u32 = 0x00000001

export function em$startup() {
    const mtvec = (<u32>e$`&em__riscv_default_irq_entry`) | 3
    const mtvt = <u32>e$`&__riscv_irq_vector_table`
    CSR.write(CSR.MTVEC, mtvec)
    CSR.write(CSR.MTVT, mtvt)
}

export function DEFAULT_isr$$() {
    IsrDefault.exec()
    fail()
}

function CLICINT(irq: u16): u32 {
    return CLIC_BASE + (<u32>irq << 2)
}

export function force(irq: u16) {
    const addr = CLICINT(irq)
    $reg32[addr] |= CLIC_ENABLE
    $reg32[addr] |= CLIC_PENDING
}

// IrqI implementation

export function enable(irq: u16) {
    $reg32[CLICINT(irq)] |= CLIC_ENABLE
}

export function disable(irq: u16) {
    $reg32[CLICINT(irq)] &= ~CLIC_ENABLE
}

export function clear(irq: u16) {
    $reg32[CLICINT(irq)] &= ~CLIC_PENDING
}

export function isEnabled(irq: u16): bool_t {
    return ($reg32[CLICINT(irq)] & CLIC_ENABLE) != 0
}

export function setPriority(irq: u16, pri: u8) {
    const addr = CLICINT(irq)
    const val = pri <= 3 ? ((<u32>pri << 6) + 0x3f) : 0
    $reg32[addr] = ($reg32[addr] & 0x00ffffff) | (val << 24)
}
