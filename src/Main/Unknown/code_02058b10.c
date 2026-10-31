#include "Main/Unknown/code_02058b10.h"

#pragma thumb on

void func_02058b10(void) {
    int v1;
    func_020562e8();
    v1 = (int) data_0217aa00 + 0x1608;
    *(u16 *) (v1 + 0x10) = 0xf;
    *(u16 *) (v1 + 0x12) = 1;
}

#pragma thumb off
