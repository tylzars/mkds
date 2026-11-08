#pragma once

#include "types.h"

typedef struct Unk0209f124 {
    /* 00 */ u8 mUnk_00[0xa4];
    /* a4 */ BOOL mPictureIndex;
} Unk0209f124;

void InitPicture2(Unk0209f124 *p0);
void InitPicture1(Unk0209f124 *p0);
