import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function arm(cpu: string, fpu: boolean, suffix: string) {
    const abi = fpu ? '-mfloat-abi=hard -mfpu=fpv5-sp-d16' : '-mfloat-abi=soft'
    const target = `-mcpu=${cpu} -mthumb ${abi}`
    return profile('gcc-arm', 'arm-none-eabi', 'arm-zephyr-eabi', target, '-funsigned-char -mno-unaligned-access', suffix)
}

export function riscv(suffix: string) {
    const target = '-march=rv32emc_zicsr_zba_zbb_zbs_zcb -mabi=ilp32e -mno-save-restore'
    return profile('gcc-riscv', 'riscv-none-elf', 'riscv64-zephyr-elf', target, '-D__EM_FREESTANDING_HEADERS__', suffix)
}

function profile(folder: string, bareMetalPrefix: string, zephyrPrefix: string, target: string, extraFlags: string, suffix: string) {
    return {
        folder,
        tools: `PREFIX="$TOOLS/bin/${bareMetalPrefix}"
if [ ! -x "$PREFIX-g++${suffix}" ]; then
    PREFIX="$TOOLS/bin/${zephyrPrefix}"
fi
CC="$PREFIX-g++${suffix}"
LD="$CC"
OBJCOPY="$PREFIX-objcopy${suffix}"
OBJDUMP="$PREFIX-objdump${suffix}"`,
        flags: `${target} -std=gnu++14 ${extraFlags}
    -ffreestanding -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
    -D__EM_RUN_INIT_ARRAY__`,
        includes: '',
        runtime: '',
        link: `"$LD" ${target} -nostdlib -static -Wl,-e,em__start,-N,--gc-sections,-Map,"$OUT/main.map" \\
    -T linkcmd.ld -o "$OUT/main.out" "$OUT/main.obj" -lgcc`,
    }
}
