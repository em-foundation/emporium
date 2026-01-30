import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

const AppButPin = $delegate(BoardC.AppButPin)

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('GPIO_EVEN')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    IntrVec.NVIC_enable(e$`GPIO_EVEN_IRQn`)
    AppButPin.makeInput()
    $R.GPIO.EXTIPSELL_SET.$$ = $R.GPIO_EXTIPSELL_EXTIPSEL0_PORTA
    $R.GPIO.EXTIPINSELL_SET.$$ = $R.GPIO_EXTIPINSELL_EXTIPINSEL0_OFFSET0
    $R.GPIO.EXTIFALL_SET.$$ = 1
    $R.GPIO.IEN_SET.$$ = $R.GPIO_IEN_EXTIEN0
    $R.GPIO.IF_CLR.$$ = $R.GPIO_IF_EXTIF0
    Common.GlobalInterrupts.enable()
    Common.Idle.exec()
}

export function GPIO_EVEN_isr$$() {
    halt()
}