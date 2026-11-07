import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function em$generate() {
    let out = $outfile('ti.distro.cc27xx/startup.cpp')
    out.addFrag(`
        |-> #include <stdbool.h>
        |-> #include <stdint.h>
        |-> 
        |-> #include "../em.arch.arm/intr.cpp"
        |-> #include "../em.arch.arm/startup.cpp"
        |-> #include "../../ti.cc27xx/ti.distro.cc27xx/BootConfig.hpp"
        |-> 
        |-> 
        |-> extern "C" bool __is_warm() {
        |->     return false;
        |-> }
        |-> 
    `)
    out.close()
}
