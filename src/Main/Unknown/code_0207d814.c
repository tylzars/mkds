#include "Main/Unknown/code_0207d814.h"

#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020435c4.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void func_0207e594(struct Unk020888b4 *p, struct Kart *q, s32 a) {
    p->mKart = q;
    p->mIndex = q->mIndex;
    p->mUnk_06 = p->mIndex % 4;
    p->mUnk_88 = 0x1000;
    if (data_021759c0->mUnk_00c == 5) {
        p->mUnk_8c = 0;
    } else {
        p->mUnk_8c = 0x1000;
    }
    p->mUnk_9c = (s32) (((s64) p->mKart->mPhysicalParam->mBaseSpeedLimit * 0x99a + 0x800) >> 12);
    func_02080d34(&p->mUnk_08, p->mIndex);
    func_0207f9cc(p, 0);
    p->mUnk_cc = 1;
}

void func_0207e564(struct Unk020888b4 *p, struct Unk02175620_bc *a) {
    func_02080cd0(&p->mUnk_08.mUnk_00, a);
    func_0207f9cc(p, 1);
    func_0207f9cc(p, 1);
}

void func_0207e4a4(struct Unk020888b4 *p) {
    Vec3 a;
    Vec3 b;
    Unk0208001c *s;
    Kart *q;
    Vec3 *t;
    Unk02175620_bc *r;

    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        func_0207e668(p);
    }
    s = &p->mUnk_08.mUnk_00;
    q = p->mKart;
    if (p->mUnk_90 == 2) {
        t = &q->mUnk_50;
    } else {
        t = &q->mUnk_138;
    }
    r = s->mUnk_14;
    GetKartPos(&a, p->mIndex);
    func_0207f6f0(p, s, q, r, &a, t);
    if (q->mState == 0) {
        func_0204360c(p->mKart->mEntryIndex, 1);
        Vec3Sub(&p->mUnk_44, &a, &b);
        func_01ffd224(p, &b, t);
    }
    func_0207ebfc(p);
}

void func_0207e400(struct Unk020888b4 *p, struct Kart *q, s32 a) {
    p->mKart = q;
    p->mIndex = q->mIndex;
    p->mUnk_06 = p->mIndex % 4;
    p->mUnk_88 = 0x1000;
    p->mUnk_8c = 0;
    p->mUnk_9c = (s32) (((s64) p->mKart->mPhysicalParam->mBaseSpeedLimit * 0x99a + 0x800) >> 12);
    func_02080d34(&p->mUnk_08, p->mIndex);
    func_0207f9cc(p, 0);
    p->mUnk_cc = 1;
}

void func_0207e35c(struct Unk020888b4 *p) {
    Vec3 a;
    Vec3 b;
    Unk0208001c *s = &p->mUnk_08.mUnk_00;
    Kart *q = p->mKart;
    Vec3 *t;
    Unk02175620_bc *r;

    if (p->mUnk_90 == 2) {
        t = &q->mUnk_50;
    } else {
        t = &q->mUnk_138;
    }
    r = s->mUnk_14;
    GetKartPos(&a, p->mIndex);
    func_0207f6f0(p, s, q, r, &a, t);
    if (q->mState == 0) {
        func_0204360c(p->mKart->mEntryIndex, 1);
        Vec3Sub(&p->mUnk_44, &a, &b);
        func_01ffd224(p, &b, t);
    }
    func_0207ebfc(p);
}

void func_0207e268(void) {
    s32 d;

    switch (func_020853dc()) {
        case 0:
            data_usa_0217ae30 = data_usa_02155630;
            data_usa_0217ae2c = data_usa_0215569c;
            break;
        case 1:
            data_usa_0217ae30 = data_usa_02155654;
            data_usa_0217ae2c = data_usa_021556c0;
            break;
        case 2:
        default:
            data_usa_0217ae30 = data_usa_02155678;
            data_usa_0217ae2c = data_usa_0215560c;
            break;
    }
    data_usa_021658f0 = 3;
    d = data_021759c0->mKartCount - data_021759c0->mUnk_3d1;
    if (d > 1) {
        if (d <= 3) {
            data_usa_021658f0 = d - 1;
        }
    }
    data_usa_0217ae34 = data_usa_02165910[d];
}

u32 func_0207e200(struct Unk02089a24 *arg0, struct Unk020888b4 *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value4;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value4 = value0;
    value0 = (u32) arg1->mKart->mPhysicalParam->mBaseSpeedLimit;
    *(u32 *) ((value4) + (0)) = value0;
    value0 = (u32) * (const u32 *) ((value4) + (0));
    *(u32 *) ((value4) + (16)) = value0;
    value0 = (u32) arg1->mIndex;
    value0 = (u32) func_020853f0(value0);
    *(u32 *) ((value4) + (28)) = value0;
    value0 = (u32) * (const u32 *) ((value4) + (28));
    value2 = 0u;
    *(u32 *) ((value4) + (32)) = value0;
    *(u32 *) ((value4) + (36)) = value2;
    value1 = (u32) * (const u32 *) ((value4) + (0));
    value0 = ~(0u);
    *(u32 *) ((value4) + (4)) = value1;
    *(u32 *) ((value4) + (8)) = value2;
    *(u32 *) ((value4) + (12)) = value2;
    value1 = (u32) * (const u32 *) ((value4) + (0));
    *(u32 *) ((value4) + (16)) = value1;
    *(u32 *) ((value4) + (20)) = value0;
    *(u32 *) ((value4) + (24)) = value2;
    return value0;
}

void func_0207e1d4(struct Unk02089a24 *p0, struct Unk020888b4 *p1) {
    p0->mUnk_04 = (u32) (((u32) p0->mUnk_00));
    p0->mUnk_08 = (u32) 0x0u;
    p0->mUnk_0c = (u32) 0x0u;
    p0->mUnk_10 = (u32) (((u32) p0->mUnk_00));
    p0->mUnk_14 = (u32) ((~(0x0u)));
    p0->mUnk_18 = (u32) 0x0u;
}

void func_0207e088(struct Unk02089a24 *a, struct Unk020888b4 *b) {
    BOOL f = FALSE;
    s32 v;
    BOOL r6;
    s32 r5;
    s32 r4;
    s32 t;
    Unk0217aebc_128 *r;
    Unk020888b4 *u;

    v = data_021759c0->mCurrentEntries[b->mIndex].mPlayer.mKind;
    if ((u32) v <= 3) {
        if ((1 << v) & 0xd) {
            f = TRUE;
        }
    }
    if (f != FALSE) {
        return;
    }
    r6 = FALSE;
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    r4 = (s16) (u16) (r->mUnk_00 >> 52);
    r5 = func_020853f0(b->mIndex);
    u = GetKart(b->mIndex)->mUnk_310;
    if (u->mUnk_154 != 0) {
        r5 = r6;
    }
    t = data_usa_0217ae30[r5];
    if (r4 < t || t >= 0x1000) {
        a->mUnk_2c = 1;
        a->mUnk_30 = func_0207d8e4(u->mUnk_154);
        r6 = TRUE;
    }
    if (r6 != FALSE) {
        return;
    }
    t = data_usa_0217ae2c[r5];
    if (r4 >= t) {
        if (!((float) t >= 1.0f)) {
            return;
        }
    }
    a->mUnk_28 = 1;
}

void func_0207de84(struct Unk02089a24 *a, struct Unk020888b4 *b) {
    BOOL f;
    s32 v;
    s32 t;
    s32 s;
    Kart *q;

    if (b->mIndex == func_02061f90()) {
        a->mUnk_08 = 0;
        a->mUnk_18 = 0;
        f = FALSE;
        v = data_021759c0->mCurrentEntries[b->mIndex].mPlayer.mKind;
        if ((u32) v <= 3) {
            if ((1 << v) & 0xd) {
                f = TRUE;
            }
        }
        if (f != FALSE) {
            a->mUnk_14 = GetKartRank(b->mIndex);
        } else {
            a->mUnk_14 = func_020854c0(b->mIndex);
        }
        a->mUnk_08 = func_02085424()->mUnk_00;
        if (func_02085390() != 0) {
            a->mUnk_08 = a->mUnk_08 >> 1;
        }
        q = b->mKart;
        t = a->mUnk_08 + q->mSpeedLimitGoal;
        if (b->mUnk_a8 == 2) {
            t = 0x3000;
        }
        if (t > 0xa000) {
            t = 0xa000;
        }
        if (q->mUnk_4c & 0x8000000) {
            t = (s32) (((s64) t * 0xb33 + 0x800) >> 12);
        }
        if (b->mUnk_90 == 0) {
            a->mUnk_0c = t;
            if (b->mUnk_70 > 0x5000) {
                s = (s32) (((s64) (b->mUnk_70 - 0x5000) * 0x5b) >> 12);
                if (s > 0x1000) {
                    s = 0x1000;
                }
                a->mUnk_0c = (s32) (((s64) (0x1000 - (s32) (((s64) s * 0x668) >> 12)) * 0xa000) >> 12);
            }
            func_0207d9f0(a, b, t);
            t = a->mUnk_10;
        }
        if (a->mUnk_0c < t) {
            t = a->mUnk_0c;
        }
        if (t > 0xa000) {
            t = 0xa000;
        }
        a->mUnk_04 = t;
    }
    q = b->mKart;
    if (q->mState != 0) {
        return;
    }
    if (q->mUnk_4c & 0x10000000) {
        return;
    }
    if ((q->mUnk_48 & 0x10000020) == 0) {
        q->mSpeedLimitGoal = a->mUnk_04;
    }
}

void func_0207d9f0(struct Unk02089a24 *a, struct Unk020888b4 *b, s32 c) {
    s32 n = a->mUnk_14;
    u16 m = b->mIndex;
    u16 i;
    BOOL f;
    s32 v;
    s32 d;
    s32 *k = &a->mUnk_1c;
    Unk0217aec0 *r = func_02085424();
    s32 e;
    s32 g;
    const s32 *t;

    a->mUnk_18 = 0;
    f = FALSE;
    v = data_021759c0->mCurrentEntries[m].mPlayer.mKind;
    if ((u32) v <= 3) {
        if ((1 << v) & 0xd) {
            f = TRUE;
        }
    }
    if (f != FALSE) {
        return;
    }
    if (k[0] > 2) {
        if (n > 2) {
            k[1] = n;
        }
    }
    if (k[0] == 1) {
        if (data_021759c0->mMode == MODE_GRAND_PRIX) {
            if (func_020853a4(m) >= 0x28f) {
                if (GetKartRank(m) >= 4) {
                    for (i = 1; i < 4; i++) {
                        d = func_02085408(i);
                        if (d >= 0) {
                            Unk020888b4 *u = GetKart(d)->mUnk_310;
                            Unk02089a24 *s = &u->mUnk_e8;

                            if (u->mUnk_154 != 0) {
                                if (s->mUnk_1c == 2) {
                                    k[0] = 2;
                                    k[1] = k[0];
                                    s->mUnk_20 = 1;
                                    s->mUnk_1c = s->mUnk_20;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    e = k[1];
    if (IsKartEnded(m) != 0) {
        t = data_usa_021658f4;
    } else {
        t = data_usa_0217ae34;
    }
    v = t[n - 1];
    k[2] = (s32) (((s64) v * r->mUnk_04) >> 12);
    if (func_02085390() != 0) {
        n = r->mUnk_04;
        d = func_02085434();
        if (d >= 0) {
            e = func_020853a4(b->mIndex);
            e -= func_020853a4((u16) d);
            if (IsKartEnded(b->mIndex) != 0) {
                t = data_usa_021658f4;
            } else {
                t = data_usa_0217ae34;
            }
            v = t[GetKartRank((s32) (u16) d)];
            if (e > (s32) (((s64) v * n) >> 12)) {
                a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0xf85) >> 12);
                a->mUnk_18 = 1;
            }
        }
    } else if (n < e) {
        a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0xe66) >> 12);
        a->mUnk_18 = 1;
    } else if (n == e) {
        if (n == 1) {
            d = func_020854a0((u16) n, data_usa_021658f0);
            if (d >= 0) {
                g = func_020853a4(m);
                g -= func_020853a4((u16) d);
                if (g > GetKart(d)->mUnk_310->mUnk_e8.mUnk_24) {
                    a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0xf85) >> 12);
                    a->mUnk_18 = 1;
                }
            }
        } else {
            g = func_020853a4(m);
            d = func_02085478();
            if (d >= 0) {
                e = func_020853a4((u16) d) - g;
                e -= (s32) (((s64) k[2] * func_0208548c()) >> 12);
                if (e > 0) {
                    a->mUnk_10 = a->mUnk_10 + (s32) (((s64) e * 0x3000) >> 12);
                } else {
                    d = func_02085458(n);
                    if (d >= 0) {
                        Kart *q = GetKart(d);
                        s32 w = r->mUnk_08;

                        if (q->mUnk_310->mUnk_e8.mUnk_04 > (s32) (((s64) w * 0xcd0) >> 12)) {
                            e = func_020853a4((u16) d) - g;
                            if (e < (s32) (((s64) k[2] * func_0208548c()) >> 12)) {
                                a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0xfae) >> 12);
                                a->mUnk_18 = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (a->mUnk_18 == 0) {
        a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0x10cd) >> 12);
        if (a->mUnk_10 >= c) {
            a->mUnk_10 = c;
        }
    } else {
        if (a->mUnk_10 < r->mUnk_08) {
            a->mUnk_10 = r->mUnk_08;
        }
    }
}

u16 func_0207d8e4(s32 a) {
    u16 v[9];
    u16 *p;
    s32 i;
    Unk0217aebc_128 *r;

    v[0] = data_usa_021658f8[0];
    v[1] = data_usa_021658f8[1];
    v[2] = data_usa_021658f8[2];
    v[3] = data_usa_02165908[0];
    v[4] = data_usa_02165908[1];
    v[5] = data_usa_02165908[2];
    v[6] = data_usa_02165900[0];
    v[7] = data_usa_02165900[1];
    v[8] = data_usa_02165900[2];
    p = &v[6];
    if (a != 0) {
        i = 2;
    } else {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        i = (u16) (((r->mUnk_00 >> 32) * 3) >> 32);
    }
    switch (data_021759c0->mUnk_014) {
        case 1:
            p = &v[0];
            break;
        case 2:
            p = &v[3];
            break;
    }
    return p[i];
}

void func_0207d814(struct Unk02089a24 *a, struct Unk020888b4 *b) {
    s32 t;

    a->mUnk_00 = b->mKart->mPhysicalParam->mBaseSpeedLimit;
    a->mUnk_04 = a->mUnk_00;
    a->mUnk_08 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = a->mUnk_00;
    a->mUnk_14 = -1;
    a->mUnk_18 = 0;
    a->mUnk_10 = 0;
    if (data_021759c0->mUnk_00c == 5) {
        b->mKart->mForwardSpeed = a->mUnk_00;
        return;
    }
    if (data_021759c0->mUnk_00c == 6) {
        t = func_0207fe70((Unk02080b1c *) &b->mUnk_08.mUnk_00);
        b->mKart->mForwardSpeed = (s32) (((s64) b->mKart->mPhysicalParam->mBaseSpeedLimit * t + 0x800) >> 12);
        b->mKart->mSpeedLimitGoal = b->mKart->mForwardSpeed;
        b->mKart->mSpeedLimit = b->mKart->mSpeedLimitGoal;
        return;
    }
    func_0207e088(a, b);
}
