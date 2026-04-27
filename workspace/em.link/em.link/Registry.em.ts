import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as T from '@em.link/Types.em'

export const DEFAULT_PARAMS = $config<T.Params>()

const node_id = $config<T.NodeId>()
const sch_hash = $config<T.SchemaHash>()

export namespace em$meta {
    export function bindNodeId(nid: T.NodeId) {
        node_id.$$val = nid
    }
    export function bindSchemaHash(sh: T.SchemaHash) {
        sch_hash.$$val = sh
    }
}

//>> ---- em$targ ---- <<//

var cur_prof: T.Profile = $null
var params = T.Params.$make()

export function getNodeId(): $$<const_t<T.NodeId>> {
    return $ref(node_id)
}

export function getParams(): $$<const_t<T.Params>> {
    return $ref(cur_prof != $null ? params : DEFAULT_PARAMS)
}

export function getSchemaHash(): T.SchemaHash {
    return sch_hash
}
export function setupParams(prof: T.Profile) {
    if (cur_prof == prof) return
    cur_prof = prof
    if (prof == $null) return
    Mem.cpy($ref(params), $ref(DEFAULT_PARAMS), $sizeof<T.Params>())
    prof($ref(params))
}

