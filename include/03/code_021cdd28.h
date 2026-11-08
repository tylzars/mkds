#pragma once

#include "types.h"

typedef struct TaskEntry TaskEntry;

typedef struct Unk021cdd48_66a8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk021cdd48_66a8;

typedef struct Unk021d1770 Unk021d1770;

typedef struct Unk021ce0f0 {
    /* 00 */ Unk021d1770 *mUnk_00[5];
    /* 14 */ u32 mTask;
    /* 18 */ u8 mUnk_18;
} Unk021ce0f0;

extern Unk021cdd48_66a8 data_ov003_021d66a8[];

u32 func_ov003_021cdd28(void);
void func_ov003_021cdd48(TaskEntry *a);
void func_ov003_021cddd0(TaskEntry *a);
void func_ov003_021cde68(TaskEntry *a);
void func_ov003_021cdf00(TaskEntry *a);
void func_ov003_021cdf98(TaskEntry *a);
u32 func_ov003_021ce00c(void);
void func_ov003_021ce024(u32 a);
void func_ov003_021ce0c4(void);
void func_ov003_021ce0f0(u32 task);
