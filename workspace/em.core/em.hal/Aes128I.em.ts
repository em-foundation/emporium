import '@$$emscript'
export const $U = $declare('INTERFACE')

export const KEY_LEN = 16
export const BLOCK_LEN = 16

export class Key extends $vector<u8> { $len = KEY_LEN }
export class Block extends $vector<u8> { $len = BLOCK_LEN }

export type Key_Ref = ptr_t<u8>
export type Block_Ref = ptr_t<u8>

export interface $I {
    encrypt(key: Key_Ref, src: Block_Ref, dst: Block_Ref): void
}
