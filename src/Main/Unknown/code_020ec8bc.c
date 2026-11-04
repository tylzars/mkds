#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d7df8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02135014.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"

#pragma thumb on
#pragma optimize_for_size on

void *func_020ed548(u8 *a) {
    char buf[0x100];

    if (a == NULL) {
        return NULL;
    }
    snprintf(buf, 0x100, data_0216c604, a);
    return FindMainRaceOrMainEffectFile(buf);
}

Unk020e6488 *func_020ed4d0(u8 *a, u8 *b, u8 *c) {
    Unk020e6488 *p;
    void *q;
    void *r;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    q = func_020ed548(a);
    r = func_020ed548(b);
    func_020e64b8(p, q, r, 0);
    p->mUnk_14 &= 0xc0ffffff;
    p->mUnk_14 |= 0x04000000;
    p->mUnk_14 &= ~0xf;
    p->mUnk_14 |= 0x2;
    p->mUnk_10 &= 0x8000ffff;
    p->mUnk_10 |= 0x10840000;
    return p;
}

void *func_020ed490(u8 *a, u8 *b) {
    void *p;
    void *q;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x6c);
    q = func_020ed548(a);
    func_02084e28(p, q);
    func_02084968(p, 4, 2, 0x294a);
    return p;
}

void func_020ed2f8(void) {
    enum { K0 } i;
    void *p;
    BOOL f;

    i = 0;
    while (i < 0xe) {
        data_0217bbfc[i] = NULL;
        i++;
    }
    data_0217bbfc[0] = func_020ed4d0(data_0216c42c, NULL, data_0216c440);
    data_0217bbfc[1] = func_020ed4d0(data_0216c454, NULL, data_0216c468);
    data_0217bbfc[2] = func_020ed4d0(data_0216c47c, NULL, data_0216c48c);
    data_0217bbfc[3] = func_020ed4d0(data_0216c49c, NULL, data_0216c4ac);
    data_0217bbfc[4] = func_020ed4d0(data_0216c4bc, NULL, data_0216c4cc);
    data_0217bbfc[5] = func_020ed4d0(data_0216c4dc, NULL, data_0216c4f0);
    data_0217bbfc[6] = func_020ed4d0(data_0216c504, NULL, data_0216c518);
    data_0217bbfc[7] = func_020ed4d0(data_0216c52c, NULL, data_0216c53c);
    data_0217bbfc[9] = func_020ed4d0(data_0216c54c, data_0216c55c, data_0216c56c);
    data_0217bbfc[10] = func_020ed4d0(data_0216c57c, NULL, data_0216c58c);
    data_0217bbfc[11] = func_020ed4d0(data_0216c59c, NULL, data_0216c5ac);
    data_0217bbfc[12] = func_020ed4d0(data_0216c5bc, NULL, data_0216c5d0);
    data_0217bbfc[13] = func_020ed4d0(data_0216c5e4, NULL, data_0216c5f4);
    data_0217bbfc[8] = data_0217bbfc[7];
    f = (data_021759c0->mCourseId == 0x1d);
    i = 0;
    while (i < 0xe) {
        p = &data_0217bc34[i];
        if (((Unk0217bc34_14 *) p)->mUnk_14 != NULL) {
            ((Unk0217bc34_14 *) p)->mUnk_14();
        }
        if (f != FALSE) {
            data_0217bbfc[i]->mUnk_14 &= 0xffff7fff;
        }
        i++;
    }
}

#pragma optimize_for_size off
#pragma thumb off

void func_020ed268(Unk020ec8bc *p, Unk020eda5c *q, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, u16 g, s32 h) {
    func_020f2b94(p, q, (e == 0) ? -1 : 0, c, d, f);
    p->mUnk_214 = a;
    p->mUnk_218 = b;
    p->mUnk_21c = q->mUnk_00c->mUnk_1f0;
    func_020f371c(&p->mUnk_21c, &p->mUnk_168, g, h);
    p->mUnk_224 = 0;
}

BOOL func_020ed0f4(Unk020ec8bc *p) {
    Vec3 v[6];
    Vec3 *r;
    Vec3 *q;
    s32 n;
    s32 s;

    q = &p->mUnk_000.mUnk_000.mUnk_50;
    r = &p->mUnk_000.mUnk_130;
    Vec3Sub(p->mUnk_168.mUnk_00->mUnk_18, q, &v[0]);
    if ((s64) v[0].x * v[0].x + (s64) v[0].y * v[0].y + (s64) v[0].z * v[0].z >= 0x10) {
        func_02039860(&v[0], &v[1]);
    }
    n = func_02039828(r, &v[1]);
    if (n > 0xddb || p->mUnk_000.mUnk_158 != 0) {
        v[0].x >>= 2;
        v[0].y >>= 2;
        v[0].z >>= 2;
        s = Vec3Dot(r, &v[0]);
        v[1].x = (s32) (((u64) ((s64) r->x * s)) >> 12);
        v[1].y = (s32) (((u64) ((s64) r->y * s)) >> 12);
        v[1].z = (s32) (((u64) ((s64) r->z * s)) >> 12);
        Vec3Add(&v[0], &v[1], &v[0]);
        Vec3Sub(q, &v[1], &v[2]);
        v[3] = *q;
        Vec3Add(q, &v[0], &v[4]);
        v[5] = *p->mUnk_168.mUnk_00->mUnk_18;
        func_020f4020(&p->mUnk_170, &v[2], p->mUnk_000.mUnk_12c);
        return TRUE;
    }
    return FALSE;
}

void func_020ece1c(Unk020ec8bc *p, s32 a, s32 b, s32 c) {
    Vec3 v;
    Vec3 *q;
    Vec3 *r;
    Vec3 *w;
    s32 n;
    s32 s;

    func_020f2228(&p->mUnk_000, a);
    if (p->mUnk_000.mUnk_158 != 0 && (p->mUnk_000.mUnk_000.mUnk_74 & 0x20000) != 0) {
        n = func_0207a974((u16) (p->mUnk_000.mUnk_000.mUnk_78 & ~0xff00))->mUnk_98.y + 0x1e000;
        if (p->mUnk_000.mUnk_000.mUnk_50.y < n) {
            p->mUnk_000.mUnk_000.mUnk_50.y = n;
        }
    }
    if (p->mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    if (p->mUnk_000.mUnk_158 == 0) {
        if (p->mUnk_000.mUnk_000.mUnk_74 & 0x20000) {
            return;
        }
    }
    q = &p->mUnk_000.mUnk_130;
    r = &p->mUnk_000.mUnk_13c;
    if (func_020f3bb4(&p->mUnk_21c, &p->mUnk_168, &p->mUnk_21c, &p->mUnk_000.mUnk_000.mUnk_50) != 0) {
        func_020f371c(&p->mUnk_21c, &p->mUnk_168, b, c);
    }
    Vec3Sub(p->mUnk_168.mUnk_00->mUnk_18, &p->mUnk_000.mUnk_000.mUnk_50, &v);
    if (p->mUnk_000.mUnk_000.mUnk_74 & 0x40000000) {
        s = Vec3Dot(r, &v);
        v.x -= (s32) (((u64) ((s64) r->x * s)) >> 12);
        v.y -= (s32) (((u64) ((s64) r->y * s)) >> 12);
        v.z -= (s32) (((u64) ((s64) r->z * s)) >> 12);
        s = Vec3Dot(&p->mUnk_000.mUnk_000.mUnk_f0, &v);
        v.x -= (s32) (((u64) ((s64) p->mUnk_000.mUnk_000.mUnk_f0.x * s)) >> 12);
        v.y -= (s32) (((u64) ((s64) p->mUnk_000.mUnk_000.mUnk_f0.y * s)) >> 12);
        v.z -= (s32) (((u64) ((s64) p->mUnk_000.mUnk_000.mUnk_f0.z * s)) >> 12);
        Vec3AddScaled(0x29, &v, &p->mUnk_000.mUnk_000.mUnk_50, &p->mUnk_000.mUnk_000.mUnk_50);
        Vec3AddScaled(0x3, &v, r, r);
        return;
    }
    if (func_02039828(r, &v) < 0) {
        w = &p->mUnk_000.mUnk_148;
        func_020397a8(r, &p->mUnk_000.mUnk_000.mUnk_f0, w);
        if (func_02039828(w, &v) > 0) {
            v = *w;
        } else {
            v.x = -w->x;
            v.y = -w->y;
            v.z = -w->z;
        }
        p->mUnk_224 = 1;
    }
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
        func_02039860(&v, &v);
    }
    s = 0x1000 - p->mUnk_214 * p->mUnk_218;
    n = (p->mUnk_224 != 0) ? 0x266 : 0x148;
    func_020eacc0(q, (s32) (((u64) ((s64) n * s)) >> 12), &v, &v);
    func_020f1d70(p, &v);
}

void func_020ec9c0(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 e) {
    Unk020f3fa8 *t;
    Vec3 *q;
    Vec3 *r;
    Vec3 v28;
    Vec3 v34;
    Vec3 v40;
    Vec3 v4c;
    s32 s;
    BOOL f;
    s32 w;

    t = &p->mUnk_170;
    q = &p->mUnk_000.mUnk_000.mUnk_50;
    r = &p->mUnk_000.mUnk_000.mUnk_5c;
    f = (p->mUnk_000.mUnk_000.mUnk_74 & 0x40000000) != 0;
    a -= p->mUnk_000.mUnk_12c;
    p->mUnk_000.mUnk_12c = p->mUnk_000.mUnk_12c + (s32) (((u64) ((s64) a * b)) >> 12);
    func_020d84c0(&t->mUnk_00, p->mUnk_000.mUnk_12c);
    if (func_020d849c(&t->mUnk_00) != 0) {
        do {
            p->mUnk_21c = p->mUnk_168;
            func_020f371c(&p->mUnk_21c, &p->mUnk_168, c, e);
        } while (func_020f3fa8(t, p->mUnk_168.mUnk_00->mUnk_18) != 0);
    }
    if (f) {
        v4c = *q;
        func_020d8488((u32) t, (u32) q);
        r->y = 0;
        if (p->mUnk_000.mUnk_158 == 0) {
            Vec3Sub(q, &v4c, &v4c);
            w = func_02039828(&v4c, &p->mUnk_000.mUnk_000.mUnk_f0);
            if (w > 0) {
                Vec3AddScaled(-w, &p->mUnk_000.mUnk_000.mUnk_f0, q, q);
            }
        }
    } else {
        if (p->mUnk_000.mUnk_158 != 0 && (p->mUnk_000.mUnk_000.mUnk_74 & 0x20000) != 0) {
            v28.y = q->y;
            func_020d8460(t, q);
            if (q->y < v28.y) {
                q->y = v28.y;
            }
        } else {
            func_020d8474(&t->mUnk_00, q);
        }
        q->y = q->y + r->y;
    }
    if (func_01ffdee4(q, &p->mUnk_000.mUnk_000.mUnk_0e4, 0, p->mUnk_000.mUnk_000.mUnk_dc, 4,
                      p->mUnk_000.mUnk_000.mUnk_da, &v28, &v34, (s32 *) &v40, &p->mUnk_000.mUnk_000.mUnk_fc, NULL, NULL,
                      NULL, NULL) != 0) {
        if (p->mUnk_000.mUnk_158 != 0) {
            if (v28.y > 0) {
                q->y = q->y + v28.y;
            }
        } else {
            Vec3Add(&v28, q, q);
        }
        if (p->mUnk_000.mUnk_000.mUnk_fc & 0x1e34ef) {
            s = Vec3Dot(&v34, r);
            r->x -= (s32) (((u64) ((s64) v34.x * s)) >> 12);
            r->y -= (s32) (((u64) ((s64) v34.y * s)) >> 12);
            r->z -= (s32) (((u64) ((s64) v34.z * s)) >> 12);
            s = (v34.x == p->mUnk_000.mUnk_000.mUnk_f0.x && v34.y == p->mUnk_000.mUnk_000.mUnk_f0.y &&
                 v34.z == p->mUnk_000.mUnk_000.mUnk_f0.z)
                    ? 1
                    : 0;
            if (s == 0) {
                p->mUnk_000.mUnk_000.mUnk_f0 = v34;
                p->mUnk_000.mUnk_000.mUnk_74 |= 0x100;
            }
        }
        if ((p->mUnk_000.mUnk_000.mUnk_fc & 0x214300) != 0 && p->mUnk_000.mUnk_15c != 0) {
            s = Vec3Dot(&v40, r);
            v28.x = (s32) (((u64) ((s64) v40.x * s)) >> 12);
            v28.y = (s32) (((u64) ((s64) v40.y * s)) >> 12);
            v28.z = (s32) (((u64) ((s64) v40.z * s)) >> 12);
            r->x -= v28.x;
            r->y -= v28.y;
            r->z -= v28.z;
            Vec3Sub(r, &v28, r);
            r->x = (s32) (((u64) ((s64) r->x * 0x23d)) >> 12);
            r->y = (s32) (((u64) ((s64) r->y * 0x23d)) >> 12);
            r->z = (s32) (((u64) ((s64) r->z * 0x23d)) >> 12);
            func_020f6fc4(p, 1);
            return;
        }
        if (p->mUnk_000.mUnk_000.mUnk_fc & 0x8000) {
            if (p->mUnk_000.mUnk_000.mUnk_44 != 5) {
                func_020f7070(p, 1);
                return;
            }
        }
    }
    func_020f2150(p);
    r->x = q->x - p->mUnk_000.mUnk_000.mUnk_0e4.x;
    r->z = q->z - p->mUnk_000.mUnk_000.mUnk_0e4.z;
}

void func_020ec918(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 d) {
    if (p->mUnk_214 >= 0) {
        func_020ece1c(p, a, c, d);
        if (p->mUnk_214 == 0) {
            if (func_020ed0f4(p) != FALSE) {
                p->mUnk_214 = -1;
            }
            return;
        }
        if (p->mUnk_000.mUnk_000.mUnk_74 & 0x40020000) {
            if (p->mUnk_000.mUnk_158 == 0) {
                return;
            }
        }
        p->mUnk_214 -= 1;
    } else {
        func_020ec9c0(p, a, b, c, d);
    }
}

void func_020ec8bc(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, s32 g) {
    func_020f1ea4(p, (d == 0) ? -1 : 0, e, c);
    p->mUnk_214 = a;
    p->mUnk_218 = b;
    func_020f371c(&p->mUnk_21c, &p->mUnk_168, f, g);
    p->mUnk_224 = 0;
}
