#include <stdint.h>
 
#define UART0_BASE 0x09000000UL   // QEMU virt machine PL011 UART
 
static inline void mmio_write(uint32_t reg, uint32_t val) {
    *(volatile uint32_t*)reg = val;
}
 
void uart_putc(char c) {
    while (*(volatile uint32_t*)(UART0_BASE + 0x18) & (1 << 5)); // TX full?
    mmio_write(UART0_BASE, c);
}
 
void uart_puts(const char *s) {
    while (*s) {
        if (*s == '\n') uart_putc('\r'); // CR+LF
        uart_putc(*s++);
    }
}
 
void main(void) {
    uart_puts("Hello, ARM64 World!\n");
    while (1);
}
