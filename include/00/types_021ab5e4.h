#pragma once

#include "types.h"

// Entry of the four-entry table at data_ov000_021b61f4.
typedef struct HttpsEntry {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u8 mUnk_20[0x30];
    /* 50 */ u32 mLastUseTime;
    /* 54 */ u32 mUnk_54;
    /* 58 */ u16 mUnk_58;
    /* 5a */ u8 mInUse;
    /* 5b */ u8 mUnk_5b;
} HttpsEntry;
