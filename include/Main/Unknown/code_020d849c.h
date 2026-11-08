#pragma once

#include "types.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_02042044.h"

// Object of 0x38 bytes whose first 0x24 bytes are an Unk020e0144 (func_020d84e4, func_020d859c, ReverseGroupFollower).
typedef struct Unk020d84e4 {
    /* 00 */ Unk020e0144 mUnk_00;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk020d84e4;

// An Unk020e0144_00_0 (func_020d80e4 and func_020d91dc), then three words.
typedef struct SegmentProgress {
    /* 00 */ Unk020e0144_00_0 mUnk_00;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
} SegmentProgress;

void ReverseGroupFollower(Unk020e0144 *follower);
void func_020d859c(Unk020d84e4 *p, u16 entryValue, s32 entryIndex);
s32 func_020d84e4(Unk020d84e4 *p);
void SetSegmentProgressRate(SegmentProgress *segmentProgress, s32 a);
BOOL AdvanceSegmentProgress(SegmentProgress *segmentProgress);
