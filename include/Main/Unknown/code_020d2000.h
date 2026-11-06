#pragma once

#include "types.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020f36d8.h"

// 0x2bc bytes.
typedef struct MapObjects {
    /* 000 */ MapObject **mMapObjects;
    // Pinned at 0xff when the 0x100-pointer array is full.
    /* 004 */ vu16 mMapObjectCount;
    /* 006 */ u8 mUnk_006[2];
    /* 008 */ Unk020e6fd4 *mDrawLists[24];
    /* 068 */ Unk020e6fd4 *mUnk_068[24];
    /* 0c8 */ Unk020e6fd4 *mUnk_0c8[24];
    /* 128 */ u16 mDrawListCount;
    /* 12a */ u16 mUnk_12a;
    /* 12c */ u16 mUnk_12c;
    /* 12e */ u8 mUnk_12e[2];
    /* 130 */ BOOL mUnk_130;
    /* 134 */ Unk020e6fd4 *mUpdateLists[16];
    /* 174 */ u16 mUpdateListCount;
    /* 176 */ u8 mUnk_176[2];
    /* 178 */ BOOL mUnk_178;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ s32 mUnk_180;
    /* 184 */ s32 mUnk_184;
    /* 188 */ s32 mUnk_188;
    /* 18c */ ItemObject mUnk_18c;
    /* 2b8 */ s32 mRunUpdateLists;
} MapObjects;

// Declared here until the code that defines them is decompiled.
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d2c2c.h"
#include "Main/Unknown/code_020d24d8.h"
