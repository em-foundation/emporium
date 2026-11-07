import '@$$emscript'
export const $U = $declare('MODULE')

import * as RfTemp from '@ti.radio.cc27xx/RfTemp.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

// LP_EM_CC2755P10 0 dBm entry 0x1E0C94: coefficient 30, raw PA setting 0x0C94.
export function program(level: i8): void {
    if (level != 0) fail()
    let value: u32 = 0x0c94
    let ib: i32 = (value >> 2) & 0x3f
    ib += (RfTemp.getTemperature() - 25) * 30 / 256
    if (ib < 1) ib = 1
    if (ib > 63) ib = 63
    value = (value & ~0xfc) | (<u32>ib << 2)
    $R.LRFDRFE.SPARE5.$$ = value
}
