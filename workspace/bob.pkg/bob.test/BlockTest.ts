import em from '@$$emscript'
export const em$_U = em.$declare('MODULE')

const buf = em.$array(em.$u32(), 5).$make()

export namespace em$meta {
    buf[2] = 100
    console.log(buf[2])
}
