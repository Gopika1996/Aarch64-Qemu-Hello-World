# Aarch64-Qemu-Hello-World

This is a very small bare-metal kernel in c/assembly that boots with qemu and print a "Hellow World" over the UART Console.

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
