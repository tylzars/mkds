#pragma once

#include "types.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_02042044.h"

// Object of 0x38 bytes whose first 0x24 bytes are an GroupFollower (AdvanceGroupFollowerWithSpeeds,
// SetupGroupFollowerWithSpeeds, ReverseGroupFollower).
typedef struct GroupFollowerWithSpeeds {
    /* 00 */ GroupFollower mUnk_00;
    /* 24 */ s32 mSpeedPerEntryUnit;
    /* 28 */ s32 mDefaultSpeed;
    /* 2c */ s32 mFromSpeed;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mToSpeed;
} GroupFollowerWithSpeeds;

// An Segment (BuildSegment and GetSegmentCurveXzLinearY), then three words.
typedef struct SegmentProgress {
    /* 00 */ Segment mUnk_00;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
} SegmentProgress;

void ReverseGroupFollower(GroupFollower *follower);
void SetupGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower, u16 entryValue, s32 entryIndex);
s32 AdvanceGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower);
void SetSegmentProgressRate(SegmentProgress *segmentProgress, s32 a);
BOOL AdvanceSegmentProgress(SegmentProgress *segmentProgress);
