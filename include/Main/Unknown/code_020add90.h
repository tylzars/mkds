#pragma once

#include "types.h"

typedef struct Unk02022aa8 Unk02022aa8;

u32 GetFontGlyphIndex(Unk02022aa8 *font, u32 code);
void FillHalfwords(void *destination, u16 value, s32 size);
