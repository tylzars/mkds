#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02081000.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_0201c528.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02067000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147288.h"
#include "Main/Unknown/code_02077bc0.h"

KartEffects *GetKartEffects(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gKartEffects;
    value1 = 0x58u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (KartEffects *) value0;
}

void InitKartEffects(u32 a) {
    KartEffects *e;
    u16 i;
    u16 j;

    i = 0;
    gKartEffects = HeapAlloc(GetHeap(func_020364e8()), a * 0x58);
    data_0217ae70 = a;
    for (; i < a; i++) {
        e = &gKartEffects[i];
        e->mCurrentEffect = NULL;
        e->mUnk_28 = NULL;
        e->mUnk_2c = NULL;
        e->mUnk_30 = NULL;
        e->mCurrentEffectId = -1;
        e->mUnk_20 = e->mUnk_24 = 0;
        for (j = 0; j < 2; j++) {
            e->mUnk_10[j].mUnk_00 = e->mUnk_10[j].mUnk_04 = 0;
            e->mUnk_04[j] = -1;
        }
    }
    data_0217ae80 = NULL;
}

void func_02084478(Kart *p) {
    u16 i;
    KartEffects *e;
    Vec3 q;
    Vec3 w;
    Vec3 v;

    e = &gKartEffects[p->mIndex];
    p->mUnk_174 = *p->mPosSource;
    for (i = 0; i < 2; i++) {
        v = p->mKartModelsEntry->mUnk_020->mUnk_14[i + 2];
        v.y = 0;
        v.x = v.x + data_02155800[i];
        q.x = (s32) (((s64) v.x * p->mScale.x) >> 12);
        q.y = (s32) (((s64) v.y * p->mScale.y) >> 12);
        q.z = (s32) (((s64) v.z * p->mScale.z) >> 12);
        Vec3MultiplyMatrix4x3(&q, &p->mUnk_150_m, &e->mUnk_34[i]);
        e->mUnk_34[i].x = e->mUnk_34[i].x >> 4;
        e->mUnk_34[i].y = e->mUnk_34[i].y >> 4;
        e->mUnk_34[i].z = e->mUnk_34[i].z >> 4;
        Vec3MultiplyMatrix3x3(&data_02155818[i], &p->mUnk_150.x, &w);
        e->mUnk_4c[i].x = w.x;
        e->mUnk_4c[i].y = w.y;
        e->mUnk_4c[i].z = w.z;
    }
}

void func_0208442c(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    func_02083928(p, 0);
}

void func_020843d8(Kart *p) {
    data_02155908[0].mUnk_18(&data_02155908[0].mUnk_00[data_0217ae8c[p->mIndex]], data_02155908[0].mUnk_1c, p);
    func_02083928(p, 0);
}

void func_02084384(Kart *p) {
    data_02155928.mUnk_18(&data_02155928.mUnk_00[data_0217ae8c[p->mIndex]], data_02155928.mUnk_1c, p);
    func_02083928(p, 0);
}

void func_02084334(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    func_02083de8(2, p);
}

void func_020842ac(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    data_02155968.mUnk_18(&data_02155968.mUnk_00[data_0217ae8c[p->mIndex]], data_02155968.mUnk_1c, p);
}

void func_02084224(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    data_02155988.mUnk_18(&data_02155988.mUnk_00[data_0217ae8c[p->mIndex]], data_02155988.mUnk_1c, p);
}

void func_0208419c(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    data_021559a8.mUnk_18(&data_021559a8.mUnk_00[data_0217ae8c[p->mIndex]], data_021559a8.mUnk_1c, p);
}

void func_02084114(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    data_021559c8.mUnk_18(&data_021559c8.mUnk_00[data_0217ae8c[p->mIndex]], data_021559c8.mUnk_1c, p);
}

void func_020840c0(Kart *p) {
    data_021559e8.mUnk_18(&data_021559e8.mUnk_00[data_0217ae8c[p->mIndex]], data_021559e8.mUnk_1c, p);
    func_02083928(p, 0);
}

void func_02084034(u32 a, Kart *p) {
    Unk0201ca6c *o;

    if (func_02061818() != 0) {
        return;
    }
    GetChaseCamera();
    if (data_0217ae80 != NULL) {
        data_0217ae80->mUnk_24.mUnk_00_0 = 1;
    }
    o = StartEffect(data_021557f8[a], &data_02155a14);
    o->mUnk_98 = 0;
    o->mUnk_94 = p;
    o->mUnk_90 = func_02083680;
    data_0217ae80 = o;
}

void func_02083f6c(s32 a, Kart *p) {
    KartEffects *e;

    if (p->mUnk_4c & 0x8000) {
        data_02155830[a](p);
        return;
    }
    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    func_02083928(p, 0);
    e = &gKartEffects[p->mIndex];
    if (e->mUnk_20 != 0) {
        e->mUnk_20->mUnk_98_8 = 1;
        e->mUnk_20 = 0;
    }
    if (e->mUnk_24 != 0) {
        e->mUnk_24->mUnk_98_8 = 1;
        e->mUnk_24 = 0;
    }
}

void func_02083ec4(Kart *p) {
    KartEffects *e;

    if (p->mUnk_4c & 0x8000) {
        func_02083a24(&data_02155968.mUnk_00[data_0217ae8c[p->mIndex]], 1, p);
        return;
    }
    e = &gKartEffects[p->mIndex];
    if (e->mUnk_20 != 0) {
        e->mUnk_20->mUnk_98_8 = 1;
        e->mUnk_20 = 0;
    }
    if (e->mUnk_24 != 0) {
        e->mUnk_24->mUnk_98_8 = 1;
        e->mUnk_24 = 0;
    }
}

void func_02083de8(s32 a, Kart *p) {
    Unk02155908 *t;
    Unk02155908_00 *n;
    KartEffects *e;
    u16 i;
    u16 j;

    t = &data_02155908[a];
    n = &t->mUnk_00[data_0217ae8c[p->mIndex]];
    if (t->mUnk_18(n, t->mUnk_1c, p) == 0) {
        return;
    }
    e = &gKartEffects[p->mIndex];
    for (i = 0; i < n->mUnk_00; i++) {
        for (j = 0; j < 2; j++) {
            if (e->mUnk_10[i].mUnk_00_a[j] != 0) {
                e->mUnk_10[i].mUnk_00_a[j]->mUnk_72 = data_0217ae6c;
            }
        }
    }
}

BOOL func_02083d4c(Unk02155908_00 *a, s32 b, Kart *p) {
    KartEffects *e;
    Unk0201ca6c *o;

    e = &gKartEffects[p->mIndex];
    if (a->mUnk_04[0] == e->mCurrentEffectId) {
        return FALSE;
    }
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
    }
    o = StartEffect(a->mUnk_04[0], &data_02155a14);
    e->mCurrentEffect = o;
    e->mCurrentEffectId = a->mUnk_04[0];
    o->mUnk_94 = p;
    o->mUnk_98_0 = b;
    o->mUnk_90 = func_02083484;
    return TRUE;
}

s32 func_02083c18(Unk02155908_00 *a, s32 b, Kart *p) {
    KartEffects *e;
    Unk0201ca6c *o;
    s32 r;
    u16 i;
    u16 j;

    r = i = 0;
    for (; i < a->mUnk_00; i++) {
        e = &gKartEffects[p->mIndex];
        j = 0;
        if (a->mUnk_04[i] != e->mUnk_04[i]) {
            if (e->mUnk_10[i].mUnk_00 != 0) {
                e->mUnk_10[i].mUnk_00->mUnk_98_8 = 1;
            }
            if (e->mUnk_10[i].mUnk_04 != 0) {
                e->mUnk_10[i].mUnk_04->mUnk_98_8 = 1;
            }
            e->mUnk_04[i] = a->mUnk_04[i];
            do {
                o = StartEffect(e->mUnk_04[i], &data_02155a14);
                gKartEffects[p->mIndex].mUnk_10[i].mUnk_00_a[j] = o;
                o->mUnk_94 = p;
                o->mUnk_98_24 = j;
                j++;
                o->mUnk_90 = func_0208335c;
            } while (j < 2);
            r = 1;
        }
    }
    return r;
}

s32 func_02083ae0(Unk02155908_00 *a, s32 b, Kart *p) {
    KartEffects *e;
    Unk0201ca6c *o;
    s32 r;
    u16 i;
    u16 j;

    r = i = 0;
    for (; i < a->mUnk_00; i++) {
        e = &gKartEffects[p->mIndex];
        j = 0;
        if (a->mUnk_04[i] != e->mUnk_04[i]) {
            if (e->mUnk_10[i].mUnk_00 != 0) {
                e->mUnk_10[i].mUnk_00->mUnk_98_8 = 1;
            }
            if (e->mUnk_10[i].mUnk_04 != 0) {
                e->mUnk_10[i].mUnk_04->mUnk_98_8 = 1;
            }
            e->mUnk_04[i] = a->mUnk_04[i];
            do {
                o = StartEffect(e->mUnk_04[i], &data_02155a14);
                gKartEffects[p->mIndex].mUnk_10[i].mUnk_00_a[j] = o;
                o->mUnk_94 = p;
                o->mUnk_98_24 = j;
                j++;
                o->mUnk_98_0 = b;
                o->mUnk_90 = func_020831bc;
            } while (j < 2);
            r = 1;
        }
    }
    return r;
}

BOOL func_02083a24(Unk02155908_00 *a, s32 b, Kart *p) {
    KartEffects *e;
    Unk0201ca6c *o;
    u16 i;

    e = &gKartEffects[p->mIndex];
    if (e->mUnk_20 != 0 || e->mUnk_24 != 0) {
        return FALSE;
    }
    for (i = 0; i < 2; i++) {
        o = StartEffect(a->mUnk_04[0], &data_02155a14);
        gKartEffects[p->mIndex].mUnk_20_a[i] = o;
        o->mUnk_94 = p;
        o->mUnk_98_24 = i;
        o->mUnk_98_0 = (u8) b;
        o->mUnk_90 = func_02082fec;
    }
    return TRUE;
}

void func_020839d8(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    func_02083928(p, 0);
}

void func_02083928(Kart *p, s32 a) {
    u16 i;
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    for (i = 0; i < 2; i++) {
        if (e->mUnk_10[i].mUnk_00 != 0 || e->mUnk_10[i].mUnk_04 != 0) {
            if (a == 0) {
                e->mUnk_10[i].mUnk_00->mUnk_98_8 = 1;
                e->mUnk_10[i].mUnk_04->mUnk_98_8 = 1;
            } else {
                func_0208b710(e->mUnk_10[i].mUnk_00);
                func_0208b710(e->mUnk_10[i].mUnk_04);
            }
            e->mUnk_10[i].mUnk_00 = e->mUnk_10[i].mUnk_04 = 0;
            e->mUnk_04[i] = -1;
        }
    }
}

void func_020838dc(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mUnk_20 != 0) {
        e->mUnk_20->mUnk_98_8 = 1;
        e->mUnk_20 = 0;
    }
    if (e->mUnk_24 != 0) {
        e->mUnk_24->mUnk_98_8 = 1;
        e->mUnk_24 = 0;
    }
}

void func_02083834(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        func_0208b710(e->mCurrentEffect);
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    func_02083928(p, 1);
    e = &gKartEffects[p->mIndex];
    if (e->mUnk_20 != 0) {
        func_0208b710(e->mUnk_20);
        e->mUnk_20 = 0;
    }
    if (e->mUnk_24 == 0) {
        return;
    }
    func_0208b710(e->mUnk_24);
    e->mUnk_24 = 0;
}

void func_02083680(Unk0201ca6c *p, s32 a) {
    Vec3s16 h;
    Vec3 v;
    Vec3 w;
    Vec3 u;
    Unk020748a8 *g;
    Kart *q;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    q = p->mUnk_94;
    if (func_02061818() != 0 || (p->mUnk_24.mUnk_00_1 != 0 && (p->mUnk_98 = p->mUnk_98 + 1, p->mUnk_98 > 5))) {
        p->mUnk_24.mUnk_00_0 = 1;
        data_0217ae80 = NULL;
        return;
    }
    if (!(q->mUnk_48 & 0x20)) {
        p->mUnk_24.mUnk_00_1 = 1;
    }
    v = g->mViewPos;
    w.x = (s32) (((s64) g->mForward.x * 0x5000) >> 12);
    w.y = (s32) (((s64) g->mForward.y * 0x5000) >> 12);
    w.z = (s32) (((s64) g->mForward.z * 0x5000) >> 12);
    Vec3Add(&w, &v, &u);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    h.x = -g->mForward.x;
    h.y = -g->mForward.y;
    h.z = -g->mForward.z;
    p->mUnk_50 = h;
}

void func_02083484(Unk0201ca6c *p, s32 a) {
    Vec3 x;
    Vec3 v;
    Vec3 w;
    Kart *q;
    Vec3 *s;
    u32 n;
    s32 k;
    u32 m;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    v = q->mEffectVelocity;
    k = data_0216596c[p->mUnk_98_b.mUnk_00];
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    f = 1;
    if (func_020675b4(q) == 0) {
        if (q->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    s = &q->mUnk_138;
    w.x = (s32) (((s64) s->x * -0x5000) >> 12);
    w.y = (s32) (((s64) s->y * -0x5000) >> 12);
    w.z = (s32) (((s64) s->z * -0x5000) >> 12);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    Vec3Add(q->mPosSource, &w, &x);
    x.x = x.x >> 4;
    x.y = x.y >> 4;
    x.z = x.z >> 4;
    v.x = (s32) (((s64) v.x * k) >> 12);
    v.y = (s32) (((s64) v.y * k) >> 12);
    v.z = (s32) (((s64) v.z * k) >> 12);
    p->mUnk_28.x = x.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = x.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = x.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_40 = v;
}

void func_0208335c(Unk0201ca6c *p, s32 a) {
    s32 x;
    Kart *q;
    u32 n;
    KartEffects *e;
    u32 m;
    u32 r;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &gKartEffects[q->mIndex];
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    f = 1;
    if (func_020675b4(q) == 0) {
        if (q->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mUnk_4c[r];
    x = e->mUnk_34[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mUnk_34[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mUnk_34[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_020831bc(Unk0201ca6c *p, s32 a) {
    s32 x;
    Vec3 v;
    Kart *q;
    u32 n;
    KartEffects *e;
    u32 m;
    u32 r;
    s32 k;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &gKartEffects[q->mIndex];
    v = q->mEffectVelocity;
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    k = data_0216596c[p->mUnk_98_b.mUnk_00];
    f = 1;
    if (func_020675b4(q) == 0) {
        if (q->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mUnk_4c[r];
    x = e->mUnk_34[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mUnk_34[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mUnk_34[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
    v.x = (s32) (((s64) v.x * k) >> 12);
    v.y = (s32) (((s64) v.y * k) >> 12);
    v.z = (s32) (((s64) v.z * k) >> 12);
    p->mUnk_40 = v;
}

void func_02082fec(Unk0201ca6c *p, s32 a) {
    s32 x;
    Vec3 v;
    u32 m;
    Kart *q;
    u32 n;
    KartEffects *e;
    u32 f;
    u32 r;
    s32 k;
    u32 g;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &gKartEffects[q->mIndex];
    v = q->mEffectVelocity;
    g = 1;
    f = 1;
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    k = data_0216596c[p->mUnk_98_b.mUnk_00];
    if (func_020675b4(q) == 0) {
        if (q->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    if (f == 0) {
        if (q->mUnk_500 <= 0x5000) {
            g = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (g != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mUnk_4c[r];
    x = e->mUnk_34[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mUnk_34[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mUnk_34[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_28.y = p->mUnk_28.y + (q->mUnk_500 >> 4);
    v.x = (s32) (((s64) v.x * k) >> 12);
    v.y = (s32) (((s64) v.y * k) >> 12);
    v.z = (s32) (((s64) v.z * k) >> 12);
    p->mUnk_40 = v;
}

void func_02082f94(Unk0201ca6c *p, s32 a) {
    if (a != 0) {
        return;
    }
    func_02082d64(p, a);
    p->mUnk_98_24 = p->mUnk_98_24 + 1;
    if (p->mUnk_98_24 >= 2) {
        p->mUnk_98_16 = (p->mUnk_98_16 == 0);
        p->mUnk_98_24 = 0;
    }
}

void func_02082e4c(s32 a) {
    Unk02155808 *e;
    s32 j;
    Unk02155888_00 *d;
    s32 k;
    u32 f;
    s32 n;
    s32 i;
    s32 m;
    Unk0201ca6c *o;

    data_0217aea0 = data_02155888[a];
    n = data_0217ae98;
    i = n;
    if (i < 4) {
        m = data_0217ae90;
        do {
            if (i != n || m == 0) {
                data_0217aea0.mUnk_00[i].mUnk_00 = -1;
            }
            data_0217aea0.mUnk_00[i].mUnk_02 = -1;
            i++;
        } while (i < 4);
    }
    e = data_02155808;
    for (j = 0; j < 2; j++) {
        f = (j != 0) ? 1 : 0;
        k = 0;
        d = data_0217aea0.mUnk_00;
        do {
            if (d->mUnk_00 < 0) {
                break;
            }
            o = func_0208b60c(e->mUnk_00, &data_02155a14);
            k++;
            o->mUnk_90 = e->mUnk_04;
            o->mUnk_98_0 = d->mUnk_00;
            o->mUnk_98_8 = (d->mUnk_02 < 0) ? 0xff : (u8) d->mUnk_02;
            d++;
            o->mUnk_98_16 = f;
            o->mUnk_98_24 = 0;
            o->mUnk_94_u = 0;
        } while (k < 4);
        e++;
    }
}

void func_02082d64(Unk0201ca6c *p, s32 a) {
    Unk0201ca6c_98 *s;
    Kart *q;
    u32 n;
    u32 f;
    u32 x;
    s32 y;
    s32 v1;
    s32 v2;
    s32 v3;

    s = &p->mUnk_98_b;
    y = s->mUnk_02;
    n = p->mUnk_94_u;
    y = (y == 0) ? s->mUnk_00 : s->mUnk_01;
    x = s->mUnk_01;
    f = 1;
    if (x > 8) {
        if (y > 8) {
            f = 0;
        }
        y = s->mUnk_00;
    }
    q = GetKart(y);
    v1 = q->mUnk_1d8.x;
    v2 = q->mUnk_1d8.y;
    v3 = q->mUnk_1d8.z;
    p->mUnk_28.x = (v1 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (v2 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (v3 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    if (q->mUnk_7c & 0x402000) {
        f = 0;
    }
    p->mUnk_24.mUnk_00_3 = (f == 0);
    if (n + 1 >= 0x32) {
        p->mUnk_24.mUnk_00_0 = 1;
    }
    p->mUnk_94_u = n + 1;
}

void func_02082aec(void) {
    s32 x;
    s32 m;

    m = data_021759c0->mUnk_010;
    x = 0x1000;
    switch (m) {
        case 1:
            x = 0xd9a;
            break;
        case 0:
            x = 0xb33;
            break;
    }
    data_0217ae9c = DivFixed12(0x1000, (s32) (((s64) x * 0x779a + 0x800) >> 12));
    data_0217ae88 = NULL;
    data_0217ae78 = NULL;
    switch (data_021759c0->mCourseId) {
        case 0x25: {
            Unk0201ca6c *p;

            if (data_021759c0->mUnk_00c == 0) {
                p = StartEffect(0x24, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_02082750;
                p = StartEffect(0x27, &data_02155a14);
                data_0217ae88 = p;
                p->mUnk_90 = func_02082a10;
            } else if (GetRaceUseChainCameras() != 0) {
                p = StartEffect(0x3d, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_020824d0;
                p = StartEffect(0x3f, &data_02155a14);
                data_0217ae88 = p;
                p->mUnk_90 = func_0208266c;
            } else {
                p = StartEffect(0x3c, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_020824d0;
                p = StartEffect(0x3f, &data_02155a14);
                data_0217ae88 = p;
                p->mUnk_90 = func_0208266c;
            }
            break;
        }
        case 0x10: {
            Unk0201ca6c *p;

            if (GetRaceUseChainCameras() != 0) {
                p = StartEffect(0x3e, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_02082034;
            } else if (data_021759c0->mUnk_00c == 0) {
                p = StartEffect(0x29, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_020821cc;
                p = StartEffect(0x25, &data_02155a14);
                data_0217ae88 = p;
                p->mUnk_90 = func_02082368;
            } else {
                p = StartEffect(0x29, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_02082034;
            }
            break;
        }
    }
}

void func_02082a10(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    v = g->mForward;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    Vec3AddScaled(0x5800, &v, &g->mViewPos, &u);
    u.y = 0x1f400;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_02082750(Unk0201ca6c *p, s32 a) {
    Vec3s16 h;
    Vec3 v;
    Vec3 x;
    Vec3 u;
    Matrix3x3 m;
    Vec3 y;
    Unk020748a8 *g;
    Kart *q;
    s32 t;
    s32 k;
    s32 s;
    u16 i;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    q = GetKart(data_021759c0->mEntryIndex);
    v = g->mForward;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    Vec3Cross(&data_02155a08, &v, &x);
    t = (s32) (((s64) q->mVelocityLength * data_0217ae9c + 0x800) >> 12);
    y = data_02165984;
    k = 0;
    if (t > 0x1000) {
        t = 0x1000;
    }
    if (q->mUnk_44 & 0x100) {
        t = t * 0xffffffff;
        k = data_02165938;
    }
    i = (s32) (((s64) t * 0x38e3 + 0x800) >> 12);
    Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) &m, &x, gPairsByAngle[(i >> 4) * 2],
                                           gPairsByAngle[(i >> 4) * 2 + 1]);
    Vec3MultiplyMatrix3x3(&y, m.mUnk_00, &y);
    h.x = y.x;
    h.y = y.y;
    h.z = y.z;
    p->mUnk_68 = (s16) ((s32) (((s64) (0x1000 - t) * 0x800 + 0x800) >> 12) + 0x800);
    p->mUnk_50 = h;
    s = data_02165954 + k;
    Vec3AddScaled(data_02165938 + (s32) (((s64) s * (s64) t + 0x800) >> 12), &v, &g->mViewPos, &u);
    u.y = GetKart(data_021759c0->mEntryIndex)->mPosSource->y >> 4;
    u.y = u.y - (s32) (((s64) data_02165934 * t + 0x800) >> 12);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_0208266c(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Camera *g;

    if (a != 0) {
        return;
    }
    g = GetCurrentCamera();
    v = g->mForward;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    Vec3AddScaled(data_02165958, &v, &g->mViewPos, &u);
    u.y = 0x1f400;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_020824d0(Unk0201ca6c *p, s32 a) {
    Vec3s16 h;
    Vec3 v;
    Vec3 x;
    Vec3 u;
    Vec3 w;
    Camera *g;

    if (a != 0) {
        return;
    }
    g = GetCurrentCamera();
    GetKart(data_021759c0->mEntryIndex);
    v = g->mForward;
    w = data_02155a08;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    Vec3Cross(&data_02155a08, &v, &x);
    w.y = w.y * 0xffffffff;
    h.x = w.x;
    h.y = w.y;
    h.z = w.z;
    p->mUnk_68 = 0x1000;
    p->mUnk_50 = h;
    Vec3AddScaled(data_02165964, &v, &g->mViewPos, &u);
    u.y = u.y + (data_02165968 + (s32) (((s64) g->mForward.y * data_02165960 + 0x800) >> 12));
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_02082368(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;
    Kart *q;
    s32 t;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    q = GetKart(data_021759c0->mEntryIndex);
    v = g->mForward;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    Vec3AddScaled(0x5800, &v, &g->mViewPos, &u);
    u.y = GetKart(data_021759c0->mEntryIndex)->mPosSource->y >> 4;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    t = (s32) (((s64) q->mVelocityLength * data_0217ae9c + 0x800) >> 12);
    if (t > 0x1000) {
        t = 0x1000;
    }
    p->mUnk_58 = (s32) (((s64) (0x1000 - t) * 0x400 + 0x800) >> 12);
}

void func_020821cc(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;
    s32 k;
    Kart *q;
    s32 t;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    q = GetKart(data_021759c0->mEntryIndex);
    v = g->mForward;
    t = (s32) (((s64) q->mVelocityLength * data_0217ae9c + 0x800) >> 12);
    k = 0;
    v.y = 0;
    if (t > 0x1000) {
        t = 0x1000;
    }
    if (q->mUnk_44 & 0x100) {
        k = -0x5800;
    }
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    k = k * 3;
    Vec3AddScaled((s32) (((s64) k * (s64) t + 0x800) >> 12) + 0x5800, &v, &g->mViewPos, &u);
    u.y = GetKart(data_021759c0->mEntryIndex)->mPosSource->y >> 4;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_58 = (s32) (((s64) 0x800 * t + 0x800) >> 12);
}

void func_02082034(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Camera *g;

    if (a != 0) {
        return;
    }
    g = GetCurrentCamera();
    v = g->mForward;
    w = data_02155a14;
    if (func_0203c5e4() != 0) {
        AngleFromPair(g->mHalfFovPairFirst, g->mHalfFovPairSecond);
        Vec3Sub(&g->mPos, &g->mPrevPos, &w);
        w.x = w.x >> 4;
        w.y = w.y >> 4;
        w.z = w.z >> 4;
    }
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    Vec3AddScaled(data_02165958, &v, &g->mViewPos, &u);
    u.y = u.y + (data_0216595c + (s32) (((s64) g->mForward.y * data_02165940 + 0x800) >> 12));
    Vec3Add(&u, &w, &u);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_58 = 0x800;
}

void func_02081f30(void) {
    Unk0201ca6c *p;

    switch (data_021759c0->mCourseId) {
        case COURSE_ID_OLD_LUIGI_AGB:
            if (data_0217ae78 != NULL) {
                func_0208b710(data_0217ae78);
                p = StartEffect(0x3c, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_020824d0;
            }
            if (data_0217ae88 == NULL) {
                return;
            }
            func_0208b710(data_0217ae88);
            p = StartEffect(0x3f, &data_02155a14);
            data_0217ae88 = p;
            p->mUnk_90 = func_0208266c;
            break;
        case COURSE_ID_OLD_FRAPPE_64:
            if (data_0217ae78 != NULL) {
                data_0217ae78->mUnk_90 = func_02082034;
            }
            if (data_0217ae88 == NULL) {
                return;
            }
            func_0208b710(data_0217ae88);
            data_0217ae88 = NULL;
            break;
    }
}

void func_02081f10(Unk02081e3c *p0, u32 p1, u32 p2) {
    p0->mUnk_9a = (u8) 0x0u;
    p0->mUnk_99 = (u8) p2;
    p0->mUnk_9b = (u8) p1;
    p0->mUnk_90 = (u32) (((u32) (&func_02081e5c)));
}

void func_02081e5c(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;
    Vec3 *v;
    Kart *q;
    s32 x;
    s32 y;
    s32 z;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    q = GetKart(i);
    v = q->mPosSource;
    x = v->x;
    y = v->y;
    z = v->z;
    p->mUnk_28.x = (x >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (y >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (z >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
}

void func_02081e3c(Unk02081e3c *p0, u32 p1, u32 p2) {
    p0->mUnk_9a = (u8) 0x0u;
    p0->mUnk_99 = (u8) p2;
    p0->mUnk_9b = (u8) p1;
    p0->mUnk_90 = (u32) (((u32) (&func_02081d78)));
}

void func_02081d78(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;
    Vec3 *v;
    Kart *q;
    s32 x;
    s32 y;
    s32 z;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    q = GetKart(i);
    v = q->mPosSource;
    x = v->x;
    y = v->y;
    z = v->z;
    p->mUnk_28.x = (x >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (y >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (z >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_40 = q->mEffectVelocity;
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
}

void func_02081ca0(Unk0201ca6c *p, Kart *q, void *a) {
    u32 r;
    u32 f;

    if (a == NULL) {
        func_02081b64(p, q, 0x733, 0xb33);
        p->mUnk_5c = (s16) (((s64) q->mScale.z * 0xb33 + 0x800) >> 12);
    } else {
        r = 1;
        func_02081b64(p, q, 0x99a, 0xe66);
        p->mUnk_6c = (s16) q->mScale.z;
        f = q->mUnk_7c;
        if (!(f & 1)) {
            if (f & 0x402000) {
                r = 0;
            }
        }
        p->mUnk_24.mUnk_00_3 = (r == 0);
    }
}

void func_02081b64(Unk0201ca6c *p, Kart *q, s32 a, s32 b) {
    Vec3 v;
    Vec3 w;
    Vec3s16 h;
    Vec3 *s = q->mPosSource;

    v.x = s->x >> 4;
    v.y = s->y >> 4;
    v.z = s->z >> 4;
    Vec3AddScaled((s32) (((s64) q->mScale.z * b + 0x800) >> 12), &q->mUnk_138, &v, &v);
    Vec3AddScaled((s32) (((s64) q->mScale.y * a + 0x800) >> 12), &q->mUnk_12c, &v, &v);
    p->mUnk_28.x = v.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = v.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = v.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    GetKartForward(q, &w);
    w.x = -w.x;
    w.y = -w.y;
    w.z = -w.z;
    h.x = w.x;
    h.y = w.y;
    h.z = w.z;
    p->mUnk_50 = h;
}

void func_02081b30(Unk0201ca6c *p, s32 a) {
    if (a != 0) {
        return;
    }
    func_02081ca0(p, GetKart(p->mUnk_98_24), p->mUnk_94);
}

void func_02081ab8(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    func_02081ca0(p, GetKart(i), p->mUnk_94);
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
}

void func_02081a40(s32 a) {
    Unk0217ae7c *e = &data_0217ae7c[a];
    u16 i;

    i = 0;
    do {
        if (e->mUnk_00[i] != NULL) {
            func_0208b710(e->mUnk_00[i]);
        }
        e->mUnk_00[i] = StartEffect(data_02165978[i], &GetKart(a)->mUnk_1d8);
        i = i + 1;
    } while (i < 3);
}

static inline s32 func_0208181c_inline(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

void func_0208181c(s32 a) {
    Unk0217ae7c *e = &data_0217ae7c[a];
    u16 i;
    s16 y;
    s16 x;
    Kart *q;
    Vec3 w;
    Vec3 v;

    q = GetKart(a);
    y = (s16) func_0208181c_inline(
        data_0216593c + func_0208181c_inline(q->mVelocityLengthRatio, data_02165950 - data_0216593c), data_02165948);
    x = (s16) func_0208181c_inline(
        data_02165944 + func_0208181c_inline(q->mVelocityLengthRatio, data_0216594c - data_02165944), data_02165948);
    i = 0;
    do {
        if (e->mUnk_00[i] != NULL) {
            Vec3AddScaled((s32) (((s64) q->mScale.y * data_02155854[q->mKartModelsEntry->mUnk_000] + 0x800) >> 12),
                          &q->mUnk_12c, &q->mPos, &v);
            func_0208b5b0(e->mUnk_00[i], &v);
            w.x = (s32) (((s64) q->mEffectVelocity.x * 0xc00) >> 12);
            w.y = (s32) (((s64) q->mEffectVelocity.y * 0xc00) >> 12);
            w.z = (s32) (((s64) q->mEffectVelocity.z * 0xc00) >> 12);
            e->mUnk_00[i]->mUnk_40 = w;
            e->mUnk_00[i]->mUnk_68 = y;
            e->mUnk_00[i]->mUnk_64 = x;
            e->mUnk_00[i]->mUnk_5c = (s16) (((s64) q->mScale.z * 0x614 + 0x800) >> 12);
        }
        i = i + 1;
    } while (i < 3);
}

void func_020817b8(s32 a) {
    Unk0217ae7c *e = &data_0217ae7c[a];
    u16 i;

    i = 0;
    do {
        if (e->mUnk_00[i] != NULL) {
            e->mUnk_00[i]->mUnk_24.mUnk_00_0 = 1;
            e->mUnk_00[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void func_02081768(s32 a) {
    Unk0217ae7c *e = &data_0217ae7c[a];
    u16 i;

    i = 0;
    do {
        if (e->mUnk_00[i] != NULL) {
            func_0208b710(e->mUnk_00[i]);
            e->mUnk_00[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void func_02081724(s32 a) {
    KartEffects *e = &gKartEffects[a];

    if (e->mUnk_2c != NULL) {
        func_0208b710(e->mUnk_2c);
    }
    e->mUnk_2c = StartEffect(0x63, &data_02155a14);
}

void func_02081618(s32 a, Vec3 *b) {
    KartEffects *e = &gKartEffects[a];
    Unk0201ca6c *p = e->mUnk_2c;
    Kart *q;
    Vec3 *s;
    Vec3 v;

    if (p == NULL) {
        return;
    }
    p->mUnk_28.x = b->x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = b->y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = b->z + p->mUnk_20->mUnk_00->mUnk_04.z;
    q = GetKart(a);
    s = &q->mEffectVelocity;
    v.x = (s32) (((s64) s->x * 0xe66) >> 12);
    v.y = (s32) (((s64) s->y * 0xe66) >> 12);
    v.z = (s32) (((s64) s->z * 0xe66) >> 12);
    e->mUnk_2c->mUnk_40 = v;
}
