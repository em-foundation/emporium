import '@$$emscript'
export const $U = $declare('MODULE')

import * as BusyWaitI from '@em.hal/BusyWaitI.em'
import * as BusyWaitN from '@em.hal/BusyWaitN.em'
import * as ConsoleUartI from '@em.hal/ConsoleUartI.em'
import * as ConsoleUartN from '@em.hal/ConsoleUartN.em'
import * as GlobalInterruptsI from '@em.hal/GlobalInterruptsI.em'
import * as GlobalInterruptsN from '@em.hal/GlobalInterruptsN.em'
import * as IdleI from '@em.hal/IdleI.em'
import * as IdleN from '@em.hal/IdleN.em'
import * as McuI from '@em.hal/McuI.em'
import * as McuN from '@em.hal/McuN.em'
import * as UptimerI from '@em.hal/UptimerI.em'
import * as UptimerN from '@em.hal/UptimerN.em'
import * as UsCounterI from '@em.hal/UsCounterI.em'
import * as UsCounterN from '@em.hal/UsCounterN.em'

export const BusyWait = $proxy<BusyWaitI.$I>()
export const ConsoleUart = $proxy<ConsoleUartI.$I>()
export const GlobalInterrupts = $proxy<GlobalInterruptsI.$I>()
export const Idle = $proxy<IdleI.$I>()
export const Mcu = $proxy<McuI.$I>()
export const Uptimer = $proxy<UptimerI.$I>()
export const UsCounter = $proxy<UsCounterI.$I>()

export namespace em$meta {
    export function em$configure() {
        if (BusyWait.$U === null) BusyWait.$$dlg = BusyWaitN
        if (ConsoleUart.$U === null) ConsoleUart.$$dlg = ConsoleUartN
        if (GlobalInterrupts.$U === null) GlobalInterrupts.$$dlg = GlobalInterruptsN
        if (Idle.$U === null) Idle.$$dlg = IdleN
        if (Mcu.$U === null) Mcu.$$dlg = McuN
        if (Uptimer.$U === null) Uptimer.$$dlg = UptimerN
        if (UsCounter.$U === null) UsCounter.$$dlg = UsCounterN
    }
}