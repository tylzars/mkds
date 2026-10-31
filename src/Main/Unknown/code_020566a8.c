#include "Main/Unknown/code_020566a8.h"

#pragma thumb on

void func_020566a8(u32 param_1, int param_2) {
    int v1;
    u32 v2;
    v2 = (u32) data_0217aa08->mUnk_18;
    *(u32 *) (param_2 + 8) = *(u32 *) (param_2 + 8) & 0xfffffffe | 1;
    func_0214d1fc((const void *) ((u16 *) (u32) param_2), (void *) ((u32 *) v2),
                  (u32) (((u32) 0x00001000u)));
    func_02057944((int) param_1, (const void *) v2);
    v1 = func_020573c8(param_1);
    if (v1 == 0) {
        func_0205746c(param_1, data_0217aa08->mUnk_00->mUnk_2a, 2);
        func_020574a0();
    }
}

#pragma thumb off
