import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function em$generate() {
    let out = $outfile('segger.arm.distro.sandbox/REGS.hpp')
    out.addFile('../segger.arm.sandbox/segger.arm.distro.sandbox/REGS.hpp.txt')
    out.close()
}
