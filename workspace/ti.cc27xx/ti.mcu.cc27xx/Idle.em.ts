import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as Debug from '@em.lang/Debug.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as IdleI from '@em.hal/IdleI.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

const sleep_enter_tab = $table<IdleI.SleepCB>()
const sleep_leave_tab = $table<IdleI.SleepCB>()

export namespace em$meta {
    export function addSleepEnter(cb: IdleI.SleepCB): void {
        sleep_enter_tab.$$add(cb)
    }

    export function addSleepLeave(cb: IdleI.SleepCB): void {
        sleep_leave_tab.$$add(cb)
    }
}

var cur_level: volatile_t<IdleI.SleepLevel> = 0

export function em$startup(): void {
    $['%%b+']
    $R.PMCTL.VDDRCTL.$$ = $R.PMCTL_VDDRCTL_SELECT_DCDC
    $R.EVTULL.WKUPMASK.$$ |= $R.EVTULL_WKUPMASK_AON_RTC_COMB
    if (($R.CKMD.LFCLKSEL.$$ & $R.CKMD_LFCLKSEL_MAIN_M) == $R.CKMD_LFCLKSEL_MAIN_FAKE) {
        $R.CKMD.LFOSCCTL.$$ |= $R.CKMD_LFOSCCTL_EN
        $R.CKMD.LFCLKSEL.$$ = $R.CKMD_LFCLKSEL_MAIN_LFOSC
    }
}

export function exec(): void {
    IntrVec.PRIMASK_set(1)
    if (cur_level > 0) {
        $['%%b:'](1)
        $['%%b-']
        e$`asm volatile ("wfi" ::: "memory")`
        $['%%b+']
    } else if (($R.RTC.ARMSET.$$ & $R.RTC_ARMSET_CH0)
        && !($R.RTC.RIS.$$ & $R.RTC_RIS_EV0)
        && !($R.CKMD.LFCLKSTAT.$$ & $R.CKMD_LFCLKSTAT_LFTICKSRC_FAKE)) {
        doSleep()
    }
    IntrVec.PRIMASK_set(0)
}

function doSleep(): void {
    for (const cb of sleep_enter_tab) cb()
    $['%%b:'](2)
    $['%%b-']
    Debug.reset()
    e$`SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk`
    e$`HapiEnterStandby(nullptr)`
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_GPIO
    $R.PMCTL.AONRSET1.$$ = $R.PMCTL_AONRSET1_VDDIOPGIO_SET
    Debug.startup()
    $['%%b+']
    for (const cb of sleep_leave_tab) cb()
}

export function getLevel(): IdleI.SleepLevel {
    return cur_level
}

export function setLevel(level: IdleI.SleepLevel): void {
    cur_level = level
}

export function wakeup(): void { }
