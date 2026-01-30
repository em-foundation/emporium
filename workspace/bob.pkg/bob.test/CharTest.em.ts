import em from '@$$emscript'
export const $U = em.$declare('MODULE')

const c = c$`a`

export namespace em$meta {
    console.log(c)
}

export function em$run() {
    em.$reg32[0xAA] = c
}
