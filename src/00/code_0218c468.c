#include "00/code_0218c468.h"
#include "00/code_0218af28.h"
#include "00/code_0218aea4.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_0218dc44.h"
#include "00/code_0218d0c8.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "00/code_0218a71c.h"

void func_ov000_0218c8e0(Unk021b4d24 *a, s8 *b, s32 c) {
    s32 d;
    s8 *p;
    s32 i;
    s8 *q;
    d = func_0213a434(a->mUnk_054);
    p = (s8 *) a->mUnk_054;
    for (i = 0; i < c; i++) {
        s32 x = p[i % d];
        s32 y = i * x % 8;
        s32 z = i % 8;
        a->mUnk_074[y] = a->mUnk_074[y] ^ (s8) (a->mUnk_074[z] ^ b[i]);
    }
    func_ov000_0218a7bc((Unk0218a71c *) a->mUnk_4bc, (const u8 *) a->mUnk_074, 8);
}

s32 func_ov000_0218c8ac(u32 a) {
    s32 b;
    b = 5;
    if ((a & 2) != 0) {
        b += 4;
    }
    if ((a & 8) != 0) {
        b += 4;
    }
    if ((a & 0x10) != 0) {
        b += 2;
    }
    if ((a & 0x20) != 0) {
        b += 2;
    }
    return b;
}

s32 func_ov000_0218c84c(u8 *a, s32 b) {
    s32 k;
    while (b > 0 && *(s8 *) a != 0) {
        k = func_ov000_0218d0c8((int) a, b);
        if (k < 0) {
            return 0;
        }
        a += k;
        b -= k;
        k = func_ov000_0218d0c8((int) a, b);
        if (k < 0) {
            return 0;
        }
        a += k;
        b -= k;
    }
    if (b == 0) {
        return 0;
    }
    return *(s8 *) a == 0;
}

s32 func_ov000_0218c794(Unk021b4d24 *a, u8 *b, s32 c) {
    s32 d;
    s32 i;
    s32 k;
    s32 t;
    d = func_ov000_0218dc44(a->mUnk_008);
    i = 0;
    if (d > 0) {
        do {
            switch (((Unk0218c0bc *) func_ov000_0218dbf8(a->mUnk_008, i))->mUnk_04) {
                case 1:
                    b += 1;
                    c -= 1;
                    break;
                case 2:
                    b += 2;
                    c -= 2;
                    break;
                case 0:
                    if (c < 1) {
                        return 0;
                    }
                    t = b[0];
                    b += 1;
                    c -= 1;
                    if (t == 0xff) {
                        k = func_ov000_0218d0c8((int) b, c);
                        if (k == -1) {
                            return 0;
                        }
                        b += k;
                        c -= k;
                    }
                    break;
                default:
                    func_0213442c(data_ov000_021b223c, data_ov000_021b2218, 0, 0x317);
                    return 0;
            }
            if (c < 0) {
                return 0;
            }
            i++;
        } while (i < d);
    }
    return 1;
}

void func_ov000_0218c744(Unk021b4d24 *a, u8 *b, s32 c, u8 *d, u16 *e) {
    u8 f;
    u8 *p;
    u8 *q;
    if (c >= 5) {
        f = b[0];
        p = b + 1;
        d[0] = p[0];
        d[1] = p[1];
        d[2] = p[2];
        d[3] = p[3];
        if ((f & 0x10) != 0) {
            if (c - 5 < 2) {
                return;
            }
            q = (u8 *) e;
            p = b + 5;
            q[0] = p[0];
            q[1] = p[1];
        } else {
            *e = a->mUnk_4a8;
        }
    }
}

s32 func_ov000_0218c550(Unk021b4d24 *a, void *b, u8 *c, s32 d, s32 e) {
    s32 h;
    s32 f;
    s32 g;
    s32 i;
    u16 k;
    u16 l;
    u32 j;
    s32 n;
    u8 *o;
    u8 *p;
    u8 *q;
    Unk0218c0bc *r;
    f = d;
    g = c[0];
    func_ov000_0218af24((int) b, g);
    c += 5;
    d -= 5;
    if ((g & 0x10) != 0) {
        c += 2;
        d -= 2;
    }
    if ((g & 2) != 0) {
        q = (u8 *) &j;
        q[0] = c[0];
        q[1] = c[1];
        q[2] = c[2];
        q[3] = c[3];
        c += 4;
        d -= 4;
    } else {
        j = 0;
    }
    if ((g & 0x20) != 0) {
        q = (u8 *) &l;
        q[0] = c[0];
        q[1] = c[1];
        c += 2;
        d -= 2;
    } else {
        l = a->mUnk_4a8;
    }
    func_ov000_0218af1c((int) b, j, l);
    if ((g & 8) != 0) {
        q = (u8 *) &j;
        q[0] = c[0];
        q[1] = c[1];
        q[2] = c[2];
        q[3] = c[3];
        c += 4;
        d -= 4;
        func_ov000_0218af18((int) b, j);
    }
    if ((g & 0x40) != 0) {
        h = func_ov000_0218dc44(a->mUnk_008);
        i = 0;
        if (h > 0) {
            do {
                r = func_ov000_0218dbf8(a->mUnk_008, i);
                switch (r->mUnk_04) {
                    case 1:
                        func_ov000_0218b358(b, r->mUnk_00, c[0]);
                        c += 1;
                        d -= 1;
                        break;
                    case 2:
                        q = (u8 *) &k;
                        q[0] = c[0];
                        q[1] = c[1];
                        func_ov000_0218b358(b, r->mUnk_00, (u16) ((k >> 8 & 0xff) | (k << 8 & 0xff00)));
                        c += 2;
                        d -= 2;
                        break;
                    case 0:
                        if (e != 0) {
                            n = c[0];
                            c += 1;
                            d -= 1;
                        } else {
                            n = 0xff;
                        }
                        if (n == 0xff) {
                            func_ov000_0218b380(b, r->mUnk_00, c);
                            n = func_0213a434(c) + 1;
                            c += n;
                            d -= n;
                        } else {
                            func_ov000_0218b380(b, r->mUnk_00, a->mUnk_084[n]);
                        }
                        break;
                }
                i++;
            } while (i < h);
        }
        func_ov000_0218af14((int) b, func_ov000_0218af10((int) b) | 1);
    }
    g = g & 0x80;
    if (g != 0) {
        while ((s8) c[0] != 0 && d > 0) {
            o = c;
            n = func_0213a434(c) + 1;
            c += n;
            d -= n;
            func_ov000_0218b380(b, o, c);
            n = func_0213a434(c) + 1;
            c += n;
            d -= n;
        }
        d -= 1;
        func_ov000_0218af14((int) b, func_ov000_0218af10((int) b) | 2);
    }
    return f - d;
}

s32 func_ov000_0218c468(Unk021b4d24 *a, u8 *b, s32 c) {
    s32 e;
    s32 d;
    void *h;
    u16 f;
    u32 g;
    s32 r;
    if (c < 1) {
        return 0;
    }
    d = b[0];
    e = func_ov000_0218c8ac(d);
    if (c < e) {
        return 0;
    }
    if ((d & 0x40) != 0) {
        if (func_ov000_0218c794(a, b + e, c - e) == 0) {
            return 0;
        }
    }
    d = d & 0x80;
    if (d != 0) {
        if (func_ov000_0218c84c(b + e, c - e) == 0) {
            return 0;
        }
    }
    if (func_02134d30(b + 1, data_ov000_021b2234, 4) == 0) {
        return -1;
    }
    func_ov000_0218c744(a, b, c, (u8 *) &g, &f);
    h = func_ov000_0218af28(a, g, f);
    if (func_ov000_0218aefc((int) h) != 0) {
        return -2;
    }
    r = func_ov000_0218c550(a, h, b, c, 1);
    func_ov000_0218d340(a, (u32) h);
    return r;
}
