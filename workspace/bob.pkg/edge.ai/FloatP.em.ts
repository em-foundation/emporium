import '@$$emscript'
export const $U = $declare('MODULE')

import * as Console from '@em.lang/Console.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    printf`x = `()
    Console.prF32(-3.14)
    printf`\n`()
    // const x: f32 = 3.14
    // e$`union { em::arg_t a; float f; } val`
    // e$`val.f = -3.14`
    // const arg = e$`val.a`
    // printf`num %08x\n`(x)
}