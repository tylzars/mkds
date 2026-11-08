#include "Main/Unknown/code_020dda38.h"
#include "Main/Unknown/code_020d3b10.h"

#include "Main/Unknown/code_020dda2c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02039860.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020de204.h"

u32 func_020de20c(u32 unused0, u32 unused1, u32 unused2, u32 bytePointer) {
    return (*OFFSET_PTR(const u8, bytePointer, 0));
}

u32 func_020de204(u32 unused0, u32 unused1, u32 unused2, u32 bytePointer) {
    return (*OFFSET_PTR(const u8, bytePointer, 0));
}

const u16 data_021583d4 = 1;

void ResetWanwanChainPoints(WanwanChainObject *chainObject) {
    Wanwan *wanwan;
    Vec3 startPoint;
    Vec3 endPoint;

    wanwan = chainObject->mWanwan;
    VEC_MultAdd(-wanwan->mUnk_f0, &wanwan->mUnk_00.mMatrix.mUnk_00[2], &wanwan->mUnk_00.mPos, &endPoint);
    startPoint = wanwan->mCenterPos;
    startPoint.y -= wanwan->mUnk_f0 >> 1;
    SetWanwanChainPointsEvenly(&chainObject->mChain, &startPoint, &endPoint);
    if (chainObject->mHasKui != FALSE) {
        return;
    }
    func_020dda2c(&chainObject->mChain);
}

#pragma thumb on

void CreateWanwanChainAndWanwanKui(void) {
    void *kuiFile;

    func_020e6488(&gWanwanChain, FindCourseMapObjFile("wanwan_chain.nsbmd"), 0, 0);
    func_020e6ab8(gWanwanChain);
    kuiFile = FindCourseFile("MapObj/wanwan_kui.nsbmd");
    if (kuiFile != NULL) {
        func_020e6488(&gWanwanKui, kuiFile, 0, 0);
        func_020e6ab8(gWanwanKui);
    }
}

void InitWanwanChainObject(WanwanChainObject *chainObject, void *unused, Wanwan *wanwan) {
    s32 d;

    chainObject->mPos = wanwan->mCenterPos;
    chainObject->mHasKui = wanwan->mUnk_fc == 0;
    if (chainObject->mHasKui != FALSE) {
        d = wanwan->mMaxRadius;
    } else {
        d = 0x55000;
    }
    InitWanwanChain(&chainObject->mChain, &chainObject->mPos, &chainObject->mPos, d - wanwan->mUnk_f0,
                    wanwan->mUnk_fc != 0 ? 4 : 7, 0x6000, &chainObject->mUnk_1c);
    if (chainObject->mHasKui == FALSE) {
        func_020dda2c(&chainObject->mChain);
        chainObject->mChain.mDownwardStep -= 0xcd;
        chainObject->mChain.mUnk_10 -= 0x3d;
        chainObject->mChain.mUnk_14.x += 0x52;
        chainObject->mChain.mUnk_14.y += 0x35c;
        chainObject->mChain.mUnk_14.z += 0x52;
        chainObject->mChain.mMinY = 0;
        chainObject->mUnk_02 |= data_021583d4;
    }
    chainObject->mWanwan = wanwan;
    if (chainObject->mHasKui != FALSE) {
        d = wanwan->mUnk_f8;
    } else {
        d = 0xc8000;
    }
    chainObject->mUnk_68 = 1.2f * (d + wanwan->mUnk_f0);
}

#pragma thumb off

void UpdateWanwanChainPoints(WanwanChain *chain, Vec3 *endPoint, Vec3 *unused) {
    Vec3 *velocities;
    s32 pointCount;
    s32 reversePointIndex;
    s32 pullIndex;
    s32 minY;
    Vec3 *points;
    s32 downwardStep;
    s32 damping;
    Vec3 t;
    Vec3 offset;
    Vec3 pullScale;
    Vec3 *current;
    s32 pointIndex;
    s32 linkLength;
    s32 weight;
    s32 excess;
    s64 excessSquared;

    velocities = chain->mVelocities;
    pointCount = chain->mPointCount;
    minY = chain->mMinY;
    points = chain->mPoints;
    downwardStep = chain->mDownwardStep;
    damping = chain->mUnk_10;
    pullScale = chain->mUnk_14;
    reversePointIndex = pointCount - 1;
    for (pointIndex = 1; pointIndex < pointCount; pointIndex++) {
        velocities[pointIndex].y -= downwardStep;
    }
    for (pointIndex = 1; pointIndex < pointCount; pointIndex++) {
        VEC_MultAdd((pointCount - pointIndex) * -damping, &velocities[pointIndex], &velocities[pointIndex],
                    &velocities[pointIndex]);
    }
    for (pointIndex = 1; pointIndex < pointCount; pointIndex++) {
        VEC_Add(&points[pointIndex], &velocities[pointIndex], &points[pointIndex]);
    }
    current = &points[reversePointIndex];
    *current = *endPoint;
    for (; reversePointIndex > 1; reversePointIndex--) {
        VEC_Subtract(&points[reversePointIndex - 1], current, &t);
        excessSquared = (s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z - chain->mLinkLengthSquared;
        excess = excessSquared < 0 ? 0 : (s32) (excessSquared >> 12);
        if (excess != 0) {
            Vec3NormalizeAndGetLengthUnchecked(&t, &offset);
            linkLength = chain->mLinkLength;
            offset.x = ((s64) offset.x * linkLength) >> 12;
            offset.y = ((s64) offset.y * linkLength) >> 12;
            offset.z = ((s64) offset.z * linkLength) >> 12;
            VEC_Add(current, &offset, &points[reversePointIndex - 1]);
            VEC_Subtract(&offset, &t, &t);
            t.x = ((s64) t.x * pullScale.x) >> 12;
            t.y = ((s64) t.y * pullScale.y) >> 12;
            t.z = ((s64) t.z * pullScale.z) >> 12;
            weight = chain->mStepFraction * reversePointIndex;
            t.x = ((s64) t.x * weight) >> 12;
            t.y = ((s64) t.y * weight) >> 12;
            t.z = ((s64) t.z * weight) >> 12;
            VEC_Add(&velocities[reversePointIndex - 1], &t, &velocities[reversePointIndex - 1]);
        }
        current--;
    }
    if (chain->mUnk_08 != 0) {
        pullIndex = 1;
    } else {
        pullIndex = 2;
    }
    for (; pullIndex < pointCount; pullIndex++) {
        VEC_Subtract(&points[pullIndex], &points[pullIndex - 1], &t);
        excessSquared = (s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z - chain->mLinkLengthSquared;
        excess = excessSquared < 0 ? 0 : (s32) (excessSquared >> 12);
        if (excess != 0) {
            Vec3NormalizeAndGetLengthUnchecked(&t, &offset);
            linkLength = chain->mLinkLength;
            offset.x = ((s64) offset.x * linkLength) >> 12;
            offset.y = ((s64) offset.y * linkLength) >> 12;
            offset.z = ((s64) offset.z * linkLength) >> 12;
            VEC_Add(&points[pullIndex - 1], &offset, &points[pullIndex]);
        }
    }
    for (pointIndex = 1; pointIndex < pointCount - 2; pointIndex++) {
        if (points[pointIndex].y - minY < 0) {
            points[pointIndex].y = minY;
            if (velocities[pointIndex].y < 0) {
                velocities[pointIndex].y = 0;
            }
            velocities[pointIndex].x = velocities[pointIndex].x * 7 >> 3;
            velocities[pointIndex].z = velocities[pointIndex].z * 7 >> 3;
        }
    }
}

void DrawWanwanChainLinks(WanwanChain *chain, NsbmdModel *model, s32 unused, u16 e) {
    s32 pointIndex;
    u32 polygonId;

    func_020e6a18(model);
    for (pointIndex = 1; pointIndex < chain->mPointCount; pointIndex++) {
        polygonId = AllocPolygonIdWrapping();
        model->mUnk_14 &= ~0x3f000000;
        model->mUnk_14 |= polygonId << 24;
        func_020e67c4(model, SetViewTransposeMatrixPos(&chain->mPoints[pointIndex]), &chain->mUnk_34, 1, e);
    }
}

void DrawWanwanChainKui(WanwanChain *chain, NsbmdModel *model, Vec3 *position, s32 unused, u16 e) {
    u32 polygonId;

    func_020e6a18(model);
    polygonId = AllocPolygonIdWrapping();
    model->mUnk_14 &= ~0x3f000000;
    model->mUnk_14 |= polygonId << 24;
    func_020e67c4(model, func_020e6cbc(position), &chain->mUnk_34, 1, e);
}
