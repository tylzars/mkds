#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object passed to the per-frame functions UpdateMissionGate and DrawMissionGate.
typedef struct MissionGateObject {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ MapObject *mUnk_0a0;
    /* 0a4 */ MapObject *mUnk_0a4;
    /* 0a8 */ u16 mUnk_0a8;
    /* 0aa */ u8 mUnk_0aa[0x2];
    /* 0ac */ s32 mState;
} MissionGateObject;

// Object whose flags and index func_ov001_02185d74 reads.
typedef struct Unk02185d74 {
    /* 00 */ u8 mUnk_00[0x48];
    /* 48 */ u32 mUnk_48;
    /* 4c */ u8 mUnk_4c[0x28];
    /* 74 */ u16 mUnk_74;
} Unk02185d74;

// Table of objects walked by func_ov001_02185c4c.
typedef struct Unk02185c4c {
    /* 00 */ MissionGateObject **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk02185c4c;

#include "01/code_0219b250.h"
#include "01/code_0218155c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_0209b000.h"

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

void func_ov001_021870e4(void *a, Unk02188950 *b, const char *c, const char *d, const char *e);
void func_ov001_021872e0(Unk02188950 *a, int b, int c, int d, int e, int f, int g, int h, u32 l);

void func_ov001_02187614(Unk02188950 *a, s32 b, s32 c, s32 d, s32 e, u32 f, s32 g);

#include "01/code_02188950.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_02187000.h"

void *func_ov001_02185ef4(void);
s32 func_ov001_02185f04(Unk02188950 *a, Unk02185f04_1 *b, u8 *c, u8 *d);
s32 func_ov001_02185fb0(Unk02188950 *a, Unk02185fb0_1 *b, u8 *c, u8 *d);
s32 func_ov001_021860cc(Unk02188950 *a, Vec3 *b, s32 c, Vec3 *d);
void func_ov001_021861f4(void *d, Unk02188950 *e, s32 f);
void func_ov001_02186368(void *a, Unk02188950 *b);
void func_ov001_021864ac(u32 a, Unk02188950 *b);
u16 func_ov001_02186fb4(Vec3 *a, Vec3 *b, s32 c, s32 d, s32 e);
u16 func_ov001_02187024(Vec3 *a, Vec3 *b, s32 c, s32 d);
int func_ov001_02187074(int a, int b, int c);
void func_ov001_02187098(void);
void func_ov001_021870b0(void *a, Unk02188950 *b, const char *c);
BOOL func_ov001_021871d0(Unk02188950 *a);
u32 func_ov001_021871f8(Unk02188950 *a, int b);
void func_ov001_0218720c(Unk02188950 *a);
void func_ov001_02187218(Unk02188950 *a, int b, s32 (*c)(Unk02188950 *));
void func_ov001_0218742c(Unk0206c1ac *a, const UnkVec16 *b);
void func_ov001_02187444(Unk02188950 *a, u32 b, int c);
void func_ov001_021874c4(Unk02188950 *a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_ov001_02187518(Unk02188950 *a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_ov001_0218756c(Unk02188950 *a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_ov001_021875c0(Unk02188950 *a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_ov001_02187684(Unk02188950 *a, int b, Vec3 *c);
void func_ov001_02187af4(Unk02188950 *a);
void func_ov001_02187b2c(void *a, Vec3 *b, Vec3 *c, s32 d);
void func_ov001_02187b94(void *a, Vec3 *b, Vec3 *c, s32 d);

#include "01/code_0219b540.h"
