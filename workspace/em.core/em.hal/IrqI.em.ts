import '@$$emscript'
export const $U = $declare('INTERFACE')

export type Handler = cb_t<[]>

export interface em$meta {
    addIntr(name: string): void
    useIntr(name: string, h?: Handler): void
}

export interface $I {
    em$meta: em$meta
    clear(irq: u16): void
    disable(irq: u16): void
    enable(irq: u16): void
    isEnabled(irq: u16): bool_t
    setPriority(irq: u16, pri: u8): void
}
