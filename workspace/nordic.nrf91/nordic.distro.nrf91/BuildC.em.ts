import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as ArmStartupC from '@em.arch.arm/StartupC.em'
import * as BoardC from '@nordic.distro.nrf91/BoardC.em'
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
    $using(IntrVec)
    $using(LinkerC)
    $using(REGS)
    $using(StartupC)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrEmpty
    for (const name of NVIC_INTRS) IntrVec.em$meta.addIntr(name)
}

export function em$generate() {
    LinkerC.genScript({
        dmem_flash: { orig: 0x20000000, len: 0x00004000 },
        imem_flash: { orig: 0x00000000, len: 0x00008000 },
        dmem_sram: { orig: 0x20000000, len: 0x00004000 },
        imem_sram: { orig: 0x20004000, len: 0x00008000 },
        lmem_sram: { orig: 0x00000000, len: 0x00008000 },
        cmem_sram: LinkerC.MEM_NULL,
    })
    let opt = $property('em.build.Optimize', 'Oz')
    let tools = $property('em.build.ToolsHome', '')
    let fpu = $property('em.build.FPU', '')
    let fpuabi = fpu ? 'hard' : 'soft'
    let fpudef = fpu ? '1' : '0'
    let libarch = fpu ? 'v8mml_fpv5_sp_d16_hard' : 'v6m'
    let libflav = opt == 'Oz' && !fpu ? 'small' : 'balanced'
    let out = $outfile('build.sh', 0o755)
    out.addFrag(`
        |-> #!/bin/sh
        |-> 
        |-> set -e
        |-> 
        |-> TOOLS=${tools}/segger-arm
        |-> CC=$TOOLS/bin/segger-cc
        |-> LD=$TOOLS/gcc/arm-none-eabi/bin/ld
        |-> OBJCOPY=$TOOLS/gcc/arm-none-eabi/bin/objcopy
        |-> OBJDUMP=$TOOLS/gcc/arm-none-eabi/bin/objdump
        |-> 
        |-> OUT=.out
        |-> 
        |-> rm -rf $OUT
        |-> mkdir $OUT
        |-> 
        |-> 
        |-> CFLAGS="\\
        |->     -D__EM_ARCH_arm__ \\
        |->     -D__EM_BOOT__=0 \\
        |->     -D__EM_BOOT_FLASH__=0 \\
        |->     -D__EM_COMPILER_segger__ \\
        |->     -D__EM_CPU_cortex_m33__ \\
        |->     -D__EM_MCU_null__ \\
        |->     -D__EM_LANG__=1 \\
        |->     -D__GNUC__ \\
        |->     -D__FPU_PRESENT=${fpudef} \\
        |->     -D__FPU_USED=${fpudef} \\
        |->     --std=c++14 \\
        |->     -triple thumbv6m-none-eabi \\
        |->     -target-cpu cortex-m33 \\
        |->     -ffunction-sections \\
        |->     -fdata-sections \\
        |->     -fno-threadsafe-statics \\
        |->     -Wno-deprecated-register \\
        |->     -Wno-invalid-noreturn \\
        |->     -Wno-macro-redefined \\
        |->     -Wno-switch \\
        |->     -Wno-uninitialized \\
        |->     -Wno-c99-designator \\
        |->     -Wno-c++20-designator \\
        |->     -Wpointer-to-int-cast \\
        |->     -target-feature +strict-align -mfloat-abi ${fpuabi} -target-abi aapcs -fno-signed-char -fnative-half-type -fnative-half-arguments-and-returns \\
        |-> "
        |-> 
        |-> CINCS="\\
        |->     -I . \\
        |->     -I $TOOLS/include \\
        |->     -I ../em.core/em.arch.arm/inc \\
        |-> "
        |-> 
        |-> COPTS="\\
        |->     -${opt} \\
        |-> "
        |-> 
        |-> LFLAGS="\\
        |->     -eem__start \\
        |->     -N \\
        |->     --gc-sections \\
        |-> "
        |-> 
        |-> LIBS="
        |->     $TOOLS/lib/libc_${libarch}_t_le_eabi_${libflav}.a \\
        |->     $TOOLS/lib/strops_${libarch}_t_le_eabi_${libflav}.a \\
        |-> "
        |-> 
        |-> $CC -c $CFLAGS $CINCS $COPTS -x c++ main.cpp -o $OUT/main.obj
        |-> $LD $LFLAGS -Map=$OUT/main.map -T linkcmd.ld -o $OUT/main.out $OUT/main.obj $LIBS
        |-> $OBJCOPY -O ihex $OUT/main.out $OUT/main.out.hex
        |-> $OBJDUMP -h -d --demangle $OUT/main.out >$OUT/main.out.dis
        |-> $OBJDUMP -t --demangle $OUT/main.out | tail -n +5 | sed -e 's/[FO] /  /' | sed -e 's/df /   /' >$OUT/main.out.sym
        |-> sort -k1 $OUT/main.out.sym > $OUT/main.out.syma
        |-> sort -k5 $OUT/main.out.sym > $OUT/main.out.symn
        |-> $OBJDUMP -h $OUT/main.out

    `)
    out.close()
    //
    const ext = (process.platform === 'win32') ? '.exe' : 'Exe'
    out = $outfile('load.sh', 0o755)
    const exec = `${tools}/segger-jlink/JLink${ext}`
    out.addText(`${exec} -CommandFile ../nordic.nrf91/nordic.distro.nrf91/jlink-cmds`)
    out.close()
}
