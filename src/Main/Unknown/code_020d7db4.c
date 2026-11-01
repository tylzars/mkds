#include "Main/Unknown/code_020d7db4.h"

#pragma thumb on

void func_020d7db4(Unk020e0144 *param_1, u16 param_2, int param_3) {
    param_1->mUnk_08 = param_2;
    func_020d7e44((u32) param_1->mUnk_08, (int) &data_02175620->mUnk_08[param_1->mUnk_08]);
    param_1->mUnk_00 = &data_0217b670[param_1->mUnk_08];
    param_1->mUnk_04 = param_3;
    func_020d90a8(param_1, 0, 1);
}

#pragma thumb off
