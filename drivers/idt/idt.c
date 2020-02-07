#include "idt.h"

#include "../../memory.h"
#include "../../kmain.h"

#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

struct IDT_entry {
    unsigned short int offset_lowerbits;
    unsigned short int selector;
    unsigned char      zero;
    unsigned char      type_attr;
    unsigned short int offset_higherbits;
};

/* create array of IDT_entry */
struct IDT_entry IDT_entries[IDT_SIZE];

void idt_init(unsigned long keyboard_handler)
{
    unsigned long keyboard_address;
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    /* populate IDT entry of keyboard's interrupt */
    keyboard_address = keyboard_handler;
    IDT_entries[0x21].offset_lowerbits = keyboard_address & 0xffff;
    IDT_entries[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
    IDT_entries[0x21].zero = 0;
    IDT_entries[0x21].type_attr = INTERRUPT_GATE;
    IDT_entries[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

    write_port(0x20, 0x11);
    write_port(0xA0, 0x11);
    write_port(0x21, 0x20);
    write_port(0xA1, 0x28);
    write_port(0x21, 0x00);
    write_port(0xA1, 0x00);
    write_port(0x21, 0x01);
    write_port(0xA1, 0x01);
    write_port(0x21, 0xff);
    write_port(0xA1, 0xff);

    idt_address = (unsigned long)IDT_entries;
    idt_ptr[0] = (sizeof (struct IDT_entry) * IDT_SIZE) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16 ;

    load_idt(idt_ptr);
}
