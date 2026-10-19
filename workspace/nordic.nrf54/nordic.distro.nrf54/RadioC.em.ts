import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as PacketCrypto from '@nordic.radio.nrf54/PacketCrypto.em'
import * as RadioDriver from '@nordic.radio.nrf54/RadioDriver.em'

// Hardware CCM packet protection; the controller supplies counters and encryption state.
export { PacketCrypto, RadioDriver }
