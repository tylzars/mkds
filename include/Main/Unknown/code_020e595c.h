#pragma once

#include "types.h"
#include "Main/Unknown/code_020e43a8.h"

// 0x28-byte object func_020e59e4 loads from data_021590ec.
typedef struct Unk020e59e4 {
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
} Unk020e59e4;

extern Unk020e59e4 *data_0217b834;

extern Unk020e59e4 *data_0217b828;

extern Unk020e59e4 *data_0217b81c;

// 0x2c-byte object func_020e5a40 loads from data_02159114.
typedef struct Unk020e5a40 {
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
} Unk020e5a40;

extern Unk020e5a40 *data_0217b840;

extern Unk020e5a40 *data_0217b82c;

extern Unk020e5a40 *data_0217b824;

// 0x40-byte object func_020e5a9c loads from data_02159140.
typedef struct Unk020e5a9c {
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
} Unk020e5a9c;

void func_020e595c(u32 a, Unk020e43a8 *p);
void func_020e5990(u32 a, Unk020e43a8 *p, u32 b, u32 c);
Unk020e59e4 *func_020e59e4(void);
Unk020e5a40 *func_020e5a40(void);
Unk020e5a9c *func_020e5a9c(void);
void func_020e5aec(Unk020e43a8 *p);
