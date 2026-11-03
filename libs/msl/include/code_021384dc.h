#pragma once

#include "types.h"
#include "code_0213a460.h"

// 0x28 bytes. Filled by func_02139400 from the text at its first argument, starting from a local copy with every
// byte zero and mUnk_04 = 0x7fffffff; func_02138618 reads mUnk_08 one bit per byte value.
typedef struct Unk02139400 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[32];
} Unk02139400;

u32 rand(void);
int sscanf(const char *a, const char *b, ...);
int vsscanf(const char *a, const char *b, char *c);
int func_021385a0(void *a, int b, int c);
int func_02138618(Unk02138618Func f, void *a, const char *s, char *b);
const char *func_02139400(const char *a, Unk02139400 *b);
