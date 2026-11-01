#include "Main/Unknown/code_02070f8c.h"
#include "Main/Unknown/code_020720dc.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0208b748.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02086080.h"
#include "Main/Unknown/code_02089d14.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a588.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210b564.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"

void func_02071980(void *p, int b) {
    func_0210b2a8((Unk0206bcb0 *) p, b, ((Unk0206bcb0 *) p)->mUnk_3e0, ((Unk0206bcb0 *) p)->mUnk_3e4,
                  ((Unk0206bcb0 *) p)->mUnk_500);
}

void func_02071958(Unk0206bcb0 *p, s32 b) {
    func_0210b564((int) p, b, p->mUnk_3e0, p->mUnk_3e4, p->mUnk_500);
}

void func_02071944(void *p, int v1) {
    u32 v2 = (u32) p;
    u32 v3 = (u32) v1;
    u32 v4;
    u32 v5;
    u32 v6;
    v6 = (u32) &func_021090c4;
    v4 = 0x7fu;
    v5 = 0u;
    func_021090c4((Unk0210bfbc *) v2, (int) v3, (int) v4, (int) v5);
    return;
}

void func_02071914(void *p, int a) {
    if (func_02109078((Unk0210bfbc *) p, a, 0x7f, 0) != 0) {
        ((Unk0206bcb0 *) p)->mUnk_488 = a;
    }
}

void func_020718c8(void *p, int v1) {
    int v;

    v = func_02086080(((Unk0206bcb0 *) p)->mUnk_74);
    func_0210ddf4(&data_0217d284, v + func_0210a588(), func_02071914, p, v1);
}

void func_02071894(Unk0206bcb0 *p) {
    if (p->mUnk_48 & 0x840) {
        return;
    }
    func_0210af40(p, p->mUnk_3cc, 7);
}

void func_02071788(Unk0206bcb0 *p) {
    p->mUnk_3fe++;
    if (p->mUnk_3fe >= p->mUnk_400) {
        p->mUnk_3fe = 0;
        p->mUnk_4c &= ~8;
        return;
    }
    if (p->mUnk_3fc == 0) {
        p->mUnk_404 = data_02154be4[p->mUnk_3fe];
        p->mUnk_408 = data_02154c20[p->mUnk_3fe];
        p->mUnk_418 = 0x1000;
        p->mUnk_414 = p->mUnk_418;
    } else if (p->mUnk_3fc == 1) {
        p->mUnk_404 = data_02154c5c[p->mUnk_3fe];
        p->mUnk_408 = data_02154c98[p->mUnk_3fe];
        p->mUnk_418 = 0x1000;
        p->mUnk_414 = p->mUnk_418;
    } else if (p->mUnk_3fc == 2) {
        p->mUnk_404 = 0x1000;
        p->mUnk_408 = data_02154c20[p->mUnk_3fe];
        p->mUnk_414 = data_02154cd4[p->mUnk_3fe];
        p->mUnk_418 = data_02154d10[p->mUnk_3fe];
    }
}

void func_02071568(Unk0206bcb0 *p) {
    s32 f;
    u16 i;
    u16 j;
    s32 v;
    s32 s;
    s32 t;

    p->mUnk_4ec = p->mUnk_4ec + p->mUnk_4e8;
    t = p->mUnk_4ec - 0x8000;
    if (t >= 0) {
        p->mUnk_4ec = t;
    }
    f = p->mUnk_4ec & 0xfff;
    i = (u16) (p->mUnk_4ec >> 12);
    j = i + 1;
    if (j >= 8) {
        j = 0;
    }
    p->mUnk_4f0.x = data_02154b64[i] + (s32) (((s64) ((data_02154b64[j] - data_02154b64[i]) >> 1) * f) >> 12);
    p->mUnk_4f0.y = data_02154b84[i] + (s32) (((s64) ((data_02154b84[j] - data_02154b84[i]) >> 1) * f) >> 12);
    p->mUnk_4f0.z = data_02154ba4[i] + (s32) (((s64) ((data_02154ba4[j] - data_02154ba4[i]) >> 1) * f) >> 12);
    v = p->mUnk_4d4;
    s = (s32) (((s64) v * 0x333) >> 12);
    if (v > 0xf33) {
        t = (s32) (((s64) ((v - 0xf33) * 0x32) * 0x19a) >> 12);
        if (t > 0x19a) {
            t = 0x19a;
        }
        t = t + 0x333;
        s = (s32) (((s64) v * t) >> 12);
    } else if (v > 0xd9a) {
        t = (s32) (((s64) ((v - 0xd9a) * 0x32) * 0x52) >> 12);
        if (t > 0x52) {
            t = 0x52;
        }
        t = t + 0x333;
        s = (s32) (((s64) v * t) >> 12);
    }
    p->mUnk_4f0.x = p->mUnk_4f0.x + (s32) (((s64) p->mUnk_4f0.x * s) >> 12);
    p->mUnk_4f0.y = p->mUnk_4f0.y + (s32) (((s64) p->mUnk_4f0.y * s) >> 12);
    p->mUnk_4f0.z = p->mUnk_4f0.z + (s32) (((s64) p->mUnk_4f0.z * s) >> 12);
}

void func_020713a0(Unk0206bcb0 *p) {
    s32 t;

    if (p->mUnk_4e4 <= 2) {
        p->mUnk_4e0 = p->mUnk_4e2 * 0x3c + p->mUnk_4e0;
        if (p->mUnk_4e0 > 0x17c) {
            p->mUnk_4e0 = 0x17c;
        } else if (p->mUnk_4e0 < -0x17c) {
            p->mUnk_4e0 = -0x17c;
        }
        p->mUnk_4de = p->mUnk_4de + p->mUnk_4e0;
        t = p->mUnk_4de;
        if ((t > 0 ? t : -t) > 0x1770) {
            if ((t > 0 && p->mUnk_4e2 > 0) || (t < 0 && p->mUnk_4e2 < 0)) {
                p->mUnk_4e2 *= -1;
                p->mUnk_4e4 = p->mUnk_4e4 + 1;
            }
        }
        p->mUnk_4d4 = 0x1000;
    } else {
        p->mUnk_4e0 = p->mUnk_4e2 * 0x3c + p->mUnk_4e0;
        if (p->mUnk_4e0 > 0xd2) {
            p->mUnk_4e0 = 0xd2;
        } else if (p->mUnk_4e0 < -0xd2) {
            p->mUnk_4e0 = -0xd2;
        }
        p->mUnk_4de = p->mUnk_4de + p->mUnk_4e0;
        p->mUnk_4d4 = (s32) (((s64) p->mUnk_4d4 * 0xf5c) >> 12);
        t = p->mUnk_4de;
        if ((t > 0 && p->mUnk_4e2 > 0) || (t < 0 && p->mUnk_4e2 < 0)) {
            p->mUnk_4de = 0;
            p->mUnk_4c &= ~0x20000000;
            func_02068a64(p, 0, 1);
            p->mUnk_44 |= 0x1000000;
        }
    }
}

void func_02071318(Unk0206bcb0 *p, s32 a) {
    s32 k;

    k = p->mUnk_180;
    if (k != 0 && k != 6) {
        return;
    }
    if (a == 2) {
        p->mUnk_3fc = 2;
    } else if (p->mUnk_44 & 2) {
        p->mUnk_3fc = 1;
    } else if (p->mUnk_380 > 0xa) {
        p->mUnk_3fc = 1;
    } else {
        p->mUnk_3fc = 0;
    }
    p->mUnk_3fe = 0;
    p->mUnk_400 = 0xf;
    p->mUnk_4c |= 8;
}

void func_020710b0(Unk0206bcb0 *p, s32 b) {
    Unk0212c400 **h;
    Unk0210bf24 *d;

    if (b == 0) {
        p->mUnk_48 |= 0x40000;
        p->mUnk_44 &= ~0x10;
    }
    p->mUnk_48 &= 0xdfe77fdf;
    p->mUnk_238 = 0;
    p->mUnk_538.mUnk_00 = 0;
    p->mUnk_23c = 0;
    if (p->mUnk_7c & 1) {
        if (!(p->mUnk_4c & 0x10000000) && !(p->mUnk_48 & 0x4000000)) {
            func_02074854();
        }
        func_02055c5c();
    }
    if (p->mUnk_4c & 0x2000) {
        p->mUnk_4c &= ~0x2000;
        p->mUnk_d8 = 0x1000;
        if (!(p->mUnk_4c & 0x8000000)) {
            func_0207b0d0(p);
        }
        func_02080ee4(p);
    }
    func_02080fb8(p);
    p->mUnk_44 &= 0xfffff7f4;
    p->mUnk_2c4 = 0;
    p->mUnk_2fc = 0;
    p->mUnk_302 = 0;
    p->mUnk_300 = p->mUnk_302;
    p->mUnk_30c = 0;
    func_0208c534(func_0208c5b8(p->mUnk_74));
    p->mUnk_180 = 0;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    func_02072600(p);
    func_02070f8c(p);
    if (!(p->mUnk_7c & 1)) {
        return;
    }
    func_02073f90();
    switch (data_021759c0->mUnk_00) {
        case 0x13:
            func_02089d14(0);
            d = func_021090c4((Unk0210bfbc *) p, 0x15c, 0x7f, 0);
            if (d != 0) {
                d->mUnk_19 |= 0x10;
            }
            h = func_02108e6c(7);
            if (!(data_0217c780 & 1)) {
                return;
            }
            if (data_0217d084.mUnk_0c == 0) {
                return;
            }
            if (h[0] != 0) {
                func_0212c6f0(h, 0);
            }
            if (h[0] != 0) {
                func_0212c6f0(h, 0);
            }
            func_0212ecc0(h, 0, 0x1d2);
            break;
        case 0x21:
            d = func_021090c4((Unk0210bfbc *) p, 0x15b, 0x7f, 0);
            if (d != 0) {
                d->mUnk_19 |= 0x10;
            }
            break;
    }
}

void func_02070f8c(Unk0206bcb0 *p) {
    s32 q[2];
    Vec3 v;
    Vec3 u;
    Unk02061808 *r;
    Vec3 *c;
    s32 v1;
    s32 n;
    s32 i;
    s32 *v2;
    s32 *w;

    v = data_0216553c;
    v1 = 1;
    r = func_02061808();
    c = &r->mUnk_024;
    if (c->x > -0x64f000) {
        if (c->x < -0x3cb000) {
            if (c->z > -0x1ad7000) {
                if (c->z < -0x164d000) {
                    v1 = 0;
                }
            }
        }
    }
    if (v1 != 0) {
        u = data_02165548;
        w = q;
        q[0] = data_02165510[0];
        q[1] = data_02165510[1];
        n = 3;
        v2 = (s32 *) &u;
        if (!(p->mUnk_7c & 1)) {
            n = 2;
            v2 = w;
        }
        for (i = 0; i < n; i++) {
            func_0208b7bc(*v2, &v);
            v2++;
        }
    } else {
        func_0208b7bc((p->mUnk_7c & 1) ? 0x47 : 0x52, &v);
    }
}
