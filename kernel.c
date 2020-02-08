/*
* Copyright (C) 2014  Arjun Sreedharan
* License: GPL version 2 or higher http://www.gnu.org/licenses/gpl.html
*/

#include "./drivers/screen/screen.h"
#include "./drivers/idt/idt.h"
#include "./drivers/keyboard/keyboard.h"

#include "memory.h"

void kmain(void)
{
    const char *str = "VimOS 0.0.1";

    kernel_clear_screen();
    kernel_print(str);

    kernel_print_newline();
    kernel_print_newline();

    idt_init((unsigned long) keyboard_handler);
    kb_init();

    while(1) {}
}

void shutdown_emulator_specific(void)
{
    port_write(0xB004, 0x2000); // Bochs and old QEMU versions
    port_write(0x604, 0x2000); // QEMU
    port_write(0x4004, 0x3400); // VirtualBox
}

