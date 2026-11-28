import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as ArmStartupC from '@em.arch.arm/StartupC.em'
import * as BoardC from '@nordic.distro.nrf54/BoardC.em'
import * as CompilerC from '@em.target.compiler/CompilerC.em'
import * as IsrDefault from '@em.arch.arm/IsrDebug.em'
import * as IntrC from '@nordic.distro.nrf54/IntrC.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LinkerC from '@em.build.segger/LinkerC.em'
import * as REGS from '@nordic.distro.nrf54/REGS.em'
import * as StartupC from '@nordic.distro.nrf54/StartupC.em'
import * as TargC from '@em.lang/TargC.em'

export function em$configure() {
    $using(ArmStartupC)
    $using(BoardC)
    $using(CompilerC)
    $using(IntrC)
    $using(IntrVec)
    $using(LinkerC)
    $using(REGS)
    $using(StartupC)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrDefault
    for (let name of IntrC.NAMES) IntrVec.em$meta.addIntr(name)
}

export function em$generate() {
    const linkerOptions = CompilerC.genScript({ cpu: 'cortex-m33', fpu: $property('em.build.FPU', '') === 'true' })
    LinkerC.genScript({
        dmem_flash: { orig: 0x2003c000, len: 0x00004000 },
        imem_flash: { orig: 0x00000000, len: 0x00008000 },
        dmem_sram: { orig: 0x2003c000, len: 0x00004000 },
        imem_sram: { orig: 0x20008000, len: 0x00008000 },
        lmem_sram: { orig: 0x00000000, len: 0x00008000 },
        cmem_sram: LinkerC.MEM_NULL,
    }, [], linkerOptions)
    const tools = $property('em.build.ToolsHome', '')
    const ext = (process.platform === 'win32') ? '.exe' : 'Exe'
    let out = $outfile('load.sh', 0o755)
    const exec = `${tools}/segger-jlink/JLink${ext}`
    out.addText(`${exec} -CommandFile ../nordic.nrf54/nordic.distro.nrf54/jlink-cmds`)
    out.close()
    out = $outfile('debug.sh', 0o755)
    out.addText(`${exec} -CommandFile ../nordic.nrf54/nordic.distro.nrf54/jlink-debug-cmds`)
    out.close()
}
