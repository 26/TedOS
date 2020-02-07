#ifndef TOYKERNEL_CURSOR_H
#define TOYKERNEL_CURSOR_H

extern void cursor_init(unsigned short cursor_start, unsigned short cursor_end);
extern void cursor_disable(void);
extern void cursor_set(int x, int y);
extern unsigned short cursor_get_position(void);

#endif //TOYKERNEL_CURSOR_H
