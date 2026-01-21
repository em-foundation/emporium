import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as GpioT from '@rpi.mcu.2040/GpioT.em'

export const SysLedPin = $clone(GpioT)

export namespace em$meta {
    export function em$configure() {
        SysLedPin.pin_num.$$val = 13
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    delay(5)
    // GPIO
    $R.RESETS_CLR.RESET.$$ = $R.RESETS_RESET_io_bank0_Msk | $R.RESETS_RESET_pads_bank0_Msk
    SysLedPin.makeOutput()
    SysLedPin.clear()
    for (const _ of $range(10)) {
        SysLedPin.toggle()
        delay(5)        
    }
    SysLedPin.set()
    stop()
}

function delay(cnt: u32) {
    let x: volatile_t<u32> = 0
    for (const _ of $range(cnt * 1_000_000)) x = 0
}

function stop() {
    while (true) {
        e$`__asm volatile ("bkpt #0")`
    }
}
