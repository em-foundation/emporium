import '@$$emscript'
export const $U = $declare('MODULE', ConsoleUartI)

import * as Common from '@em.mcu/Common.em'
import * as ConsoleUartI from '@em.hal/ConsoleUartI.em'
import * as GpioI from '@em.hal/GpioI.em'

export const baud_rate = $config<u32>(57_600)
export const TxPin = $proxy<GpioI.$I>()

const bit_time = $config<u16>()

export namespace em$meta {
    export function em$construct() {
        bit_time.$$val = Math.floor(1_000_000 / baud_rate)
    }
}

//>> ---- em$targ ---- <<//

export function em$startup(): void {
    TxPin.makeOutput()
    TxPin.set()
}

export function flush(): void { }

export function put(data: u8): void {
    const bit_cnt = 10
    let tx_bits: u16 = (data << 1) | 0x600
    const key = Common.GlobalInterrupts.disable()
    for (const _ of $range(bit_cnt)) {
        if (tx_bits & 0x1) {
            TxPin.set()
        } else {
            TxPin.clear()
        }
        tx_bits >>= 1
        Common.UsCounter.set(bit_time)
        Common.UsCounter.spin()
    }
    TxPin.set()
    Common.GlobalInterrupts.restore(key)
}
