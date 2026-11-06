import '@$$emscript'
export const $U = $declare('MODULE')

import * as BusyWait from '@em.utils/BusyWait.em'
import * as GpioI from '@em.hal/GpioI.em'

export const CS = $proxy<GpioI.$I>()
export const CLK = $proxy<GpioI.$I>()
export const PICO = $proxy<GpioI.$I>()
export const POCI = $proxy<GpioI.$I>()

const SD_CMD = <u8>0xb9

export function em$startup() {
    $['%%c+']
    // DIO3 is also DBG-B. Restore its output level after sending the command.
    const clkWasOutput = CLK.isOutput()
    const clkWasHigh = CLK.get()
    CS.set()
    CS.makeOutput()
    CLK.clear()
    CLK.makeOutput()
    PICO.makeOutput()
    POCI.makeInput()
    // attention
    BusyWait.wait(1)
    CS.clear()
    BusyWait.wait(1)
    CS.set()
    BusyWait.wait(50)
    // shutdown command
    CS.clear()
    for (let i of $range(8)) {
        CLK.clear()
        const bv = (SD_CMD >> (7 - i)) & 0x01
        if (bv == 0) {
            PICO.clear()
        } else {
            PICO.set()
        }
        CLK.set()
        BusyWait.wait(1)
    }
    CLK.clear()
    CS.set()
    BusyWait.wait(50)
    // Keep the flash deselected while DBG-B uses the shared clock pin.
    if (clkWasOutput) {
        if (clkWasHigh) CLK.set()
    } else {
        CLK.reset()
    }
    PICO.reset()
    POCI.reset()
    $['%%c-']
}
