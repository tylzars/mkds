#pragma once

#include "types.h"

typedef struct Unk02197fe8 Unk02197fe8;

typedef struct Unk0219981cEntry {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
} Unk0219981cEntry;

u32 func_ov000_0219981c(Unk02197fe8 *a);
void func_ov000_02199878(Unk02197fe8 *a, Unk0219981cEntry *b, s32 c);
u32 func_ov000_021998d8(Unk02197fe8 *a, s32 b, u32 c, const u8 *d, s32 e, s32 *f);
