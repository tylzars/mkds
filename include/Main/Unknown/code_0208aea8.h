#pragma once

#include "types.h"
#include "code_020184e4.h"

// Object behind data_0217b048: six vectors, six object pointers and a halfword; 0x64 bytes.
typedef struct Unk0217b048 {
    /* 00 */ Vec3 mUnk_00[6];
    /* 48 */ Unk0201ca6c *mUnk_48[6];
    /* 60 */ s16 mUnk_60;
    /* 62 */ u8 mUnk_62[2];
} Unk0217b048;

// Two halfwords at data_usa_021660f8.
typedef struct Unk021660f8 {
    s16 mUnk_00[2];
} Unk021660f8;

// Twenty-four halfwords at data_usa_02166108.
typedef struct Unk02166108 {
    s16 mUnk_00[24];
} Unk02166108;

// Function stored at data_0217b050: writes a word to the first argument and returns the object.
typedef SPLManager *Unk0217b050Func(s32 *a, s32 b);
extern Unk0217b050Func *data_0217b050;

extern Unk0217b048 *data_0217b048;
extern char data_usa_021660c8[];
extern char data_usa_021660e0[];
extern Unk021660f8 data_usa_021660f8;
extern Unk02166108 data_usa_02166108;
extern s32 data_usa_02155f48[];
extern Vec3 data_usa_02155f78[];
extern Vec3 data_usa_02155fc0;

void CopyKartPhysicalParams(u32 a, u32 b, u32 c);
void CreateKartPhysicalParamTable(void *a, u32 b);
void func_0208afe4(void);
void func_0208b190(void);
SPLManager *func_0208b458(s32 *a, s32 b);
