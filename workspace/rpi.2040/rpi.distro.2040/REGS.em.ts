import em from '@$$emscript'
export const $U = em.$declare('COMPOSITE')

export function em$generate() {
    let out = $outfile('rpi.distro.2040/REGS.hpp')
    out.addFile('../rpi.2040/rpi.distro.2040/REGS.hpp.txt')
    out.close()
}
