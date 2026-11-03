#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_020d22c0.h"

// Object behind gWiFiVSCourseSelect, 0x158 bytes (InitWiFiVSCourseSelect allocates it).
typedef struct Unk02174e28 {
    /* 000 */ Unk02174e60_00 mUnk_000[2];
    /* 048 */ Unk02174e14_00 mUnk_048;
    /* 064 */ Unk02174e14_00 mUnk_064;
    /* 080 */ void *mUnk_080[2];
    /* 088 */ void *mUnk_088;
    /* 08c */ void *mUnk_08c;
    /* 090 */ void *mUnk_090;
    /* 094 */ Unk020f41c4_B mUnk_094;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc[4];
    /* 0cc */ Unk02025ebc mUnk_0cc[3];
    /* 0fc */ Unk02025ebc mUnk_0fc[4];
    /* 13c */ s32 mUnk_13c;
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mUnk_148;
    /* 14c */ u16 mUnk_14c[4];
    /* 154 */ s16 mUnk_154;
} Unk02174e28;

void func_0202a820(void);
void func_0202a90c(void);
