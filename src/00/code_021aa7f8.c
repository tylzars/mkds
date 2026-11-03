#include "00/code_021aa7f8.h"
#include "00/code_021ab728.h"
#include "00/code_021abca0.h"
#include "00/code_021ac3e4.h"
#include "00/code_021aaaec.h"
#include "00/code_021aaaf8.h"
#include "00/code_021ab000.h"
#include "00/code_021ab5bc.h"
#include "00/code_021ab6d4.h"
#include "00/code_021ab7b4.h"
#include "00/code_021abc24.h"
#include "00/code_021abd2c.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b6000.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_021acbf8.h"
#include "00/code_021acc8c.h"

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
                func_0214d1fc(b, a->mUnk_008, 0x20);
            } else {
                func_0214d168(a->mUnk_008, 0, 0x20 - y);
                func_0214d1fc(b, a->mUnk_028 - y, y);
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
        func_0214d1fc(b + 2, a->mUnk_008, 0x20);
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
