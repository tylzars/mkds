#pragma once

#include "types.h"

typedef struct TextCanvas TextCanvas;

void func_02036264(void *dest, u32 size);
void func_02036278(void *dest, u32 fillValue, u32 size);
u32 func_0203629c(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void func_020362c4(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
void SetupWLMenuMBChildMessage(void *heap);
