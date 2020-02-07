#ifndef TOYKERNEL_IDT_H
#define TOYKERNEL_IDT_H

void idt_init(void);
extern void load_idt(unsigned long *idt_ptr);

#endif //TOYKERNEL_IDT_H
