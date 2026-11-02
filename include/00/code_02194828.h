#pragma once

#include "types.h"

typedef struct Unk02194828 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 *mValue;
} Unk02194828;

typedef struct Unk02194828Search {
    /* 00 */ u32 mKey;
    /* 04 */ Unk02194828 *mEntry;
} Unk02194828Search;

BOOL func_ov000_02194828(void *unused, Unk02194828 *entry, Unk02194828Search *search);
