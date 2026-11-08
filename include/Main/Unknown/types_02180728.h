#pragma once

#include "types.h"

// Four words set up by func_ov001_02180728.
typedef struct TextCanvas {
    /* 00 */ void *mCharCanvas;
    /* 04 */ void *mFont;
    /* 08 */ s32 mCharSpacing;
    /* 0c */ s32 mLineSpacing;
} TextCanvas;
