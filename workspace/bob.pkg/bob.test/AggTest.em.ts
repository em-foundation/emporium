import em from '@$$emscript'
export const $U = em.$declare('MODULE')

class Shape extends $struct {
    scale: u32
    freqdev: u32
    coeff: frame_t<u8>
}

const BLE_SHAPE = $config<Shape>(Shape.$make())

export namespace em$meta {
    export function em$construct() {
        BLE_SHAPE.$$.scale = 0x0FDE2
        BLE_SHAPE.$$.freqdev = 0x0003D090
        BLE_SHAPE.$$.coeff = $frame<u8>([0x01, 0x02, 0x05, 0x0A, 0x14, 0x22, 0x37, 0x52, 0x71, 0x91, 0xB0, 0xCB, 0xE0, 0xEE, 0xF8, 0xFD, 0xFF])
        // BLE_SHAPE.$$.coeff = $frame<u8>([0x01, 0x02])
        // console.log(BLE_SHAPE)
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    printf`scale = %x, len = %d\n`((BLE_SHAPE.$$).scale, (BLE_SHAPE.$$).coeff.$len)
    for (const c of (BLE_SHAPE.$$).coeff) {
        printf`%02x\n`(c)
    }
}

/*

    const BLE_1M_SHAPE = Shape{
        .scale = 0x0FDE2,
        .freqdev = 0x0003D090,
        .coeff = &[_]u8{ 0x01, 0x02, 0x05, 0x0A, 0x14, 0x22, 0x37, 0x52, 0x71, 0x91, 0xB0, 0xCB, 0xE0, 0xEE, 0xF8, 0xFD, 0xFF },
    };

*/