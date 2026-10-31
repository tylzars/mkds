#include "Main/Unknown/code_02077f0c.h"

#pragma thumb on

void func_02077f48(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) *(
                           const u32 *) ((u8 *) (u32) (((u32) (&data_0217ad08))) + 0))) +
                       0 + (0x1d8u)) = p0;
}

void func_02077f0c(u16 *param_1, int param_2, u32 param_3) {
    u16 v1;
    int v2;
    int v3;
    v1 = *param_1;
    v3 = param_2 - (u32) v1;
    if (v3 < 0) {
        v3 = 0xffff - v3;
    }
    v2 = func_021488e8(v3, (int) param_3);
    *param_1 = *param_1 + v2;
    if ((int) ((*param_1 + 100) - param_2) < 0) {
        *param_1 = (u16) (*param_1 + 100);
        return;
    }
    *param_1 = v1;
}

#pragma thumb off
