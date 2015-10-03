#include "kernel.h"
#include "vga.h"

void kernel_main() {
    PANIC("EXAMPLE with a very very very... really long message, of more than "
          "eighty fucking columns, to see how it behaves");
}
