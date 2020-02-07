#ifndef TOYKERNEL_KMAIN_H
#define TOYKERNEL_KMAIN_H

#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE * LINES
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

#include "drivers/drivers.h"
#include "memory.h"

char *vidptr = (char*)0xb8000;
unsigned int current_loc = 0;

extern void start();
extern void kernel_shutdown();

#endif //TOYKERNEL_KMAIN_H
