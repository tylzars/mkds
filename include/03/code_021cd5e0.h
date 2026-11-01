#pragma once

#include "types.h"
#include "03/unk_021da000.h"

// 0xf0 bytes; the object at data_ov003_021da270 holds four of them at a stride of 0x100.
typedef struct Unk021cd5e0_entry {
    /* 00 */ u8 mUnk_00[0x40];
    /* 40 */ u8 mUnk_40[0x20];
    /* 60 */ u8 mUnk_60[0x20];
    /* 80 */ u8 mUnk_80[4][0x10];
    /* c0 */ u8 mUnk_c0[4];
    /* c4 */ u8 mUnk_c4[4];
    /* c8 */ u8 mUnk_c8[8];
    /* d0 */ u8 mUnk_d0;
    /* d1 */ u8 mUnk_d1[0x15];
    /* e6 */ u8 mUnk_e6_0 : 2;
    /* e6 */ u8 mUnk_e6_2 : 6;
    /* e7 */ u8 mUnk_e7;
    /* e8 */ u8 mUnk_e8[8];
} Unk021cd5e0_entry;

// Entry at offset 0x400 of the object at data_ov003_021da270, and the bytes after it.
typedef struct Unk021cd5e0_400 {
    /* 00 */ Unk021cd5e0_entry mUnk_00;
    /* f0 */ u8 mUnk_f0[4];
    /* f4 */ u8 mUnk_f4;
    /* f5 */ u8 mUnk_f5;
    /* f6 */ u8 mUnk_f6;
    /* f7 */ u8 pad_f7;
    /* f8 */ u16 mUnk_f8;
} Unk021cd5e0_400;

// Object at data_ov003_021da270, as far as func_ov003_021cd5e0 through func_ov003_021cd790 use it.
typedef struct Unk021cd5e0 {
    /* 000 */ struct {
        Unk021cd5e0_entry mUnk_00;
        u8 mUnk_f0[0xe];
        u16 mUnk_fe;
    } mUnk_000[4];
    /* 400 */ Unk021cd5e0_400 mUnk_400;
} Unk021cd5e0;

// Argument of func_ov003_021cd5e0.
typedef struct Unk021cd5e0_arg {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u8 mUnk_28[4][0x20];
} Unk021cd5e0_arg;

extern u8 data_ov003_021d6684[];

void func_ov003_021cd5e0(const Unk021cd5e0_arg *a);
void func_ov003_021cd6d0(void);
void func_ov003_021cd790(s32 a);
