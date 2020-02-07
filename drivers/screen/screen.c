#include "../../kmain.h"

void kernel_print_char(char str) {
    vidptr[current_loc++] = str;
}

/**
 * Output a char pointer array to the screen.
 *
 * @param str
 */
void kernel_print(const char *str)
{
    unsigned int i = 0;
    while(str[i] != '\0') {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x07;
    }
}

/**
 * Output a newline to the screen.
 */
void kernel_print_newline(void)
{
    unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
    current_loc = current_loc + (line_size - current_loc % (line_size));
}

/**
 * Clear the screen.
 */
void kernel_clear_screen(void)
{
    unsigned int i = 0;
    while (i < SCREENSIZE) {
        vidptr[i++] = ' ';
        vidptr[i++] = 0x07;
    }
}
