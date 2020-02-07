#ifndef TOYKERNEL_KEYBOARD_H
#define TOYKERNEL_KEYBOARD_H

#include "keymap.h"

#define ENTER_KEY_CODE 0x1C
#define ESCAPE_KEY_CODE 0x1B
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

extern void keyboard_handler(void);
void kb_init(void);
void keyboard_handler_main(void);

#endif //TOYKERNEL_KEYBOARD_H