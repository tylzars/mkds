#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02084000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020a02c8.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8b88.h"

Unk020d98a4 *gWaterEfct;
Unk020d9cf4 *gWater;
Unk020da384 *data_0217b67c;

#pragma thumb on

void func_020da494(Unk020da494 *a, Unk020fa294 *b) {
    Unk02042044 *e;
    Vec3 *q;
    Unk020e005c_080 *o;
    a->mUnk_100 = 0x1f;
    if (b != 0) {
        func_020d7da8(&a->mUnk_cc, b, (b->mUnk_28 << 11) / 100);
        e = func_02042044(b->mUnk_26, b->mUnk_2e);
        a->mUnk_a0 = e->mUnk_00.y;
        a->mUnk_f8 = b->mUnk_28 * 0xb4 / 100;
        a->mUnk_fc = b->mUnk_2a == 0;
        func_02046be8(&a->mUnk_00.mUnk_80, data_0216be68, 6, a);
        func_020d90a8(&a->mUnk_cc, a->mUnk_00.mUnk_9c->mUnk_2e, 1);
        func_020d8b88(&a->mUnk_cc, &a->mUnk_00.mUnk_04);
        a->mUnk_00.mUnk_04.y = a->mUnk_a0;
        q = &a->mUnk_00.mUnk_10;
        q->x = 0;
        q->y = 0;
        q->z = 0;
        {
            Unk020d7b88 x = {0, 0, 0, 0x1000};
            a->mUnk_a4 = x;
        }
        {
            Unk020d7b88 y = {0, 0, 0, 0x1000};
            a->mUnk_b4 = y;
        }
        a->mUnk_f0 = 0;
        a->mUnk_f4 = 0;
        o = &a->mUnk_00.mUnk_80;
        o->mUnk_10 = 0;
        o->mUnk_12 = 1;
    } else {
        a->mUnk_cc.mUnk_08 = 0xffff;
        a->mUnk_a0 = 0;
        a->mUnk_fc = 0;
        func_02046be8(&a->mUnk_00.mUnk_80, data_0216be68, 6, a);
        a->mUnk_f8 = 0x1000;
        {
            Unk020d7b88 x = {0, 0, 0, 0x1000};
            a->mUnk_a4 = x;
        }
        {
            Unk020d7b88 y = {0, 0, 0, 0x1000};
            a->mUnk_b4 = y;
        }
        func_02046bcc(&a->mUnk_00.mUnk_80, 1);
        a->mUnk_00.mUnk_10.x = 0;
        a->mUnk_00.mUnk_10.y = 0;
        a->mUnk_00.mUnk_10.z = 0;
    }
}

#pragma thumb off

Unk020da414 *func_020da414(void) {
    Unk020da414 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    {
        Unk020da414 v = {0};
        *p = v;
    }
    return p;
}

void func_020da384(Unk020da384 *a, void *b, UnkFunc *c) {
    data_0217b67c = a;
    a->mUnk_02 &= ~2;
    a->mUnk_02 &= ~8;
    a->mUnk_66 = 0x1f;
    c();
    gWater->mUnk_174 = FindCourseFile("MapObj/water_efct.nsbmd");
    gWater->mUnk_178 = FindCourseFile("MapObj/water_efct.nsbca");
    gWater->mUnk_17c = FindCourseFile("MapObj/water_efct.nsbma");
}

void func_020d9f8c(Unk020d9cf4 *a) {
    s32 v;
    Unk0212c400 **h;
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    u16 w;
    s32 j;
    s32 k;
    h = func_02108e6c(10);
    if (a->mUnk_170 != 0) {
        if (data_021759c0->mUnk_00 != 0x1f) {
            v = 0x7f000;
        } else {
            v = func_020a02c8();
        }
        if (v >= 0) {
            func_02105b28(h, v);
        }
    }
    switch (a->mUnk_24) {
        case 0:
            a->mUnk_30 = data_0215d4b4[(a->mUnk_2c >> 4) * 2];
            a->mUnk_04 = a->mUnk_1c + (s32) (((s64) a->mUnk_28 * a->mUnk_30) >> 12);
            a->mUnk_10 = a->mUnk_04;
            a->mUnk_2c = a->mUnk_2c + a->mUnk_2e;
            a->mUnk_3a = a->mUnk_3a + a->mUnk_2e;
            if (a->mUnk_2c > 0x3fff && a->mUnk_2c < 0x7fff) {
                a->mUnk_24 = 1;
                a->mUnk_38 = 0;
                a->mUnk_3e = a->mUnk_2e;
            }
            break;
        case 1:
            a->mUnk_38 = a->mUnk_38 + 1;
            if (a->mUnk_38 > a->mUnk_34) {
                a->mUnk_24 = 2;
                if (a->mUnk_170 != 0 && v >= 0) {
                    s1.mUnk_00 = 0x114;
                    s1.mUnk_04 = 0;
                    s1.mUnk_08 = 4;
                    s1.mUnk_0c = func_020d4ef4(0);
                    func_0210b760(&s1, h);
                }
            } else if (a->mUnk_38 > (a->mUnk_34 >> 1)) {
                a->mUnk_3e = a->mUnk_3e + 1;
                a->mUnk_3a = a->mUnk_3a + a->mUnk_3e;
            } else {
                a->mUnk_3e = a->mUnk_3e - 1;
                a->mUnk_3a = a->mUnk_3a + a->mUnk_3e;
            }
            break;
        case 2:
            a->mUnk_30 = data_0215d4b4[(a->mUnk_2c >> 4) * 2];
            a->mUnk_04 = a->mUnk_1c + (s32) (((s64) a->mUnk_28 * a->mUnk_30) >> 12);
            a->mUnk_10 = a->mUnk_04;
            a->mUnk_2c = a->mUnk_2c + a->mUnk_2e;
            a->mUnk_3a = a->mUnk_3a + a->mUnk_2e;
            if (a->mUnk_2c > 0xbfff) {
                a->mUnk_24 = 3;
                a->mUnk_38 = 0;
                a->mUnk_3e = a->mUnk_2e;
            }
            break;
        case 3:
            a->mUnk_38 = a->mUnk_38 + 1;
            if (a->mUnk_38 > a->mUnk_36) {
                a->mUnk_24 = 0;
                if (a->mUnk_170 != 0 && v >= 0) {
                    s2.mUnk_00 = 0x113;
                    s2.mUnk_04 = 0;
                    s2.mUnk_08 = 4;
                    s2.mUnk_0c = func_020d4ef4(0);
                    func_0210b760(&s2, h);
                }
            } else if (a->mUnk_38 > (a->mUnk_36 >> 1)) {
                a->mUnk_3e = a->mUnk_3e + 1;
                a->mUnk_3a = a->mUnk_3a + a->mUnk_3e;
            } else {
                a->mUnk_3e = a->mUnk_3e - 1;
                a->mUnk_3a = a->mUnk_3a + a->mUnk_3e;
            }
            break;
    }
    a->mUnk_3c = a->mUnk_3c + a->mUnk_40;
    w = a->mUnk_3c - a->mUnk_50;
    if (a->mUnk_60 != 0) {
        j = (a->mUnk_3c >> 4) * 2;
        a->mUnk_00 = a->mUnk_18 + (s32) (((s64) a->mUnk_44 * data_0215d4b4[j]) >> 12);
        a->mUnk_08 = a->mUnk_20 + (s32) (((s64) a->mUnk_44 * data_0215d4b4[j + 1]) >> 12);
    }
    k = (w >> 4) * 2;
    a->mUnk_0c = a->mUnk_18 + (s32) (((s64) a->mUnk_48 * data_0215d4b4[k]) >> 12);
    a->mUnk_14 = a->mUnk_20 + (s32) (((s64) a->mUnk_48 * data_0215d4b4[k + 1]) >> 12);
}

void func_020d9e60(Unk020d9cf4 *a, struct Unk02012f58 *b) {
    if ((data_0217b67c->mUnk_02 & 0x12) != 0) {
        return;
    }
    if (a->mUnk_54 != 0) {
        if (a->mUnk_60 != 0) {
            a->mUnk_140.mUnk_24.x = a->mUnk_00 >> 4;
            a->mUnk_140.mUnk_24.y = a->mUnk_04 >> 4;
            a->mUnk_140.mUnk_24.z = a->mUnk_08 >> 4;
            func_020849f8(&a->mUnk_68, &a->mUnk_140, 0);
        }
        a->mUnk_140.mUnk_24.x = a->mUnk_0c >> 4;
        a->mUnk_140.mUnk_24.y = a->mUnk_10 >> 4;
        a->mUnk_140.mUnk_24.z = a->mUnk_14 >> 4;
        func_020849f8(&a->mUnk_d4, &a->mUnk_140, 0);
    } else {
        a->mUnk_140.mUnk_24.x = a->mUnk_0c >> 4;
        a->mUnk_140.mUnk_24.y = a->mUnk_10 >> 4;
        a->mUnk_140.mUnk_24.z = a->mUnk_14 >> 4;
        func_020849f8(&a->mUnk_d4, &a->mUnk_140, 0);
        if (a->mUnk_60 != 0) {
            a->mUnk_140.mUnk_24.x = a->mUnk_00 >> 4;
            a->mUnk_140.mUnk_24.y = a->mUnk_04 >> 4;
            a->mUnk_140.mUnk_24.z = a->mUnk_08 >> 4;
            func_020849f8(&a->mUnk_68, &a->mUnk_140, 0);
        }
    }
}

Unk020d9de0 *func_020d9de0(void) {
    Unk020d9de0 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    {
        Unk020d9de0 v = {0};
        *p = v;
    }
    return p;
}

#pragma thumb on

void func_020d9cf4(s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, u16 g, u16 h, u16 i, u16 j, u16 k, u16 l, u16 m, u16 n,
                   s32 o) {
    gWater->mUnk_1c = (a + b) >> 1;
    gWater->mUnk_04 = gWater->mUnk_1c;
    gWater->mUnk_10 = gWater->mUnk_04;
    gWater->mUnk_28 = (a - b) >> 1;
    gWater->mUnk_2c = 0;
    gWater->mUnk_3a = 0;
    gWater->mUnk_3c = 0;
    gWater->mUnk_50 = f;
    gWater->mUnk_52 = g;
    gWater->mUnk_2e = 0x10000 / h;
    gWater->mUnk_40 = (u32) gWater->mUnk_2e >> 2;
    gWater->mUnk_24 = 0;
    gWater->mUnk_34 = i;
    gWater->mUnk_36 = j;
    gWater->mUnk_30 = 0;
    gWater->mUnk_18 = data_0217b67c->mUnk_04;
    gWater->mUnk_00 = gWater->mUnk_18;
    gWater->mUnk_20 = data_0217b67c->mUnk_0c;
    gWater->mUnk_08 = gWater->mUnk_20;
    gWater->mUnk_44 = c;
    gWater->mUnk_48 = d;
    gWater->mUnk_4c = e;
    gWater->mUnk_54 = k;
    gWater->mUnk_58 = l;
    gWater->mUnk_5a = m;
    gWater->mUnk_5c = n;
    func_021471bc(&gWater->mUnk_140);
    gWater->mUnk_170 = o;
}

void CreateMiniStage3Water(void) {
    gWater = func_02036bec(func_020364e0(func_020364e8()), 0x180);
    func_020d9cf4(0xe8000, 0xc5000, 0x50000, 0x32000, 0x3c000, 0x7fff, 0x3fff, 0x1f4, 0x12c, 0x12c, 1, 5, 0xa, 0xa, 1);
    gWater->mUnk_60 = FindCourseMapObjFile("mini_stage3_waterA.nsbmd");
    gWater->mUnk_64 = FindCourseMapObjFile("mini_stage3_waterC.nsbmd");
    func_020d4980(gWater);
}

void CreateBeachWater(void) {
    gWater = func_02036bec(func_020364e0(func_020364e8()), 0x180);
    func_020d9cf4(0x78000, 0x62000, 0x50000, 0x43000, 0x3c000, 0x7fff, 0x3fff, 0x1f4, 0x96, 0x96, 1, 6, 0xa, 0xa, 1);
    gWater->mUnk_60 = FindCourseMapObjFile("beach_waterA.nsbmd");
    gWater->mUnk_64 = FindCourseMapObjFile("beach_waterC.nsbmd");
    func_020d4980(gWater);
}

void CreateTownWater(void) {
    gWater = func_02036bec(func_020364e0(func_020364e8()), 0x180);
    func_020d9cf4(0, 0, 0x29000, 0x1e000, 0xb000, 0x4e20, 0x3fff, 0x12c, 0x78, 0x1e, 1, 0xd, 0x19, 0x10, 0);
    gWater->mUnk_60 = FindCourseMapObjFile("town_waterA.nsbmd");
    gWater->mUnk_64 = FindCourseMapObjFile("town_waterC.nsbmd");
    func_020d4980(gWater);
}

void CreateYoshiWater(void) {
    gWater = func_02036bec(func_020364e0(func_020364e8()), 0x180);
    func_020d9cf4(0, 0, 0xc8000, 0x55000, 0x3c000, 0x7fff, 0x3fff, 0x1c2, 0x78, 0x1e, 1, 0xa, 0x17, 0x10, 0);
    gWater->mUnk_60 = 0;
    gWater->mUnk_64 = FindCourseMapObjFile("yoshi_waterC.nsbmd");
    func_020d4980(gWater);
}

void CreateHyudoroWater(void) {
    gWater = func_02036bec(func_020364e0(func_020364e8()), 0x180);
    func_020d9cf4(0, 0, 0x63000, 0x4d000, 0x1e000, 0x7fff, 0x3fff, 0x1c2, 0x78, 0x1e, 1, 0xf, 0x19, 0x10, 0);
    gWater->mUnk_60 = FindCourseMapObjFile("hyudoro_waterA.nsbmd");
    gWater->mUnk_64 = FindCourseMapObjFile("hyudoro_waterC.nsbmd");
    func_020d4980(gWater);
}

void func_020d9900(Unk020d9cf4 *a) {
    u32 i;
    Unk0201290c *p;
    Unk0201290c *q;
    s32 r;
    u32 n;
    if (a->mUnk_60 != 0) {
        func_02084e28(&a->mUnk_68, a->mUnk_60);
        i = 0;
        p = a->mUnk_68.mUnk_04;
        for (; i < p->mUnk_18; i++) {
            func_020135d0(p, i, 0x294a);
        }
        i = 0;
        p = a->mUnk_68.mUnk_04;
        for (; i < p->mUnk_18; i++) {
            func_020134b0(p, i, 1);
        }
    }
    func_02084e28(&a->mUnk_d4, a->mUnk_64);
    i = 0;
    p = a->mUnk_d4.mUnk_04;
    for (; i < p->mUnk_18; i++) {
        func_020135d0(p, i, 0x294a);
    }
    i = 0;
    p = a->mUnk_d4.mUnk_04;
    for (; i < p->mUnk_18; i++) {
        func_020134b0(p, i, 2);
    }
    q = a->mUnk_d4.mUnk_04;
    r = func_02013754(&q->mUnk_00[q->mUnk_08] + 4, data_02158094);
    if (a->mUnk_60 != 0) {
        n = a->mUnk_58;
        i = 0;
        p = a->mUnk_68.mUnk_04;
        for (; i < p->mUnk_18; i++) {
            func_02013468(p, i, n);
        }
    }
    func_02013468(q, r, a->mUnk_5a);
}

void CreateWaterEfct(Unk020da384 *a) {
    Unk020d98a4 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x10);
    gWaterEfct = p;
    p->mUnk_00 = a->mUnk_08;
    gWaterEfct->mUnk_04 = FindCourseFile("MapObj/water_efct.nsbmd");
    gWaterEfct->mUnk_08 = FindCourseFile("MapObj/water_efct.nsbca");
    gWaterEfct->mUnk_0c = FindCourseFile("MapObj/water_efct.nsbma");
    func_020d4970(gWaterEfct);
}

#pragma thumb off

void func_020d9810(s32 t, s32 *a, s32 *b, s32 *c, s32 *d) {
    s32 u = 0x1000000 - t;
    s32 v = (s32) (((s64) u * u) >> 24);
    *a = (s32) (((s64) u * v) >> 24);
    *b = (s32) (((s64) u * t) >> 24) * 3;
    *c = (s32) (((s64) *b * t) >> 24);
    v = (s32) (((s64) t * t) >> 24);
    *d = (s32) (((s64) t * v) >> 24);
    *b = (s32) (((s64) *b * u) >> 24);
}

void func_020d970c(s32 t, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h) {
    s32 u = 0x1000000 - t;
    *e = (s32) (((s64) u * u) >> 24);
    *a = (s32) (((s64) *e * u) >> 24);
    *h = (s32) (((s64) t * t) >> 24);
    *d = (s32) (((s64) *h * t) >> 24);
    *b = (s32) (((s64) u * t) >> 24) * 3;
    *e = *e * 3;
    *h = *h * 3;
    *g = *b << 1;
    *f = *e - *g;
    *g = *g - *h;
    *e = -*e;
    *c = (s32) (((s64) *b * t) >> 24);
    *b = (s32) (((s64) *b * u) >> 24);
}

void func_020d95c0(const Vec3 *p, Vec3 *o, s32 a, s32 b, s32 c, s32 d) {
    o->x = (s32) (((s64) p[0].x * a) >> 24);
    o->y = (s32) (((s64) p[0].y * a) >> 24);
    o->z = (s32) (((s64) p[0].z * a) >> 24);
    o->x = o->x + (s32) (((s64) p[1].x * b) >> 24);
    o->y = o->y + (s32) (((s64) p[1].y * b) >> 24);
    o->z = o->z + (s32) (((s64) p[1].z * b) >> 24);
    o->x = o->x + (s32) (((s64) p[2].x * c) >> 24);
    o->y = o->y + (s32) (((s64) p[2].y * c) >> 24);
    o->z = o->z + (s32) (((s64) p[2].z * c) >> 24);
    o->x = o->x + (s32) (((s64) p[3].x * d) >> 24);
    o->y = o->y + (s32) (((s64) p[3].y * d) >> 24);
    o->z = o->z + (s32) (((s64) p[3].z * d) >> 24);
}

void func_020d94dc(const Vec3 *p, Vec3 *o, s32 a, s32 b, s32 c, s32 d) {
    o->x = (s32) (((s64) p[0].x * a) >> 24);
    o->z = (s32) (((s64) p[0].z * a) >> 24);
    o->x = o->x + (s32) (((s64) p[1].x * b) >> 24);
    o->z = o->z + (s32) (((s64) p[1].z * b) >> 24);
    o->x = o->x + (s32) (((s64) p[2].x * c) >> 24);
    o->z = o->z + (s32) (((s64) p[2].z * c) >> 24);
    o->x = o->x + (s32) (((s64) p[3].x * d) >> 24);
    o->z = o->z + (s32) (((s64) p[3].z * d) >> 24);
}
