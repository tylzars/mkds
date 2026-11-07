#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f1d70.h"

// Element of gItemPools[2], [3], [7], [8] and [9] up to 0x130: the word at 0x12c that func_020f2df0,
// func_020f30ec and func_020f3150 use after the shared part.
typedef struct Unk020f2df0 {
    /* 000 */ ItemObject mUnk_000;
    /* 12c */ s32 mUnk_12c;
} Unk020f2df0;

void func_020f2dac(ItemObject *a, Vec3 *b, Vec3 *c);
void func_020f2df0(Unk020f2df0 *a, s32 b, s32 c, s32 d, u32 *e);
void func_020f30ec(Unk020f2df0 *a, s32 b, Vec3 *c);
void func_020f3150(Unk020f2df0 *p, ItemInUse *a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_020f357c(void);
