#include "Main/Unknown/code_02079988.h"

#pragma thumb on

void func_02079988(int param_1, u32 param_2) {
    u16 v1;
    v1 = (int) param_2 % 3;
    *(u16 *) (param_1 + 0x68) = v1;
}

#pragma thumb off
