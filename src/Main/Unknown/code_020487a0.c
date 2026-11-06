#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_020487e0(const void *a, void *b, u32 c) {
    MI_UncompressLZ8(a, b);
    DC_StoreRange(b, c);
}

void func_020487a0(int a) {
    Unk021759c8_9b0 *v1;
    v1 = &data_021759c8->mUnk_9b0[a];
    v1->mUnk_00 = NULL;
    v1->mUnk_08 = v1->mUnk_08 & (0xe0000000u);
    v1->mUnk_08 = v1->mUnk_08 | (0x20000000u);
    v1->mUnk_08 = v1->mUnk_08 & (0xbfffffffu);
}

#pragma thumb off
