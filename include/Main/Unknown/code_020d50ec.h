#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d849c.h"

// 0x1c-byte element of the table behind data_0217b5b8.
typedef struct Unk0217b5b8 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Vec3 *mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ void *mUnk_18;
} Unk0217b5b8;

// Four-byte element of the tables behind data_0217b5b4 and data_0217b5c0.
typedef struct Unk0217b5b4 {
    /* 00 */ u32 mUnk_00 : 8;
    /* 01 */ u32 mUnk_01 : 8;
    /* 02 */ s32 mUnk_02 : 16;
} Unk0217b5b4;

u32 func_020d5344(s32 a);
s32 func_020d555c(Vec3 *a, s32 b, s32 c, void *d);
// Object behind the pointer func_020d5a68 and func_020d5aa0 read: a pointer at 0x00 and a word at 0x04.
typedef struct Unk020d5a68 {
    /* 00 */ Unk020e005c *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020d5a68;

// Element object of func_020d5bf0: MapObject and the words and halfword used after it.
typedef struct Unk020d5bf0 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ Unk020d84e4 mUnk_0a4;
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ Vec3 mUnk_0e4;
    /* 0f0 */ Vec3 *mUnk_0f0;
    /* 0f4 */ BOOL mUnk_0f4;
    /* 0f8 */ s32 mUnk_0f8;
    /* 0fc */ s32 mUnk_0fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ u16 mUnk_108;
    /* 10a */ u8 mUnk_10a[2];
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ s32 mUnk_114;
    /* 118 */ s32 mUnk_118;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120;
} Unk020d5bf0;

// Twelve bytes func_020d634c fills: a word and three halfwords.
typedef struct Unk020d634c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
} Unk020d634c;

void func_020d5fb4(void *a, Unk020d5bf0 *p);
void func_020d634c(Unk020d5bf0 *p, s32 b);
u8 func_020d5f8c(Unk020d5bf0 *a, s32 b, u8 *c, u8 *d);
u8 func_020d5f64(Unk020d5bf0 *a, s32 b, u8 *c, u8 *d);
void func_020d5dd0(Unk020d5bf0 *p);
void func_020d5bf0(Unk020d5bf0 *p, struct CourseMapRow *q);
void CreateNsbmdAndShadowNsbmd(void *a, const char *name, const char *shadowName);
void CreateRock(void *a);
void CreateRock2(void *a);
void func_020d5bac(Unk0217b614 *p, Unk0217b614 *a);
void InitCourseCollision(void);
void func_020d5aa0(void *a, u32 b, Unk020e04b0 *c, Vec3 *d, Vec3 *e);
BOOL func_020d5a68(void *a, u32 b, Unk020e04b0 *c);
u16 func_020d59f8(u32 a);
void func_020d58c0(void);
void func_020d5180(void *a, s32 b, s32 c);
void func_020d5148(s16 a, s32 b);
void func_020d5114(s16 a);
void func_020d50ec(s16 a);
