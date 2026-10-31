#include "Main/Unknown/code_02128570.h"

#pragma thumb on

void func_02128570(void) {
    int v1;
    v1 = *(int *) &data_0217d3f8;
    if (*(int *) (v1 + 0x814) != 0) {
        *(u32 *) (v1 + 8) = 3;
        func_02128624(0);
        return;
    }
    if (*(int *) (v1 + 0x818) != 0) {
        *(u32 *) (v1 + 8) = 4;
    }
}

#pragma thumb off
