import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function em$generate() {
    let out = $outfile('nordic.distro.nrf52/startup.cpp')
    out.addFrag(`
        |-> #include <stdbool.h>
        |-> #include <stdint.h>
        |-> 
        |-> #include "../em.arch.arm/intr.cpp"
        |-> static inline __attribute__((always_inline)) void prepare_code_ram() {
        |->     // Flash firmware can leave the code banks off across a soft reset.
        |->     for (unsigned bank = 4; bank < 8; ++bank) {
        |->         NRF_POWER->RAM[bank].POWERSET = POWER_RAM_POWERSET_S0POWER_Msk | POWER_RAM_POWERSET_S1POWER_Msk;
        |->     }
        |->     __DSB();
        |-> }
        |-> #define EM_ARM_PREPARE_CODE_RAM() prepare_code_ram()
        |-> #include "../em.arch.arm/startup.cpp"
        |-> 
        |-> extern void em_main();
        |-> 
        |-> extern "C" bool __is_warm() {
        |->     return false;
        |-> }
        |-> 
    `)
    out.close()
}
