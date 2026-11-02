#pragma once

#include "types.h"

// Values read from the text, as built by func_ov000_02192e04 on its stack. The pointers at 0x00 to 0x14 point to
// buffers of its own; 0x1c, 0x27 and 0x34 are arrays inside.
typedef struct Unk02192e04 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ u8 *mUnk_10;
    /* 14 */ u8 *mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0xb];
    /* 27 */ u8 mUnk_27[3];
    /* 2a */ u8 mUnk_2a[2];
    /* 2c */ float mUnk_2c;
    /* 30 */ float mUnk_30;
    /* 34 */ u8 mUnk_34[0x80];
    /* b4 */ u32 mUnk_b4;
    /* b8 */ u32 mUnk_b8;
    /* bc */ u32 mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ u8 *mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ s32 mUnk_e4;
    /* e8 */ s32 mUnk_e8;
    /* ec */ s32 mUnk_ec;
} Unk02192e04;

// Copy of Unk02192e04 made by func_ov000_0219338c, 0x204 bytes.
typedef struct Unk0219338c {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x1f];
    /* 027 */ u8 mUnk_027[0x15];
    /* 03c */ u8 mUnk_03c[0x33];
    /* 06f */ u8 mUnk_06f[0x1f];
    /* 08e */ u8 mUnk_08e[0x1f];
    /* 0ad */ u8 mUnk_0ad[0x4c];
    /* 0f9 */ u8 mUnk_0f9[3];
    /* 0fc */ s32 mUnk_0fc;
    /* 100 */ u8 mUnk_100[0xb];
    /* 10b */ u8 mUnk_10b[3];
    /* 10e */ u8 mUnk_10e[2];
    /* 110 */ float mUnk_110;
    /* 114 */ float mUnk_114;
    /* 118 */ u8 mUnk_118[0x80];
    /* 198 */ u32 mUnk_198;
    /* 19c */ u32 mUnk_19c;
    /* 1a0 */ u32 mUnk_1a0;
    /* 1a4 */ s32 mUnk_1a4;
    /* 1a8 */ s32 mUnk_1a8;
    /* 1ac */ u8 mUnk_1ac[0x33];
    /* 1df */ u8 mUnk_1df;
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ s32 mUnk_1e4;
    /* 1e8 */ s32 mUnk_1e8;
    /* 1ec */ s32 mUnk_1ec;
    /* 1f0 */ s32 mUnk_1f0;
    /* 1f4 */ s32 mUnk_1f4;
    /* 1f8 */ s32 mUnk_1f8;
    /* 1fc */ s32 mUnk_1fc;
    /* 200 */ s32 mUnk_200;
} Unk0219338c;

#include "00/code_021906e4.h"
#include "00/code_0218f960.h"

u32 func_ov000_02192d64(Unk0218f960 *param_1, Unk021906e4 *param_2);
s32 func_ov000_02192e04(Unk0218f960 *param_1, Unk021937c0Node *param_2, const u8 *param_3);
void func_ov000_0219338c(Unk02192e04 *param_1, Unk0219338c *param_2);
u32 func_ov000_021935bc(u32 param_1, u32 param_2, u32 *param_3, u32 *param_4, u32 *param_5);
// Declared here until the code that defines them is decompiled.
s32 func_ov000_02196870(Unk0218f960 *param_1, const u8 *param_2, s32 param_3);
