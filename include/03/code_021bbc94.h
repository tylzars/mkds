#pragma once

#include "types.h"

typedef struct Unk021bbd70 {
    /* 00 */ u32 mUnk_00[4];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x40];
} Unk021bbd70;

#include "03/unk_021d3000.h"

extern u8 data_ov003_021d68dc[];

void func_ov003_021bbc94(u8 *a, Unk021bbd70 *b);
void func_ov003_021bbcf0(Unk021bbd70 *a, const u8 *b, u32 c);
void func_ov003_021bbd70(Unk021bbd70 *a);
void func_ov003_021bbd9c(u32 *param_1, int param_2, u8 *param_3, u8 *param_4);
void func_ov003_021bc1c4(u32 *param_1, int param_2, u8 *param_3, u8 *param_4);
int func_ov003_021bc5e4(u32 *param_1, u8 *param_2, int param_3);
int func_ov003_021bc7a8(u32 *param_1, u8 *param_2, int param_3);
void func_ov003_021bca90(u8 *param_1, u8 *param_2, u8 *param_3);
