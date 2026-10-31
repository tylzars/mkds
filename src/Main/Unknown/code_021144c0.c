#include "Main/Unknown/code_021144c0.h"

#pragma thumb on

void func_021144c0(void *param_1) {
    int v1;
    u32 v2;
    v1 = ((u32) func_02036bec(param_1, (u32) 0x10));
    *(int *) &data_0217d34c = v1;
    v2 = ((u32) func_02036bec(param_1, (u32) 0x78));
    *(u32 *) ((int) data_0217d34c + 4) = v2;
    v2 = (u32) func_0205eda0(param_1);
    *(u32 *) ((int) data_0217d34c + 8) = v2;
    v2 = ((int) func_0204799c((const char *) &data_0216d3e4));
    *(u32 *) ((int) data_0217d34c + 0xc) = v2;
}

#pragma thumb off
