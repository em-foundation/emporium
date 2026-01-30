import em from '@$$emscript'
export const $U = em.$declare('MODULE')

export namespace em$meta {

    type MyInt = i16

    class Pair extends $struct {
        x: i16
        y: i8
    }
    type MyPair = Pair
    class Info extends $struct {
        // p: Pair = Pair.$make()
        p: Pair
        m: MyPair
        b: bool_t
    }
    const info = Info.$make()
    console.log($sizeof<Info>)
    console.log(info)

    /*
        type Nested = struct_t<{
            a: i16
            b: struct_t<{
                c: u8
                d: bool_t
            }>
            e: i32
        }>
    
        console.log($sizeof<Nested>)  // Expected output: 2 + (1 + 1) + 4 = 8
    */
}
