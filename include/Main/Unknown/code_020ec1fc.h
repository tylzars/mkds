#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Initialiser stored into the 0x28-byte object func_020ec314 allocates.
typedef struct Unk021594e4 {
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
} Unk021594e4;

extern Unk021594e4 *data_0217bbf4;

// Initialiser stored into the 0x2c-byte object func_020ec370 allocates.
typedef struct Unk0215950c {
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
} Unk0215950c;

extern Unk0215950c *data_0217bbec;

// Initialiser stored into the 0x40-byte object func_020ec3cc allocates.
typedef struct Unk02159538 {
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
} Unk02159538;

extern const Unk021594e4 data_021594e4;
extern const Unk0215950c data_0215950c;
extern const Unk02159538 data_02159538;

void func_020ec1fc(void *a, Unk020e43a8 *b, void *c, u32 d);
Unk021594e4 *func_020ec314(void);
Unk0215950c *func_020ec370(void);
Unk02159538 *func_020ec3cc(void);
BOOL func_020ec41c(Unk020e43a8 *a, void *b, u8 *c);
BOOL func_020ec450(Unk020e43a8 *a, void *b, u8 *c);
