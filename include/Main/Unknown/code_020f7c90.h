#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

// Object behind data_0217bc6c, data_0217bc64 and data_0217bc74: mUnk_00 rows of 0x12
// halfwords at mUnk_04, filled in by func_020f8148.
typedef struct Unk0217bc6c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 (*mUnk_04)[0x12];
} Unk0217bc6c;

extern Unk0217bc6c data_0217bc74;

extern Unk0217bc6c data_0217bc64;

extern Unk0217bc6c data_0217bc6c;

// Element of the table behind data_02159c3c, 0xe bytes.
typedef struct Unk02159c3c {
    /* 00 */ u16 mUnk_00[7];
} Unk02159c3c;

extern Unk02159c3c data_02159c3c[];

void func_020f80c0(Unk0217bc6c *a, s32 b);
void func_020f7ec8(void);
u8 func_020f7ea8(void *a, void *b);
void func_020f7c90(Unk020f41c4_A *a, Vec3 *b, Vec3 *c);
