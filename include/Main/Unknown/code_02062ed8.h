#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart, UnkVec16
#include "Main/Unknown/code_020846c0.h" // Unk02084b2c

// Object at data_usa_0217aafc: two Unk02084b2c pointers, then the words and halfwords the code tests.
typedef struct Unk0217aafc {
    /* 00 */ Unk02084b2c *mUnk_00;
    /* 04 */ Unk02084b2c *mUnk_04;
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
} Unk0217aafc;

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

extern Unk0217aafc data_usa_0217aafc;
extern u8 data_usa_0217ab04[];
extern u8 data_0217ab5c[];
extern u8 data_usa_0217ab74[];
extern Unk02012f58 data_usa_0217abac;

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
void func_02062ef8(u32 a);
void func_0206302c(void);
void func_020631b0(void);
void func_02063228(void);
void func_0206326c(void);
void func_02063294(void);
void func_0206331c(void *a);
void func_020636f8(Kart *a);
void func_020637c4(Kart *a);
void func_020637e0(Kart *a);
void func_02063830(Kart *a);
void func_02063880(Kart *a);
