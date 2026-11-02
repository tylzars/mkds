#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_02100de4.h"

// Row of the table behind data_0215a190.
typedef struct Unk0215a190 {
    /* 00 */ u8 mUnk_00[0xc];
} Unk0215a190;

extern Unk0215a190 data_0215a190[];

void func_021001ac(Unk02101c84 *p, s32 c, Unk020e6488 *q);
void func_021003e8(Unk02101c84 *p, u32 sel, s32 value);
void func_0210045c(Unk02101c84 *p);
void func_021004c4(void *p, Unk02101c84 *a, void *b);
void func_0210050c(Unk02101c84 *p);
void func_02100564(Unk02101c84 *p);
