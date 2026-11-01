#include "00/code_021ae314.h"
#include "00/code_021ae0c4.h"
#include "00/code_021a9228.h"
#include "00/code_021af550.h"
#include "00/code_021aefc0.h"
#include "00/code_021af2a0.h"
#include "00/code_021ae958.h"
#include "00/code_021ae984.h"
#include "00/code_021b0014.h"
#include "00/unk_021b6000.h"
#include "code_02133048.h"
#include "code_0214d018.h"
#include "code_0200f5ac.h"
#include "code_0200dc3c.h"
#include "Main/Unknown/unk_0216f000.h"

u32 func_ov000_021ae314(void) {
    data_ov000_021b63e0[0] = data_ov000_021b63e0[2] + data_ov000_021b63e0[1] * data_ov000_021b63e0[0];
    return data_ov000_021b63e0[0] >> 32;
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
        for (t = data_0216ff5c.mUnk_08; t != 0; t = t->mUnk_68) {
            s = *(Unk021a998c **) t->mUnk_a4;
            if (s != 0 && s->mUnk_00 != 0 && s->mUnk_0a == data_ov000_021b6374) {
                v1 = 1;
                break;
            }
        }
    } while (v1 != 0);
    return data_ov000_021b6374;
}

void func_ov000_021ae3a4(void) {
    u32 v1;
    Unk021ae3a4 *v2;

    while (1) {
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

void func_ov000_021ae3f0(Unk021ae3f0 *param_1, u32 param_2) {
    u32 b;

    if ((u32) (((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
               (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8))) !=
        (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
               (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)))) {
        if (func_ov000_021b003c((u32) (((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
                                       (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8)))) == 0) {
            return;
        }
        if (param_2 < (u16) ((param_1->mUnk_02 >> 8) | (param_1->mUnk_02 << 8))) {
            return;
        }
        if (func_ov000_021b0188(param_1, (param_1->mUnk_00 & 0xf) << 2) != 0xffff) {
            return;
        }
        if (data_ov000_021b63b4 == (u32) (((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
                                          (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8)))) {
            func_ov000_021afb58((u8 *) param_1 - 8,
                                (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                       (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8))),
                                0);
        }
    }
    param_1 = func_ov000_021ae51c(param_1, &b);
    if (param_1 != 0) {
        u32 c = (param_1->mUnk_00 & 0xf) << 2;
        void *p = (u8 *) param_1 + c;
        u32 d = (u16) ((param_1->mUnk_02 >> 8) | (param_1->mUnk_02 << 8)) - c;
        u32 e = param_1->mUnk_09;

        if (e == 0x11) {
            func_ov000_021ae724(param_1, p, d);
        } else if (data_ov000_021b63b4 != 0) {
            if (e == 1) {
                func_ov000_021af1e4(param_1, p, d);
            } else if (e == 6) {
                func_ov000_021ae87c(param_1, p, d);
            }
        }
        if (b != 0) {
            data_ov000_021b63ac((u8 *) param_1 - 0xe);
        }
    }
}

Unk021ae3f0 *func_ov000_021ae51c(Unk021ae3f0 *param_1, u32 *param_2) {
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

    *param_2 = 0;
    a = (u16) ((param_1->mUnk_06 >> 8) | (param_1->mUnk_06 << 8));
    if ((a & 0x3fff) == 0) {
        return param_1;
    }
    b = (param_1->mUnk_00 & 0xf) << 2;
    m = *(u16 *) &param_1->mUnk_04;
    c = (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
               (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)));
    l = 0;
    k = data_ov000_021b69dc;
    for (n = 0; n < 8; k++, n++) {
        if (k->mUnk_04 != 0 && k->mUnk_00 == c && k->mUnk_06 == m) {
            break;
        }
        if (k->mUnk_04 == 0 && l == 0) {
            l = k;
        }
    }
    d = (u16) ((param_1->mUnk_02 >> 8) | (param_1->mUnk_02 << 8)) - b;
    e = a & 0x1fff;
    f = e << 3;
    g = d + f;
    if (n == 8) {
        if (l == 0 || g > 0x1000) {
            return 0;
        }
        k = l;
        l->mUnk_34 = data_ov000_021b63a4(b + 0x100e);
        if (l->mUnk_34 == 0) {
            return 0;
        }
        l->mUnk_00 = c;
        l->mUnk_06 = m;
        l->mUnk_08 = 0;
        l->mUnk_2c = func_0200f5ac() >> 16;
        l->mUnk_30 = l->mUnk_34 + 0xe + b;
        func_0214d1fc(param_1, l->mUnk_34 + 0xe, b);
    }
    if (k->mUnk_04 == 8 || g > 0x1000) {
        k->mUnk_04 = 0;
        data_ov000_021b63ac(k->mUnk_34);
        return 0;
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
    func_0214d1fc((u8 *) param_1 + b, k->mUnk_30 + f, d);
    j = k->mUnk_08;
    if (j == 0) {
        return 0;
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
        return 0;
    }
    {
        Unk021ae3f0 *p = (Unk021ae3f0 *) (k->mUnk_34 + 0xe);

        p->mUnk_02 = (u16) (((u16) (k->mUnk_0a + ((p->mUnk_00 & 0xf) << 2)) >> 8) |
                            ((u16) (k->mUnk_0a + ((p->mUnk_00 & 0xf) << 2)) << 8));
        k->mUnk_04 = 0;
        *param_2 = 1;
        return p;
    }
}

void func_ov000_021ae724(Unk021ae3f0 *param_1, Unk021ae724 *param_2, u32 param_3) {
    Unk0200db5c *t;
    Unk021a998c *s;

    if (param_2->mUnk_06 != 0 && func_ov000_021b0138(param_2, param_3, (const Unk021b0138 *) param_1, 0x11) != 0) {
        return;
    }
    for (t = data_0216ff5c.mUnk_08; t != 0; t = t->mUnk_68) {
        s = *(Unk021a998c **) t->mUnk_a4;
        if (s == 0 || s->mUnk_00 == 0 || s->mUnk_08 != 0xa ||
            s->mUnk_0a != (u16) ((param_2->mUnk_02 >> 8) | (param_2->mUnk_02 << 8))) {
            continue;
        }
        if (s->mUnk_18 != 0 && s->mUnk_18 != (u16) ((param_2->mUnk_00 >> 8) | (param_2->mUnk_00 << 8))) {
            continue;
        }
        if (s->mUnk_1c != 0 && s->mUnk_1c != 0xffffffff &&
            s->mUnk_1c != (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                 (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)))) {
            continue;
        }
        s->mUnk_14 = (u32) (((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
                            (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8)));
        if (s->mUnk_1c == 0) {
            s->mUnk_1c = (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)));
            s->mUnk_18 = (u16) ((param_2->mUnk_00 >> 8) | (param_2->mUnk_00 << 8));
        }
        if (s->mUnk_44 != 0) {
            return;
        }
        param_3 -= 8;
        if (param_3 > s->mUnk_3c) {
            s->mUnk_44 = s->mUnk_3c;
        } else {
            s->mUnk_44 = param_3;
        }
        func_0214d1fc((u8 *) param_2 + 8, s->mUnk_40, s->mUnk_44);
        if (s->mUnk_04 == 3) {
            s->mUnk_04 = 0;
            func_0200df68(s->mUnk_00);
            return;
        }
        if (s->mUnk_38 != 0 && s->mUnk_38(s->mUnk_40, s->mUnk_44, s) != 0) {
            s->mUnk_44 = 0;
        }
        return;
    }
}

void func_ov000_021ae87c(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    if (func_ov000_021b0138(param_2, param_3, (const Unk021b0138 *) param_1, 6) != 0) {
        return;
    }
    param_3 -= (param_2->mUnk_0c & 0xf0) / 4;
    switch (param_2->mUnk_0d & 0x17) {
        case 2:
            if (param_2->mUnk_0d & 0x28) {
                return;
            }
            func_ov000_021aed3c(param_1, param_2, param_3);
            return;
        case 0x12:
            if (param_2->mUnk_0d & 0x28) {
                return;
            }
            func_ov000_021aec84(param_1, param_2, param_3);
            return;
        case 0x10:
        case 0x11:
            func_ov000_021aea34(param_1, param_2, param_3);
            return;
        case 1:
            func_ov000_021ae984(param_1, param_2, param_3);
            return;
        default:
            if (param_2->mUnk_0d & 4) {
                func_ov000_021ae958(param_1, param_2);
                return;
            }
            func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 0x17);
            return;
    }
}
