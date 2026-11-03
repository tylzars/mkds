#pragma once

#include "types.h"

typedef struct Unk021cca74 {
    /* 00 */ struct Unk021d1770 *mResource;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u16 mX;
    /* 12 */ u16 mY;
    /* 14 */ u16 mUnk_14[2];
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
    /* 1a */ u8 mOffset;
    /* 1b */ u8 mUnk_1b;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
} Unk021cca74;

void func_ov003_021cca74(s32 offset);
void func_ov003_021cca9c(s32 a, u16 *b);
int func_ov003_021ccb1c(int a);
int func_ov003_021ccb50(void);
void func_ov003_021ccbbc(void);
void func_ov003_021ccc08(int a);
