#pragma once

#include "types.h"

struct Unk020e71a0_94;

// The four words of data_0216ca48, read as one 16-byte object.
typedef struct Unk0216ca48 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0216ca48;

#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0

extern Unk0216ca48 data_0216ca48;

void func_0210b870(void);
void func_0210b874(struct Unk020e71a0_94 *p, s32 b);
int func_0210b8bc(void *p, s32 b);
void func_0210b8f4(void *p, s32 b);
void func_0210b924(void *p, s32 b);
void func_0210b98c(struct Unk020e71a0_94 *p, s32 b);
void func_0210ba38(struct Unk020e71a0_94 *p, s32 b);
void func_0210ba78(void *p0, s32 b);
u32 func_0210bac0(void);
