#include <stdint.h>
#include "kernel.h"
#include "vga.h"
#include "utils.h"

uint16_t* VGA_VIDEO = (uint16_t*)0xB8000;
const uint16_t VGA_ROWS = 25;
const uint16_t VGA_COLS = 80;

void vga_clear(vga_color_t color) {
    for (uint16_t x = 0; x < VGA_ROWS; ++x)
        for (uint16_t y = 0; y < VGA_COLS; ++y)
            vga_putc(x, y, 'a', color, color);
}

void vga_putc(uint16_t x, uint16_t y, char ch, vga_color_t foreground,
              vga_color_t background) {
    uint16_t vga_encoded = (background << 12) | (foreground << 8) | ch;

    KASSERT(x < VGA_ROWS && y < VGA_COLS,
            "Invalid coordinates passed to vga_putc");
    VGA_VIDEO[x * VGA_COLS + y] = vga_encoded;
}

void vga_puts_r(const char* str, uint16_t initial_row, uint16_t initial_col,
                vga_color_t foreground, vga_color_t background,
                uint16_t* last_row, uint16_t* last_col) {
    size_t len = strlen(str);
    size_t i = 0;
    for (; i < len; ++i)
        vga_putc(initial_row + (initial_col + i) / VGA_COLS,
                 initial_col + i % VGA_COLS, str[i], foreground, background);

    if (last_row)
        *last_row = initial_row + (initial_col + i - 1) / VGA_COLS;
    if (last_col)
        *last_col = (initial_col + i - 1) % VGA_COLS;
}

void vga_puts(const char* str, uint16_t initial_row, vga_color_t foreground,
              vga_color_t background) {
    vga_puts_r(str, initial_row, 0, foreground, background, NULL, NULL);
}
