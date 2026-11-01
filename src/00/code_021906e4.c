#include "00/code_021906e4.h"

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
            func_02134df8(i, i + m, l + 1);
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
