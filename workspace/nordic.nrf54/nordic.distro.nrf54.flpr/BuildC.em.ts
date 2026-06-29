import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BoardC from '@nordic.distro.nrf54.flpr/BoardC.em'
import * as IsrDefault from '@em.arch.riscv/IsrDebug.em'
import * as IntrC from '@nordic.distro.nrf54/IntrC.em'
import * as IntrVec from '@nordic.distro.nrf54.flpr/IntrVec.em'
import * as REGS from '@nordic.distro.nrf54.flpr/REGS.em'
import * as TargC from '@em.lang/TargC.em'

export function em$configure() {
    $using(BoardC)
    $using(IntrC)
    $using(IntrVec)
    $using(REGS)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrDefault
    for (let name of IntrC.NAMES) IntrVec.em$meta.addIntr(name)
}

export function em$generate() {
    let opt = $property('em.build.Optimize', 'Oz')
    let tools = $property('em.build.ToolsHome', '')
    let fpu = $property('em.build.FPU', '')
    let fpuabi = fpu ? 'hard' : 'soft'
    let fpudef = fpu ? '1' : '0'
    let out = $outfile('build.sh', 0o755)
    out.addFrag(`
        |-> #!/bin/sh
        |-> 
        |-> set -e
        |-> 
        |-> TOOLS=${tools}/segger-riscv
        |-> CC=$TOOLS/bin/segger-cc
        |-> LD=$TOOLS/gcc/riscv32-none-elf/bin/ld
        |-> OBJCOPY=$TOOLS/gcc/riscv32-none-elf/bin/objcopy
        |-> OBJDUMP=$TOOLS/gcc/riscv32-none-elf/bin/objdump
        |-> SREC=${tools}/srecord/bin/srec_cat
        |-> 
        |-> OUT=.out
        |-> 
        |-> rm -rf $OUT
        |-> mkdir $OUT
        |-> 
        |-> CFLAGS="\\
        |->     -D__EM_ARCH_riscv__ \\
        |->     -D__EM_BOOT__=0 \\
        |->     -D__EM_BOOT_FLASH__=0 \\
        |->     -D__EM_COMPILER_segger__ \\
        |->     -D__EM_CPU_flpr__ \\
        |->     -D__EM_MCU_null__ \\
        |->     -D__EM_LANG__=1 \\
        |->     -D__GNUC__ \\
        |->     --std=c++14 \\
        |->     -triple riscv32-none-elf \\
        |->     -target-cpu generic-rv32 \\
        |->     -target-feature +e \\
        |->     -target-feature +m \\
        |->     -target-feature +c \\
        |->     -target-feature +zicsr \\
        |->     -target-feature +zba \\
        |->     -target-feature +zbb \\
        |->     -target-feature +zbs \\
        |->     -target-feature +zcb \\
        |->     -target-abi ilp32e \\
        |->     -ffreestanding \\
        |->     -ffunction-sections \\
        |->     -fdata-sections \\
        |->     -fno-threadsafe-statics \\
        |->     -Wno-deprecated-register \\
        |->     -Wno-invalid-noreturn \\
        |->     -Wno-macro-redefined \\
        |->     -Wno-switch \\
        |->     -Wno-uninitialized \\
        |->     -Wno-return-type \\
        |-> "
        |-> 
        |-> CINCS="\\
        |->     -I . \\
        |->     -I $TOOLS/include \\
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
        |->     $TOOLS/lib/libc_rv32emc_small.a \\
        |-> "
        |-> 
        |-> $CC -c $CFLAGS $CINCS $COPTS -x c++ main.cpp -o $OUT/main.obj
        |-> $LD $LFLAGS -Map=$OUT/main.map -T linkcmd.ld -o $OUT/main.out $OUT/main.obj $LIBS
        |-> $OBJCOPY -O ihex $OUT/main.out $OUT/main.out.hex
        |-> $OBJDUMP -h -D --demangle $OUT/main.out >$OUT/main.out.dis
        |-> $OBJDUMP -t --demangle $OUT/main.out | tail -n +5 | sed -e 's/[FO] /  /' | sed -e 's/df /   /' >$OUT/main.out.sym
        |-> sort -k1 $OUT/main.out.sym > $OUT/main.out.syma
        |-> sort -k5 $OUT/main.out.sym > $OUT/main.out.symn
        |-> $OBJDUMP -h $OUT/main.out
        |-> $SREC $OUT/main.out.hex -Intel -offset - -minimum-addr $OUT/main.out.hex -Intel -o $OUT/main.out.bin -Binary
        |-> $SREC ../nordic.nrf54/nordic.distro.nrf54/vpr-launcher.hex -Intel $OUT/main.out.bin  -Binary -offset 0x00008000 -o $OUT/merged.hex -Intel
`)
    out.close()
    //
    out = $outfile('nordic.distro.nrf54.flpr/startup.cpp')
    out.addFile('../nordic.nrf54/nordic.distro.nrf54.flpr/startup.cpp')
    out.close()
    //
    out = $outfile('linkcmd.ld')
    out.addFile('../nordic.nrf54/nordic.distro.nrf54.flpr/linkcmd.ld')
    out.close()
    //
    const ext = (process.platform === 'win32') ? '.exe' : 'Exe'
    out = $outfile('load.sh', 0o755)
    const exec = `${tools}/segger-jlink/JLink${ext}`
    out.addText(`${exec} -CommandFile ../nordic.nrf54/nordic.distro.nrf54.flpr/jlink-cmds`)
    out.close()
}
