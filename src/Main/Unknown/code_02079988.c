#include "Main/Unknown/code_02079988.h"

#pragma thumb on

void func_02079988(int a, u32 b) {
    u16 v1;
    v1 = (int) b % 3;
    *(u16 *) (a + 0x68) = v1;
}

#pragma thumb off
