CFLAGS=-m32 -fno-stack-protector
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386

CC=gcc
AS=nasm
LD=ld

all: kernel

kernel: kasm.o kc.o link.ld
	$(LD) $(LDFLAGS) -o kernel kasm.o kc.o -T link.ld 

kasm.o: kernel.asm
	$(AS) $(ASFLAGS) kernel.asm -o kasm.o

kc.o: kernel.c
	$(CC) $(CFLAGS) -o kc.o -c kernel.c

clean:
	rm -f kernel vimOS.iso *.o

iso: vimOS.iso

vimOS.iso: kernel
	mkdir -pv iso/boot/grub
	cp kernel iso/boot
	cp grub.cfg iso/boot/grub
	grub-file --is-x86-multiboot iso/boot/kernel
	grub-mkrescue -o VimOS.iso iso
	rm -rf iso

