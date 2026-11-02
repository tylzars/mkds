#include "Main/Unknown/code_0203ba84.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200f5ac.h"
#include "code_0202056c.h"

#pragma thumb on

void func_0203bc64(u8 *b) {
    Unk0203ba84 *a;
    Unk020f41c4_B l;
    u32 f;
    u8 k;
    Unk020f41c4_B *r;
    u8 u;
    u8 n;
    u8 m;
    s32 e;
    s32 t;
    s32 w;
    u32 g;
    s32 y;
    s32 c;
    u64 t1;
    u64 t2;

    a = (Unk0203ba84 *) b;
    f = a->mUnk_00;
    c = 0;
    if ((data_0217aa00 == 0 ? 0 : data_0217aa00->mUnk_0000) != 0 && data_0217aa00->mUnk_0004 != 0xd) {
        c = 1;
    }
    if (c != 0) {
        r = &data_0217aa00->mUnk_1ee8;
    } else {
        t1 = func_0200f5ac();
        t2 = func_0200f5ac();
        l.mUnk_00 = (u32) ((u32) t1 << 24) + (u32) (t2 >> 8);
        l.mUnk_08 = 0x5d588b656c078965;
        l.mUnk_10 = 0x269ec3;
        r = &l;
    }
    for (k = 0; k < 8; k++) {
        e = -1;
        t = a->mUnk_04[k];
        n = 0;
        if ((f & (1 << k)) == 0) {
            a->mUnk_24[k] = -1;
            u = 0;
            w = t * 3;
            for (; u < 3; u++) {
                if (func_0205fc98(a->mUnk_44, t, u + w) != 0) {
                    n = (u8) (n | (1 << u));
                }
            }
            for (u = 0; u < 8; u++) {
                if ((f & (1 << u)) != 0 && a->mUnk_24[u] >= w && a->mUnk_24[u] < (t + 1) * 3) {
                    n = (u8) (n & ~(1 << (a->mUnk_24[u] - w)));
                }
            }
            if (n == 0) {
                for (u = 0; u < 3; u++) {
                    if (func_0205fc98(a->mUnk_44, t, u + w) != 0) {
                        n = (u8) (n | (1 << u));
                    }
                }
            }
            g = func_0202056c(n);
            if (g == 0) {
                y = 0;
            } else {
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                if (g == 0) {
                    y = r->mUnk_00 >> 32;
                } else {
                    y = ((r->mUnk_00 >> 32) * g) >> 32;
                }
            }
            m = 0;
            for (u = 0; u < 3 && e == -1; u++) {
                if ((n & (1 << u)) != 0) {
                    if (m == (u16) y) {
                        e = u + w;
                    } else {
                        m = (u8) (m + 1);
                    }
                }
            }
            a->mUnk_24[k] = e;
        }
    }
}

void func_0203ba84(u8 *b) {
    Unk0203ba84 *a;
    Unk020f41c4_B l;
    u16 m;
    s32 c;
    s32 x;
    u32 f;
    Unk020f41c4_B *r;
    u8 i;
    u8 k;
    u32 g;
    u32 n;
    u32 t;
    s32 v;
    s32 e;
    s32 y;
    u8 j;
    u64 t1;
    u64 t2;

    a = (Unk0203ba84 *) b;
    m = 0;
    f = a->mUnk_01;
    c = 0;
    if (data_0217aa00 == 0) {
        x = 0;
    } else {
        x = data_0217aa00->mUnk_0000;
    }
    if (x != 0 && data_0217aa00->mUnk_0004 != 0xd) {
        c = 1;
    }
    if (c != 0) {
        r = &data_0217aa00->mUnk_1ee8;
    } else {
        t1 = func_0200f5ac();
        t2 = func_0200f5ac();
        l.mUnk_00 = (u32) ((u32) t1 << 24) + (u32) (t2 >> 8);
        l.mUnk_08 = 0x5d588b656c078965;
        l.mUnk_10 = 0x269ec3;
        r = &l;
    }
    for (i = 0; i < 0xd; i++) {
        v = -1;
        if (i != 0xc) {
            switch (i) {
                case 8:
                    v = 0x14;
                    break;
                case 9:
                    v = 0x15;
                    break;
                case 10:
                    v = 0x16;
                    break;
                case 11:
                    v = 0x17;
                    break;
            }
            if (v == -1 || func_0205fc28(v) != 0) {
                m = (u16) (m | (1 << i));
            }
        }
    }
    for (k = 0; k < 8; k++) {
        t = a->mUnk_04[k];
        if (t != -1 && (f & (1 << k)) != 0) {
            m = (u16) (m & ~(1 << t));
        }
    }
    for (k = 0; k < 8; k++) {
        e = -1;
        g = func_0202056c(m);
        n = 0;
        if ((f & (1 << k)) == 0) {
            a->mUnk_04[k] = -1;
            if (g == 0) {
                y = n;
            } else {
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                if (g == 0) {
                    y = r->mUnk_00 >> 32;
                } else {
                    y = ((r->mUnk_00 >> 32) * g) >> 32;
                }
            }
            for (j = 0; j < 0xd && e == -1; j++) {
                if ((m & (1 << j)) != 0) {
                    if (n == (u16) y) {
                        m = (u16) (m & ~(1 << j));
                        e = j;
                    } else {
                        n = (u8) (n + 1);
                    }
                }
            }
            a->mUnk_04[k] = e;
        }
    }
}

#pragma thumb off
