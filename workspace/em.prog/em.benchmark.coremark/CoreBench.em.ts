import '@$$emscript'
export const $U = $declare('MODULE')

import * as Crc from '@em.benchmark.coremark/Crc.em'
import * as ListBench from '@em.benchmark.coremark/ListBench.em'
import * as MatrixBench from '@em.benchmark.coremark/MatrixBench.em'
import * as StateBench from '@em.benchmark.coremark/StateBench.em'
import * as UT from '@em.benchmark.coremark/Utils.em'

const total_data_size = $config<u16>(2000)
const num_algs = $config<u8>(3)

export namespace em$meta {

    export function em$configure() {
        const mem_size = Math.floor(total_data_size / num_algs)
        ListBench.mem_size.$$val = mem_size
        MatrixBench.mem_size.$$val = mem_size
        StateBench.mem_size.$$val = mem_size
    }

    export function em$construct() {
        UT.em$meta.setSeed(1, 0x0)
        UT.em$meta.setSeed(2, 0x0)
        UT.em$meta.setSeed(3, 0x66)
    }
}

//>> ---- em$targ ---- <<//

export function kind(): UT.Kind {
    return UT.Kind.FINAL
}

export function print() {
    ListBench.print()
    MatrixBench.print()
    StateBench.print()
}

export function run(arg: i16): UT.sum_t {
    const crcA = ListBench.run(1)
    UT.setCrc(
        kind(),
        Crc.add16(<i16>crcA, UT.getCrc(kind()))
    )
    const crcB = ListBench.run(-1)
    UT.setCrc(
        kind(),
        Crc.add16(<i16>crcB, UT.getCrc(kind()))
    )
    UT.bindCrc(UT.Kind.LIST, UT.getCrc(kind()))
    return UT.getCrc(kind())
}

export function setup() {
    ListBench.setup()
    MatrixBench.setup()
    StateBench.setup()
}
