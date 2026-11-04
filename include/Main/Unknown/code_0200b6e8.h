#pragma once

#include "types.h"
#include "Main/Unknown/code_02008934.h"

// Block the callback behind mUnk_05dc receives from func_0200b850.
typedef struct Unk0200b850 {
    /* 00 */ u16 mUnk_00;
    /* 04 */ Unk02008934 *mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0200b850;

// Block the callback behind mUnk_05dc receives from func_0200b820.
typedef struct Unk0200b820 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk0200b820;

#include "code_02142eac.h"

// Object behind data_0216fde8; the members are the ones the code reads.
typedef struct Unk0216fde8 {
    /* 0000 */ u8 mUnk_0000[0x20];
    /* 0020 */ u8 mUnk_0020[0x480];
    /* 04a0 */ u8 mUnk_04a0[0x20];
    /* 04c0 */ u8 mUnk_04c0[0xc0];
    /* 0580 */ Unk02143a78 mUnk_0580;
    /* 0590 */ u8 mUnk_0590[0x10];
    /* 05a0 */ u8 mUnk_05a0[0x24];
    /* 05c4 */ u8 mUnk_05c4[0x18];
    /* 05dc */ void (*mUnk_05dc)(u32, void *);
    /* 05e0 */ void (*mUnk_05e0)(u32, void *);
    /* 05e4 */ u32 mUnk_05e4;
    /* 05e8 */ u8 mUnk_05e8[0x5ee - 0x5e8];
    /* 05ee */ u16 mUnk_05ee;
    /* 05f0 */ u8 mUnk_05f0[0x5ef8 - 0x5f0];
    /* 5ef8 */ u32 mUnk_5ef8;
    /* 5efc */ u32 mUnk_5efc;
    /* 5f00 */ u32 mUnk_5f00;
    /* 5f04 */ u32 mUnk_5f04;
    /* 5f08 */ u32 mUnk_5f08;
    /* 5f0c */ u16 mUnk_5f0c;
    /* 5f0e */ u16 mUnk_5f0e;
} Unk0216fde8;

extern u8 data_usa_02152be4[6];

void func_0200b6e8(void);
void func_0200b70c(void);
u32 func_0200b72c(void);
void func_0200b794(u32 a, void *b, u32 c);
u32 func_0200b7cc(void);
void func_0200b7e0(const u8 *a);
void func_0200b820(u16 a, u16 b);
void func_0200b850(u32 a, Unk02008934 *b, u32 c);
void func_0200b894(Unk021425e8 *a);
void func_0200b934(void);
void func_0200b9e0(UnkFunc *a, u32 b);
void func_0200ba44(u32 a, u32 b);
void func_0200ba84(UnkFunc *p0);
unsigned int func_0200baa8(void);
void func_0200bab0(void);
