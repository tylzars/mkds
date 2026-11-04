#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6b58.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object func_020d4418 and func_020d4484 read: a Unk02012f58 at 0x30.
typedef struct Unk020d4418 {
    /* 00 */ u8 mUnk_00[0x30];
    /* 30 */ Unk02012f58 mUnk_30;
} Unk020d4418;

void func_020d47e0(void);
void func_020d4698(void);
void func_020d4590(void);
void func_020d4484(Unk020d4418 *p);
void func_020d4418(Unk020d4418 *p);
s32 func_020d41e0(Unk0206bcb0 *a, Vec3 *b, Vec3 *c);
s32 func_020d4130(Vec3 *a, s32 b, s32 c);
