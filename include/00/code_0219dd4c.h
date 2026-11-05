#pragma once

#include "types.h"

// 0x14 bytes at the start of each record func_ov000_0219dd4c walks.
typedef struct Unk0219dd4c {
    /* 00 */ char mUnk_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
} Unk0219dd4c;

void func_ov000_0219dd4c(const void *a, u32 b);
void func_ov000_0219ddbc(u32 a);
u32 func_ov000_0219edb0(u32 a, u32 b);
void func_ov000_021a1430(void);
void func_ov000_021a1a38(s32 a, s32 b);
