#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"

// Element of gItemPools[1] and [5] up to 0x228: after the Unk020f1d70 part, the Unk020f371c_Ref at 0x168 that
// func_020f371c fills, the Unk020f3fa8 at 0x170, the words at 0x214 and 0x218 and the Unk020f371c_Ref at 0x21c.
typedef struct Unk020ec8bc {
    /* 000 */ Unk020f1d70 mUnk_000;
    /* 168 */ Unk020f371c_Ref mUnk_168;
    /* 170 */ Unk020f3fa8 mUnk_170;
    /* 214 */ s32 mUnk_214;
    /* 218 */ s32 mUnk_218;
    /* 21c */ Unk020f371c_Ref mUnk_21c;
    /* 224 */ s32 mUnk_224;
} Unk020ec8bc;

// One element of the table behind gItemKinds from its first byte: the
// pointer at 0x14.
typedef struct {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ void (*mUnk_14)(void);
} Unk0217bc34_14;

void func_020ec8bc(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, s32 g);
void func_020ec918(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 d);
void func_020ec9c0(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 e);
void func_020ece1c(Unk020ec8bc *p, s32 a, s32 b, s32 c);
BOOL func_020ed0f4(Unk020ec8bc *p);
void func_020ed268(Unk020ec8bc *p, ItemInUse *q, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, u16 g, s32 h);
void CreateItemModels(void);
void *func_020ed490(u8 *a, u8 *b);
Unk020e6488 *func_020ed4d0(u8 *a, u8 *b, u8 *c);
void *func_020ed548(u8 *a);
