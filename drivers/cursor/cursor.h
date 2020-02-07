#ifndef TOYKERNEL_CURSOR_H
#define TOYKERNEL_CURSOR_H

void cursor_init(unsigned short cursor_start, unsigned short cursor_end);
void disable_cursor(void);
void update_cursor(int x, int y);
unsigned short get_cursor_position(void);

#endif //TOYKERNEL_CURSOR_H
