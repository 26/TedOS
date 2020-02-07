#ifndef TOYKERNEL_MEMORY_H
#define TOYKERNEL_MEMORY_H

extern unsigned char read_port(unsigned short port);
extern void write_port(unsigned short port, unsigned char data);

#endif //TOYKERNEL_MEMORY_H
