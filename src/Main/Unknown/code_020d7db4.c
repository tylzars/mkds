#include "Main/Unknown/code_020d7db4.h"

#pragma thumb on

void func_020d7db4(Unk020e0144 *a, u16 b, int c) {
    a->mUnk_08 = b;
    func_020d7e44((u32) a->mUnk_08, (int) &data_02175620->mUnk_08[a->mUnk_08]);
    a->mUnk_00 = &data_0217b670[a->mUnk_08];
    a->mUnk_04 = c;
    func_020d90a8(a, 0, 1);
}

#pragma thumb off
