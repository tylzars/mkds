#pragma once

#include "types.h"
#include "00/code_02188720.h"

typedef struct NNSG3dResShpData NNSG3dResShpData;
typedef struct Unk02170500_04 Unk02170500_04;
typedef struct Unk02170500 Unk02170500;
typedef struct Unk020152bc Unk020152bc;

// Command buffer: the number of words stored from mUnk_04, then the words.
typedef struct Unk01ff9048 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04[1];
} Unk01ff9048;

void func_01ff8000(void);
void func_01ff8058(void);
void func_01ff81b4(Unk02170500 *s, u32 a);
void func_01ff8220(Unk02170500 *s, u32 a);
void func_01ff85d0(Unk02170500 *s, u32 a);
void func_01ff8648(Unk02170500 *s, u32 a, NNSG3dResShpData *c);
void func_01ff86b4(Unk02170500 *s, u32 a);
void func_01ff8738(Unk02170500 *s, u32 a, const u8 *e, u32 b);
void func_01ff8b08(Unk02170500 *s, u32 a);
void func_01ff8b98(Unk02170500 *s, u32 a);
void func_01ff8c98(Unk02170500 *s, u32 a);
void func_01ff8cc4(Unk02170500 *s, u32 a);
void func_01ff8cf0(void *a);
void func_01ff8dec(u32 *a, Unk020152bc *b);
void func_01ff8e64(Unk02170500 *s, Unk02170500_04 *i);
void func_01ff8ff8(Unk02170500 *s);
void func_01ff9048(u32 a, const void *b, u32 n);
void func_01ff9144(const void *a, u32 b);
void func_01ff9210(u32 *a);
void func_01ff921c(void);
void func_01ff9234(void);
Unk01ff9048 *func_01ff92b4(void);
void func_01ff92e0(Unk01ff9048 *a);

// Calls MIi_CpuClear32 with 0, passed through a stack offset of its own.
static inline void func_01ff8cf0_inline(u32 *p) {
    volatile u32 v = 0;
    MIi_CpuClear32(v, p, 8);
}
