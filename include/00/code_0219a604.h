#pragma once

#include "types.h"

typedef struct Unk0219a604Value {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0219a604Value;

typedef struct Gt2ConnectionEntry {
    /* 00 */ Unk0219a604Value *mValue;
} Gt2ConnectionEntry;

u32 func_ov000_0219a604(const Gt2ConnectionEntry *object, u32 modulus);
