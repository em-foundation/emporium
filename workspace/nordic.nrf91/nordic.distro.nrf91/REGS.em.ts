import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function em$generate() {
    let out = $outfile('nordic.distro.nrf91/REGS.hpp')
    out.addFile('../nordic.nrf91/nordic.distro.nrf91/REGS.hpp.txt')
    out.close()
}
