#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h" // Unk020f2df0
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"

struct ModelEffect;

// Object of item kind 9, element of gItemPools[9].
typedef struct ItemBomb {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ struct ModelEffect *mUnk_138;
    /* 13c */ u8 mUnk_13c[0x30];
    /* 16c */ BOOL mUnk_16c;
    /* 170 */ s32 mUnk_170;
    /* 174 */ s32 mUnk_174;
    /* 178 */ u16 mUnk_178;
    /* 17a */ u8 mUnk_17a[2];
    /* 17c */ s32 mUnk_17c;
    /* 180 */ s32 mUnk_180;
    /* 184 */ u8 mUnk_184[4];
    /* 188 */ s32 mStateFrames;
    /* 18c */ u8 mUnk_18c[6];
    /* 192 */ u16 mState;
    /* 194 */ u16 mNextState;
    /* 196 */ u16 mNextStateRequested;
    /* 198 */ Unk021052fc *mUnk_198;
    /* 19c */ s32 mUnk_19c;
    /* 1a0 */ BOOL mUnk_1a0;
} ItemBomb;

void func_020fd83c(ItemBomb *e);
int RequestItemBombState2(ItemBomb *e);
void DrawItemBomb(ItemBomb *e, Vec3 *a, Unk020e6488 *b);
void InitItemBombFromData(ItemBomb *e);
void *func_020fda50(void *a, ItemBomb *b, void *c);
void AdvanceItemBomb(ItemBomb *e);
void func_020fdc08(ItemBomb *e, ItemBomb *b, Unk021052fc *c);
void func_020fdd78(ItemBomb *e);
void func_020fde18(ItemBomb *e);
void UpdateItemBombState2(ItemBomb *e);
void EnterItemBombState2(ItemBomb *e);
void UpdateItemBombState1(ItemBomb *e);
