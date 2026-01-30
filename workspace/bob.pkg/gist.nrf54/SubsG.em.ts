import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as Rtc from '@nordic.nrf5x/nordic.mcu.nrf54/Rtc.em'
import * as TimeTypes from '@em.utils/TimeTypes.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    // const del = TimeTypes.Secs24p8_initMsecs(2_500)
    // printf`del = %08x\n`(del)
    const thr = Rtc.toThresh(0x280)
    printf`thr = %d\n`(thr)

    // const t0 = Rtc.readHiLo()
    // Common.BusyWait.$$.wait(500_000)
    // const t1 = Rtc.readHiLo()
    // const s0 = <u32>(t0 / 1_000_000)
    // const u0 = <u32>(t0 % 1_000_000)
    // const s1 = <u32>(t1 / 1_000_000)
    // const u1 = <u32>(t1 % 1_000_000)
    // printf`s0 = %d, u0 = %d, s1 = %d, u1 = %d\n`(s0, u0, s1, u1)

    // const r0 = Rtc.getRawTime64()
    // Common.BusyWait.$$.wait(500_000)
    // const r1 = Rtc.getRawTime64()
    // printf`r0 = %08x:%08x, r1 = %08x:%08x\n`(r0.secs, r0.subs, r1.secs, r1.subs)


    // const hi0 = <u32>(t0 >> 32)
    // const lo0 = <u32>(t0)
    // const hi1 = <u32>(t1 >> 32)
    // const lo1 = <u32>(t1)
    // printf`t0 = %08x:%08x, t1 = %08x:%08x\n`(hi0, lo0, hi1, lo1)

    // const dt = <u32>(t1 - t0)
    // printf`dt = %d\n`(dt)
    // //
    // const r0 = Rtc.getRawTime()
    // Common.BusyWait.$$.wait(500_000)
    // const r1 = Rtc.getRawTime()
    // printf`r0 = %08x:%08x, r1 = %08x:%08x\n`(r0.secs, r0.subs, r1.secs, r1.subs)
    // const s0 = TimeTypes.RawTimeToSecs24p8(r0)
    // const s1 = TimeTypes.RawTimeToSecs24p8(r1)
    // const ds = s1 - s0
    // printf`s0 = %08x, s1 = %08x, ds = %d\n`(s0, s1, ds)
}