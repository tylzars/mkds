#include "Main/Unknown/code_0202b6a0.h"

#pragma thumb on

void func_0202b6a0(int param_1, int param_2) {
    u32 v1;
    if ((data_02174e3c->mUnk_204 != 0) && (param_2 != data_02174e3c->mUnk_04c[param_1].mUnk_00)) {
        if (param_2 == 1) {
            v1 = 2;
        } else {
            v1 = 1;
        }
        func_0202cc18(param_1, (int) v1);
    }
    data_02174e3c->mUnk_04c[param_1].mUnk_00 = param_2;
}

#pragma thumb off
