#pragma once

#include "types.h"
#include "01/code_021a5140.h"
#include "01/code_021a59cc.h"
#include "01/code_02188950.h" // Unk02188950

// Data that func_ov001_021852f8 gets for the name it is given.
typedef struct Unk021852f8_02 {
    /* 0 */ u16 mUnk_00;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u16 mUnk_04;
    /* 6 */ u16 mUnk_06;
} Unk021852f8_02;

typedef struct Unk021852f8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ Unk021852f8_02 mUnk_02[1];
} Unk021852f8;

// Group of 0x20 bytes at Unk0218516c::mUnk_000.
typedef struct Unk0218516c_000 {
    /* 00 */ u8 mUnk_00[0x6];
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x6];
    /* 0e */ s16 mUnk_0e;
    /* 10 */ u8 mUnk_10[0x6];
    /* 16 */ s16 mUnk_16;
    /* 18 */ u8 mUnk_18[0x6];
    /* 1e */ s16 mUnk_1e;
} Unk0218516c_000;

// Argument of func_ov001_0218516c.
typedef struct Unk0218516c {
    /* 000 */ u8 mUnk_000[0x400];
    /* 400 */ u16 mUnk_400;
    /* 402 */ u16 mUnk_402;
} Unk0218516c;

void func_ov001_02184f7c(Unk02188950 *param_1);
void func_ov001_02184f8c(Unk02188950 *param_1);
void func_ov001_02184f9c(Unk021a5a58 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
s32 func_ov001_02184fb0(Unk021a5a58 *param_1);
void func_ov001_02184fb4(Unk021a5a58 *param_1, s32 param_2);
s32 func_ov001_02184fb8(Unk021a5a58 *param_1);
s32 func_ov001_02184fc8(Unk021a5a58 *param_1);
void func_ov001_02184fd8(Unk021a5a58 *param_1, s32 param_2, s32 param_3);
s32 func_ov001_02184ff8(Unk021a5a58 *param_1);
void func_ov001_02185018(Unk021a5a58 *param_1, s32 param_2);
void func_ov001_021850a4(Unk021a5a58 *param_1, s32 (*param_2)(Unk021a5a58 *));
s32 func_ov001_021850b4(Unk021ca41c_085c *param_1, s32 param_2, s32 param_3, s32 param_4);
Unk021a5a58 *func_ov001_02185160(Unk021ca41c_085c *param_1, s32 param_2);
void func_ov001_0218516c(Unk021ca41c_085c *param_1, Unk0218516c *param_2);
Unk021ca41c_085c *func_ov001_021852f8(const char *param_1, void *param_2, void *param_3);

#include "01/code_021a6430.h"
