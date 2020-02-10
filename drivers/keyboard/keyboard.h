#pragma once

#include "../../kernel.h"

#define CTRL_PRESS_KEY_CODE 29
#define CTRL_RELEASE_KEY_CODE 157
#define LSHIFT_PRESS_KEY_CODE 42
#define LSHIFT_RELEASE_KEY_CODE 170
#define RSHIFT_PRESS_KEY_CODE 54
#define RSHIFT_RELEASE_KEY_CODE 182
#define ALT_PRESS_KEY_CODE 56
#define ALT_RELEASE_KEY_CODE 184
#define CAPSLOCK_PRESS_KEY_CODE 58

extern void keyboard_handler(void);
extern void kb_init(void);
extern void keyboard_handler_main(void);
void update_keyboard_event(unsigned char keycode);

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

struct kbd_event {
    bool ctrl : 1;
    bool alt : 1;
    bool shift : 1;
    bool del : 1;
    bool capslock : 1;

    unsigned char keycode : 8;
} *keyboard_event;