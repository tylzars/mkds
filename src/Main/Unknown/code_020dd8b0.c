#include "Main/Unknown/code_020dd8b0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147cd8.h"

#pragma thumb on

const Vec3 data_021583c8 = {0x100, 0x400, 0x100};

void InitWanwanChain(WanwanChain *chain, Vec3 *start, Vec3 *end, s32 length, s32 pointCount, s32 e, Vec3 *f) {
    s32 segmentCount;
    void *heap;

    chain->mLength = length;
    chain->mPointCount = pointCount;
    heap = GetHeap(GetCurrentHeapCall());
    chain->mPoints = HeapAlloc(heap, pointCount * 12);
    heap = GetHeap(GetCurrentHeapCall());
    chain->mVelocities = HeapAlloc(heap, pointCount * 12);
    chain->mUnk_34 = *f;
    chain->mUnk_40 = ((s64) e * f->y) >> 12;
    segmentCount = pointCount - 1;
    chain->mStepFraction = 0x1000 / segmentCount;
    chain->mLinkLength = (s32) (((s64) length * 0x119a) >> 12) / segmentCount;
    chain->mLinkLengthSquared = (s64) chain->mLinkLength * chain->mLinkLength;
    SetWanwanChainPointsEvenly(chain, start, end);
    chain->mMinY = start->y + chain->mUnk_40;
    chain->mDownwardStep = 0x599;
    chain->mUnk_10 = 0x51;
    chain->mUnk_14 = data_021583c8;
    chain->mUnk_08 = 1;
}

void SetWanwanChainPointsEvenly(WanwanChain *chain, Vec3 *start, Vec3 *end) {
    Vec3 step;
    Vec3 *zeroedPoints;
    s32 index;
    s32 stepFraction;

    VEC_Subtract(end, start, &step);
    stepFraction = chain->mStepFraction;
    step.x = ((s64) step.x * stepFraction) >> 12;
    step.y = ((s64) step.y * stepFraction) >> 12;
    step.z = ((s64) step.z * stepFraction) >> 12;
    *chain->mPoints = *start;
    zeroedPoints = chain->mVelocities;
    zeroedPoints->x = 0;
    zeroedPoints->y = 0;
    zeroedPoints->z = 0;
    for (index = 1; index < chain->mPointCount; index++) {
        VEC_Add(&chain->mPoints[index - 1], &step, &chain->mPoints[index]);
        zeroedPoints = chain->mVelocities;
        zeroedPoints[index].x = 0;
        zeroedPoints[index].y = 0;
        zeroedPoints[index].z = 0;
    }
}

#pragma thumb off
