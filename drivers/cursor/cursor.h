#ifndef TOYKERNEL_CURSOR_H
#define TOYKERNEL_CURSOR_H

extern void cursor_init(unsigned short cursor_start, unsigned short cursor_end);
extern void disable_cursor(void);
extern void update_cursor(int x, int y);
extern unsigned short get_cursor_position(void);

#endif //TOYKERNEL_CURSOR_H
