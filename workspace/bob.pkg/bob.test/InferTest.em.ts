import em from '@$$emscript'
export const $U = em.$declare('MODULE')

export namespace em$meta {

    type Unbox<T> = T extends { $$: infer U }
        ? U // Boxed scalar
        : T extends Record<string, any>
        ? InstantiateType<T> // Nested proto object
        : never

    type InstantiateType<P> = {
        [K in keyof P]: Unbox<P[K]>
    }

    function instantiate<P extends Record<string, any>>(prototype: P): InstantiateType<P> {
        const result: any = {}
        for (const key in prototype) {
            const field = prototype[key]
            if (field && typeof field === "object" && "$$" in field) {
                // Boxed scalar: unbox it
                result[key] = field.$$
            } else if (field && typeof field === "object") {
                // Nested proto object: recurse
                result[key] = instantiate(field)
            } else {
                throw new Error(`Unsupported field type for key "${key}"`)
            }
        }
        return result
    }

    const PairP = {
        x: $u8(),
        y: $u8(),
    }

    const NestedPairP = {
        a: $u8(),
        b: {
            c: $i16(),
            d: em.$bool(),
        },
    }

    const p1 = instantiate(PairP)
    p1.x = 10
    p1.y = 20
    console.log(p1)

    const np = instantiate(NestedPairP)
    console.log(np)

    console.log(em.memoryof(NestedPairP))

}
