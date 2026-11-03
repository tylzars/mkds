#include "00/code_021aae44.h"
#include "00/code_021ab000.h"
#include "00/code_021ab548.h"
#include "00/code_021ab6d4.h"
#include "00/code_021ab728.h"
#include "00/code_021ab7b4.h"
#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021abd2c.h"
#include "00/code_021ac3e4.h"
#include "00/types_021a998c.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b6000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200dc3c.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "code_0214d018.h"

u32 func_ov000_021aae44(Unk021a998c_0c *a) {
    u32 f;
    u32 *h;
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
            h = (u32 *) a->mUnk_3d0;
            func_ov000_021ab7b4(h);
            func_ov000_021ab728(h, a->mUnk_434, a->mUnk_438 - a->mUnk_434);
            func_ov000_021ab6d4((s32) h, (u32) a->mUnk_43c);
            a->mUnk_450 = 0x10;
            break;
        case 4:
            h = (u32 *) a->mUnk_31c;
            func_ov000_021abd2c(h);
            func_ov000_021abca0(h, a->mUnk_434, a->mUnk_438 - a->mUnk_434);
            func_ov000_021abc4c((s32) h, (u32) a->mUnk_43c);
            a->mUnk_450 = 0x14;
            break;
        default:
            f |= 3;
            return f;
    }
    r = func_ov000_021ab548((s32) a, (u32) a->mUnk_584);
    if (r == 0) {
        f |= 1;
        return f;
    }
    f |= func_ov000_021aaf38(a, (Unk021aaf38 *) r);
    return f;
}

u32 func_ov000_021aaf38(Unk021a998c_0c *a, Unk021aaf38 *b) {
    s32 n;
    u16 *c;
    u16 *d;
    u16 *e;
    u16 *f;
    u32 g;
    Unk0200db5c *t;
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
        t = data_0216ff5c.mUnk_04;
        g = func_0200dcd8(t);
        func_0200dce0(t, data_ov000_021b49f4);
        func_ov000_021ac7e8(c, d, e, n, f);
        func_0200dce0(t, g);
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

BOOL func_ov000_021ab09c(Unk021a998c_0c *a, u8 **b, s32 c, s32 d, s32 e) {
    u8 *p;
    u32 t;
    u32 k;
    s32 n;
    u8 *v1;
    s32 i;
    u8 *q;
    const u8 *s;
    const u8 **v2;
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
                                func_0214d1fc(p, a->mUnk_468, n);
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
                                func_0214d1fc(p, a->mUnk_56c, n);
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
                        func_0214d1fc(p, a->mUnk_784, n);
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
