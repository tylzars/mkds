#pragma once

#include "types.h"

typedef struct MapObjectFlagsView {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} MapObjectFlagsView;

void EnterMkdEfBubbleState1(MapObjectFlagsView *bubble);
