#include "Main/Unknown/code_02086098.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_0214a4dc.h"
#include "Main/Unknown/code_0203c598.h"
#include "Main/Unknown/code_02087228.h"
#include "Main/Unknown/code_02087934.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02076cc4.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_020d50e0.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02087918.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217c000.h"

void func_02086a04(void) {
    Vec3 v24;
    Vec3 v30;
    s32 i;
    Unk0217b4f8 *q;
    Unk0206bcb0_590 *s;
    s32 k;
    u32 e;
    Unk0206bcb0 *p;
    BOOL g;
    s32 d;
    s32 h;
    BOOL a;
    BOOL b;
    u16 n;
    s32 j;
    q = func_020d50e0();
    for (i = 0; i < data_021759c0->mKartCount; i++) {
        func_0207a974(i);
        data_0217aed0->mUnk_0e4[i] = 0;
        p = func_0207a974(i);
        k = p->mUnk_1d0 * 3;
        s = p->mKartModelsEntry;
        Vec3Sub(p->mUnk_508, &q->mUnk_08, &v30);
        d = Vec3Dot(&v30, &q->mUnk_14);
        data_0217aed0->mUnk_104[i] = d + k;
        data_0217aed0->mUnk_074[p->mIndex] = data_0217aed0->mUnk_024[p->mIndex] + data_0217aed0->mUnk_034[p->mIndex];
        data_0217aed0->mUnk_054[data_0217aed0->mUnk_074[p->mIndex]] = d;
        Vec3Sub(p->mUnk_508, &q->mUnk_08, &v24);
        v24.x = v24.x >> 12;
        v24.y = v24.y >> 12;
        v24.z = v24.z >> 12;
        e = v24.x * v24.x + v24.y * v24.y + v24.z * v24.z;
        data_0217aed0->mUnk_124[i] = e;
        data_0217aed0->mUnk_0a4[(u16) (data_0217aed0->mUnk_024[p->mIndex] + data_0217aed0->mUnk_084[p->mIndex])] = e;
        if (p->mIndex != data_021759c0->mUnk_62) {
            a = TRUE;
            if (e > data_0217ca6c[0].mUnk_20) {
                a = FALSE;
            }
            if (p->mUnk_00.mUnk_34 & 1) {
                b = TRUE;
            } else {
                b = FALSE;
            }
            if ((a != FALSE && b == FALSE) || (a == FALSE && b != FALSE)) {
                func_0210cfbc(&p->mUnk_00, 2, 1);
            }
            if (d < 0) {
                s->mUnk_058 = s->mUnk_05c = s->mUnk_060 = 1;
                s->mUnk_01c->mUnk_70 &= ~1;
                p->mUnk_4c |= 0x800000;
            } else {
                g = FALSE;
                h = k >> 12;
                if (Vec3Dot(&v24, &q->mUnk_20) - h > 0) {
                    g = TRUE;
                } else if (Vec3Dot(&v24, &q->mUnk_2c) - h > 0) {
                    g = TRUE;
                }
                if (g != FALSE) {
                    p->mUnk_4c |= 0x800000;
                } else {
                    p->mUnk_4c &= ~0x800000;
                    s->mUnk_058 = s->mUnk_05c = s->mUnk_060 = 0;
                    s->mUnk_01c->mUnk_70 |= 1;
                    if (e > data_0217aed8->z) {
                        p->mUnk_4c |= 0x800000;
                        s->mUnk_058 = s->mUnk_05c = s->mUnk_060 = 1;
                        s->mUnk_01c->mUnk_70 &= ~1;
                    } else if (e > data_0217aed8->y) {
                        s->mUnk_058 = s->mUnk_060 = 1;
                        s->mUnk_01c->mUnk_70 &= ~1;
                    } else if (e > data_0217aed8->x) {
                        s->mUnk_060 = 1;
                        s->mUnk_01c->mUnk_70 &= ~1;
                    }
                }
            }
        }
    }
    if (func_02061818() != 3) {
        n = 0;
        for (j = data_0217aed0->mUnk_074[data_021759c0->mUnk_62] + 1; j < data_021759c0->mKartCount; j++) {
            Unk02086250 *t;
            t = data_0217aed0->mUnk_000[data_0217aed0->mUnk_044[j]];
            if (t != NULL) {
                if (n >= 2) {
                    data_0217aed0->mUnk_0e4[t->mUnk_0c] = 1;
                }
                n++;
            }
        }
    } else {
        n = 0;
        for (j = 0; j < data_021759c0->mKartCount; j++) {
            Unk02086250 *t;
            t = data_0217aed0->mUnk_000[data_0217aed0->mUnk_044[j]];
            if (t != NULL) {
                if (data_0217aed0->mUnk_054[data_0217aed0->mUnk_074[t->mUnk_0c]] >= 0) {
                    if (n >= 2) {
                        data_0217aed0->mUnk_0e4[t->mUnk_0c] = 1;
                    }
                    n++;
                }
            }
        }
    }
}

void func_0208677c(void) {
    Vec3 v;
    s32 i;
    s32 x;
    s32 r;
    Unk02086250 *p;
    Vec3 *w;
    Unk0206bcb0 *m;
    if (func_02061818() == 0) {
        data_0217aed8 = &data_02155a3c;
    } else {
        data_0217aed8 = &data_02155a48;
    }
    func_02086a04();
    i = 0;
    while (i < data_0217aed0->mUnk_020) {
        p = data_0217aed0->mUnk_0c4[i];
        m = func_0207a974(p->mUnk_0c);
        w = m->mUnk_508;
        v = *w;
        x = data_0217aed0->mUnk_104[p->mUnk_0c];
        r = 0x1000;
        if (x > 0) {
            if (data_0217aed0->mUnk_124[p->mUnk_0c] < 0x9c400 || func_02061818() == 3) {
                x -= 0x14000;
                p->mUnk_20 = 1;
                p->mUnk_14 = 1;
                if (x < 0) {
                    x = 0;
                }
                r = (s32) (((s64) x * 0x44 + 0x800) >> 12);
            } else {
                p->mUnk_20 = -1;
                p->mUnk_14 = 2;
            }
        }
        if (data_0217aed0->mUnk_0e4[p->mUnk_0c] != 0 || (func_0207a974(p->mUnk_0c)->mUnk_7c & 0x402020) != 0 ||
            (func_020738f8(w->y - func_0207a974(data_021759c0->mUnk_62)->mUnk_80.y) > 0x96000 &&
             func_02061818() != 3)) {
            p->mUnk_20 = -1;
        }
        if (p->mUnk_18 != 0) {
            if (func_0203c598() - 0x3c > 0) {
                p->mUnk_18 = 0;
            }
        } else if (p->mUnk_20 != 0) {
            p->mUnk_22 = p->mUnk_22 + p->mUnk_20;
            if (p->mUnk_22 > 0x1e) {
                p->mUnk_22 = 0x1e;
                p->mUnk_20 = 0;
            } else if (p->mUnk_22 < 0) {
                p->mUnk_22 = 0;
                p->mUnk_20 = 0;
            }
        }
        if (r >= 0x1000) {
            p->mUnk_24 = p->mUnk_22;
        } else {
            p->mUnk_24 = (s32) (((s64) p->mUnk_22 * r + 0x800) >> 12);
        }
        v.y += 0xf000;
        p->mUnk_00.x = v.x >> 4;
        p->mUnk_00.y = v.y >> 4;
        p->mUnk_00.z = v.z >> 4;
        i += 1;
    }
    func_020866b4();
    func_020865ec();
}

// non-matching: 3 instructions longer: the original keeps the previous index in r8 and the scaled indexes in r5 and r7,
// pushes six registers and needs no stack alignment word; here one register fewer is used and 4 bytes of stack are
// allocated.
void func_020866b4(void) {
    s32 *a;
    u16 *p;
    s16 *q;
    u16 i;
    s32 j;
    s32 x;
    s32 y;
    u16 u;
    a = data_0217aed0->mUnk_054;
    for (i = 1; (u32) i < data_021759c0->mKartCount; i++) {
        j = i - 1;
        x = a[j];
        y = a[i];
        if (x > y) {
            a[j] = y;
            a[i] = x;
            p = data_0217aed0->mUnk_044;
            q = data_0217aed0->mUnk_034;
            q[p[i]]--;
            q[p[j]]++;
            u = p[i];
            p[i] = p[j];
            p[j] = u;
        }
    }
}

void func_020865ec(void) {
    u16 *p;
    s16 *q;
    u16 i;
    u32 *a;
    s32 j;
    u32 x;
    u32 y;
    u16 u;
    a = data_0217aed0->mUnk_0a4;
    for (i = 1; (u32) i < data_021759c0->mKartCount; i++) {
        j = i - 1;
        x = a[j];
        y = a[i];
        if (x > y) {
            p = data_0217aed0->mUnk_094;
            q = data_0217aed0->mUnk_084;
            a[j] = y;
            a[i] = x;
            q[p[i]]--;
            q[p[j]]++;
            u = p[i];
            p[i] = p[j];
            p[j] = u;
        }
    }
}

void func_02086250(Unk02012f58 *a) {
    s32 i;
    s16 h;
    s32 u;
    s32 t;
    s32 z;
    Vec3 v;
    Unk02012f58 *m;
    Unk02086250 *p;
    BOOL f;
    if (func_02061818() != 0 && func_02061818() != 3) {
        return;
    }
    *(u16 *) 0x4000060 = (*(u16 *) 0x4000060 & ~0x3000) | 8;
    *(u32 *) 0x40004c4 = 0x4210;
    *(u32 *) 0x40004c0 = 0x42100000;
    *(u32 *) 0x4000440 = 0;
    func_0214a530(&data_0217aee0);
    *(u32 *) 0x4000440 = 3;
    *(u32 *) 0x4000454 = 0;
    for (i = data_021759c0->mKartCount - 1; i >= 0; i--) {
        p = data_0217aed0->mUnk_000[data_0217aed0->mUnk_044[i]];
        if (p == NULL) {
            continue;
        }
        if (data_0217aed0->mUnk_054[i] <= 0) {
            continue;
        }
        h = p->mUnk_24;
        if (h == 0) {
            continue;
        }
        if ((func_0207a974(data_0217aed0->mUnk_044[i])->mUnk_7c & 0xe0) != 0) {
            continue;
        }
        Vec3MultiplyMatrix4x3(&p->mUnk_00, a, &v);
        if (v.z >= 0) {
            f = FALSE;
        } else {
            m = func_02076cc4();
            t = (s32) (((s64) v.x * m->mUnk_00[0].x + (s64) v.z * m->mUnk_00[2].z) >> 12);
            u = (s32) (((s64) v.y * m->mUnk_00[1].z + (s64) v.z * m->mUnk_00[3].x) >> 12);
            z = -((const Vec3 *) &v)->z;
            t = DivFixed12(t, z);
            u = DivFixed12(u, z);
            t = (s32) ((((s64) t << 19) + 0x800) >> 12);
            u = (s32) (((s64) u * 0x60000 + 0x800) >> 12);
            f = TRUE;
        }
        if (f == FALSE) {
            continue;
        }
        if (p->mUnk_1c->mUnk_00[3].mUnk_0c != NULL) {
            func_02086098(&p->mUnk_1c->mUnk_00[3], p, a, data_021659a8, data_021659a0, h, t, u, data_021659bc,
                          data_021659b0, func_02087ab0);
        }
        func_02086098(&p->mUnk_1c->mUnk_00[2], p, a, data_021659cc, 0x9000, h, t, u, data_021659d0, 0, func_0208784c);
        func_02086098(&p->mUnk_1c->mUnk_00[1], p, a, 0x21000, 0xa000, h, t, u, data_021659a4, 0x199a, func_02087ab0);
        func_02086098(&p->mUnk_1c->mUnk_00[0], p, a, data_021659c8, data_021659c4, h, t, u, data_021659ac,
                      data_021659b8, func_02087918);
    }
}

static inline s32 func_02086098_inline(Unk02086250 *b) {
    return ((u16) b->mUnk_0c + 11) << 24;
}

void func_02086098(Unk02086098 *a, Unk02086250 *b, Unk02012f58 *c, s32 d, s32 e, s16 f, s32 g, s32 h, s32 i, s32 j,
                   UnkFunc *k) {
    Unk02012f58 m;
    s32 x;
    s32 y;
    s32 z;
    *(u32 *) 0x40004a8 = a->mUnk_00;
    if (a->mUnk_08 != 0) {
        *(u32 *) 0x40004ac = a->mUnk_18 >> (4 - ((a->mUnk_00 >> 26 & 7) == 2));
    }
    func_021471bc(&m);
    m.mUnk_00[3] = b->mUnk_00;
    func_0214733c(&m, c, &m);
    m.mUnk_00[3].x = g;
    if (b->mUnk_10 == 1) {
        m.mUnk_00[3].x = g + ((s32) (((s64) i * d + 0x800) >> 12) + 0x1e000);
    }
    m.mUnk_00[3].y = 0x5000 + h + (s32) (((s64) j * e + 0x800) >> 12);
    m.mUnk_00[3].z = 0;
    x = a->mUnk_1c;
    y = a->mUnk_20;
    m.mUnk_00[1].y = e;
    m.mUnk_00[0].x = d;
    m.mUnk_00[0].y = 0;
    m.mUnk_00[0].z = 0;
    m.mUnk_00[1].x = 0;
    m.mUnk_00[1].z = 0;
    m.mUnk_00[2].z = 0;
    m.mUnk_00[2].y = 0;
    m.mUnk_00[2].x = 0;
    *(u32 *) 0x40004a4 = (func_02086098_inline(b) | 0xc0) | (f << 16);
    *(u32 *) 0x4000440 = 2;
    func_0214a514(&m);
    *(u32 *) 0x4000500 = 1;
    *(u32 *) 0x4000480 = 0x7fff;
    k(x, y, b->mUnk_26);
    *(u32 *) 0x4000504 = 0;
}
