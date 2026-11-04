#pragma once

#include "types.h"

// 8 bytes, moved one byte at a time.
typedef struct Unk0218e3c4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[6];
} Unk0218e3c4;

// Object func_ov000_021a8f84 returns; mUnk_0c points at a table of pointers to a word.
typedef struct Unk021a8f84 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ s16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ u32 **mUnk_0c;
} Unk021a8f84;

// 8 bytes: descriptor, requested events and returned events.
typedef struct Unk0218e68c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk0218e68c;

extern u8 data_ov000_021b4e04[];
extern s32 data_ov000_021b4e08;
extern Unk021a8f84 data_ov000_021b4e0c;
extern u32 data_ov000_021b4e1c;
extern u32 *data_ov000_021b4e30[2];

u32 func_ov000_0218e2dc(u32 param_1);
u32 func_ov000_0218e320(u32 *param_1);
u32 func_ov000_0218e368(s32 a);
u32 func_ov000_0218e374(u32 a);
s32 func_ov000_0218e394(u32 p0, void *p1, u32 *p2);
u32 func_ov000_0218e3b8(s32 a, s32 b, s32 c, void *d, s32 e);
s32 func_ov000_0218e3c4(s32 param_1, s32 param_2, s32 param_3, void *param_4, s32 *param_5);
s32 func_ov000_0218e3e4(s32 param_1, void *param_2, s32 param_3, s32 param_4, void *param_5, s32 param_6);
s32 func_ov000_0218e420(s32 param_1, void *param_2, s32 param_3, s32 param_4);
s32 func_ov000_0218e438(s32 param_1, void *param_2, s32 param_3, s32 param_4, void *param_5, s32 *param_6);
s32 func_ov000_0218e460(s32 param_1, void *param_2, s32 param_3, s32 param_4);
s32 func_ov000_0218e478(s32 param_1, void *param_2, s32 *param_3);
s32 func_ov000_0218e49c();
s32 func_ov000_0218e4b4(s32 b, void *c, s32 d);
s32 func_ov000_0218e4e4(s32 c, void *d, s32 e);
s32 func_ov000_0218e524(s32 descriptor, s32 a);
s32 func_ov000_0218e53c(s32 descriptor);
s32 func_ov000_0218e554(s32 domain, s32 type, s32 protocol);
s32 func_ov000_0218e56c(s32 result, s32 fallback);
BOOL func_ov000_0218e57c(u32 *e);
Unk021a8f84 *func_ov000_0218e5e4(void);
u32 func_ov000_0218e644(u32 a);
u32 func_ov000_0218e668(u32 a);
s32 func_ov000_0218e68c(s32 c, u32 *d, u32 *e, u32 *f);
s32 func_ov000_0218e74c(s32 d);
s32 func_ov000_0218e77c(s32 d);
s32 func_ov000_0218e7ac(s32 a, u32 b);
s32 func_ov000_0218e7dc(s32 a, u32 b);
BOOL func_ov000_0218e80c(s32 a, s32 b);
s8 *func_ov000_0218e850(s8 *a);
void *func_ov000_0218e880(const char *a);
void func_ov000_0218e8b4(void);
void func_ov000_0218e8b8(void);
void func_ov000_0218e8bc(u32 arg0);
u32 func_ov000_0218e8c4(void);
