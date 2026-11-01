#include "Main/Unknown/code_020364a8.h"

void func_020364a8(int param_1, int param_2, int param_3, int param_4, int param_5) {
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & 0x43) | (param_1 << 14) | (param_2 << 7) | (param_3 << 8) |
                         (param_4 << 2) | (param_5 << 13);
}
