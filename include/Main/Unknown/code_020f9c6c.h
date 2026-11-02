#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

// Row of the array at 0x00 of the object behind gCourseMap.
typedef struct Unk020fa294 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ u16 mUnk_24;
    /* 26 */ s16 mUnk_26;
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ s16 mUnk_30;
    /* 32 */ s16 mUnk_32;
    /* 34 */ s16 mUnk_34;
    /* 36 */ s16 mUnk_36;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u8 mUnk_3a[2];
} Unk020fa294;

void func_020f9c6c(Unk020f41c4_A *param_1);
void func_020f9ca8(void *param_1);
s32 func_020f9ce8(Unk020f41c4_A *param_1);
s32 func_020f9dc8(Unk020f41c4_A *param_1);
void func_020f9f08(void *param_1, s32 param_2, s32 param_3);
void func_020f9fa8(Unk020f41c4_A *param_1);
void func_020fa030(Unk020f41c4_A *param_1);
s32 func_020fa0b8(void *param_1, s32 param_2, s32 param_3);
s32 func_020fa0e8(s32 param_1, s32 param_2);
void func_020fa13c(void);
void func_020fa294(void);
void *func_020fa3d0(s32 param_1, u16 param_2, void *param_3, void *param_4);
