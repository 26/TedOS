#include "common.h"

#include "../../memory.h"

/**
 * Enables the cursor.
 */
void cursor_init(unsigned short cursor_start, unsigned short cursor_end)
{
    port_write(0x3D4, 0x0A);
    port_write(0x3D5, (port_read(0x3D5) & 0xC0) | cursor_start);

    port_write(0x3D4, 0x0B);
    port_write(0x3D5, (port_read(0x3D5) & 0xE0) | cursor_end);
}

/**
 * Disables the cursor.
 */
void cursor_disable(void)
{
    port_write(0x3D4, 0x0A);
    port_write(0x3D5, 0x20);
}

/**
 * Moves the cursor to the given coordinates.
 *
 * @credit osdev.org
 * @param x
 * @param y
 */
void cursor_set(int x, int y)
{
    unsigned short pos = y * COLUMNS_IN_LINE + x;

    port_write(0x3D4, 0x0F);
    port_write(0x3D5, (unsigned short) (pos & 0xFF));
    port_write(0x3D4, 0x0E);
    port_write(0x3D5, (unsigned short) ((pos >> 8) & 0xFF));
}

/**
 * Returns the cursor position, where y = pos / COLUMNS_IN_LINE and x = pos % COLUMNS_IN_LINE.
 *
 * @credit osdev.org
 * @return
 */
unsigned short cursor_get_position(void)
{
    unsigned short pos = 0;

    port_write(0x3D4, 0x0F);
    pos |= port_read(0x3D5);

    port_write(0x3D4, 0x0E);
    pos |= ((unsigned short)port_read(0x3D5)) << 8;

    return pos;
}
