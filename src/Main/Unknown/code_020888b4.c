#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_020800f4.h"
#include "Main/Unknown/code_02080cd0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_02080000.h"
#include "Main/Unknown/code_020808d4.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a228c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02077bc0.h"

static inline s32 func_020888b4_inline(const Vec3 *a, const Vec3 *b) {
    s32 x = (a->x - b->x) >> 12;
    s32 z = (a->z - b->z) >> 12;

    return x * x + z * z;
}

// Recomputes the CPU kart's speed limit on its own turn of eight frames and sets the kart's limit from it.
void AdvanceBattleKartAiSpeedLimit(KartAiSpeedLimit *a, KartAi *b) {
    s32 m;
    Kart *q;

    if (b->mIndex == GetRaceUpdateFramesMod8()) {
        a->mUnk_0c = FALSE;
        m = b->mKart->mSpeedLimitGoal;
        if (m > 0xa000) {
            m = 0xa000;
        }
        SetBattleKartAiTurnSpeedLimit(a, b, m);
        if (a->mTurnSpeedLimit < m) {
            m = a->mTurnSpeedLimit;
        }
        if (m > 0xa000) {
            m = 0xa000;
        }
        a->mSpeedLimit = m;
        if (b->mLinkSpeedLimit != 0) {
            if (a->mSpeedLimit > b->mLinkSpeedLimit) {
                a->mSpeedLimit = b->mLinkSpeedLimit;
            }
        }
    }
    q = b->mKart;
    if (q->mState != KART_STATE_NORMAL) {
        return;
    }
    if ((q->mUnk_48 & 0x10000020) == 0) {
        q->mSpeedLimitGoal = a->mSpeedLimit;
    }
}

void SetBattleKartAiTurnSpeedLimit(KartAiSpeedLimit *a, KartAi *b, s32 c) {
    s32 t;

    a->mTurnSpeedLimit = c;
    if (b->mTurnAngleDegrees <= 0x5000) {
        return;
    }
    t = ((s64) (b->mTurnAngleDegrees - 0x5000) * 0x5b + 0x800) >> 12;
    if (t > 0x1000) {
        t = 0x1000;
    }
    a->mTurnSpeedLimit = ((s64) (0x1000 - (s32) (((s64) t * 0x99c + 0x800) >> 12)) * 0x6000 + 0x800) >> 12;
    if (b->mTargetShine == NULL) {
        return;
    }
    if (b->mEntryForwardDot > 0xb33) {
        a->mTurnSpeedLimit = a->mTurnSpeedLimit >> 1;
    }
}

void func_02089a24(KartAi *a, KartAiRaceSpeedLimit *b) {
    BOOL c = FALSE;
    s32 v;
    s32 t;
    RandomState64 *r;

    b->mUnk_28 = 0;
    b->mBoostsAtRaceStart = 0;
    b->mRaceStartBoostChoice = 0;
    v = gRaceSetup->mCurrentEntries[a->mIndex].mPlayer.mKind;
    if ((u32) v <= 3) {
        if ((1 << v) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            c = TRUE;
        }
    }
    if (c != FALSE) {
        return;
    }
    if (gRaceSetup->mBattleKind != BATTLE_KIND_SHINE) {
        return;
    }
    r = GetKartAiRandom();
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    v = (s16) (u16) (r->mValue >> 52);
    t = 0x333;
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_NORMAL:
            t = 0x666;
            break;
        case CPU_DIFFICULTY_HARD:
            t = 0x99a;
            break;
    }
    if (v > t) {
        return;
    }
    b->mBoostsAtRaceStart = 1;
    b->mRaceStartBoostChoice = PickKartAiRaceStartBoost(0);
}

void SetupBattleKartAiParams(void) {
    RaceSetup *t;

    gSearchStartIndex = 0;
    data_0217b030 = &data_0216600c;
    t = gRaceSetup;
    if (t->mBattleKind == BATTLE_KIND_BALLOON) {
        switch (t->mCpuDifficulty) {
            case CPU_DIFFICULTY_NORMAL:
                data_0217b030 = &data_02166028;
                break;
            case CPU_DIFFICULTY_HARD:
                data_0217b030 = &data_02165ff0;
                break;
        }
    } else {
        gEntryYDifferenceLimit = 0x190000;
        if (t->mCourseId == COURSE_ID_MINI_DOKAN_GC) {
            gEntryYDifferenceLimit = 0x28000;
        }
    }
}

void ResetBattleKartAi(KartAi *p) {
    Vec3 z = data_02155ebc;

    p->mSideOffset = z;
    p->mUnk_6c = 0;
    p->mUnk_6e = 0;
    p->mTurnAngleDegrees = 0;
    p->mSideOffsetRatio = 0;
    p->mUnk_78 = 0;
    p->mUnk_7a = 0;
    p->mLinkSpeedLimit = 0;
    p->mUnk_a8 = 0;
    p->mUnk_ac = 0;
    p->mTargetKart = NULL;
    p->mTargetAhead = 0;
    p->mTargetDistanceSquared = 0;
    p->mTargetDistanceSquared = -0x1000;
    p->mTargetKartPos = z;
    p->mHeadingPos = &p->mLinkPosWithSideOffset;
    p->mUnk_c2 = 0;
    p->mUnk_c4 = FALSE;
    p->mUnk_c8 = 0;
    p->mUnk_ca = 0;
    p->mUnk_cc = 0;
    p->mTargetShine = NULL;
    p->mEntrySearchStartIndex = 0;
    p->mEntryForwardDot = 0;
    p->mTargetShinePos = z;
}

void SetupBattleKartAi(KartAi *p, Kart *q) {
    Unk02165ff0 *t;
    RandomState64 *r;
    s16 j;
    s32 v;
    s16 k;

    p->mKart = q;
    p->mIndex = q->mIndex;
    p->mUnk_06 = p->mIndex % 4;
    ResetBattlePointLinkCursorNear(&p->mBattleLinkCursor, &q->mPos, &q->mUnk_138, q->mIndex);
    p->mLinkPosWithSideOffset = *p->mBattleLinkCursor.mLink->mUnk_20;
    ResetBattleKartAi(p);
    if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        t = data_0217b030;
        k = 0;
        r = GetKartAiRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (s16) (u16) (r->mValue >> 52);
        for (j = 0; j < 3; j++) {
            if (t->mUnk_00[j] > 0 && v <= t->mUnk_00[j]) {
                k = j + 1;
                break;
            }
        }
        p->mBalloonCountGoal = k;
    } else {
        p->mBalloonCountGoal = 0;
    }
}

void ResetBattleKartAiAtPointLink(KartAi *p, PointLink *a) {
    ResetBattlePointLinkCursorTo(&p->mBattleLinkCursor, a);
    p->mLinkPosWithSideOffset = *p->mBattleLinkCursor.mLink->mUnk_20;
    ResetBattleKartAi(p);
}

void AdvanceBattleKartAi(KartAi *p) {
    func_02088d34(p);
    if (p->mUnk_c4 == FALSE) {
        func_0207e668(p);
    }
    func_02089494(p);
    if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        AdvanceBattleKartAiTargetKart(p);
        return;
    }
    if (p->mTargetShine != NULL) {
        AdvanceBattleKartAiTargetKart(p);
    }
    AdvanceBattleKartAiTargetShine(p);
}

void func_02089494(KartAi *p) {
    LinkCursor *s;
    Kart *q;
    PointLink *e;
    Vec3 *g;
    Vec3 *f;
    Vec3 v;
    Vec3 w;
    Vec3 t;
    Vec3 z;
    Vec3 u;
    s32 d;
    BOOL x;
    s32 y;

    q = p->mKart;
    s = &p->mBattleLinkCursor;
    g = &q->mUnk_138;
    e = s->mRequestedLink;
    GetKartPos(&v, p->mIndex);
    if (q->mUnk_48 & 0x3840) {
        return;
    }
    if (e != NULL && s->mLink != e) {
        AdvanceBattlePointLinkCursorTo(s, e);
        p->mLinkSpeedLimit = func_020800a0(s);
        AdvanceBattleKartAiSideOffset(p);
        p->mLinkPosWithSideOffset = *s->mLink->mUnk_20;
        VEC_Add(&p->mLinkPosWithSideOffset, &p->mSideOffset, &p->mLinkPosWithSideOffset);
    } else {
        if (p->mIndex == GetRaceUpdateFramesMod8()) {
            f = p->mHeadingPos;
            z = *g;
            VEC_Subtract(f, &q->mPos, &t);
            z.y = 0;
            t.y = 0;
            VEC_CrossProduct(&z, &t, &u);
            d = VEC_Mag(&u);
            p->mTurnAngleDegrees = ((s64) FX_Atan2(d, VEC_DotProduct(&z, &t)) * 0x394bb834c8LL + 0x80000000LL) >> 32;
        }
        if (IsWithinBattlePointLinkDistance(s, &v) != 0 || IsPastBattlePointLink(s, &v) != 0) {
            x = FALSE;
            if (p->mTargetKart != NULL && p->mTargetAhead != 0) {
                x = TRUE;
            }
            if (x != FALSE) {
                y = p->mTargetKart->mIndex;
            } else {
                y = -1;
            }
            AdvanceBattlePointLinkCursor(s, &v, &q->mUnk_138, p->mIndex, p->mTargetShine, y);
            p->mLinkSpeedLimit = func_020800a0(s);
            AdvanceBattleKartAiSideOffset(p);
            p->mLinkPosWithSideOffset = *s->mLink->mUnk_20;
            VEC_Add(&p->mLinkPosWithSideOffset, &p->mSideOffset, &p->mLinkPosWithSideOffset);
            s->mRequestedLink = NULL;
            s->mUnk_18 = FALSE;
        }
    }
    if (q->mState != KART_STATE_NORMAL) {
        return;
    }
    if (p->mUnk_c4 != FALSE) {
        return;
    }
    RequestBits(p->mKart->mEntryIndex, PAD_KEY_A);
    VEC_Subtract(p->mHeadingPos, &v, &w);
    AdvanceKartAiHeading(p, &w, g);
}

void AdvanceBattleKartAiSideOffset(KartAi *p) {
    Vec3 z = gVec3UnitY;
    RandomState64 *r;
    s32 a;
    s32 t;
    s32 u;
    s32 n;
    s32 f;

    VEC_CrossProduct(&p->mBattleLinkCursor.mDirection, &z, &p->mSideOffset);
    p->mUnk_6c++;
    if (p->mUnk_6c > p->mUnk_6e) {
        p->mUnk_6c = 0;
        r = GetKartAiRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        p->mUnk_6e = 0;
        r = GetKartAiRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        a = (s16) (u16) (r->mValue >> 52);
        t = (s32) (((s64) a * 0x2000 + 0x800) >> 12) - 0x1000;
        u = ((s64) t * 0x4ce + 0x800) >> 12;
        n = p->mSideOffsetRatio + u;
        if (GetAbsoluteValue(n) > 0xb36) {
            if (n > 0) {
                n = 0xb36;
            } else {
                n = -0xb36;
            }
        }
        p->mSideOffsetRatio = n;
    }
    f = ((s64) p->mSideOffsetRatio * p->mBattleLinkCursor.mLink->mUnk_24 + 0x800) >> 12;
    p->mSideOffset.x = ((s64) p->mSideOffset.x * f) >> 12;
    p->mSideOffset.y = ((s64) p->mSideOffset.y * f) >> 12;
    p->mSideOffset.z = ((s64) p->mSideOffset.z * f) >> 12;
}

void AdvanceBattleKartAiTargetKart(KartAi *p) {
    Kart *q;
    Kart *o;
    KartItems *v1;
    Vec3 u;
    Vec3 v;
    Vec3 t;
    Vec3 e;
    Vec3 w;
    Vec3 z;
    s32 d;
    s32 x;
    s32 y;
    u16 n;
    u16 k;
    u32 m;
    u32 v2;
    s32 c;
    Vec3 *v3;

    m = p->mIndex;
    if (m != GetRaceUpdateFramesMod8()) {
        return;
    }
    if (gRaceSetup->mCpuDifficulty == CPU_DIFFICULTY_EASY) {
        return;
    }
    if (p->mTargetKart == NULL) {
        p->mHeadingPos = &p->mLinkPosWithSideOffset;
        k = gSearchStartIndex;
        for (n = 0; n < (u32) gRaceSetup->mKartCount; n++) {
            if (ShouldKartAiTargetKart(p->mIndex, k) != 0) {
                o = GetKart(k);
                v3 = &p->mKart->mPos;
                d = func_020888b4_inline(v3, &o->mPos);
                c = 0;
                if (d < 0x895440) {
                    if (GetAbsoluteValue(p->mKart->mPos.y - o->mPos.y) < 0x3c000) {
                        c = 1;
                        p->mTargetDistanceSquared = d;
                    }
                }
                if (c != 0) {
                    v2 = gRaceSetup->mKartCount;
                    gSearchStartIndex++;
                    if (gSearchStartIndex >= v2) {
                        gSearchStartIndex = 0;
                    }
                    goto store;
                }
            }
            k++;
            if (k >= (u32) gRaceSetup->mKartCount) {
                k = 0;
            }
        }
        o = NULL;
    store:
        p->mTargetKart = o;
        return;
    }
    v1 = &gKartItems[m];
    if (v1->mItemInUse.mObjectKind == 0xf && v1->mHeldItem.mItemInfoIndex == 0x13 && (p->mKart->mUnk_4c & 0x40) == 0) {
        goto clear;
    }
    if (func_0207f600(p->mTargetKart->mIndex) == FALSE) {
        goto clear;
    }
    q = p->mKart;
    o = p->mTargetKart;
    v3 = &q->mPos;
    d = func_020888b4_inline(v3, &o->mPos);
    c = 0;
    if (d < 0xf42400) {
        if (GetAbsoluteValue(p->mKart->mPos.y - p->mTargetKart->mPos.y) < 0x3c000) {
            p->mTargetDistanceSquared = d;
            c = 1;
        }
    }
    if (c == 0) {
        goto clear;
    }
    if (GetAbsoluteValue(p->mKart->mPos.y - p->mTargetKart->mPos.y) >= 0x3c000) {
        goto clear;
    }
    c = 0;
    VEC_Subtract(&p->mTargetKart->mPos, &p->mKart->mPos, &v);
    if (VEC_DotProduct(&v, &p->mKart->mUnk_138) > 0) {
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v, &v);
        }
        p->mTargetForwardDot = VEC_DotProduct(&v, &p->mKart->mUnk_138);
        c = 1;
    }
    p->mTargetAhead = c != 0;
    if (p->mTargetAhead != 0) {
        v1 = &gKartItems[p->mIndex];
        c = 1;
        if (v1->mItemInUse.mObjectKind == 0xf && v1->mHeldItem.mItemInfoIndex == 0x13) {
            if ((GetKart(p->mIndex)->mUnk_4c & 0x40) == 0) {
                c = 0;
            }
        }
        x = c != 0 ? 1 : 0;
        y = (p->mTargetKart->mUnk_4c & 0x40) != 0 ? 1 : 0;
        if (x != 0 && y == 0 && p->mTargetForwardDot > 0xb33) {
            u = p->mTargetKart->mPos;
            u.y = p->mLinkPosWithSideOffset.y;
            t = *p->mBattleLinkCursor.mLink->mUnk_20;
            z = gVec3UnitY;
            VEC_CrossProduct(&p->mBattleLinkCursor.mDirection, &z, &e);
            VEC_Subtract(&u, &t, &w);
            d = Vec3DotUnrounded(&w, &e);
            c = p->mBattleLinkCursor.mLink->mUnk_24;
            if (GetAbsoluteValue(d) >= c) {
                p->mHeadingPos = &p->mLinkPosWithSideOffset;
            } else {
                p->mTargetKartPos = u;
                p->mHeadingPos = &p->mTargetKartPos;
            }
        } else {
            p->mHeadingPos = &p->mLinkPosWithSideOffset;
        }
    } else {
        p->mHeadingPos = &p->mLinkPosWithSideOffset;
    }
    return;
clear:
    p->mTargetKart = NULL;
    p->mHeadingPos = &p->mLinkPosWithSideOffset;
}

void func_02088d34(KartAi *p) {
    s32 a;
    u16 b;
    BOOL c;

    p->mUnk_c4 = FALSE;
    if (gRaceSetup->mBattleKind != BATTLE_KIND_BALLOON) {
        return;
    }
    if (func_01ffc67c(p->mKart) != FALSE) {
        func_020a228c(p->mIndex);
        return;
    }
    a = GetBalloonOrShineCount(p->mIndex);
    b = GetBalloonsLeftToMake(p->mIndex);
    if (a >= p->mBalloonCountGoal) {
        return;
    }
    c = FALSE;
    if (b > data_0217b030->mUnk_1a || (b == data_0217b030->mUnk_1a && IsKartInflatingBalloon(p->mIndex) != 0)) {
        c = TRUE;
    }
    if (c == FALSE) {
        return;
    }
    p->mUnk_c2++;
    if (p->mUnk_c2 > data_0217b030->mUnk_18) {
        func_020a22ac(p->mIndex);
        p->mUnk_c2 = 0;
    }
    p->mUnk_c4 = TRUE;
}

void PickKartAiBalloonCountGoal(KartAi *p) {
    s32 *t = data_0217b030->mUnk_0c;
    RandomState64 *r;
    s16 j;
    s32 v;
    s16 k = 0;

    r = GetKartAiRandom();
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    v = (s16) (u16) (r->mValue >> 52);
    for (j = 0; j < 3; j++) {
        if (t[j] > 0 && v <= t[j]) {
            k = j + 1;
            break;
        }
    }
    p->mBalloonCountGoal = k;
}

void AdvanceBattleKartAiTargetShine(KartAi *p) {
    Unk020888b4_d0 *r;
    Vec3 u;
    Vec3 v;
    Vec3 t;
    Vec3 e;
    Vec3 w;
    Vec3 z;
    s32 m;
    s32 d;
    BOOL c;
    BOOL n;
    s32 x;
    Vec3 *v1;
    Vec3 *v2;

    r = p->mTargetShine;
    if (r != NULL) {
        if (!(r->mFlags & 1)) {
            v1 = &r->mPos;
            v2 = &p->mKart->mPos;
            d = func_020888b4_inline(v2, v1);
            m = gEntryYDifferenceLimit;
            if (d < 0x15f900 && GetAbsoluteValue(p->mKart->mPos.y - r->mPos.y) < m) {
                c = TRUE;
            } else {
                c = FALSE;
            }
            if (c != FALSE) {
                n = FALSE;
                VEC_Subtract(&r->mPos, &p->mKart->mPos, &v);
                if (VEC_DotProduct(&v, &p->mKart->mUnk_138) > 0) {
                    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
                    }
                    p->mEntryForwardDot = VEC_DotProduct(&v, &p->mKart->mUnk_138);
                    n = TRUE;
                }
                if (n != FALSE && p->mEntryForwardDot > 0xb33) {
                    u = r->mPos;
                    u.y = p->mLinkPosWithSideOffset.y;
                    t = *p->mBattleLinkCursor.mLink->mUnk_20;
                    z = gVec3UnitY;
                    VEC_CrossProduct(&p->mBattleLinkCursor.mDirection, &z, &e);
                    VEC_Subtract(&u, &t, &w);
                    m = Vec3DotUnrounded(&w, &e);
                    x = p->mBattleLinkCursor.mLink->mUnk_24;
                    if (GetAbsoluteValue(m) >= x) {
                        p->mHeadingPos = &p->mLinkPosWithSideOffset;
                    } else {
                        p->mTargetShinePos = u;
                        p->mHeadingPos = &p->mTargetShinePos;
                    }
                } else {
                    p->mHeadingPos = &p->mLinkPosWithSideOffset;
                }
            } else {
                p->mTargetShine = NULL;
                p->mHeadingPos = &p->mLinkPosWithSideOffset;
            }
        } else {
            p->mTargetShine = NULL;
            p->mHeadingPos = &p->mLinkPosWithSideOffset;
        }
    } else {
        if (p->mIndex == GetRaceUpdateFramesMod8()) {
            FindKartAiTargetShine(p, 0x17d7840, gEntryYDifferenceLimit);
        }
    }
}

// Picks a Shine16 object within the given x/z and y ranges as the CPU kart's target; TRUE if one was found.
BOOL FindKartAiTargetShine(KartAi *p, s32 a, s32 b) {
    MapObjectList *l;
    s16 i;
    s32 n;
    s16 c;
    s16 k;
    s32 m;
    Unk020888b4_d0 *r;
    Unk020888b4_d0 *e;
    Vec3 *v1;
    Vec3 *v2;
    s32 d;
    BOOL x;

    l = func_02100138(MAP_OBJECT_KIND_SHINE16);
    n = GetMapObjectListCount(l);
    m = 0;
    r = NULL;
    i = 0;
    c = 0;
    k = p->mEntrySearchStartIndex;
    for (; i < n; i++) {
        e = func_0210008c(l)[k];
        k++;
        if (k >= n) {
            k = 0;
        }
        if (!(e->mFlags & 1)) {
            c++;
            v1 = &e->mPos;
            v2 = &p->mKart->mPos;
            d = func_020888b4_inline(v2, v1);
            if (d < a && GetAbsoluteValue(p->mKart->mPos.y - e->mPos.y) < b) {
                x = TRUE;
            } else {
                x = FALSE;
            }
            if (x != FALSE) {
                if (r == NULL || m < d) {
                    r = e;
                    m = d;
                }
            }
            if (c >= 5) {
                break;
            }
        }
    }
    p->mEntrySearchStartIndex = k;
    if (r != NULL) {
        p->mTargetShine = r;
        return TRUE;
    }
    return FALSE;
}
