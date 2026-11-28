import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as ArmStartupC from '@em.arch.arm/StartupC.em'
import * as BoardC from '@ti.distro.cc27xx/BoardC.em'
import * as CompilerC from '@em.target.compiler/CompilerC.em'
import * as IsrEmpty from '@em.arch.arm/IsrEmpty.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LinkerC from '@em.build.segger/LinkerC.em'
import * as REGS from '@ti.distro.cc27xx/REGS.em'
import * as StartupC from '@ti.distro.cc27xx/StartupC.em'
import * as TargC from '@em.lang/TargC.em'

const NVIC_INTRS = [
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
    'ADC_COMB',
    'CPUIRQ16',
    'CPUIRQ17',
    'LGPT2_COMB',
    'LGPT3_COMB',
    'I2S_IRQ',
    'CAN_IRQ',
    'UART1_COMB',
    'SPI1_COMB',
    'APU_IRQ',
    'HSM_SEC_IRQ',
    'HSM_NONSEC_IRQ',
    'HSM_OTP_IRQ',
    'AON_PMU_COMB',
    'AON_CKM_COMB',
    'AON_RTC_COMB',
    'AON_LPCMP_IRQ',
    'AON_IOC_COMB',
    'SW0',
    'SW1',
]

export function em$configure() {
    $using(ArmStartupC)
    if (!$isbare()) $using(BoardC)
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
    const linkerOptions = CompilerC.genScript({ cpu: 'cortex-m33', fpu: false })
    LinkerC.genScript(
        {
            dmem_flash: { orig: 0x20000000, len: 0x00028800 },
            imem_flash: { orig: 0x00000000, len: 0x00100000 },
            dmem_sram: { orig: 0x20010000, len: 0x00018800 },
            imem_sram: { orig: 0x20000000, len: 0x00010000 },
            lmem_sram: { orig: 0x00000000, len: 0x00100000 },
            cmem_sram: LinkerC.MEM_NULL,
        },
        [
            { name: 'FLASH_CCFG', sect: '.ccfg', desc: { orig: 0x4e020000, len: 0x800 } },
            { name: 'FLASH_SCFG', sect: '.scfg', desc: { orig: 0x4e040000, len: 0x400 } },
        ],
        linkerOptions
    )
    const tools = $property('em.build.ToolsHome', '')
    const out = $outfile('load.sh', 0o755)
    const uniflash = $property('em.build.UniFlashHome', tools + '/ti-uniflash')
    out.addFrag(`
        |-> #!/bin/sh
        |-> set -e
        |-> 
        |-> case "$0" in */*) cd "\${0%/*}" ;; esac
        |-> UNIFLASH="${uniflash}"
        |-> CONFIG="../ti.cc27xx/ti.distro.cc27xx/CC2755P10.ccxml"
        |-> IMAGE=".out/main.out.hex"
        |-> DSLITE="$UNIFLASH/ccs_base/DebugServer/bin/DSLite"
        |-> 
        |-> if [ -f "$DSLITE.exe" ]; then
        |->     DSLITE="$DSLITE.exe"
        |-> fi
        |-> if [ ! -f "$UNIFLASH/ccs_base/common/targetdb/devices/cc2755p10.xml" ]; then
        |->     echo "CC2755P10 support missing from $UNIFLASH. Set em.build.UniFlashHome to a compatible UniFlash installation." >&2
        |->     exit 1
        |-> fi
        |-> if [ ! -f "$DSLITE" ] || [ ! -f "$CONFIG" ] || [ ! -f "$IMAGE" ]; then
        |->     echo "Missing DSLite executable, target configuration, or built HEX image." >&2
        |->     exit 1
        |-> fi
        |-> 
        |-> "$DSLITE" flash -c "$CONFIG" -s "VerifyAfterProgramLoad=No verification" -f -t 60 "$IMAGE"
    `)
    out.close()
}