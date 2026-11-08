#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d8cac.h"

void ReverseGroupFollower(GroupFollower *follower) {
    CourseMapGroupEntry *savedEntry = follower->mFromEntry;
    follower->mFromEntry = follower->mToEntry;
    follower->mToEntry = savedEntry;
    follower->mForward = follower->mForward == 0;
}

void SetupGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower, u16 entryIndex, s32 forward) {
    s32 entryValue;
    s32 speed;
    SetupGroupFollowerAtEntry(&follower->mUnk_00, entryIndex, forward);
    entryValue = follower->mUnk_00.mFromEntry->mUnk_0e;
    follower->mFromSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    follower->mUnk_30 = follower->mFromSpeed;
    entryValue = follower->mUnk_00.mToEntry->mUnk_0e;
    follower->mToSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    speed = follower->mUnk_30;
    follower->mUnk_00.mSpeed = speed;
    follower->mUnk_00.mProgressStep =
        ((s64) speed * follower->mUnk_00.mPath->mSegments[follower->mUnk_00.mSegmentIndex].mInverseProgressLength) >>
        12;
}

s32 AdvanceGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower) {
    s32 crossedEnd;
    s32 entryValue;
    s32 blend;
    s32 speed;
    crossedEnd = AdvanceGroupFollower(&follower->mUnk_00);
    if (crossedEnd != 0) {
        follower->mFromSpeed = follower->mToSpeed;
        entryValue = follower->mUnk_00.mToEntry->mUnk_0e;
        follower->mToSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    }
    if (follower->mFromSpeed != follower->mToSpeed) {
        blend = GetGroupFollowerProgress(&follower->mUnk_00);
        speed = (s32) (((s64) follower->mFromSpeed * (0x1000 - blend)) >> 12) +
                (s32) (((s64) follower->mToSpeed * blend) >> 12);
        follower->mUnk_00.mSpeed = speed;
        follower->mUnk_00.mProgressStep =
            ((s64) speed *
             follower->mUnk_00.mPath->mSegments[follower->mUnk_00.mSegmentIndex].mInverseProgressLength) >>
            12;
    }
    return crossedEnd;
}

void SetSegmentProgressRate(SegmentProgress *segmentProgress, s32 a) {
    s32 inverseLength = segmentProgress->mUnk_00.mInverseProgressLength;
    segmentProgress->mUnk_54 = a;
    a = inverseLength != 0 ? (s32) (((s64) a * inverseLength) >> 12) : 0x1000000;
    segmentProgress->mUnk_58 = a;
}

BOOL AdvanceSegmentProgress(SegmentProgress *segmentProgress) {
    segmentProgress->mUnk_5c = segmentProgress->mUnk_5c + segmentProgress->mUnk_58;
    return segmentProgress->mUnk_5c >= 0x1000000;
}
