#include "00/code_021a3f78.h"

#include "00/code_021a41dc.h"
#include "00/code_021a4654.h"
#include "00/code_021a4b84.h"
#include "00/unk_021b4000.h"
#include "code_02135014.h"

void func_ov000_021a41a0(Unk021a4a08 *a, Unk021a471c *b, s32 c, const u8 *d, s32 e, const u8 *f, s32 g, const u8 *h) {
    func_ov000_021a41dc(a, b, 0, c, d);
    func_ov000_021a41dc(a, b, 1, e, f);
    func_ov000_021a41dc(a, b, 2, g, h);
    return;
}

void func_ov000_021a412c(Unk021a4a08 *a, Unk021a471c *b, const u8 *c, s32 d) {
    u8 h;
    u8 i;
    u8 j;
    const u8 *e;
    const u8 *g;
    const u8 *f;

    e = NULL;
    g = NULL;
    f = NULL;
    if (d >= 3) {
        h = *c++;
        d--;
        if (h != 0 && h != 0xff) {
            e = c;
            c += h;
            d -= h;
        }
        if (d >= 2) {
            i = *c++;
            d--;
            if (i != 0 && i != 0xff) {
                g = c;
                c += i;
                d -= i;
            }
            if (d >= 1) {
                j = *c;
                d--;
                if (j != 0 && j != 0xff) {
                    f = c + 1;
                    d -= j;
                }
                if (d >= 0) {
                    func_ov000_021a41a0(a, b, h, e, i, g, j, f);
                }
            }
        }
    }
}

void func_ov000_021a3fc8(Unk021a4a08 *a, Unk021a471c *b, s32 c) {
    char e[0x80];
    Unk021a3fc8 d;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    const char *k;
    u8 *l;

    d.mUnk_100 = 0;
    if ((u32) (c - 1) <= 1) {
        f = a->mUnk_098(c, a->mUnk_10c);
    } else {
        f = 1;
    }
    a->mUnk_094(c, &d, a->mUnk_10c);
    h = 0;
    if (d.mUnk_100 > 0) {
        l = d.mUnk_000;
        i = h;
        do {
            k = data_ov000_021b45bc[*l];
            if (k == NULL) {
                k = data_ov000_021b43f8;
            }
            if (c == 0) {
                func_ov000_021a471c(b, k);
                b->mUnk_000[b->mUnk_800 - 1] = 0x5c;
                g = b->mUnk_800;
                a->mUnk_088(*l, b, a->mUnk_10c);
                if (g == b->mUnk_800) {
                    func_ov000_021a471c(b, data_ov000_021b4400);
                }
                b->mUnk_000[b->mUnk_800 - 1] = 0x5c;
            } else {
                j = i;
                if (f > 0) {
                    do {
                        sprintf(e, data_ov000_021b4404, k, j);
                        func_ov000_021a471c(b, e);
                        b->mUnk_000[b->mUnk_800 - 1] = 0x5c;
                        g = b->mUnk_800;
                        if (c == 1) {
                            a->mUnk_08c(*l, j, b, a->mUnk_10c);
                        } else if (c == 2) {
                            a->mUnk_090(*l, j, b, a->mUnk_10c);
                        }
                        if (g == b->mUnk_800) {
                            func_ov000_021a471c(b, data_ov000_021b4400);
                        }
                        b->mUnk_000[b->mUnk_800 - 1] = 0x5c;
                        j++;
                    } while (j < f);
                }
            }
            l++;
            h++;
        } while (h < d.mUnk_100);
    }
}

void func_ov000_021a3f78(Unk021a4a08 *a, Unk021a471c *b) {
    b->mUnk_800 = 1;
    b->mUnk_000[0] = 0x5c;
    func_ov000_021a3fc8(a, b, 0);
    func_ov000_021a3fc8(a, b, 1);
    func_ov000_021a3fc8(a, b, 2);
    func_ov000_021a471c(b, data_ov000_021b43e4);
    b->mUnk_800 = b->mUnk_800 + -1;
    return;
}
