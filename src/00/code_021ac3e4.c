#include "00/code_021ac3e4.h"
#include "00/code_021acbf8.h"
#include "00/code_021acc68.h"
#include "00/code_021acc8c.h"
#include "00/code_021acec8.h"
#include "00/unk_021b6000.h"
#include "code_021329f8.h"
#include "code_02134d30.h"
#include "code_0214d018.h"

void func_ov000_021ac3e4(u8 *a, u8 *b, s32 c) {
    s32 i;
    u8 d;
    u8 e;
    u8 *f;
    u8 g;
    u8 h;
    d = a[0];
    e = a[1];
    f = a + 2;
    for (i = 0; i < c; i++) {
        d = d + 1;
        g = f[d];
        e = e + g;
        h = f[e];
        f[d] = h;
        f[e] = g;
        b[i] ^= f[(u8) (g + h)];
    }
    a[0] = d;
    a[1] = e;
}

void func_ov000_021ac434(u8 *a, const u8 *b, s32 c) {
    u8 *d;
    s32 i;
    u8 j;
    u8 k;
    u8 t;
    a[0] = 0;
    a[1] = 0;
    d = a + 2;
    for (i = 0; i < 0x100; i++) {
        d[i] = i;
    }
    k = 0;
    j = 0;
    for (i = 0; i < 0x100; i++) {
        t = d[i];
        j = j + (t + b[k]);
        d[i] = d[j];
        d[j] = t;
        k = k + 1;
        if (k >= c) {
            k = 0;
        }
    }
}

void func_ov000_021ac488(u8 *a, const u16 *b, s32 c, s32 d) {
    a += c - 1;
    while (c > 1) {
        *a-- = *b;
        *a-- = *b++ >> 8;
        c -= 2;
    }
    if (c > 0) {
        *a = *b;
    }
}

void func_ov000_021ac4b8(u16 *a, const u8 *b, s32 c, s32 d) {
    func_0214d168(a, 0, d * 2);
    b += c - 1;
    while (c > 1) {
        *a = b[0] + (b[-1] << 8);
        a++;
        b -= 2;
        c -= 2;
    }
    if (c > 0) {
        *a = *b;
    }
}

void func_ov000_021ac4f4(u16 *a, u16 *b, u16 *c, s32 d, u16 *e) {
    u16 *f;
    u16 *g;
    u16 *h;
    u16 *i;
    u16 *j;
    u16 *k;
    u16 *l;
    s32 m;
    s32 n;
    u32 o;
    n = d * 0x16;
    f = (u16 *) data_ov000_021b63a4(n);
    if (f != NULL) {
        func_0214d168(f, 0, n);
        g = f + d;
        h = g + d;
        i = h + d;
        j = i + d;
        k = j + d;
        l = k + d;
        m = func_ov000_021acec8(e, d);
        f[m] = 1;
        func_ov000_021ac718(g, f, e, d, h);
        func_ov000_021acbf8(i, f, g, d);
        func_ov000_021acccc(g, i, 1, d);
        func_ov000_021ac900(g, g, e, NULL, d, l);
        func_ov000_021acbf8(h, b, f, d);
        func_ov000_021ac900(NULL, h, e, h, d, l);
        func_ov000_021ac900(NULL, f, e, a, d, l);
        n = 0;
        o = m << 4;
        for (; n < o; n++) {
            func_ov000_021ac650(a, k, (u16 *) 1, d, m, e, g, i, j);
            if (((0x8000u >> (n & 0xf)) & c[m - (n >> 4) - 1]) != 0) {
                func_ov000_021ac650(a, k, h, d, m, e, g, i, j);
            }
        }
        func_ov000_021ac650(a, k, NULL, d, m, e, g, i, j);
        data_ov000_021b63ac(f);
    }
}

void func_ov000_021ac650(u16 *a, u16 *b, u16 *c, s32 d, s32 e, u16 *f, u16 *g, u16 *h, u16 *i) {
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    j = d * 2;
    func_0214d1fc(a, b, j);
    if (c == (u16 *) 1) {
        func_ov000_021acab0(a, b, d);
    } else if (c != NULL) {
        func_ov000_021acbf8(a, b, c, d);
    }
    func_ov000_021acbf8(h, a, g, e);
    k = (d - e) * 2;
    l = e * 2;
    func_0214d168(h + e, 0, k);
    func_ov000_021acbf8(i, h, f, d);
    func_ov000_021ace14(a, a, i, d);
    memmove(a, a + e, k);
    func_0214d168(a + d - e, 0, l);
    m = func_ov000_021acc8c(a, f, d);
    switch (m) {
        case 0:
            func_0214d168(a, 0, j);
            break;
        case 1:
            func_ov000_021acd24(a, a, f, d);
            break;
    }
}

void func_ov000_021ac718(u16 *a, u16 *b, u16 *c, s32 d, u16 *e) {
    u16 *f;
    u16 *g;
    u16 *h;
    u16 *i;
    u16 *j;
    u16 *k;
    s32 l;
    l = d * 2;
    f = e + d;
    g = f + d;
    h = g + d;
    i = h + d;
    j = i + d;
    k = j + d;
    func_0214d1fc(b, e, l);
    func_0214d1fc(c, g, l);
    g[d] = 1;
    while (func_ov000_021ace90(e, d) > 0) {
        func_ov000_021ac900(f, g, e, j, d, k);
        func_0214d1fc(e, g, l);
        func_0214d1fc(j, e, l);
        func_ov000_021acbf8(j, f, h, d);
        func_ov000_021acd24(j, i, j, d);
        func_0214d1fc(h, i, l);
        func_0214d1fc(j, h, l);
    }
    func_ov000_021ace14(i, i, c, d);
    func_ov000_021ac900(NULL, i, c, a, d, k);
}

void func_ov000_021ac7e8(u16 *a, u16 *b, u16 *c, s32 d, u16 *e) {
    u16 *f;
    u16 *g;
    s32 h;
    s32 i;
    f = (u16 *) data_ov000_021b63a4(d * 8);
    if (f != NULL) {
        g = f + d;
        func_0214d168(a + 1, 0, (d - 1) * 2);
        a[0] = 1;
        h = d - func_ov000_021acec8(c, d);
        i = h * 16;
        for (; i < (u32) (d << 4); i++) {
            if (((0x8000u >> (i & 0xf)) & c[d - (i >> 4) - 1]) != 0) {
                func_0214d1fc(b, a, d * 2);
                i++;
                break;
            }
        }
        for (; i < (u32) (d << 4); i++) {
            func_ov000_021acab0(f, a, d);
            func_0214d1fc(f, a, d * 2);
            if (e != NULL) {
                func_ov000_021ac900(NULL, a, e, a, d, g);
            }
            if (((0x8000u >> (i & 0xf)) & c[d - (i >> 4) - 1]) != 0) {
                func_ov000_021acbf8(f, a, b, d);
                func_0214d1fc(f, a, d * 2);
                if (e != NULL) {
                    func_ov000_021ac900(NULL, a, e, a, d, g);
                }
            }
        }
        data_ov000_021b63ac(f);
    }
}

void func_ov000_021ac900(u16 *a, u16 *b, u16 *c, u16 *d, s32 e, u16 *f) {
    u16 *h;
    s32 i;
    s32 j;
    s32 k;
    u64 m;
    u16 *g;
    u32 l;
    u64 n;
    g = f + e;
    h = g + e;
    func_0214d168(g, 0, e * 4);
    i = func_ov000_021acec8(b, e);
    j = func_ov000_021acec8(c, e);
    if (i > 0 && j > 0) {
        k = e - i + j - 1;
        if (k >= e) {
            func_0214d1fc(b, h, e * 2);
        } else {
            func_0214d1fc(b, g + k, i * 2);
            if (j > 2) {
                m = ((u64) * (c + j - 1) << 32) + ((u64) * (c + j - 2) << 16) + (u64) * (c + j - 3);
            } else if (j > 1) {
                m = ((u64) * (c + j - 1) << 32) + ((u64) * (c + j - 2) << 16);
            } else {
                m = (u64) * (c + j - 1) << 32;
            }
            while (k < e) {
                memmove(g + 1, g, (e * 2 - 1) * 2);
                n = ((u64) (h + j)[0] << 48) + ((u64) (h + j)[-1] << 32) + ((u64) (h + j)[-2] << 16) + (u64) (h + j)[-3];
                l = n / m;
                if (l > 0xffff) {
                    l = 0xffff;
                }
                for (;;) {
                    func_ov000_021acb98(f, c, l, e);
                    if (func_ov000_021acc8c(h, f, e) >= 0) {
                        break;
                    }
                    l--;
                }
                func_ov000_021acd24(h, h, f, e);
                *g = l;
                k++;
            }
        }
    }
    if (a != NULL) {
        func_0214d1fc(g, a, e * 2);
    }
    if (d != NULL) {
        func_0214d1fc(h, d, e * 2);
    }
}

void func_ov000_021acab0(u16 *a, const u16 *b, s32 c) {
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    u32 h;
    u32 i;
    d = func_ov000_021acec8(b, c);
    e = d * 2;
    if (e < c) {
        func_0214d168(a + e, 0, (c - e) * 2);
    }
    for (g = 0; g < d; g++) {
        f = g * 2;
        if (f >= c) {
            break;
        }
        h = b[g] * b[g];
        a[f] = h;
        if (f == c - 1) {
            break;
        }
        a[f + 1] = h >> 16;
    }
    for (e = 0; e < d; e++) {
        for (f = e + 1; f < d && (g = e + f) < c; f++) {
            i = b[f] * b[e];
            if (i <= 0x7fff8000) {
                func_ov000_021acc68(a, i * 2, g, c);
            } else {
                func_ov000_021acc68(a, i, g, c);
                func_ov000_021acc68(a, i, g, c);
            }
        }
    }
}

void func_ov000_021acb98(u16 *a, const u16 *b, u16 c, s32 d) {
    s32 e;
    s32 f;
    u32 g;
    u32 h;
    e = func_ov000_021acec8(b, d);
    g = 0;
    for (f = 0; f < e; f++) {
        h = g + c * b[f];
        a[f] = h;
        g = h >> 16;
    }
    if (f < d) {
        a[f++] = g;
    }
    func_0214d168(a + f, 0, (d - f) * 2);
}
