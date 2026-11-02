#include "Main/Unknown/code_020487a0.h"

#pragma thumb on

void func_020487e0(const void *a, void *b, u32 c) {
    func_0214d344(a, b);
    func_0200ee58(b, c);
}

void func_020487a0(int a) {
    Unk021759c8_9b0 *v1;
    v1 = &data_021759c8->mUnk_9b0[a];
    v1->mUnk_00 = 0;
    v1->mUnk_08 = v1->mUnk_08 & ((u32) 0xe0000000u);
    v1->mUnk_08 = v1->mUnk_08 | ((u32) 0x20000000u);
    v1->mUnk_08 = v1->mUnk_08 & ((u32) 0xbfffffffu);
}

#pragma thumb off
