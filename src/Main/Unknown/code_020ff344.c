#include "Main/Unknown/code_020ff344.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_021052f0.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_020ee684.h"
#include "01/code_02187d14.h" // data_0217c600

#pragma thumb on

void CreateDram(void) {
    func_020ea588(&gDram, (void *) FindCourseMapObjFile(gDramNsbmdName), NULL);
    func_02084968(gDram, 0x3f, 2, 0x294a);
}

void InitDram(Dram *a, struct CourseMapRow *b) {
    func_02046be8(&a->mUnk_00.mUnk_80, (UnkFunc *const *) data_0216c740, 6, a);
    a->mUnk_b4[0] = b->mUnk_28 * 0x80 / 100;
    a->mUnk_b4[2] = b->mUnk_30 * 0x80 / 100;
    a->mUnk_b4[1] = (a->mUnk_b4[0] + a->mUnk_b4[2]) / 2;
    a->mUnk_a2 = b->mUnk_2a;
    a->mUnk_a0 = b->mUnk_2c;
    a->mUnk_a4 = b->mUnk_2e;
    a->mUnk_a6 = 0;
    if (a->mUnk_a0 != 0) {
        a->mUnk_b0 = 0x1000 / a->mUnk_a0;
    } else {
        a->mUnk_b0 = 0;
    }
    a->mUnk_ac = 0;
    a->mUnk_00.mUnk_80.mNextState = 1;
    a->mUnk_00.mUnk_80.mNextStateRequested = 1;
}

#pragma thumb off

Unk02100004 *func_020ffacc(void) {
    Unk02100004 *p;

    p = GetHeap(func_020364e8());
    p = HeapAlloc(p, 0x40);
    *p = data_0215a068;
    return p;
}

BOOL func_020ffabc(u32 a) {
    return a == 0xb;
}

#pragma thumb on

void func_020ff97c(Unk020ff97c *e) {
    e->mUnk_a0 = *(Matrix3x3 *) &e->mUnk_00.mMatrix;
    e->mUnk_124 = 0;
    e->mUnk_128 = 0;
    e->mUnk_12c = 0;
    e->mUnk_130 = 0;
    e->mUnk_100 = (s32) (((s64) e->mUnk_00.mScale.x * 0x190000) >> 12);
    e->mUnk_104 = (s32) (((s64) e->mUnk_00.mScale.y * 0x64000) >> 12) >> 1;
    e->mUnk_108 = (s32) (((s64) e->mUnk_00.mScale.z * 0xaf000) >> 12);
    e->mUnk_10c = (s32) (((s64) e->mUnk_00.mScale.z * 0xaf000) >> 12);
    e->mUnk_110 = 0;
    e->mUnk_114 = 1;
    e->mUnk_118 = 0;
    e->mUnk_11c = 0;
    e->mUnk_120 = 0x800;
    e->mUnk_e8 = e->mUnk_00.mPos;
    e->mUnk_00.mUnk_10.x = 0;
    e->mUnk_00.mUnk_10.y = 0;
    e->mUnk_00.mUnk_10.z = 0;
    Vec3AddScaled(-e->mUnk_104, &e->mUnk_00.mMatrix.mUnk_00[1], &e->mUnk_00.mPos, &e->mUnk_f4);
    e->mUnk_134 = 0;
    e->mUnk_138 = 0;
    e->mUnk_13c = 1;
    e->mUnk_00.mFlags |= data_0215a030;
}

#pragma thumb off

void func_020ff910(Unk020ff438 *e, Unk02012f58 *out) {
    Vec3 *v;

    v = e->mUnk_000.mUnk_000.mUnk_d0;
    e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[3].x = v->x >> 4;
    e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[3].y = v->y >> 4;
    e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[3].z = v->z >> 4;
    *out = e->mUnk_000.mUnk_000.mUnk_94;
    Matrix3x3Multiply((const s32 *) &data_0217c600, (const s32 *) out, (s32 *) out);
}

void func_020ff6d8(Unk020ff438 *e, Unk02012f58 *out) {
    s32 a, b;
    Vec3 *v;

    if ((e->mUnk_000.mUnk_000.mFlags & 0x80000) && func_020b2ec0() == 0) {
        s32 c, d;

        c = (s32) (((s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].x * e->mUnk_130.x +
                    (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].z * e->mUnk_130.z) >>
                   12);
        a = (s32) (((s64) e->mUnk_130.x * 0xa4) >> 12);
        d = (s32) (((s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].x * e->mUnk_130.x +
                    (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].z * e->mUnk_130.z) >>
                   12);
        b = (s32) (((s64) e->mUnk_130.z * 0xa4) >> 12);
        e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].x = (s32) (e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].x + a);
        e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].z += b;
        if ((s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].x * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].x +
                (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].y * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].y +
                (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].z * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1].z >=
            0x10) {
            func_02039860(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1]);
        }
        if (c * c > d * d) {
            e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].x = (s32) (e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].x - a);
            e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].z -= b;
            func_020397a8(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2],
                          &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0]);
            if ((s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].x * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].x +
                    (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].y * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].y +
                    (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].z * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].z >=
                0x10) {
                func_02039860(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0]);
            }
            func_020397a8(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1],
                          &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2]);
        } else {
            e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].x -= a;
            e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].z -= b;
            func_020397a8(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1],
                          &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2]);
            if ((s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].x * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].x +
                    (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].y * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].y +
                    (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].z * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2].z >=
                0x10) {
                func_02039860(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2]);
            }
            func_020397a8(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2],
                          &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0]);
        }
    }
    v = e->mUnk_000.mUnk_000.mUnk_d0;
    e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[3].x = v->x >> 4;
    e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[3].y = v->y >> 4;
    e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[3].z = v->z >> 4;
    *out = e->mUnk_000.mUnk_000.mUnk_94;
}

void func_020ff67c(Unk020ff438 *e) {
    *(Matrix3x3 *) &e->mUnk_000.mUnk_000.mUnk_94 = *(Matrix3x3 *) &data_0217c600;
    func_021053e4(e->mUnk_140);
    e->mUnk_140->mUnk_b0 = 2;
    func_021052f0(e->mUnk_140, func_020ff910, e);
}

void func_020ff654(Unk020ff438 *e) {
    e->mUnk_140->mUnk_b0 = 1;
    func_021052f0(e->mUnk_140, func_020ff6d8, e);
}

void func_020ff638(Unk020eda5c *a, Unk020ff438 *e) {
    func_02105338(e->mUnk_140, e->mUnk_000.mUnk_000.mUnk_d8, &e->mUnk_000.mUnk_000.mUnk_68);
}

u32 func_020ff538(Unk020eda5c *a, Unk020ff438 *e) {
    func_020f9114(e);
    e->mUnk_000.mUnk_000.mUnk_78 |= data_0215a02c;
    Matrix3x3Multiply((const s32 *) &data_0217c600, (const s32 *) &e->mUnk_000.mUnk_000.mUnk_94,
                      (s32 *) &e->mUnk_000.mUnk_000.mUnk_94);
    e->mUnk_130.x = 0;
    e->mUnk_130.y = 0;
    e->mUnk_130.z = 0;
    if ((a->mUnk_00c->mFlags & 0x10) != 0) {
        func_020f3150(&e->mUnk_000, a, 0, 1, 0x4000, 0x3000, 0x59a);
        func_021090c4(&e->mUnk_000.mUnk_000.mUnk_00, 0xda, 0x7f, 0);
        e->mUnk_13c = 1;
        return e->mUnk_13c;
    }
    func_020f3150(&e->mUnk_000, a, 0, 0, 0x4000, 0x3000, 0x59a);
    e->mUnk_13c = 0;
    return e->mUnk_13c;
}

void func_020ff438(Unk020ff438 *e) {
    s32 t;

    if (e->mUnk_000.mUnk_000.mFlags & 0x180000) {
        if (e->mUnk_000.mUnk_000.mFlags & 0x80000) {
            func_020f6e58(&e->mUnk_000.mUnk_000);
        } else if (e->mUnk_000.mUnk_000.mFlags & 0x100000) {
            func_020f758c(&e->mUnk_000.mUnk_000);
        }
    } else if (e->mUnk_000.mUnk_000.mFlags & 0x8000) {
        func_020f68b0(&e->mUnk_000.mUnk_000);
    } else if (e->mUnk_000.mUnk_000.mFlags & 0x4000) {
        func_020f63cc(&e->mUnk_000.mUnk_000);
    } else {
        if (e->mUnk_13c != 0) {
            func_020f2df0(&e->mUnk_000, 0x1ec, 0xfec, 0, (u32 *) &t);
        } else {
            func_020f2df0(&e->mUnk_000, 0x2e1, 0xf85, 0, (u32 *) &t);
        }
        if ((e->mUnk_000.mUnk_000.mFlags & 8) && (e->mUnk_000.mUnk_000.mFlags & 3) == 0) {
            if (e->mUnk_13c != 0) {
                e->mUnk_000.mUnk_000.mVelocity.y *= 2;
            }
            func_02109060(&e->mUnk_000.mUnk_000.mUnk_00, 0xda);
            func_020f6a6c(&e->mUnk_000.mUnk_000, &t);
        }
    }
    func_02105338(e->mUnk_140, e->mUnk_000.mUnk_000.mUnk_d8, &e->mUnk_000.mUnk_000.mUnk_68);
}

s32 func_020ff3c4(Unk020ff438 *e) {
    Vec3 *v;

    v = data_0217bc4c;
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z >= 0x10) {
        func_02039860(v, &e->mUnk_130);
    }
    e->mUnk_140->mUnk_b0 = 2;
    if ((e->mUnk_000.mUnk_000.mFlags & 0x180000) == 0) {
        e->mUnk_000.mUnk_000.mUnk_120 = (void (*)(ItemObject *)) func_020ff438;
    }
    return 2;
}

void func_020ff344(Unk020ff438 *e) {
    if ((s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].x * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].x +
            (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].y * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].y +
            (s64) e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].z * e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0].z >=
        0x10) {
        func_02039860(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0]);
    }
    func_020397a8(&e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[0], &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[1],
                  &e->mUnk_000.mUnk_000.mUnk_94.mUnk_00[2]);
    Matrix3x3Multiply((const s32 *) &data_0217c600, (const s32 *) &e->mUnk_000.mUnk_000.mUnk_94,
                      (s32 *) &e->mUnk_000.mUnk_000.mUnk_94);
    if ((e->mUnk_000.mUnk_000.mFlags & 0x180000) == 0) {
        e->mUnk_000.mUnk_000.mUnk_120 = (void (*)(ItemObject *)) func_020ff438;
    }
}
