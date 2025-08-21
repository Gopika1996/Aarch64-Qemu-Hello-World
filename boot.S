.section .text                  //  Places the following code in the executable text section
.global _start                  // Makes the _start symbol globally visible so the linker can find it as the entry point
_start:
    ldr x0, =stack_top          //  Loads the address of stack_top into register x0
    mov sp, x0                  // Sets the stack pointer (sp) to point to the top of the allocated stack

    bl main                     // call C main
 
// loop forever if main returns

1:  wfe                         // Wait for an interrupt (WFE)     
    b 1b                        // Unconditional branch back to label 1 (the b suffix means "backward")

.section .bss                   // Places the following in the BSS section (uninitialized data)
.space 4096                     // Reserves 4096 bytes (4KB) of space for the stack
stack_top:                      // Label marking the end of the reserved space (stacks grow downward on ARM64)
