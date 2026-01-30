import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as MemDump from '@em.utils/MemDump.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    MemDump.print(t$`PWRM`, e$`PML_BASE`, e$`sizeof(PML_RegMap_t)`)
}