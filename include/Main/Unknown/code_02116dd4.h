#pragma once

#include "types.h"

typedef struct Unk0201ea30 Unk0201ea30;

typedef struct Unk02021dc8 Unk02021dc8;

void CreateWait(void *heap, Unk02021dc8 *destinationNcer, Unk0201ea30 *destinationBncl, u32 destinationBnclIndex,
                u16 paletteIndex, u32 f);
void LoadWaitData(void);
