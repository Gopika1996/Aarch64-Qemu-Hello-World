CROSS=aarch64-linux-gnu
CFLAGS=-Wall -O2 -ffreestanding -nostdlib
 
all: kernel.elf
 
boot.o: boot.S
$(CROSS)-gcc $(CFLAGS) -c $< -o $@
 
main.o: main.c
$(CROSS)-gcc $(CFLAGS) -c $< -o $@
 
kernel.elf: boot.o main.o
$(CROSS)-ld -T flash.ld -o $@ $^
 
clean:
rm -f *.o kernel.elf
