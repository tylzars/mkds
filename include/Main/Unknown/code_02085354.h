#pragma once

#include "types.h"

typedef struct NNSG3dResMdl NNSG3dResMdl;

// Object whose pointer at 0x04 is passed to NNS_G3dDraw1Mat1Shp.
typedef struct Unk02085360 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ NNSG3dResMdl *mUnk_04;
} Unk02085360;

void func_02085354(void *a);
void func_02085360(Unk02085360 *a);
