#pragma once

#include "types.h"

typedef struct Unk021b916c Unk021b916c;
typedef struct Unk021b86e4 Unk021b86e4;

typedef struct Unk021b807c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk021b807c;

typedef struct Unk021b8340 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u8 mUnk_04[1];
} Unk021b8340;

typedef struct Unk021b82e0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ s8 mUnk_0e;
    /* 0f */ s8 mUnk_0f;
    /* 10 */ u8 mUnk_10[8];
} Unk021b82e0;

typedef struct Unk021b839c {
    /* 00 */ s8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[1];
} Unk021b839c;

typedef struct Unk021b858c {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 pad_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[1];
} Unk021b858c;

typedef struct Unk021b8498 {
    /* 00 */ s8 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u8 mUnk_06[8];
} Unk021b8498;

extern u8 data_ov003_021d7c88[2];
extern u8 data_ov003_021d7c8a[];
extern s8 data_ov003_021d6868[];
extern s32 data_ov003_021d7c40;

u32 func_ov003_021b807c(Unk021b807c *p);
void func_ov003_021b80c4(Unk021b807c *p, u8 *dst, const u8 *src, u32 n);
void func_ov003_021b80f4(Unk021b807c *p, const u8 *key, u32 keyLength, u32 n);
s32 func_ov003_021b8160(const u8 *a, u8 *b, s32 c, u32 d, const u8 *e, const u8 *f, s32 g);
s32 func_ov003_021b81f4(const u8 *a, u8 *b, s32 c, s8 *d, u8 *e, const u8 *f, s32 g);
s32 func_ov003_021b8278(void *a, s32 b, u32 c, s32 d);
void func_ov003_021b82e0(void *p, s32 b, s32 c, s32 d, s8 e, s8 f, const u8 *g);
void func_ov003_021b8340(s32 a, void *b, const void *c, s16 *d, s16 *e, s8 *f);
s16 func_ov003_021b839c(void *a);
s32 func_ov003_021b8428(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 func_ov003_021b8498(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 func_ov003_021b858c(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 func_ov003_021b86e4(s32 mode, Unk021b86e4 *buf, Unk021b916c *list, s32 id);
