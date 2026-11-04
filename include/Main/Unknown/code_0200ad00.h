#pragma once

#include "types.h"
#include "code_02142eac.h"

// 0x180-byte entries from 0x600 of Unk0216fda8.
typedef struct Unk0216fda8_600 {
    /* 000 */ u8 mUnk_000[0xc0];
    /* 0c0 */ Unk021425e8 mUnk_0c0;
    /* 178 */ u8 mUnk_178[8];
} Unk0216fda8_600;

// Object behind data_0216fda8 (0x1e00 bytes).
typedef struct Unk0216fda8 {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ u32 mUnk_008;
    /* 00c */ u16 mUnk_00c;
    /* 00e */ u16 mUnk_00e;
    /* 010 */ u16 mUnk_010;
    /* 012 */ u16 mUnk_012;
    /* 014 */ u16 mUnk_014;
    /* 016 */ u16 mUnk_016;
    /* 018 */ u16 mUnk_018;
    /* 01a */ u8 mUnk_01a[0x32 - 0x1a];
    /* 032 */ u16 mUnk_032;
    /* 034 */ u16 mUnk_034;
    /* 036 */ u16 mUnk_036;
    /* 038 */ u8 mUnk_038[8];
    /* 040 */ u8 mUnk_040[0x400];
    /* 440 */ u8 mUnk_440[0xc0];
    /* 500 */ u16 mUnk_500;
    /* 502 */ u16 mUnk_502;
    /* 504 */ u32 mUnk_504;
    /* 508 */ Unk021425e8Func mUnk_508;
    /* 50c */ u8 mUnk_50c;
    /* 50d */ u8 mUnk_50d;
    /* 50e */ u8 mUnk_50e[0x518 - 0x50e];
    /* 518 */ u16 mUnk_518;
    /* 51a */ u16 mUnk_51a;
    /* 51c */ void (*mUnk_51c)(s32, Unk021425e8 *);
    /* 520 */ u16 *mUnk_520;
    /* 524 */ u16 mUnk_524;
    /* 526 */ u16 mUnk_526;
    /* 528 */ u16 mUnk_528;
    /* 52a */ u16 mUnk_52a;
    /* 52c */ u16 mUnk_52c;
    /* 52e */ u8 mUnk_52e[2];
    /* 530 */ u16 mUnk_530[4];
    /* 538 */ u16 mUnk_538[16];
    /* 558 */ u8 mUnk_558[0x5e0 - 0x558];
    /* 5e0 */ u16 mUnk_5e0;
    /* 5e2 */ u16 mUnk_5e2;
    /* 5e4 */ u32 mUnk_5e4;
    /* 5e8 */ u32 mUnk_5e8;
    /* 5ec */ u32 mUnk_5ec;
    /* 5f0 */ u8 mUnk_5f0[0x10];
    /* 600 */ Unk0216fda8_600 mUnk_600[16];
} Unk0216fda8;

// 0x10-byte entries from 0x30 of Unk0200adfc.
typedef struct Unk0200adfc_30 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0200adfc_30;

typedef struct Unk0200adfc {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ u8 mUnk_10[4];
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x18];
    /* 30 */ Unk0200adfc_30 mUnk_30[4];
} Unk0200adfc;

void func_0200ad00(void);
u32 func_0200ad4c(void);
u32 func_0200ada4(Unk02143a78 *a);
u32 func_0200adfc(Unk0200adfc *a, u32 b, void *c, u32 d);
void func_0200ae60(Unk0200adfc *a, u32 b, u32 c, u32 d, u32 e);
