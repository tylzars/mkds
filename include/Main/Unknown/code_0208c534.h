#pragma once

#include "types.h"
#include "code_0201c528.h"

typedef struct Unk02148038 Unk02148038;
typedef struct Unk0206bcb0 Unk0206bcb0;

// 0x88 bytes, from the table behind data_0217b078. The pointer pairs at 0x00 to 0x28 hold objects returned by
// func_0208b7bc.
typedef struct Unk0208c5b8 {
    /* 00 */ Unk0201ca6c *mUnk_00[2];
    /* 08 */ Unk0201ca6c *mUnk_08[2];
    /* 10 */ Unk0201ca6c *mUnk_10[2];
    /* 18 */ Unk0201ca6c *mUnk_18[2];
    /* 20 */ Unk0201ca6c *mUnk_20[2];
    /* 28 */ Unk0201ca6c *mUnk_28[2];
    /* 30 */ s16 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s16 mUnk_48;
    /* 4a */ s16 mUnk_4a;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ u16 mUnk_60;
    /* 62 */ u16 mUnk_62;
    /* 64 */ s32 mUnk_64;
    /* 68 */ void (*mUnk_68)(struct Unk0208c5b8 *);
    /* 6c */ void (*mUnk_6c)(struct Unk0208c5b8 *);
    /* 70 */ void (*mUnk_70)(struct Unk0208c5b8 *);
    /* 74 */ void (*mUnk_74)(struct Unk0208c5b8 *);
    /* 78 */ void (*mUnk_78)(struct Unk0208c5b8 *);
    /* 7c */ void (*mUnk_7c)(struct Unk0208c5b8 *);
    /* 80 */ void (*mUnk_80)(struct Unk0208c5b8 *);
    /* 84 */ void (*mUnk_84)(struct Unk0208c5b8 *, Unk02148038 *, Vec3 *);
} Unk0208c5b8;

extern const Vec3 data_02155fcc;

void func_0208c534(Unk0208c5b8 *p);
Unk0208c5b8 *func_0208c5b8(int v1);
void func_0208c5d0(Unk0208c5b8 *p);
void func_0208c6dc(Unk0208c5b8 *p, Unk02148038 *a, Vec3 *b);
void func_0208c884(Unk0208c5b8 *p, int v1);
void func_0208c930(Unk0208c5b8 *p, Unk02148038 *a, Vec3 *b);
void func_0208cacc(Unk0208c5b8 *p, int v1);
void func_0208cb8c(Unk0208c5b8 *p, Unk0206bcb0 *q);
void func_0208ccf0(Unk0208c5b8 *p);
void func_0208cd2c(Unk0208c5b8 *p);
void func_0208cd7c(Unk0208c5b8 *p);
void func_0208cddc(Unk0208c5b8 *p);
void func_0208ceac(Unk0208c5b8 *p);
void func_0208cefc(Unk0208c5b8 *p);
void func_0208cf5c(Unk0208c5b8 *p);
void func_0208d02c(Unk0208c5b8 *p, Unk02148038 *a, Vec3 *b);
void func_0208d0dc(Unk0208c5b8 *p, Unk02148038 *a, Vec3 *b);
void func_0208d1ec(Unk0208c5b8 *p);
void func_0208d234(Unk0208c5b8 *p);
void func_0208d298(Unk0208c5b8 *p);
void func_0208d2d8(Unk0208c5b8 *p);
void func_0208d328(Unk0208c5b8 *p);
void func_0208d358(Unk0208c5b8 *p);
void func_0208d3a8(Unk0208c5b8 *p);
void func_0208d3d8(Unk0208c5b8 *p);
void func_0208d428(Unk0208c5b8 *p);
void func_0208d46c(Unk0208c5b8 *p);
void func_0208d4c4(Unk0208c5b8 *p, Unk0206bcb0 *q);
void func_0208d650(Unk0208c5b8 *p);
void func_0208d6b0(Unk0208c5b8 *p);
void func_0208d758(void *a);
