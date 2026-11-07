#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart, UnkVec16
#include "Main/Unknown/code_020846c0.h" // Unk02084b2c

// Object at gCourseModels: two Unk02084b2c pointers, then the words and halfwords the code tests. The flag halfwords
// live inside the embedded animation objects. 0xf4 is the distance to the next symbol, so the object overlaps four
// other symbols: data_usa_0217abac at +0xb0 and the embedded objects data_usa_0217ab04 at +8, data_0217ab5c at +0x40
// and data_usa_0217ab74 at +0x78 (USA).
typedef struct CourseModels {
    /* 00 */ Unk02084b2c *mNsbmd;
    // NULL when '/course_model_V.nsbmd' is absent; drawn before the main model under the other projection argument.
    /* 04 */ Unk02084b2c *mVNsbmd;
    /* 08 */ u8 mUnk_08[0xc];
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[0x36];
    /* 58 */ u16 mUnk_58;
    /* 5a */ u8 mUnk_5a[0x36];
    /* 90 */ u16 mUnk_90;
    /* 92 */ u8 mUnk_92[0x4e];
    /* e0 */ BOOL mUnk_e0;
    /* e4 */ u64 mUnk_e4;
    /* ec */ BOOL mUnk_ec;
    /* f0 */ u16 mUnk_f0;
} CourseModels;

// What func_020636f8 writes from 0x08 of the Unk0217aa14_754_04 it points to.
typedef struct Unk020636f8_B {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk020636f8_B;

extern CourseModels gCourseModels;
extern u8 data_usa_0217ab04[];
extern u8 data_0217ab5c[];
extern u8 data_usa_0217ab74[];
extern MtxFx43 data_usa_0217abac;

extern const char data_usa_02165404[];
extern const char data_usa_02165418[];
extern const char data_usa_0216542c[];
extern const char data_usa_02165440[];
extern const char data_usa_02165454[];
extern const char data_usa_0216546c[];
extern const char data_usa_02165484[];
extern const UnkVec16 data_usa_021653fc;
extern const u32 data_usa_02154990[];
extern const u32 data_usa_021549a0[];
extern const u32 data_usa_021549b0[];
extern const u32 data_usa_021549c0[];
extern const u32 data_usa_021549d0[];
extern const u32 data_usa_021549e0[];
extern const u32 data_usa_021549f0[];
extern const u32 data_usa_02154a00[];
extern const u32 data_usa_02154a10[];
extern u32 data_usa_02154a20[];

s32 func_02062ed8(void);
void SetCourseModelsFogEnableFlags(u32 a);
void InitCourseModelsFogEnableFlags(void);
void SetKoopaCourseLight2(void);
void DrawCourseModelV(void);
void DrawCourseModel(void);
void UpdateCourseModels(void);
void InitCourseModels(void *a);
void func_020636f8(Kart *a);
void func_020637c4(Kart *a);
void func_020637e0(Kart *a);
void func_02063830(Kart *a);
void func_02063880(Kart *a);
