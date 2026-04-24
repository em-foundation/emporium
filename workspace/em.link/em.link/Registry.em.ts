import '@$$emscript'
export const $U = $declare('MODULE')

import * as T from '@em.link/Types.em'

const sch_hash = $config<T.SchemaHash>()

export namespace em$meta {
    export function bindSchemaHash(sh: T.SchemaHash) {
        sch_hash.$$val = sh
    }
}

//>> ---- em$targ ---- <<//

var params = T.Params.$make()

export function getParams(): $$<T.Params> {
    return $ref(params)
}

export function getSchemaHash(): T.SchemaHash {
    return sch_hash
}

