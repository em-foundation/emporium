import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as Idle from '@nordic.mcu.nrf52/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export type Handler = cb_t<[]>

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('POWER_CLOCK')
    }
}

//>> ---- em$targ ---- <<//

var pause_level: u32
var ready_handler: Handler = $null

export function start(handler: Handler) {
    const key = GlobalInterrupts.disable()
    IntrVec.NVIC_disable(e$`POWER_CLOCK_IRQn`)
    $R.CLOCK.INTENCLR.$$ = $R.CLOCK_INTENSET_HFCLKSTARTED_Set
    $R.CLOCK.EVENTS_HFCLKSTARTED.$$ = 0
    IntrVec.NVIC_clear(e$`POWER_CLOCK_IRQn`)
    if (ready_handler != $null) Idle.setLevel(pause_level)
    ready_handler = handler
    if (handler != $null) {
        pause_level = Idle.getLevel()
        Idle.setLevel(1)
        $R.CLOCK.INTENSET.$$ = $R.CLOCK_INTENSET_HFCLKSTARTED_Set
        IntrVec.NVIC_enable(e$`POWER_CLOCK_IRQn`)
    }
    $['%%d+']
    $R.CLOCK.TASKS_HFCLKSTART.$$ = 1
    Common.BusyWait.wait(5)
    $['%%d-']
    GlobalInterrupts.restore(key)
}

export function stop() {
    const key = GlobalInterrupts.disable()
    if (ready_handler != $null) Idle.setLevel(pause_level)
    ready_handler = $null
    $R.CLOCK.INTENCLR.$$ = $R.CLOCK_INTENSET_HFCLKSTARTED_Set
    IntrVec.NVIC_disable(e$`POWER_CLOCK_IRQn`)
    $R.CLOCK.TASKS_HFCLKSTOP.$$ = 1
    $R.CLOCK.EVENTS_HFCLKSTARTED.$$ = 0
    IntrVec.NVIC_clear(e$`POWER_CLOCK_IRQn`)
    GlobalInterrupts.restore(key)
}

export function wait() {
    while ($R.CLOCK.EVENTS_HFCLKSTARTED.$$ == 0) {
    }
}

export function POWER_CLOCK_isr$$() {
    IntrVec.NVIC_clear(e$`POWER_CLOCK_IRQn`)
    if ($R.CLOCK.EVENTS_HFCLKSTARTED.$$ == 0) return
    $R.CLOCK.INTENCLR.$$ = $R.CLOCK_INTENSET_HFCLKSTARTED_Set
    $R.CLOCK.EVENTS_HFCLKSTARTED.$$ = 0
    const handler = ready_handler
    ready_handler = $null
    if (handler != $null) {
        Idle.setLevel(pause_level)
        handler()
    }
}
