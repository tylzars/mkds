#pragma once

#include "types.h"

typedef struct Unk0218dc94 Unk0218dc94;

typedef s32 UnkCompare(const void *a, const void *b);

// 0x18 bytes. Growable array: count, capacity, element size, growth step, per-element callback, element data.
typedef struct Unk0218dc94 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void (*mUnk_10)(void *);
    /* 14 */ u8 *mUnk_14;
} Unk0218dc94;

void *func_ov000_0218d818(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e, s32 *f);
void *func_ov000_0218d86c(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e);
void func_ov000_0218d8b4(Unk0218dc94 *a);
void *func_ov000_0218d8dc(Unk0218dc94 *a, UnkCompare *b, const void *c);
void func_ov000_0218d938(Unk0218dc94 *a, UnkCompare *b, const void *c);
s32 func_ov000_0218d980(Unk0218dc94 *a, const void *b, UnkCompare *c, s32 d, s32 e);
void func_ov000_0218da04(unsigned int p0, unsigned int p1);
void func_ov000_0218da1c(Unk0218dc94 *a, const void *b, s32 c);
void func_ov000_0218da5c(Unk0218dc94 *a, s32 b);
void func_ov000_0218da9c(Unk0218dc94 *a, int b);
void func_ov000_0218daf8(Unk0218dc94 *a, void *b, UnkCompare *c);
void func_ov000_0218db48(void *param_1, void *param_2, s32 param_3);
void func_ov000_0218dbc0(void *param_1, void *param_2);
void *func_ov000_0218dbf8(void *param_1, s32 param_2);
s32 func_ov000_0218dc44(void *b);
void func_ov000_0218dc48(void *c);
void *func_ov000_0218dc94(s32 b, s32 c, void (*d)(void *));
void func_ov000_0218dd18(Unk0218dc94 *a, const void *b, s32 c);
void func_ov000_0218dd38(Unk0218dc94 *a);
void func_ov000_0218dd74(void *b, s32 c);
