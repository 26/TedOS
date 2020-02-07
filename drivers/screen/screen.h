#ifndef TOYKERNEL_DISPLAY_H
#define TOYKERNEL_DISPLAY_H

extern void kernel_print_char(char str);
extern void kernel_print(const char *str);
extern void kernel_print_newline(void);
extern void kernel_clear_screen(void);

#endif //TOYKERNEL_DISPLAY_H
