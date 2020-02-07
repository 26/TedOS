#pragma once

extern void idt_init(void);
extern void load_idt(unsigned long *idt_ptr);
