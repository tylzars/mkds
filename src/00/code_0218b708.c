#include "00/code_0218b708.h"

#include "00/code_0218a9bc.h"
#include "00/code_0218b434.h"
#include "00/code_0218c958.h"
#include "00/types_0218b928.h"
#include "00/code_0218aea4.h"
#include "00/code_0218a000.h"
#include "00/unk_021b2000.h"
#include "code_02134d30.h"
#include "00/code_0218a67c.h"
#include "00/code_0218a918.h"
#include "00/code_0218acb0.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "code_0213442c.h"
#include "00/code_0218d818.h"
#include "00/code_0218b220.h"
#include "00/code_0218cd74.h"
#include "00/code_0218e2dc.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021a3678.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "code_02135014.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02192d64.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_021a3a18.h"
#include "00/unk_021b4000.h"
#include "00/code_0218ab18.h"
#include "00/code_0218b280.h"
#include "00/code_0218a71c.h"

void func_ov000_0218c8e0(SbServerList *a, s8 *b, s32 c) {
    s32 d;
    s8 *p;
    s32 i;
    s8 *q;
    d = strlen(a->mUnk_054);
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

BOOL func_ov000_0218c84c(u8 *a, s32 b) {
    s32 k;
    while (b > 0 && *(s8 *) a != 0) {
        k = func_ov000_0218d0c8(a, b);
        if (k < 0) {
            return FALSE;
        }
        a += k;
        b -= k;
        k = func_ov000_0218d0c8(a, b);
        if (k < 0) {
            return FALSE;
        }
        a += k;
        b -= k;
    }
    if (b == 0) {
        return FALSE;
    }
    return *(s8 *) a == 0;
}

BOOL func_ov000_0218c794(SbServerList *a, u8 *b, s32 c) {
    s32 d;
    s32 i;
    s32 k;
    s32 t;
    d = DarrayGetCount(a->mUnk_008);
    i = 0;
    if (d > 0) {
        do {
            switch (((Unk0218c0bc *) DarrayGetElement(a->mUnk_008, i))->mUnk_04) {
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
                        return FALSE;
                    }
                    t = b[0];
                    b += 1;
                    c -= 1;
                    if (t == 0xff) {
                        k = func_ov000_0218d0c8(b, c);
                        if (k == -1) {
                            return FALSE;
                        }
                        b += k;
                        c -= k;
                    }
                    break;
                default:
                    func_0213442c(data_ov000_021b223c, data_ov000_021b2218, NULL, 0x317);
                    return FALSE;
            }
            if (c < 0) {
                return FALSE;
            }
            i++;
        } while (i < d);
    }
    return TRUE;
}

void func_ov000_0218c744(SbServerList *a, u8 *b, s32 c, u8 *d, u16 *e) {
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

s32 func_ov000_0218c550(SbServerList *a, void *b, u8 *c, s32 d, s32 e) {
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
    func_ov000_0218af24(b, g);
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
    func_ov000_0218af1c(b, j, l);
    if ((g & 8) != 0) {
        q = (u8 *) &j;
        q[0] = c[0];
        q[1] = c[1];
        q[2] = c[2];
        q[3] = c[3];
        c += 4;
        d -= 4;
        func_ov000_0218af18(b, j);
    }
    if ((g & 0x40) != 0) {
        h = DarrayGetCount(a->mUnk_008);
        i = 0;
        if (h > 0) {
            do {
                r = DarrayGetElement(a->mUnk_008, i);
                switch (r->mUnk_04) {
                    case 1:
                        SbServerSetInt(b, r->mUnk_00, c[0]);
                        c += 1;
                        d -= 1;
                        break;
                    case 2:
                        q = (u8 *) &k;
                        q[0] = c[0];
                        q[1] = c[1];
                        SbServerSetInt(b, r->mUnk_00, (u16) ((k >> 8 & 0xff) | (k << 8 & 0xff00)));
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
                            SbServerSetValue(b, r->mUnk_00, (const char *) c);
                            n = strlen((const char *) c) + 1;
                            c += n;
                            d -= n;
                        } else {
                            SbServerSetValue(b, r->mUnk_00, a->mUnk_084[n]);
                        }
                        break;
                }
                i++;
            } while (i < h);
        }
        func_ov000_0218af14(b, func_ov000_0218af10(b) | 1);
    }
    g = g & 0x80;
    if (g != 0) {
        while ((s8) c[0] != 0 && d > 0) {
            o = c;
            n = strlen((const char *) c) + 1;
            c += n;
            d -= n;
            SbServerSetValue(b, (const char *) o, (const char *) c);
            n = strlen((const char *) c) + 1;
            c += n;
            d -= n;
        }
        d -= 1;
        func_ov000_0218af14(b, func_ov000_0218af10(b) | 2);
    }
    return f - d;
}

s32 func_ov000_0218c468(SbServerList *a, u8 *b, s32 c) {
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
        if (func_ov000_0218c794(a, b + e, c - e) == FALSE) {
            return 0;
        }
    }
    d = d & 0x80;
    if (d != 0) {
        if (func_ov000_0218c84c(b + e, c - e) == FALSE) {
            return 0;
        }
    }
    if (memcmp(b + 1, data_ov000_021b2234, 4) == 0) {
        return -1;
    }
    func_ov000_0218c744(a, b, c, (u8 *) &g, &f);
    h = func_ov000_0218af28(a, g, f);
    if (func_ov000_0218aefc(h) != 0) {
        return -2;
    }
    r = func_ov000_0218c550(a, h, b, c, 1);
    func_ov000_0218d340(a, (u32) h);
    return r;
}

void func_ov000_0218c45c(SbServerList *a, char *b) {
    a->mUnk_4ac = b;
    return;
}

s32 func_ov000_0218c15c(SbServerList *a) {
    u8 *p;
    s32 n;
    s32 u;
    s32 v;
    s32 w;
    s32 k;
    Unk0218c0bc e;
    u8 *q;
    u8 *r;
    p = a->mInBuffer;
    n = a->mInBufferLength;
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
            func_ov000_0218a6f4(a->mUnk_4bc, p, n);
        case 1:
            if (n < 6) {
                break;
            }
            q = (u8 *) &a->mUnk_4a0;
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[3] = p[3];
            a->mCallback(a, 6, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
            q = (u8 *) &a->mUnk_4a8;
            r = p + 4;
            q[0] = r[0];
            q[1] = r[1];
            if (a->mUnk_4a8 == 0xffff) {
                if (func_ov000_0218d0c8(p + 6, n - 6) == -1) {
                    break;
                }
                func_ov000_0218c45c(a, (char *) (p + 6));
                a->mCallback(a, 5, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
                if (a->mInBuffer == NULL) {
                    break;
                }
            }
            p += 6;
            n -= 6;
            if ((a->mUnk_5c4 & 2) != 0 || a->mUnk_4a8 == 0xffff) {
                a->mUnk_5c8 = 5;
                a->mState = 2;
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
                a->mUnk_008 = DarrayCreate(8, a->mUnk_484, NULL);
                if (a->mUnk_008 == NULL) {
                    return 5;
                }
                p += 1;
                n -= 1;
            }
            while (a->mUnk_484 > DarrayGetCount(a->mUnk_008)) {
                if (n < 2) {
                    break;
                }
                k = func_ov000_0218d0c8(p + 1, n - 1);
                if (k == -1) {
                    break;
                }
                e.mUnk_04 = p[0];
                e.mUnk_00 = func_ov000_0218d134(a, (const char *) (p + 1));
                DarrayAppend(a->mUnk_008, &e);
                k += 1;
                p += k;
                n -= k;
            }
            if (a->mUnk_484 > DarrayGetCount(a->mUnk_008)) {
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
                k = func_ov000_0218d0c8(p, n);
                if (k == -1) {
                    break;
                }
                a->mUnk_084[a->mUnk_480++] = func_ov000_0218d134(a, (const char *) p);
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
                    a->mState = 2;
                    a->mCallback(a, 3, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
                    break;
                }
                p += k;
                n -= k;
                if (a->mInBuffer == NULL) {
                    k = 0;
                }
            } while (k != 0);
            break;
    }
    if (n < 0) {
        func_0213442c(data_ov000_021b2228, data_ov000_021b2218, NULL, 0x4af);
    }
    if (a->mInBuffer == NULL) {
        return 0;
    }
    if (n != 0) {
        memmove(a->mInBuffer, p, n);
    }
    a->mInBufferLength = n;
    return 0;
}

s32 func_ov000_0218c0bc(SbServerList *a, u8 *b, s32 c) {
    s32 d;
    s32 i;
    s32 k;
    Unk0218c0bc e;
    d = b[0];
    b += 1;
    c -= 1;
    if (a->mUnk_008 != NULL) {
        func_ov000_0218c9d4(a);
    }
    a->mUnk_008 = DarrayCreate(8, d, NULL);
    if (a->mUnk_008 == NULL) {
        return 5;
    }
    i = 0;
    if (d > 0) {
        do {
            if (c < 2) {
                return 4;
            }
            k = func_ov000_0218d0c8(b + 1, c - 1);
            if (k == -1) {
                return 4;
            }
            e.mUnk_04 = b[0];
            e.mUnk_00 = func_ov000_0218d134(a, (const char *) (b + 1));
            DarrayAppend(a->mUnk_008, &e);
            k += 1;
            b += k;
            c -= k;
            i++;
        } while (i < d);
    }
    return 0;
}

s32 func_ov000_0218bf78(SbServerList *a, u8 *b, s32 c) {
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
            k = func_ov000_0218d0c8(b, c);
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
            m = func_ov000_0218d0c8(b, c);
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

s32 func_ov000_0218be68(SbServerList *a, u8 *b, s32 c) {
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
    i = func_ov000_0218d2a8(a, d, e);
    if (i == -1) {
        return 0;
    }
    f = func_ov000_0218d218(a, i);
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
        i = func_ov000_0218d0c8(b, c);
        if (i == -1) {
            return 4;
        }
        k[j] = b;
        b += i;
        c -= i;
        j++;
    }
    if (a->mUnk_48c == NULL) {
        return 0;
    }
    a->mUnk_48c(a, f, g, j, k, a->mUnk_494);
    return 0;
}

s32 func_ov000_0218be10(SbServerList *a, u8 *b, s32 c) {
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
    f = func_ov000_0218d2a8(a, d, e);
    if (f != -1) {
        func_ov000_0218d238(a, f);
        return 0;
    }
    return 0;
}

s32 func_ov000_0218bd5c(SbServerList *a, u8 *b, s32 c) {
    s32 d;
    void *e;
    u16 f;
    u32 g;
    if (c < 5) {
        return 4;
    }
    func_ov000_0218c744(a, b, c, (u8 *) &g, &f);
    d = func_ov000_0218d2a8(a, g, f);
    if (d == -1) {
        e = func_ov000_0218af28(a, g, f);
        if (func_ov000_0218aefc(e) != 0) {
            return 5;
        }
    } else {
        e = (void *) func_ov000_0218d218(a, d);
    }
    if (func_ov000_0218c550(a, e, b, c, 0) < 0) {
        return 4;
    }
    if (d == -1) {
        func_ov000_0218d340(a, (u32) e);
    }
    a->mCallback(a, 1, e, a->mUnk_494);
    return 0;
}

s32 func_ov000_0218bc08(SbServerList *slist) {
    s32 b;
    u16 c;
    u8 *q;
    u8 *p;
    b = 0;
    while (slist->mInBufferLength >= 3) {
        q = (u8 *) &c;
        p = slist->mInBuffer;
        q[0] = p[0];
        q[1] = p[1];
        c = (c >> 8 & 0xff) | (c << 8 & 0xff00);
        if (c > 0x1000) {
            b = 4;
            break;
        }
        if (slist->mInBufferLength < c) {
            return 0;
        }
        switch ((s8) slist->mInBuffer[2]) {
            case 1:
                b = func_ov000_0218c0bc(slist, slist->mInBuffer + 3, c - 3);
                break;
            case 2:
                b = func_ov000_0218bd5c(slist, slist->mInBuffer + 3, c - 3);
                break;
            case 3:
                if (func_ov000_0218e420(slist->mUnk_4b0, slist->mInBuffer, c, 0) <= 0) {
                    return 3;
                }
                break;
            case 4:
                b = func_ov000_0218be10(slist, slist->mInBuffer + 3, c - 3);
                break;
            case 5:
                b = func_ov000_0218be68(slist, slist->mInBuffer + 3, c - 3);
                break;
            case 6:
                b = func_ov000_0218bf78(slist, slist->mInBuffer + 3, c - 3);
                break;
        }
        slist->mInBufferLength -= c;
        if (slist->mInBufferLength < 0) {
            func_0213442c(data_ov000_021b2200, data_ov000_021b2218, NULL, 0x5b4);
        }
        if (slist->mInBufferLength != 0 && slist->mInBuffer != NULL) {
            memmove(slist->mInBuffer, slist->mInBuffer + c, slist->mInBufferLength);
        }
        if (b != 0) {
            break;
        }
    }
    if (b != 0) {
        func_ov000_0218cf30(slist);
    }
    return b;
}

s32 func_ov000_0218bb44(SbServerList *a) {
    s32 b;
    s32 c;
    s32 d;
    if (func_ov000_0218e668(a->mUnk_4b0) == 0) {
        return 0;
    }
    b = a->mInBufferLength;
    c = func_ov000_0218e460(a->mUnk_4b0, a->mInBuffer + b, 0x1000 - b, 0);
    if ((u32) (c + 1) <= 1) {
        func_ov000_0218cf30(a);
        return 3;
    }
    a->mInBufferLength += c;
    d = 0;
    if (a->mState == 2 || a->mUnk_5c8 > 0) {
        func_ov000_0218a6f4(a->mUnk_4bc, a->mInBuffer + b, a->mInBufferLength - b);
    }
    if (a->mState == 3) {
        d = func_ov000_0218c15c(a);
    }
    if (d != 0) {
        return d;
    }
    if (a->mState == 2 && a->mInBufferLength > 0) {
        return func_ov000_0218bc08(a);
    }
    return 0;
}

s32 func_ov000_0218ba88(SbServerList *a, u32 b, u16 c, u8 *d, s32 e) {
    Unk0218ba88 g;
    u16 h;
    u8 *p;
    u8 *q;
    s32 r;
    if (a->mState == 1) {
        func_ov000_0218ca58(a, NULL, NULL, 2, 0);
    }
    if (a->mState == 1) {
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

s32 func_ov000_0218ba10(SbServerList *a, u32 b, u16 c, u32 d) {
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

s32 func_ov000_0218b928(SbServerList *a) {
    Unk0218b8f4 v1;
    s32 v2;
    u8 v3[0x5e0];
    void *p;
    v2 = 8;
    while (func_ov000_0218e668(a->mUnk_4b0) != 0) {
        if (func_ov000_0218e438(a->mUnk_4b0, v3, 0x5db, 0, (u8 *) &v1, &v2) != -1) {
            if (func_ov000_0218d2a8(a, v1.mUnk_04, v1.mUnk_02) == -1) {
                p = func_ov000_0218af28(a, v1.mUnk_04, v1.mUnk_02);
                if (func_ov000_0218aefc(p) != 0) {
                    return 5;
                }
                func_ov000_0218af24(p, 0x11);
                func_ov000_0218d340(a, (u32) p);
            }
        }
    }
    if (func_ov000_0218e8c4() - a->mUnk_4b4 > 0x7d0) {
        func_ov000_0218e53c(a->mUnk_4b0);
        a->mUnk_4b0 = -1;
        a->mState = 1;
        a->mCallback(a, 3, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
    }
    return 0;
}

s32 func_ov000_0218b8e4(SbServerList *a) {
    func_ov000_0218d1dc(a);
    switch (a->mState) {
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

void func_ov000_0218b780(SbServerList *a, s32 b, SbServer *c, Unk0218b668 *d) {
    switch (b) {
        case 0:
            d->mUnk_630(d, 0, c, d->mUnk_634);
            if (((c->mUnk_14 & 3) == 0 || (c->mUnk_14 & 0x40) == 0) && (c->mUnk_14 & 0x2c) == 0 && d->mUnk_624 == 0) {
                s32 t;
                if (c->mUnk_15 & 1) {
                    if (d->mUnk_04c.mState == 0 || d->mUnk_000.mUnk_40 == 0) {
                        t = 1;
                    } else {
                        t = 0;
                    }
                } else {
                    t = 2;
                }
                func_ov000_0218ac54(&d->mUnk_000, c, 0, t);
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
                func_ov000_0218a918(d, c);
            }
            d->mUnk_630(d, 3, c, d->mUnk_634);
            break;
        case 3:
            if (d->mUnk_620 != 0) {
                func_ov000_0218c980(a);
            }
            if (DarrayGetCount(a->mUnk_004) == 0 || d->mUnk_000.mUnk_08.mUnk_08 == 0) {
                d->mUnk_630(d, 4, 0, d->mUnk_634);
            }
            break;
        case 5:
            d->mUnk_630(d, 5, 0, d->mUnk_634);
            break;
        case 6:
            func_ov000_0218acf0(d, d->mUnk_04c.mUnk_4a0);
            break;
    }
    if (c != NULL && c->mUnk_00 == d->mUnk_628 && c->mUnk_04 == d->mUnk_62c) {
        d->mUnk_628 = 0;
    }
}

void func_ov000_0218b708(void *a, s32 b, SbServer *c, Unk0218b668 *d) {
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
    if (c != NULL && c->mUnk_00 == d->mUnk_628 && c->mUnk_04 == d->mUnk_62c) {
        d->mUnk_628 = 0;
    }
}
