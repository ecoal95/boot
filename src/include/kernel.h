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
                   VGA_COLOR_BLACK, NULL, &last_row);                          \
        vga_puts_r("Message: " msg, 0, last_row + 1, VGA_COLOR_RED,            \
                   VGA_COLOR_BLACK, NULL, &last_row);                          \
        vga_puts_r("Raised at: ", 0, last_row + 1, VGA_COLOR_RED,              \
                   VGA_COLOR_BLACK, NULL, &last_row);                          \
        vga_puts_r(__func__, 0, last_row + 1, VGA_COLOR_RED, VGA_COLOR_BLACK,  \
                   &last_col, &last_row);                                      \
        vga_puts_r("@"__FILE__                                                 \
                   ":" STRINGIFY(__LINE__),                                    \
                   last_col + 1, last_row, VGA_COLOR_RED, VGA_COLOR_BLACK,     \
                   NULL, NULL);                                                \
        HALT();                                                                \
    } while (0)

#ifdef DEBUG
#define KASSERT(expr, msg)                                                     \
    do {                                                                       \
        if (!expr)                                                             \
            PANIC("Assertion failed (" msg "): " #expr);                       \
    } while (0)
#else
#define KASSERT(...)
#endif

#endif
