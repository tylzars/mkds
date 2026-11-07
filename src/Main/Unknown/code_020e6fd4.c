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
    u32 value1;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = gRaceSetup->mUnk_00c;
    compareLeft0 = value0;
    compareRight0 = 6u;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    value0 = (u32) &gJgStateMachine;
    value1 = 4u;
    func_02046bcc((void *) value0, value1);
}

#pragma thumb off
void func_020e7a18(void) {
    if (gRaceSetup->mUnk_00c != 6) {
        data_0217b8b4 = 0x14;
    }
}

void func_020e79c4(void) {
    if (gRaceSetup->mUnk_00c == 6) {
        return;
    }
    NNS_SndPlayerStopSeq(func_02108e6c(4), 1);
    gJgKart = NULL;
}

#pragma thumb on
void func_020e7760(void) {
    Kart *q;
    Vec3 *v;
    s32 i;
    Vec3 *s;
    BOOL a;

    if (gRaceSetup->mUnk_00c == 6) {
        return;
    }
    if (gRaceSetup->mUnk_00c == 3) {
        gJgKart = NULL;
        return;
    }
    if (gRaceSetup->mEntryIndex < 0) {
        gJgKart = NULL;
        return;
    }
    gJgKartIndex = gRaceSetup->mEntryIndex;
    q = GetKart(gJgKartIndex);
    gJgKart = q;
    data_0217b8c0 = &q->mKartModelsEntry->mUnk_040;
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
    a = TRUE;
    data_0217b8f0 = a;
    data_0217b8bc = a;
    data_0217b894 = 0;
    if (gCourseMap->mSettings->mUnk_04 != 0) {
        a = FALSE;
    }
    data_0217b8f8 = a;
    gJgKind = 4;
    gJgHighestLap = 1;
    gJgFinalLap = GetLapCount();
    InitJgOffsets();
    gJgPoints[0].x = 0;
    gJgPoints[0].y = 0;
    gJgPoints[0].z = 0;
    s = data_02159440;
    for (i = 0; i < 7; i++) {
        v = &gJgPoints[i + 1];
        *v = *s;
        if (data_0217b8f8 != 0) {
            v->x = -v->x;
            v->y = -v->y;
            v->z = -v->z;
        }
        s++;
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            gJgLapAndReverseEnabled = 0;
            break;
        case MODE_MISSION_RUN: {
            BOOL b;

            b = FALSE;
            if ((u8) (gRaceSetup->mMissionKind + 0xfe) <= 8 &&
                (0x115 & (1 << (u8) (gRaceSetup->mMissionKind + 0xfe))) != 0) {
                b = TRUE;
            }
            gJgLapAndReverseEnabled = b;
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
    func_02046bcc(&gJgStateMachine, 0);
}

void func_020e7460(void) {
    s32 x;
    s32 j;
    s32 i;
    void *h;
    Unk0216c324 *s;
    JgKindRow *q;
    void *p;
    s32 n;
    s32 k;

    h = GetHeap(func_020364e8());
    if (gRaceSetup->mUnk_00c == 6) {
        return;
    }
    func_020e64b8(&gJgMain, FindSceneFile(data_0216c374), FindSceneFile(data_0216c384), 0);
    func_020e6ab8(&gJgMain);
    gJgMain.mUnk_14 |= 0xc0;
    func_020e64b8(&gJgCloud, FindSceneFile(data_0216c394), NULL, 0);
    func_020e6ab8(&gJgCloud);
    gJgCloud.mUnk_14 |= 0xc0;
    data_0217b8a4 = HeapAlloc(h, 0x78);
    data_0217b8a8 = HeapAlloc(h, 0x78);
    data_0217b8a0 = HeapAlloc(h, 0x78);
    data_0217b8e0 = HeapAlloc(h, 0x78);
    data_0217b904 = HeapAlloc(h, 0x78);
    for (i = 0, x = 0; i < 0x3c; i++) {
        data_0217b8a4[i] = (u16) (((s64) gPairsByAngle[(x >> 4) * 2] * 0x4c) >> 12);
        k = (u16) (((u64) (s64) gPairsByAngle[((u16) (x + 0xa218) >> 4) * 2] * 0xb60b60b60b + 0x80000000000) >> 44) >>
            4;
        data_0217b8a8[i] = gPairsByAngle[k * 2];
        data_0217b8a0[i] = gPairsByAngle[k * 2 + 1];
        data_0217b8e0[i] = (u32) (((s64) gPairsByAngle[((u16) (x + 0x1554) >> 4) * 2] * 0x19a) >> 12) + 0xe66;
        data_0217b904[i] = (u32) (((s64) gPairsByAngle[((u16) (x + 0xbbb0) >> 4) * 2] * 0x19a) >> 12) + 0x119a;
        x += 0x444;
    }
    gJgTableIndex = 0;
    n = 2;
    for (j = n, s = data_0216c324, q = data_0217bb08; j < 4; j++) {
        if (s->mUnk_00 != NULL) {
            q->mModel = HeapAlloc(h, 0x6c);
            p = FindSceneFile(s->mUnk_00);
            InitNsbmd(q->mModel, p);
            func_02084968(q->mModel, 0x3f, n, 0x294a);
            SetNsbmdCullModeAll(q->mModel, 3);
        } else {
            q->mModel = NULL;
        }
        if (s->mUnk_04 != NULL) {
            q->mNsbcaAnimation = HeapAlloc(h, 0x38);
            func_020ea514(0, q->mModel, q->mNsbcaAnimation, p, FindSceneFile(s->mUnk_04));
            func_02087cfc(q->mNsbcaAnimation, 0, 1);
        } else {
            q->mNsbcaAnimation = NULL;
        }
        if (s->mUnk_08 != NULL) {
            q->mNsbmaAnimation = HeapAlloc(h, 0x38);
            func_020ea514(4, q->mModel, q->mNsbmaAnimation, p, FindSceneFile(s->mUnk_08));
            func_02087cfc(q->mNsbmaAnimation, 0, 1);
        } else {
            q->mNsbmaAnimation = NULL;
        }
        s++;
        q++;
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
    Unk020e7410 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = *(Unk020e7410 *) data_02159370;
    return p;
}

MapObjectList *func_020e73b4(void) {
    MapObjectList *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217b864 = p;
    *p = *(MapObjectList *) data_02159348;
    func_020e6f50(&data_0217b864);
    return data_0217b864;
}

Vec3 *func_020e73a0(u32 arg0) {
    return (*(Vec3 ***) data_0217b86c)[arg0];
}

u16 func_020e7388(int arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217b868;
    value0 = (value0 << 1);
    value1 = *(const u32 *) ((value1) + (0));
    value0 = *(const u16 *) ((value1) + (value0));
    return value0;
}

#pragma thumb on
void func_020e730c(void) {
    Unk020e730c *e;
    s32 n;
    s32 i;

    n = ((MapObjectList *) data_0217b864)->mMapObjectCount;
    *(void **) data_0217b86c = HeapAlloc(GetHeap(func_020364e8()), n * 4);
    data_0217b868 = HeapAlloc(GetHeap(func_020364e8()), n * 2);
    for (i = 0; i < ((MapObjectList *) data_0217b864)->mMapObjectCount; i++) {
        s32 k;

        e = ((MapObjectList *) data_0217b864)->mMapObjects[i];
        k = e->mUnk_a0;
        (*(Vec3 ***) data_0217b86c)[k] = &e->mUnk_00.mPos;
        data_0217b868[k] = e->mUnk_a2;
    }
}

void func_020e72cc(Unk020e730c *p, struct CourseMapRow *q) {
    p->mUnk_a0 = q->mUnk_28;
    switch (gRaceSetup->mEngineIndex) {
        case 0:
            p->mUnk_a2 = q->mUnk_2a;
            break;
        case 1:
            p->mUnk_a2 = q->mUnk_2c;
            break;
        case 2:
            p->mUnk_a2 = q->mUnk_2e;
            break;
    }
}
#pragma thumb off

void func_020e71a0(MapObject *p) {
    Unk020e71a0_94 *q;
    BOOL a;
    BOOL b;

    q = p->mSound;
    if ((p->mFlags & 2) == 0) {
        q->mSoundSource.mDistanceSquared = p->mDistanceSquaredAndFlags & ~0xc000001f;
        a = (func_020d4ddc(p) == FALSE);
        b = (q->mSoundSource.mUnk_34 & 1) != 0;
        if (a != FALSE) {
            if (b != FALSE) {
                goto ret;
            }
            goto call;
        }
    ret:
        if (a != FALSE) {
            return;
        }
        if (b == FALSE) {
            return;
        }
    call:
        SetSoundSourceFlagBit(&q->mSoundSource, 2, 1);
    } else {
        s32 v;

        v = func_020d4ef4(&p->mPos);
        q->mSoundSource.mDistanceSquared = v;
        if (func_020d4d60(p, v) != FALSE) {
            p->mDistanceSquaredAndFlags |= data_02159310;
            if ((q->mSoundSource.mUnk_34 & 1) != 0) {
                SetSoundSourceFlagBit(&q->mSoundSource, 2, 1);
            }
        } else if ((q->mSoundSource.mUnk_34 & 1) == 0) {
            SetSoundSourceFlagBit(&q->mSoundSource, 2, 1);
        }
    }
}

void UpdateMapObjectList(MapObjectList *p) {
    MapObject *e;
    Vec3 t;
    void (*cb)(void *p, MapObject *e);
    s32 n;
    void **arr;

    cb = p->mForEachObject;
    n = p->mMapObjectCount;
    arr = p->mMapObjects;
    if (cb == NULL) {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if (e->mSound != NULL) {
                func_020e71a0(e);
            }
        };
        return;
    }
    if (p->mUnk_18 == 2) {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if ((e->mFlags & 4) == 0) {
                t = e->mPos;
                cb(p, e);
                VEC_Subtract(&e->mPos, &t, &e->mUnk_10);
                if (e->mSound != NULL) {
                    func_020e71a0(e);
                }
            }
        };
        return;
    }
    {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if ((e->mFlags & 4) == 0) {
                cb(p, e);
                if (e->mSound != NULL) {
                    func_020e71a0(e);
                }
            }
        }
    }
}

void func_020e6fd4(MapObjectList *p) {
    MapObject *e;
    u8 buf[2];
    s32 i;
    s32 n;
    void **arr;
    s32 (*cb)(MapObject *, void *, void *, void *);

    n = p->mMapObjectCount;
    cb = p->mUnk_1c;
    arr = p->mMapObjects;
    buf[0] = p->mUnk_20;
    buf[1] = 0;
    if (cb == NULL) {
        return;
    }
    for (i = 0; i < n; i++) {
        e = arr[i];
        if ((e->mFlags & 0x88) == 0) {
            cb(e, NULL, &buf[0], &buf[1]);
        }
    }
}
