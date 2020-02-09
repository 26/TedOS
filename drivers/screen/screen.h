#pragma once

extern void kernel_print_char(char str);
extern void kernel_print(const char *str);
extern void kernel_print_newline(void);
extern void kernel_clear_screen(void);
extern void kernel_backspace(void);
extern void location_reset(void);
extern void location_set(unsigned int position);
