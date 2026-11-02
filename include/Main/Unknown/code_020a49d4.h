#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020a3fa8.h" // Unk020a3fa8

// Object returned by func_0209bfa8: the words at 0x38 and 0x3c are set by func_020a5918.
typedef struct Unk0209bfa8 {
    /* 00 */ u8 mUnk_00[0x38];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk0209bfa8;

void func_020a5918(void);
u32 func_020a58f4(void);
u32 func_020a58d0(void);
u32 func_020a58b4(void);
void func_020a5848(void);
void func_020a5744(Vec3 *a, s32 b, s32 c);
void func_020a5608(Unk0206bcb0 *a, Unk0206bcb0 *b);
BOOL func_020a5268(u16 a, u16 b);
s32 func_020a4f54(u16 a, u16 b);
BOOL func_020a4d94(u16 a, u16 b);
void func_020a4c58(u16 a);
void func_020a4c20(void);
void func_020a4b70(u16 a, Vec3 *b);
void func_020a49d4(Unk020a3fa8 *a);
