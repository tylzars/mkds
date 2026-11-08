#pragma once

#include "types.h"

void AdvanceSelectReturnState1(void);
void AdvanceSelectReturnState0(void);
void SetSelectReturnPaletteBits(s32 paletteKind);
s32 LoadSelectReturn(s32 subCharOffset);
void InitSelectReturnDisplay(void);
