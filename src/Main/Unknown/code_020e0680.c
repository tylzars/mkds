#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_020e8ac8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_02147000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020f3678.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020b502c.h"
#include "01/code_02187eb0.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_020d9000.h"

#pragma thumb on

void func_020e2f0c(Unk020e1e98 *a, struct Unk020fa294 *b) {
    func_02046be8(&a->mUnk_000.mUnk_80, (UnkFunc *const *) data_0216c0e8, 8, a);
    a->mUnk_0a8 = a->mUnk_000.mPos.y;
    a->mUnk_0ac = a->mUnk_000.mPos.y - 0x12000;
    a->mUnk_0b0 = a->mUnk_000.mPos.y - 0x18000;
    a->mUnk_0a4 = b->mUnk_28;
    a->mUnk_0a0 = b->mUnk_2a;
    a->mUnk_000.mUnk_80.mUnk_10 = 0;
    a->mUnk_000.mUnk_80.mUnk_12 = 1;
    func_020e516c(&a->mUnk_0b4.mUnk_08, &a->mUnk_000.mPos, (s32) (((s64) a->mUnk_000.mUnk_1c.x * 0x1b000) >> 12), 0x1e);
    a->mUnk_000.mFlags |= data_02158b7c;
}

#pragma thumb off

void *func_020e2ebc(void) {
    void *p = HeapAlloc(GetHeap(func_020364e8()), 0x40);

    *(Unk020e03f8 *) p = *(const Unk020e03f8 *) data_02158b3c;
    return p;
}

void *func_020e2e6c(void) {
    void *p = HeapAlloc(GetHeap(func_020364e8()), 0x40);

    *(Unk020e03f8 *) p = *(const Unk020e03f8 *) data_02158afc;
    return p;
}

void *func_020e2e1c(void) {
    void *p = HeapAlloc(GetHeap(func_020364e8()), 0x40);

    *(Unk020e03f8 *) p = *(const Unk020e03f8 *) data_02158abc;
    return p;
}

void *func_020e2db8(void) {
    void *p = HeapAlloc(GetHeap(func_020364e8()), 0x40);

    data_0217b79c = p;
    *(Unk020e03f8 *) p = *(const Unk020e03f8 *) data_02158a7c;
    func_020d49d8(&data_0217b79c);
    return data_0217b79c;
}

void *func_020e2d5c(void) {
    void *p = HeapAlloc(GetHeap(func_020364e8()), 0x28);

    data_0217b7a4 = p;
    *(Unk020e0340 *) p = *(const Unk020e0340 *) data_02158a54;
    func_020e6f50(&data_0217b7a4);
    return data_0217b7a4;
}

void func_020e2ccc(Unk020e20a8 *a) {
    u16 b;

    b = data_021759c0->mUnk_62;
    if (a->mUnk_038 == 0) {
        return;
    }
    if (b < 8) {
        func_020f3678((u32) data_027e00c8[b].mUnk_1f0.mUnk_00, (u32) &a->mUnk_02c);
        a->mUnk_03c = func_02039828(&a->mUnk_02c, (Vec3 *) func_020e6b14()) < 0;
    } else {
        a->mUnk_03c = 0;
    }
}

void func_020e2a74(Unk020e20a8 *a, Unk020e1e98 *b, u32 c, u32 d) {
    u32 f;
    s32 t;
    s16 v;
    s16 w;
    Vec3 *m;
    const s16 *tbl;
    Unk020e1e98_12c *r;
    s32 buf[12];
    s32 one;
    u32 k;
    s32 x;
    s32 y;

    if (a->mUnk_03c != 0) {
        t = func_02039828(&b->mUnk_000.mMatrix.mUnk_00[2], &a->mUnk_02c);
        v = b->mUnk_000.mCourseMapRow->mUnk_2e;
        w = b->mUnk_0d8.mUnk_1c->mUnk_12;
        if (v == 0) {
            t = -t;
        }
        if (t > w) {
            return;
        }
    }
    f = (s32) (b->mUnk_000.mUnk_78 & 0x3FFFFFE0) > 0x77A10 && func_0203c5e4() == 0;
    if (!f) {
        if (b->mUnk_128 != 0) {
            m = b->mUnk_0fe > 0xF ? &b->mUnk_144 : &b->mUnk_000.mPos;
            b->mUnk_000.mMatrix.mUnk_00[3].x = m->x >> 4;
            b->mUnk_000.mMatrix.mUnk_00[3].y = m->y >> 4;
            b->mUnk_000.mMatrix.mUnk_00[3].z = m->z >> 4;
            func_020ea868((void *) b->mUnk_128, &b->mUnk_000.mMatrix, &b->mUnk_000.mUnk_1c, d);
        }
    }
    b->mUnk_000.mMatrix.mUnk_00[3].x = b->mUnk_000.mPos.x >> 4;
    b->mUnk_000.mMatrix.mUnk_00[3].y = b->mUnk_000.mPos.y >> 4;
    b->mUnk_000.mMatrix.mUnk_00[3].z = b->mUnk_000.mPos.z >> 4;
    r = b->mUnk_12c;
    if (r != NULL) {
        r->mUnk_0c = b->mUnk_130 << 12;
        *r->mUnk_1c[r->mUnk_1a] = r->mUnk_0c;
    }
    func_0208ab4c(&b->mUnk_132);
    func_020ea8a8((void *) b->mUnk_124, &b->mUnk_000.mMatrix, &b->mUnk_000.mUnk_1c, d);
    if (f) {
        return;
    }
    k = b->mUnk_10c >> 4;
    tbl = data_0215d4b4;
    x = (s32) (((s64) b->mUnk_110 * tbl[k * 2] + 0x800) >> 12);
    y = (s32) (((s64) b->mUnk_110 * tbl[k * 2 + 1] + 0x800) >> 12);
    func_02147230(buf, x, y);
    buf[0] = b->mUnk_100[0];
    buf[10] = b->mUnk_100[1];
    buf[11] = b->mUnk_100[2];
    func_01ff9048(0x11, NULL, 0);
    func_01ff9048(0x19, buf, 0xc);
    func_020849d0(gCarTire);
    one = 1;
    func_01ff9048(0x12, &one, 1);
    buf[11] = -buf[11];
    func_01ff9048(0x19, buf, 0xc);
    func_020849d0(gCarTire);
}

static inline s64 func_020e2630_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

static inline s16 func_020e2630_inline2(Unk020e1e98 *b) {
    return b->mUnk_0fe;
}

void func_020e2630(u32 a, Unk020e1e98 *b) {
    enum { K0 } f;
    void *p;
    u32 n;
    Unk020e1e98_0b4 m;
    Vec3 v;
    s32 out[3];
    Vec3 u;
    Vec3 w;

    if (b->mUnk_0fe > 0xf) {
        f = 1;
        f = (s32) f;
    } else {
        f = 0;
    }
    v = b->mUnk_000.mPos;
    func_020d8cc8(&b->mUnk_0d8);
    if (!f) {
        func_020d8bc0(&b->mUnk_0d8, &b->mUnk_000.mPos);
        func_021484d0(&b->mUnk_000.mPos, &v, &b->mUnk_000.mUnk_10);
    } else {
        func_020d8bc0(&b->mUnk_0d8, &b->mUnk_144);
        b->mUnk_000.mPos.x = b->mUnk_144.x;
        b->mUnk_000.mUnk_10.y -= 0x59a;
        b->mUnk_000.mPos.y = b->mUnk_000.mPos.y + b->mUnk_000.mUnk_10.y;
        b->mUnk_000.mPos.z = b->mUnk_144.z;
        b->mUnk_000.mUnk_10.x = b->mUnk_000.mPos.x - v.x;
        b->mUnk_000.mUnk_10.z = b->mUnk_000.mPos.z - v.z;
    }
    if (f || (b->mUnk_0d4 & 7) == func_02061f90()) {
        w.x = b->mUnk_000.mPos.x;
        w.y = b->mUnk_000.mPos.y + (f ? 0xf000 : 0);
        w.z = b->mUnk_000.mPos.z;
        u = w;
        if (func_01ffdee4(&u, NULL, 0, 0xf000, 8, -2, out, &u, NULL, &n, NULL, NULL, NULL, NULL) != 0) {
            if (n & 0x1e34ef) {
                func_020d7b88((Vec3 *) &u, &b->mUnk_0b4);
                func_0208ab98(&b->mUnk_132, (u16) ((n & 0x3c000000) >> 26), 0x5000);
                if (b->mUnk_0fe != 0 && b->mUnk_000.mUnk_10.y < 0) {
                    if (b->mUnk_000.mFlags & 1) {
                        b->mUnk_000.mFlags &= ~1;
                        b->mUnk_000.mUnk_10.y =
                            -(s32) (((s64) b->mUnk_000.mUnk_10.y * (0x733 + ((b->mUnk_114.y - 0x14000) >> 9))) >> 12);
                        b->mUnk_0c4 = -b->mUnk_0c4;
                        b->mUnk_0c8 = -b->mUnk_0c8;
                        b->mUnk_0cc = -b->mUnk_0cc;
                        func_020d759c(&b->mUnk_0c4, &b->mUnk_0b4, &b->mUnk_0c4, 0x8cd);
                        b->mUnk_152 = 0x320;
                        func_020d2774(&b->mUnk_000, b->mUnk_160);
                    } else if (f && b != NULL) {
                        b->mUnk_0fe = 0xf;
                        b->mUnk_000.mUnk_10.y = 0;
                        b->mUnk_152 = 0x258;
                    }
                }
            }
            if ((n & 0x214300) && f) {
                b->mUnk_000.mPos.y = b->mUnk_000.mPos.y + out[1];
                b->mUnk_000.mUnk_10.y = 0;
            }
        }
    }
    switch (f) {
        default:
            if (b->mUnk_000.mUnk_10.y < 0) {
                b->mUnk_152 = (u16) (((s64) (-b->mUnk_000.mUnk_10.y) * 0xc) >> 12);
                p = &b->mUnk_0b4;
            } else {
                p = &b->mUnk_0c4;
            }
            break;

        case 0:
            if (func_020e2630_inline2(b) != 0) {
                b->mUnk_0fe--;
                if (b->mUnk_0fe == 0) {
                    b->mUnk_152 = b->mUnk_150;
                } else {
                    p = &b->mUnk_0b4;
                }
            }
            break;
    }

    if (func_020e2630_inline(&b->mUnk_000.mUnk_10) < 0x10) {
        m = b->mUnk_0b4;
    } else {
        b->mUnk_000.mUnk_7e =
            (s16) (((s64) func_02148538(b->mUnk_000.mUnk_10.x, b->mUnk_000.mUnk_10.z) * 0x28BE60DB9391 +
                    0x80000000000) >>
                   44);
        if (b->mUnk_0fe == 0) {
            p = &b->mUnk_0b4;
        }
        func_020d79b0(p, b->mUnk_000.mUnk_7e, &m);
    }
    func_020d759c(&b->mUnk_0a4, &m, &b->mUnk_0a4, b->mUnk_152);
    func_01ffccd0(&b->mUnk_000.mMatrix.mUnk_00[0].x, &b->mUnk_0a4);
    b->mUnk_10c += 0x600;
    if (b->mUnk_000.mUnk_78 & 8) {
        func_0210b7ec(b->mUnk_158, b->mUnk_000.mUnk_78 & 0x3FFFFFE0);
    }
    func_020d275c(&b->mUnk_000, b->mUnk_15c);
    if (b->mUnk_000.mPos.y < 0) {
        func_020e1e98(b);
    }
}

void func_020e24d0(Unk020e1e98 *a, Vec3 *b) {
    Vec3 c;
    s32 d;
    s32 e;
    s32 f;

    c = a->mUnk_000.mPos;
    func_021484d0(&c, b, &c);
    d = func_02039828(&a->mUnk_000.mMatrix.mUnk_00[0], &c);
    e = func_02039828(&a->mUnk_000.mMatrix.mUnk_00[2], &c);
    c.x = (d > 0 ? a->mUnk_000.mMatrix.mUnk_00[0].x : -a->mUnk_000.mMatrix.mUnk_00[0].x) * 2;
    c.x += e > 0 ? a->mUnk_000.mMatrix.mUnk_00[2].x : -a->mUnk_000.mMatrix.mUnk_00[2].x;
    c.z = (d > 0 ? a->mUnk_000.mMatrix.mUnk_00[0].z : -a->mUnk_000.mMatrix.mUnk_00[0].z) * 2;
    c.z += e > 0 ? a->mUnk_000.mMatrix.mUnk_00[2].z : -a->mUnk_000.mMatrix.mUnk_00[2].z;
    c.y = ((a->mUnk_114.y - 0x14000) >> 4) + 0x2000;
    if ((s64) c.x * c.x + (s64) c.y * c.y + (s64) c.z * c.z >= 0x10) {
        func_02039860(&c, &c);
    }
    func_020d7b88((Vec3 *) &c, &a->mUnk_0c4);
    a->mUnk_152 = 0x384;
    if (a->mUnk_0fe > 0xf || a->mUnk_000.mUnk_10.y <= 0) {
        f = 0;
    } else {
        f = a->mUnk_000.mUnk_10.y;
    }
    a->mUnk_000.mUnk_10.y = f + 0x7000;
    a->mUnk_000.mFlags |= *(const u16 *) data_02158a50;
    a->mUnk_0fe = 0x14;
}

u8 func_020e2494(Unk020e1e98 *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020e24d0(a, &b->mUnk_80);
        func_020d26f8(&a->mUnk_000, b);
    }
    return *d;
}

u8 func_020e246c(Unk020e1e98 *a, Unk020e246c *b, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020e24d0(a, &b->mUnk_050);
    }
    return *d;
}

// non-matching: 19 words differ, first +0xc: the loads that fill the outgoing stack arguments run in a different order
void func_020e2400(Unk020e1e98 *a, Vec3 *b, s32 c, Vec3 *d) {
    Vec3 e;
    Vec3 f;

    e.z = a->mUnk_114.z;
    e.y = a->mUnk_114.y;
    e.x = a->mUnk_114.x;
    f.x = a->mUnk_114.x;
    f.y = 0;
    f.z = a->mUnk_120;
    func_020eafc4(b, &a->mUnk_000.mPos, &a->mUnk_000.mMatrix.mUnk_00[0], &e, &f, c, d);
}

#pragma thumb on

void func_020e230c(Unk0217b79c *a) {
    s32 i;
    s32 n;
    u32 b;
    Unk020e1e98 **p;
    u16 n2;
    u16 h;
    Unk02042044 *o;
    u16 j;
    u16 z;
    Unk020e1e98 *e;
    s16 v;
    s16 w;
    float f;

    n = a->mUnk_04;
    p = a->mUnk_00;
    b = 0;
    z = 0;
    for (i = 0; i < n; i++) {
        e = *p;
        h = e->mUnk_000.mCourseMapRow->mUnk_26;
        e->mUnk_0d4 = i;
        if ((b & (1 << h)) == 0) {
            n2 = gCourseMap->mUnk_08[h].mUnk_02;
            b |= 1 << h;
            for (j = 0; j < n2; j++) {
                o = func_02042044(h, j);
                v = o->mUnk_0e;
                if (v != 0) {
                    if (v > 0) {
                        f = 0.5f + (float) (v << 12);
                    } else {
                        f = (float) (v << 12) - 0.5f;
                    }
                    w = data_0215d4b4[((((u16) (((s64) (s32) f * 0xB60B60B60B + 0x80000000000) >> 44)) >> 4) << 1) + 1];
                } else {
                    w = 0x2000;
                }
                o->mUnk_12 = w;
                o->mUnk_0e = z;
            }
        }
        p++;
    }
}

void func_020e20a8(Unk020e20a8 *a) {
    u32 b;
    u32 c;
    u32 k1;
    Unk0201290c *y1;
    u32 k2;
    Unk0201290c *y2;
    u32 k3;
    Unk0201290c *y3;
    u32 k4;
    Unk0201290c *y4;
    s32 i;
    Unk020e1e98 *e;
    u32 *q;
    Unk020e1e98_12c **z;
    s32 n;

    b = (u32) FindCourseMapObjFile(gCarANsbmdName);
    c = (u32) FindCourseMapObjFile(gTruckANsbmdName);
    a->mUnk_038 = data_021759c0->mUnk_08 != 4 && func_0203c5e4() == 0 && (u16) data_021759c0->mUnk_62 < 8;
    a->mUnk_03c = 0;
    func_020ea588(&gCarA, (void *) b, NULL);
    func_020ea588(&gTruckA, (void *) c, NULL);
    func_020ea588(&gBusA, (void *) FindCourseMapObjFile(gBusANsbmdName), NULL);
    func_020ea588(&gCarTire, (void *) FindCourseMapObjFile(gCarTireNsbmdName), NULL);
    func_020ea55c(&gCarAShadow, (void *) FindCourseMapObjFile(gCarAShadowNsbmdName), 7);
    func_020ea55c(&gTruckAShadow, (void *) FindCourseMapObjFile(gTruckAShadowNsbmdName), 7);
    func_020ea55c(&gBusAShadow, (void *) FindCourseMapObjFile(gBusAShadowNsbmdName), 7);
    func_020ea4bc(2, gCarA, &gCarANsbtp, (void *) b, (void *) FindCourseMapObjFile(gCarANsbtpName));
    func_020ea4bc(2, gTruckA, &gTruckANsbtp, (void *) c, (void *) FindCourseMapObjFile(gTruckANsbtpName));
    func_02084968(gCarA, 0x3f, 2, 0x294a);
    for (k1 = 0, y1 = ((Unk0217b7a0 *) gCarA)->mUnk_04; k1 < y1->mEntryCount; k1++) {
        func_020134b0(y1, k1, 7);
    }
    func_02084968(gTruckA, 0x3f, 2, 0x294a);
    for (k2 = 0, y2 = ((Unk0217b7a0 *) gTruckA)->mUnk_04; k2 < y2->mEntryCount; k2++) {
        func_020134b0(y2, k2, 7);
    }
    func_02084968(gBusA, 0x3f, 2, 0x294a);
    for (k3 = 0, y3 = ((Unk0217b7a0 *) gBusA)->mUnk_04; k3 < y3->mEntryCount; k3++) {
        func_020134b0(y3, k3, 7);
    }
    func_02084968(gCarTire, 0x3f, 2, 0x294a);
    for (k4 = 0, y4 = ((Unk0217b7a0 *) gCarTire)->mUnk_04; k4 < y4->mEntryCount; k4++) {
        func_020134b0(y4, k4, 7);
    }
    func_020849b0(gCarTire, 0);
    n = ((Unk0217b79c *) data_0217b79c)->mUnk_04;
    for (i = 0; i < n; i++) {
        e = ((Unk0217b79c *) data_0217b79c)->mUnk_00[i];
        q = e->mUnk_154->mUnk_20;
        e->mUnk_124 = q != NULL ? *q : 0;
        q = e->mUnk_154->mUnk_24;
        e->mUnk_128 = q != NULL ? *q : 0;
        z = e->mUnk_154->mUnk_28;
        e->mUnk_12c = z != NULL ? *z : 0;
    }
}

void func_020e1f54(Unk020e1e98 *a, struct Unk020fa294 *b, Unk020e1e98_154 *c) {
    a->mUnk_154 = c;
    func_020d7da8(&a->mUnk_0d8, b, (s16) b->mUnk_28 * 0x3000 / 100);
    a->mUnk_0fc = b->mUnk_2a;
    a->mUnk_130 = b->mUnk_2c;
    a->mUnk_0a0 = func_02042044(b->mUnk_26, a->mUnk_0fc)->mUnk_00.y;
    a->mUnk_114.x = (s32) (((s64) c->mUnk_00 * a->mUnk_000.mUnk_1c.x) >> 12);
    a->mUnk_114.y = (s32) (((s64) c->mUnk_04 * a->mUnk_000.mUnk_1c.y) >> 12);
    a->mUnk_114.z = (s32) (((s64) c->mUnk_08 * a->mUnk_000.mUnk_1c.z) >> 12);
    a->mUnk_120 = (s32) (((s64) c->mUnk_0c * a->mUnk_000.mUnk_1c.z) >> 12);
    a->mUnk_152 = (u16) ((u32) ((s16) b->mUnk_28 * 0xfa) / 100);
    a->mUnk_150 = a->mUnk_152;
    a->mUnk_100[0] = c->mUnk_10;
    a->mUnk_100[1] = c->mUnk_14 >> 4;
    a->mUnk_100[2] = c->mUnk_18 >> 4;
    a->mUnk_110 = c->mUnk_1c;
    func_020e1e98(a);
    a->mUnk_15c = c->mUnk_2c;
    a->mUnk_158 = func_020d286c(&a->mUnk_000);
    func_0210b850(a->mUnk_158);
    a->mUnk_000.mUnk_94->mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a6ec;
    a->mUnk_160 = c->mUnk_30;
}

void func_020e1e98(Unk020e1e98 *a) {
    func_020d90a8(&a->mUnk_0d8, a->mUnk_0fc, 1);
    func_020d8b18(&a->mUnk_0d8, &a->mUnk_000.mPos, &a->mUnk_000.mUnk_10);
    a->mUnk_000.mPos.y = a->mUnk_0a0;
    a->mUnk_000.mUnk_10.y = 0;
    a->mUnk_0b4 = *(const Unk020e1e98_0b4 *) data_0216c044;
    func_020d79b0(
        &a->mUnk_0b4,
        (u16) (((s64) func_02148538(a->mUnk_000.mUnk_10.x, a->mUnk_000.mUnk_10.z) * 0x28be60db9391 + 0x80000000000) >>
               44),
        &a->mUnk_0a4);
    func_01ffccd0(&a->mUnk_000.mMatrix.mUnk_00[0].x, &a->mUnk_0a4);
    a->mUnk_0fe = 0;
    a->mUnk_152 = a->mUnk_150;
    a->mUnk_10c = 0;
    func_0208adc8(&a->mUnk_132, 1);
}

#pragma thumb off

void func_020e1e38(Unk020e1dc0 *a, void *b, void (*c)(Unk020e3ef4 *, void *, u32)) {
    s32 i;
    s32 n = a->mUnk_04;

    for (i = 0; i < n; i++) {
        Unk020e3ef4 *e = a->mUnk_00[i];

        if ((e->mUnk_000.mFlags & 0x12) == 0 && e->mUnk_000.mUnk_66 != 0) {
            c(e, b, e->mUnk_000.mUnk_66);
        }
    }
}

void func_020e1dec(Unk020e3ef4 *a, void *b, u32 c) {
    a->mUnk_000.mMatrix.mUnk_00[3].x = a->mUnk_000.mPos.x >> 4;
    a->mUnk_000.mMatrix.mUnk_00[3].y = a->mUnk_000.mPos.y >> 4;
    a->mUnk_000.mMatrix.mUnk_00[3].z = a->mUnk_000.mPos.z >> 4;
    func_020ea8a8(a->mUnk_140, &a->mUnk_000.mMatrix, &a->mUnk_000.mUnk_1c.x, c);
}

void func_020e1dc0(Unk020e1dc0 *a, void *b) {
    s32 i;
    s32 n = a->mUnk_04;

    for (i = 0; i < n; i++) {
        a->mUnk_00[i]->mUnk_140 = b;
    }
}

s32 func_020e1d10(Unk020e005c *a, Vec3 *b, s32 c, u32 d, Unk020e0764 *e, Unk020e0764 *f, Vec3 *g, u16 *h, Vec3 *i,
                  u16 *j) {
    switch (a->mUnk_134) {
        case 0:
            return func_020e0bac(a, b, c, d, e, f, g, h, i, j);
        case 1:
            return func_020e0764(a, b, c, d, e, f, g, h, i, j);
    }
    return 0;
}

void func_020e1a80(s32 a, s32 b, s32 c, u32 d, u16 e, u16 *f, s32 v, Unk020e005c *w, Vec3 *g, Vec3 *h, Unk020e0764 *i,
                   Unk020e0764 *j, Vec3 *k, Vec3 *l, u16 *m) {
    BOOL q;
    s32 t;
    Unk020e0764 *s;
    u16 n;
    Vec3 u;

    q = FALSE;
    if (v != 0) {
        if (d & e) {
            t = h->y;
        } else {
            t = -h->y;
        }
        if (t > w->mUnk_120) {
            q = TRUE;
        }
    }
    u.x = h->x << 10;
    u.y = h->y << 10;
    u.z = h->z << 10;
    u.x = (s32) (((s64) u.x * b) >> 12);
    u.y = (s32) (((s64) u.y * b) >> 12);
    u.z = (s32) (((s64) u.z * b) >> 12);
    if (q) {
        n = w->mUnk_114.z != 0 && (d & 8) ? 0x12 : 0;
        *f = n;
        s = i;
    } else {
        *f = 8;
        s = j;
    }
    if (c >= s->mUnk_18) {
        s->mUnk_18 = c;
        if (d & e) {
            s->mUnk_1c = *h;
        } else {
            s->mUnk_1c.x = -h->x;
            s->mUnk_1c.y = -h->y;
            s->mUnk_1c.z = -h->z;
        }
    }
    if (u.x > s->mUnk_00) {
        s->mUnk_00 = u.x;
    } else if (u.x < s->mUnk_0c) {
        s->mUnk_0c = u.x;
    }
    if (u.y > s->mUnk_04) {
        s->mUnk_04 = u.y;
    } else if (u.y < s->mUnk_10) {
        s->mUnk_10 = u.y;
    }
    if (u.z > s->mUnk_08) {
        s->mUnk_08 = u.z;
    } else if (u.z < s->mUnk_14) {
        s->mUnk_14 = u.z;
    }
    if (k != NULL) {
        if (d & e) {
            s32 v = -(a - c);

            u.x = (s32) (((s64) h->x * v) >> 12);
            u.y = (s32) (((s64) h->y * v) >> 12);
            u.z = (s32) (((s64) h->z * v) >> 12);
        } else {
            s32 v = a - c;

            u.x = (s32) (((s64) h->x * v) >> 12);
            u.y = (s32) (((s64) h->y * v) >> 12);
            u.z = (s32) (((s64) h->z * v) >> 12);
        }
        if (u.y < k->y) {
            *k = u;
        }
    }
    if (!q) {
        return;
    }
    func_020e0680(w, g, h, l, m);
}

// non-matching: code 0x3a0 vs 0x3a4: the incoming arguments land in different callee-saved registers (r6/r8, r5/r7,
// r4/r6 against the original)
BOOL func_020e16dc(s32 a, s32 b, s32 c, u32 d, u16 e, u16 f, u16 *g, u16 h, s32 i, s32 j, Unk020e005c *w, Vec3 *l,
                   Vec3 *m, Vec3 *n, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, Vec3 *r, u16 *s) {
    BOOL u;
    BOOL v;
    BOOL k;
    s32 t;
    Unk020e0764 *x;
    Vec3 y;
    Vec3 z;
    Vec3 tmp;

    u = FALSE;
    if ((h & 0x60) == 0) {
        v = TRUE;
        k = FALSE;
        if (i != 0) {
            t = (d & e) ? m->y : -m->y;
            if (t > w->mUnk_120) {
                k = TRUE;
            }
        }
        if (k == FALSE) {
            k = FALSE;
            if (j != 0) {
                t = (d & f) ? n->y : -n->y;
                if (t > w->mUnk_120) {
                    k = TRUE;
                }
            }
            if (k == FALSE) {
                v = FALSE;
            }
        }
        if (v != FALSE) {
            u = TRUE;
        }
    }
    y.x = (s32) (((s64) m->x * b) >> 12);
    y.y = (s32) (((s64) m->y * b) >> 12);
    y.z = (s32) (((s64) m->z * b) >> 12);
    z.x = (s32) (((s64) n->x * c) >> 12);
    z.y = (s32) (((s64) n->y * c) >> 12);
    z.z = (s32) (((s64) n->z * c) >> 12);
    func_02148504(&y, &z, &y);
    y.x <<= 10;
    y.y <<= 10;
    y.z <<= 10;
    t = func_020d70ac(&y, &tmp);
    if (t > (a << 10)) {
        return FALSE;
    }
    if (t != 0) {
        z.x = (s32) (((s64) tmp.x * a) >> 12);
        z.y = (s32) (((s64) tmp.y * a) >> 12);
        z.z = (s32) (((s64) tmp.z * a) >> 12);
        y.x >>= 10;
        y.y >>= 10;
        y.z >>= 10;
        func_021484d0(&z, &y, &z);
        t = func_021482cc(&z);
    } else {
        tmp = *n;
        z.x = (s32) (((s64) tmp.x * a) >> 12);
        z.y = (s32) (((s64) tmp.y * a) >> 12);
        z.z = (s32) (((s64) tmp.z * a) >> 12);
        t = a;
    }
    if (u) {
        if (w->mUnk_114.z != 0 && (d & 8)) {
            *g = 0x1e;
            x = p;
        } else {
            *g = 0;
            x = o;
        }
    } else {
        *g = 8;
        x = p;
    }
    if (t >= x->mUnk_18) {
        x->mUnk_18 = t;
        x->mUnk_1c = tmp;
    }
    z.x <<= 10;
    z.y <<= 10;
    z.z <<= 10;
    if (z.x > x->mUnk_00) {
        x->mUnk_00 = z.x;
    } else if (z.x < x->mUnk_0c) {
        x->mUnk_0c = z.x;
    }
    if (z.y > x->mUnk_04) {
        x->mUnk_04 = z.y;
    } else if (z.y < x->mUnk_10) {
        x->mUnk_10 = z.y;
    }
    if (z.z > x->mUnk_08) {
        x->mUnk_08 = z.z;
    } else if (z.z < x->mUnk_14) {
        x->mUnk_14 = z.z;
    }
    if (q != NULL) {
        y.x = -y.x;
        y.y = -y.y;
        y.z = -y.z;
        if (y.y < q->y) {
            *q = y;
        }
    }
    if (u) {
        func_020e0680(w, l, &tmp, r, s);
    }
    return TRUE;
}

// non-matching: the original keeps n & 0x8 at stack offset 0x4c, so v, w and tmp sit 4 bytes higher; the three
// "-((x + c) + f)" sums add f as the second operand; d is passed to func_020e16dc through lsl/lsr #16 (its parameter
// is u16; a u32 parameter removes that here but makes func_020e16dc worse), and some loads are scheduled differently
s32 func_020e0bac(Unk020e005c *a, Vec3 *b, s32 c, u32 d, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, u16 *g, Vec3 *r,
                  u16 *s) {
    Vec3 v;
    Vec3 w;
    Vec3 tmp;
    Unk020e0764 *x;
    u16 n;
    s32 f6;
    s32 f5;
    s32 f4;
    s32 k6;
    s32 k5;
    s32 m6;
    s32 m5;
    s32 m4;
    BOOL u;
    BOOL e;
    BOOL h;
    s32 t;

    n = 0;
    func_021484d0(b, &a->mUnk_0f4, &v);
    f6 = func_02039828(&v, &a->mUnk_028);
    if (f6 > 0) {
        if (f6 > a->mUnk_100 + c) {
            return 0;
        }
        if (f6 > a->mUnk_100) {
            n |= 0xa00;
        } else {
            n |= 0x900;
        }
    } else {
        if (f6 < -(a->mUnk_100 + c)) {
            return 0;
        }
        if (f6 < -a->mUnk_100) {
            n |= 0x600;
        } else {
            n |= 0x500;
        }
    }
    f5 = func_02039828(&v, &a->mUnk_034);
    if (f5 > 0) {
        if (f5 > a->mUnk_104 + c) {
            return 0;
        }
        if (f5 > a->mUnk_104) {
            n |= 0xa0;
        } else {
            n |= 0x90;
        }
    } else {
        if (f5 < -(a->mUnk_104 + c)) {
            return 0;
        }
        if (f5 < -a->mUnk_104) {
            n |= 0x60;
        } else {
            n |= 0x50;
        }
    }
    f4 = func_02039828(&v, &a->mUnk_040);
    if (f4 > 0) {
        if (f4 > a->mUnk_108 + c) {
            return 0;
        }
        if (f4 > a->mUnk_108) {
            n |= 0xa;
        } else {
            n |= 0x9;
        }
    } else {
        if (f4 < -(a->mUnk_10c + c)) {
            return 0;
        }
        if (f4 < -a->mUnk_10c) {
            n |= 0x6;
        } else {
            n |= 0x5;
        }
    }
    if ((d & 4) && a->mUnk_13c != 0) {
        return 0;
    }
    if (n & 0x100) {
        if (n & 0x10) {
            if (n & 0x8) {
                f4 = (a->mUnk_108 + c) - f4;
            } else {
                f4 = -((a->mUnk_10c + c) + f4);
            }
            if (n & 0x1) {
                if (n & 0x800) {
                    k6 = (a->mUnk_100 + c) - f6;
                } else {
                    k6 = -((a->mUnk_100 + c) + f6);
                }
                if (n & 0x80) {
                    k5 = (a->mUnk_104 + c) - f5;
                } else {
                    k5 = -((a->mUnk_104 + c) + f5);
                }
                m6 = k6 > 0 ? k6 : -k6;
                m5 = k5 > 0 ? k5 : -k5;
                m4 = f4 > 0 ? f4 : -f4;
                goto smallest;
            }
            m4 = f4 > 0 ? f4 : -f4;
            goto call_8;
        }
        if (n & 0x80) {
            k5 = (a->mUnk_104 + c) - f5;
        } else {
            k5 = -((a->mUnk_104 + c) + f5);
        }
        if (!(n & 0x1)) {
            goto call_80_8;
        }
        m5 = k5 > 0 ? k5 : -k5;
        goto call_80;
    }
    if (n & 0x800) {
        k6 = (a->mUnk_100 + c) - f6;
    } else {
        k6 = -((a->mUnk_100 + c) + f6);
    }
    if (n & 0x10) {
        if (!(n & 0x1)) {
            goto call_8_800;
        }
        m6 = k6 > 0 ? k6 : -k6;
    } else {
        if (!(n & 0x1)) {
            goto rest;
        }
        goto call_800_80;
    }
call_800:
    func_020e1a80(c, k6, m6, n, 0x800, g, a->mUnk_110, a, b, &a->mUnk_028, o, p, q, r, s);
    return 1;
call_80:
    func_020e1a80(c, k5, m5, n, 0x80, g, a->mUnk_114.x, a, b, &a->mUnk_034, o, p, q, r, s);
    return 1;
call_8:
    func_020e1a80(c, f4, m4, n, 8, g, a->mUnk_114.y, a, b, &a->mUnk_040, o, p, q, r, s);
    return 1;
smallest:
    if (m6 < m4) {
        if (m6 < m5) {
            goto call_800;
        }
        goto call_80;
    }
    if (m4 < m5) {
        goto call_8;
    }
    goto call_80;
call_800_80:
    if (n & 0x800) {
        f6 = f6 - a->mUnk_100;
    } else {
        f6 = f6 + a->mUnk_100;
    }
    if (n & 0x80) {
        f5 = f5 - a->mUnk_104;
    } else {
        f5 = f5 + a->mUnk_104;
    }
    return func_020e16dc(c, f6, f5, n, 0x800, 0x80, g, d, a->mUnk_110, a->mUnk_114.x, a, b, &a->mUnk_028, &a->mUnk_034,
                         o, p, q, r, s);
call_80_8:
    if (n & 0x80) {
        f5 = f5 - a->mUnk_104;
    } else {
        f5 = f5 + a->mUnk_104;
    }
    if (n & 0x8) {
        f4 = f4 - a->mUnk_108;
    } else {
        f4 = f4 + a->mUnk_10c;
    }
    return func_020e16dc(c, f5, f4, n, 0x80, 0x8, g, d, a->mUnk_114.x, a->mUnk_114.y, a, b, &a->mUnk_034, &a->mUnk_040,
                         o, p, q, r, s);
call_8_800:
    if (n & 0x800) {
        f6 = f6 - a->mUnk_100;
    } else {
        f6 = f6 + a->mUnk_100;
    }
    if (n & 0x8) {
        f4 = f4 - a->mUnk_108;
    } else {
        f4 = f4 + a->mUnk_10c;
    }
    return func_020e16dc(c, f4, f6, n, 8, 0x800, g, d, a->mUnk_114.y, a->mUnk_110, a, b, &a->mUnk_040, &a->mUnk_028, o,
                         p, q, r, s);
rest:
    u = FALSE;
    if ((d & 0x60) == 0) {
        e = TRUE;
        h = FALSE;
        if (a->mUnk_110 != 0) {
            t = (n & 0x800) ? a->mUnk_028.y : -a->mUnk_028.y;
            if (t > a->mUnk_120) {
                h = TRUE;
            }
        }
        if (h == FALSE) {
            h = FALSE;
            if (a->mUnk_114.x != 0) {
                t = (n & 0x80) ? a->mUnk_034.y : -a->mUnk_034.y;
                if (t > a->mUnk_120) {
                    h = TRUE;
                }
            }
            if (h == FALSE) {
                e = FALSE;
            }
        }
        if (e != FALSE) {
            k5 = 0;
            if (a->mUnk_114.y != 0) {
                t = (n & 0x8) ? a->mUnk_040.y : -a->mUnk_040.y;
                if (t > a->mUnk_120) {
                    k5 = 1;
                }
            }
            if (k5 == 0) {
                e = FALSE;
            }
        }
        if (e != FALSE) {
            u = TRUE;
        }
    }
    if (n & 0x800) {
        f6 = f6 - a->mUnk_100;
    } else {
        f6 = f6 + a->mUnk_100;
    }
    if (n & 0x80) {
        f5 = f5 - a->mUnk_104;
    } else {
        f5 = f5 + a->mUnk_104;
    }
    if (n & 0x8) {
        f4 = f4 - a->mUnk_108;
    } else {
        f4 = f4 + a->mUnk_10c;
    }
    v.x = (s32) (((s64) a->mUnk_028.x * f6) >> 12);
    v.y = (s32) (((s64) a->mUnk_028.y * f6) >> 12);
    v.z = (s32) (((s64) a->mUnk_028.z * f6) >> 12);
    w.x = (s32) (((s64) a->mUnk_034.x * f5) >> 12);
    w.y = (s32) (((s64) a->mUnk_034.y * f5) >> 12);
    w.z = (s32) (((s64) a->mUnk_034.z * f5) >> 12);
    func_02148504(&w, &v, &v);
    w.x = (s32) (((s64) a->mUnk_040.x * f4) >> 12);
    w.y = (s32) (((s64) a->mUnk_040.y * f4) >> 12);
    w.z = (s32) (((s64) a->mUnk_040.z * f4) >> 12);
    func_02148504(&w, &v, &v);
    v.x <<= 10;
    v.y <<= 10;
    v.z <<= 10;
    t = func_020d70ac(&v, &w);
    if (t > (c << 10)) {
        return 0;
    }
    if (t != 0) {
        tmp.x = (s32) (((s64) w.x * c) >> 12);
        tmp.y = (s32) (((s64) w.y * c) >> 12);
        tmp.z = (s32) (((s64) w.z * c) >> 12);
        v.x >>= 10;
        v.y >>= 10;
        v.z >>= 10;
        func_021484d0(&tmp, &v, &tmp);
        t = func_021482cc(&tmp);
    } else {
        w = a->mUnk_034;
        tmp.x = (s32) (((s64) w.x * c) >> 12);
        tmp.y = (s32) (((s64) w.y * c) >> 12);
        tmp.z = (s32) (((s64) w.z * c) >> 12);
    }
    if (u) {
        if (a->mUnk_114.z != 0 && (n & 0x8)) {
            *g = 0x1e;
            x = p;
        } else {
            *g = 0;
            x = o;
        }
    } else {
        *g = 8;
        x = p;
    }
    if (t >= x->mUnk_18) {
        x->mUnk_18 = t;
        x->mUnk_1c = w;
    }
    tmp.x <<= 10;
    tmp.y <<= 10;
    tmp.z <<= 10;
    if (tmp.x > x->mUnk_00) {
        x->mUnk_00 = tmp.x;
    } else if (tmp.x < x->mUnk_0c) {
        x->mUnk_0c = tmp.x;
    }
    if (tmp.y > x->mUnk_04) {
        x->mUnk_04 = tmp.y;
    } else if (tmp.y < x->mUnk_10) {
        x->mUnk_10 = tmp.y;
    }
    if (tmp.z > x->mUnk_08) {
        x->mUnk_08 = tmp.z;
    } else if (tmp.z < x->mUnk_14) {
        x->mUnk_14 = tmp.z;
    }
    if (q != NULL) {
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
        if (v.y < q->y) {
            *q = v;
        }
    }
    if (u) {
        func_020e0680(a, b, &w, r, s);
    }
    return 1;
}

// non-matching: code 0x43c vs 0x448.
s32 func_020e0764(Unk020e005c *a, Vec3 *b, s32 c, u32 d, Unk020e0764 *o, Unk020e0764 *p, Vec3 *q, u16 *g, Vec3 *r,
                  u16 *s) {
    Vec3 v;
    s32 d0;
    Vec3 w;
    u16 fl;
    s32 x;
    s32 y;
    s32 t;
    s32 n;

    func_021484d0(b, &a->mUnk_0f4, &v);
    x = func_02039828(&v, &a->mUnk_028);
    y = func_02039828(&v, &a->mUnk_040);
    t = a->mUnk_100 + c;
    if ((s64) t * t < (s64) x * x + (s64) y * y) {
        return 0;
    }
    fl = 0;
    if ((s64) a->mUnk_100 * a->mUnk_100 < (s64) x * x + (s64) y * y) {
        fl |= data_021588e8;
    } else {
        fl |= data_021588ec;
    }
    n = func_02039828(&v, &a->mUnk_034);
    if (n > 0) {
        if (n > a->mUnk_104 + c) {
            return 0;
        }
        if (n > a->mUnk_104) {
            fl |= 0xa0;
        } else {
            fl |= 0x90;
        }
    } else {
        if (n < -(a->mUnk_104 + c)) {
            return 0;
        }
        if (n < -a->mUnk_104) {
            fl |= 0x60;
        } else {
            fl |= 0x50;
        }
    }
    if (fl & 0x1000) {
        if (fl & 0x80) {
            n = a->mUnk_104 + c - n;
        } else {
            n = -(a->mUnk_104 + c + n);
        }
        if (n > 0) {
            d0 = n;
        } else {
            d0 = -n;
        }
        if (!(fl & 0x10)) {
            goto apply80;
        }
        {
            v.x = x;
            v.y = 0;
            v.z = y;
            x = func_020d6f78(&v, &v);
            if (x == 0) {
                w = data_021588f0;
            }
            t -= x;
            if (x != 0) {
                w.x = (s32) (((s64) a->mUnk_028.x * v.x) >> 12);
                w.y = (s32) (((s64) a->mUnk_028.y * v.x) >> 12);
                w.z = (s32) (((s64) a->mUnk_028.z * v.x) >> 12);
                func_02147fd8(v.z, &a->mUnk_040, &w, &w);
            }
            if (t < d0) {
                goto apply3000;
            }
        }
    apply80:
        func_020e1a80(c, n, d0, fl, 0x80, g, a->mUnk_114.x, a, b, &a->mUnk_034, o, p, q, r, s);
        return 1;
    }
    v.x = x;
    v.y = 0;
    v.z = y;
    x = func_020d6f78(&v, &v);
    if (x == 0) {
        w = data_021588fc;
    }
    t -= x;
    if (x != 0) {
        w.x = (s32) (((s64) a->mUnk_028.x * v.x) >> 12);
        w.y = (s32) (((s64) a->mUnk_028.y * v.x) >> 12);
        w.z = (s32) (((s64) a->mUnk_028.z * v.x) >> 12);
        func_02147fd8(v.z, &a->mUnk_040, &w, &w);
    }
    if (fl & 0x10) {
        goto apply3000;
    }
    if (fl & 0x80) {
        n = n - a->mUnk_104;
    } else {
        n = n + a->mUnk_104;
    }
    x = x - a->mUnk_100;
    return func_020e16dc(c, x, n, fl, 0x3000, 0x80, g, d, a->mUnk_110, a->mUnk_114.x, a, b, &w, &a->mUnk_034, o, p, q,
                         r, s);
apply3000:
    func_020e1a80(c, t, x, fl, 0x3000, g, a->mUnk_110, a, b, &w, o, p, q, r, s);
    return 1;
}

void func_020e0680(Unk020e005c *a, Vec3 *b, Vec3 *c, Vec3 *d, u16 *e) {
    Vec3 f;

    if (d != NULL) {
        d->x = -a->mUnk_010.x;
        d->y = -a->mUnk_010.y;
        d->z = -a->mUnk_010.z;
        func_021484d0(b, &a->mUnk_004, &f);
        func_02147fd8(func_02039828(&f, &a->mUnk_028), &a->mUnk_0a0, d, d);
        func_02147fd8(func_02039828(&f, &a->mUnk_034), &a->mUnk_0ac, d, d);
        func_02147fd8(func_02039828(&f, &a->mUnk_040), &a->mUnk_0b8, d, d);
        func_021484d0(&f, d, d);
    }
    if (e != NULL) {
        *e = func_02039828(&a->mUnk_124, c);
    }
}
