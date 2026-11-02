#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object passed to the per-frame functions func_ov001_02185bb8 and func_ov001_02185ca0.
typedef struct Unk02185bb8 {
    /* 000 */ Unk020e71a0 mUnk_000;
    /* 0a0 */ Unk020e71a0 *mUnk_0a0;
    /* 0a4 */ Unk020e71a0 *mUnk_0a4;
    /* 0a8 */ u16 mUnk_0a8;
    /* 0aa */ u8 mUnk_0aa[0x2];
    /* 0ac */ s32 mUnk_0ac;
} Unk02185bb8;

// Object whose flags and index func_ov001_02185d74 reads.
typedef struct Unk02185d74 {
    /* 00 */ u8 mUnk_00[0x48];
    /* 48 */ u32 mUnk_48;
    /* 4c */ u8 mUnk_4c[0x28];
    /* 74 */ u16 mUnk_74;
} Unk02185d74;

// Table of objects walked by func_ov001_02185c4c.
typedef struct Unk02185c4c {
    /* 00 */ Unk02185bb8 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk02185c4c;

#include "01/code_0219b250.h"
#include "01/code_0218155c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/unk_021759c0.h"

typedef struct Unk02185f04_1 {
    /* 00 */ u8 mUnk_00[0x50];
    /* 50 */ s32 mUnk_50;
    /* 54 */ u8 mUnk_54[0x4];
    /* 58 */ s32 mUnk_58;
} Unk02185f04_1;

typedef struct Unk02185fb0_1 {
    /* 00 */ u8 mUnk_00[0x80];
    /* 80 */ s32 mUnk_80;
    /* 84 */ u8 mUnk_84[0x4];
    /* 88 */ s32 mUnk_88;
} Unk02185fb0_1;

void func_ov001_021870e4(void *param_1, Unk02188950 *param_2, const char *param_3, const char *param_4,
                         const char *param_5);
void func_ov001_021872e0(Unk02188950 *param_1, int param_2, int param_3, int param_4, int param_5, int param_6,
                         int param_7, int param_8, u32 param_9);

void func_ov001_02187614(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6,
                         s32 param_7);

#include "01/code_02188950.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_02187000.h"

void *func_ov001_02185ef4(void);
s32 func_ov001_02185f04(Unk02188950 *param_1, Unk02185f04_1 *param_2, u8 *param_3, u8 *param_4);
s32 func_ov001_02185fb0(Unk02188950 *param_1, Unk02185fb0_1 *param_2, u8 *param_3, u8 *param_4);
s32 func_ov001_021860cc(Unk02188950 *param_1, Vec3 *param_2, s32 param_3, Vec3 *param_4);
void func_ov001_021861f4(void *param_1, Unk02188950 *param_2, s32 param_3);
void func_ov001_02186368(void *param_1, Unk02188950 *param_2);
void func_ov001_021864ac(u32 param_1, Unk02188950 *param_2);
u16 func_ov001_02186fb4(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5);
u16 func_ov001_02187024(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4);
int func_ov001_02187074(int param_1, int param_2, int param_3);
void func_ov001_02187098(void);
void func_ov001_021870b0(void *param_1, Unk02188950 *param_2, const char *param_3);
int func_ov001_021871d0(Unk02188950 *param_1);
u32 func_ov001_021871f8(Unk02188950 *param_1, int param_2);
void func_ov001_0218720c(Unk02188950 *param_1);
void func_ov001_02187218(Unk02188950 *param_1, int param_2, s32 (*param_3)(Unk02188950 *));
void func_ov001_0218742c(Unk0206c1ac *param_1, const UnkVec16 *param_2);
void func_ov001_02187444(Unk02188950 *param_1, u32 param_2, int param_3);
void func_ov001_021874c4(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
void func_ov001_02187518(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
void func_ov001_0218756c(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
void func_ov001_021875c0(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
void func_ov001_02187684(Unk02188950 *param_1, int param_2, Vec3 *param_3);
void func_ov001_02187af4(Unk02188950 *param_1);
void func_ov001_02187b2c(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4);
void func_ov001_02187b94(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4);

#include "01/code_0219b540.h"
