#include "00/code_0218b708.h"
#include "00/types_0218b928.h"
#include "00/code_0218aea4.h"
#include "00/code_0218a000.h"
#include "00/unk_021b2000.h"
#include "code_02134d30.h"
#include "00/code_0218a67c.h"
#include "00/code_0218a918.h"
#include "00/code_0218acb0.h"
#include "00/code_0218b000.h"
#include "00/code_0218c45c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218b220.h"
#include "00/code_0218cdc4.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218e49c.h"
#include "00/code_0218e368.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021a3678.h"
#include "00/code_021965a0.h"
#include "00/code_02190ba0.h"
#include "code_02135014.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_02193818.h"
#include "00/code_021a39d8.h"
#include "00/code_021a4784.h"
#include "00/unk_021b4000.h"
#include "00/code_0218ab18.h"
#include "00/code_0218e8c4.h"

s32 func_ov000_0218c15c(Unk021b4d24 *a) {
    u8 *p;
    s32 n;
    s32 u;
    s32 v;
    s32 w;
    s32 k;
    Unk0218c0bc e;
    u8 *q;
    u8 *r;
    p = a->mUnk_07c;
    n = a->mUnk_080;
    switch (a->mUnk_5c8) {
        case 0:
            if (n < 1) {
                break;
            }
            u = (p[0] ^ 0xec) + 2;
            if (n < u) {
                break;
            }
            v = p[u - 1] ^ 0xea;
            w = u + v;
            if (n < w) {
                break;
            }
            func_ov000_0218c8e0(a, (s8 *) (p + u), v);
            a->mUnk_5c8 = 1;
            p += w;
            n -= w;
            func_ov000_0218a6f4((u32) a->mUnk_4bc, (int) p, n);
        case 1:
            if (n < 6) {
                break;
            }
            q = (u8 *) &a->mUnk_4a0;
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[3] = p[3];
            a->mUnk_488(a, 6, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
            q = (u8 *) &a->mUnk_4a8;
            r = p + 4;
            q[0] = r[0];
            q[1] = r[1];
            if (a->mUnk_4a8 == 0xffff) {
                if (func_ov000_0218d0c8((int) (p + 6), n - 6) == -1) {
                    break;
                }
                func_ov000_0218c45c(a, (u8 *) (p + 6));
                a->mUnk_488(a, 5, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
                if (a->mUnk_07c == 0) {
                    break;
                }
            }
            p += 6;
            n -= 6;
            if ((a->mUnk_5c4 & 2) != 0 || a->mUnk_4a8 == 0xffff) {
                a->mUnk_5c8 = 5;
                a->mUnk_000 = 2;
                break;
            }
            a->mUnk_5c8 = 2;
            a->mUnk_484 = -1;
        case 2:
            if (a->mUnk_484 == -1) {
                if (n < 1) {
                    break;
                }
                a->mUnk_484 = p[0];
                a->mUnk_008 = func_ov000_0218dc94(8, a->mUnk_484, 0);
                if (a->mUnk_008 == 0) {
                    return 5;
                }
                p += 1;
                n -= 1;
            }
            while (a->mUnk_484 > func_ov000_0218dc44(a->mUnk_008)) {
                if (n < 2) {
                    break;
                }
                k = func_ov000_0218d0c8((int) (p + 1), n - 1);
                if (k == -1) {
                    break;
                }
                e.mUnk_04 = p[0];
                e.mUnk_00 = func_ov000_0218d134(a, p + 1);
                func_ov000_0218dbc0(a->mUnk_008, &e);
                k += 1;
                p += k;
                n -= k;
            }
            if (a->mUnk_484 > func_ov000_0218dc44(a->mUnk_008)) {
                break;
            }
            a->mUnk_5c8 = 3;
            a->mUnk_484 = -1;
        case 3:
            if (a->mUnk_484 == -1) {
                if (n < 1) {
                    break;
                }
                a->mUnk_484 = p[0];
                a->mUnk_480 = 0;
                p += 1;
                n -= 1;
            }
            while (a->mUnk_484 > a->mUnk_480) {
                k = func_ov000_0218d0c8((int) p, n);
                if (k == -1) {
                    break;
                }
                a->mUnk_084[a->mUnk_480++] = func_ov000_0218d134(a, p);
                p += k;
                n -= k;
            }
            if (a->mUnk_484 > a->mUnk_480) {
                break;
            }
            a->mUnk_5c8 = 4;
        case 4:
            if (n < 5) {
                break;
            }
            do {
                k = func_ov000_0218c468(a, p, n);
                if (k == -2) {
                    return 5;
                }
                if (k == -1) {
                    n -= 5;
                    p += 5;
                    a->mUnk_5c8 = 5;
                    a->mUnk_000 = 2;
                    a->mUnk_488(a, 3, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
                    break;
                }
                p += k;
                n -= k;
                if (a->mUnk_07c == 0) {
                    k = 0;
                }
            } while (k != 0);
            break;
    }
    if (n < 0) {
        func_0213442c(data_ov000_021b2228, data_ov000_021b2218, 0, 0x4af);
    }
    if (a->mUnk_07c == 0) {
        return 0;
    }
    if (n != 0) {
        memmove(a->mUnk_07c, p, n);
    }
    a->mUnk_080 = n;
    return 0;
}

s32 func_ov000_0218c0bc(Unk021b4d24 *a, u8 *b, s32 c) {
    s32 d;
    s32 i;
    s32 k;
    Unk0218c0bc e;
    d = b[0];
    b += 1;
    c -= 1;
    if (a->mUnk_008 != 0) {
        func_ov000_0218c9d4(a);
    }
    a->mUnk_008 = func_ov000_0218dc94(8, d, 0);
    if (a->mUnk_008 == 0) {
        return 5;
    }
    i = 0;
    if (d > 0) {
        do {
            if (c < 2) {
                return 4;
            }
            k = func_ov000_0218d0c8((int) (b + 1), c - 1);
            if (k == -1) {
                return 4;
            }
            e.mUnk_04 = b[0];
            e.mUnk_00 = func_ov000_0218d134(a, b + 1);
            func_ov000_0218dbc0(a->mUnk_008, &e);
            k += 1;
            b += k;
            c -= k;
            i++;
        } while (i < d);
    }
    return 0;
}

s32 func_ov000_0218bf78(Unk021b4d24 *a, u8 *b, s32 c) {
    s32 d;
    s32 i;
    s32 e;
    s32 k;
    s32 m;
    u8 *l;
    u32 f;
    u16 g;
    u32 h;
    u8 *p;
    u8 *q;
    if (c < 2) {
        return 4;
    }
    d = b[0];
    e = b[1];
    b += 2;
    c -= 2;
    i = 0;
    if (e > 0) {
        do {
            l = b;
            k = func_ov000_0218d0c8((int) b, c);
            if (k == -1) {
                return 4;
            }
            b += k;
            c -= k;
            if (c < 11) {
                return 4;
            }
            p = b;
            q = (u8 *) &f;
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[3] = p[3];
            p = b + 4;
            q = (u8 *) &g;
            q[0] = p[0];
            q[1] = p[1];
            p = b + 6;
            q = (u8 *) &h;
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[3] = p[3];
            h = (h << 24 & 0xff000000) | ((h << 8 & 0xff0000) | ((h >> 24 & 0xff) | (h >> 8 & 0xff00)));
            b += 10;
            c -= 10;
            m = func_ov000_0218d0c8((int) b, c);
            if (m == -1) {
                return 4;
            }
            a->mUnk_490(a, l, f, g, h, b, a->mUnk_494);
            b += m;
            c -= m;
            i++;
        } while (i < e);
    }
    if (d != 0) {
        a->mUnk_490(a, 0, 0, 0, 0, 0, a->mUnk_494);
    }
    return 0;
}

s32 func_ov000_0218be68(Unk021b4d24 *a, u8 *b, s32 c) {
    u32 g;
    u32 d;
    u16 e;
    u32 f;
    s32 h;
    s32 i;
    s32 j;
    u8 *k[16];
    u8 *p;
    u8 *q;
    u8 *l;
    if (c < 11) {
        return 4;
    }
    p = b;
    q = (u8 *) &d;
    q[0] = p[0];
    q[1] = p[1];
    q[2] = p[2];
    q[3] = p[3];
    q = (u8 *) &e;
    p = b + 4;
    q[0] = p[0];
    q[1] = p[1];
    i = func_ov000_0218d2a8((int) a, d, e);
    if (i == -1) {
        return 0;
    }
    f = func_ov000_0218d218((u32) a, i);
    q = (u8 *) &g;
    p = b + 6;
    q[0] = p[0];
    q[1] = p[1];
    q[2] = p[2];
    q[3] = p[3];
    g = (g << 24 & 0xff000000) | ((g << 8 & 0xff0000) | ((g >> 24 & 0xff) | (g >> 8 & 0xff00)));
    h = b[10];
    b += 11;
    c -= 11;
    for (j = 0; j < h && j < 16;) {
        if (c < 1) {
            break;
        }
        i = func_ov000_0218d0c8((int) b, c);
        if (i == -1) {
            return 4;
        }
        k[j] = b;
        b += i;
        c -= i;
        j++;
    }
    if (a->mUnk_48c == 0) {
        return 0;
    }
    a->mUnk_48c(a, f, g, j, k, a->mUnk_494);
    return 0;
}

s32 func_ov000_0218be10(Unk021b4d24 *a, u8 *b, s32 c) {
    u32 d;
    u16 e;
    s32 f;
    u8 *p;
    u8 *q;
    if (c < 6) {
        return 4;
    }
    p = b;
    q = (u8 *) &d;
    q[0] = p[0];
    q[1] = p[1];
    q[2] = p[2];
    q[3] = p[3];
    q = (u8 *) &e;
    p = b + 4;
    q[0] = p[0];
    q[1] = p[1];
    f = func_ov000_0218d2a8((int) a, d, e);
    if (f != -1) {
        func_ov000_0218d238(a, f);
        return 0;
    }
    return 0;
}

s32 func_ov000_0218bd5c(Unk021b4d24 *a, u8 *b, s32 c) {
    s32 d;
    void *e;
    u16 f;
    u32 g;
    if (c < 5) {
        return 4;
    }
    func_ov000_0218c744(a, b, c, (u8 *) &g, &f);
    d = func_ov000_0218d2a8((int) a, g, f);
    if (d == -1) {
        e = func_ov000_0218af28(a, g, f);
        if (func_ov000_0218aefc((int) e) != 0) {
            return 5;
        }
    } else {
        e = (void *) func_ov000_0218d218((u32) a, d);
    }
    if (func_ov000_0218c550(a, e, b, c, 0) < 0) {
        return 4;
    }
    if (d == -1) {
        func_ov000_0218d340(a, (u32) e);
    }
    a->mUnk_488(a, 1, e, a->mUnk_494);
    return 0;
}

s32 func_ov000_0218bc08(Unk021b4d24 *a) {
    s32 b;
    u16 c;
    u8 *q;
    u8 *p;
    b = 0;
    while (a->mUnk_080 >= 3) {
        q = (u8 *) &c;
        p = a->mUnk_07c;
        q[0] = p[0];
        q[1] = p[1];
        c = (c >> 8 & 0xff) | (c << 8 & 0xff00);
        if (c > 0x1000) {
            b = 4;
            break;
        }
        if (a->mUnk_080 < c) {
            return 0;
        }
        switch ((s8) a->mUnk_07c[2]) {
            case 1:
                b = func_ov000_0218c0bc(a, a->mUnk_07c + 3, c - 3);
                break;
            case 2:
                b = func_ov000_0218bd5c(a, a->mUnk_07c + 3, c - 3);
                break;
            case 3:
                if (func_ov000_0218e420(a->mUnk_4b0, a->mUnk_07c, c, 0) <= 0) {
                    return 3;
                }
                break;
            case 4:
                b = func_ov000_0218be10(a, a->mUnk_07c + 3, c - 3);
                break;
            case 5:
                b = func_ov000_0218be68(a, a->mUnk_07c + 3, c - 3);
                break;
            case 6:
                b = func_ov000_0218bf78(a, a->mUnk_07c + 3, c - 3);
                break;
        }
        a->mUnk_080 -= c;
        if (a->mUnk_080 < 0) {
            func_0213442c(data_ov000_021b2200, data_ov000_021b2218, 0, 0x5b4);
        }
        if (a->mUnk_080 != 0 && a->mUnk_07c != 0) {
            memmove(a->mUnk_07c, a->mUnk_07c + c, a->mUnk_080);
        }
        if (b != 0) {
            break;
        }
    }
    if (b != 0) {
        func_ov000_0218cf30(a);
    }
    return b;
}

s32 func_ov000_0218bb44(Unk021b4d24 *a) {
    s32 b;
    s32 c;
    s32 d;
    if (func_ov000_0218e668(a->mUnk_4b0) == 0) {
        return 0;
    }
    b = a->mUnk_080;
    c = func_ov000_0218e460(a->mUnk_4b0, a->mUnk_07c + b, 0x1000 - b, 0);
    if ((u32) (c + 1) <= 1) {
        func_ov000_0218cf30(a);
        return 3;
    }
    a->mUnk_080 += c;
    d = 0;
    if (a->mUnk_000 == 2 || a->mUnk_5c8 > 0) {
        func_ov000_0218a6f4((u32) a->mUnk_4bc, (int) (a->mUnk_07c + b), a->mUnk_080 - b);
    }
    if (a->mUnk_000 == 3) {
        d = func_ov000_0218c15c(a);
    }
    if (d != 0) {
        return d;
    }
    if (a->mUnk_000 == 2 && a->mUnk_080 > 0) {
        return func_ov000_0218bc08(a);
    }
    return 0;
}

s32 func_ov000_0218ba88(Unk021b4d24 *a, u32 b, u16 c, u8 *d, s32 e) {
    Unk0218ba88 g;
    u16 h;
    u8 *p;
    u8 *q;
    s32 r;
    if (a->mUnk_000 == 1) {
        func_ov000_0218ca58(a, 0, 0, 2, 0);
    }
    if (a->mUnk_000 == 1) {
        return 3;
    }
    h = e + 9;
    g.mUnk_00 = (h >> 8 & 0xff) | (h << 8 & 0xff00);
    p = g.mUnk_02;
    q = (u8 *) &g.mUnk_00;
    p[0] = q[0];
    p[1] = q[1];
    g.mUnk_04 = 2;
    p = g.mUnk_05;
    q = (u8 *) &b;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
    p = g.mUnk_09;
    q = (u8 *) &c;
    p[0] = q[0];
    p[1] = q[1];
    r = func_ov000_0218cc48(a, g.mUnk_02, 9);
    if (r != 0) {
        return r;
    }
    if (func_ov000_0218e420(a->mUnk_4b0, d, e, 0) < 0) {
        return 3;
    }
    return 0;
}

s32 func_ov000_0218ba10(Unk021b4d24 *a, u32 b, u16 c, u32 d) {
    u8 v[10];
    u8 *p;
    u8 *q;
    v[0] = 0xfd;
    v[1] = 0xfc;
    v[2] = 0x1e;
    v[3] = 0x66;
    v[4] = 0x6a;
    v[5] = 0xb2;
    d = (d << 24 & 0xff000000) | ((d << 8 & 0xff0000) | ((d >> 24 & 0xff) | (d >> 8 & 0xff00)));
    p = v + 6;
    q = (u8 *) &d;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
    return func_ov000_0218ba88(a, b, c, v, 10);
}

s32 func_ov000_0218b928(Unk021b4d24 *a) {
    Unk0218b8f4 v1;
    s32 v2;
    u8 v3[0x5e0];
    void *p;
    v2 = 8;
    while (func_ov000_0218e668(a->mUnk_4b0) != 0) {
        if (func_ov000_0218e438(a->mUnk_4b0, v3, 0x5db, 0, (u8 *) &v1, &v2) != -1) {
            if (func_ov000_0218d2a8((int) a, v1.mUnk_04, v1.mUnk_02) == -1) {
                p = func_ov000_0218af28(a, v1.mUnk_04, v1.mUnk_02);
                if (func_ov000_0218aefc((int) p) != 0) {
                    return 5;
                }
                func_ov000_0218af24((int) p, 0x11);
                func_ov000_0218d340(a, (u32) p);
            }
        }
    }
    if (func_ov000_0218e8c4() - a->mUnk_4b4 > 0x7d0) {
        func_ov000_0218e53c(a->mUnk_4b0);
        a->mUnk_4b0 = -1;
        a->mUnk_000 = 1;
        a->mUnk_488(a, 3, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
    }
    return 0;
}

s32 func_ov000_0218b8e4(Unk021b4d24 *a) {
    func_ov000_0218d1dc(a);
    switch (a->mUnk_000) {
        case 2:
        case 3:
            return func_ov000_0218bb44(a);
        case 0:
            return func_ov000_0218b928(a);
        case 1:
        default:
            return 0;
    }
}

void func_ov000_0218b780(Unk021b4d24 *a, s32 b, Unk0218af28 *c, Unk0218b668 *d) {
    switch (b) {
        case 0:
            d->mUnk_630(d, 0, c, d->mUnk_634);
            if (((c->mUnk_14 & 3) == 0 || (c->mUnk_14 & 0x40) == 0) && (c->mUnk_14 & 0x2c) == 0 && d->mUnk_624 == 0) {
                s32 t;
                if (c->mUnk_15 & 1) {
                    if (d->mUnk_04c.mUnk_000 == 0 || d->mUnk_040 == 0) {
                        t = 1;
                    } else {
                        t = 0;
                    }
                } else {
                    t = 2;
                }
                func_ov000_0218ac54((Unk0218a9bc *) d, c, 0, t);
            }
            break;
        case 1:
            if ((c->mUnk_14 & 0x43) == 0) {
                d->mUnk_630(d, 2, c, d->mUnk_634);
            } else {
                d->mUnk_630(d, 1, c, d->mUnk_634);
            }
            break;
        case 2:
            if ((c->mUnk_14 & 0x2c) != 0) {
                func_ov000_0218a918((int) d, (u32) c);
            }
            d->mUnk_630(d, 3, c, d->mUnk_634);
            break;
        case 3:
            if (d->mUnk_620 != 0) {
                func_ov000_0218c980(a);
            }
            if (func_ov000_0218dc44(a->mUnk_004) == 0 || d->mUnk_010 == 0) {
                d->mUnk_630(d, 4, 0, d->mUnk_634);
            }
            break;
        case 5:
            d->mUnk_630(d, 5, 0, d->mUnk_634);
            break;
        case 6:
            func_ov000_0218acf0((int) d, d->mUnk_04c.mUnk_4a0);
            break;
    }
    if (c != 0 && c->mUnk_00 == d->mUnk_628 && c->mUnk_04 == d->mUnk_62c) {
        d->mUnk_628 = 0;
    }
}

void func_ov000_0218b708(void *a, s32 b, Unk0218af28 *c, Unk0218b668 *d) {
    switch (b) {
        case 1:
            d->mUnk_630(d, 2, c, d->mUnk_634);
            break;
        case 0:
            d->mUnk_630(d, 1, c, d->mUnk_634);
            break;
        case 2:
            d->mUnk_630(d, 4, c, d->mUnk_634);
            break;
    }
    if (c != 0 && c->mUnk_00 == d->mUnk_628 && c->mUnk_04 == d->mUnk_62c) {
        d->mUnk_628 = 0;
    }
}
