#pragma once

int kernel_mode;

enum {
    SHUTDOWN_KERNEL_MODE,
    BOOT_KERNEL_MODE,
    VIM_KERNEL_MODE
};

typedef enum {false = 0, true = 1} bool;

extern void shutdown_emulator_specific(void);
extern void kmain(void);
extern void start(void);
extern void kernel_shutdown(void);