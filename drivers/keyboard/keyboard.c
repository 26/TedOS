#include "../../memory.h"
#include "../../kernel.h"
#include "keyboard.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

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

