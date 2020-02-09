/*
* Copyright (C) 2014  Arjun Sreedharan
* License: GPL version 2 or higher http://www.gnu.org/licenses/gpl.html
*/

#include "./drivers/screen/screen.h"
#include "./drivers/screen/cursor.h"
#include "./drivers/idt/idt.h"
#include "./drivers/keyboard/keyboard.h"

#include "memory.h"
#include "kernel.h"

/**
 * Main kernel entrypoint
 */
void kmain(void)
{
    kernel_mode = BOOT_KERNEL_MODE;

    const char *header = "VimOS ";
    const char *version = "0.0.1";

    idt_init((unsigned long) keyboard_handler);
    kb_init();

    cursor_set(0,2);

    kernel_clear_screen();

    kernel_print(header);
    kernel_print(version);

    kernel_print_newline();
    kernel_print_newline();

    while(1) {}
}

/**
 * Initiliaze emulator specific shutdown sequence
 */
void shutdown_emulator_specific(void)
{
    port_write(0xB004, 0x2000); // Bochs and old QEMU versions
    port_write(0x604, 0x2000); // QEMU
    port_write(0x4004, 0x3400); // VirtualBox
}

