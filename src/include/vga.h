#ifndef __VGA_H
#define __VGA_H

#include <stdint.h>
#include "kernel.h"

typedef enum vga_color {
    VGA_COLOR_BLACK,
    VGA_COLOR_BLUE,
    VGA_COLOR_GREEN,
    VGA_COLOR_CYAN,
    VGA_COLOR_RED,
    VGA_COLOR_MAGENTA,
    VGA_COLOR_YELLOW,
    VGA_COLOR_GRAY,
    VGA_COLOR_BRIGHT
} vga_color_t;

extern uint16_t* VGA_VIDEO;
extern const uint16_t VGA_ROWS;
extern const uint16_t VGA_COLS;

void vga_clear(vga_color_t color);
void vga_putc(uint16_t x, uint16_t y, char ch, vga_color_t foreground,
              vga_color_t background);
void vga_puts_r(const char* str, uint16_t initial_row, uint16_t initial_col,
                vga_color_t foreground, vga_color_t background,
                uint16_t* last_row, uint16_t* last_col);
void vga_puts(const char* str, uint16_t initial_row, vga_color_t foreground,
              vga_color_t background);

#endif
