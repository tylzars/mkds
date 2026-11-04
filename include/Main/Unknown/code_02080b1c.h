#pragma once

#include "types.h"

// Object at 0x20 of an Unk02080b1c_00: halfwords at 0x02, 0x04 and 0x06.
typedef struct Unk02080b1c_20 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk02080b1c_20;

// Entries reached through Unk02080b1c: a table of pointers to further entries at 0x00 (the count is the halfword at
// 0x24), a vector pointer at 0x18, a word at 0x1c and an Unk02080b1c_20 pointer at 0x20.
typedef struct Unk02080b1c_00 {
    /* 00 */ struct Unk02080b1c_00 *mUnk_00[6];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ Unk02080b1c_20 *mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26[2];
} Unk02080b1c_00;

// Current entry at 0x00, previous entry at 0x04, a vector at 0x08, the halfword at 0x1c given to GetKart and a
// byte at 0x1e.
typedef struct Unk02080b1c {
    /* 00 */ Unk02080b1c_00 *mUnk_00;
    /* 04 */ Unk02080b1c_00 *mUnk_04;
    /* 08 */ Vec3 mUnk_08;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u8 mUnk_1e;
} Unk02080b1c;

// Object of 0x2a bytes: an Unk02080b1c at 0x00, a word at 0x20, the halfword at 0x24 given to GetKart and
// halfwords at 0x26 and 0x28.
typedef struct Unk020905a8 {
    /* 00 */ Unk02080b1c mUnk_00;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ s16 mUnk_26;
    /* 28 */ s16 mUnk_28;
} Unk020905a8;

void func_02080b1c(Unk02080b1c *p);
s32 func_02080bf4(Unk02080b1c *p, Vec3 *a);
s32 func_02080c64(Unk02080b1c *p, Vec3 *a);
