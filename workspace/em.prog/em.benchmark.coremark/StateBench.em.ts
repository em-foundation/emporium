import '@$$emscript'
export const $U = $declare('MODULE')

import * as Crc from '@em.benchmark.coremark/Crc.em'
import * as UT from '@em.benchmark.coremark/Utils.em'

export const mem_size = $config<u16>()

enum State {
    START, INVALID, S1, S2, INT, FLOAT, EXPONENT, SCIENTIFIC,
}

const NUM_STATES = 8
class StateCnt extends $vector<u32> { $len = NUM_STATES }

const int_pat = $table<text_t>([
    t$`5012`, t$`1234`, t$`-874`, t$`+122`
])
const flt_pat = $table<text_t>([
    t$`35.54400`, t$`.1234500`, t$`-110.700`, t$`+0.64400`
])
const sci_pat = $table<text_t>([
    t$`5.500e+3`, t$`-.123e-2`, t$`-87e+832`, t$`+0.6e-12`
])
const err_pat = $table<text_t>([
    t$`T0.3e-1F`, t$`-T.T++Tq`, t$`1T3.4e4z`, t$`34.0e-T^`
])

const int_pat_len = $config<u16>(int_pat[0].$len)
const flt_pat_len = $config<u16>(flt_pat[0].$len)
const sci_pat_len = $config<u16>(sci_pat[0].$len)
const err_pat_len = $config<u16>(err_pat[0].$len)

var membuf = $table<u8>()

export namespace em$meta {
    export function em$construct() {
        for (const _ of $range(mem_size)) membuf.$$add(0)
    }
}

//>> ---- em$targ ---- <<//

export function kind(): UT.Kind {
    return UT.Kind.STATE
}

export function print() {
    let p = membuf.$ptr()
    let cnt = 0
    printf`\n%c`(c$`"`)
    while (p.$$) {
        if (cnt++ % 8 == 0) {
            printf`\n    `()
        }
        while (true) {
            let c = p.$$
            p.$inc()
            if (c == c$`,`) break
            printf`%c`(c)
        }
        printf`, `()
    }
    printf`\n%c, count = %d\n`(c$`"`, cnt)
}

export function run(arg: i16): UT.sum_t {
    if (arg < 0x22) arg = 0x22
    let final_cnt = StateCnt.$make()
    let trans_cnt = StateCnt.$make()
    for (const i of $range(NUM_STATES)) final_cnt[i] = trans_cnt[i] = 0
    scan(final_cnt, trans_cnt)
    scramble(UT.getSeed(1), arg)
    scan(final_cnt, trans_cnt)
    scramble(UT.getSeed(2), arg)
    let crc = UT.getCrc(UT.Kind.FINAL)
    for (let i of $range(NUM_STATES)) {
        crc = Crc.addU32(final_cnt[i], crc)
        crc = Crc.addU32(trans_cnt[i], crc)
    }
    return crc
}

export function setup() {
    let seed = UT.getSeed(1)
    let p = membuf.$ptr()
    let total = 0
    let pat = t$``
    let plen = 0
    while ((total + plen + 1) < (mem_size - 1)) {
        if (plen) {
            for (const i of $range(plen)) {
                p.$$ = pat[i]
                p.$inc()
            }
            p.$$ = c$`,`
            p.$inc()
            total += plen + 1
        }
        switch (++seed & 0x7) {
            case 0:
            case 1:
            case 2:
                pat = int_pat[(seed >> 3) & 0x3]
                plen = int_pat_len
                break
            case 3:
            case 4:
                pat = flt_pat[(seed >> 3) & 0x3]
                plen = flt_pat_len
                break
            case 5:
            case 6:
                pat = sci_pat[(seed >> 3) & 0x3]
                plen = sci_pat_len
                break
            case 7:
                pat = err_pat[(seed >> 3) & 0x3]
                plen = err_pat_len
                break
        }
    }
}

// private

function isDigit(ch: u8): bool_t {
    return ch >= c$`0` && ch <= c$`9`
}

function nextState(str_ref: $$<ptr_t<u8>>, trans_cnt: index_t<u32>): State {
    let str = str_ref.$$
    let state = <State>State.START
    for (; str.$$ && state != State.INVALID; str.$inc()) {
        const ch = str.$$
        if (ch == c$`,`) {
            str.$inc()
            break
        }
        switch (state) {
            case State.START:
                if (isDigit(ch)) {
                    state = State.INT
                } else if (ch == c$`+` || ch == c$`-`) {
                    state = State.S1
                } else if (ch == c$`.`) {
                    state = State.FLOAT
                } else {
                    state = State.INVALID
                    trans_cnt[ord(State.INVALID)] += 1
                }
                trans_cnt[ord(State.START)] += 1
                break
            case State.S1:
                if (isDigit(ch)) {
                    state = State.INT
                    trans_cnt[ord(State.S1)] += 1
                } else if (ch == c$`.`) {
                    state = State.FLOAT
                    trans_cnt[ord(State.S1)] += 1
                } else {
                    state = State.INVALID
                    trans_cnt[ord(State.S1)] += 1
                }
                break
            case State.INT:
                if (ch == c$`.`) {
                    state = State.FLOAT
                    trans_cnt[ord(State.INT)] += 1
                } else if (!isDigit(ch)) {
                    state = State.INVALID
                    trans_cnt[ord(State.INT)] += 1
                }
                break
            case State.FLOAT:
                if (ch == c$`E` || ch == c$`e`) {
                    state = State.S2
                    trans_cnt[ord(State.FLOAT)] += 1
                } else if (!isDigit(ch)) {
                    state = State.INVALID
                    trans_cnt[ord(State.FLOAT)] += 1
                }
                break
            case State.S2:
                if (ch == c$`+` || ch == c$`-`) {
                    state = State.EXPONENT
                    trans_cnt[ord(State.S2)] += 1
                } else {
                    state = State.INVALID
                    trans_cnt[ord(State.S2)] += 1
                }
                break
            case State.EXPONENT:
                if (isDigit(ch)) {
                    state = State.SCIENTIFIC
                    trans_cnt[ord(State.EXPONENT)] += 1
                } else {
                    state = State.INVALID
                    trans_cnt[ord(State.EXPONENT)] += 1
                }
                break
            case State.SCIENTIFIC:
                if (!isDigit(ch)) {
                    state = State.INVALID
                    trans_cnt[ord(State.INVALID)] += 1
                }
                break
            default:
                printf`*** bad state: %d\n`(state)
                fail()
        }
    }
    str_ref.$$ = str
    return state
}

function ord(state: State): u8 {
    return <u8>state
}

function scan(final_cnt: index_t<u32>, trans_cnt: index_t<u32>) {
    let str = membuf.$ptr()
    let cnt = <u32>0
    while (str.$$) {
        const state = nextState($$(str), trans_cnt)
        cnt += 1
        final_cnt[ord(state)] += 1
    }
}

function scramble(seed: UT.seed_t, step: u32) {
    for (let idx = 0; idx < mem_size; idx += step) {
        if (membuf[idx] != c$`,`) membuf[idx] ^= <u8>seed
    }
}
