; kernel.asm

; nasm directive - 32 bit
bits 32
section .text
        ; multiboot spec
        align 4
        dd 0x1BADB002            ; 'magic'
        dd 0x00                  ; flags
        dd - (0x1BADB002 + 0x00) ; checksum. m+f+c should be zero

global start
global kernel_shutdown
global keyboard_handler
global port_read
global port_write
global load_idt

extern shutdown_emulator_specific
extern keyboard_handler_main
extern kmain

kernel_shutdown:
    call shutdown_emulator_specific ; call emulator-specific shutdown methods

    mov ax, 0x1000
    mov ax, ss
    mov sp, 0xf000
    mov ax, 0x5307
    mov bx, 0x0001
    mov cx, 0x0003
    int 0x15

    ret ; if interrupt doesnt work

port_read:
    ; read data from port
	mov edx, [esp + 4]
	in al, dx
	ret

port_write:
    ; write data to port
	mov   edx, [esp + 4]
	mov   al, [esp + 4 + 4]
	out   dx, al
	ret

load_idt:
    ; load interrupt descriptor table
	mov edx, [esp + 4]
	lidt [edx]
	sti
	ret

keyboard_handler:
    ; handle keyboard input using the keyboard_handler_main function
	call    keyboard_handler_main
	iretd

cursor: ; initialize cursor
    scr.width equ 80

.setcoords: ; set coords of text cursor
    mov dl, scr.width
    mul dl
    add bx, ax

.setoffset:
    mov dx, 0x03D4
    mov al, 0x0F
    out dx, al
    inc dl
    mov al, bl
    out dx, al
    dec dl
    mov al, 0x0E
    out dx, al
    inc dl
    mov al, bh
    out dx, al
    ret

start:
    cli 		; block interrupts
    mov  esp, stack_space
    call kmain
    hlt		 	; halt the CPU

section .bss
resb 8192   ; 8 kb stack size

stack_space:
