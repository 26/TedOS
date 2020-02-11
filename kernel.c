#include "memory.h"
#include "kernel.h"

#include "./drivers/screen/screen.h"
#include "./drivers/screen/cursor.h"
#include "./drivers/idt/idt.h"
#include "./drivers/keyboard/keyboard.h"


enum kernel_mode mode;

/**
 * Main kernel entrypoint
 */
void kmain(void)
{
    mode = BOOT_KERNEL_MODE;

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
 * This function gets called by the keyboard driver when a new keyboard event has occurred.
 */
void handle_keyboard_event(void) {
    if(keyboard_event->ctrl == true && keyboard_event->alt == true) {
        kernel_print_char('y');
    } else if(keyboard_event->keycode > 0 && keyboard_event->keycode < 127) {
        kernel_print_char('n');
    }
}

/**
 * Initialize emulator specific shutdown sequence
 */
void shutdown_emulator_specific(void)
{
    port_write(0xB004, 0x2000); // Bochs and old QEMU versions
    port_write(0x604, 0x2000); // QEMU
    port_write(0x4004, 0x3400); // VirtualBox
}

