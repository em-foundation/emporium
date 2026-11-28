import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function arm(cpu: string, fpu: boolean, suffix: string) {
    const abi = fpu ? '-mfloat-abi=hard -mfpu=fpv5-sp-d16' : '-mfloat-abi=soft'
    const target = `--target=arm-none-eabi -mcpu=${cpu} -mthumb ${abi}`
    return {
        folder: 'llvm',
        tools: `CC="$TOOLS/bin/clang${suffix}"
LD="$TOOLS/bin/ld.lld${suffix}"
OBJCOPY="$TOOLS/bin/llvm-objcopy${suffix}"
OBJDUMP="$TOOLS/bin/llvm-objdump${suffix}"`,
        flags: `${target} -std=gnu++14 -funsigned-char -mno-unaligned-access
    -ffreestanding -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables`,
        includes: '',
        runtime: `RUNTIME=$("$CC" ${target} --rtlib=compiler-rt -print-libgcc-file-name)
if [ ! -f "$RUNTIME" ]; then
    echo "Missing LLVM compiler-rt archive: $RUNTIME" >&2
    exit 1
fi`,
        link: '"$LD" -eem__start -N --gc-sections -Map="$OUT/main.map" -T linkcmd.ld -o "$OUT/main.out" "$OUT/main.obj" "$RUNTIME"',
    }
}
