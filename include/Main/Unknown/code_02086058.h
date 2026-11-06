#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

// 0x24-byte entry: the word at 0x00 and the halfword at 0x08 are tested by func_02086098 and func_02086e8c,
// the words at 0x1c and 0x20 are passed to the function given to func_02086098.
typedef struct Unk02086098 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ u32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk02086098;

// Four entries.
typedef struct Unk02086250_1c {
    /* 00 */ Unk02086098 mUnk_00[4];
} Unk02086250_1c;

// Object in the tables of data_0217aed0.
typedef struct Unk02086250 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ BOOL mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ BOOL mUnk_18;
    /* 1c */ Unk02086250_1c *mUnk_1c;
    /* 20 */ s16 mUnk_20;
    /* 22 */ s16 mUnk_22;
    /* 24 */ s16 mUnk_24;
    /* 26 */ u16 mUnk_26;
} Unk02086250;

void func_02086098(Unk02086098 *a, Unk02086250 *b, MtxFx43 *c, s32 d, s32 e, s16 f, s32 g, s32 h, s32 i, s32 j,
                   UnkFunc *k);

u16 *func_02086058(void);
u16 func_0208606c(int a);
int func_02086080(int arg0);
void func_02086250(MtxFx43 *a);
void func_020865ec(void);
void func_020866b4(void);
void func_0208677c(void);
void func_02086a04(void);
