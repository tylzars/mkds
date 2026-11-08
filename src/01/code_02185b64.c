#include "01/code_02185b64.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/callees_0219b000.h"
#include "01/code_02185ef4.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "ITCM/code_01ff8000.h"

Unk0219b250 *gMissionGate;

void InitMissionGate(MissionGateObject *missionGateObject) {
    s32 mtx[9];
    s32 sideExtentX;
    s32 sideExtentY;
    s16 saved;

    RefreshMapObjectMatrixFromHitNormal(missionGateObject);
    missionGateObject->mMapObject.mAngle =
        (missionGateObject->mMapObject.mCourseMapRow->mUnk_0c.y * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    MTX_RotY33_(mtx, gPairsByAngle[(missionGateObject->mMapObject.mAngle >> 4) * 2],
                gPairsByAngle[(missionGateObject->mMapObject.mAngle >> 4) * 2 + 1]);
    MTX_Concat33(mtx, &missionGateObject->mMapObject.mMatrix.mUnk_00[0].x,
                 &missionGateObject->mMapObject.mMatrix.mUnk_00[0].x);
    sideExtentX = (missionGateObject->mMapObject.mScale.x * 0xA000LL) >> 12;
    sideExtentY = (missionGateObject->mMapObject.mScale.y * 0xF000LL) >> 12;
    saved = missionGateObject->mMapObject.mCourseMapRow->mUnk_28;
    missionGateObject->mMapObject.mCourseMapRow->mUnk_28 = 0x12;
    missionGateObject->mNegativeSideObject = CreateMapObjectFromObject(&missionGateObject->mMapObject, 0x66);
    missionGateObject->mPositiveSideObject = CreateMapObjectFromObject(&missionGateObject->mMapObject, 0x66);
    missionGateObject->mMapObject.mCourseMapRow->mUnk_28 = saved;
    VEC_MultAdd(-(missionGateObject->mMapObject.mExtent.x + sideExtentX),
                &missionGateObject->mMapObject.mMatrix.mUnk_00[0], &missionGateObject->mMapObject.mPos,
                &missionGateObject->mNegativeSideObject->mPos);
    VEC_MultAdd(missionGateObject->mMapObject.mExtent.x + sideExtentX,
                &missionGateObject->mMapObject.mMatrix.mUnk_00[0], &missionGateObject->mMapObject.mPos,
                &missionGateObject->mPositiveSideObject->mPos);
    SetMapObjectExtentX(missionGateObject->mNegativeSideObject, sideExtentX);
    SetMapObjectExtentX(missionGateObject->mPositiveSideObject, sideExtentX);
    SetMapObjectExtentY(missionGateObject->mNegativeSideObject, sideExtentY);
    SetMapObjectExtentY(missionGateObject->mPositiveSideObject, sideExtentY);
}

u32 CollideKartWithMissionGate(MissionGateObject *missionGateObject, Unk02185d74 *kart, u8 *e, u8 *f) {
    u32 a = *e;
    u32 b = *f;

    if ((kart->mUnk_48 & 0x200) != 0 ||
        (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated(kart->mUnk_74) : 0) != FALSE) {
        return 0;
    }
    if (a == 1) {
        missionGateObject->mMapObject.mFlags |= data_ov001_021a6580;
        missionGateObject->mState = 2;
    }
    return b;
}

void LoadMissionGate(void *a) {
    gMissionGate = LoadMapObjectModelAnimated(a, "MissionGate.nsbmd");
    LoadMapObjectModelNsbtpAnimation(gMissionGate, "MissionGate.nsbtp");
    LoadMapObjectModelNsbmaAnimation(gMissionGate, "MissionGate.nsbma");
    SetMapObjectModelPolygonId(gMissionGate, 0x3f);
    func_0209ba08(gMissionGate, 2);
    SetNsbmdEmiAll(gMissionGate->mAnimatedModel, 0x294a);
}

void func_ov001_02185d18(void) {}

void DrawMissionGate(void *mapObjectList, MissionGateObject *missionGateObject) {
    s32 buf;

    buf = 0x1e;
    func_01ff9048(0x14, &buf, 1);
    missionGateObject->mMapObject.mMatrix.mUnk_00[3].x = missionGateObject->mMapObject.mPos.x >> 4;
    missionGateObject->mMapObject.mMatrix.mUnk_00[3].y = missionGateObject->mMapObject.mPos.y >> 4;
    missionGateObject->mMapObject.mMatrix.mUnk_00[3].z = missionGateObject->mMapObject.mPos.z >> 4;
    func_01ff9048(0x19, &missionGateObject->mMapObject.mMatrix, 0xc);
    func_01ff9048(0x1b, &missionGateObject->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gMissionGate, missionGateObject->mMapObject.mCourseMapRow->mUnk_28);
    SetMapObjectModelNsbmaFrameIndex(gMissionGate, missionGateObject->mNsbmaFrameIndex);
    DrawMapObjectModel(mapObjectList, gMissionGate, missionGateObject);
}

void InitMissionGateObjects(MissionGateList *missionGateList) {
    s32 i;
    MissionGateObject *missionGateObject;

    if (missionGateList) {
        for (i = 0; i < missionGateList->mObjectCount && (missionGateObject = missionGateList->mObjects[i]) != NULL;
             i++) {
            if (missionGateObject->mMapObject.mCourseMapRow->mUnk_28 != 0) {
                missionGateObject->mMapObject.mFlags |= data_ov001_021a6580;
                missionGateObject->mState = 0;
            } else {
                missionGateObject->mMapObject.mFlags &= ~1;
                missionGateObject->mState = 1;
            }
        }
    }
}

void UpdateMissionGate(void *a, MissionGateObject *missionGateObject) {
    s32 count;

    switch (missionGateObject->mState) {
        case 0:
            count = gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            if (count >= missionGateObject->mMapObject.mCourseMapRow->mUnk_28 - 1) {
                missionGateObject->mMapObject.mFlags &= ~1;
                missionGateObject->mState = 1;
            }
            break;
        case 2:
            count = GetMapObjectModelNsbmaFrameCount(gMissionGate);
            missionGateObject->mNsbmaFrameIndex++;
            if (missionGateObject->mNsbmaFrameIndex >= count - 1) {
                missionGateObject->mNsbmaFrameIndex = GetMapObjectModelNsbmaFrameCount(gMissionGate) - 1;
                missionGateObject->mState = 1;
            }
            break;
    }
}

void CreateMissionGateKindData(void) {
    CreateMapObjectKindData(&CollideKartWithMissionGate, NULL, NULL, 0, 1);
}

void CreateMissionGateDrawList(void) {
    CreateMapObjectDrawList1(LoadMissionGate, DrawMissionGate, func_ov001_02185d18);
}

void CreateMissionGateUpdateList(void) {
    CreateMapObjectUpdateList(InitMissionGateObjects, UpdateMissionGate, NULL);
}
