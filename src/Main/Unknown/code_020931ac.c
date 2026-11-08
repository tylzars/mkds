#include "Main/Unknown/code_020931ac.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020d2000.h"

#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"

void InitMkdEfBurner(MapObject *arg0) {
    MapObject *value0 = arg0;
    u32 value12;
    CreateMapObjectSoundSourceFalloff2(value0);
}

u8 CollideKartWithMkdEfBurner(MkdEfBurner *a, Kart *b, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (a->mUnk_d4[b->mIndex] == 0 && StartSoundIfKartStarOrKiller(&a->mUnk_00, b) != 0) {
        a->mUnk_00.mDistanceSquaredAndFlags |= data_usa_02156470;
        a->mUnk_d4[b->mIndex] = 0x1f;
    }
    return v;
}

void CreateMkdEfBurner(Unk02093708 *p) {
    gMkdEfBurner = CreateMapObjectModelAnimated(p, gMkdEfBurnerNsbmdName);
    CreateMapObjectModelNsbtaAnimation(gMkdEfBurner, gMkdEfBurnerNsbtaName);
    SetMapObjectModelPolygonId(gMkdEfBurner, 0x3f);
    p->mUnk_1c = 1;
}

void SetupDrawMkdEfBurner(void *a) {
    func_0209bbd0(a, gMkdEfBurner);
}

void DrawMkdEfBurner(void *a, MkdEfBurner *p) {
    s32 s0;
    Vec3 s4;
    Vec3 s10;

    if (p->mUnk_a8 <= 0) {
        return;
    }
    SetMapObjectModelPolygonId(gMkdEfBurner, AllocPolygonIdWrapping());
    s0 = 0x1e;
    func_01ff9048(0x14, &s0, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mPos), 0xc);
    s4.y = p->mUnk_00.mExtent.y >> 4;
    s4.x = 0;
    s4.z = 0;
    func_01ff9048(0x1c, &s4, 3);
    s10.x = p->mUnk_a8;
    s10.y = s10.x;
    s10.z = s10.x;
    func_01ff9048(0x1b, &s10, 3);
    func_01ff9048(0x1b, &p->mUnk_00.mScale, 3);
    SetMapObjectModelNsbtaFrameIndex(gMkdEfBurner, p->mUnk_a4);
    DrawMapObjectModel(a, gMkdEfBurner, p);
}

void InitMkdEfBurnerObjects(MapObjectList *p) {
    BOOL z;
    s32 i;
    MkdEfBurner *e;
    u16 f;
    s32 n;

    if (p == NULL) {
        return;
    }
    z = FALSE;
    f = data_usa_0215646c;
    for (i = 0; i < p->mMapObjectCount && (e = p->mMapObjects[i]) != NULL; i++) {
        e->mUnk_00.mPos.y = e->mUnk_00.mCourseMapRow->mUnk_00.y - e->mUnk_00.mExtent.y;
        if (e->mUnk_00.mCourseMapRow->mUnk_26 < 0) {
            e->mUnk_b0.mGroupIndex = 0xffff;
        } else {
            InitGroupFollower(&e->mUnk_b0, e->mUnk_00.mCourseMapRow, z);
            n = (e->mUnk_00.mCourseMapRow->mUnk_2e << 12) / 100;
            e->mUnk_b0.mSpeed = n;
            e->mUnk_b0.mProgressStep =
                ((s64) n * e->mUnk_b0.mPath->mSegments[e->mUnk_b0.mSegmentIndex].mInverseProgressLength) >> 12;
        }
        if (e->mUnk_00.mCourseMapRow->mUnk_28 == 0 && e->mUnk_00.mCourseMapRow->mUnk_2a == 0 &&
            e->mUnk_00.mCourseMapRow->mUnk_2c == 0) {
            e->mUnk_a8 = 0x1000;
            e->mState = 4;
            e->mUnk_00.mFlags &= ~1;
        } else {
            e->mUnk_a0++;
            if (e->mUnk_a0 >= e->mUnk_00.mCourseMapRow->mUnk_2c) {
                e->mUnk_a0 = 0;
                e->mState = 1;
                e->mUnk_00.mFlags |= f;
                e->mUnk_00.mExtent.y = 0;
            }
        }
    }
}

void UpdateMkdEfBurner(void *a, MkdEfBurner *p) {
    u16 n;
    s32 i;
    u8 c;

    switch (p->mState) {
        case 0:
            p->mUnk_a0++;
            if (p->mUnk_a0 >= p->mUnk_00.mCourseMapRow->mUnk_2a) {
                p->mUnk_a0 = 0;
                p->mState = 1;
                p->mUnk_00.mFlags &= ~1;
            }
            break;
        case 1:
            p->mUnk_a8 += 0x7b;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
                p->mState = 2;
            }
            p->mUnk_00.mExtent.y = ((s64) p->mUnk_00.mKindData->mUnk_10 * p->mUnk_a8) >> 12;
            break;
        case 2:
            p->mUnk_a0++;
            if (p->mUnk_a0 >= p->mUnk_00.mCourseMapRow->mUnk_28) {
                p->mUnk_a0 = 0;
                p->mState = 3;
            }
            StartMapObjectSoundWhileRequested(&p->mUnk_00, 0x170);
            break;
        case 3:
            p->mUnk_a8 -= 0x29;
            if (p->mUnk_a8 <= 0) {
                p->mUnk_a8 = 0;
                p->mState = 0;
                p->mUnk_00.mFlags |= data_usa_0215646c;
            }
            p->mUnk_00.mExtent.y = ((s64) p->mUnk_00.mKindData->mUnk_10 * p->mUnk_a8) >> 12;
            break;
        case 4:
            StartMapObjectSoundWhileRequested(&p->mUnk_00, 0x170);
            break;
    }
    n = GetMapObjectModelNsbtaFrameCount(gMkdEfBurner);
    p->mUnk_a4++;
    if (p->mUnk_a4 >= n) {
        p->mUnk_a4 = 0;
    }
    if (p->mUnk_b0.mGroupIndex != 0xffff) {
        AdvanceGroupFollower(&p->mUnk_b0);
        GetGroupFollowerLinearPosition(&p->mUnk_b0, &p->mUnk_00.mPos);
        p->mUnk_00.mPos.y = p->mUnk_00.mPos.y - p->mUnk_00.mExtent.y;
    } else {
        p->mUnk_00.mPos.y = p->mUnk_00.mCourseMapRow->mUnk_00.y - p->mUnk_00.mExtent.y;
    }
    c = gRaceSetup->mKartCount;
    for (i = 0; i < c; i++) {
        if (p->mUnk_d4[i] > 0) {
            p->mUnk_d4[i]--;
        }
    }
}

void CreateMkdEfBurnerKindData(void) {
    func_0209bf70(&CollideKartWithMkdEfBurner, NULL, NULL, 2, 0, (0x0000018du));
}

void CreateMkdEfBurnerDrawList(void) {
    CreateMapObjectDrawList1(&CreateMkdEfBurner, &DrawMkdEfBurner, &SetupDrawMkdEfBurner);
}

void CreateMkdEfBurnerUpdateList(void) {
    CreateMapObjectUpdateList(&InitMkdEfBurnerObjects, &UpdateMkdEfBurner, NULL);
}

u16 func_020931ac(Unk0217b498_00 *a) {
    if (a->mUnk_a8 >= 0x1000) {
        return 3;
    }
    if (a->mUnk_a8 >= 0x99a) {
        return 2;
    }
    return a->mUnk_a8 >= 0x4cd;
}
