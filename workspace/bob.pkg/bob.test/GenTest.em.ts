import '@$$emscript'
export const $U = $declare('MODULE')

const iter_count = 1000

export namespace em$meta {
    export function em$generate() {
        let out = $outfile(`${$U.uid}-gen.cpp`)
        out.addFrag(`
                                    |-> extern "C" em::u32 doCount() {
                                    |->     volatile em::u32 val = 0;
        `)
        for (const _ of $range(iter_count)) {
            out.addFrag(`
                                    |->     val += 1;
            `)
        }
        out.addFrag(`
                                    |->     return val;
                                    |-> }
        `)
        out.close()
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    $['%%d+']
    let val: volatile_t<u32> = 0
    for (const _ of $range(10)) {
        val = e$`doCount()`
    }
    $['%%d-']
    printf`val = %d\n`(val)
}