#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124efc.h"
#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"
#include "code_02021e8c.h"
#include "code_020222ec.h"

#pragma thumb on

void func_02124ed0(void *a, Unk0201ea30 *b, Unk0201ea30 *c, Unk02124b1c **d) {
    u16 n;

    n = b->mUnk_06;
    if (c != NULL) {
        n = n + c->mUnk_06;
    }
    *d = HeapAlloc(a, n << 6);
    func_02124efc(*d, n);
}

u32 func_02124c70(s32 a, Unk02021dc8 *b, Unk0201ea30 *c, Unk0201ea30 *d, Unk02124c70 *e, Unk02124b1c *f, s32 g) {
    s32 v10;
    s32 v14;
    s32 *v18;
    Unk0201ea84 l20[3];
    s32 v28[2];
    Unk02124a68 *m;
    Unk0201ea30_08 *t;
    u16 r6;
    u32 h;
    Unk02124c70_00 *p;

    if (f->mUnk_38 != -1) {
        func_02124c70(f->mUnk_38 + c->mUnk_06, b, c, d, e, f - a + c->mUnk_06 + f->mUnk_38, g);
    }
    v18 = NULL;
    if (f->mUnk_00 == 0) {
        return (u32) v18;
    }
    if (a >= c->mUnk_06) {
        Unk0212428c *s = func_0201ea58(d, a - c->mUnk_06);
        m = f->mUnk_3c->mUnk_44;
        l20[0] = s->mUnk_00;
        l20[1] = s->mUnk_02;
        v10 = m->mUnk_08 - m->mUnk_0c;
        v14 = m->mUnk_0a - m->mUnk_0e;
        v28[0] = l20[0].mUnk_00_0 << 12;
        v28[1] = l20[1].mUnk_00_0 << 12;
    } else {
        t = func_0201ea30(c, a);
        m = (Unk02124a68 *) func_02021f1c(b, (u16) t->mUnk_04);
        l20[2] = t->mUnk_00_0;
        l20[0] = l20[2];
        l20[1] = t->mUnk_00_2;
        v10 = m->mUnk_08 - m->mUnk_0c;
        v14 = m->mUnk_0a - m->mUnk_0e;
        v28[0] = ((v10 >> 1) + func_0201ebe8(l20[2], v10)) << 12;
        v28[1] = ((v14 >> 1) + func_0201eba0(t->mUnk_00_2, v14)) << 12;
    }
    if (f->mUnk_08 != FALSE) {
        if (a >= c->mUnk_06) {
            v28[0] = f->mUnk_0c << 12;
            v28[1] = f->mUnk_0e << 12;
        } else {
            v28[0] = (f->mUnk_0c + (v10 >> 1) * (1 - l20[0].mUnk_00_12)) << 12;
            v28[1] = (f->mUnk_0e + (v14 >> 1) * (1 - l20[1].mUnk_00_12)) << 12;
        }
    }
    v28[0] += f->mUnk_04 << 12;
    v28[1] += f->mUnk_06 << 12;
    if ((v28[0] >> 12) + v10 < 0 || (v28[0] >> 12) - v10 > 0x100 || (v28[1] >> 12) + v14 < 0 ||
        (v28[1] >> 12) - v14 > 0xc0) {
        return 0;
    }
    r6 = func_020ae5e4((u32) e);
    if (f->mUnk_10 != 0) {
        v18 = f->mUnk_24;
        p = &e->mUnk_000[r6];
        p->mUnk_00[0].mUnk_00[3] = f->mUnk_14[0] >> 4;
        p->mUnk_00[1].mUnk_00[3] = f->mUnk_14[1] >> 4;
        p->mUnk_00[2].mUnk_00[3] = f->mUnk_14[2] >> 4;
        p->mUnk_00[3].mUnk_00[3] = f->mUnk_14[3] >> 4;
        if (g != 0) {
            func_020ae5d4((u32) e);
        }
    }
    h = e->mUnk_400;
    e->mUnk_400 += func_020224e0(&e->mUnk_000[0].mUnk_00[h], 0x80 - h, (Unk020224e0_c *) m, v18, v28, r6, f->mUnk_34);
}

void func_02124c30(void *a, void *b, void *c, void *d, void *e) {
    s32 i;
    for (i = ((Unk0201ea30 *) a)->mUnk_06 - 1; i >= 0; i--) {
        func_02124c70(i, b, a, c, d, (Unk02124b1c *) e + i, 1);
    }
}

void func_02124bf0(void *a, void *b, void *c, void *d, void *e) {
    s32 i;
    for (i = ((Unk0201ea30 *) a)->mUnk_06 - 1; i >= 0; i--) {
        func_02124c70(i, b, a, c, d, (Unk02124b1c *) e + i, 0);
    }
}

#pragma thumb off
