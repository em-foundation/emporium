import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as ArmStartupC from '@em.arch.arm/StartupC.em'
import * as BoardC from '@nordic.distro.nrf91/BoardC.em'
import * as CompilerC from '@em.target.compiler/CompilerC.em'
import * as IsrEmpty from '@em.arch.arm/IsrEmpty.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LinkerC from '@em.build.segger/LinkerC.em'
import * as REGS from '@nordic.distro.nrf91/REGS.em'
import * as StartupC from '@nordic.distro.nrf91/StartupC.em'
import * as TargC from '@em.lang/TargC.em'

const NVIC_INTRS = <Array<string>>[
    null,
    null,
    null,
    'SPU',                              //!< 3  SPU
    null,
    'CLOCK_POWER',                      //!< 5  CLOCK_POWER
    null,
    null,
    'SPIM0_SPIS0_TWIM0_TWIS0_UARTE0',   //!< 8  SPIM0_SPIS0_TWIM0_TWIS0_UARTE0
    'SPIM1_SPIS1_TWIM1_TWIS1_UARTE1',   //!< 9  SP/M1_SPIS1_TWIM1_TWIS1_UARTE1
    'SPIM2_SPIS2_TWIM2_TWIS2_UARTE2',   //!< 10 SPIM2_SPIS2_TWIM2_TWIS2_UARTE2
    'SPIM3_SPIS3_TWIM3_TWIS3_UARTE3',   //!< 11 SPIM3_SPIS3_TWIM3_TWIS3_UARTE3                                 
    null,
    'GPIOTE0',                          //!< 13 GPIOTE0
    'SAADC',                            //!< 14 SAADC     
    'TIMER0',                           //!< 15 TIMER0    
    'TIMER1',                           //!< 16 TIMER1    
    'TIMER2',                           //!< 17 TIMER2    
    null,
    null,
    'RTC0',                             //!< 20 RTC0      
    'RTC1',                             //!< 21 RTC1      
    null,
    null,
    'WDT',                              //!< 24 WDT       
    null,
    null,
    'EGU0',                             //!< 27 EGU0      
    'EGU1',                             //!< 28 EGU1      
    'EGU2',                             //!< 29 EGU2      
    'EGU3',                             //!< 30 EGU3      
    'EGU4',                             //!< 31 EGU4      
    'EGU5',                             //!< 32 EGU5      
    'PWM0',                             //!< 33 PWM0      
    'PWM1',                             //!< 34 PWM1      
    'PWM2',                             //!< 35 PWM2      
    'PWM3',                             //!< 36 PWM3      
    null,
    'PDM',                              //!< 38 PDM       
    null,
    'I2S',                              //!< 40 I2S       
    null,
    'IPC',                              //!< 42 IPC       
    null,
    'FPU',                              //!< 44 FPU       
    null,
    null,
    null,
    null,
    'GPIOTE1',                          //!< 49 GPIOTE1   
    null,
    null,
    null,
    null,
    null,
    null,
    null,
    'KMU',                              //!< 57 KMU       
    null,
    null,
    null,
    null,
    null,
    null,
    'CRYPTOCELL',                       //!< 64 CRYPTOCELL
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
    const use_sram = $property('em.build.BootFlash', false)
    const tfm_image = use_sram ? 'tfm_s-cache-off.hex' : 'tfm_s.hex'
    const suffix = process.platform === 'win32' ? '.exe' : ''
    const linkerOptions = CompilerC.genScript({
        cpu: 'cortex-m33',
        fpu: $property('em.build.FPU', '') === 'true',
        includeDirs: ['../em.core/em.arch.arm/inc'],
    }, `
SREC="$TOOLS_HOME/srecord/bin/srec_cat${suffix}"
"$SREC" "../nordic.nrf91/nordic.distro.nrf91/${tfm_image}" -Intel "$OUT/main.out.hex" -Intel -o "$OUT/merged.hex" -Intel`)
    LinkerC.genScript({
        dmem_flash: { orig: 0x20008000, len: 0x00008000 },
        imem_flash: { orig: 0x00008000, len: 0x00008000 },
        dmem_sram: { orig: 0x20008000, len: 0x00006000 },
        imem_sram: { orig: 0x2000e000, len: 0x00002000 },
        lmem_sram: { orig: 0x00008000, len: 0x00006000 },
        cmem_sram: LinkerC.MEM_NULL,
    }, [], linkerOptions)
    const tools = $property('em.build.ToolsHome', '')
    const ext = (process.platform === 'win32') ? '.exe' : 'Exe'
    let out = $outfile('load.sh', 0o755)
    const exec = `${tools}/segger-jlink/JLink${ext}`
    out.addText(`${exec} -CommandFile ../nordic.nrf91/nordic.distro.nrf91/jlink-cmds`)
    out.close()
    out = $outfile('debug.sh', 0o755)
    out.addText(`${exec} -CommandFile ../nordic.nrf91/nordic.distro.nrf91/jlink-debug-cmds`)
    out.close()
}
