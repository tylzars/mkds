#pragma once

#include "types.h"

typedef struct Unk020e6488 Unk020e6488;
typedef struct ItemTeresa ItemTeresa;

// Row of the table behind data_0215a190.
typedef struct Unk0215a190 {
    /* 00 */ u8 mUnk_00[0xc];
} Unk0215a190;

extern Unk0215a190 data_0215a190[];

void DrawItemTeresa(ItemTeresa *p, s32 c, Unk020e6488 *q);
void func_021003e8(ItemTeresa *p, u32 sel, s32 value);
void InitItemTeresaFromData(ItemTeresa *p);
void func_021004c4(void *p, ItemTeresa *a, void *b);
void func_0210050c(ItemTeresa *p);
void UpdateItemTeresaState6(ItemTeresa *p);
