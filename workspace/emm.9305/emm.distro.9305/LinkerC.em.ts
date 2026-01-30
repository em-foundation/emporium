import '@$$emscript'
export const $U = $declare('COMPOSITE')

export function genScript() {
    const use_sram = $property('em.build.BootFlash', false)
    let out = $outfile('linkcmd.ld')
    if (!use_sram) {
        out.addFrag(`
            |-> MEMORY {
            |->     BMEM : ORIGIN = 0x0030_0000, LENGTH = 8K
            |->     DMEM : ORIGIN = 0x0080_1000, LENGTH = 24K
            |->     IMEM : ORIGIN = 0x0030_2000, LENGTH = 512K - 8K
            |-> }
            |-> 
            |-> SECTIONS {
            |-> 
            |->     .entry : {
            |->         KEEP(*(.entry.*))
            |->     } > BMEM
            |-> 
            |->     .intvec : {
            |->         KEEP(*(.intvec.*))
            |->     } > IMEM
            |-> 
            |->     .text : {
            |->         *(.start)
            |->         *(.text .text.*)
            |->         . = ALIGN(., 4);
            |->     } > IMEM
            |->     .const : {
            |->         *(.rodata .rodata* .constdata .constdata*)
            |->         . = ALIGN(., 4);
            |->         __data_load_start__ = ALIGN(., 4);
            |->     } > IMEM
            |-> 
            |->     .data : {
            |->         *(.data .data.* .sdata .sdata.*)
            |->         . = ALIGN(., 4);
            |->     } > DMEM AT > IMEM
            |-> 
            |->     .bss (NOLOAD): {
            |->         *(.bss .bss.*)
            |->         *(.sbss .sbss.*)
            |->         . = ALIGN(., 4);
            |->     } > DMEM
            |-> 
            |->     __bss_addr__ = ADDR(.bss);
            |->     __bss_size__ = SIZEOF(.bss) / 4;
            |->     __code_load__ = ADDR(.text);
            |->     __data_addr__ = ADDR(.data);
            |->     __data_load__ = LOADADDR(.data);
            |->     __data_size__ = SIZEOF(.data) / 4;
            |->     __code_addr__ = ~0;
            |->     __code_size__ = ~0;
            |->     __stack_top__ = 0x0080_8000;
            |-> 
            |->     __CTORS_INIT = 0;
            |-> }
        `)
    } else {
        out.addFrag(`
            |-> MEMORY {
            |->     BMEM : ORIGIN = 0x0030_0000, LENGTH = 8K
            |->     DMEM : ORIGIN = 0x0080_1000, LENGTH = 24K
            |->     IMEM : ORIGIN = 0x0018_4000, LENGTH = 16K
            |->     LMEM : ORIGIN = 0x0030_2000, LENGTH = 512K - 8K
            |-> 
            |-> }
            |-> 
            |-> SECTIONS {
            |-> 
            |->     .entry : {
            |->         KEEP(*(.entry.*))
            |->     } > BMEM
            |-> 
            |->     .text : {
            |->         *(.start)
            |->         KEEP(*(.intvec.*))
            |->         *(.text .text.*)
            |->         . = ALIGN(., 4);
            |->     } > IMEM AT > LMEM
            |->     .const : {
            |->         *(.rodata .rodata* .constdata .constdata*)
            |->         . = ALIGN(., 4);
            |->         __data_load_start__ = ALIGN(., 4);
            |->     } > IMEM AT > LMEM
            |-> 
            |->     .data : {
            |->         *(.data .data.* .sdata .sdata.*)
            |->         . = ALIGN(., 4);
            |->     } > DMEM AT > LMEM
            |-> 
            |->     .bss (NOLOAD): {
            |->         *(.bss .bss.*)
            |->         *(.sbss .sbss.*)
            |->         . = ALIGN(., 4);
            |->     } > DMEM
            |-> 
            |->     __bss_addr__ = ADDR(.bss);
            |->     __bss_size__ = SIZEOF(.bss) / 4;
            |->     __data_addr__ = ADDR(.data);
            |->     __data_load__ = LOADADDR(.data);
            |->     __data_size__ = SIZEOF(.data) / 4;
            |->     __code_addr__ = 0x0080_8000;
            |->     __code_load__ = LOADADDR(.text);
            |->     __code_size__ = ((__data_load__ - __code_load__) / 4);
            |->     __stack_top__ = 0x0080_8000;
            |-> 
            |->     __CTORS_INIT = 0;
            |-> }
        `)
    }
    out.close()
    let rom_out = $outfile('rom.sym')
    rom_out.addFile('../emm.9305/emm.distro.9305/rom.sym')
    rom_out.close()
}
