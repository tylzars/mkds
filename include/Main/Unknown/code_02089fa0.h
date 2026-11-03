#pragma once

#include "types.h"
#include "Main/Unknown/code_020846c0.h" // Unk02084b2c
#include "Main/Unknown/code_02087d0c.h" // Unk02087d0c
#include "Main/Unknown/unk_02155000.h" // Unk02155ee8

// 0x14 bytes: a table of 0x6c-byte objects at 0x00, three tables of 0x38-byte objects at 0x04, 0x08 and 0x0c, and the
// number of entries of the first table at 0x10.
typedef struct Unk0208a69c {
    /* 00 */ Unk02084b2c *mNsbmds;
    /* 04 */ Unk02087d0c *mNsbcaNsbmaNsbtp[3];
    /* 10 */ u16 mNsbmdCount;
} Unk0208a69c;

void func_02089fa0(void);
void func_0208a218(void);
void func_0208a31c(s32 a);
void func_0208a460(void *a);
void InitNsbmdNsbcaNsbmaNsbtp(void *a, Unk0208a69c *b, const Unk02155ee8 *c, u16 d);
void func_0208aa30(void *a);
