import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as ArmStartupC from '@em.arch.arm/StartupC.em'
import * as BoardC from '@nordic.distro.nrf52/BoardC.em'
import * as CompilerC from '@em.target.compiler/CompilerC.em'
import * as IsrEmpty from '@em.arch.arm/IsrEmpty.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LinkerC from '@em.build.segger/LinkerC.em'
import * as REGS from '@nordic.distro.nrf52/REGS.em'
import * as StartupC from '@nordic.distro.nrf52/StartupC.em'
import * as TargC from '@em.lang/TargC.em'

const NVIC_INTRS = <Array<string>>[
    'POWER_CLOCK',
    'RADIO',
    'UARTE0_UART0                                                           ',
    'SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0',
    'SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1',
    'NFCT',
    'GPIOTE',
    'SAADC',
    'TIMER0',
    'TIMER1',
    'TIMER2',
    'RTC0',
    'TEMP',
    'RNG',
    'ECB',
    'CCM_AAR',
    'WDT',
    'RTC1',
    'QDEC',
    'COMP_LPCOMP',
    'SWI0_EGU0',
    'SWI1_EGU1',
    'SWI2_EGU2',
    'SWI3_EGU3',
    'SWI4_EGU4',
    'SWI5_EGU5',
    'TIMER3',
    'TIMER4',
    'PWM0',
    'PDM',
    'MWU',
    'PWM1',
    'PWM2',
    'SPIM2_SPIS2_SPI2',
    'RTC2',
    'I2S',
    'FPU',
]

export function em$configure() {
    $using(ArmStartupC)
    $using(BoardC)
    $using(CompilerC)
    $using(IntrVec)
    $using(LinkerC)
    $using(REGS)
    $using(StartupC)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrEmpty
    for (const name of NVIC_INTRS) IntrVec.em$meta.addIntr(name)
}

export function em$generate() {
    const linkerOptions = CompilerC.genScript({ cpu: 'cortex-m4', fpu: false })
    LinkerC.genScript({
        dmem_flash: { orig: 0x20000000, len: 0x00004000 },
        imem_flash: { orig: 0x00000000, len: 0x00008000 },
        dmem_sram: { orig: 0x20000000, len: 0x00004000 },
        imem_sram: { orig: 0x00808000, len: 0x00008000 },
        lmem_sram: { orig: 0x00000000, len: 0x00008000 },
        cmem_sram: { orig: 0x20008000, len: 0x00008000 },
    }, [], linkerOptions)
    const tools = $property('em.build.ToolsHome', '')
    const ext = process.platform === 'win32' ? '.exe' : 'Exe'
    const out = $outfile('load.sh', 0o755)
    const exec = `${tools}/segger-jlink/JLink${ext}`
    out.addText(`${exec} -CommandFile ../nordic.nrf52/nordic.distro.nrf52/jlink-cmds`)
    out.close()
}
