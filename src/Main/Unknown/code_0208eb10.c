#include "Main/Unknown/code_0208eb10.h"

#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020172d0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "code_0201750c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/code_0208ffd8.h"
#include "Main/Unknown/code_0208ffe4.h"
#include "Main/Unknown/code_02090088.h"
#include "Main/Unknown/code_02090194.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

void func_02090194(Unk02090194 *p0) {
    p0->mUnk_10 = 0x1u;
}

void func_02090088(KartAiItemUse *a, KartAi *b) {
    RandomState64 *r;
    s32 v;

    if (DecrementHeldItemTimer(a) != 0) {
        r = GetKartAiRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (s16) (u16) (r->mValue >> 52);
        if (v < 0xb33) {
            UseItemForwardAndResetInUseTimer(a, b);
        } else {
            UseItemBehindAndResetInUseTimer(a, b);
        }
    } else {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        if (b->mTargetAhead != 0 && b->mTargetForwardDot > 0xb33) {
            UseItemForwardAndResetInUseTimer(a, b);
        } else {
            UseItemBehindAndResetInUseTimer(a, b);
        }
    }
}

void func_0208ffe4(KartAiItemUse *a, KartAi *b) {
    RandomState64 *r;
    s32 v;

    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    r = GetKartAiRandom();
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    v = (s16) (u16) (r->mValue >> 52);
    if (v < 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void SetItemBitsEveryCall(Unk0208ffd8 *p0) {
    p0->mUnk_10 = 0x1u;
}

void func_0208fefc(KartAiItemUse *a, struct KartAi *b) {
    RandomState64 *r;
    s32 v;

    if (DecrementHeldItemTimer(a) != 0) {
        r = GetKartAiRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (s16) (u16) (r->mValue >> 52);
        if (v > 0xccd) {
            UseItemBehindAndResetInUseTimer(a, b);
        } else {
            UseItemForwardAndResetInUseTimer(a, b);
        }
    } else {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208fe58(KartAiItemUse *a, struct KartAi *b) {
    RandomState64 *r;
    s32 v;

    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    r = GetKartAiRandom();
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    v = (s16) (u16) (r->mValue >> 52);
    if (v > 0xccd) {
        UseItemBehindAndResetInUseTimer(a, b);
    } else {
        UseItemForwardAndResetInUseTimer(a, b);
    }
}

void func_0208fe1c(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0208fdcc(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    if (b->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetHeldTimer(a, b);
}

void SetupBattleItemInUseEntry(KartAiItemUse *a, struct KartAi *b) {
    enum { K0 } k = (gKartItems)[b->mIndex].mItemInUse.mObjectKind;
    KartAiItemUseEntry *t = &gBattleItemInUseEntries[k];

    a->mItemInUseEntry = t;
    ResetItemInUseTimer(a, t);
}

u32 func_0208fd88(u32 p0) {
    return p0;
}
// Calls one of two handlers, by whether the item in use is the circling kind.

void ThrowItemByCircleKind(KartAiItemUse *a, struct KartAi *b) {
    if (gKartItems[b->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        data_0217b0a0(a, b);
    } else {
        data_0217b098(a, b);
    }
}

void ThrowItemAtNearTarget(KartAiItemUse *a, struct KartAi *b) {
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead != 0 && b->mTargetForwardDot > 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208fba0(KartAiItemUse *a, struct KartAi *b) {
    RandomState64 *r;
    s32 v;

    if (DecrementItemInUseTimer(a) != 0) {
        r = GetKartAiRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (s16) (u16) (r->mValue >> 52);
        if (v < 0xb33) {
            UseItemForwardAndResetInUseTimer(a, b);
        } else {
            UseItemBehindAndResetInUseTimer(a, b);
        }
    } else {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        if (b->mTargetAhead != 0 && b->mTargetForwardDot > 0xb33) {
            UseItemForwardAndResetInUseTimer(a, b);
        } else {
            UseItemBehindAndResetInUseTimer(a, b);
        }
    }
}

void func_0208fafc(KartAiItemUse *a, struct KartAi *b) {
    RandomState64 *r;
    s32 v;

    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    r = GetKartAiRandom();
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    v = (s16) (u16) (r->mValue >> 52);
    if (v < 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208fa50(KartAiItemUse *a, struct KartAi *b) {
    a->mItemBitsEveryCall = 1;
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead != 0 && b->mTargetForwardDot > 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208f9ac(KartAiItemUse *a, struct KartAi *b) {
    RandomState64 *r;
    s32 v;

    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    r = GetKartAiRandom();
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    v = (s16) (u16) (r->mValue >> 52);
    if (v < 0xb33) {
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
// Calls one of two handlers, by whether the item in use is the circling kind.
}

void UseItemByCircleKind(KartAiItemUse *a, struct KartAi *b) {
    if (gKartItems[b->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        data_0217b090(a, b);
    } else {
        data_0217b094(a, b);
    }
}

void func_0208f8ac(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead == 0) {
        return;
    }
    if (b->mTargetForwardDot <= 0x666) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0208f810(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead == 0) {
        return;
    }
    if (b->mTargetForwardDot <= 0x666) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void UseItemAfterInUse(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0208f754(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0208f6d4(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
// Calls one of two handlers, by whether the item in use is the trail kind.
}

void ThrowItemByTrailKind(KartAiItemUse *a, struct KartAi *b) {
    if (gKartItems[b->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_TRAIL) {
        data_0217b0ac(a, b);
    } else {
        data_0217b0a8(a, b);
    }
}

void func_0208f5c4(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead != 0) {
        if (b->mTargetForwardDot <= 0xb33) {
            return;
        }
        UseItemForwardAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208f4e8(KartAiItemUse *a, struct KartAi *b) {
    RandomState64 *r;
    s32 v;

    if (DecrementItemInUseTimer(a) != 0) {
        r = GetKartAiRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (s16) (u16) (r->mValue >> 52);
        if (v > 0xb33) {
            UseItemBehindAndResetInUseTimer(a, b);
        } else {
            UseItemForwardAndResetInUseTimer(a, b);
        }
    } else {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void func_0208f434(KartAiItemUse *a, struct KartAi *b) {
    a->mItemBitsEveryCall = 1;
    if (DecrementItemInUseTimer(a) == 0) {
        return;
    }
    if (b->mTargetKart == NULL) {
        return;
    }
    if (b->mTargetDistanceSquared >= 0x15f90) {
        return;
    }
    if (b->mTargetAhead != 0) {
        if (b->mTargetForwardDot <= 0xb33) {
            return;
        }
        UseItemBehindAndResetInUseTimer(a, b);
    } else {
        UseItemBehindAndResetInUseTimer(a, b);
    }
}

void UseItemBehindAfterInUseOrNearTarget(KartAiItemUse *a, struct KartAi *b) {
    if (DecrementItemInUseTimer(a) == 0) {
        if (b->mTargetKart == NULL) {
            return;
        }
        if (b->mTargetDistanceSquared >= 0x15f90) {
            return;
        }
    }
    UseItemBehindAndResetInUseTimer(a, b);
}

// Allocates the strips and their points, loads the texture they are drawn with and sets the values for a race or the
// award scene.
void InitPosStrips(void *a) {
    void *s;
    PosStrip *e;
    PosStripPoint *f;
    u16 i;
    u16 n;
    u16 m;
    NNSG3dResTex *q;
    s32 t;

    s = FindMainRaceOrMainEffectFile(gRaceSetup->mRaceKind == RACE_KIND_AWARD ? data_02166514 : data_02166530);
    gPosStripHeightDecreasePerFrame = 0x4d;
    gPosStripMaxAgeFrames = 8;
    data_021663dc = 3;
    gPosStripPointsPerStrip = 0xc;
    gSetPosStripPointFunction = (s32(*)()) SetPosStripPointFromPos;
    gPosStripFirstPolygonId = 0xe;
    gPosStripDrawEnabled = 1;
    n = 1;
    if (gRaceSetup->mMode == 5) {
        n += 3;
    } else if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        gPosStripHeightDecreasePerFrame = 0;
        gPosStripMaxAgeFrames = 0xe;
        data_021663dc = 2;
        gPosStripPointsPerStrip = 0x1e;
        gSetPosStripPointFunction = (s32(*)()) SetPosStripPointFromKart;
        gPosStripFirstPolygonId = 4;
        gPosStripDrawEnabled = 0;
        n = 6;
    }
    m = gPosStripPointsPerStrip * n;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        a = data_0217aa10->mExpHeap;
    }
    gPosStrips = HeapAlloc(a, 0x38);
    e = HeapAlloc(a, n * 0x30);
    f = HeapAlloc(a, m * 0x1c);
    NNS_FndInitList(&gPosStrips->mLists[0], 0);
    NNS_FndInitList(&gPosStrips->mLists[1], 0);
    NNS_FndInitList(&gPosStrips->mLists[2], 0);
    for (i = 0; i < n; i++) {
        NNS_FndInitList(&e[i].mPoints, 0);
        NNS_FndAppendListObject(&gPosStrips->mLists[1], &e[i]);
    }
    for (i = 0; i < m; i++) {
        NNS_FndAppendListObject(&gPosStrips->mLists[2], &f[i]);
    }
    AddResFileEntry(&gPosStrips->mEffectFileEntry, s, s);
    q = gPosStrips->mEffectFileEntry.mTexture;
    t = (q->mTexInfo.mVramKey & 0xffff) << 3;
    gPosStripTexture.mTexImageParam = gPosStripTexture.mTexImageParam & 0xffff0000;
    gPosStripTexture.mTexImageParam = gPosStripTexture.mTexImageParam | (((u32) t >> 3) & 0xffff);
    gPosStripTexture.mPlttBase = (q->mPlttInfo.mVramKey & 0xffff) << 3;
    gPosStripTexture.mUnk_1c = 0x10000;
    gPosStripTexture.mUnk_20 = 0x8000;
    gPosStrips->mPolygonAttrBits = gRaceSetup->mCourseId == COURSE_ID_RAINBOW ? 0 : 0x8000;
}

void UpdatePosStrips(void) {
    void *p;
    p = NNS_FndGetNextListObject(&gPosStrips->mLists[0], NULL);
    while (p != NULL) {
        UpdatePosStrip(p);
        p = NNS_FndGetNextListObject(&gPosStrips->mLists[0], p);
    }
}

void DrawPosStrips(const MtxFx43 *a) {
    PosStrip *p;
    PosStripPoint *r;
    PosStripPoint *q;
    s32 v;
    u8 f;
    BOOL g;

    f = gPosStripFirstPolygonId;
    g = FALSE;
    p = NNS_FndGetNextListObject(&gPosStrips->mLists[0], NULL);
    if (p == NULL) {
        return;
    }
    do {
        if (g == FALSE) {
            reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
            reg_G3_SPE_EMI = 0x7c004210;
            reg_G3_DIF_AMB = 0x42100000;
            reg_G3_MTX_MODE = 3;
            reg_G3_MTX_IDENTITY = 0;
            reg_G3_MTX_MODE = 2;
            reg_G3_TEXIMAGE_PARAM = gPosStripTexture.mTexImageParam;
            reg_G3_PLTT_BASE = gPosStripTexture.mPlttBase >> (4 - ((gPosStripTexture.mTexImageParam >> 26 & 7) == 2));
            g = TRUE;
        }
        reg_G3_COLOR = 0x7fff;
        q = NNS_FndGetNextListObject(&p->mPoints, NULL);
        if (q != NULL && gPosStripDrawEnabled != 0) {
            r = NNS_FndGetNextListObject(&p->mPoints, NULL);
            if (r != NULL) {
                do {
                    v = 0x1f - q->mSinceAddedFrames * data_021663dc;
                    reg_G3_POLYGON_ATTR = f << 24 | (gPosStrips->mPolygonAttrBits | 0xc0) | v << 16;
                    DrawPosStripQuad(a, q, r, &gPosStripTexture);
                    q = r;
                    r = NNS_FndGetNextListObject(&p->mPoints, r);
                } while (r != NULL);
            }
        }
        f = f + 1;
        p = NNS_FndGetNextListObject(&gPosStrips->mLists[0], p);
    } while (p != NULL);
}

void SetPosStripPointFromPos(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value3 = *(const u32 *) ((value1) + (20));
    value2 = *(const u32 *) ((value1) + (28));
    value1 = 0u;
    *(u32 *) ((value0) + (8)) = value2;
    *(u16 *) ((value0) + (12)) = value1;
    value1 = *(const u32 *) ((value3) + (0));
    value1 = ((s32) value1 >> 4);
    *(u32 *) ((value0) + (16)) = value1;
    value1 = *(const u32 *) ((value3) + (4));
    value1 = ((s32) value1 >> 4);
    *(u32 *) ((value0) + (20)) = value1;
    value1 = *(const u32 *) ((value3) + (8));
    value1 = ((s32) value1 >> 4);
    *(u32 *) ((value0) + (24)) = value1;
}

void SetPosStripPointFromKart(PosStripPoint *a, PosStrip *b) {
    Kart *o;
    Vec3 v;
    Vec3 x;
    Vec3 y;
    Vec3 z;
    Vec3 *p;
    s32 k;

    o = GetKart(b->mKartIndex);
    v = o->mPos;
    p = &o->mUnk_120;
    k = b->mOffsetX;
    x.x = ((s64) p->x * k) >> 12;
    x.y = ((s64) p->y * k) >> 12;
    x.z = ((s64) p->z * k) >> 12;
    p = &o->mUnk_12c;
    k = b->mOffsetY;
    y.x = ((s64) p->x * k) >> 12;
    y.y = ((s64) p->y * k) >> 12;
    y.z = ((s64) p->z * k) >> 12;
    p = &o->mUnk_138;
    k = b->mOffsetZ;
    z.x = ((s64) p->x * k) >> 12;
    z.y = ((s64) p->y * k) >> 12;
    z.z = ((s64) p->z * k) >> 12;
    VEC_Add(&v, &x, &v);
    VEC_Add(&v, &y, &v);
    VEC_Add(&v, &z, &v);
    a->mHeight = b->mHeight;
    a->mSinceAddedFrames = 0;
    a->mPos.x = v.x >> 4;
    a->mPos.y = v.y >> 4;
    a->mPos.z = v.z >> 4;
}

// Starts a strip that follows the position a points to; returns the strip, or 0 when none is free.
s32 StartPosStrip(u32 a) {
    PosStrip *p;
    p = NNS_FndGetNthListObject(&gPosStrips->mLists[1], 0);
    if (p != NULL) {
        p->mFollowedPos = a;
        p->mStopped = 0;
        p->mHeight = 0x400;
        NNS_FndRemoveListObject(&gPosStrips->mLists[1], p);
        NNS_FndAppendListObject(&gPosStrips->mLists[0], p);
    }
    return (s32) p;
}

// Award scene only: starts a strip that follows kart a.
PosStrip *StartAwardKartPosStrip(s32 a) {
    PosStrip *p;
    Kart *o;
    KartModelsEntry *t;
    Vec3 v;
    s32 h;

    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        p = NNS_FndGetNthListObject(&gPosStrips->mLists[1], 0);
        if (p != NULL) {
            o = GetKart(a);
            t = o->mKartModelsEntry;
            v = ((Vec3 *) &t->mKartOffsetData->mUnk_44)[t->mCharacterIndex];
            p->mFollowedPos = (u32) &o->mPos;
            p->mStopped = 0;
            p->mHeight = 0x400;
            p->mKartIndex = a;
            h = (v.y + (data_02166418[t->mCharacterIndex][0] >> 4) - data_02166480[t->mKartIndex]) / 2;
            p->mHeight = h;
            p->mOffsetX = v.x << 4;
            p->mOffsetY = (data_02166480[t->mKartIndex] + h) << 4;
            p->mOffsetZ = data_0216641c[t->mCharacterIndex][0] + (v.z << 4);
            NNS_FndRemoveListObject(&gPosStrips->mLists[1], p);
            NNS_FndAppendListObject(&gPosStrips->mLists[0], p);
        }
        return p;
    }
    return NULL;
}

// Adds no more points to the strip; it goes back to the pool once its points have gone.
void StopPosStrip(u32 p0) {
    *OFFSET_PTR(u32, p0, 24) = 0x1u;
}
