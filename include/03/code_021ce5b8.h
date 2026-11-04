#pragma once

#include "types.h"
#include "code_02142eac.h"

typedef struct Unk021da280_1300 {
    /* 0 */ u8 mUnk_00[6];
    /* 6 */ u8 mUnk_06;
} Unk021da280_1300;

// Object behind data_ov003_021da280.
struct Unk021da280 {
    /* 0000 */ u8 mUnk_0000[0xf00];
    /* 0f00 */ u8 mUnk_0f00[0x400];
    /* 1300 */ Unk021da280_1300 mUnk_1300[16];
    /* 1370 */ void (*mUnk_1370)(u32);
    /* 1374 */ Unk021438f0 mUnk_1374;
    /* 13ac */ u8 mUnk_13ac[0xc];
    /* 13b8 */ Unk02142988 mUnk_13b8;
    /* 1b74 */ u32 mUnk_1b74;
    /* 1b78 */ u32 mUnk_1b78;
    /* 1b7c */ u32 mUnk_1b7c;
    /* 1b80 */ u8 mUnk_1b80;
    /* 1b81 */ u8 mUnk_1b81;
    /* 1b82 */ u8 mUnk_1b82;
};

typedef struct Unk021ce5b8_10 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ u8 mUnk_0c[8];
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
} Unk021ce5b8_10;

typedef struct Unk021ce5b8 {
    /* 00 */ u8 mUnk_00[0xe];
    /* 0e */ u16 mUnk_0e;
    /* 10 */ Unk021ce5b8_10 *mUnk_10[1];
} Unk021ce5b8;

#include "03/unk_021da000.h"

void func_ov003_021ce4d4();
void func_ov003_021ce5b8(Unk021ce5b8 *a);
void func_ov003_021ce6ac(Unk021ce5b8 *a);
void func_ov003_021ce7c0(Unk021425e8 *a);
void func_ov003_021ce834(u32 a);
u32 func_ov003_021ce848(void);
u32 func_ov003_021ce8ec(void);
u32 func_ov003_021ce920(void (*a)(u32));
