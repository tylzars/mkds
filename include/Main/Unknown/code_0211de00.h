#pragma once

#include "types.h"

typedef struct Unk0201ea30 Unk0201ea30;

typedef struct Unk02021dc8 Unk02021dc8;

void QueueSelectCupNameM(u32 nameIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, u32 d, u32 e);
void CreateSelectCupNameM(void *heap);
void LoadSelectCupNameMData(void);
void QueueCupMark(u32 cupMarkIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, u32 d, u16 paletteSlot, s32 f);
void ClearCupMarkPointer(void);
