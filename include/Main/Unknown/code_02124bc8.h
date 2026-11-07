#pragma once

#include "types.h"

typedef struct Unk02124b1c Unk02124b1c;

typedef struct Unk02021dc8 Unk02021dc8;

typedef struct Unk0201ea30 Unk0201ea30;

void DrawLayoutTableEntry(s32 index, Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout,
                          void *oamList, Unk02124b1c *table);
