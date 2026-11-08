#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;
typedef struct ItemTeresa ItemTeresa;

// Row of the table behind data_0215a190.
typedef struct Unk0215a190 {
    /* 00 */ u8 mUnk_00[0xc];
} Unk0215a190;

extern Unk0215a190 data_0215a190[];

void DrawItemTeresa(ItemTeresa *teresa, s32 c, NsbmdModel *model);
void func_021003e8(ItemTeresa *teresa, u32 sel, s32 value);
void InitItemTeresaFromData(ItemTeresa *teresa);
void func_021004c4(void *cursor, ItemTeresa *teresa, void *toData);
void func_0210050c(ItemTeresa *teresa);
void UpdateItemTeresaState6(ItemTeresa *teresa);
