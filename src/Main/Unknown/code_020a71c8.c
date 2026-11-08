#include "Main/Unknown/code_020a71c8.h"

#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a3f2c.h"
#include "Main/Unknown/code_020a73b0.h"
#include "Main/Unknown/code_020a7eb0.h"
#include "Main/Unknown/code_020a7eb4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020a737c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_020a8098.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/code_020a8080.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_02077bc0.h"

void InitSanbo(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value1 = *(const u32 *) ((value0) + (156));
    value0 = (value0) + (0x1d8u);
    value2 = 0u;
    InitGroupFollower((GroupFollower *) value0, (CourseMapRow *) value1, value2);
}

u8 CollideKartWithSanbo(Sanbo *p, Kart *a, u8 *b, u8 *c) {
    Unk0210b7a8 s;
    u32 d;

    d = *c;
    if (*b == 1) {
        StartSanboLaunch(p);
        p->mUnk_000.mFlags = p->mUnk_000.mFlags | data_021567e4;
        p->mUnk_000.mFlags = p->mUnk_000.mFlags | data_021567e8;
        StartSoundIfKartStarOrKiller(&p->mUnk_000, a);
    } else {
        if (p->mFastWobbleTimer == 0) {
            s.mSoundId = 0x193;
            s.mPositionSource = &p->mUnk_000.mPos;
            s.mUnk_08 = 2;
            s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&p->mUnk_000.mPos);
            func_0210b7a8(&s);
            p->mSoundTimer = 0x14;
        }
        p->mFastWobbleTimer = 0x3c;
    }
    return d;
}

u8 CollideItemObjectWithSanbo(Sanbo *p, ItemObject *a, u8 *b, u8 *c) {
    Unk0210b7a8 s;
    u32 d;

    d = *c;
    if (*b == 1) {
        StartSanboLaunch(p);
        p->mUnk_000.mFlags = p->mUnk_000.mFlags | data_021567e4;
        p->mUnk_000.mFlags = p->mUnk_000.mFlags | data_021567e8;
    } else {
        if (p->mFastWobbleTimer == 0) {
            s.mSoundId = 0x193;
            s.mPositionSource = &p->mUnk_000.mPos;
            s.mUnk_08 = 2;
            s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&p->mUnk_000.mPos);
            func_0210b7a8(&s);
            p->mSoundTimer = 0x14;
        }
        p->mFastWobbleTimer = 0x3c;
    }
    return d;
}

void CreateSanboHAndSanboB(void *a) {
    gSanboH = CreateMapObjectModelNsbmd(a, gSanboHNsbmdName);
    gSanboB = CreateMapObjectModelNsbmd(a, gSanboBNsbmdName);
    SetMapObjectModelPolygonId(gSanboH, 0x3f);
    SetMapObjectModelPolygonId(gSanboB, 0x3f);
}

u32 func_020a7eb0(u32 p0) {
    return p0;
}

void DrawSanbo(void *a, Sanbo *p) {
    s32 i;
    s32 k;
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m0[9];
    s32 m1[9];
    s32 f0[3];
    s32 f1[3];
    s32 f2[3];
    s32 g2[3];
    s32 f3[3];
    s32 g3[3];
    s32 t;

    w0 = 0x1e;
    func_01ff9048(0x14, &w0, 1);
    switch (p->mState) {
        case 0:
        case 1:
            func_01ff9048(0x19, SetViewTransposeMatrixPos(&p->mUnk_000.mPos), 12);
            f0[0] = 0;
            f0[1] = 0xa00;
            f0[2] = 0;
            func_01ff9048(0x1c, f0, 3);
            for (i = 0; i < p->mPieceCount; i++) {
                if (p->mPieces[i].mRotateZAngle != 0) {
                    k = ((u16) p->mPieces[i].mRotateZAngle >> 4) * 2;
                    MTX_RotZ33_(m0, gPairsByAngle[k], gPairsByAngle[k + 1]);
                    func_01ff9048(0x1a, m0, 9);
                }
                if (i != 0) {
                    f1[0] = 0;
                    f1[1] = 0x1400;
                    f1[2] = 0x80;
                    func_01ff9048(0x1c, f1, 3);
                }
                if (i == 3) {
                    func_0209bbd0(a, gSanboH);
                    DrawMapObjectModel(a, gSanboH, p);
                } else {
                    func_0209bbd0(a, gSanboB);
                    DrawMapObjectModel(a, gSanboB, p);
                }
            }
            break;
        case 2:
            for (i = 0; i < p->mPieceCount; i++) {
                w1 = 0x1e;
                func_01ff9048(0x14, &w1, 1);
                f2[0] = 0;
                f2[1] = 0xa00;
                f2[2] = 0;
                func_01ff9048(0x1c, f2, 3);
                func_01ff9048(0x19, SetViewTransposeMatrixPos(&p->mPieces[i].mPos), 12);
                if ((p->mUnk_000.mFlags & 0x12) == 0 && p->mPieces[i].mRotateZAngle != 0) {
                    k = ((u16) p->mPieces[i].mRotateZAngle >> 4) * 2;
                    MTX_RotZ33_(m1, gPairsByAngle[k], gPairsByAngle[k + 1]);
                    func_01ff9048(0x1a, m1, 9);
                }
                t = p->mPieces[i].mDrawScale;
                if (t < 0x1000) {
                    g2[0] = t;
                    g2[1] = t;
                    g2[2] = 0;
                    func_01ff9048(0x1b, g2, 3);
                }
                if (i == 3) {
                    func_0209bbd0(a, gSanboH);
                    DrawMapObjectModel(a, gSanboH, p);
                } else {
                    func_0209bbd0(a, gSanboB);
                    DrawMapObjectModel(a, gSanboB, p);
                }
            }
            break;
        case 3:
            for (i = 0; i < p->mPieceCount; i++) {
                w2 = 0x1e;
                func_01ff9048(0x14, &w2, 1);
                func_01ff9048(0x19, SetViewTransposeMatrixPos(&p->mUnk_000.mPos), 12);
                f3[2] = 0x80;
                f3[0] = 0;
                f3[1] = (i * 0x14000 + 0xa000) >> 4;
                func_01ff9048(0x1c, f3, 3);
                t = p->mPieces[i].mDrawScale;
                if (t < 0x1000) {
                    g3[0] = t;
                    g3[1] = t;
                    g3[2] = 0;
                    func_01ff9048(0x1b, g3, 3);
                }
                if (i == 3) {
                    func_0209bbd0(a, gSanboH);
                    DrawMapObjectModel(a, gSanboH, p);
                } else {
                    func_0209bbd0(a, gSanboB);
                    DrawMapObjectModel(a, gSanboB, p);
                }
            }
            break;
    }
}

void InitSanboObjects(MapObjectList *l) {
    s32 j;
    s32 i;
    Sanbo *o;

    if (l == NULL) {
        return;
    }
    for (i = 0; i < l->mMapObjectCount && (o = l->mMapObjects[i]) != NULL; i++) {
        o->mPathSpeed = (o->mUnk_000.mCourseMapRow->mUnk_28 << 12) / 100;
        o->mPieceCount = 4;
        for (j = 0; j < o->mPieceCount; j++) {
            o->mPieces[j].mWobbleAngle = 0;
            o->mPieces[j].mWobbleMid = 0;
            o->mPieces[j].mWobbleAmplitude = 0x71c;
            o->mPieces[j].mWobbleAmplitudePerFrame = 0;
            o->mPieces[j].mWobbleAnglePerFrame = 0x2d8;
            o->mPieces[j].mUnk_38 = 0;
            o->mPieces[j].mDrawScale = 0x1000;
            o->mPieces[j].mRotateZAngle = 0;
            o->mPieces[j].mWobbleDelayTimer = j * 0x14;
        }
    }
}

s32 func_020a78b0(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_020a7894(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void UpdateSanbo(void *a, Sanbo *p) {
    Unk0210b7a8 s;
    s32 m;
    s32 k;
    s32 i;
    s32 j;
    s32 t;
    s32 v;

    if (p->mPathWaitTimer-- <= 0) {
        t = p->mPathSpeed;
        p->mFollower.mSpeed = t;
        p->mFollower.mProgressStep =
            (s64) t * p->mFollower.mPath->mSegments[p->mFollower.mSegmentIndex].mInverseProgressLength >> 12;
        if (AdvanceGroupFollower(&p->mFollower) != FALSE) {
            p->mPathWaitTimer = (u16) p->mFollower.mFromEntry->mUnk_0e;
        } else {
            p->mPathWaitTimer = 0;
        }
        if (p->mFollower.mPath->mWraps != 0) {
            GetGroupFollowerCurvePosStep(&p->mFollower, &p->mUnk_000.mPos, &p->mUnk_000.mUnk_10);
        } else {
            GetGroupFollowerLinearPosStep(&p->mFollower, &p->mUnk_000.mPos, &p->mUnk_000.mUnk_10);
        }
    } else {
        p->mFollower.mSpeed = 0;
        p->mFollower.mProgressStep = 0;
        p->mUnk_000.mUnk_10.x = 0;
        p->mUnk_000.mUnk_10.y = 0;
        p->mUnk_000.mUnk_10.z = 0;
    }
    switch (p->mState) {
        case 0:
            if ((p->mUnk_000.mFlags & 0x12) != 0) {
                return;
            }
            for (i = 0; i < p->mPieceCount; i++) {
                if (p->mFastWobbleTimer > 0) {
                    p->mPieces[i].mWobbleAnglePerFrame = 0xb61;
                } else if (p->mPieces[i].mWobbleAnglePerFrame > 0x38e) {
                    p->mPieces[i].mWobbleAnglePerFrame = p->mPieces[i].mWobbleAnglePerFrame - 0xb6;
                } else {
                    p->mPieces[i].mWobbleAnglePerFrame = 0x2d8;
                }
                if (p->mPieces[i].mWobbleDelayTimer-- <= 0) {
                    p->mPieces[i].mWobbleDelayTimer = 0;
                    p->mPieces[i].mWobbleAngle = p->mPieces[i].mWobbleAngle + p->mPieces[i].mWobbleAnglePerFrame;
                    p->mPieces[i].mUnk_24 =
                        p->mPieces[i].mWobbleMid +
                        func_020a7894(p->mPieces[i].mWobbleAmplitude, func_020a78b0(p->mPieces[i].mWobbleAngle)) -
                        p->mPieces[i].mWobbleValue;
                    p->mPieces[i].mWobbleValue = p->mPieces[i].mWobbleValue + p->mPieces[i].mUnk_24;
                    t = p->mPieces[i].mWobbleAmplitude;
                    if (t > 0) {
                        v = t + p->mPieces[i].mWobbleAmplitudePerFrame;
                        if (v <= 0) {
                            v = 0;
                        }
                        p->mPieces[i].mWobbleAmplitude = v;
                    } else if (t < 0) {
                        v = t + p->mPieces[i].mWobbleAmplitudePerFrame;
                        if (v >= 0) {
                            v = 0;
                        }
                        p->mPieces[i].mWobbleAmplitude = v;
                    }
                    t = p->mPieces[i].mWobbleAnglePerFrame;
                    if (t > 0) {
                        v = t + p->mPieces[i].mUnk_38;
                        if (v <= 0) {
                            v = 0;
                        }
                        p->mPieces[i].mWobbleAnglePerFrame = v;
                    } else if (t < 0) {
                        v = t + p->mPieces[i].mUnk_38;
                        if (v >= 0) {
                            v = 0;
                        }
                        p->mPieces[i].mWobbleAnglePerFrame = v;
                    }
                    p->mPieces[i].mRotateZAngle = (u16) p->mPieces[i].mWobbleValue;
                }
            }
            if (p->mFastWobbleTimer <= 0) {
                return;
            }
            p->mFastWobbleTimer = p->mFastWobbleTimer - 1;
            if (p->mSoundTimer > 0) {
                p->mSoundTimer = p->mSoundTimer - 1;
                return;
            }
            if (p->mPieces[0].mWobbleAngle <= 0x8000) {
                return;
            }
            if (p->mPieces[0].mWobbleAngle >= 0xc000) {
                return;
            }
            s.mSoundId = 0x194;
            s.mPositionSource = &p->mUnk_000.mPos;
            s.mUnk_08 = 2;
            s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&p->mUnk_000.mPos);
            func_0210b7a8(&s);
            p->mSoundTimer = 0x14;
            break;
        case 2:
            for (j = 0; j < p->mPieceCount; j++) {
                if (p->mPieces[j].mPos.y > 0) {
                    p->mPieces[j].mPos.x = p->mPieces[j].mPos.x + p->mPieces[j].mVelocity.x;
                    p->mPieces[j].mPos.y = p->mPieces[j].mPos.y + p->mPieces[j].mVelocity.y;
                    p->mPieces[j].mPos.z = p->mPieces[j].mPos.z + p->mPieces[j].mVelocity.z;
                    p->mPieces[j].mVelocity.y = p->mPieces[j].mVelocity.y - 0x400;
                }
            }
            if ((p->mUnk_000.mFlags & 0x12) == 0) {
                for (m = 0; m < p->mPieceCount; m++) {
                    p->mPieces[m].mRotateZAngle = p->mPieces[m].mRotateZAngle + p->mPieces[m].mRotateZAnglePerFrame;
                }
            }
            if (p->mUnk_000.mCourseMapRow->mUnk_2a != 0) {
                return;
            }
            if (p->mState2Timer-- > 0) {
                return;
            }
            for (k = 0; k < p->mPieceCount; k++) {
                p->mPieces[k].mWobbleAngle = 0;
                p->mPieces[k].mDrawScale = 0;
                p->mPieces[k].mRotateZAngle = 0;
                p->mPieces[k].mWobbleDelayTimer = k * 0x14;
            }
            p->mPieceCount = 1;
            p->mState = 3;
            p->mUnk_000.mFlags = p->mUnk_000.mFlags & ~1;
            p->mUnk_000.mFlags = p->mUnk_000.mFlags & ~8;
            break;
        case 3:
            p->mPieces[p->mPieceCount - 1].mDrawScale = p->mPieces[p->mPieceCount - 1].mDrawScale + 0xcd;
            if (p->mPieces[p->mPieceCount - 1].mDrawScale < 0x1000) {
                return;
            }
            p->mPieces[p->mPieceCount - 1].mDrawScale = 0x1000;
            p->mPieceCount = p->mPieceCount + 1;
            if (p->mPieceCount > 4) {
                p->mPieceCount = 4;
                p->mState = 0;
            }
            break;
    }
}

void CreateSanboKindData(void) {
    CreateMapObjectKindData(&CollideKartWithSanbo, &CollideItemObjectWithSanbo, NULL, 1, 1);
}

void *CreateSanboDrawList(void) {
    return CreateMapObjectDrawList2(CreateSanboHAndSanboB, DrawSanbo, func_020a7eb0);
}

void *CreateSanboUpdateList(void) {
    return CreateMapObjectUpdateList(InitSanboObjects, UpdateSanbo, NULL);
}

BOOL ShineKartHitCallback(u16 a, u16 b) {
    if (GetBalloonOrShineCount(a) != 0) {
        AddBalloonOrShineCountAndMoveRank(a, -1);
        if (b >= 8) {
            b = a;
        }
        StartShine16FromKart(GetKart(a), GetKart(b));
        return TRUE;
    }
    return FALSE;
}

void ShineKartEliminatedCallback(u16 a) {
    if (GetBalloonOrShineCount(a) == 0) {
        return;
    }
    AddBalloonOrShineCountAndMoveRank(a, -1);
    StartShine16FromKart(GetKart(a), GetKart(a));
}

void ShineEndCallback(void) {
    s32 i;
    MapObject *o;
    MapObjectList *l;

    l = FindMapObjectKindUpdateList(0x6b);
    if (l != NULL) {
        for (i = 0; i < l->mMapObjectCount && (o = l->mMapObjects[i]) != NULL; i++) {
            if ((o->mFlags & 0x100) == 0) {
                ParkMapObject(o);
            }
        }
    }
    l = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE_BALLOON);
    if (l != NULL) {
        for (i = 0; i < l->mMapObjectCount && (o = l->mMapObjects[i]) != NULL; i++) {
            if ((o->mFlags & 0x100) == 0) {
                ParkMapObject(o);
            }
        }
    }
    ParkShine16Objects();
}
