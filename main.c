#include <stdint.h>
 
#define UART0_BASE 0x09000000UL   // QEMU virt machine PL011 UART
 
/**
 * @brief Writes a 32-bit value to a memory-mapped I/O register.
 *
 * This function performs a memory-mapped I/O write operation by writing
 * a 32-bit value to the specified register address. The volatile keyword
 * ensures the compiler does not optimize away the memory access.
 *
 * @param reg The physical address of the MMIO register to write to
 * @param val The 32-bit value to write to the register
 *
 * @return void This function does not return a value
 */
static inline void mmio_write(volatile uint32_t* reg, uint32_t val) {
    *reg = val;
}
 
/**
 * @brief Transmits a single character through the UART interface.
 *
 * This function sends a single character via the PL011 UART by first
 * waiting for the transmit FIFO to have space available, then writing
 * the character to the UART data register. The function blocks until
 * the character can be transmitted.
 *
 * @param c The character to transmit through the UART
 *
 * @return void This function does not return a value
 */
void uart_putc(char c) {
    while ((volatile uint32_t)(UART0_BASE + 0x18) & (1 << 5)); // TX full?
    mmio_write((volatile uint32_t*)UART0_BASE, c);
}
 
/**
 * @brief Transmits a null-terminated string through the UART interface.
 *
 * This function sends a complete string via the PL011 UART by iterating
 * through each character and transmitting it using uart_putc(). When a
 * newline character ('\n') is encountered, it automatically inserts a
 * carriage return ('\r') before the newline to ensure proper line ending
 * formatting for terminal compatibility (CR+LF sequence).
 *
 * @param s Pointer to the null-terminated string to transmit through the UART.
 *          The string must be properly null-terminated to avoid undefined behavior.
 *
 * @return void This function does not return a value
 */
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