import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as UsCounter from '@em.arch.arc/UsCounterTimer0.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    UsCounter.start()
    $['%%c+']
    Common.BusyWait.wait(1000)
    $['%%c-']
    let cnt = UsCounter.stop()
    printf`cnt = %d\n`(cnt)

    // e$`_sr(0, REG_COUNT0)`
    // let cnt = e$`_lr(REG_COUNT0)`
    // printf`cnt = %d\n`(cnt)

    // e$`_sr(1, AUX_RTC_CTRL)`
    // $['%%c+']
    // Common.BusyWait.wait(1000)
    // $['%%c-']
    // let rtc_low: u32 = e$`_lr(AUX_RTC_LOW)`
    // printf`t = %d\n`(rtc_low)
}