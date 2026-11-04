#pragma once

#include "types.h"
#include "Main/Unknown/code_020b3f7c.h" // Unk020b3fb0
#include "code_0201ea58.h" // Unk0201ea30
#include "Main/Unknown/code_02124094.h" // Unk02124b1c

// Seven words at 0x24 of Unk02174e50, passed by address to func_02025b20, func_02025a50 and func_02025a00.
typedef struct Unk02174e50_24 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ Unk02124b1c *mUnk_18;
} Unk02174e50_24;

// 12-byte entries at 0x58 of Unk02174e50.
typedef struct Unk02174e50_58 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk02174e50_58;

// 0xa8-byte object that data_02174e50 points to.
typedef struct Unk02174e50 {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ Unk02174e50_24 mUnk_24;
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ Unk02174e50_58 mUnk_58[4];
    /* 88 */ s32 mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mUnk_94;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mUnk_9c;
    /* a0 */ Unk020b3fb0 *mUnk_a0;
    /* a4 */ void *mHeap;
} Unk02174e50;

// Argument of func_0202f764: a halfword at 4.
typedef struct Unk0202f764 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk0202f764;

void func_0202f688(void);
void func_0202f744(void);
s32 func_0202f764(Unk0202f764 *a);
void func_0202fbc8(void *a, void *b, void *c);
void func_0202fd2c(void);
