#pragma once

#include "types.h"
#include "03/code_021b94b8.h"
#include "03/code_021b8748.h"

typedef struct Unk021b8c8c {
    /* 00 */ u8 pad_00[6];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 pad_08[2];
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ Unk021b916c mUnk_10;
    /* 18 */ u8 mUnk_18[1];
} Unk021b8c8c;

extern Unk021b8758 data_ov003_021d836c[2];
extern u8 data_ov003_021d7cec[];

s32 func_ov003_021b8b18(Unk021b8760 *a, u8 *b);
s32 func_ov003_021b8bf0(Unk021b916c *a, Unk021b916c *b);
s32 func_ov003_021b8c44(s32 a, const u8 *b);
s32 func_ov003_021b8c8c(Unk021b8c8c *a);
s32 func_ov003_021b8d9c(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
s32 func_ov003_021b8e60(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
s32 func_ov003_021b8f68(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
