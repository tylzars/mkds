#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // UnkVec16

// Sixteen bytes; gCourseCollision.mUnk_08 points to an array of these, which func_01ffdee4 indexes by halfwords.
typedef struct Unk0217b614_08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk0217b614_08;

// Object at gCourseCollision (0x3c bytes): three tables, a tree of word offsets, three words, three masks and three
// shift counts.
typedef struct Unk0217b614 {
    /* 00 */ Vec3 *mUnk_00;
    /* 04 */ UnkVec16 *mUnk_04;
    /* 08 */ Unk0217b614_08 *mUnk_08;
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ u8 mUnk_10[4];
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u8 mUnk_38[4];
} Unk0217b614;

int func_01ffdee4(void *param_1, void *param_2, u32 param_3, int param_4, u32 param_5, short param_6, void *param_7,
                  void *param_8, void *param_9, u32 *param_10, u32 *param_11, int *param_12, u16 *param_13,
                  u32 *param_14);
