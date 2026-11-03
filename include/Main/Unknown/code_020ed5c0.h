#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020846c0.h" // Unk02084b2c
#include "Main/Unknown/code_0207adf8.h" // Unk0207adf8
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02087d0c.h"

// Object with an array of Unk020f41c4_A pointers at 0x04 and a word at 0x10.
typedef struct Unk020ed718 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ Unk020f41c4_A **mUnk_004;
    /* 008 */ u8 mUnk_008[8];
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
} Unk020ed718;

// The object behind the word at 0x20 of a Unk0206bcb0_590: the vectors from 0x48.
typedef struct Unk0206bcb0_590_20 {
    /* 00 */ char mUnk_00[0x10];
    /* 10 */ s32 mUnk_10;
    /* 14 */ Vec3 mUnk_14[4];
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ Vec3 mUnk_48[1];
} Unk0206bcb0_590_20;

// The object behind the word at 0x590 of a Unk0206bcb0 from its first byte:
// the halfword at 0x40.
// The object behind the word at 0x08 of a Unk0206bcb0_590: the halfword at 0x1a.
typedef struct Unk0206bcb0_590_08 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} Unk0206bcb0_590_08;

// The object behind the word at 0x54 of a Unk0206bcb0_590.
typedef struct Unk0206bcb0_590_54 {
    union {
        Vec3 mUnk_v[4];
        struct {
            /* 00 */ s32 mUnk_00;
            /* 04 */ u8 mUnk_04[8];
            /* 0c */ s32 mUnk_0c;
            /* 10 */ u8 mUnk_10[8];
            /* 18 */ s32 mUnk_18;
            /* 1c */ u8 mUnk_1c[8];
            /* 24 */ s32 mUnk_24;
        };
    };
} Unk0206bcb0_590_54;

// Halfwords at 0x6a of a Unk0206bcb0_590: three packed colours (0x00, 0x02, 0x04), per-channel start values and
// differences, and a step at 0x2a.
typedef struct Unk0206bcb0_590_6a {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
    /* 10 */ s16 mUnk_10;
    /* 12 */ s16 mUnk_12;
    /* 14 */ s16 mUnk_14;
    /* 16 */ s16 mUnk_16;
    /* 18 */ s16 mUnk_18;
    /* 1a */ s16 mUnk_1a;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    /* 20 */ s16 mUnk_20;
    /* 22 */ s16 mUnk_22;
    /* 24 */ s16 mUnk_24;
    /* 26 */ s16 mUnk_26;
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
} Unk0206bcb0_590_6a;

// Words and halfwords from 0x24 of a Unk0206bcb0_590.
typedef struct Unk0206bcb0_590_24 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ s32 mUnk_14;
    /* 18 */ s16 mUnk_18;
} Unk0206bcb0_590_24;

struct Unk02084b2c;

typedef struct Unk0206bcb0_590 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ Unk0206bcb0_590_08 *mUnk_008;
    /* 00c */ Unk0206bcb0_590_08 *mUnk_00c;
    /* 10 */ Unk02084b2c * mUnk_010[3];
    /* 01c */ Unk0207adf8 *mUnk_01c;
    /* 020 */ Unk0206bcb0_590_20 *mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ u8 mUnk_028[4];
    /* 02c */ s32 mUnk_02c;
    /* 030 */ s32 mUnk_030;
    /* 034 */ u8 mUnk_034[0xc];
    /* 040 */ u16 mUnk_040;
    /* 042 */ u8 mUnk_042[0x12];
    /* 054 */ Unk0206bcb0_590_54 *mUnk_054;
    /* 058 */ s32 mUnk_058;
    /* 05c */ s32 mUnk_05c;
    /* 060 */ s32 mUnk_060;
    /* 064 */ s32 mUnk_064;
    /* 068 */ u8 mUnk_068[2];
    /* 06a */ Unk0206bcb0_590_6a mUnk_06a;
    /* 096 */ u8 mUnk_096[2];
    /* 098 */ u8 mUnk_098[0xc];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ u8 mUnk_0a8[4];
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
} Unk0206bcb0_590;

// Three vectors at 0x00, 0x0c and 0x18.
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
} Unk020eda5c_02c;

// Object at 0x58 of a Unk020ee684 (that Unk020ee684 at 0x0c), passed first to the function pointers in the
// data_0217bc34 entries: three Unk020f41c4_A pointers at 0x14, vectors from 0x2c to 0x0e4.
typedef struct Unk020eda5c {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ struct Unk020ee684 *mUnk_00c;
    /* 010 */ Unk0206bcb0 *mUnk_010;
    /* 014 */ Unk020f41c4_A *mUnk_014[3];
    /* 020 */ s32 mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ u16 mUnk_028;
    /* 02a */ u8 mUnk_02a[2];
    /* 02c */ Unk020eda5c_02c mUnk_02c;
    /* 050 */ Vec3 mUnk_050;
    /* 05c */ Vec3 mUnk_05c;
    /* 068 */ s32 mUnk_068;
    /* 06c */ Vec3 mUnk_06c;
    /* 078 */ s32 mUnk_078;
    /* 07c */ s32 mUnk_07c;
    /* 080 */ s32 mUnk_080;
    /* 084 */ Vec3 mUnk_084;
    /* 090 */ Vec3 mUnk_090;
    /* 09c */ Vec3 mUnk_09c;
    /* 0a8 */ Vec3 mUnk_0a8;
    /* 0b4 */ Vec3 mUnk_0b4;
    /* 0c0 */ Vec3 mUnk_0c0;
    /* 0cc */ s32 mUnk_0cc[3];
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ s32 mUnk_0ec[2][16];
    /* 16c */ s32 mUnk_16c;
    /* 170 */ void *mUnk_170;
    /* 174 */ u16 mUnk_174;
    /* 176 */ u16 mUnk_176;
    /* 178 */ s32 mUnk_178;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ Vec3 mUnk_180;
    /* 18c */ u16 mUnk_18c[3];
} Unk020eda5c;

void func_020ed5c0(Unk020f41c4_A *p, Unk020e6488 *q, Vec3 *v);
void func_020ed718(Unk020ed718 *p, void *a, void (*cb)(void *, void *, void *));
void func_020ed79c(Unk020ed718 *p, Vec3 *v);
void *func_020ed98c(Unk020f41c4_A *p, Vec3 *v);
void func_020eda5c(Unk020eda5c *p, Unk020f41c4_A *q);
void func_020edad8(Unk020eda5c *p);
void func_020edb00(Unk020eda5c *p);
s32 func_020edb8c(Unk020eda5c *p, s32 a, s32 b, s32 c, Vec3 *d);
s32 func_020edc9c(Unk020eda5c *p, s32 a, s32 b, s32 c, Vec3 *d);
void func_020eddb4(Unk020eda5c *p);
void func_020ee2e4(Unk020eda5c *a, Unk020f40dc *b);
BOOL func_020ee528(Unk020eda5c *a);
void func_020edf10(Unk020eda5c *p);
void func_020ee160(Unk020f41c4_A *a, Unk020f41c4_A *b);
BOOL func_020ee284(Unk020f41c4_A *p, Vec3 *v, s32 d);
