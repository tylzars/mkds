#include "Main/Unknown/code_02058f28.h"

#pragma thumb on

void func_02058f28(void) {
    int v1;
    v1 = func_02058dc0(func_02058f58);
    if (v1 == 1) {
        v1 = (int) data_0217aa00 + 0x1608;
        *(u16 *) (v1 + 0x10) = 0xf;
        *(u16 *) (v1 + 0x12) = 1;
    }
}

#pragma thumb off
