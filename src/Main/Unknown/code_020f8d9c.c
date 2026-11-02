#include "Main/Unknown/code_020f8d9c.h"

#pragma thumb on

void func_020f8d9c(int a, u32 b, int c) {
    *(u32 *) (a + 0x48) = b;
    func_020e0650((u32 *) (u32) (a + 0x104));
    func_02109110((Unk0210bfbc *) a, data_0217bc34[c].mUnk_a0, (Vec3 *) (a + 0x50));
    func_02109054((Unk0210bfbc *) a);
}

#pragma thumb off
