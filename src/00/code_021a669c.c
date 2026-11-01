#include "00/code_021a669c.h"
#include "00/code_021a666c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "code_02133274.h"
#include "code_0200dc3c.h"
#include "Main/Unknown/code_02000800.h"

// non-matching: loop guard at +0x2c is `cmp r6, r0` + `bcs` (ours) against `cmp r0, #0` + `bls` (original); size and
// all other words equal
Unk021b5f50_2270_0c *func_ov000_021a669c(void) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;
    u32 n;
    enum { K0 } i;

    g = func_ov000_021a5b30();
    l = g->mUnk_2270;
    e = 0;
    if (l != 0 && g->mUnk_2274 > 0xc) {
        n = (g->mUnk_2274 - 0xc) / 0xd0;
        if (n != 0 && n > l->mUnk_00) {
            for (i = 0; i < n; i++) {
                e = &l->mUnk_0c[i];
                if (e->mUnk_00 == 0) {
                    break;
                }
            }
            if (i < n) {
                e->mUnk_00 = 1;
                e->mUnk_04 = l->mUnk_00;
                e->mUnk_0c = 0;
                e->mUnk_08 = l->mUnk_08;
                l->mUnk_08 = e;
                if (e->mUnk_08 != 0) {
                    e->mUnk_08->mUnk_0c = e;
                } else {
                    l->mUnk_04 = e;
                }
                l->mUnk_00++;
            }
        }
    }
    return e;
}

void func_ov000_021a671c(Unk021a5e84 *a, u16 b) {
    Unk021b5f50 *g;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    if (g != 0 && g->mUnk_226a == 0 && a->mUnk_3c == 0) {
        e = func_ov000_021a6614(a->mUnk_04);
        if (e == 0) {
            e = func_ov000_021a669c();
        }
        if (e == 0 && g->mUnk_2278 == 1) {
            e = func_ov000_021a666c();
        }
        if (e != 0) {
            e->mUnk_02 = b;
            func_0214d0a8(a, e->mUnk_10, 0xc0);
            func_ov000_021a6558(e);
        }
    }
}

u8 *func_ov000_021a6788(u16 a) {
    u32 v1;
    Unk021b5f50_2270_0c *e;

    v1 = func_0200fca0();
    if (func_ov000_021a5b30() == 0) {
        func_0200fcb4(v1);
        return 0;
    }
    e = func_ov000_021a65d8(a);
    if (e == 0) {
        func_0200fcb4(v1);
        return 0;
    }
    func_0200fcb4(v1);
    return e->mUnk_10;
}

u32 func_ov000_021a67dc(u32 a) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = func_ov000_021a5b30();
    if (g == 0) {
        func_0200fcb4(v1);
        return 0;
    }
    if (a != 0) {
        a = g->mUnk_226a != 0;
        g->mUnk_226a = 1;
    } else {
        a = g->mUnk_226a != 0;
        g->mUnk_226a = 0;
    }
    func_0200fcb4(v1);
    return a;
}

u32 func_ov000_021a6844(void) {
    u32 v1;
    u32 r;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = func_ov000_021a5b30();
    r = 0;
    if (g == 0) {
        func_0200fcb4(v1);
        return r;
    }
    if (g->mUnk_2270 != 0 && g->mUnk_2274 > 0xc) {
        r = g->mUnk_2270->mUnk_00;
    }
    func_0200fcb4(v1);
    return r;
}

void func_ov000_021a6894(void) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = func_ov000_021a5b30();
    if (g == 0) {
        func_0200fcb4(v1);
        return;
    }
    if (g->mUnk_2270 != 0 && (s32) g->mUnk_2274 > 0) {
        func_0214d168(g->mUnk_2270, 0, g->mUnk_2274);
    }
    func_0200fcb4(v1);
}

void func_ov000_021a68dc(Unk0200edc0 *a) {
    if (a->mUnk_08 == (struct Unk0200db5c *) func_01ff8000) {
        a->mUnk_0c--;
        if (a->mUnk_0c == 0) {
            a->mUnk_08 = 0;
            func_0200df9c(&a->mUnk_00);
        }
    }
}
