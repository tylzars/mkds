#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d8cac.h"

void ReverseGroupFollower(Unk020e0144 *follower) {
    Unk02042044 *savedEntry = follower->mUnk_1c;
    follower->mUnk_1c = follower->mUnk_20;
    follower->mUnk_20 = savedEntry;
    follower->mUnk_18 = follower->mUnk_18 == 0;
}

void func_020d859c(Unk020d84e4 *p, u16 entryIndex, s32 forward) {
    s32 entryValue;
    s32 speed;
    func_020d90a8(&p->mUnk_00, entryIndex, forward);
    entryValue = p->mUnk_00.mUnk_1c->mUnk_0e;
    p->mUnk_2c = entryValue != 0 ? p->mUnk_24 * entryValue : p->mUnk_28;
    p->mUnk_30 = p->mUnk_2c;
    entryValue = p->mUnk_00.mUnk_20->mUnk_0e;
    p->mUnk_34 = entryValue != 0 ? p->mUnk_24 * entryValue : p->mUnk_28;
    speed = p->mUnk_30;
    p->mUnk_00.mUnk_04 = speed;
    p->mUnk_00.mUnk_10 = ((s64) speed * p->mUnk_00.mUnk_00->mUnk_00[p->mUnk_00.mUnk_0c].mUnk_34) >> 12;
}

s32 func_020d84e4(Unk020d84e4 *p) {
    s32 crossedEnd;
    s32 entryValue;
    s32 blend;
    s32 speed;
    crossedEnd = func_020d8cc8(&p->mUnk_00);
    if (crossedEnd != 0) {
        p->mUnk_2c = p->mUnk_34;
        entryValue = p->mUnk_00.mUnk_20->mUnk_0e;
        p->mUnk_34 = entryValue != 0 ? p->mUnk_24 * entryValue : p->mUnk_28;
    }
    if (p->mUnk_2c != p->mUnk_34) {
        blend = func_020d8cac(&p->mUnk_00);
        speed = (s32) (((s64) p->mUnk_2c * (0x1000 - blend)) >> 12) + (s32) (((s64) p->mUnk_34 * blend) >> 12);
        p->mUnk_00.mUnk_04 = speed;
        p->mUnk_00.mUnk_10 = ((s64) speed * p->mUnk_00.mUnk_00->mUnk_00[p->mUnk_00.mUnk_0c].mUnk_34) >> 12;
    }
    return crossedEnd;
}

void SetSegmentProgressRate(SegmentProgress *segmentProgress, s32 a) {
    s32 t = segmentProgress->mUnk_00.mUnk_34;
    segmentProgress->mUnk_54 = a;
    a = t != 0 ? (s32) (((s64) a * t) >> 12) : 0x1000000;
    segmentProgress->mUnk_58 = a;
}

BOOL AdvanceSegmentProgress(SegmentProgress *segmentProgress) {
    segmentProgress->mUnk_5c = segmentProgress->mUnk_5c + segmentProgress->mUnk_58;
    return segmentProgress->mUnk_5c >= 0x1000000;
}
