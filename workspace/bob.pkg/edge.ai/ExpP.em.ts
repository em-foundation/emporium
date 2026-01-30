import '@$$emscript'
export const $U = $declare('MODULE')

import * as Console from '@em.lang/Console.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var x: volatile_t<f32> = 3.14
var y: volatile_t<f32> = 0.00005
var z: volatile_t<f32> = 0.0

export function em$run() {
    e$`asm("nop")`
    // z = x * y
    y = e$`expf(x)`
    // Console.prF32(y)
    // printf`\n`()
}