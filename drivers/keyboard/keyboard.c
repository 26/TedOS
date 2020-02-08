#include "../../kmain.h"
#include "../../memory.h"

#include "../screen/screen.h"

#define ENTER_KEY_CODE 0x1C
#define ESCAPE_KEY_CODE 0x01
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

/* The following array is taken from
    http://www.osdever.net/bkerndev/Docs/keyboard.htm
*/
static unsigned char keymap[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
    '9', '0', '-', '=', '\b',	/* Backspace */
    '\t',			/* Tab */
    'q', 'w', 'e', 'r',	/* 19 */
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
    '\'', '`',   0,		/* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
    'm', ',', '.', '/',   0,				/* Right shift */
    '*',
    0,	/* Alt */
    ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
    '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
    '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

void kb_init(void)
{
    port_write(0x21 , 0xFD);
}

void handle_keypress(unsigned char keycode) {
    char string[5];

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
    port_write(0x20, 0x20);
    unsigned char status = port_read(KEYBOARD_STATUS_PORT);

    if (status & 0x01) {
        unsigned char keycode = port_read(KEYBOARD_DATA_PORT);

        if(keycode < 0 || keycode > 127) {
            // Invalid keycode or extended ASCII code (unsupported)
            return;
        }

        handle_keypress(keycode);
    }
}

