import '@$$emscript'
export const $U = $declare('MODULE')

// Compatibility entry point. New energy programs live in nordic.tests.nrf54.
import * as SleepyCracenP from '@nordic.tests.nrf54/SleepyCracenP.em'

export function em$run() {
    SleepyCracenP.em$run()
}