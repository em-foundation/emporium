import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    delay(5_000_000)
    // GPIO
    $R.RESETS_CLR.RESET.$$ = $R.RESETS_RESET_io_bank0_Msk | $R.RESETS_RESET_pads_bank0_Msk
    $reg32[e$`IO_BANK0_CTRL_get(13)`] = 5
    $R.SIO.GPIO_OE_SET.$$ = (1 << 13)
    wink(1_000_000)
    // UART
    $R.RESETS_CLR.RESET.$$ = $R.RESETS_RESET_uart0_Msk
    $reg32[e$`IO_BANK0_CTRL_get(0)`] = 2
    $R.UART0.UARTCR.$$ = 0
    $R.UART0.UARTIBRD.$$ = 67
    $R.UART0.UARTFBRD.$$ = 52
    $R.UART0.UARTLCR_H.$$ = 3 << $R.UART0_UARTLCR_H_WLEN_Pos
    $R.UART0.UARTCR.$$ = $R.UART0_UARTCR_TXE_Msk | $R.UART0_UARTCR_UARTEN_Msk
    for (const b of $range(0x30, 0x35)) {
        put(b)
        put(0x55)
        wink(500_000)
    }
    stop()
}

function delay(cnt: u32) {
    let x: volatile_t<u32> = 0
    for (const _ of $range(cnt)) x = 0
}

function put(b: u8) {
    $R.UART0.UARTDR.$$ = b
    while ($R.UART0.UARTFR.$$ & $R.UART0_UARTFR_BUSY_Msk) { }
}

function stop() {
    while (true) {
        e$`__asm volatile ("bkpt #0")`
    }
}

function wink(cnt: u32) {
    $R.SIO.GPIO_OUT_SET.$$ = (1 << 13)
    delay(cnt)
    $R.SIO.GPIO_OUT_CLR.$$ = (1 << 13)
}