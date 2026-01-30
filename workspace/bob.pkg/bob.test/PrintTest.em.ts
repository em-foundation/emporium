import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Console from '@em.lang/Console.em'

export namespace em$meta {
    // printf`x = %d\n`(10)
}

export function em$run() {
    printf`hello world\n`()
    let cnt = 88
    printf`\n%c, count = %d\n`(c$`"`, cnt)
}
