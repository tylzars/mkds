#include "Main/Unknown/code_020e6fd4.h"
#include "code_02146d78.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_0210c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e73a0.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ea000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020e7a40(void) {
    u32 value0;
    u32 requestedState;
    u32 raceKind;
    u32 staffRollKind;
    value0 = gRaceSetup->mRaceKind;
    raceKind = value0;
    staffRollKind = 6u;
    if (raceKind == staffRollKind) {
    }
    if (raceKind == staffRollKind) {
    }
    if (raceKind == staffRollKind) {
        return;
    }
    value0 = (u32) &gJgStateMachine;
    requestedState = 4u;
    SetStateMachineState((void *) value0, requestedState);
}

#pragma thumb off
void func_020e7a18(void) {
    if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        data_0217b8b4 = 0x14;
    }
}

void func_020e79c4(void) {
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    NNS_SndPlayerStopSeq(GetSndHandleSlot(4), 1);
    gJgKart = NULL;
}

#pragma thumb on
void func_020e7760(void) {
    Kart *kart;
    Vec3 *point;
    s32 i;
    Vec3 *sourcePoint;
    BOOL flag;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
        gJgKart = NULL;
        return;
    }
    if (gRaceSetup->mEntryIndex < 0) {
        gJgKart = NULL;
        return;
    }
    gJgKartIndex = gRaceSetup->mEntryIndex;
    kart = GetKart(gJgKartIndex);
    gJgKart = kart;
    data_0217b8c0 = &kart->mKartModelsEntry->mUnk_040;
    gJgTargetPos.x = 0;
    gJgTargetPos.y = 0;
    gJgTargetPos.z = 0;
    data_0217b90c = gJgTargetPos;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    gJgPos = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    gJgVelocity.x = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    gJgEasedPos = gJgPos;
    flag = TRUE;
    data_0217b8f0 = flag;
    data_0217b8bc = flag;
    data_0217b894 = 0;
    if (gCourseMap->mSettings->mUnk_04 != 0) {
        flag = FALSE;
    }
    data_0217b8f8 = flag;
    gJgKind = 4;
    gJgHighestLap = 1;
    gJgFinalLap = GetLapCount();
    InitJgOffsets();
    gJgPoints[0].x = 0;
    gJgPoints[0].y = 0;
    gJgPoints[0].z = 0;
    sourcePoint = data_02159440;
    for (i = 0; i < 7; i++) {
        point = &gJgPoints[i + 1];
        *point = *sourcePoint;
        if (data_0217b8f8 != 0) {
            point->x = -point->x;
            point->y = -point->y;
            point->z = -point->z;
        }
        sourcePoint++;
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            gJgLapAndReverseEnabled = 0;
            break;
        case MODE_MISSION_RUN: {
            BOOL enabled;

            enabled = FALSE;
            if ((u8) (gRaceSetup->mMissionKind + 0xfe) <= 8 &&
                (0x115 & (1 << (u8) (gRaceSetup->mMissionKind + 0xfe))) != 0) {
                enabled = TRUE;
            }
            gJgLapAndReverseEnabled = enabled;
            break;
        }
        default:
            gJgLapAndReverseEnabled = 1;
            break;
    }
    switch (gRaceSetup->mEngineIndex) {
        case 0:
            gJgState2FrameCount = 0x50;
            break;
        case 1:
            gJgState2FrameCount = 0x3c;
            break;
        case 2:
        default:
            gJgState2FrameCount = 0x2d;
            break;
    }
    data_0217b9dc.mUnk_00 = 0x101;
    data_0217b9dc.mUnk_04 = &gJgPos;
    data_0217b9dc.mUnk_08 = 1;
    func_02046be8(&gJgStateMachine, (UnkFunc *const *) gJgStateTable, 7, NULL);
    SetStateMachineState(&gJgStateMachine, 0);
}

void func_020e7460(void) {
    s32 angle;
    s32 j;
    s32 i;
    void *heap;
    Unk0216c324 *sourceRow;
    JgKindRow *kindRow;
    void *file;
    s32 n;
    s32 angleIndex;

    heap = GetHeap(GetCurrentHeapCall());
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    func_020e64b8(&gJgMain, FindSceneFile(data_0216c374), FindSceneFile(data_0216c384), 0);
    func_020e6ab8(&gJgMain);
    gJgMain.mUnk_14 |= 0xc0;
    func_020e64b8(&gJgCloud, FindSceneFile(data_0216c394), NULL, 0);
    func_020e6ab8(&gJgCloud);
    gJgCloud.mUnk_14 |= 0xc0;
    data_0217b8a4 = HeapAlloc(heap, 0x78);
    data_0217b8a8 = HeapAlloc(heap, 0x78);
    data_0217b8a0 = HeapAlloc(heap, 0x78);
    data_0217b8e0 = HeapAlloc(heap, 0x78);
    data_0217b904 = HeapAlloc(heap, 0x78);
    for (i = 0, angle = 0; i < 0x3c; i++) {
        data_0217b8a4[i] = (u16) (((s64) gPairsByAngle[(angle >> 4) * 2] * 0x4c) >> 12);
        angleIndex =
            (u16) (((u64) (s64) gPairsByAngle[((u16) (angle + 0xa218) >> 4) * 2] * 0xb60b60b60b + 0x80000000000) >>
                   44) >>
            4;
        data_0217b8a8[i] = gPairsByAngle[angleIndex * 2];
        data_0217b8a0[i] = gPairsByAngle[angleIndex * 2 + 1];
        data_0217b8e0[i] = (u32) (((s64) gPairsByAngle[((u16) (angle + 0x1554) >> 4) * 2] * 0x19a) >> 12) + 0xe66;
        data_0217b904[i] = (u32) (((s64) gPairsByAngle[((u16) (angle + 0xbbb0) >> 4) * 2] * 0x19a) >> 12) + 0x119a;
        angle += 0x444;
    }
    gJgTableIndex = 0;
    n = 2;
    for (j = n, sourceRow = data_0216c324, kindRow = data_0217bb08; j < 4; j++) {
        if (sourceRow->mUnk_00 != NULL) {
            kindRow->mModel = HeapAlloc(heap, 0x6c);
            file = FindSceneFile(sourceRow->mUnk_00);
            InitNsbmd(kindRow->mModel, file);
            func_02084968(kindRow->mModel, 0x3f, n, 0x294a);
            SetNsbmdCullModeAll(kindRow->mModel, 3);
        } else {
            kindRow->mModel = NULL;
        }
        if (sourceRow->mUnk_04 != NULL) {
            kindRow->mNsbcaAnimation = HeapAlloc(heap, 0x38);
            InitModelAnimationWithEntries(0, kindRow->mModel, kindRow->mNsbcaAnimation, file,
                                          FindSceneFile(sourceRow->mUnk_04));
            func_02087cfc(kindRow->mNsbcaAnimation, 0, 1);
        } else {
            kindRow->mNsbcaAnimation = NULL;
        }
        if (sourceRow->mUnk_08 != NULL) {
            kindRow->mNsbmaAnimation = HeapAlloc(heap, 0x38);
            InitModelAnimationWithEntries(4, kindRow->mModel, kindRow->mNsbmaAnimation, file,
                                          FindSceneFile(sourceRow->mUnk_08));
            func_02087cfc(kindRow->mNsbmaAnimation, 0, 1);
        } else {
            kindRow->mNsbmaAnimation = NULL;
        }
        sourceRow++;
        kindRow++;
    }
    func_020e6488((Unk020e6488 **) gJgKindRowLapModels, FindSceneFile(data_0216c3a4), FindSceneFile(data_0216c3b4), 0);
    func_020e6ab8(gJgKindRows[0].mLapModel);
    gJgKindRows[0].mLapModel->mUnk_14 |= 0xc0;
    func_020e6488((Unk020e6488 **) data_0217bb04, FindSceneFile(data_0216c3c4), 0, 0);
    func_020e6ab8(gJgKindRows[1].mLapModel);
    gJgKindRows[1].mLapModel->mUnk_14 |= 0xc0;
}
#pragma thumb off

Unk020e7410 *func_020e7410(void) {
    Unk020e7410 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = *(Unk020e7410 *) data_02159370;
    return kindData;
}

MapObjectList *func_020e73b4(void) {
    MapObjectList *list;

    list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b864 = list;
    *list = *(MapObjectList *) data_02159348;
    SetUpdateListSlot(&data_0217b864);
    return data_0217b864;
}

Vec3 *GetMapObjectPositionByTableIndex(u32 index) {
    return (*(Vec3 ***) gMapObjectPositionByTableIndex)[index];
}

u16 func_020e7388(int index) {
    u32 value0 = index;
    u32 value1;
    value1 = (u32) &data_0217b868;
    value0 = (value0 << 1);
    value1 = *(const u32 *) ((value1) + (0));
    value0 = *(const u16 *) ((value1) + (value0));
    return value0;
}

#pragma thumb on
void func_020e730c(void) {
    Unk020e730c *object;
    s32 objectCount;
    s32 i;

    objectCount = ((MapObjectList *) data_0217b864)->mMapObjectCount;
    *(void **) gMapObjectPositionByTableIndex = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 4);
    data_0217b868 = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 2);
    for (i = 0; i < ((MapObjectList *) data_0217b864)->mMapObjectCount; i++) {
        s32 tableIndex;

        object = ((MapObjectList *) data_0217b864)->mMapObjects[i];
        tableIndex = object->mTableIndex;
        (*(Vec3 ***) gMapObjectPositionByTableIndex)[tableIndex] = &object->mUnk_00.mPos;
        data_0217b868[tableIndex] = object->mEntryValue;
    }
}

void func_020e72cc(Unk020e730c *object, struct CourseMapRow *courseRow) {
    object->mTableIndex = courseRow->mUnk_28;
    switch (gRaceSetup->mEngineIndex) {
        case 0:
            object->mEntryValue = courseRow->mUnk_2a;
            break;
        case 1:
            object->mEntryValue = courseRow->mUnk_2c;
            break;
        case 2:
            object->mEntryValue = courseRow->mUnk_2e;
            break;
    }
}
#pragma thumb off

void func_020e71a0(MapObject *object) {
    Unk020e71a0_94 *sound;
    BOOL resultIsFalse;
    BOOL hasSoundBit0;

    sound = object->mSound;
    if ((object->mFlags & 2) == 0) {
        sound->mSoundSource.mDistanceSquared = object->mDistanceSquaredAndFlags & ~0xc000001f;
        resultIsFalse = (func_020d4ddc(object) == FALSE);
        hasSoundBit0 = (sound->mSoundSource.mUnk_34 & 1) != 0;
        if (resultIsFalse != FALSE) {
            if (hasSoundBit0 != FALSE) {
                goto ret;
            }
            goto call;
        }
    ret:
        if (resultIsFalse != FALSE) {
            return;
        }
        if (hasSoundBit0 == FALSE) {
            return;
        }
    call:
        SetSoundSourceFlagBit(&sound->mSoundSource, 2, 1);
    } else {
        s32 distanceSquared;

        distanceSquared = GetHorizontalCameraDistanceSquared(&object->mPos);
        sound->mSoundSource.mDistanceSquared = distanceSquared;
        if (func_020d4d60(object, distanceSquared) != FALSE) {
            object->mDistanceSquaredAndFlags |= data_02159310;
            if ((sound->mSoundSource.mUnk_34 & 1) != 0) {
                SetSoundSourceFlagBit(&sound->mSoundSource, 2, 1);
            }
        } else if ((sound->mSoundSource.mUnk_34 & 1) == 0) {
            SetSoundSourceFlagBit(&sound->mSoundSource, 2, 1);
        }
    }
}

void UpdateMapObjectList(MapObjectList *list) {
    MapObject *object;
    Vec3 previousPos;
    void (*callback)(void *list, MapObject *object);
    s32 count;
    void **objects;

    callback = list->mForEachObject;
    count = list->mMapObjectCount;
    objects = list->mMapObjects;
    if (callback == NULL) {
        s32 i;

        for (i = 0; i < count; i++) {
            object = objects[i];
            if (object->mSound != NULL) {
                func_020e71a0(object);
            }
        };
        return;
    }
    if (list->mUnk_18 == 2) {
        s32 i;

        for (i = 0; i < count; i++) {
            object = objects[i];
            if ((object->mFlags & 4) == 0) {
                previousPos = object->mPos;
                callback(list, object);
                VEC_Subtract(&object->mPos, &previousPos, &object->mUnk_10);
                if (object->mSound != NULL) {
                    func_020e71a0(object);
                }
            }
        };
        return;
    }
    {
        s32 i;

        for (i = 0; i < count; i++) {
            object = objects[i];
            if ((object->mFlags & 4) == 0) {
                callback(list, object);
                if (object->mSound != NULL) {
                    func_020e71a0(object);
                }
            }
        }
    }
}

void func_020e6fd4(MapObjectList *list) {
    MapObject *object;
    u8 callbackArgs[2];
    s32 i;
    s32 count;
    void **objects;
    s32 (*callback)(MapObject *, void *, void *, void *);

    count = list->mMapObjectCount;
    callback = list->mUnk_1c;
    objects = list->mMapObjects;
    callbackArgs[0] = list->mUnk_20;
    callbackArgs[1] = 0;
    if (callback == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        object = objects[i];
        if ((object->mFlags & 0x88) == 0) {
            callback(object, NULL, &callbackArgs[0], &callbackArgs[1]);
        }
    }
}
