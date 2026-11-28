import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BoardC from '@nordic.distro.nrf54.riscv/BoardC.em'
import * as CompilerC from '@em.target.compiler/CompilerC.em'
import * as IsrDefault from '@em.arch.riscv/IsrDebug.em'
import * as IntrC from '@nordic.distro.nrf54/IntrC.em'
import * as IntrVec from '@nordic.distro.nrf54.riscv/IntrVec.em'
import * as REGS from '@nordic.distro.nrf54/REGS.em'
import * as TargC from '@em.lang/TargC.em'

export function em$configure() {
    $using(BoardC)
    $using(CompilerC)
    $using(IntrC)
    $using(IntrVec)
    $using(REGS)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrDefault
    for (let name of IntrC.NAMES) IntrVec.em$meta.addIntr(name)
}

export function em$generate() {
    const tools = $property('em.build.ToolsHome', '')
    const suffix = process.platform === 'win32' ? '.exe' : ''
    CompilerC.genScript({ arch: 'riscv', cpu: 'flpr' }, `
SREC="$TOOLS_HOME/srecord/bin/srec_cat${suffix}"
"$SREC" "$OUT/main.out.hex" -Intel -offset - -minimum-addr "$OUT/main.out.hex" -Intel -o "$OUT/main.out.bin" -Binary
"$SREC" ../nordic.nrf54/nordic.distro.nrf54/vpr-launcher.hex -Intel "$OUT/main.out.bin" -Binary -offset 0x00008000 -o "$OUT/merged.hex" -Intel`)

    let out = $outfile('nordic.distro.nrf54.riscv/startup.cpp')
    out.addFile('../nordic.nrf54.riscv/nordic.distro.nrf54.riscv/startup.cpp')
    out.close()
    //
    out = $outfile('nordic.distro.nrf54.riscv/REGS.hpp')
    out.addFile('../nordic.nrf54/nordic.distro.nrf54/REGS.hpp.txt')
    out.close()
    //
    out = $outfile('linkcmd.ld')
    out.addFile('../nordic.nrf54.riscv/nordic.distro.nrf54.riscv/linkcmd.ld')
    out.close()
    //
    const ext = (process.platform === 'win32') ? '.exe' : 'Exe'
    out = $outfile('load.sh', 0o755)
    const exec = `${tools}/segger-jlink/JLink${ext}`
    out.addText(`${exec} -CommandFile ../nordic.nrf54.riscv/nordic.distro.nrf54.riscv/jlink-cmds`)
    out.close()
}
