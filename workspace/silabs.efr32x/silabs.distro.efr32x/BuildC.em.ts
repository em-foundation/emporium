import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as ArmStartupC from '@em.arch.arm/StartupC.em'
import * as BoardC from '@silabs.distro.efr32x/BoardC.em'
import * as IsrDefault from '@em.arch.arm/IsrEmpty.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LinkerC from '@em.build.segger/LinkerC.em'
import * as REGS from '@silabs.distro.efr32x/REGS.em'
import * as StartupC from '@silabs.distro.efr32x/StartupC.em'
import * as TargC from '@em.lang/TargC.em'

const NVIC_INTRS = [
    'CRYPTOACC',
    'TRNG',
    'PKE',
    'SMU_SECURE',
    'SMU_S_PRIVILEGED',
    'SMU_NS_PRIVILEGED',
    'EMU',
    'TIMER0',
    'TIMER1',
    'TIMER2',
    'TIMER3',
    'TIMER4',
    'RTCC',
    'USART0_RX',
    'USART0_TX',
    'USART1_RX',
    'USART1_TX',
    'ICACHE0',
    'BURTC',
    'LETIMER0',
    'SYSCFG',
    'LDMA',
    'LFXO',
    'LFRCO',
    'ULFRCO',
    'GPIO_ODD',
    'GPIO_EVEN',
    'I2C0',
    'I2C1',
    'EMUDG',
    'EMUSE',
    'AGC',
    'BUFC',
    'FRC_PRI',
    'FRC',
    'MODEM',
    'PROTIMER',
    'RAC_RSM',
    'RAC_SEQ',
    'RDMAILBOX',
    'RFSENSE',
    'PRORTC',
    'SYNTH',
    'WDOG0',
    'HFXO0',
    'HFRCO0',
    'CMU',
    'AES',
    'IADC',
    'MSC',
    'DPLL0',
    'PDM',
    'SW0',
    'SW1',
    'SW2',
    'SW3',
    'KERNEL0',
    'KERNEL1',
    'M33CTI0',
    'M33CTI1',
    'EMUEFP',
    'DCDC',
    'EUART0_RX',
    'EUART0_TX',
]

export function em$configure() {
    $using(ArmStartupC)
    $using(BoardC)
    $using(IntrVec)
    $using(LinkerC)
    $using(REGS)
    $using(StartupC)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrDefault
    for (let name of NVIC_INTRS) IntrVec.em$meta.addIntr(name)
}

export function em$generate() {
    LinkerC.genScript({
        dmem_flash: { orig: 0x20000000, len: 0x00008000 },
        imem_flash: { orig: 0x00000000, len: 0x00080000 },
        dmem_sram: { orig: 0x20004000, len: 0x00004000 },
        imem_sram: { orig: 0x20004000, len: 0x00004000 },
        lmem_sram: { orig: 0x10000000, len: 0x00004000 },
    })
    let opt = $property('em.build.Optimize', 'Oz')
    let tools = $property('em.build.ToolsHome', '')
    let libflav = opt == 'Oz' ? 'small' : 'balanced'
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
        |->     -target-feature +strict-align -msoft-float -target-abi aapcs -mfloat-abi soft -fno-signed-char -fnative-half-type -fnative-half-arguments-and-returns \\
        |-> "
        |-> 
        |-> CINCS="\\
        |->     -I . \\
        |->     -I $TOOLS/include \\
        |->     -I ../em.core/em.arch.arm/inc
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
        |->     $TOOLS/lib/libc_v6m_t_le_eabi_${libflav}.a \\
        |->     $TOOLS/lib/strops_v6m_t_le_eabi_${libflav}.a \\
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
    const ext = (process.platform === 'win32') ? '.exe' : 'Exe'
    out = $outfile('load.sh', 0o755)
    const exec = `${tools}/segger-jlink/JLink${ext}`
    out.addText(`${exec} -CommandFile ../silabs.efr32x/silabs.distro.efr32x/jlink-cmds`)
    out.close()


}
