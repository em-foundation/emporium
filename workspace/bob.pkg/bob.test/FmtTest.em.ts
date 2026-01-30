import em from '@$$emscript'
export const $U = em.$declare('MODULE')

export const Args = $array($u32(), 2)
export const NumBuf = $array($u8(), 10)

export namespace em$meta {

    let num_buf = NumBuf.$make()
    let OUT = new Array<number>

    function addOut(buf: em.ArrayLike<u8>) {
        for (let i = 0; i < buf.$len; i++) OUT.push(buf[i])
    }

    function c2d(ch: u8): u8 { return ch - c$`0` }

    function formatNum(buf: frame_t<u8>, num: u32, base: u8, width: i8, pad: u8): frame_t<u8> {
        let HEXDIGS = t$`0123456789ABCDEF`
        let idx = buf.$len
        for (; ;) {
            width -= 1
            idx -= 1
            buf[idx] = HEXDIGS[(num % base)]
            num = Math.floor(num / base)
            if (num == 0) break
        }
        while (width > 0) {
            width -= 1
            idx -= 1
            buf[idx] = pad
        }
        return buf.$frame(idx, 0)
    }

    function isDigit(ch: u8): bool_t {
        return ch >= c$`0` && ch <= c$`9`
    }

    function print(fmt: text_t, a1: any = 0, a2: any = 0) {
        let args = Args.$make()
        args[0] = a1
        args[1] = a2
        let argp = args.$ptr()
        let idx = 0
        while (idx < fmt.$len) {
            let width = 0
            let pad = c$` `
            let ch = fmt[idx++]
            if (ch != c$`%`) {
                OUT.push(ch)
                continue
            }
            ch = fmt[idx++]
            if (ch == c$`0`) {
                pad = ch
                ch = fmt[idx++]
            }
            while (isDigit(ch)) {
                width = width * 10 + c2d(ch)
                ch = fmt[idx++]
            }
            if (ch == c$`d`) {
                let dn = <i32>argp.$$
                argp.$inc()
                if (dn < 0) {
                    OUT.push(c$`-`)
                    dn = -dn
                }
                let nb = formatNum(num_buf, <u32>dn, 10, width, pad)
                addOut(nb)
            }
            else if (ch == c$`x`) {
                let xn = <u32>argp.$$
                argp.$inc()
                let nb = formatNum(num_buf, xn, 16, width, pad)
                addOut(nb)
            }
            else if (ch == c$`c`) {
                let cn = argp.$$
                OUT.push(cn)
            }
            else if (ch == c$`s`) {
                let sb = <text_t><unknown>argp.$$
                argp.$inc()
                addOut(sb)
            }
            else {
                OUT.push(ch)
            }
        }
    }
    // print(em.$T`hello world\n`)
    //print(em.$T`x = 0x%x;`, 10)
    //print(em.$T`c = '%c'`, em.$C`X`)
    print(t$`hello %s!!\n`, t$`esther`)

    console.log(String.fromCharCode(...OUT))
}
