#pragma once

#include "types.h"
#include "03/unk_021da000.h"

u32 StartBlendBrightnessFadeWait(u16 frameCount);
void AdvanceBlendBrightnessFade(u32 task, BlendBrightnessFadeSlot *slot);
u32 StartBlendBrightnessFade(s32 kind, s32 screen, u32 plane, u16 frameCount);
