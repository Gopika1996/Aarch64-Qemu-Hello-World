.section .text
.global _start
_start:
    // set up stack pointer (use address 0x40000000 as example)
    ldr x0, =stack_top
    mov sp, x0
 
    // call C main
    bl main
 
    // loop forever if main returns
1:  wfe
    b 1b
 
.section .bss
.space 4096
stack_top:
