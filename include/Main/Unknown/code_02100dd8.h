#pragma once

#include "types.h"

typedef struct Unk02100dd8 {
    /* 00 */ u8 mUnk_00[0x19c];
    /* 19c */ u32 mUnk_19c;
} Unk02100dd8;

void EnterItemTeresaState3(Unk02100dd8 *p0);
