#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct ItemFBox ItemFBox;

// Element of the two tables data_0217c200 and data_0217be00: 0x14 bytes of
// bytes passed on followed by three words.
typedef struct Unk0217be00 {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0217be00;

extern Unk0217be00 data_0217c200[];

extern Unk0217be00 data_0217be00[];

u8 *func_020ff2b0(u8 *a, ItemFBox *b, void *c);
void func_020ff25c(ItemFBox *a);
void func_020ff1d8(void);
void func_020ff1b8(s32 a, s32 *p);
void func_020ff1a0(s32 a, s32 *p);
s32 func_020ff178(ItemObject *p);
u8 *func_020ff0b0(u8 *a, Vec3 *b, Vec3 *q, void *c);
u8 *func_020ff040(u8 *a, void *b, void *c);
u8 *func_020fefe8(u8 *a, s32 *b, void *c);
u8 *func_020fecdc(u8 *a, void *b, void *c);
void func_020fec30(void);
void func_020feb44(void);
void func_020fea84(u32 a, u32 b, void *c, u8 d);
void func_020fe9d0(u32 a, u32 b, s32 c, void *d, u32 e);
u8 *func_020fe958(u32 a);
u8 *func_020fe8ac(u32 a);
u8 *func_020fe828(u32 a);
u8 *func_020fe7a0(u32 a, u32 b, u32 c, u32 d);
u8 *func_020fe71c(u32 a, u32 b, u32 c);
u8 *func_020fe694(u32 a, u32 b, u32 c, u32 d);
void func_020fe5b8(u32 a, u32 b, u8 *c, u32 d);
void func_020fe56c(u32 a, u32 b, u32 c, void *d, u32 e);
void *func_020fe4c0(void *a, void *b, s32 c);
void func_020fe4b4(void *p);
