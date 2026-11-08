#pragma once

#include "types.h"

struct RomArchiveFileNode;

// Object behind data_02179ec0: the list head at 0xb04 is the word at 0x46c4 of data_usa_021762e0.
typedef struct Unk02179ec0 {
    /* 000 */ u8 mUnk_000[0xb04];
    /* b04 */ struct RomArchiveFileNode *mUnk_b04;
    /* b08 */ u8 mUnk_b08[8];
    /* b10 */ u32 mUnk_b10;
} Unk02179ec0;

extern Unk02179ec0 data_02179ec0;
