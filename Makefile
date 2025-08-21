CROSS=aarch64-linux-gnu
CFLAGS=-Wall -O2 -ffreestanding -nostdlib

#Build kernel executable 
all: kernel.elf

#compile boot.S
boot.o: boot.S
 $(CROSS)-gcc $(CFLAGS) -c $< -o $@

#compile main.c
main.o: main.c
 $(CROSS)-gcc $(CFLAGS) -c $< -o $@

#Link executable
kernel.elf: boot.o main.o
 $(CROSS)-ld -T flash.ld -o $@ $^

#clean build
clean:
 rm -f *.o kernel.elf
