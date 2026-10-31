#include "Main/Unknown/code_020588a8.h"

#pragma thumb on

void func_020588a8(void) {
    int v1;
    v1 = func_02058dc0(func_02058efc);
    if (v1 == 1) {
        v1 = (int) data_0217aa00 + 0x1608;
        *(u16 *) (v1 + 0x10) = 0xc;
        *(u16 *) (v1 + 0x12) = 1;
    }
}

#pragma thumb off
