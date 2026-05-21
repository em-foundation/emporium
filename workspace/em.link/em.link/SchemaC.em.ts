import '@$$emscript'
export const $U = $declare('COMPOSITE')

type Resource = {
    name: string
    typeName: string
    typeDesc: string
    uuid?: string
    canRead: boolean
    canWrite: boolean
    canNotify: boolean
}

type Info = {
    uid: string
    name: string
    uuid: string
    resources: Resource[]
}

export function makeInfo(uid: string): Info {
    const unit = $$units.get(uid)
    const prefix = uid + ':'
    const resources: Resource[] = []
    for (const [key, tdesc] of $$tdefs) {
        if (!key.startsWith(prefix) || !key.endsWith('_T')) {
            continue
        }
        const typeName = key.slice(prefix.length)
        const name = typeName.slice(0, -2)
        resources.push({
            name,
            typeName,
            typeDesc: tdesc,
            uuid: unit[`${name}_uuid`],
            canRead: !!unit[`${name}_read`],
            canWrite: !!unit[`${name}_write`],
            canNotify: !!unit[`${name}_notify`],
        })
    }
    return {
        uid,
        name: unit.$S_name,
        uuid: unit.$S_uuid,
        resources,
    }
}

