#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020dda38.h"

#include "Main/Unknown/code_020dda2c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02039860.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020de204.h"

u32 func_020de20c(u32 p0, u32 p1, u32 p2, u32 p3) {
    return ((u32) * (const u8 *) ((u8 *) p3 + 0));
}

u32 func_020de204(u32 p0, u32 p1, u32 p2, u32 p3) {
    return ((u32) * (const u8 *) ((u8 *) p3 + 0));
}

const u16 data_021583d4 = 1;

void func_020de184(Unk020de000 *o) {
    Wanwan *p;
    Vec3 v;
    Vec3 w;

    p = o->mUnk_a0;
    Vec3AddScaled(-p->mUnk_f0, &p->mUnk_00.mMatrix.mUnk_00[2], &p->mUnk_00.mPos, &w);
    v = p->mUnk_a0;
    v.y -= p->mUnk_f0 >> 1;
    func_020dd8b0(&o->mUnk_a4, &v, &w);
    if (o->mUnk_f4 != FALSE) {
        return;
    }
    func_020dda2c(&o->mUnk_a4);
}

#pragma thumb on

void CreateWanwanChainAndWanwanKui(void) {
    void *v;

    func_020e6488(&gWanwanChain, FindCourseMapObjFile("wanwan_chain.nsbmd"), 0, 0);
    func_020e6ab8(gWanwanChain);
    v = FindCourseFile("MapObj/wanwan_kui.nsbmd");
    if (v != NULL) {
        func_020e6488(&gWanwanKui, v, 0, 0);
        func_020e6ab8(gWanwanKui);
    }
}

void func_020de000(Unk020de000 *o, void *a, Wanwan *p) {
    s32 d;

    o->mUnk_04 = p->mUnk_a0;
    o->mUnk_f4 = p->mUnk_fc == 0;
    if (o->mUnk_f4 != FALSE) {
        d = p->mUnk_1ec;
    } else {
        d = 0x55000;
    }
    func_020dd950(&o->mUnk_a4, &o->mUnk_04, &o->mUnk_04, d - p->mUnk_f0, p->mUnk_fc != 0 ? 4 : 7, 0x6000, &o->mUnk_1c);
    if (o->mUnk_f4 == FALSE) {
        func_020dda2c(&o->mUnk_a4);
        o->mUnk_a4.mUnk_04 -= 0xcd;
        o->mUnk_a4.mUnk_10 -= 0x3d;
        o->mUnk_a4.mUnk_14.x += 0x52;
        o->mUnk_a4.mUnk_14.y += 0x35c;
        o->mUnk_a4.mUnk_14.z += 0x52;
        o->mUnk_a4.mUnk_0c = 0;
        o->mUnk_02 |= data_021583d4;
    }
    o->mUnk_a0 = p;
    if (o->mUnk_f4 != FALSE) {
        d = p->mUnk_f8;
    } else {
        d = 0xc8000;
    }
    o->mUnk_68 = (s32) (1.2f * (float) (d + p->mUnk_f0));
}

#pragma thumb off

void func_020ddb44(Unk020dd950 *a, Vec3 *b, Vec3 *v) {
    Vec3 *p48;
    s32 n;
    s32 j;
    s32 m;
    s32 m0c;
    Vec3 *p44;
    s32 m04;
    s32 m10;
    Vec3 t;
    Vec3 u;
    Vec3 g;
    Vec3 *q;
    s32 i;
    s32 w;
    s32 c;
    s32 e;
    s64 d;

    p48 = a->mUnk_48;
    n = a->mUnk_20;
    m0c = a->mUnk_0c;
    p44 = a->mUnk_44;
    m04 = a->mUnk_04;
    m10 = a->mUnk_10;
    g = a->mUnk_14;
    j = n - 1;
    for (i = 1; i < n; i++) {
        p48[i].y -= m04;
    }
    for (i = 1; i < n; i++) {
        Vec3AddScaled((n - i) * -m10, &p48[i], &p48[i], &p48[i]);
    }
    for (i = 1; i < n; i++) {
        Vec3Add(&p44[i], &p48[i], &p44[i]);
    }
    q = &p44[j];
    *q = *b;
    for (; j > 1; j--) {
        Vec3Sub(&p44[j - 1], q, &t);
        d = (s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z - a->mUnk_2c;
        e = d < 0 ? 0 : (s32) (d >> 12);
        if (e != 0) {
            func_02039860(&t, &u);
            w = a->mUnk_28;
            u.x = (s32) (((s64) u.x * w) >> 12);
            u.y = (s32) (((s64) u.y * w) >> 12);
            u.z = (s32) (((s64) u.z * w) >> 12);
            Vec3Add(q, &u, &p44[j - 1]);
            Vec3Sub(&u, &t, &t);
            t.x = (s32) (((s64) t.x * g.x) >> 12);
            t.y = (s32) (((s64) t.y * g.y) >> 12);
            t.z = (s32) (((s64) t.z * g.z) >> 12);
            c = a->mUnk_24 * j;
            t.x = (s32) (((s64) t.x * c) >> 12);
            t.y = (s32) (((s64) t.y * c) >> 12);
            t.z = (s32) (((s64) t.z * c) >> 12);
            Vec3Add(&p48[j - 1], &t, &p48[j - 1]);
        }
        q--;
    }
    if (a->mUnk_08 != 0) {
        m = 1;
    } else {
        m = 2;
    }
    for (; m < n; m++) {
        Vec3Sub(&p44[m], &p44[m - 1], &t);
        d = (s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z - a->mUnk_2c;
        e = d < 0 ? 0 : (s32) (d >> 12);
        if (e != 0) {
            func_02039860(&t, &u);
            w = a->mUnk_28;
            u.x = (s32) (((s64) u.x * w) >> 12);
            u.y = (s32) (((s64) u.y * w) >> 12);
            u.z = (s32) (((s64) u.z * w) >> 12);
            Vec3Add(&p44[m - 1], &u, &p44[m]);
        }
    }
    for (i = 1; i < n - 2; i++) {
        if (p44[i].y - m0c < 0) {
            p44[i].y = m0c;
            if (p48[i].y < 0) {
                p48[i].y = 0;
            }
            p48[i].x = p48[i].x * 7 >> 3;
            p48[i].z = p48[i].z * 7 >> 3;
        }
    }
}

void func_020ddaa0(Unk020dd950 *a, Unk020e6488 *b, s32 c, u16 e) {
    s32 i;
    u32 v;

    func_020e6a18(b);
    for (i = 1; i < a->mUnk_20; i++) {
        v = func_020d3c44();
        b->mUnk_14 &= ~0x3f000000;
        b->mUnk_14 |= v << 24;
        func_020e67c4(b, func_020e6cf8(&a->mUnk_44[i]), &a->mUnk_34, 1, e);
    }
}

void func_020dda38(Unk020dd950 *a, Unk020e6488 *b, Vec3 *c, s32 d, u16 e) {
    u32 v;

    func_020e6a18(b);
    v = func_020d3c44();
    b->mUnk_14 &= ~0x3f000000;
    b->mUnk_14 |= v << 24;
    func_020e67c4(b, func_020e6cbc(c), &a->mUnk_34, 1, e);
}
