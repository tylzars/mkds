#pragma once

#include "types.h"
#include "code_0212f788.h" // Interpolator

// 0x44 bytes; sixteen of them in data_0217d45c. Most functions take a pointer to a pointer to one.
typedef struct Unk0212c400 {
    /* 00 */ struct Unk0212c400 **mUnk_00;
    /* 04 */ struct Unk0212c7a0 *mUnk_04;
    /* 08 */ struct Unk0212c700 *mUnk_08;
    /* 0c */ u8 mUnk_0c[0x10];
    /* 1c */ Interpolator mUnk_1c;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d;
    /* 2e */ u8 mUnk_2e;
    /* 2f */ u8 mUnk_2f;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36[2];
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ u8 mUnk_3c;
    /* 3d */ u8 mUnk_3d;
    /* 3e */ s16 mUnk_3e;
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41;
    /* 42 */ u8 mUnk_42[2];
} Unk0212c400;

#include "code_0212d214.h"

// Memory func_0212c700 gets from HeapStackAlloc: mUnk_08 is the HeapStack it sets up on mUnk_14, mUnk_10 the index
// of the data_0217d89c element whose list receives it.
typedef struct Unk0212c700 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ HeapStack *mUnk_08;
    /* 0c */ Unk0212c400 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14[1];
} Unk0212c700;

#include "code_0212c7a0.h" // Unk0212c7a0

extern LinkedList data_0217d444;
extern LinkedList data_0217d450;

void func_0212bcac(Unk0212c400 *p, u32 b);
void func_0212bd10(Unk0212c700 *p);
void func_0212bd6c(Unk0212c400 *p);
Unk0212c400 *func_0212bdfc(s32 a);
void func_0212be78(Unk0212c400 *p);
void func_0212beb4(Unk0212c400 *p);
void func_0212bf14(Unk0212c7a0 *e, Unk0212c400 *p);
void func_0212bf70(Unk0212c400 *p);
HeapStack *func_0212bfbc(u32 a, Unk0212c400 *b);
void func_0212c018(Unk0212c400 *p, u32 b);
void func_0212c078(Unk0212c400 *a, void *b, u32 c, void *d);
void func_0212c0d4(void *a);
Unk0212c400 *func_0212c0e0(Unk0212c400 **a, s32 b, s32 c);
void func_0212c19c(void);
void func_0212c310(void);
u32 func_0212c3c8(Unk0212c400 **a, u32 b, u32 c);
u32 func_0212c400(Unk0212c400 **a, u32 b, s16 *c);
u32 func_0212c450(Unk0212c400 **arg0, u32 arg1, u32 arg2);
void func_0212c478(Unk0212c400 **a, u32 b);
void func_0212c494(Unk0212c400 **a, u32 b);
void func_0212c4c4(Unk0212c400 **a, u32 b, u32 c);
u32 func_0212c4f4(Unk0212c400 **a, u32 b, u32 c);
void func_0212c524(Unk0212c400 **a, u32 b, u32 c);
void func_0212c554(Unk0212c400 **a, u32 b, u32 c);
void func_0212c594(Unk0212c400 **a, u32 b, u32 c);
void func_0212c5c4(Unk0212c400 **a, u32 b);
void func_0212c5f4(Unk0212c400 **a, u32 b);
void func_0212c620(Unk0212c400 **a, s32 b, s32 c);
u32 func_0212c668(Unk0212c400 **arg0, u32 arg1);
Unk0212c400 *func_0212c678(Unk0212c400 **arg0, u32 arg1);
void func_0212c688(Unk0212c400 **a);
void func_0212c6a0(Unk0212c400 **arg0);
void func_0212c6ac(u32 a);
u32 func_0212c6f0(Unk0212c400 **a, u32 b);
s32 func_0212c700(u32 a, HeapStack *b, u32 c);
