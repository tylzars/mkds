#include "Main/Unknown/code_0207ffa4.h"

#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020800f4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020808d4.h"
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
#include "Main/Unknown/code_02080adc.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_02080cc0.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02077bc0.h"

void func_02081060(Kart *p) {
    Unk0201ca6c *e;

    if (!(p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    if (data_0217ae94[p->mIndex] != NULL) {
        return;
    }
    data_0217ae94[p->mIndex] = StartEffect(0x80, &data_02155a14);
    e = data_0217ae94[p->mIndex];
    e->mUnk_98_24 = p->mIndex;
    e->mUnk_94 = 0;
    e->mUnk_90 = AdvanceKartAheadEffect;
}

void func_02081000(Kart *p) {
    Unk0201ca6c *e = data_0217ae94[p->mIndex];

    if (e == NULL) {
        return;
    }
    e->mUnk_98_16 = 0;
    e->mUnk_98_8 = 3;
    e->mUnk_90 = AdvanceKartAheadEffectWithLimit;
    data_0217ae94[p->mIndex] = NULL;
}

void func_02080fb8(Kart *p) {
    if (data_0217ae94[p->mIndex] == NULL) {
        return;
    }
    func_0208b710(data_0217ae94[p->mIndex]);
    data_0217ae94[p->mIndex] = NULL;
}

void func_02080f44(Kart *p) {
    Unk0201ca6c *e;

    if (data_0217ae74[p->mIndex] != NULL) {
        return;
    }
    data_0217ae74[p->mIndex] = StartEffect(0x7f, &data_02155a14);
    e = data_0217ae74[p->mIndex];
    e->mUnk_98_24 = p->mIndex;
    e->mUnk_94 = (void *) 1;
    e->mUnk_90 = AdvanceKartAheadEffect;
}

void func_02080ee4(Kart *p) {
    Unk0201ca6c *e = data_0217ae74[p->mIndex];

    if (e == NULL) {
        return;
    }
    e->mUnk_98_16 = 0;
    e->mUnk_98_8 = 5;
    e->mUnk_90 = AdvanceKartAheadEffectWithLimit;
    data_0217ae74[p->mIndex] = NULL;
}

void func_02080e9c(Kart *p) {
    if (data_0217ae74[p->mIndex] == NULL) {
        return;
    }
    func_0208b710(data_0217ae74[p->mIndex]);
    data_0217ae74[p->mIndex] = NULL;
}

void func_02080e88(Unk0201ca6c *p, Kart *q) {
    p->mUnk_6c = (s16) q->mScale.z;
}

s32 IsWithinBattlePointLinkDistance(LinkCursor *p, Vec3 *a) {
    Vec3 v;
    s32 n;
    BOOL r = FALSE;

    n = p->mLink->mUnk_24;
    VEC_Subtract(p->mLink->mUnk_20, a, &v);
    v.y = r;
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z < (s64) n * n) {
        r = TRUE;
    }
    return r;
}

s32 IsPastBattlePointLink(LinkCursor *p, Vec3 *a) {
    Vec3 v;
    Vec3 *t = p->mLink->mUnk_20;
    BOOL r = FALSE;

    if (p->mDirection.x != 0 || p->mDirection.y != 0 || p->mDirection.z != 0) {
        VEC_Subtract(a, t, &v);
        if (Vec3DotUnrounded(&p->mDirection, &v) > 0) {
            r = TRUE;
        }
    }
    return r;
}

void InitRacePointLinkCursor(Unk02080d34 *p, u16 kartIndex) {
    p->mUnk_00.mLink = gCourseMap->mRaceRoute0FirstLink;
    p->mUnk_00.mPreviousLink = p->mUnk_00.mLink->mUnk_0c;
    p->mUnk_00.mDirection = data_021557ec;
    VEC_Subtract(p->mUnk_00.mLink->mUnk_18, p->mUnk_00.mPreviousLink->mUnk_18, &p->mUnk_00.mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&p->mUnk_00.mDirection, &p->mUnk_00.mDirection);
    p->mUnk_00.mRequestedLink = NULL;
    p->mUnk_00.mUnk_18 = FALSE;
    p->mKartIndex = kartIndex;
    p->mUnk_1e = 0;
}

void ResetPointLinkCursor(LinkCursor *p, PointLink *a) {
    p->mLink = a;
    p->mPreviousLink = p->mLink->mUnk_0c;
    p->mRequestedLink = NULL;
    p->mUnk_18 = FALSE;
    p->mDirection = data_021557ec;
    VEC_Subtract(p->mLink->mUnk_18, p->mPreviousLink->mUnk_18, &p->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&p->mDirection, &p->mDirection);
}

s16 func_02080cc0(LinkCursor *p) {
    return *(s16 *) p->mLink->mUnk_20;
}

s32 IsWithinPointLinkDistance(PointLinkCursor *p, Vec3 *a) {
    Vec3 v;
    s32 d;
    BOOL r;
    Unk02080b1c_00 *n = p->mLink;

    r = FALSE;
    d = n->mUnk_1c;
    VEC_Subtract(n->mUnk_18, a, &v);
    v.y = r;
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z < (s64) d * d) {
        r = TRUE;
    }
    return r;
}

s32 IsPastPointLink(PointLinkCursor *p, Vec3 *a) {
    Vec3 v;
    BOOL r;
    Vec3 *w = p->mLink->mUnk_18;

    r = FALSE;
    if (p->mDirection.x != 0 || p->mDirection.y != 0 || p->mDirection.z != 0) {
        VEC_Subtract(a, w, &v);
        if (Vec3DotUnrounded(&p->mDirection, &v) > 0) {
            r = TRUE;
        }
    }
    return r;
}

void AdvancePointLinkCursor(PointLinkCursor *p) {
    u16 i = 0;
    u16 n;
    u32 v;
    RandomState64 *q;

    if (!(GetKart(p->mKartIndex)->mUnk_4c & 0x10000000)) {
        n = p->mLink->mUnk_24;
        if (n > 1) {
            q = GetKartAiRandom();
            if (n == 0) {
                v = 0;
            } else {
                q->mValue = (s64) q->mMultiplier * (s64) q->mValue + q->mIncrement;
                v = (n == 0) ? (u32) (q->mValue >> 32) : (u32) (((q->mValue >> 32) * (u32) n) >> 32);
            }
            i = v;
        }
    }
    p->mPreviousLink = p->mLink;
    p->mLink = p->mLink->mUnk_00[i];
    VEC_Subtract(p->mLink->mUnk_18, p->mPreviousLink->mUnk_18, &p->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&p->mDirection, &p->mDirection);
}

void AdvancePointLinkCursorTo(LinkCursor *p, PointLink *a) {
    p->mPreviousLink = p->mLink;
    p->mLink = a;
    VEC_Subtract(p->mLink->mUnk_18, p->mPreviousLink->mUnk_18, &p->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&p->mDirection, &p->mDirection);
}

void func_02080ac0(LinkCursor *p) {
    if (p->mRequestedLink == NULL) {
        p->mRequestedLink = p->mPreviousLink;
        p->mUnk_18 = FALSE;
    }
}

void ResetBattlePointLinkCursorNear(LinkCursor *p, Vec3 *a, Vec3 *b, u16 c) {
    PointLink *r = NULL;
    u16 i;
    u16 j;
    s32 k;
    s32 m;
    s32 d;
    PointLink *v1 = gCourseMap->mFirstBattlePointLink;
    PointLink *v2[3] = {0, 0, 0};
    s32 v3[3];
    Vec3 v;
    Vec3 w;

    v3[0] = v3[1] = v3[2] = 0xc8000;
    m = -0x1000;
    for (i = 0; i < gCourseMap->mBattlePointCount; i++) {
        VEC_Subtract(&gCourseMap->mBattlePoints[i].mPos, a, &v);
        d = VEC_Mag(&v);
        if (d < 0xc8000) {
            for (k = 0; k < 3; k++) {
                if (d < v3[k]) {
                    v3[k] = d;
                    v2[k] = &v1[i];
                    break;
                }
            }
        }
    }
    for (j = 0; j < 3; j++) {
        if (v2[j] != NULL) {
            VEC_Subtract(v2[j]->mUnk_20, a, &w);
            if ((s64) w.x * w.x + (s64) w.y * w.y + (s64) w.z * w.z >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&w, &w);
            }
            d = Vec3DotUnrounded(&w, b);
            if (d >= m) {
                r = v2[j];
                m = d;
            }
        }
    }
    p->mLink = r;
    p->mPreviousLink = r;
    p->mDirection = data_021557ec;
    p->mRequestedLink = NULL;
    p->mUnk_18 = FALSE;
}

void ResetBattlePointLinkCursorTo(LinkCursor *p, PointLink *a) {
    p->mPreviousLink = a;
    p->mLink = p->mPreviousLink;
    p->mDirection = data_021557ec;
    p->mRequestedLink = NULL;
    p->mUnk_18 = FALSE;
}

void AdvanceBattlePointLinkCursor(LinkCursor *p, Vec3 *a, Vec3 *b, u16 c, Unk020888b4_d0 *d, s32 e) {
    s32 m2;
    PointLink *r;
    s32 m1;
    PointLink *v1 = p->mLink;
    u16 n2 = 0;
    PointLink *v2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    u16 n1;
    s32 m0;
    Kart *o;
    PointLink *q;
    s32 u;
    u16 n;
    u16 l;
    u16 h;
    u32 v32;
    BOOL v3;
    PointLink *f;
    u16 n0;
    s32 t;
    u16 i;
    u8 j;
    RandomState64 *g;
    u16 k;
    Vec3 v;
    Vec3 w;
    Vec3 x;
    Vec3 y;
    Vec3 z[2];
    Vec3 s;

    m2 = -0x1000;
    m1 = 0x1000;
    r = NULL;
    m0 = m2;
    f = NULL;
    if (p->mLink->mUnk_2c == 1) {
        r = p->mLink->mUnk_00[0];
    } else {
        PointLink *v4[2] = {0, 0};

        n = 0;
        n1 = 0;
        n1 = n1;
        n0 = 0;
        if (d != NULL) {
            k = 0;
            VEC_Subtract(&d->mPos, &GetKart(c)->mPos, &v);
            if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&v, &v);
            }
            for (i = 0; i < p->mLink->mUnk_2c; i++) {
                if (p->mPreviousLink == ((const LinkCursor *) p)->mLink->mUnk_00[i]) {
                    continue;
                }
                VEC_Subtract(p->mLink->mUnk_00[i]->mUnk_20, &GetKart(c)->mPos, &w);
                if ((s64) w.x * w.x + (s64) w.y * w.y + (s64) w.z * w.z >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&w, &w);
                }
                t = Vec3DotUnrounded(&w, b);
                if (t >= -0x800) {
                    u = VEC_DotProduct(&v, &w);
                    if (u > m0 || k == 0) {
                        m0 = u;
                        k++;
                        r = p->mLink->mUnk_00[i];
                    }
                } else if (t >= m2 || n2 == 0) {
                    m2 = t;
                    f = p->mLink->mUnk_00[i];
                    n2++;
                }
            }
        } else if (e != -1) {
            n1 = (u16) n1;
            if (GetKart(e)->mUnk_4c & 0x40) {
                v3 = TRUE;
            } else {
                v3 = FALSE;
            }
            o = GetKart(c);
            VEC_Subtract(&GetKart(e)->mPos, &o->mPos, &x);
            if ((s64) x.x * x.x + (s64) x.y * x.y + (s64) x.z * x.z >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&x, &x);
            }
            for (i = 0; i < p->mLink->mUnk_2c; i++) {
                if (p->mPreviousLink == ((const LinkCursor *) p)->mLink->mUnk_00[i]) {
                    continue;
                }
                VEC_Subtract(p->mLink->mUnk_00[i]->mUnk_20, &GetKart(c)->mPos, &y);
                if ((s64) y.x * y.x + (s64) y.y * y.y + (s64) y.z * y.z >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&y, &y);
                }
                t = Vec3DotUnrounded(&y, b);
                if (t >= -0x800) {
                    if (v3 == FALSE) {
                        u = VEC_DotProduct(&x, &y);
                        if (u > m0 || n0 == 0) {
                            m0 = u;
                            r = p->mLink->mUnk_00[i];
                            n0++;
                        }
                    } else {
                        u = VEC_DotProduct(&x, &y);
                        if (u < m1 || n1 == 0) {
                            m1 = u;
                            r = p->mLink->mUnk_00[i];
                            n1++;
                        }
                    }
                } else if (t >= m2 || n2 == 0) {
                    m2 = t;
                    f = p->mLink->mUnk_00[i];
                    n2++;
                }
            }
        } else {
            for (i = 0; i < p->mLink->mUnk_2c; i++) {
                if (p->mPreviousLink != ((const LinkCursor *) p)->mLink->mUnk_00[i] &&
                    !(p->mLink->mUnk_2e & (1 << (u8) i))) {
                    v4[n0] = ((const LinkCursor *) p)->mLink->mUnk_00[i];
                    n0++;
                    n1 = 1;
                }
            }
            if (n1 != 0) {
                l = 0;
                if (n0 > 1) {
                    for (h = 0; h < 2; h++) {
                        VEC_Subtract(v4[h]->mUnk_20, p->mLink->mUnk_20, &z[h]);
                        if ((s64) z[h].x * z[h].x + (s64) z[h].y * z[h].y + (s64) z[h].z * z[h].z >= 0x10) {
                            Vec3NormalizeAndGetLengthUnchecked(&z[h], &z[h]);
                        }
                    }
                    if (Vec3DotUnrounded(&z[0], b) < Vec3DotUnrounded(&z[1], b)) {
                        l = 1;
                    }
                }
                v2[0] = v4[l];
                n = 1;
            } else {
                for (i = 0; i < ((const PointLink *) p->mLink)->mUnk_2c; i++) {
                    if (p->mPreviousLink != ((const LinkCursor *) p)->mLink->mUnk_00[i] &&
                        (p->mLink->mUnk_2e & (1 << (u8) i))) {
                        s = data_021557ec;
                        q = p->mLink->mUnk_00[i];
                        for (j = 0; j < q->mUnk_2c; j++) {
                            if (!(q->mUnk_2e & (1 << j)) && ((const LinkCursor *) p)->mLink != q->mUnk_00[j]) {
                                VEC_Subtract(q->mUnk_00[j]->mUnk_20, q->mUnk_20, &s);
                                if ((s64) s.x * (s64) s.x + (s64) s.y * (s64) s.y + (s64) s.z * (s64) s.z >= 0x10) {
                                    Vec3NormalizeAndGetLengthUnchecked(&s, &s);
                                }
                                break;
                            }
                        }
                        t = Vec3DotUnrounded(&s, b);
                        if (t >= -0x800) {
                            v2[n] = p->mLink->mUnk_00[i];
                            n++;
                        } else if (t >= m2 || n2 == 0) {
                            m2 = t;
                            f = p->mLink->mUnk_00[i];
                            n2++;
                        }
                    }
                }
            }
        }
        if (r == NULL) {
            if (n == 0) {
                r = f;
            } else {
                if (n == 1) {
                    k = 0;
                } else {
                    g = GetKartAiRandom();
                    if (n == 0) {
                        v32 = 0;
                    } else {
                        g->mValue = g->mMultiplier * g->mValue + g->mIncrement;
                        if (n == 0) {
                            v32 = g->mValue >> 32;
                        } else {
                            v32 = ((g->mValue >> 32) * (u32) n) >> 32;
                        }
                    }
                    k = v32;
                }
                r = v2[k];
            }
        }
    }
    p->mLink = r;
    p->mPreviousLink = v1;
    p->mDirection = data_021557ec;
    VEC_Subtract(p->mLink->mUnk_20, p->mPreviousLink->mUnk_20, &p->mDirection);
    if ((s64) p->mDirection.x * p->mDirection.x + (s64) p->mDirection.y * p->mDirection.y +
            (s64) p->mDirection.z * p->mDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&p->mDirection, &p->mDirection);
    }
}

s32 func_020800a0(LinkCursor *p) {
    s32 r = 0;
    s16 a = *p->mLink->mUnk_28;

    if (a != 0) {
        r = ((s64) a * 0x28f5c) >> 12;
    }
    return r;
}

void AdvanceBattlePointLinkCursorTo(LinkCursor *p, PointLink *a) {
    p->mPreviousLink = p->mLink;
    p->mLink = a;
    p->mDirection = data_021557ec;
    VEC_Subtract(p->mLink->mUnk_20, p->mPreviousLink->mUnk_20, &p->mDirection);
    if ((s64) p->mDirection.x * p->mDirection.x + (s64) p->mDirection.y * p->mDirection.y +
            (s64) p->mDirection.z * p->mDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&p->mDirection, &p->mDirection);
    }
}

void SetupPointLinkCursor(PointLinkCursor *cursor, u32 kartIndex, Unk02080b1c_00 *link) {
    cursor->mDirection = data_021557ec;
    cursor->mPreviousLink = link;
    cursor->mLink = cursor->mPreviousLink->mUnk_00[0];
    VEC_Subtract(cursor->mLink->mUnk_18, cursor->mPreviousLink->mUnk_18, &cursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&cursor->mDirection, &cursor->mDirection);
    cursor->mUnk_14 = 0;
    cursor->mUnk_18 = 0;
    cursor->mKartIndex = kartIndex;
}
