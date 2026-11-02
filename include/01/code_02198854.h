#pragma once

#include "types.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02125de0.h"

// An s16 pair of Unk021a9be8.
typedef struct Unk021a9be8Pair {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk021a9be8Pair;

// Object behind data_ov001_021a9be8.
typedef struct Unk021a9be8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c[2];
    /* 14 */ s32 mUnk_14[2];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s16 mUnk_24;
    /* 26 */ Unk021a9be8Pair mUnk_26[3];
    /* 32 */ u8 mUnk_32[2];
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40[2][2];
    /* 50 */ void *mUnk_50;
    /* 54 */ Unk02124b1c *mUnk_54;
    /* 58 */ Unk02124b1c *mUnk_58;
    /* 5c */ struct Unk02021dc8 *mUnk_5c;
    /* 60 */ struct Unk02021dc8 *mUnk_60;
    /* 64 */ Unk020b4934 *mUnk_64;
    /* 68 */ Unk020b4934 *mUnk_68;
    /* 6c */ Unk020b4a44 *mUnk_6c;
    /* 70 */ Unk020b4a44 *mUnk_70;
    /* 74 */ Unk0201ea30 *mUnk_74;
    /* 78 */ Unk0201ea30 *mUnk_78;
    /* 7c */ void *mUnk_7c;
    /* 80 */ void *mUnk_80;
    /* 84 */ void *mUnk_84;
    /* 88 */ void *mUnk_88;
    /* 8c */ void *mUnk_8c;
} Unk021a9be8;

// Object behind data_0217aa08; the byte at 0x31 of the object at its first member holds flags.
extern Unk021a9be8 *data_ov001_021a9be8;
extern u8 data_ov001_021a6a20[];
extern u8 data_ov001_021a6a24[];
extern u8 data_ov001_021a6a2c[];
extern u8 data_ov001_021a6a30[];
extern u8 data_ov001_021a6a34[];
extern u8 data_ov001_021a6a38[][3];
extern s32 data_ov001_021a6a44[];
extern u8 data_ov001_021a6a50[][3][2];
extern u8 data_ov001_021a6a5c[][12];

void func_ov001_02198854(void);
void func_ov001_02198878(void);
void func_ov001_02198918(void);
void func_ov001_021989bc(void);
void func_ov001_02198a6c(void);
void func_ov001_02198b58(void);
void func_ov001_02198bbc(void);
void func_ov001_02198d20(void);
void func_ov001_02198d8c(void);
void func_ov001_02198e94(void);
void func_ov001_02198ec0(void);
void func_ov001_021992a0(void);
void func_ov001_021992dc(void);
void func_ov001_02199374(void);
void func_ov001_021993b8(void);
void func_ov001_02199420(void);
void func_ov001_02199464(void);
void func_ov001_021995f8(void);
void func_ov001_02199640(void *a);
void func_ov001_021997dc(void);
