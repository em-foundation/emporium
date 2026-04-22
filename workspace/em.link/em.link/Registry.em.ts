import '@$$emscript'
export const $U = $declare('MODULE')

import * as T from '@em.link/Types.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var params = T.Params.$make()

export function getParams(): $$<T.Params> {
    return $ref(params)
}