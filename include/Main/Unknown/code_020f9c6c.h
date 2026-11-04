#pragma once

#include "types.h"

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

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec

// Object func_020e6b38 returns: a vector at 0x18.
typedef struct Unk020e6b38 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ Vec3 mUnk_18;
} Unk020e6b38;

// Stack object of func_020fb038: the two vectors func_02039860 and func_020d7b88 write.
typedef struct Unk020fb038 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[8];
} Unk020fb038;

// Element of data_027e00cc[5]: 0x31c bytes (the size in data_0217bc34[5]), handled by the functions of this file
// from func_020fad9c to func_020fc268 and by those of code_020fc2e8.c, code_020fcbb8.c and code_020fcf10.c.
typedef struct Unk020fc2e8 {
    /* 000 */ Unk020f41c4_A mUnk_000;
    /* 12c */ u8 mUnk_12c[4];
    /* 130 */ u32 mUnk_130;
    /* 134 */ u8 mUnk_134[0x2c];
    /* 160 */ s32 mUnk_160;
    /* 164 */ u8 mUnk_164[4];
    /* 168 */ Unk020f371c *mUnk_168;
    /* 16c */ s32 mUnk_16c;
    /* 170 */ u32 mUnk_170;
    /* 174 */ u8 mUnk_174[0xa8];
    /* 21c */ s32 mUnk_21c;
    /* 220 */ u8 mUnk_220[8];
    /* 228 */ struct Unk020ee684 *mUnk_228;
    /* 22c */ Vec3 mUnk_22c;
    /* 238 */ Vec3 mUnk_238;
    /* 244 */ Vec3 mUnk_244;
    /* 250 */ Vec3 mUnk_250;
    /* 25c */ s32 mUnk_25c;
    /* 260 */ s32 mUnk_260;
    /* 264 */ s32 mUnk_264;
    /* 268 */ u16 mUnk_268;
    /* 26a */ u8 mUnk_26a[2];
    /* 26c */ s32 mUnk_26c;
    /* 270 */ s32 mUnk_270;
    /* 274 */ u16 mUnk_274;
    /* 276 */ u16 mUnk_276;
    /* 278 */ s32 mUnk_278;
    /* 27c */ s32 mUnk_27c;
    /* 280 */ u16 mUnk_280;
    /* 282 */ u8 mUnk_282[2];
    /* 284 */ s32 mUnk_284;
    /* 288 */ u16 mUnk_288;
    /* 28a */ u8 mUnk_28a[2];
    /* 28c */ Vec3 mUnk_28c;
    /* 298 */ Vec3 mUnk_298;
    /* 2a4 */ Vec3 mUnk_2a4;
    /* 2b0 */ struct Unk0208e490 *mUnk_2b0;
    /* 2b4 */ u8 mUnk_2b4[0x30];
    /* 2e4 */ s32 mUnk_2e4;
    /* 2e8 */ u8 mUnk_2e8[4];
    /* 2ec */ u32 mUnk_2ec;
    /* 2f0 */ u8 mUnk_2f0[6];
    /* 2f6 */ u16 mUnk_2f6;
    /* 2f8 */ u16 mUnk_2f8;
    /* 2fa */ u16 mUnk_2fa;
    /* 2fc */ s32 mUnk_2fc;
    /* 300 */ Unk0210b7ec mUnk_300;
    /* 310 */ u8 mUnk_310[0xc];
} Unk020fc2e8;

typedef struct Unk020fc2e8 Unk020fc2e8;

#include "Main/Unknown/code_020f1d70.h"

#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_0206bcb0.h"

extern Unk020ea670 *data_0217bd38;

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
struct Unk020f41c4_A *func_020fa4b4(u32 arg0);
s32 func_020fa4c8(Kart *param_1);
void func_020fa78c(s32 param_1, s32 param_2, s32 param_3);
void func_020fa8ac(void *a);
void func_020fa920(void);
void func_020fa9e4(void);
BOOL func_020faa78(s32 param_1);
BOOL func_020fab34(s32 *param_1);
BOOL func_020faca4(s32 param_1);
void func_020fad00(void);
Vec3 *func_020fad9c(Unk020fc2e8 *param_1, s32 *param_2, s32 *param_3);
BOOL func_020fadcc(Unk020fc2e8 *param_1);
s32 func_020fade4(Unk020fc2e8 *param_1);
void func_020fae74(Unk020fc2e8 *param_1, s32 param_2, s32 param_3);
void func_020faed0(Unk020fc2e8 *param_1, s32 param_2, s32 param_3);
void func_020fb038(Unk020fc2e8 *param_1);
void *func_020fb208(void *param_1, Unk020fc2e8 *param_2, void *param_3);
void func_020fb2b4(Unk020fc2e8 *param_1);
void func_020fb35c(Unk020fc2e8 *param_1);
void func_020fb46c(Unk020fc2e8 *param_1);
void func_020fb5dc(Unk020fc2e8 *param_1);
void func_020fb61c(Unk020fc2e8 *param_1);
void func_020fb770(Unk020fc2e8 *param_1);
void func_020fb7f8(Unk020fc2e8 *param_1);
void func_020fba6c(Unk020fc2e8 *param_1);
void func_020fbae0(Unk020fc2e8 *param_1);
void func_020fbc18(Unk020fc2e8 *param_1);
void func_020fbd4c(Unk020fc2e8 *param_1);
void func_020fbd98(Unk020fc2e8 *param_1);
void func_020fc268(Unk020fc2e8 *param_1);
void func_020fc2c0(int a);
void func_020fc2e8(Unk020fc2e8 *p, Vec3 *v, s32 v1, Vec3 *v2);
void func_020fc654(Unk020fc2e8 *p);
s32 func_020fc79c(Unk020eda5c *a, Unk020fc2e8 *e);
void func_020fc8ec(Unk020fc2e8 *e, s32 a);
void func_020fc94c(Unk020fc2e8 *p);
void func_020fcac0(Unk020fc2e8 *a);
void func_020fcb30(Unk020fc2e8 *p);
