#pragma once

#include "types.h"

typedef struct Unk021da194 {
    /* 00000 */ u8 pad_00000[0x1e280];
    /* 1e280 */ u8 mUnk_1e280[0x18];
    /* 1e298 */ void (*mUnk_1e298)(s32 a);
    /* 1e29c */ u32 mUnk_1e29c;
    /* 1e2a0 */ u8 mUnk_1e2a0;
    /* 1e2a1 */ u8 mUnk_1e2a1;
} Unk021da194;

typedef struct Unk021d6e24 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u8 pad_0c[0xc];
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 pad_19[3];
} Unk021d6e24;

#include "03/unk_021da000.h"

extern Unk021d6e24 data_ov003_021d6e24;
extern Unk021da194 *data_ov003_021da194;

void func_ov003_021c25e0(u32 a);
u8 *func_ov003_021c27b4(void);
u32 func_ov003_021c27c8(void);
void func_ov003_021c27d0(void *a);
u32 func_ov003_021c27e4(void);
void func_ov003_021c27f8(u32 a);
void func_ov003_021c2824(void);
void func_ov003_021c2840(u32 a);
// Not decompiled yet.
// Not decompiled yet.
