#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_02147000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020f3678.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "01/code_02187eb0.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_020d9000.h"
#include "code_021471bc.h"

#pragma thumb on

void InitChoropu(Unk020e1e98 *choropu, struct CourseMapRow *courseRow) {
    InitStateMachine(&choropu->mUnk_000.mStateMachine, (UnkFunc *const *) data_0216c0e8, 8, choropu);
    choropu->mUnk_0a8 = choropu->mUnk_000.mPos.y;
    choropu->mUnk_0ac = choropu->mUnk_000.mPos.y - 0x12000;
    choropu->mUnk_0b0 = choropu->mUnk_000.mPos.y - 0x18000;
    choropu->mUnk_0a4 = courseRow->mUnk_28;
    choropu->mUnk_0a0 = courseRow->mUnk_2a;
    choropu->mUnk_000.mStateMachine.mNextState = 0;
    choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&choropu->mUnk_0b4.mUnk_08, &choropu->mUnk_000.mPos,
                        ((s64) choropu->mUnk_000.mScale.x * 0x1b000) >> 12, 0x1e);
    choropu->mUnk_000.mFlags |= data_02158b7c;
}

#pragma thumb off

void *CreateCarAKindData(void) {
    Unk020e03f8 *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *kindData = data_02158b3c;
    return kindData;
}

void *CreateTruckAKindData(void) {
    Unk020e03f8 *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *kindData = data_02158afc;
    return kindData;
}

void *CreateBusAKindData(void) {
    Unk020e03f8 *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *kindData = data_02158abc;
    return kindData;
}

void *func_020e2db8(void) {
    Unk020e03f8 *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    data_0217b79c = (Unk0217b79c *) drawList;
    *drawList = data_02158a7c;
    func_020d49d8(&data_0217b79c);
    return data_0217b79c;
}

void *func_020e2d5c(void) {
    Unk020e0340 *updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);

    data_0217b7a4 = updateList;
    *updateList = data_02158a54;
    SetUpdateListSlot(&data_0217b7a4);
    return data_0217b7a4;
}

void func_020e2ccc(Unk020e20a8 *drawList) {
    u16 entryIndex;

    entryIndex = gRaceSetup->mEntryIndex;
    if (drawList->mUnk_038 == FALSE) {
        return;
    }
    if (entryIndex < 8) {
        GetItemPointLinkDirection((u32) gKartItems[entryIndex].mUnk_1f0.mLink, (u32) &drawList->mUnk_02c);
        drawList->mUnk_03c = Vec3DotUnrounded(&drawList->mUnk_02c, GetViewTransposeMatrixAxis2()) < 0;
    } else {
        drawList->mUnk_03c = FALSE;
    }
}

void func_020e2a74(Unk020e20a8 *drawList, Unk020e1e98 *vehicle, u32 c, u32 alpha) {
    u32 f;
    s32 dotAxis2;
    s16 v;
    s16 w;
    Vec3 *shadowPosition;
    const s16 *anglePairs;
    Unk020e1e98_12c *animation;
    s32 tireMatrix[12];
    s32 one;
    u32 angleIndex;
    s32 x;
    s32 y;

    if (drawList->mUnk_03c != FALSE) {
        dotAxis2 = Vec3DotUnrounded(&vehicle->mUnk_000.mMatrix.mUnk_00[2], &drawList->mUnk_02c);
        v = vehicle->mUnk_000.mCourseMapRow->mUnk_2e;
        w = vehicle->mUnk_0d8.mFromEntry->mUnk_12;
        if (v == 0) {
            dotAxis2 = -dotAxis2;
        }
        if (dotAxis2 > w) {
            return;
        }
    }
    f = (s32) (vehicle->mUnk_000.mDistanceSquaredAndFlags & 0x3FFFFFE0) > 0x77A10 && func_0203c5e4() == 0;
    if (!f) {
        if (vehicle->mUnk_128 != 0) {
            shadowPosition = vehicle->mUnk_0fe > 0xF ? &vehicle->mUnk_144 : &vehicle->mUnk_000.mPos;
            vehicle->mUnk_000.mMatrix.mUnk_00[3].x = shadowPosition->x >> 4;
            vehicle->mUnk_000.mMatrix.mUnk_00[3].y = shadowPosition->y >> 4;
            vehicle->mUnk_000.mMatrix.mUnk_00[3].z = shadowPosition->z >> 4;
            DrawShadowWithMaxAlpha((void *) vehicle->mUnk_128, &vehicle->mUnk_000.mMatrix, &vehicle->mUnk_000.mScale,
                                   alpha);
        }
    }
    vehicle->mUnk_000.mMatrix.mUnk_00[3].x = vehicle->mUnk_000.mPos.x >> 4;
    vehicle->mUnk_000.mMatrix.mUnk_00[3].y = vehicle->mUnk_000.mPos.y >> 4;
    vehicle->mUnk_000.mMatrix.mUnk_00[3].z = vehicle->mUnk_000.mPos.z >> 4;
    animation = vehicle->mUnk_12c;
    if (animation != NULL) {
        animation->mUnk_0c = vehicle->mUnk_130 << 12;
        *animation->mUnk_1c[animation->mUnk_1a] = animation->mUnk_0c;
    }
    func_0208ab4c(&vehicle->mUnk_132);
    DrawNsbmdWithMatrixAndMaxAlpha((void *) vehicle->mUnk_124, &vehicle->mUnk_000.mMatrix, &vehicle->mUnk_000.mScale,
                                   alpha);
    if (f) {
        return;
    }
    angleIndex = vehicle->mUnk_10c >> 4;
    anglePairs = gPairsByAngle;
    x = ((s64) vehicle->mUnk_110 * anglePairs[angleIndex * 2] + 0x800) >> 12;
    y = ((s64) vehicle->mUnk_110 * anglePairs[angleIndex * 2 + 1] + 0x800) >> 12;
    MTX_RotX43_(tireMatrix, x, y);
    tireMatrix[0] = vehicle->mUnk_100[0];
    tireMatrix[10] = vehicle->mUnk_100[1];
    tireMatrix[11] = vehicle->mUnk_100[2];
    func_01ff9048(0x11, NULL, 0);
    func_01ff9048(0x19, tireMatrix, 0xc);
    DrawNsbmd(gCarTire);
    one = 1;
    func_01ff9048(0x12, &one, 1);
    tireMatrix[11] = -tireMatrix[11];
    func_01ff9048(0x19, tireMatrix, 0xc);
    DrawNsbmd(gCarTire);
}

static inline s64 func_020e2630_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

static inline s16 func_020e2630_inline2(Unk020e1e98 *b) {
    return b->mUnk_0fe;
}

void func_020e2630(u32 a, Unk020e1e98 *vehicle) {
    enum { K0 } f;
    void *baseRotation;
    u32 hitFlags;
    Unk020e1e98_0b4 targetRotation;
    Vec3 previousPosition;
    s32 out[3];
    Vec3 u;
    Vec3 testPosition;

    if (vehicle->mUnk_0fe > 0xf) {
        f = 1;
        f = (s32) f;
    } else {
        f = 0;
    }
    previousPosition = vehicle->mUnk_000.mPos;
    AdvanceGroupFollower(&vehicle->mUnk_0d8);
    if (!f) {
        GetGroupFollowerCurveXzLinearY(&vehicle->mUnk_0d8, &vehicle->mUnk_000.mPos);
        VEC_Subtract(&vehicle->mUnk_000.mPos, &previousPosition, &vehicle->mUnk_000.mUnk_10);
    } else {
        GetGroupFollowerCurveXzLinearY(&vehicle->mUnk_0d8, &vehicle->mUnk_144);
        vehicle->mUnk_000.mPos.x = vehicle->mUnk_144.x;
        vehicle->mUnk_000.mUnk_10.y -= 0x59a;
        vehicle->mUnk_000.mPos.y = vehicle->mUnk_000.mPos.y + vehicle->mUnk_000.mUnk_10.y;
        vehicle->mUnk_000.mPos.z = vehicle->mUnk_144.z;
        vehicle->mUnk_000.mUnk_10.x = vehicle->mUnk_000.mPos.x - previousPosition.x;
        vehicle->mUnk_000.mUnk_10.z = vehicle->mUnk_000.mPos.z - previousPosition.z;
    }
    if (f || (vehicle->mUnk_0d4 & 7) == GetRaceUpdateFramesMod8()) {
        testPosition.x = vehicle->mUnk_000.mPos.x;
        testPosition.y = vehicle->mUnk_000.mPos.y + (f ? 0xf000 : 0);
        testPosition.z = vehicle->mUnk_000.mPos.z;
        u = testPosition;
        if (func_01ffdee4(&u, NULL, 0, 0xf000, 8, -2, out, &u, NULL, &hitFlags, NULL, NULL, NULL, NULL) != 0) {
            if (hitFlags & 0x1e34ef) {
                QuaternionFromYAxisToVec3(&u, &vehicle->mUnk_0b4);
                AdvanceCourseColorBlend(&vehicle->mUnk_132, (hitFlags & 0x3c000000) >> 26, 0x5000);
                if (vehicle->mUnk_0fe != 0 && vehicle->mUnk_000.mUnk_10.y < 0) {
                    if (vehicle->mUnk_000.mFlags & 1) {
                        vehicle->mUnk_000.mFlags &= ~1;
                        vehicle->mUnk_000.mUnk_10.y = -(s32) (((s64) vehicle->mUnk_000.mUnk_10.y *
                                                               (0x733 + ((vehicle->mUnk_114.y - 0x14000) >> 9))) >>
                                                              12);
                        vehicle->mUnk_0c4 = -vehicle->mUnk_0c4;
                        vehicle->mUnk_0c8 = -vehicle->mUnk_0c8;
                        vehicle->mUnk_0cc = -vehicle->mUnk_0cc;
                        QuaternionBlendTowardNearerSign(&vehicle->mUnk_0c4, &vehicle->mUnk_0b4, &vehicle->mUnk_0c4,
                                                        0x8cd);
                        vehicle->mUnk_152 = 0x320;
                        StartMapObjectSound(&vehicle->mUnk_000, vehicle->mUnk_160);
                    } else if (f && vehicle != NULL) {
                        vehicle->mUnk_0fe = 0xf;
                        vehicle->mUnk_000.mUnk_10.y = 0;
                        vehicle->mUnk_152 = 0x258;
                    }
                }
            }
            if ((hitFlags & 0x214300) && f) {
                vehicle->mUnk_000.mPos.y = vehicle->mUnk_000.mPos.y + out[1];
                vehicle->mUnk_000.mUnk_10.y = 0;
            }
        }
    }
    switch (f) {
        default:
            if (vehicle->mUnk_000.mUnk_10.y < 0) {
                vehicle->mUnk_152 = ((s64) (-vehicle->mUnk_000.mUnk_10.y) * 0xc) >> 12;
                baseRotation = &vehicle->mUnk_0b4;
            } else {
                baseRotation = &vehicle->mUnk_0c4;
            }
            break;

        case 0:
            if (func_020e2630_inline2(vehicle) != 0) {
                vehicle->mUnk_0fe--;
                if (vehicle->mUnk_0fe == 0) {
                    vehicle->mUnk_152 = vehicle->mUnk_150;
                } else {
                    baseRotation = &vehicle->mUnk_0b4;
                }
            }
            break;
    }

    if (func_020e2630_inline(&vehicle->mUnk_000.mUnk_10) < 0x10) {
        targetRotation = vehicle->mUnk_0b4;
    } else {
        vehicle->mUnk_000.mAngle =
            (s16) (((s64) FX_Atan2(vehicle->mUnk_000.mUnk_10.x, vehicle->mUnk_000.mUnk_10.z) * 0x28BE60DB9391 +
                    0x80000000000) >>
                   44);
        if (vehicle->mUnk_0fe == 0) {
            baseRotation = &vehicle->mUnk_0b4;
        }
        func_020d79b0(baseRotation, vehicle->mUnk_000.mAngle, &targetRotation);
    }
    QuaternionBlendTowardNearerSign(&vehicle->mUnk_0a4, &targetRotation, &vehicle->mUnk_0a4, vehicle->mUnk_152);
    Matrix3x3FromQuaternion(&vehicle->mUnk_000.mMatrix.mUnk_00[0].x, &vehicle->mUnk_0a4);
    vehicle->mUnk_10c += 0x600;
    if (vehicle->mUnk_000.mDistanceSquaredAndFlags & 8) {
        AdvanceSoundDistanceSquaredChange(vehicle->mUnk_158, vehicle->mUnk_000.mDistanceSquaredAndFlags & 0x3FFFFFE0);
    }
    StartMapObjectSoundWhileRequested(&vehicle->mUnk_000, vehicle->mUnk_15c);
    if (vehicle->mUnk_000.mPos.y < 0) {
        func_020e1e98(vehicle);
    }
}

void func_020e24d0(Unk020e1e98 *vehicle, Vec3 *hitterPosition) {
    Vec3 c;
    s32 dotAxis0;
    s32 dotAxis2;
    s32 upwardSpeed;

    c = vehicle->mUnk_000.mPos;
    VEC_Subtract(&c, hitterPosition, &c);
    dotAxis0 = Vec3DotUnrounded(&vehicle->mUnk_000.mMatrix.mUnk_00[0], &c);
    dotAxis2 = Vec3DotUnrounded(&vehicle->mUnk_000.mMatrix.mUnk_00[2], &c);
    c.x = (dotAxis0 > 0 ? vehicle->mUnk_000.mMatrix.mUnk_00[0].x : -vehicle->mUnk_000.mMatrix.mUnk_00[0].x) * 2;
    c.x += dotAxis2 > 0 ? vehicle->mUnk_000.mMatrix.mUnk_00[2].x : -vehicle->mUnk_000.mMatrix.mUnk_00[2].x;
    c.z = (dotAxis0 > 0 ? vehicle->mUnk_000.mMatrix.mUnk_00[0].z : -vehicle->mUnk_000.mMatrix.mUnk_00[0].z) * 2;
    c.z += dotAxis2 > 0 ? vehicle->mUnk_000.mMatrix.mUnk_00[2].z : -vehicle->mUnk_000.mMatrix.mUnk_00[2].z;
    c.y = ((vehicle->mUnk_114.y - 0x14000) >> 4) + 0x2000;
    if ((s64) c.x * c.x + (s64) c.y * c.y + (s64) c.z * c.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&c, &c);
    }
    QuaternionFromYAxisToVec3(&c, &vehicle->mUnk_0c4);
    vehicle->mUnk_152 = 0x384;
    if (vehicle->mUnk_0fe > 0xf || vehicle->mUnk_000.mUnk_10.y <= 0) {
        upwardSpeed = 0;
    } else {
        upwardSpeed = vehicle->mUnk_000.mUnk_10.y;
    }
    vehicle->mUnk_000.mUnk_10.y = upwardSpeed + 0x7000;
    vehicle->mUnk_000.mFlags |= *(const u16 *) data_02158a50;
    vehicle->mUnk_0fe = 0x14;
}

u8 func_020e2494(Unk020e1e98 *vehicle, Kart *kart, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020e24d0(vehicle, &kart->mPos);
        StartSoundIfKartStarOrKiller(&vehicle->mUnk_000, kart);
    }
    return *d;
}

u8 func_020e246c(Unk020e1e98 *vehicle, Unk020e246c *itemObject, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020e24d0(vehicle, &itemObject->mUnk_050);
    }
    return *d;
}

void func_020e2400(Unk020e1e98 *vehicle, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 e;
    Vec3 f;
    s32 x;
    s32 y;
    s32 z;

    z = vehicle->mUnk_114.z;
    y = vehicle->mUnk_114.y;
    x = vehicle->mUnk_114.x;
    e.x = x;
    e.y = y;
    e.z = z;
    z = vehicle->mUnk_120;
    x = vehicle->mUnk_114.x;
    f.x = x;
    f.y = 0;
    f.z = z;
    ComputeSphereHitOnRotatedBox(sphereCenter, &vehicle->mUnk_000.mPos, &vehicle->mUnk_000.mMatrix.mUnk_00[0], &e, &f,
                                 sphereRadius, overlapOffset);
}

#pragma thumb on

void func_020e230c(Unk0217b79c *updateList) {
    s32 index;
    s32 count;
    u32 seenGroupMask;
    Unk020e1e98 **vehicleCursor;
    u16 entryCount;
    u16 groupIndex;
    CourseMapGroupEntry *entry;
    u16 entryIndex;
    u16 z;
    Unk020e1e98 *vehicle;
    s16 v;
    s16 w;
    float f;

    count = updateList->mUnk_04;
    vehicleCursor = updateList->mUnk_00;
    seenGroupMask = 0;
    z = 0;
    for (index = 0; index < count; index++) {
        vehicle = *vehicleCursor;
        groupIndex = vehicle->mUnk_000.mCourseMapRow->mUnk_26;
        vehicle->mUnk_0d4 = index;
        if ((seenGroupMask & (1 << groupIndex)) == 0) {
            entryCount = gCourseMap->mEntryGroups[groupIndex].mEntryCount;
            seenGroupMask |= 1 << groupIndex;
            for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
                entry = GetCourseMapGroupEntry(groupIndex, entryIndex);
                v = entry->mUnk_0e;
                if (v != 0) {
                    if (v > 0) {
                        f = 0.5f + (v << 12);
                    } else {
                        f = (v << 12) - 0.5f;
                    }
                    w = gPairsByAngle[((((u16) (((s64) (s32) f * 0xB60B60B60B + 0x80000000000) >> 44)) >> 4) << 1) + 1];
                } else {
                    w = 0x2000;
                }
                entry->mUnk_12 = w;
                entry->mUnk_0e = z;
            }
        }
        vehicleCursor++;
    }
}

void func_020e20a8(Unk020e20a8 *drawList) {
    void *carFile;
    void *truckFile;
    u32 carMaterialIndex;
    NNSG3dResMdl *carModel;
    u32 truckMaterialIndex;
    NNSG3dResMdl *truckModel;
    u32 busMaterialIndex;
    NNSG3dResMdl *busModel;
    u32 tireMaterialIndex;
    NNSG3dResMdl *tireModel;
    s32 index;
    Unk020e1e98 *vehicle;
    u32 *q;
    Unk020e1e98_12c **animationSlot;
    s32 count;

    carFile = FindCourseMapObjFile(gCarANsbmdName);
    truckFile = FindCourseMapObjFile(gTruckANsbmdName);
    drawList->mUnk_038 =
        gRaceSetup->mMode != MODE_MISSION_RUN && func_0203c5e4() == 0 && (u16) gRaceSetup->mEntryIndex < 8;
    drawList->mUnk_03c = FALSE;
    CreateNsbmd(&gCarA, carFile, NULL);
    CreateNsbmd(&gTruckA, truckFile, NULL);
    CreateNsbmd(&gBusA, FindCourseMapObjFile(gBusANsbmdName), NULL);
    CreateNsbmd(&gCarTire, FindCourseMapObjFile(gCarTireNsbmdName), NULL);
    CreateShadowModel(&gCarAShadow, FindCourseMapObjFile(gCarAShadowNsbmdName), 7);
    CreateShadowModel(&gTruckAShadow, FindCourseMapObjFile(gTruckAShadowNsbmdName), 7);
    CreateShadowModel(&gBusAShadow, FindCourseMapObjFile(gBusAShadowNsbmdName), 7);
    CreateModelAnimation(2, gCarA, &gCarANsbtp, carFile, FindCourseMapObjFile(gCarANsbtpName));
    CreateModelAnimation(2, gTruckA, &gTruckANsbtp, truckFile, FindCourseMapObjFile(gTruckANsbtpName));
    func_02084968(gCarA, 0x3f, 2, 0x294a);
    for (carMaterialIndex = 0, carModel = ((Unk0217b7a0 *) gCarA)->mUnk_04; carMaterialIndex < carModel->mInfo.mNumMat;
         carMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(carModel, carMaterialIndex, 7);
    }
    func_02084968(gTruckA, 0x3f, 2, 0x294a);
    for (truckMaterialIndex = 0, truckModel = ((Unk0217b7a0 *) gTruckA)->mUnk_04;
         truckMaterialIndex < truckModel->mInfo.mNumMat; truckMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(truckModel, truckMaterialIndex, 7);
    }
    func_02084968(gBusA, 0x3f, 2, 0x294a);
    for (busMaterialIndex = 0, busModel = ((Unk0217b7a0 *) gBusA)->mUnk_04; busMaterialIndex < busModel->mInfo.mNumMat;
         busMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(busModel, busMaterialIndex, 7);
    }
    func_02084968(gCarTire, 0x3f, 2, 0x294a);
    for (tireMaterialIndex = 0, tireModel = ((Unk0217b7a0 *) gCarTire)->mUnk_04;
         tireMaterialIndex < tireModel->mInfo.mNumMat; tireMaterialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(tireModel, tireMaterialIndex, 7);
    }
    SetNsbmdLightEnableFlagAll(gCarTire, 0);
    count = data_0217b79c->mUnk_04;
    for (index = 0; index < count; index++) {
        vehicle = data_0217b79c->mUnk_00[index];
        q = vehicle->mUnk_154->mUnk_20;
        vehicle->mUnk_124 = q != NULL ? *q : 0;
        q = vehicle->mUnk_154->mUnk_24;
        vehicle->mUnk_128 = q != NULL ? *q : 0;
        animationSlot = vehicle->mUnk_154->mUnk_28;
        vehicle->mUnk_12c = animationSlot != NULL ? *animationSlot : 0;
    }
}

void func_020e1f54(Unk020e1e98 *vehicle, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo) {
    vehicle->mUnk_154 = kindInfo;
    InitGroupFollower(&vehicle->mUnk_0d8, courseRow, (s16) courseRow->mUnk_28 * 0x3000 / 100);
    vehicle->mUnk_0fc = courseRow->mUnk_2a;
    vehicle->mUnk_130 = courseRow->mUnk_2c;
    vehicle->mUnk_0a0 = GetCourseMapGroupEntry(courseRow->mUnk_26, vehicle->mUnk_0fc)->mPos.y;
    vehicle->mUnk_114.x = ((s64) kindInfo->mUnk_00 * vehicle->mUnk_000.mScale.x) >> 12;
    vehicle->mUnk_114.y = ((s64) kindInfo->mUnk_04 * vehicle->mUnk_000.mScale.y) >> 12;
    vehicle->mUnk_114.z = ((s64) kindInfo->mUnk_08 * vehicle->mUnk_000.mScale.z) >> 12;
    vehicle->mUnk_120 = ((s64) kindInfo->mUnk_0c * vehicle->mUnk_000.mScale.z) >> 12;
    vehicle->mUnk_152 = (u32) ((s16) courseRow->mUnk_28 * 0xfa) / 100;
    vehicle->mUnk_150 = vehicle->mUnk_152;
    vehicle->mUnk_100[0] = kindInfo->mUnk_10;
    vehicle->mUnk_100[1] = kindInfo->mUnk_14 >> 4;
    vehicle->mUnk_100[2] = kindInfo->mUnk_18 >> 4;
    vehicle->mUnk_110 = kindInfo->mUnk_1c;
    func_020e1e98(vehicle);
    vehicle->mUnk_15c = kindInfo->mUnk_2c;
    vehicle->mUnk_158 = func_020d286c(&vehicle->mUnk_000);
    ResetSoundDistanceSquaredChange(vehicle->mUnk_158);
    vehicle->mUnk_000.mSound->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210a6ec;
    vehicle->mUnk_160 = kindInfo->mUnk_30;
}

void func_020e1e98(Unk020e1e98 *vehicle) {
    SetupGroupFollowerAtEntry(&vehicle->mUnk_0d8, vehicle->mUnk_0fc, 1);
    GetGroupFollowerCurvePosStepXz(&vehicle->mUnk_0d8, &vehicle->mUnk_000.mPos, &vehicle->mUnk_000.mUnk_10);
    vehicle->mUnk_000.mPos.y = vehicle->mUnk_0a0;
    vehicle->mUnk_000.mUnk_10.y = 0;
    vehicle->mUnk_0b4 = *(const Unk020e1e98_0b4 *) data_0216c044;
    func_020d79b0(&vehicle->mUnk_0b4,
                  (u16) (((s64) FX_Atan2(vehicle->mUnk_000.mUnk_10.x, vehicle->mUnk_000.mUnk_10.z) * 0x28be60db9391 +
                          0x80000000000) >>
                         44),
                  &vehicle->mUnk_0a4);
    Matrix3x3FromQuaternion(&vehicle->mUnk_000.mMatrix.mUnk_00[0].x, &vehicle->mUnk_0a4);
    vehicle->mUnk_0fe = 0;
    vehicle->mUnk_152 = vehicle->mUnk_150;
    vehicle->mUnk_10c = 0;
    InitCourseColorBlend(&vehicle->mUnk_132, 1);
}

#pragma thumb off

void func_020e1e38(Unk020e1dc0 *list, void *viewMatrix, void (*drawObject)(Unk020e3ef4 *, void *, u32)) {
    s32 index;
    s32 count = list->mUnk_04;

    for (index = 0; index < count; index++) {
        Unk020e3ef4 *mapObject = list->mUnk_00[index];

        if ((mapObject->mUnk_000.mFlags & 0x12) == 0 && mapObject->mUnk_000.mAlpha != 0) {
            drawObject(mapObject, viewMatrix, mapObject->mUnk_000.mAlpha);
        }
    }
}

void func_020e1dec(Unk020e3ef4 *mapObject, void *viewMatrix, u32 alpha) {
    mapObject->mUnk_000.mMatrix.mUnk_00[3].x = mapObject->mUnk_000.mPos.x >> 4;
    mapObject->mUnk_000.mMatrix.mUnk_00[3].y = mapObject->mUnk_000.mPos.y >> 4;
    mapObject->mUnk_000.mMatrix.mUnk_00[3].z = mapObject->mUnk_000.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(mapObject->mModel, &mapObject->mUnk_000.mMatrix, &mapObject->mUnk_000.mScale.x,
                                   alpha);
}

void SetMapObjectsModel(Unk020e1dc0 *list, void *model) {
    s32 index;
    s32 count = list->mUnk_04;

    for (index = 0; index < count; index++) {
        list->mUnk_00[index]->mModel = model;
    }
}

s32 func_020e1d10(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *e, Unk020e0764 *f,
                  Vec3 *g, u16 *h, Vec3 *i, u16 *j) {
    switch (object->mUnk_134) {
        case 0:
            return func_020e0bac(object, sphereCenter, sphereRadius, d, e, f, g, h, i, j);
        case 1:
            return func_020e0764(object, sphereCenter, sphereRadius, d, e, f, g, h, i, j);
    }
    return 0;
}

void func_020e1a80(s32 a, s32 b, s32 c, u32 d, u16 e, u16 *f, s32 v, Unk020e005c *object, Vec3 *g, Vec3 *h,
                   Unk020e0764 *i, Unk020e0764 *j, Vec3 *k, Vec3 *l, u16 *m) {
    BOOL q;
    s32 t;
    Unk020e0764 *s;
    u16 n;
    Vec3 u;

    q = FALSE;
    if (v != 0) {
        if (d & e) {
            t = h->y;
        } else {
            t = -h->y;
        }
        if (t > object->mUnk_120) {
            q = TRUE;
        }
    }
    u.x = h->x << 10;
    u.y = h->y << 10;
    u.z = h->z << 10;
    u.x = ((s64) u.x * b) >> 12;
    u.y = ((s64) u.y * b) >> 12;
    u.z = ((s64) u.z * b) >> 12;
    if (q) {
        n = object->mUnk_114.z != 0 && (d & 8) ? 0x12 : 0;
        *f = n;
        s = i;
    } else {
        *f = 8;
        s = j;
    }
    if (c >= s->mUnk_18) {
        s->mUnk_18 = c;
        if (d & e) {
            s->mUnk_1c = *h;
        } else {
            s->mUnk_1c.x = -h->x;
            s->mUnk_1c.y = -h->y;
            s->mUnk_1c.z = -h->z;
        }
    }
    if (u.x > s->mUnk_00) {
        s->mUnk_00 = u.x;
    } else if (u.x < s->mUnk_0c) {
        s->mUnk_0c = u.x;
    }
    if (u.y > s->mUnk_04) {
        s->mUnk_04 = u.y;
    } else if (u.y < s->mUnk_10) {
        s->mUnk_10 = u.y;
    }
    if (u.z > s->mUnk_08) {
        s->mUnk_08 = u.z;
    } else if (u.z < s->mUnk_14) {
        s->mUnk_14 = u.z;
    }
    if (k != NULL) {
        if (d & e) {
            s32 v = -(a - c);

            u.x = ((s64) h->x * v) >> 12;
            u.y = ((s64) h->y * v) >> 12;
            u.z = ((s64) h->z * v) >> 12;
        } else {
            s32 v = a - c;

            u.x = ((s64) h->x * v) >> 12;
            u.y = ((s64) h->y * v) >> 12;
            u.z = ((s64) h->z * v) >> 12;
        }
        if (u.y < k->y) {
            *k = u;
        }
    }
    if (!q) {
        return;
    }
    func_020e0680(object, g, h, l, m);
}

BOOL func_020e16dc(s32 a, s32 b, s32 c, u32 d, u16 e, u16 f, u16 *g, u16 h, s32 i, s32 j, Unk020e005c *object, Vec3 *l,
                   Vec3 *m, Vec3 *n, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, Vec3 *r, u16 *s) {
    BOOL u;
    BOOL v;
    BOOL k;
    s32 t;
    Unk020e0764 *x;
    Vec3 y;
    Vec3 z;
    Vec3 tmp;

    u = FALSE;
    if ((h & 0x60) == 0) {
        v = TRUE;
        k = FALSE;
        if (i != 0) {
            t = (d & e) ? m->y : -m->y;
            if (t > object->mUnk_120) {
                k = TRUE;
            }
        }
        if (k == FALSE) {
            k = FALSE;
            if (j != 0) {
                t = (d & f) ? n->y : -n->y;
                if (t > object->mUnk_120) {
                    k = TRUE;
                }
            }
            if (k == FALSE) {
                v = FALSE;
            }
        }
        if (v != FALSE) {
            u = TRUE;
        }
    }
    y.x = ((s64) m->x * b) >> 12;
    y.y = ((s64) m->y * b) >> 12;
    y.z = ((s64) m->z * b) >> 12;
    z.x = ((s64) n->x * c) >> 12;
    z.y = ((s64) n->y * c) >> 12;
    z.z = ((s64) n->z * c) >> 12;
    VEC_Add(&y, &z, &y);
    y.x <<= 10;
    y.y <<= 10;
    y.z <<= 10;
    t = Vec3NormalizeAndGetLengthOrZero(&y, &tmp);
    if (t > (a << 10)) {
        return FALSE;
    }
    if (t != 0) {
        z.x = ((s64) tmp.x * a) >> 12;
        z.y = ((s64) tmp.y * a) >> 12;
        z.z = ((s64) tmp.z * a) >> 12;
        y.x >>= 10;
        y.y >>= 10;
        y.z >>= 10;
        VEC_Subtract(&z, &y, &z);
        c = VEC_Mag(&z);
    } else {
        tmp = *n;
        z.x = ((s64) tmp.x * a) >> 12;
        z.y = ((s64) tmp.y * a) >> 12;
        z.z = ((s64) tmp.z * a) >> 12;
        c = a;
    }
    if (u) {
        if (object->mUnk_114.z != 0 && (d & 8)) {
            *g = 0x1e;
            x = p;
        } else {
            *g = 0;
            x = o;
        }
    } else {
        *g = 8;
        x = p;
    }
    if (c >= x->mUnk_18) {
        x->mUnk_18 = c;
        x->mUnk_1c = tmp;
    }
    z.x <<= 10;
    z.y <<= 10;
    z.z <<= 10;
    if (z.x > x->mUnk_00) {
        x->mUnk_00 = z.x;
    } else if (z.x < x->mUnk_0c) {
        x->mUnk_0c = z.x;
    }
    if (z.y > x->mUnk_04) {
        x->mUnk_04 = z.y;
    } else if (z.y < x->mUnk_10) {
        x->mUnk_10 = z.y;
    }
    if (z.z > x->mUnk_08) {
        x->mUnk_08 = z.z;
    } else if (z.z < x->mUnk_14) {
        x->mUnk_14 = z.z;
    }
    if (q != NULL) {
        y.x = -y.x;
        y.y = -y.y;
        y.z = -y.z;
        if (y.y < q->y) {
            *q = y;
        }
    }
    if (u) {
        func_020e0680(object, l, &tmp, r, s);
    }
    return TRUE;
}

BOOL func_020e0bac(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *o, Unk020e0764 *p,
                   Vec3 *q, u16 *g, Vec3 *r, u16 *s) {
    Vec3 v;
    Vec3 w;
    Vec3 tmp;
    Unk020e0764 *x;
    u16 n;
    s32 f6;
    s32 f5;
    s32 f4;
    s32 k6;
    s32 k5;
    s32 m6;
    s32 m5;
    s32 m4;
    BOOL u;
    BOOL e;
    BOOL h;
    BOOL y;
    s32 t;

    n = 0;
    VEC_Subtract(sphereCenter, &object->mUnk_0f4, &v);
    f6 = Vec3DotUnrounded(&v, &object->mUnk_028);
    if (f6 > 0) {
        if (f6 > object->mUnk_100 + sphereRadius) {
            return FALSE;
        }
        if (f6 > object->mUnk_100) {
            n |= 0xa00;
        } else {
            n |= 0x900;
        }
    } else {
        if (f6 < -(object->mUnk_100 + sphereRadius)) {
            return FALSE;
        }
        if (f6 < -object->mUnk_100) {
            n |= 0x600;
        } else {
            n |= 0x500;
        }
    }
    f5 = Vec3DotUnrounded(&v, &object->mUnk_034);
    if (f5 > 0) {
        if (f5 > object->mUnk_104 + sphereRadius) {
            return FALSE;
        }
        if (f5 > object->mUnk_104) {
            n |= 0xa0;
        } else {
            n |= 0x90;
        }
    } else {
        if (f5 < -(object->mUnk_104 + sphereRadius)) {
            return FALSE;
        }
        if (f5 < -object->mUnk_104) {
            n |= 0x60;
        } else {
            n |= 0x50;
        }
    }
    f4 = Vec3DotUnrounded(&v, &object->mUnk_040);
    if (f4 > 0) {
        if (f4 > object->mUnk_108 + sphereRadius) {
            return FALSE;
        }
        if (f4 > object->mUnk_108) {
            n |= 0xa;
        } else {
            n |= 0x9;
        }
    } else {
        if (f4 < -(object->mUnk_10c + sphereRadius)) {
            return FALSE;
        }
        if (f4 < -object->mUnk_10c) {
            n |= 0x6;
        } else {
            n |= 0x5;
        }
    }
    if ((d & 4) && object->mUnk_13c != 0) {
        return FALSE;
    }
    if (n & 0x100) {
        if (n & 0x10) {
            if (n & 0x8) {
                f4 = (object->mUnk_108 + sphereRadius) - f4;
            } else {
                f4 = -(object->mUnk_10c + sphereRadius) - f4;
            }
            if (n & 0x1) {
                if (n & 0x800) {
                    k6 = (object->mUnk_100 + sphereRadius) - f6;
                } else {
                    k6 = -(object->mUnk_100 + sphereRadius) - f6;
                }
                if (n & 0x80) {
                    k5 = (object->mUnk_104 + sphereRadius) - f5;
                } else {
                    k5 = -(object->mUnk_104 + sphereRadius) - f5;
                }
                m6 = k6 > 0 ? k6 : -k6;
                m5 = k5 > 0 ? k5 : -k5;
                m4 = f4 > 0 ? f4 : -f4;
                goto smallest;
            }
            m4 = f4 > 0 ? f4 : -f4;
            goto call_8;
        }
        if (n & 0x80) {
            k5 = (object->mUnk_104 + sphereRadius) - f5;
        } else {
            k5 = -(object->mUnk_104 + sphereRadius) - f5;
        }
        if (!(n & 0x1)) {
            goto call_80_8;
        }
        m5 = k5 > 0 ? k5 : -k5;
        goto call_80;
    }
    if (n & 0x800) {
        k6 = (object->mUnk_100 + sphereRadius) - f6;
    } else {
        k6 = -(object->mUnk_100 + sphereRadius) - f6;
    }
    if (n & 0x10) {
        if (!(n & 0x1)) {
            goto call_8_800;
        }
        m6 = k6 > 0 ? k6 : -k6;
    } else {
        if (!(n & 0x1)) {
            goto rest;
        }
        goto call_800_80;
    }
call_800:
    func_020e1a80(sphereRadius, k6, m6, n, 0x800, g, object->mUnk_110, object, sphereCenter, &object->mUnk_028, o, p, q,
                  r, s);
    return TRUE;
call_80:
    func_020e1a80(sphereRadius, k5, m5, n, 0x80, g, object->mUnk_114.x, object, sphereCenter, &object->mUnk_034, o, p,
                  q, r, s);
    return TRUE;
call_8:
    func_020e1a80(sphereRadius, f4, m4, n, 8, g, object->mUnk_114.y, object, sphereCenter, &object->mUnk_040, o, p, q,
                  r, s);
    return TRUE;
smallest:
    if (m6 < m4) {
        if (m6 < m5) {
            goto call_800;
        }
        goto call_80;
    }
    if (m4 < m5) {
        goto call_8;
    }
    goto call_80;
call_800_80:
    if (n & 0x800) {
        f6 = f6 - object->mUnk_100;
    } else {
        f6 = f6 + object->mUnk_100;
    }
    if (n & 0x80) {
        f5 = f5 - object->mUnk_104;
    } else {
        f5 = f5 + object->mUnk_104;
    }
    return func_020e16dc(sphereRadius, f6, f5, n, 0x800, 0x80, g, d, object->mUnk_110, object->mUnk_114.x, object,
                         sphereCenter, &object->mUnk_028, &object->mUnk_034, o, p, q, r, s);
call_80_8:
    if (n & 0x80) {
        f5 = f5 - object->mUnk_104;
    } else {
        f5 = f5 + object->mUnk_104;
    }
    if (n & 0x8) {
        f4 = f4 - object->mUnk_108;
    } else {
        f4 = f4 + object->mUnk_10c;
    }
    return func_020e16dc(sphereRadius, f5, f4, n, 0x80, 0x8, g, d, object->mUnk_114.x, object->mUnk_114.y, object,
                         sphereCenter, &object->mUnk_034, &object->mUnk_040, o, p, q, r, s);
call_8_800:
    if (n & 0x8) {
        f4 = f4 - object->mUnk_108;
    } else {
        f4 = f4 + object->mUnk_10c;
    }
    if (n & 0x800) {
        f6 = f6 - object->mUnk_100;
    } else {
        f6 = f6 + object->mUnk_100;
    }
    return func_020e16dc(sphereRadius, f4, f6, n, 8, 0x800, g, d, object->mUnk_114.y, object->mUnk_110, object,
                         sphereCenter, &object->mUnk_040, &object->mUnk_028, o, p, q, r, s);
rest:
    u = FALSE;
    if ((d & 0x60) == 0) {
        e = TRUE;
        y = TRUE;
        h = FALSE;
        if (object->mUnk_110 != 0) {
            t = (n & 0x800) ? object->mUnk_028.y : -object->mUnk_028.y;
            if (t > object->mUnk_120) {
                h = TRUE;
            }
        }
        if (h == FALSE) {
            h = FALSE;
            if (object->mUnk_114.x != 0) {
                t = (n & 0x80) ? object->mUnk_034.y : -object->mUnk_034.y;
                if (t > object->mUnk_120) {
                    h = TRUE;
                }
            }
            if (h == FALSE) {
                y = FALSE;
            }
        }
        if (y == FALSE) {
            k5 = 0;
            if (object->mUnk_114.y != 0) {
                t = (n & 0x8) ? object->mUnk_040.y : -object->mUnk_040.y;
                if (t > object->mUnk_120) {
                    k5 = 1;
                }
            }
            if (k5 == 0) {
                e = FALSE;
            }
        }
        if (e != FALSE) {
            u = TRUE;
        }
    }
    if (n & 0x800) {
        f6 = f6 - object->mUnk_100;
    } else {
        f6 = f6 + object->mUnk_100;
    }
    if (n & 0x80) {
        f5 = f5 - object->mUnk_104;
    } else {
        f5 = f5 + object->mUnk_104;
    }
    if (n & 0x8) {
        f4 = f4 - object->mUnk_108;
    } else {
        f4 = f4 + object->mUnk_10c;
    }
    v.x = ((s64) object->mUnk_028.x * f6) >> 12;
    v.y = ((s64) object->mUnk_028.y * f6) >> 12;
    v.z = ((s64) object->mUnk_028.z * f6) >> 12;
    w.x = ((s64) object->mUnk_034.x * f5) >> 12;
    w.y = ((s64) object->mUnk_034.y * f5) >> 12;
    w.z = ((s64) object->mUnk_034.z * f5) >> 12;
    VEC_Add(&w, &v, &v);
    w.x = ((s64) object->mUnk_040.x * f4) >> 12;
    w.y = ((s64) object->mUnk_040.y * f4) >> 12;
    w.z = ((s64) object->mUnk_040.z * f4) >> 12;
    VEC_Add(&w, &v, &v);
    v.x <<= 10;
    v.y <<= 10;
    v.z <<= 10;
    t = Vec3NormalizeAndGetLengthOrZero(&v, &w);
    if (t > (sphereRadius << 10)) {
        return FALSE;
    }
    if (t != 0) {
        tmp.x = ((s64) w.x * sphereRadius) >> 12;
        tmp.y = ((s64) w.y * sphereRadius) >> 12;
        tmp.z = ((s64) w.z * sphereRadius) >> 12;
        v.x >>= 10;
        v.y >>= 10;
        v.z >>= 10;
        VEC_Subtract(&tmp, &v, &tmp);
        sphereRadius = VEC_Mag(&tmp);
    } else {
        w = object->mUnk_034;
        tmp.x = ((s64) w.x * sphereRadius) >> 12;
        tmp.y = ((s64) w.y * sphereRadius) >> 12;
        tmp.z = ((s64) w.z * sphereRadius) >> 12;
    }
    if (u) {
        if (object->mUnk_114.z != 0 && (n & 0x8)) {
            *g = 0x1e;
            x = p;
        } else {
            *g = 0;
            x = o;
        }
    } else {
        *g = 8;
        x = p;
    }
    if (sphereRadius >= x->mUnk_18) {
        x->mUnk_18 = sphereRadius;
        x->mUnk_1c = w;
    }
    tmp.x <<= 10;
    tmp.y <<= 10;
    tmp.z <<= 10;
    if (tmp.x > x->mUnk_00) {
        x->mUnk_00 = tmp.x;
    } else if (tmp.x < x->mUnk_0c) {
        x->mUnk_0c = tmp.x;
    }
    if (tmp.y > x->mUnk_04) {
        x->mUnk_04 = tmp.y;
    } else if (tmp.y < x->mUnk_10) {
        x->mUnk_10 = tmp.y;
    }
    if (tmp.z > x->mUnk_08) {
        x->mUnk_08 = tmp.z;
    } else if (tmp.z < x->mUnk_14) {
        x->mUnk_14 = tmp.z;
    }
    if (q != NULL) {
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
        if (v.y < q->y) {
            *q = v;
        }
    }
    if (u) {
        func_020e0680(object, sphereCenter, &w, r, s);
    }
    return TRUE;
}

BOOL func_020e0764(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 d, Unk020e0764 *o, Unk020e0764 *p,
                   Vec3 *q, u16 *g, Vec3 *r, u16 *s) {
    Vec3 v;
    s32 d0;
    Vec3 w;
    s32 t;
    s32 k;
    s64 sq;
    u16 fl;
    s32 x;
    s32 y;
    s32 n;

    fl = 0;
    VEC_Subtract(sphereCenter, &object->mUnk_0f4, &v);
    x = Vec3DotUnrounded(&v, &object->mUnk_028);
    y = Vec3DotUnrounded(&v, &object->mUnk_040);
    sq = (s64) x * x + (s64) y * y;
    t = object->mUnk_100 + sphereRadius;
    if ((s64) t * t < sq) {
        return FALSE;
    }
    if ((s64) object->mUnk_100 * object->mUnk_100 < sq) {
        fl |= data_021588e8;
    } else {
        fl |= data_021588ec;
    }
    n = Vec3DotUnrounded(&v, &object->mUnk_034);
    if (n > 0) {
        if (n > object->mUnk_104 + sphereRadius) {
            return FALSE;
        }
        if (n > object->mUnk_104) {
            fl |= 0xa0;
        } else {
            fl |= 0x90;
        }
    } else {
        if (n < -(object->mUnk_104 + sphereRadius)) {
            return FALSE;
        }
        if (n < -object->mUnk_104) {
            fl |= 0x60;
        } else {
            fl |= 0x50;
        }
    }
    if (fl & 0x1000) {
        if (fl & 0x80) {
            n = object->mUnk_104 + sphereRadius - n;
        } else {
            n = -(object->mUnk_104 + sphereRadius) - n;
        }
        if (n > 0) {
            d0 = n;
        } else {
            d0 = -n;
        }
        if (!(fl & 0x10)) {
            goto apply80;
        }
        v.x = x;
        v.y = 0;
        v.z = y;
        x = Vec3NormalizeXZAndGetLengthOrZero(&v, &v);
        k = t - x;
        if (x == 0) {
            w = data_021588f0;
        } else {
            w.x = ((s64) object->mUnk_028.x * v.x) >> 12;
            w.y = ((s64) object->mUnk_028.y * v.x) >> 12;
            w.z = ((s64) object->mUnk_028.z * v.x) >> 12;
            VEC_MultAdd(v.z, &object->mUnk_040, &w, &w);
        }
        goto cmp;
    }
    v.x = x;
    v.y = 0;
    v.z = y;
    x = Vec3NormalizeXZAndGetLengthOrZero(&v, &v);
    k = t - x;
    if (x == 0) {
        w = data_021588fc;
    } else {
        w.x = ((s64) object->mUnk_028.x * v.x) >> 12;
        w.y = ((s64) object->mUnk_028.y * v.x) >> 12;
        w.z = ((s64) object->mUnk_028.z * v.x) >> 12;
        VEC_MultAdd(v.z, &object->mUnk_040, &w, &w);
    }
    if (fl & 0x10) {
        goto apply3000;
    }
    goto tail;
apply80:
    func_020e1a80(sphereRadius, n, d0, fl, 0x80, g, object->mUnk_114.x, object, sphereCenter, &object->mUnk_034, o, p,
                  q, r, s);
    return TRUE;
apply3000:
    func_020e1a80(sphereRadius, k, x, fl, 0x3000, g, object->mUnk_110, object, sphereCenter, &w, o, p, q, r, s);
    return TRUE;
tail:
    x = x - object->mUnk_100;
    if (fl & 0x80) {
        n = n - object->mUnk_104;
    } else {
        n = n + object->mUnk_104;
    }
    return func_020e16dc(sphereRadius, x, n, fl, 0x3000, 0x80, g, d, object->mUnk_110, object->mUnk_114.x, object,
                         sphereCenter, &w, &object->mUnk_034, o, p, q, r, s);
cmp:
    if (k < d0) {
        goto apply3000;
    }
    goto apply80;
}

void func_020e0680(Unk020e005c *object, Vec3 *position, Vec3 *c, Vec3 *d, u16 *e) {
    Vec3 offset;

    if (d != NULL) {
        d->x = -object->mUnk_010.x;
        d->y = -object->mUnk_010.y;
        d->z = -object->mUnk_010.z;
        VEC_Subtract(position, &object->mPos, &offset);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mUnk_028), &object->mUnk_0a0, d, d);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mUnk_034), &object->mUnk_0ac, d, d);
        VEC_MultAdd(Vec3DotUnrounded(&offset, &object->mUnk_040), &object->mUnk_0b8, d, d);
        VEC_Subtract(&offset, d, d);
    }
    if (e != NULL) {
        *e = Vec3DotUnrounded(&object->mUnk_124, c);
    }
}
