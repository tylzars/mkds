#include "Main/Unknown/code_021296b4.h"

#pragma thumb on

void func_021296b4(void) {
    s32 i;
    u8 n;
    i = 0;
    data_0217d400->mUnk_1c[0] = 0;
    for (; i < func_020ab748(); i++) {
        if (func_020ab798()[i] != 0x20 && func_020ab798()[i] != 0x3000) {
            data_0217d400->mUnk_1c[0] = 1;
        }
    }
    n = data_0215d0e0[1];
    if (n - 1 == func_020ab748()) {
        if ((func_020ab798() + n)[-1] != 0x20 && (func_020ab798() + n)[-1] != 0x3000 &&
            (func_020ab798() + n)[-1] != 0) {
            data_0217d400->mUnk_1c[0] = 1;
        }
    }
    if (func_020ab8c4() == 1) {
        data_0217d400->mUnk_14[0] = 1;
    } else {
        data_0217d400->mUnk_14[0] = 0;
    }
    if (func_020ab8c4() == 2) {
        data_0217d400->mUnk_14[1] = 1;
        return;
    }
    data_0217d400->mUnk_14[1] = 0;
}

#pragma thumb off
