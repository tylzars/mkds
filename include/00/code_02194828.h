#pragma once

#include "types.h"

typedef struct Unk02194828 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 *mValue;
} Unk02194828;

typedef struct GpiProfileSearch {
    /* 00 */ u32 mKey;
    /* 04 */ Unk02194828 *mEntry;
} GpiProfileSearch;

BOOL func_ov000_02194828(void *unused, Unk02194828 *entry, GpiProfileSearch *search);
