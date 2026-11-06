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

void func_02089c3c(Unk02089b4c *a, Unk020888b4 *b) {
    s32 m;
    Kart *q;

    if (b->mIndex == GetRaceUpdateFramesMod8()) {
        a->mUnk_0c = FALSE;
        m = b->mKart->mSpeedLimitGoal;
        if (m > 0xa000) {
            m = 0xa000;
        }
        func_02089b4c(a, b, m);
        if (a->mUnk_10 < m) {
            m = a->mUnk_10;
        }
        if (m > 0xa000) {
            m = 0xa000;
        }
        a->mUnk_04 = m;
        if (b->mUnk_a4 != 0) {
            if (a->mUnk_04 > b->mUnk_a4) {
                a->mUnk_04 = b->mUnk_a4;
            }
        }
    }
    q = b->mKart;
    if (q->mState != KART_STATE_NORMAL) {
        return;
    }
    if ((q->mUnk_48 & 0x10000020) == 0) {
        q->mSpeedLimitGoal = a->mUnk_04;
    }
}

void func_02089b4c(Unk02089b4c *a, Unk020888b4 *b, s32 c) {
    s32 t;

    a->mUnk_10 = c;
    if (b->mUnk_70 <= 0x5000) {
        return;
    }
    t = ((s64) (b->mUnk_70 - 0x5000) * 0x5b + 0x800) >> 12;
    if (t > 0x1000) {
        t = 0x1000;
    }
    a->mUnk_10 = ((s64) (0x1000 - (s32) (((s64) t * 0x99c + 0x800) >> 12)) * 0x6000 + 0x800) >> 12;
    if (b->mUnk_d0 == NULL) {
        return;
    }
    if (b->mUnk_d8 > 0xb33) {
        a->mUnk_10 = a->mUnk_10 >> 1;
    }
}

void func_02089a24(Unk020888b4 *a, Unk02089a24 *b) {
    BOOL c = FALSE;
    s32 v;
    s32 t;
    Unk0217aebc_128 *r;

    b->mUnk_28 = 0;
    b->mUnk_2c = 0;
    b->mUnk_30 = 0;
    v = data_021759c0->mCurrentEntries[a->mIndex].mPlayer.mKind;
    if ((u32) v <= 3) {
        if ((1 << v) & 0xd) {
            c = TRUE;
        }
    }
    if (c != FALSE) {
        return;
    }
    if (data_021759c0->mUnk_18 != 1) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    t = 0x333;
    switch (data_021759c0->mUnk_014) {
        case 2:
            t = 0x666;
            break;
        case 3:
            t = 0x99a;
            break;
    }
    if (v > t) {
        return;
    }
    b->mUnk_2c = 1;
    b->mUnk_30 = func_0207d8e4(0);
}

void func_02089974(void) {
    Unk021759c0 *t;

    gSearchStartIndex = 0;
    data_0217b030 = &data_0216600c;
    t = data_021759c0;
    if (t->mUnk_18 == 0) {
        switch (t->mUnk_014) {
            case 2:
                data_0217b030 = &data_02166028;
                break;
            case 3:
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

void func_020898bc(Unk020888b4 *p) {
    Vec3 z = data_02155ebc;

    p->mUnk_60 = z;
    p->mUnk_6c = 0;
    p->mUnk_6e = 0;
    p->mUnk_70 = 0;
    p->mUnk_74 = 0;
    p->mUnk_78 = 0;
    p->mUnk_7a = 0;
    p->mUnk_a4 = 0;
    p->mUnk_a8 = 0;
    p->mUnk_ac = 0;
    p->mUnk_b0 = NULL;
    p->mUnk_b4 = 0;
    p->mUnk_b8 = 0;
    p->mUnk_b8 = -0x1000;
    p->mUnk_50 = z;
    p->mUnk_5c = &p->mUnk_44;
    p->mUnk_c2 = 0;
    p->mUnk_c4 = FALSE;
    p->mUnk_c8 = 0;
    p->mUnk_ca = 0;
    p->mUnk_cc = 0;
    p->mUnk_d0 = NULL;
    p->mEntrySearchStartIndex = 0;
    p->mUnk_d8 = 0;
    p->mUnk_dc = z;
}

void func_02089788(Unk020888b4 *p, Kart *q) {
    Unk02165ff0 *t;
    Unk0217aebc_128 *r;
    s16 j;
    s32 v;
    s16 k;

    p->mKart = q;
    p->mIndex = q->mIndex;
    p->mUnk_06 = p->mIndex % 4;
    func_02080908(&p->mUnk_28, &q->mPos, &q->mUnk_138, q->mIndex);
    p->mUnk_44 = *p->mUnk_28.mUnk_00->mUnk_20;
    func_020898bc(p);
    if (data_021759c0->mUnk_18 == 0) {
        t = data_0217b030;
        k = 0;
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        for (j = 0; j < 3; j++) {
            if (t->mUnk_00[j] > 0 && v <= t->mUnk_00[j]) {
                k = j + 1;
                break;
            }
        }
        p->mUnk_c0 = k;
    } else {
        p->mUnk_c0 = 0;
    }
}

void func_02089754(Unk020888b4 *p, Unk02175620_bc *a) {
    func_020808d4(&p->mUnk_28, a);
    p->mUnk_44 = *p->mUnk_28.mUnk_00->mUnk_20;
    func_020898bc(p);
}

void func_020896e0(Unk020888b4 *p) {
    func_02088d34(p);
    if (p->mUnk_c4 == FALSE) {
        func_0207e668(p);
    }
    func_02089494(p);
    if (data_021759c0->mUnk_18 == 0) {
        func_02088e44(p);
        return;
    }
    if (p->mUnk_d0 != NULL) {
        func_02088e44(p);
    }
    func_02088a0c(p);
}

void func_02089494(Unk020888b4 *p) {
    Unk0208001c *s;
    Kart *q;
    Unk02175620_bc *e;
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
    s = &p->mUnk_28;
    g = &q->mUnk_138;
    e = s->mUnk_14;
    GetKartPos(&v, p->mIndex);
    if (q->mUnk_48 & 0x3840) {
        return;
    }
    if (e != NULL && s->mUnk_00 != e) {
        func_0208001c(s, e);
        p->mUnk_a4 = func_020800a0(s);
        func_020892bc(p);
        p->mUnk_44 = *s->mUnk_00->mUnk_20;
        VEC_Add(&p->mUnk_44, &p->mUnk_60, &p->mUnk_44);
    } else {
        if (p->mIndex == GetRaceUpdateFramesMod8()) {
            f = p->mUnk_5c;
            z = *g;
            VEC_Subtract(f, &q->mPos, &t);
            z.y = 0;
            t.y = 0;
            VEC_CrossProduct(&z, &t, &u);
            d = VEC_Mag(&u);
            p->mUnk_70 = ((s64) FX_Atan2(d, VEC_DotProduct(&z, &t)) * 0x394bb834c8LL + 0x80000000LL) >> 32;
        }
        if (func_02080e2c(s, &v) != 0 || func_02080dbc(s, &v) != 0) {
            x = FALSE;
            if (p->mUnk_b0 != NULL && p->mUnk_b4 != 0) {
                x = TRUE;
            }
            if (x != FALSE) {
                y = p->mUnk_b0->mIndex;
            } else {
                y = -1;
            }
            func_020800f4(s, &v, &q->mUnk_138, p->mIndex, p->mUnk_d0, y);
            p->mUnk_a4 = func_020800a0(s);
            func_020892bc(p);
            p->mUnk_44 = *s->mUnk_00->mUnk_20;
            VEC_Add(&p->mUnk_44, &p->mUnk_60, &p->mUnk_44);
            s->mUnk_14 = NULL;
            s->mUnk_18 = FALSE;
        }
    }
    if (q->mState != KART_STATE_NORMAL) {
        return;
    }
    if (p->mUnk_c4 != FALSE) {
        return;
    }
    func_0204360c(p->mKart->mEntryIndex, 1);
    VEC_Subtract(p->mUnk_5c, &v, &w);
    func_01ffd224(p, &w, g);
}

void func_020892bc(Unk020888b4 *p) {
    Vec3 z = data_02155eb0;
    Unk0217aebc_128 *r;
    s32 a;
    s32 t;
    s32 u;
    s32 n;
    s32 f;

    VEC_CrossProduct(&p->mUnk_28.mUnk_08, &z, &p->mUnk_60);
    p->mUnk_6c++;
    if (p->mUnk_6c > p->mUnk_6e) {
        p->mUnk_6c = 0;
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        p->mUnk_6e = 0;
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        a = (s16) (u16) (r->mUnk_00 >> 52);
        t = (s32) (((s64) a * 0x2000 + 0x800) >> 12) - 0x1000;
        u = ((s64) t * 0x4ce + 0x800) >> 12;
        n = p->mUnk_74 + u;
        if (func_020738f8(n) > 0xb36) {
            if (n > 0) {
                n = 0xb36;
            } else {
                n = -0xb36;
            }
        }
        p->mUnk_74 = n;
    }
    f = ((s64) p->mUnk_74 * p->mUnk_28.mUnk_00->mUnk_24 + 0x800) >> 12;
    p->mUnk_60.x = ((s64) p->mUnk_60.x * f) >> 12;
    p->mUnk_60.y = ((s64) p->mUnk_60.y * f) >> 12;
    p->mUnk_60.z = ((s64) p->mUnk_60.z * f) >> 12;
}

void func_02088e44(Unk020888b4 *p) {
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
    if (data_021759c0->mUnk_014 == 1) {
        return;
    }
    if (p->mUnk_b0 == NULL) {
        p->mUnk_5c = &p->mUnk_44;
        k = gSearchStartIndex;
        for (n = 0; n < (u32) data_021759c0->mKartCount; n++) {
            if (func_0207f554(p->mIndex, k) != 0) {
                o = GetKart(k);
                v3 = &p->mKart->mPos;
                d = func_020888b4_inline(v3, &o->mPos);
                c = 0;
                if (d < 0x895440) {
                    if (func_020738f8(p->mKart->mPos.y - o->mPos.y) < 0x3c000) {
                        c = 1;
                        p->mUnk_b8 = d;
                    }
                }
                if (c != 0) {
                    v2 = data_021759c0->mKartCount;
                    gSearchStartIndex++;
                    if (gSearchStartIndex >= v2) {
                        gSearchStartIndex = 0;
                    }
                    goto store;
                }
            }
            k++;
            if (k >= (u32) data_021759c0->mKartCount) {
                k = 0;
            }
        }
        o = NULL;
    store:
        p->mUnk_b0 = o;
        return;
    }
    v1 = &gKartItems[m];
    if (v1->mItemInUse.mUnk_000 == 0xf && v1->mHeldItem.mUnk_00 == 0x13 && (p->mKart->mUnk_4c & 0x40) == 0) {
        goto clear;
    }
    if (func_0207f600(p->mUnk_b0->mIndex) == FALSE) {
        goto clear;
    }
    q = p->mKart;
    o = p->mUnk_b0;
    v3 = &q->mPos;
    d = func_020888b4_inline(v3, &o->mPos);
    c = 0;
    if (d < 0xf42400) {
        if (func_020738f8(p->mKart->mPos.y - p->mUnk_b0->mPos.y) < 0x3c000) {
            p->mUnk_b8 = d;
            c = 1;
        }
    }
    if (c == 0) {
        goto clear;
    }
    if (func_020738f8(p->mKart->mPos.y - p->mUnk_b0->mPos.y) >= 0x3c000) {
        goto clear;
    }
    c = 0;
    VEC_Subtract(&p->mUnk_b0->mPos, &p->mKart->mPos, &v);
    if (VEC_DotProduct(&v, &p->mKart->mUnk_138) > 0) {
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v, &v);
        }
        p->mUnk_bc = VEC_DotProduct(&v, &p->mKart->mUnk_138);
        c = 1;
    }
    p->mUnk_b4 = c != 0;
    if (p->mUnk_b4 != 0) {
        v1 = &gKartItems[p->mIndex];
        c = 1;
        if (v1->mItemInUse.mUnk_000 == 0xf && v1->mHeldItem.mUnk_00 == 0x13) {
            if ((GetKart(p->mIndex)->mUnk_4c & 0x40) == 0) {
                c = 0;
            }
        }
        x = c != 0 ? 1 : 0;
        y = (p->mUnk_b0->mUnk_4c & 0x40) != 0 ? 1 : 0;
        if (x != 0 && y == 0 && p->mUnk_bc > 0xb33) {
            u = p->mUnk_b0->mPos;
            u.y = p->mUnk_44.y;
            t = *p->mUnk_28.mUnk_00->mUnk_20;
            z = data_02155eb0;
            VEC_CrossProduct(&p->mUnk_28.mUnk_08, &z, &e);
            VEC_Subtract(&u, &t, &w);
            d = Vec3DotUnrounded(&w, &e);
            c = p->mUnk_28.mUnk_00->mUnk_24;
            if (func_020738f8(d) >= c) {
                p->mUnk_5c = &p->mUnk_44;
            } else {
                p->mUnk_50 = u;
                p->mUnk_5c = &p->mUnk_50;
            }
        } else {
            p->mUnk_5c = &p->mUnk_44;
        }
    } else {
        p->mUnk_5c = &p->mUnk_44;
    }
    return;
clear:
    p->mUnk_b0 = NULL;
    p->mUnk_5c = &p->mUnk_44;
}

void func_02088d34(Unk020888b4 *p) {
    s32 a;
    u16 b;
    BOOL c;

    p->mUnk_c4 = FALSE;
    if (data_021759c0->mUnk_18 != 0) {
        return;
    }
    if (func_01ffc67c(p->mKart) != FALSE) {
        func_020a228c(p->mIndex);
        return;
    }
    a = GetBalloonOrShineCount(p->mIndex);
    b = func_020a10d4(p->mIndex);
    if (a >= p->mUnk_c0) {
        return;
    }
    c = FALSE;
    if (b > data_0217b030->mUnk_1a || (b == data_0217b030->mUnk_1a && func_020a2204(p->mIndex) != 0)) {
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

void func_02088c7c(Unk020888b4 *p) {
    s32 *t = data_0217b030->mUnk_0c;
    Unk0217aebc_128 *r;
    s16 j;
    s32 v;
    s16 k = 0;

    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    for (j = 0; j < 3; j++) {
        if (t[j] > 0 && v <= t[j]) {
            k = j + 1;
            break;
        }
    }
    p->mUnk_c0 = k;
}

void func_02088a0c(Unk020888b4 *p) {
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

    r = p->mUnk_d0;
    if (r != NULL) {
        if (!(r->mFlags & 1)) {
            v1 = &r->mPos;
            v2 = &p->mKart->mPos;
            d = func_020888b4_inline(v2, v1);
            m = gEntryYDifferenceLimit;
            if (d < 0x15f900 && func_020738f8(p->mKart->mPos.y - r->mPos.y) < m) {
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
                    p->mUnk_d8 = VEC_DotProduct(&v, &p->mKart->mUnk_138);
                    n = TRUE;
                }
                if (n != FALSE && p->mUnk_d8 > 0xb33) {
                    u = r->mPos;
                    u.y = p->mUnk_44.y;
                    t = *p->mUnk_28.mUnk_00->mUnk_20;
                    z = data_02155eb0;
                    VEC_CrossProduct(&p->mUnk_28.mUnk_08, &z, &e);
                    VEC_Subtract(&u, &t, &w);
                    m = Vec3DotUnrounded(&w, &e);
                    x = p->mUnk_28.mUnk_00->mUnk_24;
                    if (func_020738f8(m) >= x) {
                        p->mUnk_5c = &p->mUnk_44;
                    } else {
                        p->mUnk_dc = u;
                        p->mUnk_5c = &p->mUnk_dc;
                    }
                } else {
                    p->mUnk_5c = &p->mUnk_44;
                }
            } else {
                p->mUnk_d0 = NULL;
                p->mUnk_5c = &p->mUnk_44;
            }
        } else {
            p->mUnk_d0 = NULL;
            p->mUnk_5c = &p->mUnk_44;
        }
    } else {
        if (p->mIndex == GetRaceUpdateFramesMod8()) {
            func_020888b4(p, 0x17d7840, gEntryYDifferenceLimit);
        }
    }
}

BOOL func_020888b4(Unk020888b4 *p, s32 a, s32 b) {
    Unk02100094 *l;
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
    n = func_021000c8(l);
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
            if (d < a && func_020738f8(p->mKart->mPos.y - e->mPos.y) < b) {
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
        p->mUnk_d0 = r;
        return TRUE;
    }
    return FALSE;
}
