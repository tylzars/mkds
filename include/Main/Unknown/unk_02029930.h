#pragma once

#include "types.h"

// 0x2c-byte rows of the table at member 0xf8 of Unk02029930.
typedef struct Unk02029930_f8 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mMissionTableValue;
    /* 07 */ u8 mUnk_07[0x1];
    /* 08 */ u8 mCourseId;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mCharacterIndex0;
    /* 0b */ u8 mKartIndex0;
    /* 0c */ u8 mUnk_0c[0x10];
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u8 mCharacterIndex1;
    /* 1f */ u8 mKartIndex1;
    /* 20 */ u8 mMissionRunStem[0xc];
} Unk02029930_f8;
