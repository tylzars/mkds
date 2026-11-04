#include "Main/Unknown/code_0200ba44.h"

#pragma thumb on

void func_0200ba44(u32 a, u32 b) {
    u32 v1;
    v1 = IrqDisable();
    data_0216fde8->mUnk_5f0e = a;
    IrqRestore(v1);
    if (data_0216fde8->mUnk_05e0 != NULL) {
        data_0216fde8->mUnk_05e0(a, (void *) b);
    }
}

#pragma thumb off
