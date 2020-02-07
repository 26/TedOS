#pragma once

extern void idt_init(unsigned long keyboard_handler);
extern void load_idt(unsigned long *idt_ptr);
