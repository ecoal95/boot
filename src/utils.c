#include "utils.h"

size_t strlen(const char* str) {
    size_t ret = 0;
    while (*str++)
        ret++;

    return ret;
}
