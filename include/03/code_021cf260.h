#pragma once

#include "types.h"

// One 0x1e-byte record of Unk021cf260.
typedef struct Unk021cf260_0e {
    /* 00 */ u8 mUnk_00[0x16];
    /* 16 */ u8 mUnk_16[6];
    /* 1c */ u16 mUnk_1c;
} Unk021cf260_0e;

struct Unk021cf260 {
    /* 0000 */ u16 mUnk_00;
    /* 0002 */ u16 mMask;
    /* 0004 */ u16 mUnk_04;
    /* 0006 */ u16 mUnk_06;
    /* 0008 */ u16 mUnk_08;
    /* 000a */ u16 mUnk_0a;
    /* 000c */ u16 mUnk_0c;
    /* 000e */ Unk021cf260_0e mRecords[15];
    /* 01d0 */ u8 mUnk_01d0[0xfe70];
    /* 10040 */ u8 mUnk_10040[0xb100];
    /* 1b140 */ void *mUnk_1b140;
    /* 1b144 */ void *mUnk_1b144;
};

#include "03/unk_021da000.h"
#include "code_02142eac.h"

// Fourteen bytes moved as one value.
typedef struct Unk021cf5ac {
    /* 00 */ u16 mUnk_00[7];
} Unk021cf5ac;

// Object with the path pointer at 0x00 that func_ov003_021cf8ac takes.
typedef struct Unk021cf8ac {
    /* 00 */ const u8 *mUnk_00;
} Unk021cf8ac;

void *func_ov003_021cf260(u32 index);
u32 func_ov003_021cf284(u32 a);
u16 func_ov003_021cf32c(u32 a);
u16 func_ov003_021cf360(void);
void func_ov003_021cf36c(u16 a);
void func_ov003_021cf378(u32 a, u32 b, Unk021425e8 *c);
void func_ov003_021cf598(void);
void func_ov003_021cf5ac(void);
u32 func_ov003_021cf64c(void);
void func_ov003_021cf69c(void);
void func_ov003_021cf72c(u32 a);
void func_ov003_021cf7b8(u32 a);
void func_ov003_021cf844(u32 a);
u32 func_ov003_021cf8ac(Unk021cf8ac *a);
void func_ov003_021cf93c(Unk021cf8ac *a, u16 b);
void func_ov003_021cf978(u32 a, u32 b);
void func_ov003_021cfa30(u8 *a);
