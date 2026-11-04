#include "00/code_021aaaf8.h"
#include "00/code_021aae2c.h"
#include "00/code_021aae44.h"
#include "00/code_021ab5bc.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b6000.h"
#include "code_02134d30.h"
#include "code_0214d018.h"
#include "code_0214d954.h"

u32 func_ov000_021aaaf8(const u8 *a, s32 b, s32 c) {
    u32 i;
    const u16 *p;
    for (i = 0, p = data_ov000_021b4a00; i < 2; p++, i++) {
        if (func_ov000_021aab3c(a, b, c, *p) != 0) {
            return data_ov000_021b4a00[i];
        }
    }
    return 0;
}

BOOL func_ov000_021aab3c(const u8 *a, s32 b, s32 c, u32 d) {
    s32 i;
    u32 e;
    for (i = 0; i < b; i++) {
        e = (a[0] << 8) + a[1];
        if (c == 3) {
            e = (e << 8) + a[2];
        }
        if (e == d) {
            return TRUE;
        }
        a += c;
    }
    return FALSE;
}

// non-matching: one instruction order, ours loads ldrb r6, [r0] before adds r4, #0x23 and the original after; same size
void func_ov000_021aab74(Unk021a998c_0c *a, u8 *b) {
    u8 n;
    u8 *c;
    u8 *p;
    Unk021ab5e4 *s;
    MemCopy(b + 2, a->mUnk_028, 0x20);
    n = b[0x22];
    c = b + 0x23;
    s = a->mUnk_000;
    if (s != NULL && n == 0x20 && memcmp(s->mUnk_00, c, 0x20) == 0) {
        a->mUnk_004 = 1;
    } else {
        if (s != NULL) {
            s->mUnk_5a = 0;
        }
        if (n == 0) {
            a->mUnk_000 = &data_ov000_021b6198;
        } else {
            a->mUnk_000 = func_ov000_021ab5e4(c);
        }
        a->mUnk_004 = 0;
    }
    p = c + n;
    a->mUnk_006 = (p[0] << 8) + p[1];
    a->mUnk_429 = 2;
}

void func_ov000_021aabf0(Unk021a998c_0c *a, u8 *b) {
    s32 i;
    s32 n;
    u32 f;
    u32 t;
    BOOL m;
    s32 k;
    u8 *q;
    u32 d[4];
    n = (((b[0] << 8) + b[1]) << 8) + b[2];
    b += 3;
    a->mUnk_430 = -1;
    func_0214e038(d);
    a->mUnk_7e0 = d[2] + (((d[0] + 0x7d0) << 16) + (d[1] << 8));
    a->mUnk_684[0] = 0;
    a->mUnk_568 = a->mUnk_574 = 0;
    m = FALSE;
    i = m;
    for (;;) {
        k = (((b[0] << 8) + b[1]) << 8) + b[2];
        b += 3;
        n -= k + 3;
        a->mUnk_42c = -1;
        a->mUnk_581 = 0;
        a->mUnk_580 = 0;
        a->mUnk_583 = 0;
        a->mUnk_684[0] = 0;
        a->mUnk_584[0] = 0;
        a->mUnk_784[0] = 0;
        a->mUnk_7d8 = b;
        a->mUnk_7dc = k;
        if (func_ov000_021ab09c(a, &b, 0, 0, m) != 0 || a->mUnk_568 < 0x33 || a->mUnk_574 == 0) {
            a->mUnk_429 = 9;
            return;
        }
        f = func_ov000_021aae44(a);
        if (i == 0 && a->mUnk_7d4 != NULL && func_ov000_021aadcc(a->mUnk_7d4, a->mUnk_784) != 0) {
            f |= 0x4000;
        }
        t = f & 0xff;
        if (t == 1 && n != 0) {
            q = b + 3;
            a->mUnk_581 = 0;
            if (func_ov000_021ab09c(a, &q, 0, 0, 2) != 0) {
                a->mUnk_429 = 9;
                return;
            }
            f = (f & ~0xff) | func_ov000_021aaf38(a, &a->mUnk_454);
        }
        if (a->mUnk_7e4 != NULL) {
            f = a->mUnk_7e4(f, a, i);
        }
        i++;
        if (t != 0 && f == 0 && n != 0) {
            m = TRUE;
            continue;
        }
        break;
    }
    if (f == 0) {
        a->mUnk_429 = 3;
    } else {
        a->mUnk_429 = 9;
    }
}

BOOL func_ov000_021aadcc(const s8 *a, const s8 *b) {
    s32 x;
    s32 y;
    s8 c;
    s8 d;
    for (;;) {
        while ((d = *a++) == (c = *b++)) {
            if (d == 0) {
                return FALSE;
            }
        }
        if (c != '*') {
            return TRUE;
        }
        a--;
        x = func_ov000_021aae2c(a);
        y = func_ov000_021aae2c(b);
        if (y > x) {
            return TRUE;
        }
        a += x - y;
    }
}
