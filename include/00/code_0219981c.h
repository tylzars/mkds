#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;

typedef struct Unk0219981cEntry {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
} Unk0219981cEntry;

u32 func_ov000_0219981c(Gt2Connection *a);
void func_ov000_02199878(Gt2Connection *a, Unk0219981cEntry *b, s32 c);
u32 func_ov000_021998d8(Gt2Connection *a, s32 b, u32 c, const u8 *d, s32 e, s32 *f);
