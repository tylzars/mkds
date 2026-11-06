#pragma once

#include "types.h"

typedef struct Unk021274ec {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk021274ec;

void ClearTxtSystemCanvasInUse(void);
s32 InitTxtSystem(void *b, Unk021274ec *c);
