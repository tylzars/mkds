#pragma once

#include "types.h"
#include "03/code_021d1d88.h"

typedef struct Unk021d309c {
    /* 00 */ struct Unk021d309c *mUnk_00;
    /* 04 */ struct Unk021d309c *mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk021d309c;

typedef struct Unk021d31b0 {
    /* 000 */ u8 mUnk_000[0x180];
    /* 180 */ Unk021d309c mUnk_180;
    /* 18c */ Unk021d309c mUnk_18c;
    /* 198 */ void *mUnk_198;
    /* 19c */ Unk021d1d88 *mUnk_19c;
} Unk021d31b0;

typedef struct Unk021d2fa0 {
    /* 000 */ u8 mUnk_000[2][0x400];
    /* 800 */ Unk021d1d88 *mUnk_800[2];
    /* 808 */ u32 mUnk_808;
} Unk021d2fa0;

void func_ov003_021d2fa0(void);
void func_ov003_021d2fdc(void);
void func_ov003_021d305c(u32 c);
Unk021d309c *func_ov003_021d309c(u32 a, s32 b, s32 c, u32 *d);
void func_ov003_021d31b0(void);
