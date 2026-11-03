#pragma once

#include "types.h"

// Record of 0x54 bytes: four positions, then words at 0x30 and 0x34.
typedef struct Unk020e0144_00_0 {
    /* 00 */ Vec3 mUnk_00[4];
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ Vec3 mUnk_48;
} Unk020e0144_00_0;

typedef struct Unk020e0144_00 {
    /* 00 */ Unk020e0144_00_0 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk020e0144_00;

typedef struct Unk020e0144 {
    /* 00 */ Unk020e0144_00 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ struct Unk02042044 *mUnk_1c;
    /* 20 */ struct Unk02042044 *mUnk_20;
} Unk020e0144;

// Sub-object at 0x80 of Unk020e005c and MapObject: func_02046be8 stores its second, fourth and third arguments at
// 0x00, 0x08 and 0x0c and zeroes 0x04, 0x0e and 0x10.
typedef struct Unk020e005c_080 {
    /* 00 */ UnkFunc *const *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk020e005c_080;

typedef struct Unk020e005c {
    /* 000 */ u16 mUnk_000;
    /* 002 */ u16 mUnk_002;
    /* 004 */ Vec3 mUnk_004;
    /* 010 */ Vec3 mUnk_010;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ s32 mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ Vec3 mUnk_028;
    /* 034 */ Vec3 mUnk_034;
    /* 040 */ Vec3 mUnk_040;
    /* 04c */ u8 mUnk_04c[0x1a];
    /* 066 */ u16 mUnk_066;
    /* 068 */ u8 mUnk_068[8];
    /* 070 */ s32 mUnk_070;
    /* 074 */ u8 mUnk_074[0x4];
    /* 078 */ u32 mUnk_078;
    /* 07c */ u8 mUnk_07c[0x4];
    /* 080 */ Unk020e005c_080 mUnk_080;
    /* 094 */ u8 mUnk_094[0xc];
    /* 0a0 */ Vec3 mUnk_0a0;
    /* 0ac */ Vec3 mUnk_0ac;
    /* 0b8 */ Vec3 mUnk_0b8;
    /* 0c4 */ u8 mUnk_0c4[0x24];
    /* 0e8 */ Vec3 mUnk_0e8;
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ Vec3 mUnk_114;
    /* 120 */ s32 mUnk_120;
    /* 124 */ Vec3 mUnk_124;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ void *mUnk_140;
    /* 144 */ Unk020e0144 mUnk_144;
    /* 168 */ s32 mUnk_168;
    /* 16c */ u16 mUnk_16c;
} Unk020e005c;

void func_020e005c(Unk020e005c *a);
void func_020e00f8(Unk020e005c *a);
void func_020e012c(Unk020e005c *a);
