#include "00/code_02186a9c.h"
#include "03/code_021b94b8.h"
#include "00/unk_021b1000.h"
#include "00/code_02186628.h"
#include "code_0200d118.h"
#include "code_02134d30.h"
#include "code_02139f70.h"

#pragma opt_lifetimes off

BOOL func_ov000_02186a9c(Unk021868d0 *a, const u8 *b) {
    s32 d;
    Unk02186998 *c;
    s32 e;
    s32 f;
    c = &a->mUnk_928;
    d = strlen(b);
    e = c->mUnk_08 - c->mUnk_04;
    if (d > e) {
        if (func_ov000_02186998(a, c, d - e + 1) == 0) {
            return TRUE;
        }
        e = c->mUnk_08 - c->mUnk_04;
    }
    f = func_0200d9e0(c->mUnk_04, e, data_ov000_021b1290, b);
    if (f != d) {
        return TRUE;
    }
    c->mUnk_04 = c->mUnk_04 + f;
    return FALSE;
}

BOOL func_ov000_02186b0c(Unk021868d0 *a, const u8 *b, const void *c, s32 d) {
    Unk02186998 *e = &a->mUnk_928;
    char *f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    if (a->mUnk_924 == 0) {
        f = data_ov000_021b1294;
    } else {
        f = data_ov000_021b1298;
    }
    a->mUnk_924 = a->mUnk_924 + 1;
    g = func_ov000_021882f8(c, d, NULL, 0);
    h = strlen((const u8 *) f);
    i = g + (h - 2 + strlen(b));
    j = e->mUnk_08 - e->mUnk_04;
    if (i > j) {
        if (func_ov000_02186998(a, e, i - j + 1) == 0) {
            return TRUE;
        }
        j = e->mUnk_08 - e->mUnk_04;
    }
    e->mUnk_04 = e->mUnk_04 + func_0200d9e0(e->mUnk_04, j, f, b);
    if (func_ov000_021882f8(c, d, (s8 *) e->mUnk_04, e->mUnk_08 - e->mUnk_04 - 1) < 0) {
        return TRUE;
    }
    e->mUnk_04 = e->mUnk_04 + g;
    *e->mUnk_04 = 0;
    return FALSE;
}

BOOL func_ov000_02186bd4(Unk021868d0 *a, const u8 *b, const u8 *c) {
    s32 e;
    Unk02186998 *d;
    s32 f;
    char *g;
    s8 *p;
    s8 h;
    s32 i;
    d = &a->mUnk_928;
    e = strlen(c);
    f = strlen((const u8 *) data_ov000_021b12a0);
    e = e + (f - 4 + strlen(b));
    i = d->mUnk_08 - d->mUnk_04;
    if (e + 1 > i) {
        if (func_ov000_02186998(a, d, e - i + 1) == 0) {
            return TRUE;
        }
    }
    p = (s8 *) strstr((const u8 *) d->mUnk_00, data_ov000_021b1230);
    g = (char *) p + 2;
    h = p[2];
    memmove(g + e, g, strlen((const u8 *) g) + 1);
    i = func_0200d9e0(g, e + 1, data_ov000_021b12a0, b, c);
    g[i] = h;
    d->mUnk_04 = d->mUnk_04 + e;
    return FALSE;
}

BOOL func_ov000_02186c74(Unk021868d0 *a) {
    Unk02186998 *b = &a->mUnk_928;
    char *c;
    s32 d;
    s32 e;
    s32 f;
    if (a->mUnk_008 == 0) {
        c = data_ov000_021b12ac;
    } else {
        c = data_ov000_021b1300;
    }
    d = strlen(a->mUnk_0a8);
    e = strlen((const u8 *) c);
    f = d + (e - 4 + strlen(a->mUnk_0ac));
    if (func_ov000_02186a38(a, &a->mUnk_928, f + 0x400) != 1) {
        return TRUE;
    }
    b->mUnk_04 = b->mUnk_04 + func_0200d9e0(b->mUnk_04, b->mUnk_0c, c, a->mUnk_0ac, a->mUnk_0a8);
    return FALSE;
}
