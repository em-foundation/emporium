import '@$$emscript'
export const $U = $declare('MODULE', BenchAlgI)

import * as BenchAlgI from '@em.benchmark.coremark/BenchAlgI.em'
import * as Crc from '@em.benchmark.coremark/Crc.em'
import * as UT from '@em.benchmark.coremark/Utils.em'

export const mem_size = $config<u16>()

type matdat_t = i16
type matres_t = i32

const dimN = $config<u8>()

var matA = $table<matdat_t>()
var matB = $table<matdat_t>()
var matC = $table<matres_t>()

export namespace em$meta {
    export function em$construct() {
        let i = 0
        let j = 0
        while (j < mem_size) {
            i += 1
            j = i * i * 2 * 4
        }
        dimN.$$val = i - 1
        for (const _ of $range(dimN * dimN)) {
            matA.$$add(0)
            matB.$$add(0)
            matC.$$add(0)
        }
    }
}

//>> ---- em$targ ---- <<//

export function kind(): UT.Kind {
    return UT.Kind.MATRIX
}

export function print() {
    prDat(t$`A`, matA.$frame(0))
    prDat(t$`B`, matB.$frame(0))
    prRes(t$`C`)
}

export function run(arg: arg_t): UT.sum_t {
    const val = <matdat_t>arg
    const clipval = enlarge(val)
    let crc = <UT.sum_t>0
    //
    addVal(val)
    mulVal(val)
    crc = Crc.add16(sumDat(clipval), crc)
    //
    mulVec()
    crc = Crc.add16(sumDat(clipval), crc)
    //
    mulMat()
    crc = Crc.add16(sumDat(clipval), crc)
    //
    mulMatBix()
    crc = Crc.add16(sumDat(clipval), crc)
    //
    addVal(-val)
    return Crc.add16(<i16>crc, UT.getCrc(UT.Kind.FINAL))
}

export function setup() {
    const s32 = (<u32>UT.getSeed(1)) | ((<u32>UT.getSeed(2)) << 16)
    let sd = <matdat_t>s32
    if (sd == 0) sd = 1
    let order = <matdat_t>1
    for (const i of $range(dimN)) {
        for (const j of $range(dimN)) {
            sd = <matdat_t>((order * sd) % 65536)
            let val = <matdat_t>(sd + order)
            val = clip(val, false)
            matB[i * dimN + j] = val
            val += order
            val = clip(val, true)
            matA[i * dimN + j] = val
            order += 1
        }
    }
}

// private

function addVal(val: matdat_t) {
    for (const i of $range(dimN)) {
        for (const j of $range(dimN)) {
            matA[i * dimN + j] += val
        }
    }
}

function bix(res: matres_t, lower: u8, upper: u8): matres_t {
    const r = <u32>res
    const l = <u32>lower
    const u = <u32>upper
    return <matres_t>((r >> l) & ~(0xffffffff << u))
}

function clip(d: matdat_t, b: bool_t): matdat_t {
    const x = <u16>d
    return <matdat_t>(x & (b ? 0x0ff : 0x0ffff))
}

function enlarge(val: matdat_t): matdat_t {
    const v = <u16>val
    return <matdat_t>(0xf000 | v)
}

function mulVal(val: matdat_t) {
    for (const i of $range(dimN)) {
        for (const j of $range(dimN)) {
            matC[i * dimN + j] =
                <matres_t>matA[i * dimN + j] * <matres_t>val
        }
    }
}

function mulMat() {
    for (const i of $range(dimN)) {
        for (const j of $range(dimN)) {
            matC[i * dimN + j] = 0
            for (const k of $range(dimN)) {
                matC[i * dimN + j] +=
                    <matres_t>matA[i * dimN + k] *
                    <matres_t>matB[k * dimN + j]
            }
        }
    }
}

function mulMatBix() {
    for (const i of $range(dimN)) {
        for (const j of $range(dimN)) {
            matC[i * dimN + j] = 0
            for (const k of $range(dimN)) {
                const tmp =
                    <matres_t>matA[i * dimN + k] *
                    <matres_t>matB[k * dimN + j]
                matC[i * dimN + j] += bix(tmp, 2, 4) * bix(tmp, 5, 7)
            }
        }
    }
}

function mulVec() {
    for (const i of $range(dimN)) {
        matC[i] = 0
        for (const j of $range(dimN)) {
            matC[i] += <matres_t>matA[i * dimN + j] * <matres_t>matB[j]
        }
    }
}

function prDat(lab: text_t, mat: frame_t<matdat_t>) {
    printf`\n%s:\n    `(lab)
    for (const i of $range(dimN)) {
        let sep = t$``
        for (let j of $range(dimN)) {
            printf`%s%d`(sep, mat[i * dimN + j])
            sep = t$`,`
        }
        printf`\n    `()
    }
}

function prRes(lab: text_t) {
    printf`\n%s:\n    `(lab)
    for (const i of $range(dimN)) {
        let sep = t$``
        for (const j of $range(dimN)) {
            printf`%s%d`(sep, matC[i * dimN + j])
            sep = t$`,`
        }
        printf`\n    `()
    }
}

function sumDat(clipval: matdat_t): matdat_t {
    let cur = <matres_t>0
    let prev = <matres_t>0
    let tmp = <matres_t>0
    let ret = <matdat_t>0
    for (const i of $range(dimN)) {
        for (const j of $range(dimN)) {
            cur = matC[i * dimN + j]
            tmp += cur
            if (tmp > clipval) {
                ret += 10
                tmp = 0
            } else {
                ret += cur > prev ? 1 : 0
            }
            prev = cur
        }
    }
    return ret
}
