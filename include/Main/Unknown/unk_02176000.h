#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_02003024.h"

// Objects whose layout isn't known yet.
extern Unk02175ec0_440s data_usa_021762e0;

// Object the word at 0x46c8 of Unk021762e0 points to: an Unk02003024 at 0x38, a state word at 0x80, words at 0x8c to
// 0xa4 and two 0x400-byte buffers from 0xc0 (mUnk_a4[i] is the offset of buffer i).
typedef struct Unk021762e0_46c8 {
    /* 000 */ u8 mUnk_00[0x38];
    /* 038 */ Unk02003024 mUnk_38;
    /* 080 */ s32 mUnk_80;
    /* 084 */ u8 mUnk_84[8];
    /* 08c */ u32 mUnk_8c;
    /* 090 */ u32 mUnk_90;
    /* 094 */ u32 mUnk_94;
    /* 098 */ s32 mUnk_98;
    /* 09c */ s32 mUnk_9c;
    /* 0a0 */ s32 mUnk_a0;
    /* 0a4 */ s32 mUnk_a4[2];
    /* 0ac */ u8 mUnk_ac[0x14];
    /* 0c0 */ u8 mUnk_c0[2][0x400];
} Unk021762e0_46c8;

// Object at data_usa_021762e0; the word at 0x46c8 is a pointer, the bytes at 0x340 and the halfword at 0x4c4 are used
// by func_0204be0c.
typedef struct Unk021762e0 {
    /* 0000 */ u8 mUnk_0000[0x340];
    /* 0340 */ u8 mUnk_0340[0x184];
    /* 04c4 */ u16 mUnk_04c4;
    /* 04c6 */ u8 mUnk_04c6[0x4202];
    /* 46c8 */ Unk021762e0_46c8 *mUnk_46c8;
} Unk021762e0;

// The part of Unk021762e0 from 0x4000.
typedef struct Unk021762e0_4000 {
    /* 000 */ u8 mUnk_000[0x6c8];
    /* 6c8 */ Unk021762e0_46c8 *mUnk_6c8;
} Unk021762e0_4000;
