#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.
#include "Main/Unknown/code_0210bafc.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
typedef struct Unk0210b7a8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Vec3 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0210b7a8;

// Object of AdvanceSoundDistanceSquaredChange: a value at 0x00, the previous value at 0x04, their difference at 0x08
// and a shift at 0x0c.
typedef struct Unk0210b7ec {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0210b7ec;

extern Unk0210b7a8 data_0216c698;
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b610.h"
#include "Main/Unknown/code_0210b870.h"
