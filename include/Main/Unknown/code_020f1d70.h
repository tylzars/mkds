#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ed5c0.h"

typedef struct Unk020eda5c Unk020eda5c;
typedef struct ItemKouraR ItemKouraR;

// Element of gItemPools[0], [1] and [5] up to 0x168: the word and the three vectors from 0x12c and the words
// and halfword from 0x154 that the functions of this file read after the shared part.
typedef struct Unk020f1d70 {
    /* 000 */ ItemObject mUnk_000;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ Vec3 mUnk_130;
    /* 13c */ Vec3 mUnk_13c;
    /* 148 */ Vec3 mUnk_148;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ BOOL mUnk_15c;
    /* 160 */ BOOL mUnk_160;
    /* 164 */ u16 mUnk_164;
    /* 166 */ u8 mUnk_166[2];
} Unk020f1d70;

void func_020f1d70(void *a0, const Vec3 *b);
void func_020f1ea4(void *a0, s32 b, s32 c, s32 d);
void func_020f1f98(Unk020f1d70 *a, Vec3 *b, Vec3 *c);
void func_020f2028(ItemObject *a);
void func_020f2150(void *a0);
void func_020f2228(Unk020f1d70 *a, s32 b);
void func_020f2768(Unk020f1d70 *a, Vec3 *b, Vec3 *c);
void func_020f288c(Unk020f1d70 *a, Vec3 *b);
void func_020f29e8(ItemKouraR *a);
void func_020f2a6c(Vec3 *a, Vec3 *b, Vec3 *c);
void func_020f2b94(void *a0, Unk020eda5c *b0, s32 c, s32 d, s32 e, s32 f);
