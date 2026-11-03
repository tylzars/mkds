#pragma once

#include "types.h"
#include "03/unk_021d8000.h"

// Eight bytes passed by address.
typedef struct Unk021bdcd8 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk021bdcd8;

// Table of 0x30-byte records, mUnk_00 counts them.
typedef struct Unk021bdd3c_Entry {
    /* 00 */ u32 mUnk_00;
    /* 04 */ char mUnk_04[0x20];
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ Unk021d8c54 mUnk_28;
    /* 2e */ u16 mUnk_2e;
} Unk021bdd3c_Entry;

typedef struct Unk021bdd3c {
    /* 0 */ u32 mUnk_00;
    /* 4 */ Unk021bdd3c_Entry mUnk_04[1];
} Unk021bdd3c;

s32 func_ov003_021bdcd8(s32 descriptor, const void *data, u32 size);
s32 func_ov003_021bdd1c(s32 descriptor, const Unk021bdcd8 *address, const u8 *param_2, const void *data, u32 size);
s32 func_ov003_021bdd3c(void);
s32 func_ov003_021be028(Unk021bdd3c *a, Unk021bdd3c *b, u32 *c);
void func_ov003_021be1fc(void);
