import '@$$emscript'
export const $U = $declare('MODULE', IrqI)

import * as IrqI from '@em.hal/IrqI.em'

export namespace em$meta {
    export function addIntr(name: string) { }

    export function addIntrNames(names: Array<string>) { }

    export function useIntr(name: string, h?: IrqI.Handler) { }
}

//>> ---- em$targ ---- <<//

export function clear(irq: u16) { }

export function disable(irq: u16) { }

export function enable(irq: u16) { }

export function isEnabled(irq: u16): bool_t { return false }

export function setPriority(irq: u16, pri: u8) { }
