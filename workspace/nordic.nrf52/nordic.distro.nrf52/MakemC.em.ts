import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Basic from '@nordic.makem.nrf52/Basic.em'
import * as Makem from '@em.makem/Makem.em'

export function em$configure(): void {
    Makem.Basic.$$dlg = Basic
}
