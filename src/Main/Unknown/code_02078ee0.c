#include "Main/Unknown/code_02078ee0.h"

#pragma thumb on

void func_02078f78(Unk020136f0 *param_1) {
    u32 v1;
    v1 = (u32) func_020136f0(param_1);
    *(u32 *) ((int) data_0217ad08 + 0x1d4) = v1;
    func_02012cbc(param_1);
}

void func_02078f18(void *param_1, int param_2) {
    u32 v1;
    func_02079a3c((u32 *) ((u32 *) (u32) param_2));
    *(u32 *) (param_2 + 0xb0) = (u32) data_021759d0->mUnk_00;
    *(u32 *) (param_2 + 0xb4) = 0;
    v1 = ((u32) func_02036bec(param_1, (u32) 0x6c));
    *(u32 *) (param_2 + 0x10) = v1;
    v1 = ((u32) func_02036bec(param_1, (u32) 0x6c));
    *(u32 *) (param_2 + 0x14) = v1;
    v1 = ((u32) func_02036bec(param_1, (u32) 0x6c));
    *(u32 *) (param_2 + 0x18) = v1;
    v1 = ((u32) func_02036bec(param_1, (u32) 0x74));
    *(u32 *) (param_2 + 0x1c) = v1;
    v1 = ((u32) func_02036bec(param_1, (u32) 0x38));
    *(u32 *) (param_2 + 8) = v1;
}

void func_02078ee0(u32 *param_1, int param_2) {
    u32 v1;
    v1 = 0;
    *param_1 = 0xffffffff;
    param_1[1] = 0xffffffff;
    param_1[2] = ((u32) 0x00001000u);
    *(u16 *) ((int) param_1 + 0x16) = (short) ((u32) 0x0000eaabu);
    *(u16 *) (param_1 + 5) = *(u16 *) ((int) param_1 + 0x16);
    *(u16 *) (param_1 + 6) = 0;
    param_1[3] = 0;
    param_1[4] = 0xffffff88;
    if (param_2 != 0) {
        v1 = 0xffffff06;
    }
    param_1[0xb] = v1;
    param_1[0xc] = 0;
}

#pragma thumb off
