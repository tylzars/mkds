#pragma once

#include "types.h"
#include "code_0213ee6c.h" // Unk02136638

// 16 bytes. Filled by func_0213770c; func_021352e0 passes it by value (moved as four words) to
// func_02135c80, func_02136850, func_02136f14 and func_02137358.
typedef struct Unk021352e0 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk021352e0;

// Strings passed to strcpy by func_02135c80 and func_02136850.
extern u8 data_0216ee80[];
extern u8 data_0216ee88[];
extern u8 data_0216ee90[];
extern u8 data_0216ee94[];
extern u8 data_0216ee98[];
extern u8 data_0216eea0[];
extern u8 data_0216eea8[];
extern u8 data_0216eeac[];
// String passed to strcpy by func_02136850.
extern u8 data_0216eeb0[];

int func_021352e0(void *(*f)(void *, const u8 *, u32), void *a, const u8 *b, char *c);
u8 *func_02135c80(double v, u8 *end, Unk021352e0 spec);
void func_02136638(Unk02136638 *a, int k);
u8 *func_02136850(double v, u8 *end, Unk021352e0 spec);
u8 *func_02136f14(u64 v, u8 *end, Unk021352e0 spec);
u8 *func_02137358(unsigned long v, u8 *end, Unk021352e0 spec);
const u8 *func_0213770c(const u8 *p, char **b, Unk021352e0 *buf);
