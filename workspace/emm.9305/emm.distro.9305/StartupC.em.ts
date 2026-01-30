import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function em$generate() {
    let bf = $property('em.build.BootFlash', false) ? '1' : '0'
    let cpp_out = $outfile('emm.distro.9305/startup.cpp')
    cpp_out.addFrag(`
        |-> #define __EM_BOOT_FLASH__ ${bf}
        |-> //
    `)
    cpp_out.addFile('../emm.9305/emm.distro.9305/startup.cpp')
    cpp_out.close()
}
