import em from '@$$emscript'
export const $U = em.$declare('MODULE')

const GPIOn = e$`MXC_GPIO_GET_GPIO(1)`

var addr = <u32>GPIOn

export function em$run() {
    e$`asm volatile ("bkpt")`
    $['%%>'](addr)
    e$`asm volatile ("bkpt")`
}
