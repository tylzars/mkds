#include "00/code_021a9228.h"

#include "00/code_021ab6d4.h"
#include "00/code_021abd2c.h"
#include "00/code_021ad734.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b6000.h"
#include "code_0214d018.h"
#include "00/code_021abca0.h"
#include "code_0200db4c.h"
#include "00/code_021abc24.h"
#include "code_0200fc8c.h"
#include "00/code_021ac3e4.h"
#include "00/code_021ab000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/unk_021b4000.h"
#include "code_02139f70.h"
#include "00/code_021acbf8.h"
#include "00/code_021acc8c.h"
#include "code_0214d93c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200f5ac.h"
#include "code_0214e1e0.h"

Unk021ab5e4 *func_ov000_021ab684(const u8 *a) {
    s32 i;
    Unk021ab5e4 *e;
    i = 0;
    e = data_ov000_021b61f4;
    for (; i < 4; i++) {
        if (e->mUnk_5a != 0 && memcmp(e->mUnk_00, a, 0x20) == 0) {
            e->mUnk_50 = OS_GetTick() >> 16;
            return e;
        }
        e++;
    }
    return NULL;
}

Unk021ab5e4 *func_ov000_021ab63c(u32 a, u32 b) {
    Unk021ab5e4 *e;
    s32 i;
    i = 0;
    e = data_ov000_021b61f4;
    for (; i < 4; i++) {
        if (e->mUnk_5a != 0 && e->mUnk_54 == a && e->mUnk_58 == b) {
            e->mUnk_50 = OS_GetTick() >> 16;
            return e;
        }
        e++;
    }
    return NULL;
}

Unk021ab5e4 *func_ov000_021ab5e4(const u8 *a) {
    Unk021ab5e4 *v1;
    u32 t;
    s32 i;
    u32 v2;
    u32 v3;
    Unk021ab5e4 *e;
    t = OS_GetTick() >> 16;
    v3 = 0;
    v1 = data_ov000_021b61f4;
    i = 0;
    e = v1;
    for (; i < 4; i++) {
        if (e->mUnk_5a == 0) {
            v1 = e;
            break;
        }
        v2 = t - e->mUnk_50;
        if (v2 > v3) {
            v3 = v2;
            v1 = e;
        }
        e++;
    }
    MI_CpuCopy8(a, v1, 0x20);
    v1->mUnk_50 = t;
    v1->mUnk_5a = 1;
    return v1;
}

u32 func_ov000_021ab5bc(void) {
    RTCDate a;
    RTCTime b;
    RTC_GetDate(&a);
    RTC_GetTime(&b);
    return (u32) RTC_ConvertDateTimeToSecond(&a, &b) + 0x386d4380;
}

void func_ov000_021ab594(u32 a, u32 b) {
    Unk021a998c *v1;
    Unk021a998c_0c *v2;
    v1 = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if ((v1 != NULL) && (v2 = v1->mUnk_0c, v2 != NULL)) {
        v2->mUnk_7e8 = a;
        v2->mUnk_7ec = b;
    }
}

u32 func_ov000_021ab548(Unk021a998c_0c *a, const s8 *b) {
    int v1;
    int v2;
    u32 *v3;
    u32 *v4;
    int v5;
    v2 = 0;
    v1 = a->mUnk_7ec;
    if (0 < v1) {
        v4 = (u32 *) a->mUnk_7e8;
        v3 = v4;
        do {
            v5 = strcmp((const char *) (*(u32 *) *v3), (const char *) b);
            if (v5 == 0) {
                return v4[v2];
            }
            v3 = v3 + 1;
            v2 = v2 + 1;
        } while (v2 < v1);
    }
    return 0;
}

s32 func_ov000_021ab4f8(u8 **a) {
    u8 *p;
    s32 x;
    u32 k;
    p = *a;
    x = *p++;
    if ((x & 0x80) != 0) {
        k = x & 0x7f;
        x = 0;
        while (k-- != 0) {
            if ((x & 0xff000000) != 0) {
                return -1;
            }
            x = (x << 8) + *p++;
        }
    }
    *a = p;
    return x;
}

void func_ov000_021ab4b0(s8 *a, const s8 *b, s32 c) {
    s8 *d;
    d = a;
    if (*a != 0) {
        do {
            a++;
        } while (*a != 0);
        if (a - d >= 0xff) {
            return;
        }
        *a++ = ',';
        *a++ = ' ';
    }
    while (c-- != 0 && a - d < 0xff) {
        *a++ = *b++;
    }
    *a = 0;
}

u32 func_ov000_021ab448(const u8 *a, u32 b) {
    u32 x;
    u32 y;
    x = a[1] + a[0] * 10 - 0x210;
    a += 2;
    if (b == 0x17) {
        if (x < 0x32) {
            y = x + 0x7d0;
        } else {
            y = x + 0x76c;
        }
    } else {
        y = x * 100 + (a[1] + a[0] * 10 - 0x210);
        a += 2;
    }
    return (y << 16) + ((a[1] + a[0] * 10 - 0x210) << 8) + (a[3] + a[2] * 10 - 0x210);
}

BOOL func_ov000_021ab09c(Unk021a998c_0c *a, u8 **b, s32 c, s32 d, s32 e) {
    u8 *p;
    u32 t;
    u32 k;
    s32 n;
    u8 *v1;
    s32 i;
    u8 *q;
    const char *s;
    const char **v2;
    u32 v;
    p = *b;
    t = *p++;
    n = func_ov000_021ab4f8(&p);
    if (n < 0 || n > 0x7d0) {
        return TRUE;
    }
    k = t & 0x1f;
    switch (k) {
        case 2:
            if (a->mUnk_581 != 0) {
                if (d == 0) {
                    while (*p == 0) {
                        p++;
                        n--;
                    }
                    switch (e) {
                        case 0:
                            if (n <= 0x100) {
                                MI_CpuCopy8(p, a->mUnk_468, n);
                                a->mUnk_568 = n;
                            }
                            break;
                        case 2:
                            a->mUnk_454.mUnk_04 = n;
                            a->mUnk_454.mUnk_08 = p;
                            break;
                    }
                } else if (d == 1) {
                    while (*p == 0) {
                        p++;
                        n--;
                    }
                    switch (e) {
                        case 0:
                            if (n <= 8) {
                                MI_CpuCopy8(p, a->mUnk_56c, n);
                                a->mUnk_574 = n;
                            }
                            break;
                        case 2:
                            a->mUnk_454.mUnk_0c = n;
                            a->mUnk_454.mUnk_10 = p;
                            break;
                    }
                }
            }
            p += n;
            break;
        case 3:
            if (c == 1 && e != 2) {
                a->mUnk_578 = p + 1;
                a->mUnk_57c = n - 1;
            }
            if (a->mUnk_581 != 0) {
                p++;
                if (func_ov000_021ab09c(a, &p, c, 0, e) != FALSE) {
                    return TRUE;
                }
                a->mUnk_581 = 0;
            } else {
                p += n;
            }
            break;
        case 6:
            i = 0;
            v2 = data_ov000_021b4a30;
            q = p;
            do {
                s = *v2;
                if (memcmp(q, s, strlen(s)) == 0) {
                    switch (i) {
                        case 1:
                        case 2:
                            if (e == 0) {
                                a->mUnk_430 = i;
                            }
                            a->mUnk_581 = i;
                            break;
                        case 3:
                        case 4:
                            if (e != 2) {
                                a->mUnk_42c = i;
                            }
                            break;
                        case 5:
                            if (e != 2) {
                                a->mUnk_582 = i;
                            }
                            break;
                    }
                    break;
                }
                v2++;
                i++;
            } while (i < 6);
            p += n;
            break;
        case 0xc:
        case 0x13:
        case 0x14:
        case 0x16:
            if (e != 2) {
                if (a->mUnk_580 != 0) {
                    func_ov000_021ab4b0(a->mUnk_684, (const s8 *) p, n);
                    if (a->mUnk_582 == 5 && n <= 0x4f) {
                        MI_CpuCopy8(p, a->mUnk_784, n);
                        a->mUnk_784[n] = 0;
                    }
                } else {
                    func_ov000_021ab4b0(a->mUnk_584, (const s8 *) p, n);
                }
            }
            a->mUnk_582 = 0;
            p += n;
            break;
        case 0x17:
        case 0x18:
            if (e != 2) {
                v = func_ov000_021ab448(p, k);
                if (d == 0) {
                    if (a->mUnk_7e0 >= v) {
                        a->mUnk_583 = 1;
                    }
                } else {
                    if (a->mUnk_7e0 > v) {
                        a->mUnk_583 = 0;
                    }
                }
            }
            p += n;
            a->mUnk_580 = 1;
            break;
        case 0x10:
            if (c == 0 && d == 0 && e != 2) {
                a->mUnk_434 = p;
            }
            v1 = p + n;
            n = 0;
            if (p < v1) {
                do {
                    i = func_ov000_021ab09c(a, &p, c + 1, n, e);
                    n++;
                    if (i != 0) {
                        return TRUE;
                    }
                } while (p < v1);
            }
            if (c == 1 && d == 0 && e != 2) {
                a->mUnk_438 = p;
            }
            break;
        case 0x11:
            v1 = p + n;
            if (p < v1) {
                do {
                    if (func_ov000_021ab09c(a, &p, c + 1, 0, e) != FALSE) {
                        return TRUE;
                    }
                } while (p < v1);
            }
            break;
        default:
            if (t == 0xa0) {
                v1 = p + n;
                if (p < v1) {
                    do {
                        if (func_ov000_021ab09c(a, &p, c + 1, 0, e) != FALSE) {
                            return TRUE;
                        }
                    } while (p < v1);
                }
            } else {
                p += n;
            }
            break;
    }
    *b = p;
    return FALSE;
}

u32 func_ov000_021aaf38(Unk021a998c_0c *a, Unk021aaf38 *b) {
    s32 n;
    u16 *c;
    u16 *d;
    u16 *e;
    u16 *f;
    u32 g;
    OSThread *t;
    u32 r;
    enum { K0 } i;
    if (a->mUnk_578 == NULL || a->mUnk_57c == 0 || b->mUnk_10 == NULL || b->mUnk_0c == 0 || b->mUnk_08 == NULL ||
        b->mUnk_04 == 0) {
        return 2;
    }
    n = b->mUnk_04 * 2;
    n = n / 2;
    c = (u16 *) data_ov000_021b63a4(n * 8);
    if (c == NULL) {
        return 2;
    }
    d = c + n;
    e = d + n;
    f = e + n;
    func_ov000_021ac4b8(d, a->mUnk_578, a->mUnk_57c, n);
    func_ov000_021ac4b8(e, b->mUnk_10, b->mUnk_0c, n);
    func_ov000_021ac4b8(f, b->mUnk_08, b->mUnk_04, n);
    if (data_ov000_021b49f4 < 0x20) {
        t = data_0216ff5c.mCurrentThread;
        g = OS_GetThreadPriority(t);
        OS_SetThreadPriority(t, data_ov000_021b49f4);
        func_ov000_021ac7e8(c, d, e, n, f);
        OS_SetThreadPriority(t, g);
    } else {
        func_ov000_021ac7e8(c, d, e, n, f);
    }
    func_ov000_021ac488((u8 *) d, c, b->mUnk_04, n);
    r = 0;
    if (((u8 *) d)[0] != 0 || ((u8 *) d)[1] != 1) {
        r = 2;
    } else {
        i = 2;
        if (b->mUnk_04 > 2) {
            do {
                if (((u8 *) d)[i] != 0xff) {
                    break;
                }
                i++;
            } while (i < b->mUnk_04);
        }
        if (i + 1 >= b->mUnk_04 || ((u8 *) d)[i] != 0 || ((u8 *) d)[i + 1] != 0x30 ||
            memcmp(a->mUnk_43c, (u8 *) d + b->mUnk_04 - a->mUnk_450, a->mUnk_450) != 0) {
            r = 2;
        }
    }
    data_ov000_021b63ac(c);
    return r;
}

u32 func_ov000_021aae44(Unk021a998c_0c *a) {
    u32 f;
    Unk021ab728 *h;
    Unk021abca0 *g;
    u32 r;
    if (a->mUnk_583 != 0) {
        f = 0;
    } else {
        f = 0x8000;
    }
    if (a->mUnk_430 == -1) {
        f |= 4;
        return f;
    }
    switch (a->mUnk_42c) {
        case 3:
            h = &a->mUnk_3d0;
            func_ov000_021ab7b4(h);
            func_ov000_021ab728(h, a->mUnk_434, a->mUnk_438 - a->mUnk_434);
            func_ov000_021ab6d4(h, a->mUnk_43c);
            a->mUnk_450 = 0x10;
            break;
        case 4:
            g = &a->mUnk_31c;
            func_ov000_021abd2c(g);
            func_ov000_021abca0(g, a->mUnk_434, a->mUnk_438 - a->mUnk_434);
            func_ov000_021abc4c(g, a->mUnk_43c);
            a->mUnk_450 = 0x14;
            break;
        default:
            f |= 3;
            return f;
    }
    r = func_ov000_021ab548(a, a->mUnk_584);
    if (r == 0) {
        f |= 1;
        return f;
    }
    f |= func_ov000_021aaf38(a, (Unk021aaf38 *) r);
    return f;
}

s32 func_ov000_021aae2c(const s8 *text) {
    const s8 *start = text;
    while (*text != '.' && *text != 0) {
        text++;
    }
    return text - start;
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

void func_ov000_021aabf0(Unk021a998c_0c *a, u8 *b) {
    s32 i;
    s32 n;
    u32 f;
    u32 t;
    BOOL m;
    s32 k;
    u8 *q;
    RTCDate d;
    n = (((b[0] << 8) + b[1]) << 8) + b[2];
    b += 3;
    a->mUnk_430 = -1;
    RTC_GetDate(&d);
    a->mUnk_7e0 = d.mDay + (((d.mYear + 0x7d0) << 16) + (d.mMonth << 8));
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

void func_ov000_021aab74(Unk021a998c_0c *a, u8 *b) {
    u8 n;
    u8 *p;
    u8 *q;
    Unk021ab5e4 *s;
    MI_CpuCopy8(b + 2, a->mUnk_028, 0x20);
    q = b + 0x22;
    b = (u8 *) b + 0x23;
    n = *q;
    s = a->mUnk_000;
    if (s != NULL && n == 0x20 && memcmp(s->mUnk_00, b, 0x20) == 0) {
        a->mUnk_004 = 1;
    } else {
        if (s != NULL) {
            s->mUnk_5a = 0;
        }
        if (n == 0) {
            a->mUnk_000 = &data_ov000_021b6198;
        } else {
            a->mUnk_000 = func_ov000_021ab5e4(b);
        }
        a->mUnk_004 = 0;
    }
    p = b + n;
    a->mUnk_006 = (p[0] << 8) + p[1];
    a->mUnk_429 = 2;
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
                MI_CpuCopy8(b, a->mUnk_008, 0x20);
            } else {
                MI_CpuFill8(a->mUnk_008, 0, 0x20 - y);
                MI_CpuCopy8(b, a->mUnk_028 - y, y);
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
        MI_CpuCopy8(b + 2, a->mUnk_008, 0x20);
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
    Unk021abca0 *e;
    Unk021ab728 *g;
    e = &c->mUnk_31c;
    func_ov000_021abd2c(e);
    func_ov000_021abca0(e, b, strlen((const char *) b));
    func_ov000_021abca0(e, c->mUnk_000->mUnk_20, 0x30);
    func_ov000_021abca0(e, c->mUnk_008, 0x20);
    func_ov000_021abca0(e, c->mUnk_028, 0x20);
    func_ov000_021abc4c(e, d);
    g = &c->mUnk_3d0;
    func_ov000_021ab7b4(g);
    func_ov000_021ab728(g, c->mUnk_000->mUnk_20, 0x30);
    func_ov000_021ab728(g, d, 0x14);
    func_ov000_021ab6d4(g, a);
}

void func_ov000_021aa7b4(Unk021a998c_0c *a) {
    u8 v1[16];
    u8 v2[16];
    u8 v3[16];
    func_ov000_021aa7f8(v1, data_ov000_021b4a58, a);
    func_ov000_021aa7f8(v2, data_ov000_021b4a5c, a);
    func_ov000_021aa7f8(v3, data_ov000_021b4a60, a);
    MI_CpuCopy8(v1, a->mUnk_000->mUnk_20, 0x30);
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
    void *h;
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
            h = &a->mUnk_31c;
            func_ov000_021abd2c(h);
            c[0] = i + 0x41;
            for (j = 0; j < i + 1; j++) {
                func_ov000_021abca0(h, c, 1);
            }
            func_ov000_021abca0(h, a->mUnk_000->mUnk_20, 0x30);
            func_ov000_021abca0(h, a->mUnk_028, 0x20);
            func_ov000_021abca0(h, a->mUnk_008, 0x20);
            func_ov000_021abc4c(h, c + 1);
            h = &a->mUnk_3d0;
            func_ov000_021ab7b4(h);
            func_ov000_021ab728(h, a->mUnk_000->mUnk_20, 0x30);
            func_ov000_021ab728(h, c + 1, 0x14);
            func_ov000_021ab6d4(h, a->mUnk_048 + o);
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
    Unk021ab728 *e;
    e = &a->mUnk_378;
    if ((a->mUnk_428 ^ c) != 0) {
        func_ov000_021ab728(e, data_ov000_021b4a48, 4);
    } else {
        func_ov000_021ab728(e, data_ov000_021b4a50, 4);
    }
    func_ov000_021ab728(e, a->mUnk_000->mUnk_20, 0x30);
    MI_CpuFill8(d, 0x36, 0x30);
    func_ov000_021ab728(e, d, 0x30);
    func_ov000_021ab6d4(e, b);
    func_ov000_021ab7b4(e);
    func_ov000_021ab728(e, a->mUnk_000->mUnk_20, 0x30);
    MI_CpuFill8(d, 0x5c, 0x30);
    func_ov000_021ab728(e, d, 0x30);
    func_ov000_021ab728(e, b, 0x10);
    func_ov000_021ab6d4(e, b);
}

void func_ov000_021aa468(Unk021a998c_0c *a, u8 *b, u32 c) {
    u8 d[0x28];
    Unk021abca0 *e;
    e = &a->mUnk_2c0;
    if ((a->mUnk_428 ^ c) != 0) {
        func_ov000_021abca0(e, data_ov000_021b4a48, 4);
    } else {
        func_ov000_021abca0(e, data_ov000_021b4a50, 4);
    }
    func_ov000_021abca0(e, a->mUnk_000->mUnk_20, 0x30);
    MI_CpuFill8(d, 0x36, 0x28);
    func_ov000_021abca0(e, d, 0x28);
    func_ov000_021abc4c(e, b);
    func_ov000_021abd2c(e);
    func_ov000_021abca0(e, a->mUnk_000->mUnk_20, 0x30);
    MI_CpuFill8(d, 0x5c, 0x28);
    func_ov000_021abca0(e, d, 0x28);
    func_ov000_021abca0(e, b, 0x14);
    func_ov000_021abc4c(e, b);
}

void func_ov000_021aa3b8(Unk021a998c_0c *a, u8 *b) {
    int v1;
    u8 v2[20];
    MI_CpuCopy8(&a->mUnk_378, &a->mUnk_3d0, 0x58);
    func_ov000_021aa50c(a, v2, 1);
    MI_CpuCopy8(&a->mUnk_3d0, &a->mUnk_378, 0x58);
    v1 = memcmp(b, v2, 0x10);
    if (v1 != 0) {
        a->mUnk_429 = 9;
        return;
    }
    MI_CpuCopy8(&a->mUnk_2c0, &a->mUnk_31c, 0x5c);
    func_ov000_021aa468(a, v2, 1);
    MI_CpuCopy8(&a->mUnk_31c, &a->mUnk_2c0, 0x5c);
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

u32 func_ov000_021aa380(u32 p0, u8 *p1, u32 p2) {
    u32 v1 = ((p2) + (0x0u));
    u32 v2 = 0x1b4u;
    u32 v3 = ((p0) + (v2));
    u32 v5;
    func_ov000_021ac3e4((u8 *) v3, p1, (s32) p2);
    v5 = ((v1) + (0x0u));
    return v5;
}

s32 func_ov000_021aa1e0(Unk021a998c_0c *a, u8 *b) {
    u8 c[0x14];
    u8 d[0x30];
    s32 e;
    u32 f;
    Unk021ab728 *g;
    Unk021abca0 *h;
    e = func_ov000_021aa380((u32) a, (b + 5), (b[3] << 8) + b[4]);
    switch (a->mUnk_006) {
        case 4:
            e -= 0x10;
            b[3] = e >> 8;
            b[4] = e;
            g = &a->mUnk_3d0;
            func_ov000_021ab7b4(g);
            func_ov000_021ab728(g, a->mUnk_1a8, 0x10);
            MI_CpuFill8(d, 0x36, 0x30);
            func_ov000_021ab728(g, d, 0x30);
            func_ov000_021ab728(g, a->mUnk_2b8, 8);
            func_ov000_021ab728(g, b, 1);
            func_ov000_021ab728(g, b + 3, 2);
            func_ov000_021ab728(g, b + 5, e);
            func_ov000_021ab6d4(g, c);
            func_ov000_021ab7b4(g);
            func_ov000_021ab728(g, a->mUnk_1a8, 0x10);
            MI_CpuFill8(d, 0x5c, 0x30);
            func_ov000_021ab728(g, d, 0x30);
            func_ov000_021ab728(g, c, 0x10);
            func_ov000_021ab6d4(g, c);
            f = 0x10;
            break;
        case 5:
            e -= 0x14;
            b[3] = e >> 8;
            b[4] = e;
            h = &a->mUnk_31c;
            func_ov000_021abd2c(h);
            func_ov000_021abca0(h, a->mUnk_1a8, 0x14);
            MI_CpuFill8(d, 0x36, 0x28);
            func_ov000_021abca0(h, d, 0x28);
            func_ov000_021abca0(h, a->mUnk_2b8, 8);
            func_ov000_021abca0(h, b, 1);
            func_ov000_021abca0(h, b + 3, 2);
            func_ov000_021abca0(h, b + 5, e);
            func_ov000_021abc4c(h, c);
            func_ov000_021abd2c(h);
            func_ov000_021abca0(h, a->mUnk_1a8, 0x14);
            MI_CpuFill8(d, 0x5c, 0x28);
            func_ov000_021abca0(h, d, 0x28);
            func_ov000_021abca0(h, c, 0x14);
            func_ov000_021abc4c(h, c);
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
    Unk021ab728 *f;
    Unk021abca0 *g2;
    switch (a->mUnk_006) {
        case 4:
            f = &a->mUnk_3d0;
            func_ov000_021ab7b4(f);
            func_ov000_021ab728(f, a->mUnk_090, 0x10);
            MI_CpuFill8(e, 0x36, 0x30);
            func_ov000_021ab728(f, e, 0x30);
            func_ov000_021ab728(f, a->mUnk_1a0, 8);
            func_ov000_021ab728(f, b, 1);
            func_ov000_021ab728(f, b + 3, 2);
            func_ov000_021ab728(f, b + 5, c);
            func_ov000_021ab6d4(f, d);
            func_ov000_021ab7b4(f);
            func_ov000_021ab728(f, a->mUnk_090, 0x10);
            MI_CpuFill8(e, 0x5c, 0x30);
            func_ov000_021ab728(f, e, 0x30);
            func_ov000_021ab728(f, d, 0x10);
            func_ov000_021ab6d4(f, d);
            c += 0x10;
            break;
        case 5:
            g2 = &a->mUnk_31c;
            func_ov000_021abd2c(g2);
            func_ov000_021abca0(g2, a->mUnk_090, 0x14);
            MI_CpuFill8(e, 0x36, 0x28);
            func_ov000_021abca0(g2, e, 0x28);
            func_ov000_021abca0(g2, a->mUnk_1a0, 8);
            func_ov000_021abca0(g2, b, 1);
            func_ov000_021abca0(g2, b + 3, 2);
            func_ov000_021abca0(g2, b + 5, c);
            func_ov000_021abc4c(g2, d);
            func_ov000_021abd2c(g2);
            func_ov000_021abca0(g2, a->mUnk_090, 0x14);
            MI_CpuFill8(e, 0x5c, 0x28);
            func_ov000_021abca0(g2, e, 0x28);
            func_ov000_021abca0(g2, d, 0x14);
            func_ov000_021abc4c(g2, d);
            c += 0x14;
            break;
    }
    b[3] = c >> 8;
    b[4] = c;
    func_ov000_021ac3e4(a->mUnk_09c, (b + 5), c);
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
        MI_CpuCopy8(v1, a, v2);
        func_ov000_021adf30(v2, c);
        a = a + v2;
        b = b - v2;
    } while (0 < b);
    return 0;
}

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
            func_ov000_021abca0(&c->mUnk_2c0, q, n);
            func_ov000_021ab728(&c->mUnk_378, q, n);
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
                MI_CpuFill8(c->mUnk_2b8, 0, 8);
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
                    func_ov000_021abca0(&c->mUnk_2c0, r - 4, (u32) (v3 + 4));
                    func_ov000_021ab728(&c->mUnk_378, r - 4, (u32) (v3 + 4));
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
            func_ov000_021abd2c((Unk021abca0 *) d);
            g = OS_DisableInterrupts();
            func_ov000_021abca0(d, data_ov000_021b6184, 0x14);
            func_ov000_021abc24((Unk021abca0 *) d, b);
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
            OS_RestoreInterrupts(g);
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
    func_ov000_021abd2c((Unk021abca0 *) b);
    c = OS_DisableInterrupts();
    func_ov000_021abca0(b, data_ov000_021b6184, 0x14);
    func_ov000_021abca0(b, a, n);
    func_ov000_021abc4c((Unk021abca0 *) b, data_ov000_021b6184);
    OS_RestoreInterrupts(c);
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
    MI_CpuCopy8(c->mUnk_028, h + 6, 0x20);
    h[0x26] = 0x20;
    if (c->mUnk_000 != NULL) {
        MI_CpuCopy8(c->mUnk_000, h + 0x27, 0x20);
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
            MI_CpuCopy8(d->mUnk_04, h, e);
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
    func_ov000_021abca0(&c->mUnk_2c0, g + 5, i);
    func_ov000_021ab728(&c->mUnk_378, g + 5, i);
    func_ov000_021adcec(g, i + 5, NULL, 0, a);
    data_ov000_021b63ac(g);
    return c->mUnk_004;
}

void func_ov000_021a998c(Unk021a998c *a) {
    u8 *msg;
    Unk021a998c_0c *obj;
    obj = a->mUnk_0c;
    msg = data_ov000_021b63a4(0x83);
    if (msg == NULL) {
        obj->mUnk_429 = 9;
        return;
    }
    msg[0] = 0x14;
    msg[1] = 3;
    msg[2] = 0;
    msg[3] = 0;
    msg[4] = 1;
    msg[5] = 1;
    MI_CpuFill8(obj->mUnk_1a0, 0, 8);
    msg[6] = 0x16;
    msg[7] = 3;
    msg[8] = 0;
    msg[9] = 0;
    msg[10] = 0x28;
    msg[11] = 0x14;
    msg[12] = 0;
    msg[13] = 0;
    msg[14] = 0x24;
    MI_CpuCopy8(&obj->mUnk_378, &obj->mUnk_3d0, 0x58);
    func_ov000_021aa50c(obj, msg + 0xf, 0);
    MI_CpuCopy8(&obj->mUnk_3d0, &obj->mUnk_378, 0x58);
    MI_CpuCopy8(&obj->mUnk_2c0, &obj->mUnk_31c, 0x5c);
    func_ov000_021aa468(obj, msg + 0x1f, 0);
    MI_CpuCopy8(&obj->mUnk_31c, &obj->mUnk_2c0, 0x5c);
    func_ov000_021abca0(&obj->mUnk_2c0, msg + 0xb, 0x28);
    func_ov000_021ab728(&obj->mUnk_378, msg + 0xb, 0x28);
    func_ov000_021adcec(msg, func_ov000_021aa054(obj, msg + 6) + 6, NULL, 0, a);
    data_ov000_021b63ac(msg);
}

void func_ov000_021a9868(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u8 *b;
    u8 *d;
    u8 *e;
    u32 f;
    s32 g;
    u32 i;
    u16 *h;
    b = data_ov000_021b63a4(0x98);
    if (b == NULL) {
        c->mUnk_429 = 9;
        return;
    }
    d = b + 9;
    b[9] = 3;
    d[1] = 0;
    f = func_ov000_021ab5bc();
    c->mUnk_008[0] = f >> 24;
    c->mUnk_008[1] = f >> 16;
    c->mUnk_008[2] = f >> 8;
    c->mUnk_008[3] = f;
    func_ov000_021a9ca8(&c->mUnk_008[4], 0x1c);
    MI_CpuCopy8(c->mUnk_008, d + 2, 0x20);
    c->mUnk_000 = func_ov000_021ab63c(a->mUnk_1c, a->mUnk_18);
    if (c->mUnk_000 != NULL) {
        d[0x22] = 0x20;
        MI_CpuCopy8(c->mUnk_000, d + 0x23, 0x20);
        d += 0x43;
    } else {
        e = d + 0x22;
        d += 0x23;
        *e = 0;
    }
    i = 0;
    *d = 0;
    e = d + 1;
    d += 2;
    *e = 4;
    h = data_ov000_021b4a00;
    for (; i < 2; i++) {
        *d = *h >> 8;
        e = d + 1;
        d += 2;
        *e = *h;
        h++;
    }
    *d = 1;
    d[1] = 0;
    e = d + 2;
    g = e - b - 5;
    b[0] = 0x16;
    b[1] = 3;
    b[2] = 0;
    b[3] = g >> 8;
    b[4] = g;
    b[5] = 1;
    b[6] = (g - 4) >> 16;
    b[7] = (g - 4) >> 8;
    b[8] = g - 4;
    func_ov000_021adcec(b, g + 5, NULL, 0, a);
    func_ov000_021ab728(&c->mUnk_378, b + 5, g);
    func_ov000_021abca0(&c->mUnk_2c0, b + 5, g);
    data_ov000_021b63ac(b);
}

void func_ov000_021a9640(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    s32 b;
    s32 d;
    u16 *f;
    u16 *g;
    u16 *h;
    u16 *i;
    u8 *e;
    u8 *j;
    s32 m;
    u8 *p;
    u8 *k;
    c->mUnk_000->mUnk_20[0] = 3;
    c->mUnk_000->mUnk_20[1] = 0;
    func_ov000_021a9ca8(&c->mUnk_000->mUnk_20[2], 0x2e);
    b = c->mUnk_568;
    d = (b * 2) / 2;
    e = data_ov000_021b63a4(b);
    if (e == NULL) {
        c->mUnk_429 = 9;
        return;
    }
    e[0] = 0;
    e[1] = 2;
    func_ov000_021a9ca8(e + 2, b - 0x33);
    e[b - 0x31] = 0;
    MI_CpuCopy8(c->mUnk_000->mUnk_20, e + b - 0x30, 0x30);
    f = (u16 *) data_ov000_021b63a4(d * 8);
    if (f == NULL) {
        data_ov000_021b63ac(e);
        c->mUnk_429 = 9;
        return;
    }
    g = f + d;
    h = g + d;
    i = h + d;
    func_ov000_021ac4b8(g, e, b, d);
    func_ov000_021ac4b8(h, c->mUnk_56c, c->mUnk_574, d);
    func_ov000_021ac4b8(i, c->mUnk_468, b, d);
    if (data_ov000_021b49f4 < 0x20) {
        OSThread *n = data_0216ff5c.mCurrentThread;
        u32 o = OS_GetThreadPriority(n);
        OS_SetThreadPriority(n, data_ov000_021b49f4);
        func_ov000_021ac7e8(f, g, h, d, i);
        OS_SetThreadPriority(n, o);
    } else {
        func_ov000_021ac7e8(f, g, h, d, i);
    }
    j = data_ov000_021b63a4(b + 0x49);
    if (j == NULL) {
        data_ov000_021b63ac(e);
        data_ov000_021b63ac(f);
        c->mUnk_429 = 9;
        return;
    }
    j[0] = 0x16;
    j[1] = 3;
    j[2] = 0;
    j[3] = (b + 4) >> 8;
    j[4] = b + 4;
    j[5] = 0x10;
    j[6] = b >> 16;
    j[7] = b >> 8;
    p = j + 9;
    j[8] = b;
    if (b & 1) {
        *p = f[b / 2];
        p += 1;
    }
    for (m = b / 2 - 1; m >= 0; m--) {
        *p = f[m] >> 8;
        k = p + 1;
        p += 2;
        *k = f[m];
    }
    func_ov000_021adcec(j, b + 9, NULL, 0, a);
    func_ov000_021ab728(&c->mUnk_378, j + 5, (u32) b + 4);
    func_ov000_021abca0(&c->mUnk_2c0, j + 5, b + 4);
    data_ov000_021b63ac(j);
    data_ov000_021b63ac(f);
    data_ov000_021b63ac(e);
}

u32 func_ov000_021a9610(Unk021a998c *a) {
    int v1;
    v1 = func_ov000_021a9d68(a);
    if (v1 != 7) {
        return 1;
    }
    v1 = func_ov000_021a9d68(a);
    if (v1 != 6) {
        return 1;
    }
    return 0;
}

BOOL func_ov000_021a95a0(Unk021a998c *a) {
    if (func_ov000_021a9d68(a) != 1) {
        return TRUE;
    }
    if (func_ov000_021a9aa0(a) != 0) {
        func_ov000_021aa5e0(a->mUnk_0c);
        func_ov000_021a998c(a);
        if (func_ov000_021a9610(a) != 0) {
            return TRUE;
        }
    } else {
        if (func_ov000_021a9d68(a) != 5) {
            return TRUE;
        }
        if (func_ov000_021a9610(a) != 0) {
            return TRUE;
        }
        func_ov000_021a998c(a);
    }
    return FALSE;
}

void func_ov000_021a9534(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    while (1) {
        func_ov000_021ae228(a);
        c->mUnk_429 = 0;
        c->mUnk_428 = 1;
        func_ov000_021abd2c(&c->mUnk_2c0);
        func_ov000_021ab7b4(&c->mUnk_378);
        if (func_ov000_021a95a0(a) == 0) {
            c->mUnk_429 = 8;
            return;
        }
        func_ov000_021ae0c4(a);
        a->mUnk_18 = a->mUnk_1a;
        a->mUnk_1c = a->mUnk_20;
    }
}

BOOL func_ov000_021a9494(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u8 b;
    func_ov000_021a9868(a);
    while (1) {
        b = func_ov000_021a9d68(a);
        if (b == 9) {
            return TRUE;
        }
        if (b == 4 || c->mUnk_004 != 0) {
            break;
        }
    }
    if (c->mUnk_004 != 0) {
        func_ov000_021aa5e0(c);
        if (func_ov000_021a9610(a) != 0) {
            return TRUE;
        }
        func_ov000_021a998c(a);
    } else {
        c->mUnk_000->mUnk_54 = a->mUnk_1c;
        c->mUnk_000->mUnk_58 = a->mUnk_18;
        func_ov000_021a9640(a);
        func_ov000_021aa7b4(c);
        func_ov000_021aa5e0(c);
        func_ov000_021a998c(a);
        if (func_ov000_021a9610(a) != 0) {
            return TRUE;
        }
    }
    c->mUnk_429 = 8;
    return FALSE;
}

BOOL func_ov000_021a943c(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    if (a->mState != 4 && func_ov000_021ae16c(a) != 0) {
        return TRUE;
    }
    c->mUnk_429 = 0;
    c->mUnk_428 = 0;
    func_ov000_021abd2c(&c->mUnk_2c0);
    func_ov000_021ab7b4(&c->mUnk_378);
    return func_ov000_021a9494(a);
}

u8 *func_ov000_021a93e0(s32 *a, Unk021a998c *b) {
    Unk021a998c_0c *c = b->mUnk_0c;
    while (c->mUnk_7f8 == NULL) {
        if (func_ov000_021a9d68(b) == 9) {
            *a = 0;
            return NULL;
        }
    }
    *a = c->mUnk_7fc - c->mUnk_800;
    return c->mUnk_7f8 + c->mUnk_800;
}

void func_ov000_021a9394(u32 a, Unk021a998c *b) {
    Unk021a998c_0c *c = b->mUnk_0c;
    if (a >= c->mUnk_7fc - c->mUnk_800) {
        data_ov000_021b63ac(c->mUnk_7f8);
        c->mUnk_7f8 = NULL;
        c->mUnk_800 = c->mUnk_7fc;
    } else {
        c->mUnk_800 += a;
    }
}

s32 func_ov000_021a9358(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    if (c->mUnk_7f8 == NULL) {
        if (a->mReceiveBufferLength == 0) {
            return 0;
        }
        func_ov000_021a9d68(a);
    }
    return c->mUnk_7fc - c->mUnk_800;
}

s32 func_ov000_021a9280(u8 *a, u32 b, u8 *c, u32 d, Unk021a998c *e) {
    Unk021a998c_0c *f = e->mUnk_0c;
    s32 g = b + d;
    u8 *l;
    s32 i;
    u32 j;
    u32 k;
    s32 h = 0;
    u8 m = 0;
    s32 n = 0;
    BOOL p = FALSE;
    while (1) {
        if (g > 0xb4f) {
            i = 0xb4f;
        } else {
            i = g;
        }
        l = data_ov000_021b63a4(i + 0x19);
        if (l == NULL) {
            break;
        }
        if (b >= i) {
            j = i;
        } else {
            j = b;
        }
        k = i - j;
        MI_CpuCopy8(a, l + 5, j);
        a += j;
        b -= j;
        MI_CpuCopy8(c, l + 5 + j, k);
        c += k;
        l[0] = 0x17;
        l[1] = 3;
        l[2] = m;
        l[3] = i >> 8;
        l[4] = i;
        j = func_ov000_021aa054(f, l);
        if (func_ov000_021adcec(l, j, (const u8 *) n, n, e) < j) {
            i = p;
        }
        data_ov000_021b63ac(l);
        g -= i;
        h += i;
        if (g == 0) {
            break;
        }
        if (i == 0) {
            break;
        }
    }
    return h;
}

void func_ov000_021a9228(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u8 b[0x20];
    if (c->mUnk_429 == 8) {
        b[0] = 0x15;
        b[1] = 3;
        b[2] = 0;
        b[3] = 0;
        b[4] = 2;
        b[5] = 1;
        b[6] = 0;
        func_ov000_021adcec(b, func_ov000_021aa054(c, b), NULL, 0, a);
    }
    func_ov000_021ae0c4(a);
    c->mUnk_429 = 0;
}
