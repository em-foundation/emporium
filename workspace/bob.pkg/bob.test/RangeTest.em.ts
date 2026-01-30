import em from '@$$emscript'
export const $U = em.$declare('MODULE')

export namespace em$meta {
    export function em$construct() {
        for (let i of $range(2, 5)) console.log(i)
    }
}

export function em$run() {
    for (let i of $range(2, 5)) printf`i = %d\n`(i)
}
