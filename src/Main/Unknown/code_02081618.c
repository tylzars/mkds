#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f36d8.h"

void func_02081d78(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;
    Vec3 *v;
    Unk0206bcb0 *q;
    s32 x;
    s32 y;
    s32 z;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    q = func_0207a974(i);
    v = q->mUnk_508;
    x = v->x;
    y = v->y;
    z = v->z;
    p->mUnk_28.x = (x >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (y >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (z >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_40 = q->mUnk_3b0;
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
}

void func_02081ca0(Unk0201ca6c *p, Unk0206bcb0 *q, void *a) {
    u32 r;
    u32 f;

    if (a == 0) {
        func_02081b64(p, q, 0x733, 0xb33);
        p->mUnk_5c = (s16) (((s64) q->mUnk_bc.z * 0xb33 + 0x800) >> 12);
    } else {
        r = 1;
        func_02081b64(p, q, 0x99a, 0xe66);
        p->mUnk_6c = (s16) q->mUnk_bc.z;
        f = q->mUnk_7c;
        if (!(f & 1)) {
            if (f & 0x402000) {
                r = 0;
            }
        }
        p->mUnk_24.mUnk_00_3 = (r == 0);
    }
}

void func_02081b64(Unk0201ca6c *p, Unk0206bcb0 *q, s32 a, s32 b) {
    Vec3 v;
    Vec3 w;
    Unk02148038 h;
    Vec3 *s = q->mUnk_508;

    v.x = s->x >> 4;
    v.y = s->y >> 4;
    v.z = s->z >> 4;
    func_02147fd8((s32) (((s64) q->mUnk_bc.z * b + 0x800) >> 12), &q->mUnk_138, &v, &v);
    func_02147fd8((s32) (((s64) q->mUnk_bc.y * a + 0x800) >> 12), &q->mUnk_12c, &v, &v);
    p->mUnk_28.x = v.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = v.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = v.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    func_02063b10(q, &w);
    w.x = -w.x;
    w.y = -w.y;
    w.z = -w.z;
    h.mUnk_00 = w.x;
    h.mUnk_02 = w.y;
    h.mUnk_04 = w.z;
    p->mUnk_50 = h;
}

void func_02081b30(Unk0201ca6c *p, s32 a) {
    if (a != 0) {
        return;
    }
    func_02081ca0(p, func_0207a974(p->mUnk_98_24), p->mUnk_94);
}

void func_02081ab8(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    func_02081ca0(p, func_0207a974(i), p->mUnk_94);
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
        if (e->mUnk_00[i] != 0) {
            func_0208b710(e->mUnk_00[i]);
        }
        e->mUnk_00[i] = func_0208b7bc(data_02165978[i], &func_0207a974(a)->mUnk_1d8);
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
    Unk0206bcb0 *q;
    Vec3 w;
    Vec3 v;

    q = func_0207a974(a);
    y = (s16) func_0208181c_inline(data_0216593c + func_0208181c_inline(q->mUnk_2a0, data_02165950 - data_0216593c),
                                   data_02165948);
    x = (s16) func_0208181c_inline(data_02165944 + func_0208181c_inline(q->mUnk_2a0, data_0216594c - data_02165944),
                                   data_02165948);
    i = 0;
    do {
        if (e->mUnk_00[i] != 0) {
            func_02147fd8((s32) (((s64) q->mUnk_bc.y * data_02155854[q->mUnk_590->mUnk_000] + 0x800) >> 12),
                          &q->mUnk_12c, &q->mUnk_80, &v);
            func_0208b5b0(e->mUnk_00[i], &v);
            w.x = (s32) (((s64) q->mUnk_3b0.x * 0xc00) >> 12);
            w.y = (s32) (((s64) q->mUnk_3b0.y * 0xc00) >> 12);
            w.z = (s32) (((s64) q->mUnk_3b0.z * 0xc00) >> 12);
            e->mUnk_00[i]->mUnk_40 = w;
            e->mUnk_00[i]->mUnk_68 = y;
            e->mUnk_00[i]->mUnk_64 = x;
            e->mUnk_00[i]->mUnk_5c = (s16) (((s64) q->mUnk_bc.z * 0x614 + 0x800) >> 12);
        }
        i = i + 1;
    } while (i < 3);
}

void func_020817b8(s32 a) {
    Unk0217ae7c *e = &data_0217ae7c[a];
    u16 i;

    i = 0;
    do {
        if (e->mUnk_00[i] != 0) {
            e->mUnk_00[i]->mUnk_24.mUnk_00_0 = 1;
            e->mUnk_00[i] = 0;
        }
        i = i + 1;
    } while (i < 3);
}

void func_02081768(s32 a) {
    Unk0217ae7c *e = &data_0217ae7c[a];
    u16 i;

    i = 0;
    do {
        if (e->mUnk_00[i] != 0) {
            func_0208b710(e->mUnk_00[i]);
            e->mUnk_00[i] = 0;
        }
        i = i + 1;
    } while (i < 3);
}

void func_02081724(s32 a) {
    Unk0217ae84 *e = &data_0217ae84[a];

    if (e->mUnk_2c != 0) {
        func_0208b710(e->mUnk_2c);
    }
    e->mUnk_2c = func_0208b7bc(0x63, &data_02155a14);
}

void func_02081618(s32 a, Vec3 *b) {
    Unk0217ae84 *e = &data_0217ae84[a];
    Unk0201ca6c *p = e->mUnk_2c;
    Unk0206bcb0 *q;
    Vec3 *s;
    Vec3 v;

    if (p == 0) {
        return;
    }
    p->mUnk_28.x = b->x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = b->y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = b->z + p->mUnk_20->mUnk_00->mUnk_04.z;
    q = func_0207a974(a);
    s = &q->mUnk_3b0;
    v.x = (s32) (((s64) s->x * 0xe66) >> 12);
    v.y = (s32) (((s64) s->y * 0xe66) >> 12);
    v.z = (s32) (((s64) s->z * 0xe66) >> 12);
    e->mUnk_2c->mUnk_40 = v;
}
