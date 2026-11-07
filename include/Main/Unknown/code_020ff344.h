#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h" // Unk020f2df0
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ffc4c.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020ffdd4.h"

// Object of func_020ff97c: 0x144 bytes.
typedef struct Unk020ff97c {
    /* 000 */ MapObject mUnk_00;
    /* 0a0 */ MtxFx33 mUnk_a0;
    /* 0c4 */ u8 mUnk_c4[0x24];
    /* 0e8 */ Vec3 mUnk_e8;
    /* 0f4 */ Vec3 mUnk_f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ s32 mUnk_114;
    /* 118 */ s32 mUnk_118;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120;
    /* 124 */ s32 mUnk_124;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ u8 mUnk_140[4];
} Unk020ff97c;

// Object of item kind 7, element of gItemPools[7].
typedef struct ItemFBox {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ Vec3 mUnk_130;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ Unk021052fc *mUnk_140;
} ItemFBox;

void func_020ff344(ItemFBox *e);
s32 func_020ff3c4(ItemFBox *e);
void AdvanceItemFBox(ItemFBox *e);
u32 InitItemFBox(ItemInUse *a, ItemFBox *e);
void AdvanceItemFBoxInUse(ItemInUse *a, ItemFBox *e);
void StartItemFBox(ItemFBox *e);
void ResetItemFBox(ItemFBox *e);
void func_020ff6d8(ItemFBox *e, MtxFx43 *out);
void func_020ff910(ItemFBox *e, MtxFx43 *out);
void func_020ff97c(Unk020ff97c *e);
BOOL func_020ffabc(u32 a);
Unk02100004 *func_020ffacc(void);
void InitDram(Dram *a, struct CourseMapRow *b);
void CreateDram(void);
