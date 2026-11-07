import '@$$emscript'
export const $U = $declare('MODULE')

import * as RfTemp from '@ti.radio.cc27xx/RfTemp.em'

export namespace em$meta {
    export function em$construct() {
        $using(RfTemp)
        $U.auxH()
    }
}

export function apply(): void {
    e$`cc27_rf_trim::apply()`
}
