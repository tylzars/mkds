#include "Main/Unknown/code_0205982c.h"

#pragma thumb on

void func_0205982c(void *param_1) {
    int v1;
    int v2;
    u32 v3;
    int *v4;
    v3 = (u32) func_02036b74(param_1, ((u32) 0x0000016cu), 0x20);
    v4 = (int *) &data_0217aa00;
    *(u32 *) ((int) data_0217aa00 + ((u32) 0x00001624u)) = v3;
    v1 = 0;
    v2 = 0;
    do {
        v3 = ((u32) func_02036bec(param_1, (u32) 0x12));
        *(u32 *) (*v4 + v2 + 0x162c) = v3;
        v2 = v2 + 4;
        v1 = v1 + 1;
    } while (v1 < 8);
}

#pragma thumb off
