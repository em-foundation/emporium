import '@$$emscript'
export const $U = $declare('MODULE')

import * as BasicI from '@em.makem.basic/BasicI.em'
import * as MakemC from '@$distro/MakemC.em'

export const Basic = $proxy<BasicI.$I>()

export namespace em$meta {
    export function em$configure(): void {
        $using(MakemC)
    }
}

//>> ---- em$targ ---- <<//
