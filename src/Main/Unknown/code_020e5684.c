#include "Main/Unknown/code_020e5684.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020e57f4.h"
#include "Main/Unknown/code_020e57fc.h"
#include "Main/Unknown/code_020e5850.h"
#include "Main/Unknown/code_020e5854.h"
#include "Main/Unknown/code_020e58b8.h"
#include "Main/Unknown/code_020e58c4.h"
#include "Main/Unknown/code_020e58fc.h"
#include "Main/Unknown/code_020e5900.h"
#include "Main/Unknown/code_020e5950.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ec000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e5b88.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_020e5c6c.h"

void DrawObPakkunSf(u32 a, Unk020e43a8 *obPakkunSf, u32 c, u16 alpha) {
    MtxFx43 *matrix;
    gObPakkunSf->mFrameIndex = ((*(u16 *) &obPakkunSf->mUnk_a0.mUnk_18.x & 0x10) >> 4);
    if (obPakkunSf->mUnk_00.mStateMachine.mState == 0) {
        matrix = func_020e6cbc(&obPakkunSf->mUnk_00.mPos);
        func_020e67c4(gObPakkunSf, matrix, &obPakkunSf->mUnk_00.mScale, 0, alpha);
        return;
    }
    matrix = func_020e6cbc(&obPakkunSf->mUnk_00.mPos);
    func_020e66e4(gObPakkunSf, matrix, *(u16 *) &obPakkunSf->mUnk_a0.mUnk_0c.x, &obPakkunSf->mUnk_00.mScale, 0, alpha);
}

void UpdateObPakkunSf(u32 a, Unk020e43a8 *obPakkunSf) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;

    *(u16 *) &obPakkunSf->mUnk_a0.mUnk_18 = *(u16 *) &obPakkunSf->mUnk_a0.mUnk_18 + 1;
    if ((*(u16 *) &obPakkunSf->mUnk_a0.mUnk_18 & 0x1f) == 0 &&
        (obPakkunSf->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
        if (obPakkunSf->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
            falloffIndex = 2;
        } else if (obPakkunSf->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x163;
        soundRequest.mPositionSource = &obPakkunSf->mUnk_00.mPos;
        soundRequest.mUnk_08 = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&obPakkunSf->mUnk_00.mPos);
        func_0210b7a8(&soundRequest);
    }
    AdvanceStateMachine(&obPakkunSf->mUnk_00.mStateMachine);
}

u8 CollideKartWithObPakkunSf(Unk020e43a8 *obPakkunSf, void *kart, u8 *b, u8 *c) {
    if (func_020ec450(obPakkunSf, kart, b) != FALSE) {
        StartSoundIfKartStarOrKiller(&obPakkunSf->mUnk_00, kart);
    }
    return *c;
}

u8 CollideItemObjectWithObPakkunSf(Unk020e43a8 *obPakkunSf, void *itemObject, u8 *b, u8 *c) {
    func_020ec41c(obPakkunSf, itemObject, b);
    return *c;
}

#pragma thumb on

void CreateObPakkunSf(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = FindCourseMapObjFile(gObPakkunSfNsbmdName);
    nsbtpFile = FindCourseMapObjFile(gObPakkunSfNsbtpName);
    func_020e6488((NsbmdModel **) (((u32 *) &gObPakkunSf)), nsbmdFile, nsbtpFile, 0);
    func_020e6ab8(gObPakkunSf);
}

#pragma thumb off

#pragma thumb on

void InitObPakkunSf(Unk020e43a8 *obPakkunSf) {
    obPakkunSf->mUnk_00.mPos.y =
        obPakkunSf->mUnk_00.mPos.y + (s32) (((s64) obPakkunSf->mUnk_00.mScale.y * 0xa000) >> 12);
    *(u16 *) &obPakkunSf->mUnk_a0.mUnk_18.x = 0;
    InitPushedMotion(obPakkunSf, obPakkunSf->mUnk_00.mPos.y - 0x18000, 0x400, 0x800, 0x4000, 0x1800);
    InitPushedObjectStates(obPakkunSf);
}

#pragma thumb off

Unk020e5a9c *CreateSecondHandKindData(void) {
    Unk020e5a9c *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = *(Unk020e5a9c *) data_02159140;
    return kindData;
}

Unk020e5a40 *CreateSecondHandDrawList(void) {
    Unk020e5a40 *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217b824 = drawList;
    *drawList = *(Unk020e5a40 *) data_02159114;
    func_020d49d8(&data_0217b824);
    return data_0217b824;
}

Unk020e59e4 *CreateSecondHandUpdateList(void) {
    Unk020e59e4 *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b81c = updateList;
    *updateList = *(Unk020e59e4 *) data_021590ec;
    SetUpdateListSlot(&data_0217b81c);
    return data_0217b81c;
}

void DrawSecondHand(u32 a, Unk020e43a8 *secondHand, u32 b, u32 alpha) {
    secondHand->mUnk_00.mMatrix.mUnk_00[3].x = secondHand->mUnk_00.mPos.x >> 4;
    secondHand->mUnk_00.mMatrix.mUnk_00[3].y = secondHand->mUnk_00.mPos.y >> 4;
    secondHand->mUnk_00.mMatrix.mUnk_00[3].z = secondHand->mUnk_00.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gSecondHand, &secondHand->mUnk_00.mMatrix, &secondHand->mUnk_00.mScale, alpha);
}

void UpdateSecondHand(u32 a, Unk020e43a8 *secondHand) {
    AdvanceStateMachine(&secondHand->mUnk_00.mStateMachine);
    QuaternionMultiplyAngleAroundY(&secondHand->mUnk_a0.mUnk_0c.y, secondHand->mUnk_00.mAngle, &secondHand->mUnk_a0);
    Matrix3x3FromQuaternion(&secondHand->mUnk_00.mMatrix, &secondHand->mUnk_a0);
}

void EnterSecondHandState0(Unk020e5950 *secondHand) {
    secondHand->mUnk_c8 = 0x0u;
}

void UpdateSecondHandState0(Unk020e43a8 *secondHand) {
    secondHand->mUnk_c8 = secondHand->mUnk_c8 + secondHand->mUnk_cc;
    secondHand->mUnk_00.mAngle =
        secondHand->mUnk_00.mAngle + (s16) (((s64) secondHand->mUnk_c8 * secondHand->mUnk_c6) >> 12);
    if (secondHand->mUnk_00.mStateMachine.mStateFrames > *(u16 *) &secondHand->mUnk_a0.mUnk_18.z) {
        secondHand->mUnk_00.mStateMachine.mNextState = 1;
        secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e58fc(u32 value) {
    return value;
}

void UpdateSecondHandState1(Unk020e43a8 *secondHand) {
    secondHand->mUnk_00.mAngle = secondHand->mUnk_00.mAngle + secondHand->mUnk_c6;
    if (*((u16 *) &secondHand->mUnk_a0.mUnk_18.z + 1) == 0) {
        return;
    }
    if (secondHand->mUnk_00.mStateMachine.mStateFrames > *((u16 *) &secondHand->mUnk_a0.mUnk_18.z + 1)) {
        secondHand->mUnk_00.mStateMachine.mNextState = 2;
        secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterSecondHandState2(Unk020e58b8 *secondHand) {
    secondHand->mUnk_c8 = 0x4000u;
}

void UpdateSecondHandState2(Unk020e43a8 *secondHand) {
    secondHand->mUnk_c8 = secondHand->mUnk_c8 - secondHand->mUnk_cc;
    secondHand->mUnk_00.mAngle =
        secondHand->mUnk_00.mAngle + (s16) (((s64) secondHand->mUnk_c8 * secondHand->mUnk_c6) >> 12);
    if (secondHand->mUnk_00.mStateMachine.mStateFrames > *(u16 *) &secondHand->mUnk_a0.mUnk_18.z) {
        secondHand->mUnk_c6 = -secondHand->mUnk_c6;
        secondHand->mUnk_00.mStateMachine.mNextState = 3;
        secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e5850(u32 value) {
    return value;
}

void UpdateSecondHandState3(Unk020e43a8 *secondHand) {
    if (secondHand->mUnk_00.mStateMachine.mStateFrames > secondHand->mUnk_c4) {
        secondHand->mUnk_00.mStateMachine.mNextState = 0;
        secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

s32 CollideKartWithSecondHand(Unk020e43a8 *secondHand, KartItemEffectView *kart, s32 a, u8 *b) {
    u32 x;

    x = kart->mUnk_29c;
    if (x == 1 || x == 3) {
        secondHand->mUnk_00.mDistanceSquaredAndFlags |= data_021590e8;
    }
    return *b;
}

u32 func_020e57f4(u32 p0, u32 p1, u32 p2, u32 p3) {
    return (*OFFSET_PTR(const u8, p3, 0));
}

void ComputeSphereHitOnSecondHand(Unk020e43a8 *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 s;
    s32 y;

    y = secondHand->mUnk_00.mExtent.y;
    s.x = secondHand->mUnk_00.mExtent.x;
    s.y = y;
    s.z = 0;
    ComputeSphereHitOnRotatedBox(sphereCenter, &secondHand->mUnk_00.mPos, &secondHand->mUnk_00.mMatrix.mUnk_00[0],
                                 &secondHand->mUnk_00.mExtent, &s, sphereRadius, overlapOffset);
}

#pragma thumb on

void CreateSecondHand(void) {
    CreateNsbmd(&gSecondHand, FindCourseMapObjFile(gSecondHandNsbmdName), NULL);
    func_02084968(gSecondHand, 0x3f, 2, 0x294a);
}

void InitSecondHand(Unk020e43a8 *secondHand, Unk020e5684 *courseRow) {
    secondHand->mUnk_00.mExtent.y = ((s64) secondHand->mUnk_00.mScale.x * 0x4b000) >> 12;
    InitStateMachine(&secondHand->mUnk_00.mStateMachine, (UnkFunc *const *) data_0216c240, 4, secondHand);
    QuaternionFromVec3Degrees(&courseRow->mUnk_0c, (u32 *) &secondHand->mUnk_a0.mUnk_00);
    *(Quaternion *) &secondHand->mUnk_a0.mUnk_0c.y = *(Quaternion *) &secondHand->mUnk_a0.mUnk_00;
    *(s16 *) &secondHand->mUnk_a0.mUnk_18.z = courseRow->mUnk_2c;
    *((s16 *) &secondHand->mUnk_a0.mUnk_18.z + 1) = courseRow->mUnk_2a;
    secondHand->mUnk_c4 = courseRow->mUnk_2e;
    secondHand->mUnk_c6 = (courseRow->mUnk_28 << 7) / 0x64;
    if (courseRow->mUnk_30 != 0) {
        secondHand->mUnk_c6 = -secondHand->mUnk_c6;
    }
    secondHand->mUnk_00.mAngle = 0;
    if (*(u16 *) &secondHand->mUnk_a0.mUnk_18.z != 0) {
        secondHand->mUnk_cc = 0x1000 / *(u16 *) &secondHand->mUnk_a0.mUnk_18.z;
    } else {
        secondHand->mUnk_cc = 0;
    }
    secondHand->mUnk_c8 = 0;
    secondHand->mUnk_00.mStateMachine.mNextState = 0;
    secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    secondHand->mUnk_00.mFlags |= data_021590b0;
}

#pragma thumb off
