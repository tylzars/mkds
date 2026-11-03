#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02042410.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_0200f5ac.h"

Unk02175620_bc *func_02040da8(u32 a) {
    return &gCourseMap->mUnk_b8[gCourseMap->mUnk_34[gCourseMap->mUnk_fc[a]].mUnk_18];
}

s32 func_02040d68(const UnkPair020b502c *a, const UnkPair020b502c *b) {
    return (s32) (((s64) a->mUnk_00 * b->mUnk_00 + (s64) a->mUnk_04 * b->mUnk_04 + 0x800) >> 12);
}

s64 func_02040d24(const UnkPair020b502c *a, const UnkPair020b502c *b) {
    return ((s64) a->mUnk_00 * b->mUnk_00 + (s64) a->mUnk_04 * b->mUnk_04 + 0x800) >> 12;
}

static inline s32 func_02040bc0_inline(s8 i) {
    BOOL f = FALSE;
    if ((u32) data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_00 <= 3 &&
        ((1 << data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_00) & 0xd) != 0) {
        f = TRUE;
    }
    return f;
}

s32 func_02040bc0(void) {
    BOOL r = FALSE;
    BOOL g;
    s8 i = data_021759c0->mUnk_62;

    if (i == -1 || func_02040bc0_inline(i) == 0) {
        r = TRUE;
    }
    if (r != FALSE) {
        return r;
    }
    switch (data_021759c0->mUnk_08) {
        case 4:
            g = FALSE;
            switch (data_0217561c->mUnk_000[(u16) i].mUnk_14) {
                case 1:
                case 2:
                case 3:
                    g = TRUE;
                    break;
            }
            if (g == FALSE) {
                if (data_0217561c->mUnk_4e0 != 0) {
                    return r;
                }
            }
            return 1;
        case 2:
            if (data_0217561c->mUnk_4cc != 0) {
                r = TRUE;
            }
            return r;
        default:
            g = FALSE;
            switch (data_0217561c->mUnk_000[(u16) i].mUnk_14) {
                case 1:
                case 2:
                case 3:
                    g = TRUE;
                    break;
            }
            if (g != FALSE) {
                r = TRUE;
            }
            return r;
    }
}

void func_02040a8c(Unk0217561c_500 *a, s32 b) {
    Unk0206cdd4_B *t = func_0207a6b0();
    Unk0217561c *d = data_0217561c;
    Unk0217561c_14 *e = &d->mUnk_14[b];
    Unk0217561c_4c8 *r = d->mUnk_4c8;

    if (d->mUnk_000[0].mUnk_0c == 0) {
        a->mUnk_00 = 0;
    } else {
        a->mUnk_00 =
            (func_02147f34(r->mUnk_0a * (d->mUnk_000[0].mUnk_0c - d->mUnk_000[0].mUnk_00), d->mUnk_000[0].mUnk_0c) +
             0x800) >>
            12;
    }
    a->mUnk_04 = (r->mUnk_0c * func_02147f34(e->mUnk_28 << 12, data_0217561c->mUnk_000[0].mUnk_0c << 12)) >> 12;
    if (t->mUnk_00 != 0) {
        a->mUnk_08 = r->mUnk_0e;
    } else {
        a->mUnk_08 = 0;
    }
    a->mUnk_0c = r->mUnk_10 * t->mUnk_04;
    a->mUnk_10 = r->mUnk_12 * t->mUnk_08;
    a->mUnk_14 = -((u32) (t->mUnk_0c * func_02147f18(r->mUnk_14 << 12)) >> 12);
    a->mUnk_18 = t->mUnk_10 * -r->mUnk_16;
    a->mUnk_1c = t->mUnk_14 * -r->mUnk_18;
    a->mUnk_20 = t->mUnk_18 * -r->mUnk_1a;
}

s16 func_020408f0(s32 a) {
    Unk0217561c_500 b;
    Unk0206cdd4_B *t;
    Unk021759c0 *g;
    Unk0217561c *d = data_0217561c;
    Unk0217561c_500 *o = &d->mUnk_500;
    s32 s;
    u8 *h;

    if ((d->mUnk_000[a].mUnk_44 & 1) == 0) {
        return 0;
    }
    g = data_021759c0;
    switch (g->mUnk_08) {
        case 0:
            func_02040a8c(&b, a);
            break;
        case 4:
            h = (u8 *) g + 0x28;
            t = func_0207a6b0();
            b.mUnk_00 =
                func_02147f34(*(s16 *) (h + 4) * (*(u16 *) (h + 2) - d->mUnk_000[0].mUnk_00) << 12, 0x3e8000) >> 12;
            b.mUnk_04 = 0;
            b.mUnk_08 = 0;
            b.mUnk_0c = 0;
            b.mUnk_10 = t->mUnk_08 * -5;
            b.mUnk_14 = 0;
            b.mUnk_18 = t->mUnk_10 * -5;
            b.mUnk_1c = t->mUnk_14 * -10;
            b.mUnk_20 = t->mUnk_18 * -20;
            break;
        default:
            return 0;
    }
    *o = b;
    s = o->mUnk_00 + o->mUnk_04 + o->mUnk_08 + o->mUnk_0c + o->mUnk_10 + o->mUnk_14 + o->mUnk_18 + o->mUnk_1c +
        o->mUnk_20;
    if (s < -9999) {
        s = -9999;
    }
    if (s > 9999) {
        s = 9999;
    }
    return (s16) s;
}

void func_02040750(Unk0217561c_14 *a, s32 b) {
    s32 i;
    Unk0217aa1c_144_00 *p;
    Unk02175620_4c *e;
    s32 m;

    if (gCourseMap->mUnk_44 == NULL) {
        a->mUnk_38 = 0;
        a->mUnk_32 = 0;
    } else {
        a->mUnk_38 = gCourseMap->mUnk_4c->mUnk_07;
        e = &gCourseMap->mUnk_4c[a->mUnk_38];
        m = gCourseMap->mUnk_4c[a->mUnk_38].mUnk_00;
        a->mUnk_32 = m + e->mUnk_02 - 1;
    }
    a->mUnk_04 = 0;
    a->mUnk_08 = 0;
    a->mUnk_2c = 0;
    a->mUnk_3a = 1;
    a->mUnk_24 = 0;
    a->mUnk_00 = 0;
    a->mUnk_30 = 0;
    a->mUnk_34 = gCourseMap->mUnk_98 - 1;
    a->mUnk_36 = gCourseMap->mUnk_98 - 1;
    a->mUnk_3c = (a->mUnk_3c & ~0xf0) | (((u16) b & 0xf) << 4);
    a->mUnk_44 = 0;
    a->mUnk_48 = 0;
    a->mUnk_3e = 0;
    a->mUnk_28 = 0;
    a->mUnk_40 = 0;
    a->mUnk_3c = a->mUnk_3c & ~0x300;
    p = a->mUnk_0c;
    for (i = 0; i < 5; i++) {
        func_0203f5f0(&p->mUnk_02, &p->mUnk_03, &p->mUnk_00, 0, data_0217561c->mUnk_000[0].mUnk_00);
        p++;
    }
    func_0203f5f0(&a->mUnk_0c[5].mUnk_02, &a->mUnk_0c[5].mUnk_03, &a->mUnk_0c[5].mUnk_00, 0,
                  data_0217561c->mUnk_000[0].mUnk_00);
    if (b == data_021759c0->mUnk_62) {
        a->mUnk_30 = a->mUnk_30 | 1;
    }
    a->mUnk_3c = (a->mUnk_3c & ~0xf) | ((u16) (b + 1) & 0xf);
}

static inline u32 func_020401ac_inline(Unk0217aa00 *p) {
    return p == NULL ? 0 : p->mUnk_0000;
}

static inline void func_020401ac_inline2(Unk0217561c_000 *q) {
    q->mUnk_00 = 0;
    q->mUnk_04 = 0;
}

static inline void func_020401ac_inline3(Unk0217aa1c_144_00 *p, u32 e) {
    func_0203f5f0(&p->mUnk_02, &p->mUnk_03, &p->mUnk_00, 0, e);
}

static inline void func_020401ac_inline4(Unk020f41c4_B *x, u32 s) {
    x->mUnk_00 = s;
    x->mUnk_08 = 0x5d588b656c078965;
    x->mUnk_10 = 0x269ec3;
}

static inline s32 func_020401ac_inline5(s32 a, s32 b) {
    return b == 0 ? 0 : func_02147f34(a + 0x1000, b << 12);
}

static inline u32 func_020401ac_inline6(Unk020f41c4_B *x, u32 n) {
    x->mUnk_00 = (s64) x->mUnk_08 * (s64) x->mUnk_00 + x->mUnk_10;
    return ((s64) (x->mUnk_00 >> 32) * n) >> 32;
}

void func_020401ac(void) {
    BOOL f;
    s32 i;
    u32 s;
    s32 v1;
    u64 a;
    u64 c;
    u64 d;
    u16 j;
    u16 k;
    u16 v2;
    s32 v;
    Unk0217aa00 *p;
    Unk02175620_4c *e;
    Unk02175620_44 *q;

    func_020401ac_inline2(&data_0217561c->mUnk_000[0]);
    func_020401ac_inline3(&data_0217561c->mUnk_000[0].mUnk_08_view, data_0217561c->mUnk_000[0].mUnk_00);
    f = FALSE;
    data_0217561c->mUnk_000[0].mUnk_0e = 0;
    data_0217561c->mUnk_000[0].mUnk_10 = 0;
    data_0217561c->mUnk_4cc = 0;
    switch (data_021759c0->mUnk_00c) {
        case 1:
        case 2:
        case 6:
            f = TRUE;
            break;
        case 0:
            if (func_02040bc0() != 0) {
                f = TRUE;
            }
            break;
    }
    data_0217561c->mUnk_4f0 = f;
    data_0217561c->mUnk_4e0 = 6;
    data_0217561c->mUnk_4ec = 0;
    data_0217561c->mUnk_4f4 = 0;
    switch (data_021759c0->mUnk_08) {
        case 4:
            if (data_021759c0->mUnk_2f == 6) {
                data_0217561c->mUnk_4ec = 0;
            } else {
                data_0217561c->mUnk_4ec = 1;
            }
            data_0217561c->mUnk_4f4 = data_021759c0->mUnk_028;
            break;
        case 2:
            if (data_021759c0->mUnk_18 == 1) {
                data_0217561c->mUnk_4ec = 1;
                data_0217561c->mUnk_4f4 = gCourseMap->mUnk_018->mUnk_02 * 0x3c;
            }
            break;
    }
    for (i = 0; i < 8; i++) {
        func_02040750(&data_0217561c->mUnk_14[i], i);
        data_0217561c->mUnk_474[i] = -1;
    }
    switch (data_021759c0->mUnk_00c) {
        case 2:
            s = data_021759c0->mUnk_05c;
            break;
        case 5:
            s = 0xc240793;
            break;
        case 6:
            s = 0x71abc95;
            break;
        default:
            switch (data_021759c0->mUnk_08) {
                case 1:
                    s = 0x34a8f71;
                    break;
                case 4:
                    s = 0x158b76f;
                    break;
                case 5:
                    s = 0x5b12f73;
                    break;
                default:
                    p = data_0217aa00;
                    v = 0;
                    if (func_020401ac_inline(p) != 0) {
                        if (p->mUnk_0004 != 0xd) {
                            v = 1;
                        }
                    }
                    if (v != 0) {
                        s = p->mUnk_1eb0;
                    } else {
                        a = func_0200f5ac();
                        s = (a << 16) + func_0200f5ac();
                    }
                    break;
            }
            break;
    }
    func_020401ac_inline4(&data_0217561c->mUnk_47c, s);
    data_0217561c->mUnk_494 = s;
    data_021759c0->mUnk_1e8.mUnk_5c = s;
    a = func_0200f5ac();
    c = func_0200f5ac();
    d = func_0200f5ac();
    func_020401ac_inline4(&data_0217561c->mUnk_498, a + ((c << 24) + (d << 8)));
    func_020401ac_inline4(&data_0217561c->mUnk_4b0, 0xa094a2f);
    if (data_021759c0->mUnk_08 == 2) {
        func_020427d4(&data_0217561c->mUnk_47c);
    }
    data_0217561c->mUnk_4d0 = 0;
    data_0217561c->mUnk_4e4 = func_02147f18((gCourseMap->mUnk_9c + 1) << 12);
    data_0217561c->mUnk_4e8 = func_02147f18(func_02044618() << 12);
    for (i = 0; i < gCourseMap->mUnk_98 + 1; i++) {
        v1 = i % (gCourseMap->mUnk_98 + 1);
        if (v1 == gCourseMap->mUnk_98) {
            data_0217561c->mUnk_4d4[i] = 0x1000;
        } else {
            for (j = 0; j < gCourseMap->mUnk_50; j++) {
                e = &gCourseMap->mUnk_4c[j];
                for (k = 0; k < e->mUnk_02; k++) {
                    v2 = k + e->mUnk_00;
                    q = &gCourseMap->mUnk_44[v2];
                    if (q->mUnk_20 == v1) {
                        v = func_020401ac_inline5((v2 - e->mUnk_00) << 12, e->mUnk_02);
                        v += e->mUnk_0a << 12;
                        data_0217561c->mUnk_4d4[i] = ((s64) v * data_0217561c->mUnk_4e4 + 0x800) >> 12;
                    }
                }
            }
        }
    }
    if (data_021759c0->mUnk_08 != 2) {
        data_0217561c->mUnk_4f8 = 0;
        return;
    }
    data_0217561c->mUnk_4f8 = func_020401ac_inline6(&data_0217561c->mUnk_47c, 8);
}
