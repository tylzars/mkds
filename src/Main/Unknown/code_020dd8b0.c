#include "Main/Unknown/code_020dd8b0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147cd8.h"

#pragma thumb on

const Vec3 data_021583c8 = {0x100, 0x400, 0x100};

void InitWanwanChain(Unk020dd950 *chain, Vec3 *start, Vec3 *end, s32 length, s32 pointCount, s32 e, Vec3 *f) {
    s32 segmentCount;
    void *heap;

    chain->mUnk_00 = length;
    chain->mUnk_20 = pointCount;
    heap = GetHeap(GetCurrentHeapCall());
    chain->mUnk_44 = HeapAlloc(heap, pointCount * 12);
    heap = GetHeap(GetCurrentHeapCall());
    chain->mUnk_48 = HeapAlloc(heap, pointCount * 12);
    chain->mUnk_34 = *f;
    chain->mUnk_40 = ((s64) e * f->y) >> 12;
    segmentCount = pointCount - 1;
    chain->mUnk_24 = 0x1000 / segmentCount;
    chain->mUnk_28 = (s32) (((s64) length * 0x119a) >> 12) / segmentCount;
    chain->mUnk_2c = (s64) chain->mUnk_28 * chain->mUnk_28;
    SetWanwanChainPointsEvenly(chain, start, end);
    chain->mUnk_0c = start->y + chain->mUnk_40;
    chain->mUnk_04 = 0x599;
    chain->mUnk_10 = 0x51;
    chain->mUnk_14 = data_021583c8;
    chain->mUnk_08 = 1;
}

void SetWanwanChainPointsEvenly(Unk020dd950 *chain, Vec3 *start, Vec3 *end) {
    Vec3 step;
    Vec3 *zeroedPoints;
    s32 index;
    s32 stepFraction;

    VEC_Subtract(end, start, &step);
    stepFraction = chain->mUnk_24;
    step.x = ((s64) step.x * stepFraction) >> 12;
    step.y = ((s64) step.y * stepFraction) >> 12;
    step.z = ((s64) step.z * stepFraction) >> 12;
    *chain->mUnk_44 = *start;
    zeroedPoints = chain->mUnk_48;
    zeroedPoints->x = 0;
    zeroedPoints->y = 0;
    zeroedPoints->z = 0;
    for (index = 1; index < chain->mUnk_20; index++) {
        VEC_Add(&chain->mUnk_44[index - 1], &step, &chain->mUnk_44[index]);
        zeroedPoints = chain->mUnk_48;
        zeroedPoints[index].x = 0;
        zeroedPoints[index].y = 0;
        zeroedPoints[index].z = 0;
    }
}

#pragma thumb off
