#pragma once

#include "types.h"
#include "Main/Unknown/code_020e43a8.h"

// 0x28-byte object built from a table.
typedef struct Unk020e4610 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
} Unk020e4610;

extern Unk020e4610 *data_0217b7dc;

// 0x2c-byte object built from a table.
typedef struct Unk020e466c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
} Unk020e466c;

// 0x40-byte object built from a table.
typedef struct Unk020e46c8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} Unk020e46c8;

void func_020e44e4(u32 a, Unk020e43a8 *p);
Unk020e4610 *func_020e4610(void);
Unk020e466c *func_020e466c(void);
Unk020e46c8 *func_020e46c8(void);
Unk020e46c8 *func_020e4718(void);
Unk020e46c8 *func_020e4768(void);
void func_020e47c8(Unk020e43a8 *p, Vec3 *a);
