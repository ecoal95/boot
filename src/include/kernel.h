#ifndef __KERNEL_H
#define __KERNEL_H

#include "vga.h"
#include <stddef.h>

#define INLINE inline

#define HALT() while (1)

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#define PANIC(msg)                                                             \
    do {                                                                       \
        uint16_t last_row = 0;                                                 \
        uint16_t last_col = 0;                                                 \
        vga_clear(VGA_COLOR_BLACK);                                            \
        vga_puts_r("Kernel Panic: This is a bug", 0, 0, VGA_COLOR_RED,         \
                   VGA_COLOR_BLACK, &last_row, NULL);                          \
        vga_puts_r("Message: " msg, last_row + 1, 0, VGA_COLOR_RED,            \
                   VGA_COLOR_BLACK, &last_row, NULL);                          \
        vga_puts_r("Raised at: ", last_row + 1, 0, VGA_COLOR_RED,              \
                   VGA_COLOR_BLACK, &last_row, NULL);                          \
        vga_puts_r(__func__, last_row + 1, 0, VGA_COLOR_RED, VGA_COLOR_BLACK,  \
                   &last_row, &last_col);                                      \
        vga_puts_r("@"__FILE__                                                 \
                   ":" STRINGIFY(__LINE__),                                    \
                   last_row, last_col + 1, VGA_COLOR_RED, VGA_COLOR_BLACK,     \
                   NULL, NULL);                                                \
        HALT();                                                                \
    } while (0)

#ifdef DEBUG
#define KASSERT(expr, msg)                                                     \
    do {                                                                       \
        if (!(expr))                                                           \
            PANIC("Assertion failed (" msg "): " #expr);                       \
    } while (0)
#else
#define KASSERT(...)
#endif

#endif
