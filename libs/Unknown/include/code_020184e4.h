#pragma once

#include "types.h"
#include "code_0201c528.h"

// Word at Unk020184e4_2c 0x0c and Unk020184e4_2c_00 0x04.
typedef struct Unk020184e4_2c_0c {
    /* 00 */ u32 mUnk_00_0 : 4;
    /* 00 */ u32 mUnk_00_4 : 4;
    /* 00 */ u32 mUnk_00_8 : 4;
    /* 00 */ u32 mUnk_00_12 : 2;
    /* 00 */ u32 mUnk_00_14 : 2;
    /* 00 */ u32 mUnk_00_16 : 1;
    /* 00 */ u32 mUnk_00_17 : 1;
    /* 00 */ u32 mUnk_00_18 : 8;
    /* 00 */ u32 mUnk_00_26 : 6;
} Unk020184e4_2c_0c;

// Header of an entry of the table at Unk020184e4 0x2c.
typedef struct Unk020184e4_2c_00 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk020184e4_2c_0c mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[8];
    /* 1c */ s32 mUnk_1c;
} Unk020184e4_2c_00;

// Entries of the table at Unk020184e4 0x2c (0x14 bytes each, count at 0x32).
typedef struct Unk020184e4_2c {
    /* 00 */ Unk020184e4_2c_00 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk020184e4_2c_0c mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk020184e4_2c;

// First bytes of the data func_02018a1c reads.
typedef struct Unk02018a1c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk02018a1c;

typedef struct Unk020184e4 {
    /* 00 */ void *(*mUnk_00)(u32 a);
    /* 04 */ Unk0201e494 mUnk_04[3];
    /* 28 */ Unk0201ca6c_20 *mUnk_28;
    /* 2c */ Unk020184e4_2c *mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mUnk_32;
    /* 34 */ s16 mUnk_34;
    /* 36 */ s16 mUnk_36;
    /* 38 */ u32 mUnk_38_0 : 6;
    /* 38 */ u32 mUnk_38_6 : 6;
    /* 38 */ u32 mUnk_38_12 : 6;
    /* 38 */ u32 mUnk_38_18 : 6;
    /* 38 */ u32 mUnk_38_24 : 1;
    /* 38 */ u32 mUnk_38_25 : 7;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ Unk0201ca6c *mUnk_40;
    /* 44 */ MtxFx43 *mUnk_44;
    /* 48 */ u16 mUnk_48;
} Unk020184e4;

// Entries of the two local call tables of func_020192e0.
typedef struct Unk020192e0_28 {
    /* 00 */ void (*mUnk_00)(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
    /* 04 */ u32 mUnk_04;
} Unk020192e0_28;

void func_020184e4(Unk020184e4 *a, Unk0201ca6c *b);
Unk0201ca6c *func_02018578(Unk020184e4 *a, s32 b, Vec3 *c, s32 d, void (*e)(Unk0201ca6c *p, s32 a));
Unk0201ca6c *func_02018600(Unk020184e4 *a, s32 b, Vec3 *c);
void func_02018674(Unk020184e4 *a, MtxFx43 *b);
void func_0201873c(Unk020184e4 *a);
s32 func_02018874(Unk020184e4 *a);
s32 func_02018888(Unk020184e4 *a);
s32 func_0201889c(Unk020184e4 *a, u32 (*b)(s32 a, s32 b));
s32 func_02018950(Unk020184e4 *a, u32 (*b)(s32 a, s32 b));
void func_02018a1c(Unk020184e4 *a, Unk02018a1c *b);
Unk020184e4 *func_02018d94(void *(*a)(u32 a), u16 b, u16 c, s32 d, u16 e, u16 f);
u32 func_02018f24(s32 a, s32 b);
u32 func_02018f5c(s32 a, s32 b);
void func_02018f94(Unk0201ca6c *a, Vec3 *b, Vec3 *c);
void func_02019090(Unk020184e4 *a);
void func_0201910c(Unk020184e4 *a);
void func_020191f4(Unk020184e4 *a);
void func_020192e0(Unk020184e4 *a, Unk0201ca6c *b);
void func_02019b28(Unk0201ca6c *a, Unk0201ca6c_20 *b, Vec3 *c);
void func_02019df4(Unk020184e4_2c *a);
void func_02019df8(Unk020184e4_2c *a);
void func_02019ee4(Unk020184e4 *a, Unk0201e3c8 *b);
void func_0201a364(Unk020184e4 *a, Unk0201e3c8 *b);
void func_0201a7e0(Unk020184e4 *a, Unk0201e3c8 *b);
void func_0201ab30(Unk020184e4 *a, Unk0201e3c8 *b);
void func_0201ae80(Unk020184e4 *a, Unk0201e3c8 *b);
void func_0201b560(Unk020184e4 *a, Unk0201e3c8 *b);
void func_0201bc48(Unk020184e4 *a, Unk0201e3c8 *b);
void func_0201c09c(Unk020184e4 *a, Unk0201e3c8 *b);
