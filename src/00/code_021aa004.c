#include "00/code_021aa004.h"

#include "00/code_021adbac.h"
#include "code_0214d018.h"
#include "00/code_021ab6d4.h"
#include "00/code_021ab728.h"
#include "00/code_021ab7b4.h"
#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021abd2c.h"
#include "00/code_021ac3e4.h"
#include "00/types_021a998c.h"
#include "00/code_021ab000.h"
#include "code_02134d30.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b4000.h"
#include "00/code_021aaaf8.h"
#include "00/code_021aae44.h"
#include "00/unk_021b6000.h"
#include "code_02139f70.h"
#include "00/code_021acbf8.h"
#include "00/code_021acc8c.h"

u32 func_ov000_021aaaec(int a, int b) {
    if (a == 3) {
        return 1;
    }
    return 0;
}

void func_ov000_021aaa58(Unk021a998c_0c *a, u8 *b) {
    s32 n;
    u16 m;
    s32 x;
    s32 y;
    if (func_ov000_021aaaec(b[0], b[1]) != 0) {
        n = (b[2] << 8) + b[3];
        m = func_ov000_021aaaf8(b + 8, n / 3, 3);
        if (m != 0) {
            a->mUnk_006 = m;
            x = (b[4] << 8) + b[5];
            y = (b[6] << 8) + b[7];
            a->mUnk_000 = NULL;
            b += n + 8 + x;
            if (y >= 0x20) {
                MemCopy(b, a->mUnk_008, 0x20);
            } else {
                MemFill(a->mUnk_008, 0, 0x20 - y);
                MemCopy(b, a->mUnk_028 - y, y);
            }
            a->mUnk_429 = 1;
        }
    }
}

void func_ov000_021aa9ec(Unk021a998c_0c *a, const u8 *b) {
    u8 n;
    u16 m;
    const u8 *c;
    if (func_ov000_021aaaec(b[0], b[1]) != 0) {
        MemCopy(b + 2, a->mUnk_008, 0x20);
        n = b[0x22];
        c = b + 0x23;
        if (n != 0x20) {
            a->mUnk_000 = NULL;
        } else {
            a->mUnk_000 = func_ov000_021ab684(c);
        }
        c += n;
        m = func_ov000_021aaaf8(c + 2, ((c[0] << 8) + c[1]) / 2, 2);
        a->mUnk_006 = m;
        if (m != 0) {
            a->mUnk_429 = 1;
        }
    }
}

void func_ov000_021aa880(u8 *a, const u8 *b, Unk021aa880 *c) {
    u16 *d;
    u16 *e;
    u16 *f;
    u16 *g;
    u16 *h;
    u16 *i;
    u16 *j;
    u16 *k;
    s32 n;
    if (c == NULL || c->mUnk_00 == 0) {
        return;
    }
    n = c->mUnk_00 * 2;
    n = n / 2 + 1;
    d = (u16 *) data_ov000_021b63a4(n * 0x14);
    if (d == NULL) {
        return;
    }
    e = d + n;
    f = e + n;
    g = f + n;
    h = g + n;
    i = h + n;
    j = i + n;
    k = j + n;
    func_ov000_021ac4b8(d, b, c->mUnk_00, n);
    func_ov000_021ac4b8(e, c->mUnk_1c, c->mUnk_18, n);
    func_ov000_021ac4b8(i, c->mUnk_0c, c->mUnk_08, n);
    func_ov000_021ac4f4(g, d, e, n, i);
    func_ov000_021ac4b8(e, c->mUnk_24, c->mUnk_20, n);
    func_ov000_021ac4b8(i, c->mUnk_14, c->mUnk_10, n);
    func_ov000_021ac4f4(h, d, e, n, i);
    func_ov000_021acd24(d, g, h, n);
    func_ov000_021ac4b8(e, c->mUnk_2c, c->mUnk_28, n);
    func_ov000_021acbf8(f, d, e, n);
    func_ov000_021ac4b8(e, c->mUnk_14, c->mUnk_10, n);
    func_ov000_021acbf8(d, f, e, n);
    func_ov000_021ace14(f, d, h, n);
    func_ov000_021ac4b8(e, c->mUnk_04, c->mUnk_00, n);
    if (func_ov000_021ace90(f, n) < 0) {
        func_ov000_021acda8(f, n);
        func_ov000_021ac900(NULL, f, e, j, n, k);
        func_ov000_021acd24(j, e, j, n);
    } else {
        func_ov000_021ac900(NULL, f, e, j, n, k);
    }
    func_ov000_021ac488(a, j, 0x30, n);
    data_ov000_021b63ac(d);
}

void func_ov000_021aa7f8(u8 *a, const u8 *b, Unk021a998c_0c *c) {
    u8 d[0x14];
    u32 *e;
    e = (u32 *) c->mUnk_31c;
    func_ov000_021abd2c(e);
    func_ov000_021abca0(e, b, strlen((const char *) b));
    func_ov000_021abca0(e, c->mUnk_000->mUnk_20, 0x30);
    func_ov000_021abca0(e, c->mUnk_008, 0x20);
    func_ov000_021abca0(e, c->mUnk_028, 0x20);
    func_ov000_021abc4c((s32) e, (u32) d);
    e = (u32 *) c->mUnk_3d0;
    func_ov000_021ab7b4(e);
    func_ov000_021ab728(e, c->mUnk_000->mUnk_20, 0x30);
    func_ov000_021ab728(e, d, 0x14);
    func_ov000_021ab6d4((s32) e, (u32) a);
}

void func_ov000_021aa7b4(Unk021a998c_0c *a) {
    u8 v1[16];
    u8 v2[16];
    u8 v3[16];
    func_ov000_021aa7f8(v1, data_ov000_021b4a58, a);
    func_ov000_021aa7f8(v2, data_ov000_021b4a5c, a);
    func_ov000_021aa7f8(v3, data_ov000_021b4a60, a);
    MemCopy(v1, a->mUnk_000->mUnk_20, 0x30);
    return;
}

void func_ov000_021aa5e0(Unk021a998c_0c *a) {
    s32 x;
    s32 y;
    s32 z;
    s32 n;
    s32 o;
    s32 i;
    s32 j;
    u8 c[0x15];
    u32 *h;
    switch (a->mUnk_006) {
        case 4:
            x = 0x10;
            y = 0x10;
            z = 0;
            break;
        case 5:
            x = 0x14;
            y = 0x10;
            z = 0;
            break;
    }
    n = (x + y + z) * 2;
    i = 0;
    if (n > 0) {
        o = 0;
        do {
            h = (u32 *) a->mUnk_31c;
            func_ov000_021abd2c(h);
            c[0] = i + 0x41;
            for (j = 0; j < i + 1; j++) {
                func_ov000_021abca0(h, c, 1);
            }
            func_ov000_021abca0(h, a->mUnk_000->mUnk_20, 0x30);
            func_ov000_021abca0(h, a->mUnk_028, 0x20);
            func_ov000_021abca0(h, a->mUnk_008, 0x20);
            func_ov000_021abc4c((s32) h, (u32) (c + 1));
            h = (u32 *) a->mUnk_3d0;
            func_ov000_021ab7b4(h);
            func_ov000_021ab728(h, a->mUnk_000->mUnk_20, 0x30);
            func_ov000_021ab728(h, c + 1, 0x14);
            func_ov000_021ab6d4((s32) h, (u32) (a->mUnk_048 + o));
            o += 0x10;
            i++;
        } while (o < n);
    }
    if (a->mUnk_428 != 0) {
        a->mUnk_1a8 = a->mUnk_048;
        a->mUnk_1ac = a->mUnk_1a8 + x * 2;
        a->mUnk_1b0 = a->mUnk_1ac + y * 2;
        a->mUnk_090 = a->mUnk_048 + x;
        a->mUnk_094 = a->mUnk_090 + x + y;
        a->mUnk_098 = a->mUnk_094 + y + z;
    } else {
        a->mUnk_090 = a->mUnk_048;
        a->mUnk_094 = a->mUnk_090 + x * 2;
        a->mUnk_098 = a->mUnk_094 + y * 2;
        a->mUnk_1a8 = a->mUnk_048 + x;
        a->mUnk_1ac = a->mUnk_1a8 + x + y;
        a->mUnk_1b0 = a->mUnk_1ac + y + z;
    }
    func_ov000_021ac434(a->mUnk_1b4, a->mUnk_1ac, 0x10);
    func_ov000_021ac434(a->mUnk_09c, a->mUnk_094, 0x10);
}

void func_ov000_021aa5b0(Unk021a998c_0c *a, const u8 *b) {
    func_ov000_021aa880(a->mUnk_000->mUnk_20, b, a->mUnk_7f0);
    func_ov000_021aa7b4(a);
    func_ov000_021aa5e0(a);
    a->mUnk_429 = 5;
}

void func_ov000_021aa50c(Unk021a998c_0c *a, u8 *b, u32 c) {
    u8 d[0x30];
    u32 *e;
    e = (u32 *) a->mUnk_378;
    if ((a->mUnk_428 ^ c) != 0) {
        func_ov000_021ab728(e, data_ov000_021b4a48, 4);
    } else {
        func_ov000_021ab728(e, data_ov000_021b4a50, 4);
    }
    func_ov000_021ab728(e, a->mUnk_000->mUnk_20, 0x30);
    MemFill(d, 0x36, 0x30);
    func_ov000_021ab728(e, d, 0x30);
    func_ov000_021ab6d4((s32) e, (u32) b);
    func_ov000_021ab7b4(e);
    func_ov000_021ab728(e, a->mUnk_000->mUnk_20, 0x30);
    MemFill(d, 0x5c, 0x30);
    func_ov000_021ab728(e, d, 0x30);
    func_ov000_021ab728(e, b, 0x10);
    func_ov000_021ab6d4((s32) e, (u32) b);
}

void func_ov000_021aa468(Unk021a998c_0c *a, u8 *b, u32 c) {
    u8 d[0x28];
    u32 *e;
    e = (u32 *) a->mUnk_2c0;
    if ((a->mUnk_428 ^ c) != 0) {
        func_ov000_021abca0(e, data_ov000_021b4a48, 4);
    } else {
        func_ov000_021abca0(e, data_ov000_021b4a50, 4);
    }
    func_ov000_021abca0(e, a->mUnk_000->mUnk_20, 0x30);
    MemFill(d, 0x36, 0x28);
    func_ov000_021abca0(e, d, 0x28);
    func_ov000_021abc4c((s32) e, (u32) b);
    func_ov000_021abd2c(e);
    func_ov000_021abca0(e, a->mUnk_000->mUnk_20, 0x30);
    MemFill(d, 0x5c, 0x28);
    func_ov000_021abca0(e, d, 0x28);
    func_ov000_021abca0(e, b, 0x14);
    func_ov000_021abc4c((s32) e, (u32) b);
}

void func_ov000_021aa3b8(Unk021a998c_0c *a, u8 *b) {
    int v1;
    u8 v2[20];
    MemCopy(a->mUnk_378, a->mUnk_3d0, 0x58);
    func_ov000_021aa50c(a, v2, 1);
    MemCopy(a->mUnk_3d0, a->mUnk_378, 0x58);
    v1 = memcmp(b, v2, 0x10);
    if (v1 != 0) {
        a->mUnk_429 = 9;
        return;
    }
    MemCopy(a->mUnk_2c0, a->mUnk_31c, 0x5c);
    func_ov000_021aa468(a, v2, 1);
    MemCopy(a->mUnk_31c, a->mUnk_2c0, 0x5c);
    v1 = memcmp(b + 0x10, v2, 0x14);
    if (v1 != 0) {
        a->mUnk_429 = 9;
        return;
    }
    a->mUnk_429 = 6;
}

void func_ov000_021aa398(u8 *bytes, s32 count) {
    s32 i;
    bytes += count;
    for (i = 0; i < count; i++) {
        bytes--;
        (*bytes)++;
        if (*bytes != 0) {
            break;
        }
    }
}

u32 func_ov000_021aa380(u32 p0, u32 p1, u32 p2) {
    u32 v1 = ((p2) + (0x0u));
    u32 v2 = 0x1b4u;
    u32 v3 = ((p0) + (v2));
    u32 v5;
    func_ov000_021ac3e4((u8 *) v3, (u8 *) p1, (s32) p2);
    v5 = ((v1) + (0x0u));
    return v5;
}

s32 func_ov000_021aa1e0(Unk021a998c_0c *a, u8 *b) {
    u8 c[0x14];
    u8 d[0x30];
    s32 e;
    u32 f;
    u32 *g;
    e = func_ov000_021aa380((u32) a, (u32) (b + 5), (b[3] << 8) + b[4]);
    switch (a->mUnk_006) {
        case 4:
            e -= 0x10;
            b[3] = e >> 8;
            b[4] = e;
            g = (u32 *) a->mUnk_3d0;
            func_ov000_021ab7b4(g);
            func_ov000_021ab728(g, a->mUnk_1a8, 0x10);
            MemFill(d, 0x36, 0x30);
            func_ov000_021ab728(g, d, 0x30);
            func_ov000_021ab728(g, a->mUnk_2b8, 8);
            func_ov000_021ab728(g, b, 1);
            func_ov000_021ab728(g, b + 3, 2);
            func_ov000_021ab728(g, b + 5, e);
            func_ov000_021ab6d4((s32) g, (u32) c);
            func_ov000_021ab7b4(g);
            func_ov000_021ab728(g, a->mUnk_1a8, 0x10);
            MemFill(d, 0x5c, 0x30);
            func_ov000_021ab728(g, d, 0x30);
            func_ov000_021ab728(g, c, 0x10);
            func_ov000_021ab6d4((s32) g, (u32) c);
            f = 0x10;
            break;
        case 5:
            e -= 0x14;
            b[3] = e >> 8;
            b[4] = e;
            g = (u32 *) a->mUnk_31c;
            func_ov000_021abd2c(g);
            func_ov000_021abca0(g, a->mUnk_1a8, 0x14);
            MemFill(d, 0x36, 0x28);
            func_ov000_021abca0(g, d, 0x28);
            func_ov000_021abca0(g, a->mUnk_2b8, 8);
            func_ov000_021abca0(g, b, 1);
            func_ov000_021abca0(g, b + 3, 2);
            func_ov000_021abca0(g, b + 5, e);
            func_ov000_021abc4c((s32) g, (u32) c);
            func_ov000_021abd2c(g);
            func_ov000_021abca0(g, a->mUnk_1a8, 0x14);
            MemFill(d, 0x5c, 0x28);
            func_ov000_021abca0(g, d, 0x28);
            func_ov000_021abca0(g, c, 0x14);
            func_ov000_021abc4c((s32) g, (u32) c);
            f = 0x14;
            break;
    }
    if (memcmp(b + 5 + e, c, f) != 0) {
        a->mUnk_429 = 9;
    }
    func_ov000_021aa398(a->mUnk_2b8, 8);
    return e + 5;
}

s32 func_ov000_021aa054(void *g, u8 *h) {
    Unk021a998c_0c *a = g;
    u8 *b = h;
    s32 c = (b[3] << 8) + b[4];
    u8 *d = b + 5 + c;
    u8 e[0x30];
    u8 *f;
    switch (a->mUnk_006) {
        case 4:
            f = a->mUnk_3d0;
            func_ov000_021ab7b4((u32 *) f);
            func_ov000_021ab728(f, a->mUnk_090, 0x10);
            MemFill(e, 0x36, 0x30);
            func_ov000_021ab728(f, e, 0x30);
            func_ov000_021ab728(f, a->mUnk_1a0, 8);
            func_ov000_021ab728(f, b, 1);
            func_ov000_021ab728(f, b + 3, 2);
            func_ov000_021ab728(f, b + 5, c);
            func_ov000_021ab6d4((s32) f, (u32) d);
            func_ov000_021ab7b4((u32 *) f);
            func_ov000_021ab728(f, a->mUnk_090, 0x10);
            MemFill(e, 0x5c, 0x30);
            func_ov000_021ab728(f, e, 0x30);
            func_ov000_021ab728(f, d, 0x10);
            func_ov000_021ab6d4((s32) f, (u32) d);
            c += 0x10;
            break;
        case 5:
            f = a->mUnk_31c;
            func_ov000_021abd2c((u32 *) f);
            func_ov000_021abca0(f, a->mUnk_090, 0x14);
            MemFill(e, 0x36, 0x28);
            func_ov000_021abca0(f, e, 0x28);
            func_ov000_021abca0(f, a->mUnk_1a0, 8);
            func_ov000_021abca0(f, b, 1);
            func_ov000_021abca0(f, b + 3, 2);
            func_ov000_021abca0(f, b + 5, c);
            func_ov000_021abc4c((s32) f, (u32) d);
            func_ov000_021abd2c((u32 *) f);
            func_ov000_021abca0(f, a->mUnk_090, 0x14);
            MemFill(e, 0x5c, 0x28);
            func_ov000_021abca0(f, e, 0x28);
            func_ov000_021abca0(f, d, 0x14);
            func_ov000_021abc4c((s32) f, (u32) d);
            c += 0x14;
            break;
    }
    b[3] = c >> 8;
    b[4] = c;
    func_ov000_021ac3e4((u8 *) a->mUnk_09c, (u8 *) (b + 5), c);
    func_ov000_021aa398(a->mUnk_1a0, 8);
    return c + 5;
}

u32 func_ov000_021aa004(u8 *a, s32 b, Unk021a998c *c) {
    u8 *v1;
    u32 v2;
    do {
        v1 = func_ov000_021adfc8(&v2, c);
        if (v2 == 0) {
            return 0xffffffff;
        }
        if (v2 > b) {
            v2 = b;
        }
        MemCopy(v1, a, v2);
        func_ov000_021adf30(v2, c);
        a = a + v2;
        b = b - v2;
    } while (0 < b);
    return 0;
}
