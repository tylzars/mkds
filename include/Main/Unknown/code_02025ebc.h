#pragma once

#include "types.h"

// 0x10-byte object passed to func_02025ebc, func_02025edc and func_02025f14.
typedef struct Unk02025ebc {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
} Unk02025ebc;

s16 func_02025ebc(Unk02025ebc *a);
