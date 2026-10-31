#include "Main/Unknown/code_02127a38.h"

#pragma thumb on

void func_02127a38(void) {
    int *v1;
    int v2;
    v1 = (int *) &data_0217d3f4;
    v2 = *(int *) &data_0217d3f4;
    if (*(int *) (0x28 + v2) != 0) {
        *(u32 *) (v2 + 8) = 0;
        *(u32 *) (*v1 + 0x28) = 0;
        return;
    }
    *(int *) (v2 + 0xc) = *(int *) (v2 + 0xc) + 1;
    v2 = *(int *) (*v1 + 0xc);
    if (15 <= v2) {
        *(u32 *) (*v1 + 0x1c) = 1;
        *(u32 *) (*v1 + 0xc) = 0xf;
        return;
    }
    if (5 <= v2) {
        func_02127d74();
    }
}

#pragma thumb off
