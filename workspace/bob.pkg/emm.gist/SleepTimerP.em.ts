import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arc/IntrVec.em'
import * as MemDump from '@em.utils/MemDump.em'

const AppButPin = $delegate(BoardC.AppButPin)
const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('SLEEP_TIMER_OUT_CMP_0')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    AppLed.on()
    Common.BusyWait.wait(10000)
    AppLed.off()
    if (Common.Mcu.isWarm()) {
        halt()
    }
    // Common.GlobalInterrupts.enable()
    // $R.IRQ.RegIRQSleepTimEnSet.$$ = 1
    // $R.IRQ.RegIRQSleepTimMskSet.$$ = 1
    $R.PML.RegSleepTimCtrl.$$ = $R.ST_CLEAR_MASK
    $R.PML.RegSleepTimCtrl.$$ = 0
    $R.PML.RegSleepTimCompareCfg.$$ = 0x0001_0001
    $R.PML.RegSleepTimCompare0.$$ = 32678
    while ($R.PML.RegSleepTimCount.$$ != 0) { }
    $R.PML.RegSleepTimCtrl.$$ = $R.ST_RUN_EN_MASK
    $['%%d']
    Common.Idle.exec()
}

export function SLEEP_TIMER_OUT_CMP_0_isr$$() {
    halt()
    $['%%c']
    $R.IRQ.RegIRQSleepTimStsClr.$$ = 1
    $R.PML.RegSleepTimCtrl.$$ = 0
}


