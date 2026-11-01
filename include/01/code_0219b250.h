#pragma once

#include "types.h"

// Object at Unk0219b250::mUnk_1c and mUnk_20 (a 0x38-byte allocation).
typedef struct Unk0219b250_Item {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xa];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} Unk0219b250_Item;

// Object at Unk0219b250_10::mUnk_04.
typedef struct Unk0219b250_10_04 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u8 mUnk_18;
} Unk0219b250_10_04;

// Object at Unk0219b250::mUnk_10 (a 0x6c-byte allocation).
typedef struct Unk0219b250_10 {
    /* 00 */ u8 mUnk_00[0x4];
    /* 04 */ Unk0219b250_10_04 *mUnk_04;
    /* 08 */ u8 mUnk_08[0x24];
    /* 2c */ struct Unk02188950 *mUnk_2c;
} Unk0219b250_10;

// Object behind Unk02188950::mUnk_304: the 0x2c-byte allocation made by func_ov001_0219b478 and func_ov001_0219b418.
typedef struct Unk0219b250 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk0219b250_10 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk0219b250_Item *mUnk_1c;
    /* 20 */ Unk0219b250_Item *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mUnk_28;
} Unk0219b250;

// First argument of func_ov001_0219b478 and func_ov001_0219b418.
typedef struct Unk0219b478 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0219b478;

void func_ov001_0219b250(Unk0219b250 *p0);
void func_ov001_0219b25c(Unk0219b250 *p0, void *p1);
void func_ov001_0219b28c(Unk0219b250 *p0, void *p1);
void func_ov001_0219b2e8(Unk0219b250 *p0, char *p1);
void func_ov001_0219b31c(Unk0219b250 *p0, char *p1);
void func_ov001_0219b380(Unk0219b250 *p0, char *p1);
void func_ov001_0219b3b4(Unk0219b250 *p0, char *p1);
Unk0219b250 *func_ov001_0219b418(Unk0219b478 *p0, char *p1);
Unk0219b250 *func_ov001_0219b478(Unk0219b478 *p0, char *p1);
void *func_ov001_0219b4d8(char *p0);
void *func_ov001_0219b510(void *p0, void *p1, void *p2, u32 p3, u16 p4, u16 p5, u16 p6);
void func_ov001_0219b540(void);
