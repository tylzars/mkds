#include "Main/Unknown/code_0209a748.h"
#include "code_02146d78.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_02077bc0.h"

void InitCrab(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value1 = *(const u32 *) ((value0) + (156));
    value0 = (value0) + (0xf0u);
    value2 = 0u;
    InitGroupFollower((GroupFollower *) value0, (CourseMapRow *) value1, value2);
}

static inline u32 func_0209b388_inline(RandomState64 *r, u32 c) {
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    if (c == 0) {
        return r->mValue >> 32;
    } else {
        return ((r->mValue >> 32) * c) >> 32;
    }
}

void func_0209b388(Crab *a, Vec3 *b, Vec3 *c, Vec3 *d) {
    Vec3 v;
    RandomState64 *r;
    s32 x;
    s32 z;

    if (b != NULL && c != NULL) {
        VEC_Subtract(&a->mUnk_000.mPos, b, &v);
        z = c->z;
        x = c->x;
        if ((s64) v.z * x - (s64) v.x * z < 0) {
            v.z = -x;
            v.x = z;
            v.y = 0;
            a->mUnk_0a0 = 0x71c;
        } else {
            v.z = x;
            v.x = -z;
            v.y = 0;
            a->mUnk_0a0 = 0xf8e4;
        }
        a->mUnk_000.mUnk_10.x = ((s64) v.x * 0x1800) >> 12;
        a->mUnk_000.mUnk_10.y = ((s64) v.y * 0x1800) >> 12;
        a->mUnk_000.mUnk_10.z = ((s64) v.z * 0x1800) >> 12;
    } else {
        r = GetMapObjectRandom();
        z = (u16) func_0209b388_inline(r, 0x10000);
        x = gPairsByAngle[((u16) z >> 4) * 2 + 1];
        x = ((s64) x * 0x1800) >> 12;
        a->mUnk_000.mUnk_10.x = x;
        a->mUnk_000.mUnk_10.z = x;
        r = GetMapObjectRandom();
        if ((u16) func_0209b388_inline(r, 2) != 0) {
            a->mUnk_0a0 = 0x71c;
        } else {
            a->mUnk_0a0 = 0xf8e4;
        }
    }
    if (d != NULL) {
        a->mUnk_000.mUnk_10.x += d->x / 2;
        a->mUnk_000.mUnk_10.z += d->z / 2;
    }
    a->mUnk_000.mUnk_10.y = 0x4000;
    a->mUnk_0a4 = 0x12c;
    a->mState = 2;
    a->mUnk_000.mFlags |= data_usa_0215659c;
}

u8 CollideKartWithCrab(Crab *a, Kart *b, u8 *c, u8 *d) {
    u32 e;

    e = *d;
    if (*c == 1) {
        func_0209b388(a, &b->mPos, &b->mEasedTurnedForward, &b->mVelocity);
        StartSoundIfKartStarOrKiller(&a->mUnk_000, b);
    }
    return e;
}

u8 CollideItemObjectWithCrab(Crab *a, Kart *b, u8 *c, u8 *d) {
    Vec3 v;
    Kart *t;
    u32 e;

    e = *d;
    if (*c == 1) {
        if (b != NULL) {
            if ((s64) b->mSignedTurnedForward.x * b->mSignedTurnedForward.x +
                    (s64) b->mSignedTurnedForward.y * b->mSignedTurnedForward.y +
                    (s64) b->mSignedTurnedForward.z * b->mSignedTurnedForward.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&b->mSignedTurnedForward, &v);
                func_0209b388(a, &b->mTurnedForward, &v, NULL);
            } else {
                func_0209b388(a, NULL, NULL, NULL);
            }
            func_020f8ddc(b);
        } else {
            t = GetKart((u16) gRaceSetup->mEntryIndex);
            func_0209b388(a, &t->mPos, &t->mEasedTurnedForward, &t->mVelocity);
        }
    }
    return e;
}

void CreateCrabAndCrabHand(void *a) {
    gCrab = CreateMapObjectModelNsbmdNsbtp(a, "crab.nsbmd", "crab.nsbtp");
    gCrabHand = CreateMapObjectModelNsbmdNsbtp(a, "crab_hand.nsbmd", "crab_hand.nsbtp");
    SetMapObjectModelPolygonId(gCrab, 0x3f);
    SetMapObjectModelPolygonId(gCrabHand, 0x3f);
}

u32 func_0209b1f8(u32 p0) {
    return p0;
}

void DrawCrab(void *a, Crab *b) {
    s32 w;
    s32 f0[9];
    s32 f1[9];

    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_020e6d88(&b->mUnk_000.mMatrix.mUnk_00[1]);
    func_01ff9048(0x19, func_020e6bd0(&b->mUnk_000.mPos), 0xc);
    if (b->mUnk_0a2 != 0) {
        MTX_RotZ33_(f0, gPairsByAngle[(b->mUnk_0a2 >> 4) * 2], gPairsByAngle[(b->mUnk_0a2 >> 4) * 2 + 1]);
        func_01ff9048(0x1a, f0, 9);
    }
    func_01ff9048(0x1b, &b->mUnk_000.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gCrab, b->mUnk_0a8 >> 12);
    func_0209bbd0(a, gCrab);
    DrawMapObjectModel(a, gCrab, b);
    MTX_RotZ33_(f1, gPairsByAngle[((u16) b->mUnk_0d0.mUnk_04 >> 4) * 2],
                gPairsByAngle[((u16) b->mUnk_0d0.mUnk_04 >> 4) * 2 + 1]);
    func_01ff9048(0x1a, f1, 9);
    SetMapObjectModelNsbtpFrameIndex(gCrabHand, b->mUnk_0ac >> 12);
    func_0209bbd0(a, gCrabHand);
    DrawMapObjectModel(a, gCrabHand, b);
}

void InitCrabObjects(Unk0209af98 *p) {
    s32 i;
    Crab *o;
    RandomState64 *r;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != NULL; i++) {
        o->mUnk_0d0.mUnk_00 = 0;
        o->mUnk_0d0.mUnk_0c = 0;
        o->mUnk_0d0.mUnk_10 = 0x1c7;
        o->mUnk_0d0.mUnk_14 = 0;
        o->mUnk_0d0.mUnk_18 = 0xe39;
        o->mUnk_0d0.mUnk_1c = 0;
        r = GetMapObjectRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        o->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mValue >> 32) * 60) >> 32) + 30);
        o->mState = 0;
    }
}

s16 func_0209af80(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_0209af64(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

static inline void func_0209a7dc_inline(Unk0209a7dc_b0 *b) {
    s32 t;

    b->mUnk_00 += b->mUnk_18;
    b->mUnk_08 = b->mUnk_0c + func_0209af64(b->mUnk_10, func_0209af80(b->mUnk_00)) - b->mUnk_04;
    b->mUnk_04 += b->mUnk_08;
    if (b->mUnk_10 > 0) {
        t = b->mUnk_10 + b->mUnk_14;
        if (t <= 0) {
            t = 0;
        }
        b->mUnk_10 = t;
    } else if (b->mUnk_10 < 0) {
        t = b->mUnk_10 + b->mUnk_14;
        if (t >= 0) {
            t = 0;
        }
        b->mUnk_10 = t;
    }
    if (b->mUnk_18 > 0) {
        t = b->mUnk_18 + b->mUnk_1c;
        if (t <= 0) {
            t = 0;
        }
        b->mUnk_18 = t;
    } else if (b->mUnk_18 < 0) {
        t = b->mUnk_18 + b->mUnk_1c;
        if (t >= 0) {
            t = 0;
        }
        b->mUnk_18 = t;
    }
}

void UpdateCrab(void *a, Crab *b) {
    Vec3 v;
    RandomState64 *r;

    switch (b->mState) {
        case 0:
            b->mUnk_0ac += 0x200;
            if (b->mUnk_0ac >= (s32) (GetMapObjectModelNsbtpFrameCount(gCrabHand) > 0
                                          ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12)
                                          : (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12) - 0.5f)) {
                b->mUnk_0ac = 0;
            }
            if (b->mUnk_0a4-- > 0) {
                return;
            }
            if (b->mUnk_0ac == 0) {
                b->mState = 1;
            }
            break;
        case 1:
            b->mUnk_0f0.mSpeed = 0x800;
            b->mUnk_0f0.mProgressStep =
                ((s64) b->mUnk_0f0.mPath->mSegments[b->mUnk_0f0.mSegmentIndex].mInverseProgressLength * 0x800) >> 12;
            if (AdvanceGroupFollower(&b->mUnk_0f0) != FALSE) {
                b->mUnk_0d0.mUnk_00 = 0;
                b->mUnk_0d0.mUnk_0c = 0;
                b->mUnk_0d0.mUnk_10 = 0x1c7;
                b->mUnk_0d0.mUnk_14 = 0;
                b->mUnk_0d0.mUnk_18 = 0xe39;
                b->mUnk_0d0.mUnk_1c = 0;
                r = GetMapObjectRandom();
                r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                b->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mValue >> 32) * 60) >> 32) + 30);
                b->mState = 0;
            }
            b->mUnk_0a8 += 0x200;
            if (b->mUnk_0a8 >= (s32) (GetMapObjectModelNsbtpFrameCount(gCrab) > 0
                                          ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrab) << 12)
                                          : (GetMapObjectModelNsbtpFrameCount(gCrab) << 12) - 0.5f)) {
                b->mUnk_0a8 = 0;
            }
            func_0209a7dc_inline(&b->mUnk_0d0);
            GetGroupFollowerLinearPosition(&b->mUnk_0f0, &b->mUnk_000.mPos);
            v = *GetGroupFollowerSegmentUp(&b->mUnk_0f0);
            VEC_Subtract(&v, &b->mUnk_000.mMatrix.mUnk_00[1], &v);
            v.x = ((s64) v.x * 0x800) >> 12;
            v.y = ((s64) v.y * 0x800) >> 12;
            v.z = ((s64) v.z * 0x800) >> 12;
            VEC_Add(&b->mUnk_000.mMatrix.mUnk_00[1], &v, &b->mUnk_000.mMatrix.mUnk_00[1]);
            if ((s64) b->mUnk_000.mMatrix.mUnk_00[1].x * b->mUnk_000.mMatrix.mUnk_00[1].x +
                    (s64) b->mUnk_000.mMatrix.mUnk_00[1].y * b->mUnk_000.mMatrix.mUnk_00[1].y +
                    (s64) b->mUnk_000.mMatrix.mUnk_00[1].z * b->mUnk_000.mMatrix.mUnk_00[1].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&b->mUnk_000.mMatrix.mUnk_00[1], &b->mUnk_000.mMatrix.mUnk_00[1]);
            }
            break;
        case 2:
            if (b->mUnk_0a4-- > 0) {
                b->mUnk_000.mUnk_10.y -= 0x400;
                VEC_Add(&b->mUnk_000.mPos, &b->mUnk_000.mUnk_10, &b->mUnk_000.mPos);
                b->mUnk_0a2 += b->mUnk_0a0;
                return;
            }
            SetupGroupFollowerAtEntry(&b->mUnk_0f0, 0, 0);
            GetGroupFollowerLinearXz(&b->mUnk_0f0, &b->mUnk_000.mPos);
            b->mUnk_000.mPos.y = b->mUnk_000.mCourseMapRow->mUnk_00.y - 0x5000;
            b->mUnk_0b0.mUnk_00 = 0;
            b->mUnk_0b0.mUnk_0c = 0;
            b->mUnk_0b0.mUnk_10 = 0x2aab;
            b->mUnk_0b0.mUnk_14 = -0xb6;
            b->mUnk_0b0.mUnk_18 = 0x71c;
            b->mUnk_0b0.mUnk_1c = 0;
            func_0209a7dc_inline(&b->mUnk_0b0);
            b->mUnk_0a2 = b->mUnk_0b0.mUnk_04;
            b->mState = 3;
            break;
        case 3:
            b->mUnk_0ac += 0x200;
            if (b->mUnk_0ac >= (s32) (GetMapObjectModelNsbtpFrameCount(gCrabHand) > 0
                                          ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12)
                                          : (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12) - 0.5f)) {
                b->mUnk_0ac = 0;
            }
            func_0209a7dc_inline(&b->mUnk_0b0);
            b->mUnk_0a2 = b->mUnk_0b0.mUnk_04;
            b->mUnk_000.mPos.y += 0x200;
            if (b->mUnk_000.mPos.y < b->mUnk_000.mCourseMapRow->mUnk_00.y) {
                return;
            }
            b->mUnk_000.mPos.y = b->mUnk_000.mCourseMapRow->mUnk_00.y;
            b->mUnk_000.mUnk_10.x = 0;
            b->mUnk_000.mUnk_10.y = 0;
            b->mUnk_000.mUnk_10.z = 0;
            b->mUnk_0a2 = 0;
            b->mUnk_0d0.mUnk_00 = 0;
            b->mUnk_0d0.mUnk_0c = 0;
            b->mUnk_0d0.mUnk_10 = 0x1c7;
            b->mUnk_0d0.mUnk_14 = 0;
            b->mUnk_0d0.mUnk_18 = 0xe39;
            b->mUnk_0d0.mUnk_1c = 0;
            r = GetMapObjectRandom();
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            b->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mValue >> 32) * 60) >> 32) + 30);
            b->mState = 0;
            b->mUnk_000.mFlags &= ~1;
            break;
    }
}

void CreateCrabKindData(void) {
    Unk0209bf70 *o;

    o = func_0209bf70(CollideKartWithCrab, CollideItemObjectWithCrab, NULL, 2, 1, 0x10e);
    o->mUnk_28 = 0x10f;
}

void *CreateCrabDrawList(void) {
    return CreateMapObjectDrawList2(CreateCrabAndCrabHand, DrawCrab, func_0209b1f8);
}

void *CreateCrabUpdateList(void) {
    return CreateMapObjectUpdateList(InitCrabObjects, UpdateCrab, NULL);
}
