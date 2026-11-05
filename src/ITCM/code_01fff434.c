#include "ITCM/code_01fff434.h"
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
    Unk020f40dc *b = &p->mHeldItem;
    Unk020eda5c *a = &p->mItemInUse;
    Kart *q;
    Unk020f371c_Ref *r;
    Vec3 *v;
    s64 d;
    s32 k;
    u16 f;
    u16 t;
    u32 g;
    f = p->mFlags;
    g = f & 0x1000;
    t = data_0217562a[p->mUnk_200].mBits & 0x600;
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
        p->mUnk_204 = FALSE;
        p->mUnk_208 = FALSE;
        return;
    }
    p->mUnk_204 = FALSE;
    if (p->mUnk_20c != FALSE) {
        if (func_01ffc67c(q) == FALSE && !(q->mUnk_48 & 0x10000) && (q->mUnk_44 & 0x10)) {
            p->mUnk_20c = FALSE;
        }
    } else if (func_01ffc67c(q) != FALSE || (q->mUnk_48 & 0x10000)) {
        p->mUnk_20c = TRUE;
    } else {
        func_01fff524(p);
        p->mFlags |= data_usa_021595d4;
    }
    if (a->mUnk_000 != 0xf) {
        func_020eddb4(a);
    }
    if (b->mUnk_00 != 0x13) {
        if ((p->mFlags & 0x242) == 0x242 && b->mUnk_00 != 0x13 && b->mUnk_20 == 0 && (p->mFlags & 0x200) &&
            q->mState == 0) {
            func_020ee2e4(a, b);
        }
        func_020f4884(b);
    }
    if (p->mSlotState != 0 && UpdateItemSlot(p, p) != FALSE) {
        k = p->mSlotResult;
        FinishItemSlot(p);
        if (gItemInfos[k].mEnabled != FALSE) {
            func_020f47e4(b, k);
        }
    }
    if (p->mKartIndex == func_02061f90() && (r = &p->mUnk_1f0)->mUnk_00 != NULL) {
        q = p->mKart;
        v = &q->mUnk_98;
        func_020f3c54(r, r, v);
        d = (s64) (r->mUnk_00->mUnk_18->x - v->x) * (r->mUnk_00->mUnk_18->x - v->x);
        d += (s64) (r->mUnk_00->mUnk_18->z - v->z) * (r->mUnk_00->mUnk_18->z - v->z);
        if (d >= ((s64) 0x15f9 << 32)) {
            func_020f3a58(r, r, v);
        }
    }
    p->mUnk_208 = FALSE;
}

void func_01fff524(KartItems *p) {
    BOOL r;
    s32 a;
    p->mFlags &= ~0xff;
    if (data_021759c0->mMode == 5) {
        a = p->mHeldItem.mUnk_00;
        if (a == 0x13 || p->mItemInUse.mUnk_000 != 0xf) {
            r = FALSE;
        } else {
            r = (u32) (gItemInfos[a].mUnk_14 - 1) <= 1;
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
    if (data_021759c0->mMode != 5 && (p->mFlags & 0x1000)) {
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
    q = DivFixed12((s32) (((s64) a * b) >> 12) - c, (s32) (((s64) a * a) >> 12) - 0x1000);
    u = b - (s32) (((s64) q * a) >> 12);
    d->x = (s32) (((s64) q * e->x) >> 12) + (s32) (((s64) u * f->x) >> 12);
    d->y = (s32) (((s64) q * e->y) >> 12) + (s32) (((s64) u * f->y) >> 12);
    d->z = (s32) (((s64) q * e->z) >> 12) + (s32) (((s64) u * f->z) >> 12);
    *g = (s64) d->x * d->x + (s64) d->y * d->y + (s64) d->z * d->z;
}
