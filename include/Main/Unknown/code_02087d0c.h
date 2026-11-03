#pragma once

#include "types.h"

typedef struct Unk02010b50 Unk02010b50;
typedef struct Unk02010ab4 Unk02010ab4;

// 0x38-byte object: a table of pointers at 0x1c (count at 0x18, current index at 0x1a) and a table of words at 0x20,
// both with one entry per element.
typedef struct Unk02087d0c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ Unk02010ab4 *mUnk_14;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ Unk02010b50 **mUnk_1c;
    /* 20 */ u32 *mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ Unk02010b50 *mUnk_34;
} Unk02087d0c;

extern s32 (*data_02155cd8[])(Unk02010b50 *a);

typedef struct Unk020882fc_08 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk020882fc_08;

typedef struct Unk020882fc {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk020882fc_08 *mUnk_08;
} Unk020882fc;

extern u32 data_0217af20;

s32 func_02087d0c(void *a);
void func_02087d44(Unk02087d0c *p);
void func_02087de0(void *a);
void func_02087e90(void *a, u16 b);
void func_02087f84(void *a, s32 b);
void func_0208805c(void *a, void *b, void *c);
void func_020881b0(void *a, s32 b, void *c, u32 d, void *e);
void func_0208823c(u32 a, void *b, void *c, u32 d, void *e, void *f);
unsigned int func_020882fc(Unk020882fc *p0);
unsigned int func_02088308(Unk020882fc *p0);
unsigned int func_02088314(Unk020882fc *p0);
unsigned int func_02088320(Unk020882fc *p0);
unsigned int func_0208832c(Unk020882fc *p0);
