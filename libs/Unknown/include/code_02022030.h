#pragma once

#include "types.h"
#include "code_02021db0.h" // Unk02021dc8, Unk02021e40

// 0x1c bytes: func_02022438 clears everything after the first word and sets mUnk_04 and mUnk_08 to 0x1000.
// func_02022484, func_020224a4 and func_020224c0 set a member and a bit of mUnk_12 when mUnk_00 is 1.
typedef struct Unk02022438 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[8];
} Unk02022438;

typedef struct Unk02022030 {
    /* 00 */ Unk02021e40 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ Unk02021dc8 *mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ UnkFunc *mUnk_24;
    /* 28 */ u16 mUnk_28;
    /* 2c */ Unk02021e40 *mUnk_2c;
    /* 30 */ Unk02021dc8 *mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ Unk02022438 mUnk_38;
} Unk02022030;

// Seen through mUnk_00 of the element func_0202212c steps over: a word, then a halfword.
typedef struct Unk02022188 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk02022188;

// Record at the first word of the element: func_0202294c reads these members, except when the low byte of
// mUnk_04 of the header is 2 (then Unk020229b4).
typedef struct Unk020229c8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
} Unk020229c8;

typedef struct Unk020229b4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk020229b4;

typedef struct Unk020224e0_s {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
} Unk020224e0_s;

typedef struct Unk020224e0_o {
    /* 00 */ u16 mUnk_00[4];
} Unk020224e0_o;

typedef struct Unk020224e0_c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Unk020224e0_s *mUnk_04;
} Unk020224e0_c;

void func_02022030(Unk02022030 *a, Unk02021dc8 *b);
void func_02022040(Unk02022030 *a);
