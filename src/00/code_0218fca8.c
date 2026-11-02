#include "00/code_0218fca8.h"
#include "00/code_02190000.h"
#include "00/code_02196590.h"
#include "00/code_021965a0.h"
#include "00/code_02196914.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

s32 func_ov000_0218fca8(Unk0218f960 *a, u8 *b) {
    u8 c[0x1000];
    u8 d[0x100];
    u8 e[0x10];
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
    u8 *q;
    u8 *w;
    enum { K0 } i;
    Unk0218f960_00 *o;
    Unk0218fca8 *p1;
    Unk0218fca8_40c *p2;
    Unk0218fca8_108 *p3;
    Unk02194934 *p;
    Unk02194934_08 *t;

    o = a->mUnk_00;
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
        z = func_ov000_0218e320(0);
    }
    switch (k) {
        case 1:
            s1 = o->mUnk_1a4[3];
            if (s1.mUnk_00 == 0) {
                break;
            }
            p1 = func_ov000_021a3690(0xc);
            if (p1 == 0) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            if (func_ov000_021967b4(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            p1->mUnk_08 = func_ov000_021a3690(strlen(c) + 1);
            if (p1->mUnk_08 == 0) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            strcpy(p1->mUnk_08, c);
            p1->mUnk_00 = y;
            p1->mUnk_04 = z;
            r = func_ov000_02190ed4(a, s1, p1, 0, 2);
            if (r != 0) {
                return r;
            }
            break;
        case 2:
            p = func_ov000_0219496c(a, y);
            if (p == 0) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            if (func_ov000_021967b4(b, data_ov000_021b27d0, c, 0x1000) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b27d8);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            q = (u8 *) strstr(c, data_ov000_021b2824);
            if (q == 0) {
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
            p->mUnk_10 = 0;
            q += 8;
            p->mUnk_10 = func_ov000_0218e880(q);
            p->mUnk_14++;
            s4 = o->mUnk_1a4[1];
            if (s4.mUnk_00 == 0) {
                break;
            }
            p2 = func_ov000_021a3690(0x40c);
            if (p2 == 0) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            func_ov000_02196914(p2->mUnk_008, c, 0x401);
            p2->mUnk_000 = y;
            p2->mUnk_004 = z;
            r = func_ov000_02190ed4(a, s4, p2, 0, 6);
            if (r != 0) {
                return r;
            }
            break;
        case 100:
            p = func_ov000_0219496c(a, y);
            if (p == 0) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            if (p->mUnk_08 == 0) {
                p->mUnk_08 = func_ov000_021a3690(0x18);
                if (p->mUnk_08 == 0) {
                    func_ov000_02196590(a, data_ov000_021b2814);
                    return 1;
                }
                w = (u8 *) p->mUnk_08;
                i = 0x18;
                do {
                    *w++ = 0;
                } while (--i != 0);
                p->mUnk_08->mUnk_00 = o->mUnk_430++;
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
            t->mUnk_08 = 0;
            if (func_ov000_021967b4(c, data_ov000_021b2834, d, 0x100) == 0) {
                d[0] = 0;
            }
            t->mUnk_08 = func_ov000_0218e880(d);
            if (t->mUnk_08 == 0) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            func_ov000_021a3668(t->mUnk_0c);
            t->mUnk_0c = 0;
            if (func_ov000_021967b4(c, data_ov000_021b283c, d, 0x100) == 0) {
                d[0] = 0;
            }
            t->mUnk_0c = func_ov000_0218e880(d);
            if (t->mUnk_0c == 0) {
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
            s3 = o->mUnk_1a4[2];
            if (s3.mUnk_00 == 0) {
                break;
            }
            p1 = func_ov000_021a3690(0xc);
            if (p1 == 0) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            p1->mUnk_00 = y;
            p1->mUnk_08 = (void *) t->mUnk_00;
            p1->mUnk_04 = z;
            r = func_ov000_02190ed4(a, s3, p1, 0, 5);
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
            q = (u8 *) strstr(c, data_ov000_021b284c);
            if (q == 0) {
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
            q = (u8 *) strstr(c, data_ov000_021b2850);
            if (q != 0) {
                func_ov000_02196914(d, (q + 3), 0x100);
            } else {
                d[0] = 0;
            }
            s2 = o->mUnk_1a4[4];
            if (s2.mUnk_00 == 0) {
                break;
            }
            p3 = func_ov000_021a3690(0x108);
            if (p3 == 0) {
                func_ov000_02196590(a, data_ov000_021b2814);
                return 1;
            }
            p3->mUnk_000 = y;
            p3->mUnk_004 = n;
            strcpy((char *) p3->mUnk_008, d);
            r = func_ov000_02190ed4(a, s2, p3, 0, 0);
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
