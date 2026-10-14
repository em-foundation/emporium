import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_LED_PIN = 15

export function em$run() {
    const pin = APP_LED_PIN
    const mask = 1 << pin
    e$`*(volatile uint32_t*)(GPIO_BASE + GPIO_O_DOESET31_0) = mask`
    e$`*(volatile uint32_t*)(IOC_BASE + IOC_O_IOC0 + (pin) * 4) &= ~IOC_IOC0_INPEN`
    e$`*(volatile uint32_t*)(GPIO_BASE + GPIO_O_DOUTSET31_0) = mask`
}
