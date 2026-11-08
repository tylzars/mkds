#pragma once

#include "types.h"

typedef struct BlendBrightnessFadeSlot {
    /* 00 */ u32 mTask;
    /* 04 */ s16 mFrames;
    /* 06 */ u16 mFrameCount;
    /* 08 */ u8 mKind;
    /* 09 */ u8 mEnabled;
} BlendBrightnessFadeSlot;

void AdvanceBlendBrightnessFadeWait(u32 task, BlendBrightnessFadeSlot *state);
