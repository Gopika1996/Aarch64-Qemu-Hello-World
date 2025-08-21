ENTRY(_start)
 
SECTIONS {
  . = 0x40080000;        /* load address for QEMU -kernel */
  .text : { *(.text*) }
  .rodata : { *(.rodata*) }
  .data : { *(.data*) }
  .bss : { *(.bss*) *(COMMON) }
}
