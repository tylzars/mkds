#pragma once

#include "types.h"

typedef struct Unk02061808 Unk02061808;

// Object whose address func_ov001_021a2048 receives as its second argument.
typedef struct Unk021a2048_9c {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ s16 mUnk_28;
} Unk021a2048_9c;

typedef struct Unk021a2048 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0x56];
    /* 66 */ u16 mUnk_66;
    /* 68 */ u8 mUnk_68[0x34];
    /* 9c */ Unk021a2048_9c *mUnk_9c;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ void *mUnk_a4;
} Unk021a2048;

// Argument of func_ov001_021a2300: a table of objects and the number of its entries.
typedef struct Unk021a2300 {
    /* 00 */ Unk021a2048 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021a2300;

void *func_ov001_021a2034(void);
void func_ov001_021a2048(void *p0, Unk021a2048 *p1);
void func_ov001_021a2218(Unk021a2048 *o, Unk02061808 *g, Vec3 *out);
void *func_ov001_021a226c(void);
void func_ov001_021a2284(void *p0, Unk021a2048 *p1);
void func_ov001_021a2300(Unk021a2300 *p);
