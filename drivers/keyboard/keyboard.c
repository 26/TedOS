#include "../../memory.h"
#include "../../kernel.h"
#include "keyboard.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

unsigned char keymap[128] = {
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

    keyboard_event->ctrl     = false;
    keyboard_event->alt      = false;
    keyboard_event->capslock = false;
    keyboard_event->shift    = false;
    keyboard_event->del      = false;
    keyboard_event->keycode  = false;
}

void update_keyboard_event(const unsigned char keycode)
{
    keyboard_event->keycode = keycode;

    switch(keycode) {
        case CTRL_PRESS_KEY_CODE:
            keyboard_event->ctrl = true;
            break;
        case CTRL_RELEASE_KEY_CODE:
            keyboard_event->ctrl = false;
            break;
        case LSHIFT_PRESS_KEY_CODE:
        case RSHIFT_PRESS_KEY_CODE:
            keyboard_event->shift = true;
            break;
        case LSHIFT_RELEASE_KEY_CODE:
        case RSHIFT_RELEASE_KEY_CODE:
            keyboard_event->shift = false;
            break;
        case ALT_PRESS_KEY_CODE:
            keyboard_event->alt = true;
            break;
        case ALT_RELEASE_KEY_CODE:
            keyboard_event->alt = false;
            break;
        case CAPSLOCK_PRESS_KEY_CODE:
            if(keyboard_event->capslock == true) {
                keyboard_event->capslock = false;
            } else {
                keyboard_event->capslock = true;
            }
            break;
        default:
            break;
    }
}

void keyboard_handler_main(void)
{
    port_write(0x20, 0x20);
    unsigned char status = port_read(KEYBOARD_STATUS_PORT);

    if (status & 0x01) {
        const unsigned char keycode = port_read(KEYBOARD_DATA_PORT);

        update_keyboard_event(keycode);
        handle_keyboard_event();
    }
}

