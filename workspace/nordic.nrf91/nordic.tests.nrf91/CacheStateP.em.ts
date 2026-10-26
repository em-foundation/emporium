import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf91/REGS.em'

// Read-only diagnostic after TF-M and normal MCU startup.
// Use the SRAM setup to inspect the state inherited from secure boot.
export function em$run() {
    printf`Reading NVMC.ICACHECNF\n`()
    const cache_cnf = $R.NVMC.ICACHECNF.$$
    const enabled: u32 = (cache_cnf & $R.NVMC_ICACHECNF_CACHEEN_Msk) != 0 ? 1 : 0
    printf`CACHEEN=%d (ICACHECNF=0x%x)\n`(enabled, cache_cnf)
}
