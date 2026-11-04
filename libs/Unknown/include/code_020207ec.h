#pragma once

#include "types.h"

// PxiCommandEnqueue takes an PxiCommand from PxiCommandAlloc, stores its five arguments in mUnk_04 to mUnk_14 and
// passes it to PxiCommandPendingAppend. The functions after it pass a fixed first argument to PxiCommandEnqueue,
// func_02020870 or func_020208a4.
void PxiCommandEnqueue(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_02020844(u32 a);
void func_02020870(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_020208a4(u32 a, u32 b, u32 c, u32 d);
void func_020208d8(void);
void func_02020904(u32 a);
void func_02020930(u32 a, u32 b, u32 c, u32 d);
void func_02020964(u32 a);
void func_02020990(void *a, void *b);
void func_020209bc(void *a, void *b);
void func_020209e8(void *a, void *b);
void func_02020a14(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
void func_02020a6c(u32 a, u32 b, u32 c);
void func_02020aa0(u32 a, u32 b);
void func_02020acc(u32 a, u32 b);
void func_02020af8(u32 a, u32 b, u32 c);
void func_02020b2c(s32 a, u32 b, u32 c, UnkFunc *d, void *e);
void func_02020b70(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_02020bbc(u32 a, u32 b, u32 c, u32 d);
void func_02020c2c(u32 a, u32 b, u32 c, u32 d);
void func_02020c60(u32 a, u32 b, u32 c);
void func_02020c94(u32 a, u32 b, u32 c);
void func_02020cbc(u32 a, u32 b, u32 c);
void func_02020ce4(u32 a, u32 b, u32 c);
void func_02020d0c(u32 a, u32 b, u32 c);
void func_02020d34(u32 a, u32 b, u32 c);
void func_02020d68(u32 a, u32 b);
void func_02020d80(u32 a, u32 b);
void func_02020d98(u32 a, u32 b);
void func_02020db0(u32 a);
void func_02020ddc(u32 a, u32 b, u32 c, u32 d);
void func_02020e10(u32 a);
