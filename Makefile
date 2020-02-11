CFLAGS=-m32 -nostdinc -fno-stack-protector -std=c11 -Wall -Wextra -pedantic
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386
MKFLAGS=
QMFLAGS=-kernel

CC=gcc
AS=nasm
LD=ld
MK=make
QM=qemu-system-i386

all: kernel

kernel: kasm.o kc.o driver_idt.o driver_keyboard.o driver_screen_screen.o driver_screen_cursor.o link.ld 
	$(LD) $(LDFLAGS) -o kernel kasm.o kc.o driver_idt.o driver_keyboard.o driver_screen_screen.o driver_screen_cursor.o -T link.ld

debug: kernel
	$(MK) $(MKFLAGS) clean
	$(MK) $(MKFLAGS) kernel
	$(QM) $(QMFLAGS) kernel
	$(MK) $(MKFLAGS) clean

kasm.o: kernel.asm
	$(AS) $(ASFLAGS) kernel.asm -o kasm.o

kc.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kc.o

driver_idt.o: drivers/idt/idt.c
	$(CC) $(CFLAGS) -c drivers/idt/idt.c -o driver_idt.o

driver_keyboard.o: drivers/keyboard/keyboard.c
	$(CC) $(CFLAGS) -c drivers/keyboard/keyboard.c -o driver_keyboard.o

driver_screen_screen.o: drivers/screen/screen.c 
	$(CC) $(CFLAGS) -c drivers/screen/screen.c -o driver_screen_screen.o

driver_screen_cursor.o: drivers/screen/cursor.c
	$(CC) $(CFLAGS) -c drivers/screen/cursor.c -o driver_screen_cursor.o

clean:
	rm -f kernel *.o
