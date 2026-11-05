#pragma once

#include "types.h"

typedef struct Unk02180728 Unk02180728;

typedef void Unk020ade08_f(u16 *a, s32 b, s32 c, s32 d);

typedef struct Unk02175628_48 Unk02175628_48;

// Four halfwords passed by value to func_020ae244.
typedef struct Unk020ae244 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk020ae244;

typedef struct Unk02175628_48 Unk02175628_48;

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn);

typedef struct Unk02175628 Unk02175628;

extern u32 data_02168024[];

void func_020ade08(const u16 *a, u16 *b, s32 c, s32 d, Unk020ade08_f *e);
void func_020adec0(u16 *a, s32 b, s32 c, s32 d);
void func_020adf00(u32 a);
void func_020adfb0(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f);
void func_020adfd8(Unk02180728 *a, void *b, void *c, s32 d, s32 e);
void func_020adff0(u32 a, u16 *b, u32 c);
int func_020ae0ac(int arg0);
u32 func_020ae114(u32 a);
u32 func_020ae15c(u32 arg0);
u32 func_020ae244(u32 a, Unk020ae244 b);
u32 func_020ae290(u32 a);
u32 func_020ae2b0(Unk02175628_48 *a);
u32 func_020ae2e4(Unk02175628_48 *a);
u32 func_020ae308(Unk02175628_48 *a);
unsigned int func_020ae338(Unk02175628_48 *p0);
u32 func_020ae3a4(s32 a, s32 b);
u32 func_020ae3b4(u32 a);
u16 func_020ae428(u32 a, u32 b);
u16 func_020ae444(Unk02175628 *a, u32 b);
u16 func_020ae458(u32 a, u32 b);
u16 func_020ae474(Unk02175628 *a, u32 b);
s16 func_020ae488(s32 a);
s16 func_020ae4c0(s32 a, s16 b, s16 c, s32 d, s32 e);
s32 func_020ae54c(s32 a);
s32 func_020ae554(s32 a, s32 b);
s16 func_020ae564(s32 a);
s32 func_020ae584(s32 a);
u16 func_020ae5c4(void *a);
