#include "00/code_021a9aa0.h"
#include "00/code_021aa004.h"
#include "00/code_021ab728.h"
#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021abd2c.h"
#include "00/code_021adbac.h"
#include "00/types_021a998c.h"
#include "00/unk_021b6000.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

u8 func_ov000_021a9d68(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u32 n;
    u8 *p;
    u8 *q;
    u8 *r;
    u8 v1;
    u8 v2;
    s32 v3;
    do {
        p = func_ov000_021adfc8(&n, a);
        if (n == 0) {
            c->mUnk_429 = 9;
            return c->mUnk_429;
        }
    } while (n < 5);
    v1 = p[0];
    if (v1 == 0x80) {
        if (c->mUnk_428 != 0 && c->mUnk_429 == 0) {
            n = p[1];
            func_ov000_021adf30(2, a);
            q = data_ov000_021b63a4(n);
            if (q == NULL) {
                c->mUnk_429 = 9;
                return c->mUnk_429;
            }
            if (func_ov000_021aa004(q, n, a) == 0 && q[0] == 1) {
                func_ov000_021aaa58(c, q + 1);
            } else {
                c->mUnk_429 = 9;
            }
            func_ov000_021abca0(c->mUnk_2c0, q, n);
            func_ov000_021ab728(c->mUnk_378, q, n);
            data_ov000_021b63ac(q);
        } else {
            c->mUnk_429 = 9;
        }
    } else {
        n = ((p[3] << 8) + p[4]) + 5;
        q = data_ov000_021b63a4(n);
        if (q == NULL) {
            c->mUnk_429 = 9;
            return c->mUnk_429;
        }
        if (func_ov000_021aa004(q, n, a) != 0) {
            data_ov000_021b63ac(q);
            c->mUnk_429 = 9;
            return c->mUnk_429;
        }
        if (((u8) (c->mUnk_429 + 0xf9) <= 1 && v1 != 0x15) || (v1 == 0x15 && n > 7)) {
            n = func_ov000_021aa1e0(c, q);
        }
        r = q + 5;
        n -= 5;
        switch (v1) {
            case 0x14:
                MemFill(c->mUnk_2b8, 0, 8);
                c->mUnk_429 = 7;
                break;
            case 0x15:
                if (r[0] == 2) {
                    c->mUnk_429 = 9;
                }
                break;
            case 0x16:
                do {
                    v2 = r[0];
                    v3 = r[3] + ((r[1] << 16) + (r[2] << 8));
                    r += 4;
                    switch (v2) {
                        case 1:
                            if (c->mUnk_428 != 0 && c->mUnk_429 == 0) {
                                func_ov000_021aa9ec(c, r);
                            }
                            break;
                        case 0x10:
                            func_ov000_021aa5b0(c, r);
                            break;
                        case 2:
                            func_ov000_021aab74(c, r);
                            break;
                        case 0xb:
                            func_ov000_021aabf0(c, r);
                            break;
                        case 0xe:
                            c->mUnk_429 = 4;
                            break;
                        case 0x14:
                            func_ov000_021aa3b8(c, r);
                            break;
                        default:
                            c->mUnk_429 = 9;
                            break;
                    }
                    func_ov000_021abca0(c->mUnk_2c0, r - 4, (u32) (v3 + 4));
                    func_ov000_021ab728(c->mUnk_378, r - 4, (u32) (v3 + 4));
                    r += v3;
                    n -= (u32) (v3 + 4);
                    if (n == 0) {
                        break;
                    }
                } while (c->mUnk_429 != 9);
                break;
            case 0x17:
                c->mUnk_7f8 = q;
                c->mUnk_800 = 5;
                c->mUnk_7fc = n + 5;
                return c->mUnk_429;
        }
        data_ov000_021b63ac(q);
    }
    return c->mUnk_429;
}

void func_ov000_021a9ca8(u8 *a, s32 n) {
    u8 b[0x14];
    u8 d[0x5c];
    u32 c;
    s32 i;
    s32 j;
    s32 k;
    u32 h;
    u8 *e;
    u8 *f;
    u32 g;
    u32 q;
    u64 *l;
    u64 m;
    if (data_ov000_021b617c == 0) {
        l = data_ov000_021b63e0;
        m = l[1] * l[0] + l[2];
        l[0] = m;
        c = m >> 32;
        func_ov000_021a9c5c(&c, 4);
    }
    i = 0x14;
    j = 0;
    while (j < n) {
        if (i == 0x14) {
            func_ov000_021abd2c((u32 *) d);
            g = IrqDisable();
            func_ov000_021abca0(d, data_ov000_021b6184, 0x14);
            func_ov000_021abc24((u32) d, (u32) b);
            h = 1;
            k = 0x13;
            e = b + 0x13;
            f = &data_ov000_021b6197;
            for (; k >= 0; k--) {
                q = *f + *e + h;
                *f = q;
                h = q >> 8;
                e--;
                f--;
            }
            c = q;
            IrqRestore(g);
            i = 0;
        }
        if (b[i] != 0) {
            a[j] = b[i];
            j++;
        }
        i++;
    }
}

void func_ov000_021a9c5c(void *a, u32 n) {
    u8 b[0x60];
    u32 c;
    func_ov000_021abd2c((u32 *) b);
    c = IrqDisable();
    func_ov000_021abca0(b, data_ov000_021b6184, 0x14);
    func_ov000_021abca0(b, a, n);
    func_ov000_021abc4c((s32) b, (u32) data_ov000_021b6184);
    IrqRestore(c);
    data_ov000_021b617c = 1;
}

u8 func_ov000_021a9aa0(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    Unk021a998c_0c_7f4 *d = c->mUnk_7f4;
    s32 e;
    u32 f;
    u8 *g;
    u8 *h;
    s32 i;
    if (d != NULL) {
        e = d->mUnk_00;
    } else {
        e = 0;
    }
    f = func_ov000_021ab5bc();
    c->mUnk_028[0] = f >> 24;
    c->mUnk_028[1] = f >> 16;
    c->mUnk_028[2] = f >> 8;
    c->mUnk_028[3] = f;
    func_ov000_021a9ca8(&c->mUnk_028[4], 0x1c);
    g = data_ov000_021b63a4(e + 0x9d);
    if (g == NULL) {
        c->mUnk_429 = 9;
        return 1;
    }
    h = g + 5;
    g[5] = 2;
    h[1] = 0;
    h[2] = 0;
    h[3] = 0x46;
    h[4] = 3;
    h[5] = 0;
    MemCopy(c->mUnk_028, h + 6, 0x20);
    h[0x26] = 0x20;
    if (c->mUnk_000 != NULL) {
        MemCopy(c->mUnk_000, h + 0x27, 0x20);
        h += 0x47;
        c->mUnk_004 = 1;
    } else {
        func_ov000_021a9ca8(h + 0x27, 0x1c);
        f = data_ov000_021b6180;
        h[0x43] = f >> 24;
        h[0x44] = f >> 16;
        h[0x45] = f >> 8;
        h += 0x46;
        *h++ = f;
        c->mUnk_000 = func_ov000_021ab5e4(h - 0x20);
        data_ov000_021b6180 = data_ov000_021b6180 + 1;
        c->mUnk_004 = 0;
    }
    h[0] = c->mUnk_006 >> 8;
    h[1] = c->mUnk_006;
    h += 2;
    *h++ = 0;
    if (c->mUnk_004 == 0) {
        if (e != 0) {
            h[0] = 0xb;
            i = e + 6;
            h[1] = i >> 16;
            h[2] = i >> 8;
            h[3] = i;
            i = e + 3;
            h[4] = i >> 16;
            h[5] = i >> 8;
            h[6] = i;
            h[7] = e >> 16;
            h[8] = e >> 8;
            h += 9;
            *h++ = e;
            MemCopy(d->mUnk_04, h, e);
            h += e;
        }
        h[0] = 0xe;
        h[1] = 0;
        h[2] = 0;
        h += 3;
        *h++ = 0;
    }
    i = h - g - 5;
    g[0] = 0x16;
    g[1] = 3;
    g[2] = 0;
    g[3] = i >> 8;
    g[4] = i;
    func_ov000_021abca0(c->mUnk_2c0, g + 5, i);
    func_ov000_021ab728(c->mUnk_378, g + 5, i);
    func_ov000_021adcec(g, i + 5, NULL, 0, a);
    data_ov000_021b63ac(g);
    return c->mUnk_004;
}
