import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function em$generate() {
    let out = $outfile('rpi.distro.2040/startup.cpp')
    out.addFrag(`
        |-> #include <stdbool.h>
        |-> #include <stdint.h>
        |-> 
        |-> #include "../em.arch.arm/intr.cpp"
        |-> #include "../em.arch.arm/startup.cpp"
        |-> 
        |-> extern void em_main();
        |-> 
        |-> extern "C" bool __is_warm() {
        |->     return false;
        |-> }
        |-> 

        |-> extern "C" const intvec_elem __vector_table[];
        |-> 
        |-> extern "C" void __attribute__((section(".boot2"))) __em_boot2() {
        |-> 
        |->     XIP_SSI->SSIENR = 0;
        |->     XIP_SSI->BAUDR = 2; // Must be even
        |->     XIP_SSI->CTRLR0 = (XIP_SSI_CTRLR0_SPI_FRF_STD << XIP_SSI_CTRLR0_SPI_FRF_Pos) |
        |->         (XIP_SSI_CTRLR0_TMOD_EEPROM_READ << XIP_SSI_CTRLR0_TMOD_Pos) |
        |->         ((32-1) << XIP_SSI_CTRLR0_DFS_32_Pos);
        |->     XIP_SSI->CTRLR1 = (0 << XIP_SSI_CTRLR1_NDF_Pos);
        |->     XIP_SSI->SPI_CTRLR0 = (0x03/*READ_DATA*/ << XIP_SSI_SPI_CTRLR0_XIP_CMD_Pos) |
        |->         ((24 / 4) << XIP_SSI_SPI_CTRLR0_ADDR_L_Pos) |
        |->         (XIP_SSI_SPI_CTRLR0_INST_L_8B << XIP_SSI_SPI_CTRLR0_INST_L_Pos) |
        |->         (XIP_SSI_SPI_CTRLR0_TRANS_TYPE_1C1A << XIP_SSI_SPI_CTRLR0_TRANS_TYPE_Pos);
        |->     XIP_SSI->SSIENR = XIP_SSI_SSIENR_SSI_EN_Msk;
        |-> 
        |->     uint32_t* wp = (uint32_t*)__vector_table;
        |->     uint32_t stackPtr = *wp++;
        |->     uint32_t startAdr = *wp;
        |->     asm("mov sp, %[v]"        : : [v] "r" (stackPtr));
        |->     asm("bx %[v]"             : : [v] "r" (startAdr));
        |-> 
        |-> }
    
    `)
    out.close()
}
