#include "00/code_021ae314.h"
#include "00/code_021ae0c4.h"
#include "00/code_021a9228.h"
#include "00/code_021af550.h"
#include "00/code_021aefa8.h"
#include "00/code_021ae958.h"
#include "00/code_021ae984.h"
#include "00/code_021b0014.h"
#include "00/unk_021b6000.h"
#include "code_02133048.h"
#include "code_0214d018.h"
#include "code_0200f5ac.h"
#include "code_0200db4c.h"
#include "Main/Unknown/unk_0216f000.h"

void func_ov000_021ae87c(Unk021ae3f0 *a, Unk021ae87c *b, u32 c) {
    if (func_ov000_021b0138(b, c, (const Unk021b0138 *) a, 6) != 0) {
        return;
    }
    c -= (b->mUnk_0c & 0xf0) / 4;
    switch (b->mUnk_0d & 0x17) {
        case 2:
            if (b->mUnk_0d & 0x28) {
                return;
            }
            func_ov000_021aed3c(a, b, c);
            return;
        case 0x12:
            if (b->mUnk_0d & 0x28) {
                return;
            }
            func_ov000_021aec84(a, b, c);
            return;
        case 0x10:
        case 0x11:
            func_ov000_021aea34(a, b, c);
            return;
        case 1:
            func_ov000_021ae984(a, b, c);
            return;
        default:
            if (b->mUnk_0d & 4) {
                func_ov000_021ae958(a, b);
                return;
            }
            func_ov000_021aeed8(a, b, c, (a->mUnk_05 << 8) + 0x17);
            return;
    }
}

void func_ov000_021ae724(Unk021ae3f0 *a, Unk021ae724 *b, u32 c) {
    Unk0200db5c *t;
    Unk021a998c *s;

    if (b->mUnk_06 != 0 && func_ov000_021b0138(b, c, (const Unk021b0138 *) a, 0x11) != 0) {
        return;
    }
    for (t = data_0216ff5c.mUnk_08; t != NULL; t = t->mUnk_68) {
        s = *(Unk021a998c **) t->mUnk_a4;
        if (s == NULL || s->mThread == NULL || s->mState != 0xa ||
            s->mUnk_0a != (u16) ((b->mUnk_02 >> 8) | (b->mUnk_02 << 8))) {
            continue;
        }
        if (s->mUnk_18 != 0 && s->mUnk_18 != (u16) ((b->mUnk_00 >> 8) | (b->mUnk_00 << 8))) {
            continue;
        }
        if (s->mUnk_1c != 0 && s->mUnk_1c != 0xffffffff &&
            s->mUnk_1c != (u32) (((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) |
                                 (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8)))) {
            continue;
        }
        s->mUnk_14 = (u32) (((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) |
                            (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8)));
        if (s->mUnk_1c == 0) {
            s->mUnk_1c = (u32) (((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) |
                                (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8)));
            s->mUnk_18 = (u16) ((b->mUnk_00 >> 8) | (b->mUnk_00 << 8));
        }
        if (s->mReceiveBufferLength != 0) {
            return;
        }
        c -= 8;
        if (c > s->mReceiveBufferSize) {
            s->mReceiveBufferLength = s->mReceiveBufferSize;
        } else {
            s->mReceiveBufferLength = c;
        }
        MemCopy((u8 *) b + 8, s->mReceiveBuffer, s->mReceiveBufferLength);
        if (s->mUnk_04 == 3) {
            s->mUnk_04 = 0;
            func_0200df68(s->mThread);
            return;
        }
        if (s->mReceiveCallback != NULL && s->mReceiveCallback(s->mReceiveBuffer, s->mReceiveBufferLength, s) != 0) {
            s->mReceiveBufferLength = 0;
        }
        return;
    }
}

Unk021ae3f0 *func_ov000_021ae51c(Unk021ae3f0 *r, u32 *s) {
    u32 a;
    u32 d;
    u32 e;
    u32 b;
    u32 g;
    u32 f;
    u32 c;
    u32 h;
    u32 q;
    u32 j;
    Unk021b69dc *l;
    Unk021b69dc *k;
    u16 m;
    u32 n;
    u32 o;
    u32 i;

    *s = 0;
    a = (u16) ((r->mUnk_06 >> 8) | (r->mUnk_06 << 8));
    if ((a & 0x3fff) == 0) {
        return r;
    }
    b = (r->mUnk_00 & 0xf) << 2;
    m = *(u16 *) &r->mUnk_04;
    c = (u32) (((u16) ((r->mUnk_0c >> 8) | (r->mUnk_0c << 8)) << 16) | (u16) ((r->mUnk_0e >> 8) | (r->mUnk_0e << 8)));
    l = NULL;
    k = data_ov000_021b69dc;
    for (n = 0; n < 8; k++, n++) {
        if (k->mUnk_04 != 0 && k->mUnk_00 == c && k->mUnk_06 == m) {
            break;
        }
        if (k->mUnk_04 == 0 && l == NULL) {
            l = k;
        }
    }
    d = (u16) ((r->mUnk_02 >> 8) | (r->mUnk_02 << 8)) - b;
    e = a & 0x1fff;
    f = e << 3;
    g = d + f;
    if (n == 8) {
        if (l == NULL || g > 0x1000) {
            return NULL;
        }
        k = l;
        l->mUnk_34 = data_ov000_021b63a4(b + 0x100e);
        if (l->mUnk_34 == NULL) {
            return NULL;
        }
        l->mUnk_00 = c;
        l->mUnk_06 = m;
        l->mUnk_08 = 0;
        l->mUnk_2c = func_0200f5ac() >> 16;
        l->mUnk_30 = l->mUnk_34 + 0xe + b;
        MemCopy(r, l->mUnk_34 + 0xe, b);
    }
    if (k->mUnk_04 == 8 || g > 0x1000) {
        k->mUnk_04 = 0;
        data_ov000_021b63ac(k->mUnk_34);
        return NULL;
    }
    h = e + ((d + 7) >> 3);
    a = a & 0x2000;
    if (a == 0) {
        k->mUnk_0a = g;
        k->mUnk_08 = h;
    }
    k->mUnk_0c[k->mUnk_04] = e;
    k->mUnk_1c[k->mUnk_04] = h;
    k->mUnk_04++;
    MemCopy((u8 *) r + b, k->mUnk_30 + f, d);
    j = k->mUnk_08;
    if (j == 0) {
        return NULL;
    }
    i = 0;
    o = 0;
    q = k->mUnk_04;
    while (o < q) {
        if (k->mUnk_0c[o] <= i && i < k->mUnk_1c[o]) {
            i = k->mUnk_1c[o];
            o = 0;
        } else {
            o++;
        }
    }
    if (i < j) {
        return NULL;
    }
    {
        Unk021ae3f0 *p = (Unk021ae3f0 *) (k->mUnk_34 + 0xe);

        p->mUnk_02 = (u16) (((u16) (k->mUnk_0a + ((p->mUnk_00 & 0xf) << 2)) >> 8) |
                            ((u16) (k->mUnk_0a + ((p->mUnk_00 & 0xf) << 2)) << 8));
        k->mUnk_04 = 0;
        *s = 1;
        return p;
    }
}

void func_ov000_021ae3f0(Unk021ae3f0 *a, u32 f) {
    u32 b;

    if ((u32) (((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) | (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8))) !=
        (u32) (((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) | (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8)))) {
        if (func_ov000_021b003c((u32) (((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) |
                                       (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8)))) == 0) {
            return;
        }
        if (f < (u16) ((a->mUnk_02 >> 8) | (a->mUnk_02 << 8))) {
            return;
        }
        if (func_ov000_021b0188(a, (a->mUnk_00 & 0xf) << 2) != 0xffff) {
            return;
        }
        if (data_ov000_021b63b4 == (u32) (((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) |
                                          (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8)))) {
            func_ov000_021afb58((u8 *) a - 8,
                                (u32) (((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) |
                                       (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8))),
                                0);
        }
    }
    a = func_ov000_021ae51c(a, &b);
    if (a != NULL) {
        u32 c = (a->mUnk_00 & 0xf) << 2;
        void *p = (u8 *) a + c;
        u32 d = (u16) ((a->mUnk_02 >> 8) | (a->mUnk_02 << 8)) - c;
        u32 e = a->mUnk_09;

        if (e == 0x11) {
            func_ov000_021ae724(a, p, d);
        } else if (data_ov000_021b63b4 != 0) {
            if (e == 1) {
                func_ov000_021af1e4(a, p, d);
            } else if (e == 6) {
                func_ov000_021ae87c(a, p, d);
            }
        }
        if (b != 0) {
            data_ov000_021b63ac((u8 *) a - 0xe);
        }
    }
}

void func_ov000_021ae3a4(void) {
    u32 v1;
    Unk021ae3a4 *v2;

    for (;;) {
        v2 = (Unk021ae3a4 *) func_ov000_021afdcc(&v1);
        if (v1 > 0x22) {
            switch ((u16) ((v2->mUnk_0c >> 8) | (v2->mUnk_0c << 8))) {
                case 0x800:
                    func_ov000_021ae3f0((Unk021ae3f0 *) ((u8 *) v2 + 0xe), v1 - 0xe);
                    break;
                case 0x806:
                    func_ov000_021af3e8((Unk021af3e8 *) ((u8 *) v2 + 0xe), v1 - 0xe);
                    break;
            }
        }
        func_ov000_021afd8c();
    }
}

u16 func_ov000_021ae340(void) {
    u32 v1;
    Unk0200db5c *t;
    Unk021a998c *s;

    do {
        v1 = 0;
        data_ov000_021b6374++;
        if (data_ov000_021b6374 < 0x400 || data_ov000_021b6374 >= 0x1388) {
            data_ov000_021b6374 = 0x400;
        }
        for (t = data_0216ff5c.mUnk_08; t != NULL; t = t->mUnk_68) {
            s = *(Unk021a998c **) t->mUnk_a4;
            if (s != NULL && s->mThread != NULL && s->mUnk_0a == data_ov000_021b6374) {
                v1 = 1;
                break;
            }
        }
    } while (v1 != 0);
    return data_ov000_021b6374;
}

u32 func_ov000_021ae314(void) {
    data_ov000_021b63e0[0] = data_ov000_021b63e0[2] + data_ov000_021b63e0[1] * data_ov000_021b63e0[0];
    return data_ov000_021b63e0[0] >> 32;
}
