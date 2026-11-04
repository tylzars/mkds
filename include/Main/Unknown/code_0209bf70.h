#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h" // Unk020e0144

// 0x40-byte object of func_0209bfa8: the words at 0x00 and 0x04 are its first two arguments, 0x18 the third, 0x20 the
// fourth and 0x1c the fifth; func_0209bf70 stores its sixth argument at 0x24.
typedef struct Unk0209bf70 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x10];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c[0xc];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk0209bf70;

// Object of the list func_02100138(0x1a8), created by func_0209bfe0 and moved by func_0209c220.
typedef struct Unk0209c220 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u8 mUnk_0a2[2];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ u8 mUnk_0a8[0xc];
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ u16 mUnk_0b8;
    /* 0ba */ u8 mUnk_0ba[2];
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ s32 mUnk_0c4;
    /* 0c8 */ s32 mUnk_0c8;
    /* 0cc */ s32 mUnk_0cc;
    /* 0d0 */ s32 mUnk_0d0;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ u16 mUnk_0d8;
    /* 0da */ u8 mUnk_0da[2];
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ s32 mUnk_0ec;
    /* 0f0 */ s32 mUnk_0f0;
    /* 0f4 */ s32 mUnk_0f4;
    /* 0f8 */ Unk020e0144 mUnk_0f8;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120[8];
} Unk0209c220;

// Object of func_0209cf34 and func_0209d394.
typedef struct Unk0209cf34 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u32 mUnk_0a0;
    /* 0a4 */ u16 mUnk_0a4;
    /* 0a6 */ u8 mUnk_0a6[2];
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ u32 mUnk_0ac;
    /* 0b0 */ u16 mUnk_0b0;
    /* 0b2 */ u16 mUnk_0b2;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ Unk020e0144 mUnk_0b8;
    /* 0dc */ s32 mUnk_0dc;
} Unk0209cf34;

extern const char gBerryNsbmdName[];
extern const char gCreamEffectNsbmdName[];
extern const char gCreamNsbmdName[];
extern const char gBoundNsbmdName[];
extern const char gBoundNsbtpName[];
extern const char gSunNsbmdName[];
extern const char gSunNsbcaName[];
extern const char gSunLODNsbmdName[];

void CreateBound(void *a);

// Declared here until the code that defines it is decompiled.

// Object of func_0209d3fc: the MapObject it starts with, a word at 0xac, halfwords at 0xb0 and 0xb2 and a state
// at 0xdc.
typedef struct Unk0209d3fc {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u8 mUnk_a0[0xc];
    /* ac */ u32 mUnk_ac;
    /* b0 */ u16 mUnk_b0;
    /* b2 */ u16 mUnk_b2;
    /* b4 */ u8 mUnk_b4[0x28];
    /* dc */ u32 mUnk_dc;
} Unk0209d3fc;

#include "Main/Unknown/code_02100094.h" // Unk02100094

extern u32 data_usa_021565d0;
extern u16 data_usa_021565d4;
extern const char data_usa_02167328[];

Unk0209bf70 *func_0209bf70(void *a, void *b, void *c, u32 d, u16 e, u16 f);
u32 func_0209bf8c(void);
void *func_0209bfa8(void *param_1, void *param_2, void *param_3, u32 param_4, u16 param_5);
BOOL func_0209bfe0(s32 a);
void func_0209c0d4(void);
void func_0209c0f4(void);
void func_0209c114(void);
void func_0209c134(void);
void func_0209c154(void);
void func_0209c198(void);
void func_0209c1dc(void);
void func_0209c220(Unk02100094 *a, Unk0209c220 *p);
s32 func_0209c4bc(s32 a, s32 b);
s16 func_0209c4d8(s32 a);
void func_0209c4f0(Unk02100094 *a);
void func_0209c5b8(Unk02100094 *a, Unk0209c220 *p);
void func_0209c678(Unk02100094 *a, Unk0209c220 *p);
void func_0209c738(void *a);
void func_0209c770(void *a);
void func_0209c7a8(Unk02100094 *a, Unk0209c220 *p);
BOOL func_0209c8b0(Unk0209c220 *p, Vec3 *a, s32 b, Vec3 *c);
u8 func_0209c964(Unk0209c220 *p, void *a, u8 *b, u8 *c);
s32 func_0209c9fc(Unk0209c220 *p, Unk0206bcb0 *k, u8 *b, u8 *c);
void func_0209cebc(Unk0209c220 *p);
void func_0209cef0(void);
void func_0209cf10(void);
void func_0209cf34(Unk02100094 *a, Unk0209cf34 *p);
void func_0209d394(Unk02100094 *a);
void func_0209d3fc(void *a, Unk0209d3fc *b);
