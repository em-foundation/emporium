import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@nordic.nrf5x/nordic.distro.nrf54/BoardC.em'
import * as Common from '@em.mcu/Common.em'

export const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta { }

export function em$run() {
    AppLed.$$.on()
    Common.BusyWait.$$.wait(100_000)
    AppLed.$$.off()
    // e$`SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk`
    // e$`SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk`
    // $R.GCR.PM.$$ |= $R.S_GCR_PM_MODE_STANDBY
    // e$`asm volatile ("wfi")`
    Common.Idle.$$.exec()
}