import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function arm(cpu: string, fpu: boolean, suffix: string) {
    const abi = fpu ? '-mfloat-abi=hard -mfpu=fpv5-sp-d16' : '-mfloat-abi=soft'
    const triple = ['cortex-m0', 'cortex-m0plus'].includes(cpu) ? 'thumbv6m-none-eabi' : 'arm-none-eabi'
    const target = `--target=${triple} -mcpu=${cpu} -mthumb ${abi}`
    return profile(target, '-funsigned-char -mno-unaligned-access', suffix)
}

export function riscv(suffix: string) {
    const target = '--target=riscv32-none-elf -march=rv32emc_zicsr_zba_zbb_zbs_zcb -mabi=ilp32e -mno-save-restore'
    return profile(target, '', suffix)
}

function profile(target: string, extraFlags: string, suffix: string) {
    return {
        folder: 'llvm',
        tools: `CC="$TOOLS/bin/clang${suffix}"
LD="$TOOLS/bin/ld.lld${suffix}"
OBJCOPY="$TOOLS/bin/llvm-objcopy${suffix}"
OBJDUMP="$TOOLS/bin/llvm-objdump${suffix}"`,
        flags: `${target} -std=gnu++14 ${extraFlags}
    -ffreestanding -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
    -D__EM_FREESTANDING_HEADERS__`,
        includes: '',
        runtime: `RUNTIME=$("$CC" ${target} --rtlib=compiler-rt -print-libgcc-file-name)
if [ ! -f "$RUNTIME" ]; then
    echo "Missing LLVM compiler-rt archive: $RUNTIME" >&2
    exit 1
fi`,
        link: '"$LD" -eem__start -N --gc-sections -Map="$OUT/main.map" -T linkcmd.ld -o "$OUT/main.out" "$OUT/main.obj" "$RUNTIME"',
    }
}
