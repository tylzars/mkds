#pragma once

#include "types.h"
#include "code_0213ee6c.h"

// 16 bytes. Filled by func_0213e468 from the text after a '%', read by func_0213cae0 and passed by value
// (one word in r3, three on the stack) to func_0213d398, func_0213deec and func_0213e1f0. Byte 0x05 is never accessed.
typedef struct Unk0213d398 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0213d398;

// u16 table indexed by characters below 0x80; func_0213e468 tests bit 3, func_0213d398 bit 9.
extern const u16 data_0215d384[];

int func_0213cae0(void *(*a)(void *, const u16 *, u32), void *b, const u16 *c, char *d);
u16 *func_0213d398(double v, u16 *end, Unk0213d398 s);
void func_0213dcd4(Unk02136638 *a, int k);
u16 *func_0213deec(u64 v, u16 *end, Unk0213d398 s);
u16 *func_0213e1f0(unsigned long v, u16 *end, Unk0213d398 s);
const u16 *func_0213e468(const u16 *a, char **b, Unk0213d398 *c);
