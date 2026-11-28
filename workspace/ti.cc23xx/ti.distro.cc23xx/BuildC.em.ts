import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as ArmStartupC from '@em.arch.arm/StartupC.em'
import * as BoardC from '@ti.distro.cc23xx/BoardC.em'
import * as CompilerC from '@em.target.compiler/CompilerC.em'
import * as IsrDebug from '@em.arch.arm/IsrDebug.em'
import * as IsrEmpty from '@em.arch.arm/IsrEmpty.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LinkerC from '@em.build.segger/LinkerC.em'
import * as REGS from '@ti.distro.cc23xx/REGS.em'
import * as StartupC from '@ti.distro.cc23xx/StartupC.em'
import * as TargC from '@em.lang/TargC.em'

const NVIC_INTRS = <Array<string>>[
    'CPUIRQ0',
    'CPUIRQ1',
    'CPUIRQ2',
    'CPUIRQ3',
    'CPUIRQ4',
    'GPIO_COMB',
    'LRFD_IRQ0',
    'LRFD_IRQ1',
    'DMA_DONE_COMB',
    'AES_COMB',
    'SPI0_COMB',
    'UART0_COMB',
    'I2C0_IRQ',
    'LGPT0_COMB',
    'LGPT1_COMB',
    'ADC0_COMB',
    'CPUIRQ16',
    'LGPT2_COMB',
    'LGPT3_COMB',
]

export function em$configure() {
    $using(ArmStartupC)
    $using(BoardC)
    $using(CompilerC)
    $using(IntrVec)
    $using(LinkerC)
    $using(REGS)
    $using(StartupC)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrEmpty
    for (const name of NVIC_INTRS) IntrVec.em$meta.addIntr(name)
}

export function em$generate() {
    const linkerOptions = CompilerC.genScript({ cpu: 'cortex-m0plus', fpu: false })
    LinkerC.genScript(
        {
            dmem_flash: { orig: 0x20000000, len: 0x00009000 },
            imem_flash: { orig: 0x00000000, len: 0x0007c000 },
            dmem_sram: { orig: 0x20008000, len: 0x00001000 },
            imem_sram: { orig: 0x20000000, len: 0x00008000 },
            lmem_sram: { orig: 0x00000000, len: 0x0007c000 },
            cmem_sram: LinkerC.MEM_NULL,
        },
        [
            // Reserve the top 16 KiB of main Flash for radio firmware, outside the SRAM copy.
            { name: 'FLASH_RADIO', sect: '.radio_firmware', desc: { orig: 0x0007c000, len: 0x4000 } },
            { name: 'FLASH_CCFG', sect: '.ccfg', desc: { orig: 0x4e020000, len: 0x800 } }
        ],
        linkerOptions
    )
    const tools = $property('em.build.ToolsHome', '')
    const dslite =
        process.platform === 'win32'
            ? 'dslite.bat'
            : process.platform === 'linux'
                ? 'dslite-Cortex_M0P.sh'
                : 'dslite.sh'
    const out = $outfile('load.sh', 0o755)
    out.addText(
        `${tools}/ti-uniflash/${dslite} -c ../ti.cc23xx/ti.distro.cc23xx/CC2340R5.ccxml .out/main.out\n`
    )
    out.close()
}
