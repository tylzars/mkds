#include "Main/Unknown/code_020364a8.h"

void func_020364a8(int a, int b, int c, int d, int e) {
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13);
}
