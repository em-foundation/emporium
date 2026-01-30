import em from '@$$emscript'
export const $U = em.$declare('COMPOSITE')

export function em$generate() {
    let out = $outfile('bob.test/frag.txt')
    out.addFrag(`
                    |-> MAJOR
                    |->     MINOR
                    |->     MINOR
                    |-> 
                    |-> 
                    |-> 
        `)
    out.close()
}
