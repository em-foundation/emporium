import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function arm(cpu: string, fpu: boolean, optimize: string, suffix: string) {
    const abi = fpu ? 'hard' : 'soft'
    const softFloat = fpu ? '' : '-target-feature +soft-float -target-feature +soft-float-abi -msoft-float'
    const arch = fpu ? 'v8mml_fpv5_sp_d16_hard' : 'v6m'
    const flavor = optimize === 'Oz' && !fpu ? 'small' : 'balanced'
    const lib = `${arch}_t_le_eabi_${flavor}.a`
    return {
        folder: 'segger-arm',
        tools: `CC="$TOOLS/bin/segger-cc${suffix}"
LD="$TOOLS/gcc/arm-none-eabi/bin/ld${suffix}"
OBJCOPY="$TOOLS/gcc/arm-none-eabi/bin/objcopy${suffix}"
OBJDUMP="$TOOLS/gcc/arm-none-eabi/bin/objdump${suffix}"`,
        flags: `-D__GNUC__ --std=c++14 -triple thumbv6m-none-eabi -target-cpu ${cpu}
    -Wno-deprecated-register -Wno-invalid-noreturn -Wno-macro-redefined
    -Wno-switch -Wno-uninitialized -Wno-c99-designator -Wno-c++20-designator -Wpointer-to-int-cast
    -target-feature +strict-align ${softFloat} -mfloat-abi ${abi} -target-abi aapcs -fno-signed-char
    -fnative-half-type -fnative-half-arguments-and-returns`,
        includes: '-I "$TOOLS/include"',
        runtime: '',
        link: `"$LD" -eem__start -N --gc-sections -Map="$OUT/main.map" -T linkcmd.ld \\
    -o "$OUT/main.out" "$OUT/main.obj" "$TOOLS/lib/libc_${lib}" "$TOOLS/lib/strops_${lib}"`,
    }
}

export function riscv(suffix: string) {
    return {
        folder: 'segger-riscv',
        tools: `TOOLS="\${SEGGER_RISCV_HOME:-$TOOLS}"
CC="$TOOLS/bin/segger-cc${suffix}"
LD="$TOOLS/gcc/riscv32-none-elf/bin/ld${suffix}"
OBJCOPY="$TOOLS/gcc/riscv32-none-elf/bin/objcopy${suffix}"
OBJDUMP="$TOOLS/gcc/riscv32-none-elf/bin/objdump${suffix}"`,
        flags: `-D__GNUC__ --std=c++14 -triple riscv32-none-elf -target-cpu generic-rv32
    -target-feature +e -target-feature +m -target-feature +c -target-feature +zicsr
    -target-feature +zba -target-feature +zbb -target-feature +zbs -target-feature +zcb -target-abi ilp32e
    -ffreestanding -Wno-deprecated-register -Wno-invalid-noreturn -Wno-macro-redefined
    -Wno-switch -Wno-uninitialized -Wno-return-type`,
        includes: '-I "$TOOLS/include"',
        runtime: '',
        link: '"$LD" -eem__start -N --gc-sections -Map="$OUT/main.map" -T linkcmd.ld -o "$OUT/main.out" "$OUT/main.obj" "$TOOLS/lib/libc_rv32emc_small.a"',
    }
}
