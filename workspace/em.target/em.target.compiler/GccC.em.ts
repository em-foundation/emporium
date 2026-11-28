import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function arm(cpu: string, fpu: boolean, suffix: string) {
    const abi = fpu ? '-mfloat-abi=hard -mfpu=fpv5-sp-d16' : '-mfloat-abi=soft'
    const target = `-mcpu=${cpu} -mthumb ${abi}`
    return {
        folder: 'gcc-arm',
        tools: `PREFIX="$TOOLS/bin/arm-none-eabi"
if [ ! -x "$PREFIX-g++${suffix}" ]; then
    PREFIX="$TOOLS/bin/arm-zephyr-eabi"
fi
CC="$PREFIX-g++${suffix}"
LD="$CC"
OBJCOPY="$PREFIX-objcopy${suffix}"
OBJDUMP="$PREFIX-objdump${suffix}"`,
        flags: `${target} -std=gnu++14 -funsigned-char -mno-unaligned-access
    -ffreestanding -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
    -D__EM_RUN_INIT_ARRAY__`,
        includes: '',
        runtime: '',
        link: `"$LD" ${target} -nostdlib -static -Wl,-e,em__start,-N,--gc-sections,-Map,"$OUT/main.map" \\
    -T linkcmd.ld -o "$OUT/main.out" "$OUT/main.obj" -lgcc`,
    }
}
