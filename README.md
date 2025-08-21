# Aarch64-Qemu-Hello-World

This is a very small bare-metal kernel in c/assembly that boots with qemu and print a "Hellow World" over the UART Console.

This boot code:

1.Initializes the stack - Essential for C function calls and local variables.

2.Transfers control to C code - Calls the main C function where the actual kernel logic resides.

3.Handles main function return - If main ever returns (which it shouldn't in a kernel), the CPU enters a low-power wait state in an infinite loop.

This is a typical pattern for bare-metal ARM64 systems where assembly handles the initial hardware setup before handing control to higher-level C code.

Lessons learned:
1. boot Flow
2. linker script
3. mmio uart
4. qemu device model

# Prerequisites:

Ubuntu-based system:
  
  sudo apt-get install gcc-aarch64-linux-gnu qemu-system-arm qemu-system-aarch64 make

Fedora-based system:
  
  sudo dnf install gcc-aarch64-linux-gnu qemu-system-arm qemu-system-aarch64 make

# Build steps:
make

# Qemu Command:
qemu-system-aarch64 -M virt -cpu cortex-a57 -nographic -kernel kernel.elf
