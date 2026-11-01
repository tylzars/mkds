#include "Main/Unknown/code_020487a0.h"

#pragma thumb on

void func_020487e0(const void *param_1, void *param_2, u32 param_3) {
    func_0214d344(param_1, param_2);
    func_0200ee58(param_2, param_3);
}

void func_020487a0(int param_1) {
    Unk021759c8_9b0 *v1;
    v1 = &data_021759c8->mUnk_9b0[param_1];
    v1->mUnk_00 = 0;
    v1->mUnk_08 = v1->mUnk_08 & ((u32) 0xe0000000u);
    v1->mUnk_08 = v1->mUnk_08 | ((u32) 0x20000000u);
    v1->mUnk_08 = v1->mUnk_08 & ((u32) 0xbfffffffu);
}

#pragma thumb off
