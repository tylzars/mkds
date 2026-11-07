#pragma once

#include "types.h"

// Halfword at 0x00 and the halfword at 0x02 derived from it by UpdateTimedQuad, word at 0x08.
typedef struct Unk02089e68 {
    /* 00 */ s16 mTimer;
    /* 02 */ s16 mUnk_02;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ s32 mEnabled;
} Unk02089e68;

void UpdateTimedQuad(Unk02089e68 *a);
void WriteQuadVertex(int a);
