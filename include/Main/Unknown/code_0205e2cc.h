#pragma once

#include "types.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02114158.h"

// 0xb04 bytes: a signed byte at 0x00 and, from 0x04, an Unk0217aa08_24.
typedef struct Unk0205ec14 {
    /* 00 */ s8 mUnk_00;
    /* 01 */ u8 mUnk_01[3];
    /* 04 */ Unk0217aa08_24 mUnk_04;
} Unk0205ec14;

void func_0205e2cc(void *a);
s32 func_0205e4e4(Unk020487fc *a);
void func_0205e518(u32 a);
void func_0205e520(void);
void func_0205e528(void);
void func_0205e530(void);
u8 func_0205e548(void);
void func_0205e5c4(s32 a);
void func_0205e67c(void);
void func_0205e900(void);
void func_0205ec14(Unk0205ec14 *a, u8 b);
BOOL func_0205eca4(Unk0205ec14 *a, u8 b, Unk021141c8 *c);
Unk0205ec14 *func_0205eda0(void *a);
