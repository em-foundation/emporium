import em from '@$$emscript'
export const $U = em.$declare('MODULE')

export const MAX: u32 = 100

export const scalar = $config<u8>()

export namespace em$meta {
    export function em$construct() {
        console.log(scalar.$$ + 5)
    }
}
