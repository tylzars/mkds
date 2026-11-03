#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207ffa4.h"
#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/code_02080cd0.h"

// Entry of the list func_020888b4 searches: a halfword at 0x02 (bit 0 tested) and a vector at 0x04.
typedef struct Unk020888b4_d0 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mFlags;
    /* 04 */ Vec3 mPos;
} Unk020888b4_d0;

// Object of 0x34 bytes at 0xe8 of the object Unk020888b4 starts: func_02089a24 writes the words at 0x28 and 0x2c and
// the halfword at 0x30.
typedef struct Unk02089a24 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[2];
} Unk02089a24;

// Object at 0x140 of the object Unk020888b4 starts: func_02089c3c and func_02089b4c write the words at 0x04, 0x0c and
// 0x10.
typedef struct Unk02089b4c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk02089b4c;

// Object of 0x158 bytes (func_020888b4 to func_02089a24 take it first): the Unk0206bcb0 it follows at 0x00, a
// Unk0208001c at 0x28, vectors at 0x44, 0x50, 0x60 and 0xdc, a Unk02089a24 at 0xe8, a Unk0208fd8c at 0x11c, a
// Unk02089b4c at 0x140 and a word at 0x154.
typedef struct Unk020888b4 {
    /* 00 */ Unk0206bcb0 *mUnk_00;
    /* 04 */ u16 mIndex;
    /* 06 */ u16 mUnk_06;
    /* 08 */ Unk02080d34 mUnk_08;
    /* 28 */ Unk0208001c mUnk_28;
    /* 44 */ Vec3 mUnk_44;
    /* 50 */ Vec3 mUnk_50;
    /* 5c */ Vec3 *mUnk_5c;
    /* 60 */ Vec3 mUnk_60;
    /* 6c */ u16 mUnk_6c;
    /* 6e */ u16 mUnk_6e;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ u16 mUnk_78;
    /* 7a */ u16 mUnk_7a;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ u16 mUnk_80;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ s32 mUnk_84;
    /* 88 */ s32 mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mUnk_94;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mUnk_9c;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s16 mUnk_ac;
    /* ae */ u8 mUnk_ae[2];
    /* b0 */ Unk0206bcb0 *mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ s16 mUnk_c0;
    /* c2 */ s16 mUnk_c2;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ u16 mUnk_c8;
    /* ca */ u16 mUnk_ca;
    /* cc */ s32 mUnk_cc;
    /* d0 */ Unk020888b4_d0 *mUnk_d0;
    /* d4 */ s16 mEntrySearchStartIndex;
    /* d6 */ u8 mUnk_d6[2];
    /* d8 */ s32 mUnk_d8;
    /* dc */ Vec3 mUnk_dc;
    /* e8 */ Unk02089a24 mUnk_e8;
    /* 11c */ Unk0208fd8c mUnk_11c;
    /* 140 */ Unk02089b4c mUnk_140;
    /* 154 */ s32 mUnk_154;
} Unk020888b4;

void func_02089c3c(Unk02089b4c *a, Unk020888b4 *b);
void func_02089b4c(Unk02089b4c *a, Unk020888b4 *b, s32 c);
void func_02089a24(Unk020888b4 *a, Unk02089a24 *b);
void func_02089974(void);
void func_020898bc(Unk020888b4 *p);
void func_02089788(Unk020888b4 *p, Unk0206bcb0 *q);
void func_02089754(Unk020888b4 *p, Unk02175620_bc *a);
void func_020896e0(Unk020888b4 *p);
void func_02089494(Unk020888b4 *p);
void func_020892bc(Unk020888b4 *p);
void func_02088e44(Unk020888b4 *p);
void func_02088d34(Unk020888b4 *p);
void func_02088c7c(Unk020888b4 *p);
void func_02088a0c(Unk020888b4 *p);
BOOL func_020888b4(Unk020888b4 *p, s32 a, s32 b);
