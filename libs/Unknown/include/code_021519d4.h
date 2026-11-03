#pragma once

#include "types.h"

typedef struct Unk021510a4 Unk021510a4;

// Output of func_02151ddc: the first two fields of Unk021510a4, a flag and a word.
typedef struct Unk02151ddc {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk02151ddc;

extern const u8 data_usa_0216172c[];

void func_021519d4(u8 *a, u32 b);
s32 func_02151a00(u8 *a);
u32 func_02151a64(const u8 *a);
s32 func_02151b38(u8 *a);
u32 func_02151da8(void);
void func_02151ddc(Unk02151ddc *a);
u32 func_02151e20(Unk021510a4 *a);
u32 func_02151f48(Unk021510a4 *a, u8 *b);
