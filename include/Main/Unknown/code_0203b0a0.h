#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02056b30.h"

// 0x03-byte argument of func_0203b0a0.
typedef struct Unk0203b0a0 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
} Unk0203b0a0;

BOOL func_0203b0a0(const Unk0203b0a0 *a, const Unk0203b0a0 *b);
void func_0203b0f8(void *a);
void func_0203b194(void *a);
void func_0203b1c8(void *a);
void func_0203b1fc(void *a);
u32 func_0203b230(void);
s32 func_0203b324(void);
BOOL func_0203b3d8(TimeRecord *a, TimeRecord *b);
void func_0203b4c8(TimeRecord *a);
void func_0203b598(TimeRecord *a, Unk0217aa1c_144_00 *b, TimeRecord *c);

#include "00/code_021832d8.h"
