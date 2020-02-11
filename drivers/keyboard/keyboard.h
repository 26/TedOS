#pragma once

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
unsigned char keymap[128];

struct kbd_event {
    bool ctrl : 1;
    bool alt : 1;
    bool shift : 1;
    bool del : 1;
    bool capslock : 1;

    unsigned char keycode : 8;
};

extern struct kbd_event *keyboard_event;

