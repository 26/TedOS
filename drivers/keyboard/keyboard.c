#include "../../kmain.h"

void kb_init(void)
{
    write_port(0x21 , 0xFD);
}

void handle_keypress(unsigned char keycode) {
    switch(keycode) {
        case ENTER_KEY_CODE:
            kernel_print_newline();
            break;
        case ESCAPE_KEY_CODE:
            kernel_shutdown();
            break;
        default:
            kernel_print_char(keymap[keycode]);
            kernel_print_char(0x07);
            break;
    }
}

void keyboard_handler_main(void)
{
    write_port(0x20, 0x20);
    unsigned char status = read_port(KEYBOARD_STATUS_PORT);

    if (status & 0x01) {
        unsigned char keycode = read_port(KEYBOARD_DATA_PORT);

        if(keycode < 0 || keycode > 127) {
            return;
        }

        handle_keypress(keycode);
    }
}

