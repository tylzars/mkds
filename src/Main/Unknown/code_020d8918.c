#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e005c.h"
#include "code_02147cd8.h"

void func_020d8b18(Unk020e0144 *follower, Vec3 *position, Vec3 *step) {
    func_020d9270(&follower->mUnk_00->mUnk_00[follower->mUnk_0c], follower->mUnk_14, follower->mUnk_10, position, step);
    if (follower->mUnk_18 == 0) {
        step->x = -step->x;
        step->z = -step->z;
    }
}

void GetGroupFollowerLinearPosition(Unk020e0144 *follower, Vec3 *position) {
    Unk020e0144_00_0 *segment;
    s32 progress;
    s32 remaining;
    segment = &follower->mUnk_00->mUnk_00[follower->mUnk_0c];
    progress = follower->mUnk_14;
    remaining = 0x1000000 - progress;
    position->x = ((s64) segment->mUnk_00[0].x * remaining) >> 24;
    position->y = ((s64) segment->mUnk_00[0].y * remaining) >> 24;
    position->z = ((s64) segment->mUnk_00[0].z * remaining) >> 24;
    position->x = position->x + (s32) (((s64) segment->mUnk_00[3].x * progress) >> 24);
    position->y = position->y + (s32) (((s64) segment->mUnk_00[3].y * progress) >> 24);
    position->z = position->z + (s32) (((s64) segment->mUnk_00[3].z * progress) >> 24);
}

void func_020d8918(Unk020e0144 *follower, Vec3 *position, Vec3 *step) {
    Unk020e0144_00_0 *segment;
    s32 progress;
    s32 remaining;
    s32 rate;
    segment = &follower->mUnk_00->mUnk_00[follower->mUnk_0c];
    progress = follower->mUnk_14;
    remaining = 0x1000000 - progress;
    position->x = ((s64) segment->mUnk_00[0].x * remaining) >> 24;
    position->y = ((s64) segment->mUnk_00[0].y * remaining) >> 24;
    position->z = ((s64) segment->mUnk_00[0].z * remaining) >> 24;
    position->x = position->x + (s32) (((s64) segment->mUnk_00[3].x * progress) >> 24);
    position->y = position->y + (s32) (((s64) segment->mUnk_00[3].y * progress) >> 24);
    position->z = position->z + (s32) (((s64) segment->mUnk_00[3].z * progress) >> 24);
    VEC_Subtract(&segment->mUnk_00[3], &segment->mUnk_00[0], step);
    rate = follower->mUnk_10;
    step->x = ((s64) step->x * rate) >> 24;
    step->y = ((s64) step->y * rate) >> 24;
    step->z = ((s64) step->z * rate) >> 24;
    if (follower->mUnk_18 == 0) {
        step->x = -step->x;
        step->y = -step->y;
        step->z = -step->z;
    }
}
