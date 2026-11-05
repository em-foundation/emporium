import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as ArmStartupC from '@em.arch.arm/StartupC.em'
import * as IsrEmpty from '@em.arch.arm/IsrEmpty.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LinkerC from '@em.build.segger/LinkerC.em'
import * as StartupC from '@ti.distro.cc27xx/StartupC.em'
import * as TargC from '@em.lang/TargC.em'

export function em$configure() {
    $using(ArmStartupC)
    $using(IntrVec)
    $using(LinkerC)
    $using(StartupC)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrEmpty
}

export function em$generate() {
    LinkerC.genScript(
        {
            dmem_flash: { orig: 0x20000000, len: 0x00028800 },
            imem_flash: { orig: 0x00000000, len: 0x00100000 },
            dmem_sram: LinkerC.MEM_NULL,
            imem_sram: LinkerC.MEM_NULL,
            lmem_sram: LinkerC.MEM_NULL,
            cmem_sram: LinkerC.MEM_NULL,
        },
        [
            { name: 'FLASH_CCFG', sect: '.ccfg', desc: { orig: 0x4e020000, len: 0x800 } },
            { name: 'FLASH_SCFG', sect: '.scfg', desc: { orig: 0x4e040000, len: 0x400 } },
        ],
    )
    let regs = $outfile('ti.distro.cc27xx/REGS.hpp')
    regs.addText('#pragma once\n#include "../../ti.cc27xx/ti.distro.cc27xx/inc/cc27xx.h"\n#include "core_cm33.h"\n#include "../../ti.cc27xx/ti.distro.cc27xx/inc/hw_clkctl.h"\n#include "../../ti.cc27xx/ti.distro.cc27xx/inc/hw_gpio.h"\n#include "../../ti.cc27xx/ti.distro.cc27xx/inc/hw_ioc.h"\n#include "../../ti.cc27xx/ti.distro.cc27xx/inc/hw_memmap.h"\n#include "../../ti.cc27xx/ti.distro.cc27xx/inc/hw_pmctl.h"\n#include "../../ti.cc27xx/ti.distro.cc27xx/inc/hw_types.h"\n')
    regs.close()

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
        |-> CFLAGS="\\
        |->     -D__EM_ARCH_arm__ \\
        |->     -D__EM_BOOT__=0 \\
        |->     -D__EM_BOOT_FLASH__=0 \\
        |->     -D__EM_COMPILER_segger__ \\
        |->     -D__EM_CPU_cortex_m33__ \\
        |->     -D__EM_MCU_null__ \\
        |->     -D__EM_LANG__=1 \\
        |->     --std=c++14 \\
        |->     -triple thumbv8m.main-none-eabi \\
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
        |->     -target-feature +strict-align -target-feature +soft-float -target-feature +soft-float-abi -msoft-float -target-abi aapcs -mfloat-abi soft -fno-signed-char -fnative-half-type -fnative-half-arguments-and-returns \\
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
    //
    out = $outfile('load.sh', 0o755)
    const uniflash = $property('em.build.UniFlashHome', tools + '/ti-uniflash')
    out.addFrag(`
        |-> #!/bin/sh
        |-> set -e
        |-> 
        |-> case "$0" in */*) cd "\${0%/*}" ;; esac
        |-> UNIFLASH="${uniflash}"
        |-> CONFIG="../ti.cc27xx/ti.distro.cc27xx/CC2755P10.ccxml"
        |-> IMAGE=".out/main.out.hex"
        |-> DSLITE="$UNIFLASH/ccs_base/DebugServer/bin/DSLite"
        |-> 
        |-> if [ -f "$DSLITE.exe" ]; then
        |->     DSLITE="$DSLITE.exe"
        |-> fi
        |-> if [ ! -f "$UNIFLASH/ccs_base/common/targetdb/devices/cc2755p10.xml" ]; then
        |->     echo "CC2755P10 support missing from $UNIFLASH. Set em.build.UniFlashHome to a compatible UniFlash installation." >&2
        |->     exit 1
        |-> fi
        |-> if [ ! -f "$DSLITE" ] || [ ! -f "$CONFIG" ] || [ ! -f "$IMAGE" ]; then
        |->     echo "Missing DSLite executable, target configuration, or built HEX image." >&2
        |->     exit 1
        |-> fi
        |-> 
        |-> "$DSLITE" flash -c "$CONFIG" -s "VerifyAfterProgramLoad=No verification" -f -t 60 "$IMAGE"
        |-> "$DSLITE" flash -c "$CONFIG" -s "ImageVerificationSetting=1" -t 60 "$IMAGE"
    `)
    out.close()
}