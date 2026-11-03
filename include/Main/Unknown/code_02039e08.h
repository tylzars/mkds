#pragma once

#include "types.h"

typedef struct Unk020487fc Unk020487fc;
typedef struct Unk020176c0 Unk020176c0;

// Object whose halfword at 0x04 func_0203a0dc and func_0203a520 write.
typedef struct Unk0203a0dc {
    /* 00 */ u8 mUnk_00[0x4];
    /* 04 */ u16 mUnk_04;
} Unk0203a0dc;

void func_02044940(void);
void func_0204465c(void);
void func_02037850(void);
u32 func_0203afe4(u32 a);
u32 func_0203a9ec(u32 a);
u32 func_0203a908(u32 a);

u32 func_02039e08(Unk020176c0 *a, void **b, void **c, void **d, void **e, void **f);
u32 func_02039eec(Unk020487fc *a);
void func_02039f34(void);
void func_02039f50(void);
void func_02039f5c(void);
void func_02039f90(void);
u32 func_02039f9c(Unk020487fc *a);
void func_0203a050(void);
void func_0203a05c(void);
void func_0203a0dc(Unk0203a0dc *a, u32 b);
