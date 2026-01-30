import '@$$emscript'
export const $U = $declare('MODULE')

import * as Console from '@em.lang/Console.em'

const in_max_tab = $table<f32>()
const in_min_tab = $table<f32>()

export namespace em$meta {

    const in_max_vals = [
        11.8999996,
        2040.0000000,
        2214.0000000,
        2683.0000000,
        2775.0000000,
        2523.0000000,
        44.5999985,
        88.6999969,
        2.1805999,
    ]
    const in_min_vals = [
        0.1000000,
        647.0000000,
        387.0000000,
        322.0000000,
        559.0000000,
        225.0000000,
        -1.3000000,
        9.1999998,
        0.1847000,
    ]

    export function em$construct() {
        for (const v of in_max_vals) in_max_tab.$$add(v)
        for (const v of in_min_vals) in_min_tab.$$add(v)
    }
}

//>> ---- em$targ ---- <<//

const w0: f32 = 0.5644180
const b0: f32 = 0.1098376
const w1: f32 = 0.9692999
const b1: f32 = -0.4583102

const a1: f32 = 10.0783634

const out_min: f32 = 0.2000000
const out_max: f32 = 63.7000008
const out_span: f32 = out_max - out_min

class Inputs extends $vector<f32> { $len = 9 }

export function em$run() {
    let inputs = Inputs.$make()
    inputs[0] = 2.7
    inputs[1] = 1146
    inputs[2] = 1125
    inputs[3] = 846
    inputs[4] = 1511
    inputs[5] = 1016
    inputs[6] = 33.4
    inputs[7] = 20.3
    inputs[8] = 1.027
    const res = predict(inputs)
    Console.prF32(res, 6)
    printf`\n`()
}

export function predict(in_vals: index_t<f32>): f32 {
    const s2 = scale01(in_vals[2], in_min_tab[2], in_max_tab[2])
    /* Neuron 0: clip01 */
    const z0 = w0 * s2 + b0
    const y0 = clampf(z0, 0.0, 1.0)
    /* Neuron 1: sigmoid */
    const z1 = w1 * y0 + b1
    const y1 = sigmoid(z1, a1)
    // const y1 = 1.0 / (1.0 + expf(-a1 * z1));
    return out_min + y1 * out_span;
}

function clampf(x: f32, lo: f32, hi: f32): f32 {
    if (x < lo) return lo
    if (x > hi) return hi
    return x
}

function scale01(u: f32, u_min: f32, u_max: f32): f32 {
    const x = clampf(u, u_min, u_max)
    const d = u_max - u_min
    return (x - u_min) / d
}

function sigmoid(z: f32, a: f32): f32 {
    const e: f32 = e$`expf(-a * z)`
    return 1.0 / (1.0 + e)
}
