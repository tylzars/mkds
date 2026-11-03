#include "Main/Unknown/code_0200589c.h"
#include "Main/Unknown/code_0200635c.h"

#pragma thumb on

void func_0200635c(Unk0200628c *a, u32 b) {
    a->mUnk_10 = a->mUnk_10 + 1;
    a->mUnk_0c = b;
    a->mUnk_14[(s32) b >> 5] = a->mUnk_14[(s32) b >> 5] | 1 << (b & 0x1f);
}

#pragma thumb off
