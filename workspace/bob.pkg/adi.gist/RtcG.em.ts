import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@maxim.distro.326xx/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('RTC')
    }
}

//>> ---- em$targ ---- <<//

// export function em$startup() {
//     $R.GCR.CLKCTRL.$$ |= $R.F_GCR_CLKCTRL_ERTCO_EN
//     $R.GCR.PM.$$ |= $R.F_GCR_PM_RTC_WE
//     IntrVec.NVIC_enable(e$`RTC_IRQn`)
// }

export function em$run() {
    $R.RTC.CTRL.$$ &= ~$R.F_RTC_CTRL_EN
    while ($R.RTC.CTRL.$$ & $R.F_RTC_CTRL_BUSY) { } // KEEP
    $R.RTC.SSECA.$$ = 0xffffffff - (1 << 12) // 1 SEC ALARM
    $R.RTC.CTRL.$$ |= $R.F_RTC_CTRL_SSEC_ALARM_IE
    while ($R.RTC.CTRL.$$ & $R.F_RTC_CTRL_BUSY) { } // KEEP
    $R.RTC.CTRL.$$ |= $R.F_RTC_CTRL_EN
    Common.GlobalInterrupts.$$.enable()
    Common.Idle.$$.exec()
}

// export function RTC_isr$$() {
//     $['%%d']
//     IntrVec.NVIC_clear(e$`RTC_IRQn`)
//     halt()
// }