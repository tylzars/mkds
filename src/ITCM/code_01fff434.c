#include "ITCM/code_01fff434.h"
#include "Main/Unknown/code_020435c4.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void UpdateKartItems(KartItems *p) {
    HeldItem *b = &p->mHeldItem;
    ItemInUse *a = &p->mItemInUse;
    Kart *q;
    ItemPointLinkRef *r;
    Vec3 *v;
    s64 d;
    s32 k;
    u16 f;
    u16 t;
    u32 g;
    f = p->mFlags;
    g = f & 0x1000;
    t = data_0217562a[p->mEntryIndex].mBits & ITEM_BITS;
    q = p->mKart;
    p->mFlags &= ~0xf200;
    if (t) {
        if (!g) {
            p->mFlags |= 0x3000;
        } else {
            p->mFlags |= data_usa_021595cc;
        }
    } else if (g) {
        p->mFlags |= data_usa_021595d0;
    }
    if (func_02068eac(q) != FALSE) {
        p->mKinokoBoostStarted = FALSE;
        p->mUnk_208 = FALSE;
        return;
    }
    p->mKinokoBoostStarted = FALSE;
    if (p->mUnk_20c != FALSE) {
        if (func_01ffc67c(q) == FALSE && !(q->mUnk_48 & 0x10000) && (q->mUnk_44 & KART_44_ON_GROUND)) {
            p->mUnk_20c = FALSE;
        }
    } else if (func_01ffc67c(q) != FALSE || (q->mUnk_48 & 0x10000)) {
        p->mUnk_20c = TRUE;
    } else {
        func_01fff524(p);
        p->mFlags |= data_usa_021595d4;
    }
    if (a->mObjectKind != 0xf) {
        AdvanceItemInUse(a);
    }
    if (b->mItemInfoIndex != 0x13) {
        if ((p->mFlags & 0x242) == 0x242 && b->mItemInfoIndex != 0x13 && b->mObjectStartFramesLeft == 0 &&
            (p->mFlags & 0x200) && q->mState == KART_STATE_NORMAL) {
            StartItemInUse(a, b);
        }
        UpdateHeldItem(b);
    }
    if (p->mSlotState != 0 && UpdateItemSlot(p, p) != FALSE) {
        k = p->mSlotResult;
        FinishItemSlot(p);
        if (gItemInfos[k].mEnabled != FALSE) {
            SetHeldItem(b, k);
        }
    }
    if (p->mKartIndex == GetRaceUpdateFramesMod8() && (r = &p->mUnk_1f0)->mLink != NULL) {
        q = p->mKart;
        v = &q->mDrawMatrixPos;
        PickNearestNearbyItemPointLink(r, r, v);
        d = (s64) (r->mLink->mPointPos->x - v->x) * (r->mLink->mPointPos->x - v->x);
        d += (s64) (r->mLink->mPointPos->z - v->z) * (r->mLink->mPointPos->z - v->z);
        if (d >= ((s64) 0x15f9 << 32)) {
            FollowItemPointLinksToPos(r, r, v);
        }
    }
    p->mUnk_208 = FALSE;
}

void func_01fff524(KartItems *p) {
    BOOL r;
    s32 a;
    p->mFlags &= ~0xff;
    if (gRaceSetup->mMode == 5) {
        a = p->mHeldItem.mItemInfoIndex;
        if (a == 0x13 || p->mItemInUse.mObjectKind != 0xf) {
            r = FALSE;
        } else {
            r = (u32) (gItemInfos[a].mUseKind - 1) <= 1;
        }
        if (r != FALSE) {
            if ((p->mFlags & 0x4000) && func_020f0154(p) != FALSE) {
                p->mFlags |= data_usa_021595b0;
            }
            goto after;
        }
    }
    if ((p->mFlags & 0x2000) && func_020f0154(p) != FALSE) {
        p->mFlags |= data_usa_021595b0;
    }
after:
    if (!(p->mFlags & 0x100)) {
        return;
    }
    p->mFlags &= ~0x100;
    if (gRaceSetup->mMode != 5 && (p->mFlags & 0x1000)) {
        return;
    }
    if (func_020f0154(p) == FALSE) {
        return;
    }
    p->mFlags |= data_usa_021595b4;
}

void func_01fff434(s32 a, s32 b, s32 c, Vec3 *d, const Vec3 *e, const Vec3 *f, s64 *g) {
    s32 q;
    s32 u;
    q = FX_Div((s32) (((s64) a * b) >> 12) - c, (s32) (((s64) a * a) >> 12) - 0x1000);
    u = b - (s32) (((s64) q * a) >> 12);
    d->x = (s32) (((s64) q * e->x) >> 12) + (s32) (((s64) u * f->x) >> 12);
    d->y = (s32) (((s64) q * e->y) >> 12) + (s32) (((s64) u * f->y) >> 12);
    d->z = (s32) (((s64) q * e->z) >> 12) + (s32) (((s64) u * f->z) >> 12);
    *g = (s64) d->x * d->x + (s64) d->y * d->y + (s64) d->z * d->z;
}
