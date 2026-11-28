import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as GccC from '@em.target.compiler/GccC.em'
import * as LlvmC from '@em.target.compiler/LlvmC.em'
import * as SeggerC from '@em.target.compiler/SeggerC.em'

export function em$configure() {
    $using(GccC)
    $using(LlvmC)
    $using(SeggerC)
}

function shellQuote(value: string) {
    return "'" + value.replaceAll("'", "'\\''") + "'"
}

type Target = { arch?: 'arm', cpu: string, fpu: boolean } | { arch: 'riscv', cpu: string }

export function genScript(target: Target, postBuild = '') {
    const compiler = $property('em.build.Compiler', 'segger')
    const tools = $property('em.build.ToolsHome', '')
    const optimize = $property('em.build.Optimize', 'Oz')
    const windows = process.platform === 'win32'
    const suffix = windows ? '.exe' : ''
    const opt = shellQuote('-' + optimize)
    const arch = target.arch ?? 'arm'
    const riscv = target.arch === 'riscv'
    let profile
    switch (compiler) {
        case 'segger':
            profile = riscv ? SeggerC.riscv(suffix) : SeggerC.arm(target.cpu, target.fpu, optimize, suffix)
            break
        case 'llvm':
            profile = riscv ? LlvmC.riscv(suffix) : LlvmC.arm(target.cpu, target.fpu, suffix)
            break
        case 'gcc':
            profile = riscv ? GccC.riscv(suffix) : GccC.arm(target.cpu, target.fpu, suffix)
            break
        default:
            throw new Error(`Unknown em.build.Compiler "${compiler}". Use segger, llvm, or gcc.`)
    }
    const fpu = !riscv && target.fpu ? 1 : 0
    const out = $outfile('build.sh', 0o755)
    out.addText(`#!/bin/sh
set -e

TOOLS_HOME=${shellQuote(windows ? tools.replaceAll('\\', '/') : tools)}
TOOLS="$TOOLS_HOME/${profile.folder}"
${profile.tools}
for tool in "$CC" "$LD" "$OBJCOPY" "$OBJDUMP"; do
    if [ ! -x "$tool" ]; then
        echo "Cannot run ${compiler} tool: $tool" >&2
        exit 1
    fi
done
${profile.runtime}
OUT=.out
rm -rf "$OUT"
mkdir "$OUT"

CFLAGS="-D__EM_ARCH_${arch}__ -D__EM_BOOT__=0 -D__EM_BOOT_FLASH__=0 -D__EM_MCU_null__ -D__EM_LANG__=1
    -D__EM_CPU_${target.cpu.replaceAll('-', '_')}__ -D__EM_COMPILER_${compiler}__
    ${riscv ? '' : `-D__FPU_PRESENT=${fpu} -D__FPU_USED=${fpu}`}
    -ffunction-sections -fdata-sections -fno-threadsafe-statics
    ${profile.flags}"
"$CC" -c $CFLAGS -I . ${profile.includes} ${opt} -x c++ main.cpp -o "$OUT/main.obj"
${profile.link}
"$OBJCOPY" -O ihex "$OUT/main.out" "$OUT/main.out.hex"
"$OBJDUMP" -h ${riscv ? '-D' : '-d'} --demangle "$OUT/main.out" > "$OUT/main.out.dis"
"$OBJDUMP" -t --demangle "$OUT/main.out" | tail -n +5 | sed -e 's/[FO] /  /' | sed -e 's/df /   /' > "$OUT/main.out.sym"
sort -k1 "$OUT/main.out.sym" > "$OUT/main.out.syma"
sort -k5 "$OUT/main.out.sym" > "$OUT/main.out.symn"
"$OBJDUMP" -h "$OUT/main.out"
${postBuild}
`)
    out.close()
    return { initArray: compiler === 'gcc' }
}
