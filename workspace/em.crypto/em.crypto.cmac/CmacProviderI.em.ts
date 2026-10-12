import '@$$emscript'
export const $U = $declare('INTERFACE')

export const KEY_LEN = 16
export const MAC_LEN = 16

export class Key extends $vector<u8> { $len = KEY_LEN }
export class Mac extends $vector<u8> { $len = MAC_LEN }

export type Key_Ref = ptr_t<u8>
export type Mac_Ref = ptr_t<u8>

export interface $I {
    compute(key: Key_Ref, msg: frame_t<u8>, mac_OUT: Mac_Ref): void
}
