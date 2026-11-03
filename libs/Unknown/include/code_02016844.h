#pragma once

#include "types.h"

typedef struct Unk02016638 Unk02016638;

// Object at data_02173220: a pointer to an array of Unk02016638, its length at 04, two indices at 08 and 0a that
// func_02016978 advances modulo the length, and a count at 0c (func_02016960 compares it with the length,
// func_0201694c tests it for zero).
typedef struct Unk02016468 {
    /* 00 */ Unk02016638 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 10 */ u32 mUnk_10;
} Unk02016468;

void func_02016844(const void *a, u32 b, u32 c);
void func_02016850(const void *a, u32 b, u32 c);
void func_0201685c(const void *a, u32 b, u32 c);
void func_02016868(const void *a, u32 b, u32 c);
void func_02016874(const void *a, u32 b, u32 c);
void func_02016880(const void *a, u32 b, u32 c);
void func_0201688c(const void *a, u32 b, u32 c);
void func_020168bc(const void *a, u32 b, u32 c);
void func_020168ec(const void *a, u32 b, u32 c);
void func_0201691c(const void *a, u32 b, u32 c);
s32 func_0201694c(Unk02016468 *p);
s32 func_02016960(Unk02016468 *p);
u16 func_02016978(Unk02016468 *p, u32 v);
