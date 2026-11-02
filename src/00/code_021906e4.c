#include "00/code_021906e4.h"
#include "00/code_0218e368.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021a3678.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218dc44.h"
#include "00/code_021965a0.h"
#include "00/code_02190ba0.h"
#include "code_02135014.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"

u32 func_ov000_02190b80(void *p0, void *p1, const void *p2) {
    return func_ov000_02190ba0(p0, p1, p2, strlen(p2));
}

u32 func_ov000_02190b58(void *a, void *b, u32 c) {
    u8 d[0x14];

    sprintf(d, data_ov000_021b29a0, c);
    return func_ov000_02190b80(a, b, d);
}

u32 func_ov000_02190aa8(Unk0218f960 *a, s32 b, const void *c, s32 d, s32 *e, s32 *f, const s8 *g) {
    s32 h;
    u32 i;

    h = func_ov000_0218e420(b, c, d, 0);
    if (h == -1) {
        i = func_ov000_0218e368(b);
        if (i != -6 && i != -0x1a && i != -0x4c) {
            if (g[0] == 0x50 && g[1] == 0x52) {
                return 3;
            }
            func_ov000_021965a0(a, 5, data_ov000_021b29cc);
            func_ov000_02190f4c(a, 3, 0);
            return 3;
        }
        *f = 0;
        *e = 0;
    } else if (h == 0) {
        func_ov000_0219690c(a, (const u8 *) data_ov000_021b29f4, g);
        *f = 0;
        *e = 1;
    } else {
        *f = h;
        *e = 0;
    }
    return 0;
}

u32 func_ov000_02190a24(Unk0218f960 *a, Unk02190988 *b, s8 c) {
    s32 d;
    s32 e;
    u32 f;

    if (b->mUnk_28.mUnk_00 == 0) {
        func_0213442c(data_ov000_021b29a4, data_ov000_021b28a8, 0, 0xde);
    }
    if (b->mUnk_28.mUnk_08 - b->mUnk_28.mUnk_0c == 0 && func_ov000_0218dc44(b->mUnk_38) == 0) {
        f = func_ov000_02190aa8(a, b->mUnk_08, &c, 1, &d, &e, data_ov000_021b29c8);
        if (f != 0) {
            return f;
        }
        if (e != 0) {
            return 0;
        }
    }
    return func_ov000_02190c64(a, &b->mUnk_28, c);
}

u32 func_ov000_02190988(Unk0218f960 *a, Unk02190988 *b, const u8 *c, s32 d) {
    s32 e;
    s32 f;
    s32 g;
    u32 h;

    if (b->mUnk_28.mUnk_00 == 0) {
        func_0213442c(data_ov000_021b29a4, data_ov000_021b28a8, 0, 0xfb);
    }
    e = 0;
    if (d == 0) {
        return e;
    }
    if (b->mUnk_28.mUnk_08 - b->mUnk_28.mUnk_0c == 0 && func_ov000_0218dc44(b->mUnk_38) == 0) {
        do {
            h = func_ov000_02190aa8(a, b->mUnk_08, c + e, d, &f, &g, data_ov000_021b29c8);
            if (h != 0) {
                return h;
            }
            if (g != 0) {
                e += g;
                d -= g;
            }
        } while (g != 0 && d != 0);
    }
    if (d != 0) {
        h = func_ov000_02190ba0(a, &b->mUnk_28, c + e, d);
        if (h != 0) {
            return h;
        }
    }
    return 0;
}

u32 func_ov000_02190968(Unk0218f960 *p0, Unk02190988 *p1, const u8 *p2) {
    u32 v6 = strlen(p2);
    return func_ov000_02190988(p0, p1, p2, v6);
}

u32 func_ov000_021907e8(Unk0218f960 *a, s32 b, Unk021906e4 *c, s32 *d, u32 *e, const s8 *f) {
    u8 *g;
    s32 h;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    s32 n;

    if (b == -1) {
        func_0213442c(data_ov000_021b28d8, data_ov000_021b28a8, 0, 0x150);
    }
    if (c == 0) {
        func_0213442c(data_ov000_021b28f0, data_ov000_021b28a8, 0, 0x151);
    }
    if (d == 0) {
        func_0213442c(data_ov000_021b2904, data_ov000_021b28a8, 0, 0x152);
    }
    if (e == 0) {
        func_0213442c(data_ov000_021b2918, data_ov000_021b28a8, 0, 0x153);
    }
    g = c->mUnk_00;
    h = c->mUnk_08;
    i = c->mUnk_04;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    do {
        n = h + 0x800;
        if (n > i) {
            i = n;
            g = func_ov000_021a3678(g, n + 1);
            if (g == 0) {
                func_ov000_02196590(a, data_ov000_021b292c);
                return 1;
            }
        }
        l = func_ov000_0218e460(b, g + h, i - h, 0);
        if (l == -1) {
            n = func_ov000_0218e368(b);
            if (n != -6 && n != -0x1a && n != -0x4c) {
                func_ov000_02196590(a, data_ov000_021b293c);
                return 3;
            }
        } else if (l == 0) {
            k = 1;
            func_ov000_0219690c(a, data_ov000_021b2968, f);
        } else {
            h += l;
            j += l;
        }
        g[h] = 0;
    } while (l != -1 && k == 0 && j < 0x20000);
    if (j != 0) {
        func_ov000_0219690c(a, data_ov000_021b298c, f, j);
    }
    c->mUnk_00 = g;
    c->mUnk_08 = h;
    c->mUnk_04 = i;
    *d = j;
    *e = k;
    return 0;
}

u32 func_ov000_021906e4(Unk0218f960 *a, s32 b, Unk021906e4 *c, u32 *d, s32 e, const s8 *f) {
    s32 g;
    s32 h;
    u8 *i;
    s32 j;
    s32 k;
    s32 m;
    s32 l;
    s32 n;
    u32 r;

    if (c == 0) {
        func_0213442c(data_ov000_021b2890, data_ov000_021b28a8, 0, 0x1b9);
    }
    i = c->mUnk_00;
    j = c->mUnk_08;
    k = c->mUnk_0c;
    l = j - k;
    m = 0;
    if (l == 0) {
        return m;
    }
    do {
        r = func_ov000_02190aa8(a, b, i + (k + m), l, &g, &h, f);
        if (r != 0) {
            return r;
        }
        n = h;
        if (n != 0) {
            m += n;
            l -= n;
        }
    } while (n != 0 && l != 0);
    if (e != 0) {
        if (m > 0) {
            memmove(i, i + m, l + 1);
            j -= m;
        }
    } else {
        k += m;
    }
    if (j < 0) {
        func_0213442c(data_ov000_021b28b4, data_ov000_021b28a8, 0, 0x1de);
    }
    if (k < 0) {
        func_0213442c(data_ov000_021b28c0, data_ov000_021b28a8, 0, 0x1df);
    }
    if (k > j) {
        func_0213442c(data_ov000_021b28cc, data_ov000_021b28a8, 0, 0x1e0);
    }
    c->mUnk_08 = j;
    c->mUnk_0c = k;
    if (d != 0) {
        *d = g;
    }
    return 0;
}
