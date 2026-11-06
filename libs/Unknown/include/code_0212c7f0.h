#pragma once

#include "types.h"
#include "code_02003024.h" // FSFile
#include "code_0212f788.h" // Interpolator
#include "code_0214f4a4.h" // PMSleepCallbackInfo

// 0x160 bytes; data_0217e404 holds four. Flags word at 0x24: bit 0 and bit 1 are tested and cleared or set by
// func_0212c824, func_0212c918 and func_0212c948. mUnk_4c holds mUnk_48 bytes. Bits of mUnk_110: 0 is tested by
// func_0212ef48, func_0212efb8 and func_0212f094, 1 by func_0212efb8 and func_0212f094, 2 and 3 by func_0212f094.
typedef struct Unk0212c7f0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ PMSleepCallbackInfo mUnk_08;
    /* 14 */ PMSleepCallbackInfo mUnk_14;
    /* 20 */ u8 mUnk_20[4];
    /* 24 */ s32 mUnk_24_0 : 1;
    /* 24 */ s32 mUnk_24_1 : 1;
    /* 24 */ s32 mUnk_24_2 : 30;
    /* 28 */ u8 mUnk_28[0x14];
    /* 3c */ s32 mUnk_3c;
    /* 40 */ u32 mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ u8 mUnk_4c[0x10];
    /* 5c */ FSFile mUnk_5c;
    /* a4 */ u8 mUnk_a4[0x44];
    /* e8 */ Interpolator mUnk_e8;
    /* f8 */ u8 mUnk_f8[0x18];
    /* 110 */ s32 mUnk_110_0 : 1;
    /* 110 */ s32 mUnk_110_1 : 1;
    /* 110 */ s32 mUnk_110_2 : 1;
    /* 110 */ s32 mUnk_110_3 : 1;
    /* 110 */ s32 mUnk_110_4 : 28;
    /* 114 */ s32 mUnk_114;
    /* 118 */ s32 mUnk_118;
    /* 11c */ u8 mUnk_11c[4];
    /* 120 */ s32 mUnk_120;
    /* 124 */ u8 mUnk_124[0x28];
    /* 14c */ u32 *mUnk_14c;
    /* 150 */ u8 mUnk_150[4];
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ u8 mUnk_15c[4];
} Unk0212c7f0;

// 8 bytes; func_0212c8a4 reads mUnk_04 of the element a byte of mUnk_4c selects in data_0217dd28.
typedef struct Unk0212c8a4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0212c8a4;

void func_0212c7f0(Unk0212c7f0 *p);
void func_0212c824(Unk0212c7f0 *p);
void func_0212c8a4(Unk0212c7f0 *p, s32 a);
void func_0212c918(Unk0212c7f0 *p);
void func_0212c948(Unk0212c7f0 *p);
void func_0212c9a4(Unk0212c7f0 *p);
