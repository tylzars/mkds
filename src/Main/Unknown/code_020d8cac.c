#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_02042044.h"

void func_020d9270(Unk020e0144_00_0 *segment, s32 fraction, s32 scale, Vec3 *firstResult, Vec3 *secondResult) {
    s32 firstWeight0;
    s32 firstWeight1;
    s32 firstWeight2;
    s32 firstWeight3;
    s32 secondWeight0;
    s32 secondWeight1;
    s32 secondWeight2;
    s32 secondWeight3;
    func_020d970c(fraction, &firstWeight0, &firstWeight1, &firstWeight2, &firstWeight3, &secondWeight0, &secondWeight1,
                  &secondWeight2, &secondWeight3);
    func_020d94dc(segment->mUnk_00, firstResult, firstWeight0, firstWeight1, firstWeight2, firstWeight3);
    func_020d94dc(segment->mUnk_00, secondResult, secondWeight0, secondWeight1, secondWeight2, secondWeight3);
    secondResult->x = ((s64) secondResult->x * scale) >> 24;
    secondResult->z = ((s64) secondResult->z * scale) >> 24;
}

void func_020d91dc(Unk020e0144_00_0 *segment, s32 fraction, Vec3 *result) {
    s32 weight0;
    s32 weight1;
    s32 weight2;
    s32 weight3;
    func_020d9810(fraction, &weight0, &weight1, &weight2, &weight3);
    func_020d94dc(segment->mUnk_00, result, weight0, weight1, weight2, weight3);
    result->y = ((s64) segment->mUnk_00[0].y * (0x1000000 - fraction)) >> 24;
    result->y = result->y + (s32) (((s64) segment->mUnk_00[3].y * fraction) >> 24);
}

void func_020d90a8(Unk020e0144 *follower, u16 entryIndex, s32 ascending) {
    Unk020e0144_00 *path;
    u16 currentIndex;
    u16 nextIndex;
    s32 speedScale;
    path = follower->mUnk_00;
    if (path->mUnk_08 != 0) {
        if (entryIndex == 0 && ascending == 0) {
            entryIndex = path->mUnk_04;
        }
    } else if (entryIndex == 0 && ascending == 0) {
        ascending = 1;
    } else if (entryIndex == path->mUnk_04) {
        if (ascending != 0) {
            ascending = 0;
        }
    }
    follower->mUnk_0c = ascending != 0 ? entryIndex : entryIndex - 1;
    speedScale = path->mUnk_00[follower->mUnk_0c].mUnk_34;
    follower->mUnk_10 = speedScale != 0 ? (s32) (((s64) follower->mUnk_04 * speedScale) >> 12) : 0x1000000;
    follower->mUnk_14 = ascending != 0 ? 0 : 0x1000000;
    follower->mUnk_18 = ascending;
    currentIndex = entryIndex;
    if (follower->mUnk_18 == 0 && path->mUnk_08 != 0 && entryIndex == path->mUnk_04) {
        currentIndex = 0;
    }
    follower->mUnk_1c = GetCourseMapGroupEntry(follower->mUnk_08, currentIndex);
    nextIndex = follower->mUnk_18 != 0 ? entryIndex + 1 : entryIndex - 1;
    if (follower->mUnk_18 != 0 && path->mUnk_08 != 0 && nextIndex == path->mUnk_04) {
        nextIndex = 0;
    }
    follower->mUnk_20 = GetCourseMapGroupEntry(follower->mUnk_08, nextIndex);
}

BOOL func_020d8cc8(Unk020e0144 *follower) {
    Unk020e0144_00 *path;
    s32 speedScale;
    s32 segmentIndex;
    path = follower->mUnk_00;
    if (follower->mUnk_18 != 0) {
        follower->mUnk_14 = follower->mUnk_14 + follower->mUnk_10;
        if (follower->mUnk_14 >= 0x1000000) {
            if (follower->mUnk_0c == path->mUnk_04 - 1) {
                if (path->mUnk_08 != 0) {
                    follower->mUnk_14 -= 0x1000000;
                    follower->mUnk_14 = ((s64) follower->mUnk_14 * path->mUnk_00[follower->mUnk_0c].mUnk_30) >> 12;
                    follower->mUnk_0c = 0;
                    follower->mUnk_1c = follower->mUnk_20;
                    follower->mUnk_20 = GetCourseMapGroupEntry(follower->mUnk_08, 1);
                    speedScale = path->mUnk_00[follower->mUnk_0c].mUnk_34;
                    if (speedScale != 0) {
                        follower->mUnk_14 = ((s64) follower->mUnk_14 * speedScale) >> 24;
                    }
                    follower->mUnk_10 =
                        speedScale != 0 ? (s32) (((s64) follower->mUnk_04 * speedScale) >> 12) : 0x1000000;
                } else {
                    follower->mUnk_18 = 0;
                    follower->mUnk_14 = 0x1000000;
                    follower->mUnk_1c = follower->mUnk_20;
                    follower->mUnk_20 = GetCourseMapGroupEntry(follower->mUnk_08, follower->mUnk_0c);
                }
            } else {
                follower->mUnk_14 -= 0x1000000;
                follower->mUnk_14 = ((s64) follower->mUnk_14 * path->mUnk_00[follower->mUnk_0c].mUnk_30) >> 12;
                follower->mUnk_0c = follower->mUnk_0c + 1;
                follower->mUnk_1c = follower->mUnk_20;
                if (follower->mUnk_0c == path->mUnk_04 - 1 && path->mUnk_08 != 0) {
                    follower->mUnk_20 = GetCourseMapGroupEntry(follower->mUnk_08, 0);
                } else {
                    follower->mUnk_20 = GetCourseMapGroupEntry(follower->mUnk_08, follower->mUnk_0c + 1);
                }
                speedScale = path->mUnk_00[follower->mUnk_0c].mUnk_34;
                if (speedScale != 0) {
                    follower->mUnk_14 = ((s64) follower->mUnk_14 * speedScale) >> 24;
                }
                follower->mUnk_10 = speedScale != 0 ? (s32) (((s64) follower->mUnk_04 * speedScale) >> 12) : 0x1000000;
            }
            return TRUE;
        }
    } else {
        follower->mUnk_14 = follower->mUnk_14 - follower->mUnk_10;
        if (follower->mUnk_14 <= 0) {
            segmentIndex = follower->mUnk_0c;
            if (segmentIndex == 0) {
                if (path->mUnk_08 != 0) {
                    follower->mUnk_14 = ((s64) follower->mUnk_14 * path->mUnk_00[segmentIndex].mUnk_30) >> 12;
                    follower->mUnk_0c = path->mUnk_04 - 1;
                    follower->mUnk_1c = follower->mUnk_20;
                    follower->mUnk_20 = GetCourseMapGroupEntry(follower->mUnk_08, path->mUnk_04 - 1);
                    speedScale = path->mUnk_00[follower->mUnk_0c].mUnk_34;
                    if (speedScale != 0) {
                        follower->mUnk_14 = ((s64) follower->mUnk_14 * speedScale) >> 24;
                    }
                    follower->mUnk_14 = follower->mUnk_14 + 0x1000000;
                    follower->mUnk_10 =
                        speedScale != 0 ? (s32) (((s64) follower->mUnk_04 * speedScale) >> 12) : 0x1000000;
                } else {
                    follower->mUnk_18 = 1;
                    follower->mUnk_14 = 0;
                    follower->mUnk_1c = follower->mUnk_20;
                    follower->mUnk_20 = GetCourseMapGroupEntry(follower->mUnk_08, 1);
                }
            } else {
                follower->mUnk_14 = ((s64) follower->mUnk_14 * path->mUnk_00[segmentIndex].mUnk_30) >> 12;
                follower->mUnk_0c = follower->mUnk_0c - 1;
                follower->mUnk_1c = follower->mUnk_20;
                follower->mUnk_20 = GetCourseMapGroupEntry(follower->mUnk_08, follower->mUnk_0c);
                speedScale = path->mUnk_00[follower->mUnk_0c].mUnk_34;
                if (speedScale != 0) {
                    follower->mUnk_14 = ((s64) follower->mUnk_14 * speedScale) >> 24;
                }
                follower->mUnk_14 = follower->mUnk_14 + 0x1000000;
                follower->mUnk_10 = speedScale != 0 ? (s32) (((s64) follower->mUnk_04 * speedScale) >> 12) : 0x1000000;
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_020d8cac(Unk020e0144 *follower) {
    s32 progress;
    if (follower->mUnk_18 != 0) {
        progress = follower->mUnk_14;
    } else {
        progress = 0x1000000 - follower->mUnk_14;
    }
    return progress >> 12;
}
