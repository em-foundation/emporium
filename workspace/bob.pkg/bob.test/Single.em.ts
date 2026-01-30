import em from '@$$emscript'
export const $U = em.$declare('MODULE')

namespace em$meta {
    export function em$init() {
        console.log('initM', foo(10))
    }
    function foo(x: Readonly<u8>): u8 {
        x += 10
        return x
    }
}

export default { $U, ...em$meta }
