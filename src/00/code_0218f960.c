#include "00/code_0218f960.h"

#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_02194840.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218d818.h"
#include "00/code_0218e2dc.h"
#include "00/code_021965a0.h"
#include "00/code_02190cd4.h"
#include "00/code_02196000.h"
#include "code_02135014.h"
#include "00/code_021906e4.h"
#include "00/code_02194000.h"
#include "00/code_021947e4.h"
#include "00/code_02190548.h"
#include "00/code_021948f8.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_02194bb8.h"
#include "00/code_02193000.h"
#include "00/code_02193b88.h"
#include "00/code_02192000.h"
#include "00/code_021a3668.h"
#include "00/unk_021b23b0.h"
#include "00/code_021967b4.h"

s32 func_ov000_0218fca8(GpConnection *a, char *b) {
    char c[0x1000];
    char d[0x100];
    char e[0x10];
    Unk02190ed4Cb s1;
    Unk02190ed4Cb s2;
    Unk02190ed4Cb s3;
    Unk02190ed4Cb s4;
    s32 z;
    s32 y;
    s32 k;
    s32 n;
    s32 r;
    u16 h;
    char *q;
    u8 *w;
    enum { K0 } i;
    GpiConnection *o;
    Unk0218fca8 *p1;
    Unk0218fca8_40c *p2;
    Unk0218fca8_108 *p3;
    Unk02194934 *p;
    Unk02194934_08 *t;

    o = a->mGpiConnection;
    if (func_ov000_021967b4(b, data_ov000_021b27c4, c, 0x1000) == 0) {
        func_ov000_021965a0(a, 1, data_ov000_021b27d8);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    k = func_0213bf90(c);
    if (func_ov000_021967b4(b, data_ov000_021b2808, c, 0x1000) == 0) {
        func_ov000_021965a0(a, 1, data_ov000_021b27d8);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    y = func_0213bf90(c);
    if (func_ov000_021967b4(b, data_ov000_021b280c, c, 0x1000) != 0) {
        z = func_0213bf90(c);
    } else {
        z = func_ov000_0218e320(NULL);
    }
    switch (k) {
        case 1:
            s1 = o->mCallbacks[3];
            if (s1.mUnk_00 == NULL) {
                break;
            }
            p1 = func_ov000_021a3690(0xc);
            if (p1 == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            if (func_ov000_021967b4(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            p1->mUnk_08 = func_ov000_021a3690(strlen(c) + 1);
            if (p1->mUnk_08 == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            strcpy(p1->mUnk_08, c);
            p1->mUnk_00 = y;
            p1->mUnk_04 = z;
            r = func_ov000_02190ed4(a, s1, p1, NULL, 2);
            if (r != 0) {
                return r;
            }
            break;
        case 2:
            p = func_ov000_0219496c(a, y);
            if (p == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            if (func_ov000_021967b4(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            q = strstr(c, data_ov000_021b2824);
            if (q == NULL) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            *q = 0;
            if (strlen(q + 8) != 0x20) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            func_ov000_021a3668(p->mUnk_10);
            p->mUnk_10 = NULL;
            q += 8;
            p->mUnk_10 = func_ov000_0218e880(q);
            p->mUnk_14++;
            s4 = o->mCallbacks[1];
            if (s4.mUnk_00 == NULL) {
                break;
            }
            p2 = func_ov000_021a3690(0x40c);
            if (p2 == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            func_ov000_02196914(p2->mUnk_008, c, 0x401);
            p2->mUnk_000 = y;
            p2->mUnk_004 = z;
            r = func_ov000_02190ed4(a, s4, p2, NULL, 6);
            if (r != 0) {
                return r;
            }
            break;
        case 100:
            p = func_ov000_0219496c(a, y);
            if (p == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            if (p->mUnk_08 == NULL) {
                p->mUnk_08 = func_ov000_021a3690(0x18);
                if (p->mUnk_08 == NULL) {
                    func_ov000_02196590(a, data_ov000_021b2814);
                    return 1;
                }
                w = (u8 *) p->mUnk_08;
                i = 0x18;
                do {
                    *w++ = 0;
                } while (--i != 0);
                p->mUnk_08->mUnk_00 = o->mBuddyCount++;
            }
            t = p->mUnk_08;
            if (func_ov000_021967b4(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2830, e, 0x10) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            t->mUnk_04 = func_0213bf90(e);
            func_ov000_021a3668(t->mUnk_08);
            t->mUnk_08 = NULL;
            if (func_ov000_021967b4(c, data_ov000_021b2834, d, 0x100) == 0) {
                d[0] = 0;
            }
            t->mUnk_08 = func_ov000_0218e880(d);
            if (t->mUnk_08 == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            func_ov000_021a3668(t->mUnk_0c);
            t->mUnk_0c = NULL;
            if (func_ov000_021967b4(c, data_ov000_021b283c, d, 0x100) == 0) {
                d[0] = 0;
            }
            t->mUnk_0c = func_ov000_0218e880(d);
            if (t->mUnk_0c == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2844, e, 0x10) == 0) {
                t->mUnk_10 = 0;
            } else {
                t->mUnk_10 = (((u32) func_0213bf90(e) >> 24) & 0xff) | (((u32) func_0213bf90(e) >> 8) & 0xff00) |
                             (((u32) func_0213bf90(e) << 8) & 0xff0000) | (((u32) func_0213bf90(e) << 24) & 0xff000000);
            }
            if (func_ov000_021967b4(c, data_ov000_021b284c, e, 0x10) == 0) {
                t->mUnk_14 = 0;
            } else {
                h = func_0213bf90(e);
                t->mUnk_14 = (u16) (((h >> 8) & 0xff) | ((h << 8) & 0xff00));
            }
            s3 = o->mCallbacks[2];
            if (s3.mUnk_00 == NULL) {
                break;
            }
            p1 = func_ov000_021a3690(0xc);
            if (p1 == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            p1->mUnk_00 = y;
            p1->mUnk_08 = (void *) t->mUnk_00;
            p1->mUnk_04 = z;
            r = func_ov000_02190ed4(a, s3, p1, NULL, 5);
            if (r != 0) {
                return r;
            }
            break;
        case 101:
            if (func_ov000_021967b4(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            q = strstr(c, data_ov000_021b284c);
            if (q == NULL) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if ((s8) q[3] == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            n = func_0213bf90(q + 3);
            q = strstr(c, data_ov000_021b2850);
            if (q != NULL) {
                func_ov000_02196914(d, (q + 3), 0x100);
            } else {
                d[0] = 0;
            }
            s2 = o->mCallbacks[4];
            if (s2.mUnk_00 == NULL) {
                break;
            }
            p3 = func_ov000_021a3690(0x108);
            if (p3 == NULL) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            p3->mUnk_000 = y;
            p3->mUnk_004 = n;
            strcpy(p3->mUnk_008, d);
            r = func_ov000_02190ed4(a, s2, p3, NULL, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 102:
            if (func_ov000_021967b4(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            func_ov000_0218fb3c(a, y, 0x67, data_ov000_021b2854);
            break;
    }
    return 0;
}

u32 func_ov000_0218fbe0(GpConnection *a, s32 b, s32 c, const char *d) {
    GpiConnection *o;
    char e[0xdad];
    o = a->mGpiConnection;
    func_ov000_02196914(e, d, 0xdad);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b27c4);
    func_ov000_02190b58(a, &o->mOutputBuffer, c);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b275c);
    func_ov000_02190b58(a, &o->mOutputBuffer, o->mSesskey);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b27cc);
    func_ov000_02190b58(a, &o->mOutputBuffer, b);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b27d0);
    func_ov000_02190b80(a, &o->mOutputBuffer, e);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b2778);
    return 0;
}

u32 func_ov000_0218fb3c(GpConnection *a, s32 b, s32 c, const char *d) {
    Unk02194934 *e;
    Unk02193f2cNode *n;
    u32 r;
    n = func_ov000_02193f2c(a, b);
    if (n == NULL) {
        if (func_ov000_02194934(a, b, &e) == 0 || e->mUnk_08 == NULL || e->mUnk_08->mUnk_14 == 0) {
            return func_ov000_0218fbe0(a, b, c, d);
        }
        n = func_ov000_02193eac(a, b, 1);
        if (n == NULL) {
            return 1;
        }
        if (e->mUnk_18 == NULL) {
            r = func_ov000_02193e70(a, n);
            if (r != 0) {
                return r;
            }
        } else {
            r = func_ov000_02193d64(a, n);
            if (r != 0) {
                return r;
            }
        }
    }
    r = func_ov000_02193c74(a, n, c, d);
    if (r == 0) {
        return 0;
    }
    return r;
}

u32 func_ov000_0218faac(GpConnection *a, u32 b) {
    GpiConnection *o;
    Unk02194934 *e;
    u32 r;
    o = a->mGpiConnection;
    if (func_ov000_02194934(a, b, &e) == 0) {
        func_ov000_02196590(a, data_ov000_021b273c);
        return 2;
    }
    if (e->mUnk_10 == NULL) {
        func_ov000_02196590(a, data_ov000_021b273c);
        return 2;
    }
    r = func_ov000_02190548(a, e);
    if (r == 0) {
        e->mUnk_14--;
        if (o->mUnk_100 == 0 && e->mUnk_14 <= 0) {
            func_ov000_021a3668(e->mUnk_10);
            e->mUnk_10 = NULL;
            if (func_ov000_021947e4(e) != 0) {
                func_ov000_021948f8(a, e);
            }
        }
        return 0;
    }
    return r;
}

s32 func_ov000_0218fa98(void *unused, Unk0218fa98 *object, s32 minimum) {
    if (object->mUnk_08 != NULL && *object->mUnk_08 > minimum) {
        --*object->mUnk_08;
    }
    return 1;
}

u32 func_ov000_0218f960(GpConnection *p, u32 b) {
    GpiConnection *o;
    Unk02194934 *e;
    s32 n;

    o = p->mGpiConnection;
    if (func_ov000_02194934(p, b, &e) == 0) {
        func_ov000_02196590(p, data_ov000_021b273c);
        return 2;
    }
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2750);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b275c);
    func_ov000_02190b58(p, &o->mOutputBuffer, o->mSesskey);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2768);
    func_ov000_02190b58(p, &o->mOutputBuffer, e->mUnk_00);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2778);
    if (e->mUnk_08 != NULL) {
        n = e->mUnk_08->mUnk_00;
        if (n < 0) {
            func_0213442c(data_ov000_021b2780, data_ov000_021b278c, NULL, 0x1fd);
        }
        func_ov000_021a3668(e->mUnk_08->mUnk_08);
        e->mUnk_08->mUnk_08 = NULL;
        func_ov000_021a3668(e->mUnk_08->mUnk_0c);
        e->mUnk_08->mUnk_0c = NULL;
        func_ov000_021a3668(e->mUnk_08);
        e->mUnk_08 = NULL;
        if (func_ov000_021947e4(e) != 0) {
            func_ov000_021948f8(p, e);
        }
        o->mBuddyCount--;
        if (o->mBuddyCount < 0) {
            func_0213442c(data_ov000_021b2798, data_ov000_021b278c, NULL, 0x204);
        }
        func_ov000_02194840(p, func_ov000_0218fa98, (void *) n);
    }
    return 0;
}
