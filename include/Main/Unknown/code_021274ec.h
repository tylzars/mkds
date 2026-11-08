#pragma once

#include "types.h"

typedef struct TxtSystemArgs {
    /* 00 */ u32 mFont;
    /* 04 */ u32 mUseCanvas1;
    /* 08 */ u32 mUseCanvas2;
    /* 0c */ u32 mUseCanvas3;
    /* 10 */ s32 mSubCharOffset;
} TxtSystemArgs;

void ClearTxtSystemCanvasInUse(void);
s32 InitTxtSystem(void *heap, TxtSystemArgs *args);
