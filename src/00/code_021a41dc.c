#include "00/code_021a41dc.h"
#include "00/code_021a44a0.h"
#include "00/code_021a4654.h"
#include "00/code_021a4b84.h"
#include "00/unk_021b4000.h"
#include "code_021384dc.h"
#include "code_02139f70.h"

void func_ov000_021a4418(Unk021a4a08 *a, Unk021a471c *b, const u8 *c, s32 d) {
    u8 e[0x44];

    if (d >= 1 && d <= 0x41 && ((s8 *) c)[d - 1] == 0) {
        strcpy((char *) e, c);
        func_ov000_021a44a0(a->mUnk_044, strlen(a->mUnk_044), e, d - 1);
        func_ov000_021a4578(e, d - 1, &b->mUnk_000[b->mUnk_800]);
        b->mUnk_800 += strlen(&b->mUnk_000[b->mUnk_800]) + 1;
    }
}

void func_ov000_021a438c(Unk021a4a08 *a, const u8 *b) {
    u32 c;
    u32 d;
    u16 e;

    func_02138510(b, data_ov000_021b440c, &c, &d);
    e = (u16) d;
    c = (c << 24 & 0xff000000) | ((c << 8 & 0xff0000) | ((c >> 24 & 0xff) | (c >> 8 & 0xff00)));
    if (c != 0 && e != 0) {
        if (a->mUnk_104 != c || a->mUnk_108 != e) {
            a->mUnk_104 = c;
            a->mUnk_108 = e;
            a->mUnk_0a8(c, e, a->mUnk_10c);
        }
    }
}

void func_ov000_021a41dc(Unk021a4a08 *a, Unk021a471c *b, s32 c, s32 d, const u8 *e) {
    Unk021a3fc8 f;
    u16 g;
    u16 h;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    s32 n;
    const u8 *o;
    const u8 *p;
    u8 *q;
    u8 *r;

    f.mUnk_100 = 0;
    if (d == 0) {
        return;
    }
    if ((u32) (c - 1) <= 1) {
        if ((u32) (0x800 - b->mUnk_800) < 2) {
            return;
        }
        i = a->mUnk_098(c, a->mUnk_10c);
        g = (u16) i;
        h = (g >> 8 & 0xff) | (g << 8 & 0xff00);
        r = &b->mUnk_000[b->mUnk_800];
        q = (u8 *) &h;
        r[0] = q[0];
        r[1] = q[1];
        b->mUnk_800 += 2;
    } else {
        i = 1;
    }
    if (d == 0xff) {
        a->mUnk_094(c, &f, a->mUnk_10c);
        l = 0;
        if (f.mUnk_100 > 0) {
            o = f.mUnk_000;
            do {
                p = data_ov000_021b45bc[*o];
                if (p == 0) {
                    p = data_ov000_021b43f8;
                }
                func_ov000_021a471c(b, p);
                if (c == 0) {
                    k = b->mUnk_800;
                    a->mUnk_088(*o, b, a->mUnk_10c);
                    if (k == b->mUnk_800) {
                        func_ov000_021a471c(b, data_ov000_021b4400);
                    }
                }
                o++;
                l++;
            } while (l < f.mUnk_100);
        }
        if (0x800 - b->mUnk_800 < 1) {
            return;
        }
        b->mUnk_000[b->mUnk_800++] = 0;
        d = f.mUnk_100;
        e = f.mUnk_000;
        if (c == 0) {
            return;
        }
    }
    j = 0;
    if (i > 0) {
        m = j;
        do {
            n = m;
            if (d > 0) {
                do {
                    k = b->mUnk_800;
                    if (c == 0) {
                        a->mUnk_088(e[n], b, a->mUnk_10c);
                    } else if (c == 1) {
                        a->mUnk_08c(e[n], j, b, a->mUnk_10c);
                    } else if (c == 2) {
                        a->mUnk_090(e[n], j, b, a->mUnk_10c);
                    }
                    if (k == b->mUnk_800) {
                        func_ov000_021a471c(b, data_ov000_021b4400);
                    }
                    n++;
                } while (n < d);
            }
            j++;
        } while (j < i);
    }
}
