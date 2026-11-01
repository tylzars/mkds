#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50b4.h"
#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020df890.h"

void func_020d47e0(void) {
    u32 f;
    s32 i;
    s32 n;
    Unk020e71a0 *e;
    Unk020e71a0 **t;
    u32 g;
    u16 a;
    u32 b;

    n = data_0217b4f0->mUnk_004;
    t = data_0217b4f0->mUnk_000;
    f = func_0207a780();
    g = func_02061fb8() & 3;
    i = 0;
    if (n <= 0) {
        return;
    }
    a = data_021568ec;
    b = data_021568f0;
    do {
        e = t[i];
        e->mUnk_78 &= ~8;
        if (!(e->mUnk_02 & 2)) {
            if (e->mUnk_78 & 1) {
                if (e->mUnk_66 != 0) {
                    e->mUnk_66 -= 1;
                }
            } else {
                if (e->mUnk_66 < 0x1f) {
                    e->mUnk_66 += 1;
                }
            }
            if ((i & 3) == g) {
                if (e->mUnk_74 & f) {
                    e->mUnk_78 = (e->mUnk_78 & 0x10) | 0x5f592e7;
                    e->mUnk_02 |= a;
                } else {
                    if (e->mUnk_7c != 0) {
                        e->mUnk_78 = (e->mUnk_78 & 0x10) |
                                     func_01ffd648(&e->mUnk_04, e->mUnk_68, e->mUnk_6c, e->mUnk_70, e->mUnk_66);
                    } else {
                        e->mUnk_78 = (e->mUnk_78 & 0x10) |
                                     func_01ffd778(&e->mUnk_04, e->mUnk_68, e->mUnk_6c, e->mUnk_70, e->mUnk_66);
                    }
                    e->mUnk_78 |= b;
                    if (e->mUnk_78 & 2) {
                        e->mUnk_02 |= a;
                    } else {
                        e->mUnk_02 &= ~0x10;
                    }
                }
            }
        }
    } while (++i < n);
}

void func_020d4698(void) {
    u32 f;
    s32 i;
    s32 n;
    Unk020e71a0 *e;
    Unk020e71a0 **t;
    u16 a;
    u32 b;

    f = func_0207a780();
    i = 0;
    n = data_0217b4f0->mUnk_004;
    t = data_0217b4f0->mUnk_000;
    if (n <= 0) {
        return;
    }
    a = data_021568ec;
    b = data_021568f0;
    do {
        e = t[i];
        e->mUnk_78 &= ~8;
        if (!(e->mUnk_02 & 2)) {
            if (e->mUnk_74 & f) {
                e->mUnk_02 |= a;
            } else {
                if (e->mUnk_7c != 0) {
                    e->mUnk_78 = (e->mUnk_78 & 0x10) |
                                 func_01ffd648(&e->mUnk_04, e->mUnk_68, e->mUnk_6c, e->mUnk_70, e->mUnk_66);
                } else {
                    e->mUnk_78 = (e->mUnk_78 & 0x10) |
                                 func_01ffd778(&e->mUnk_04, e->mUnk_68, e->mUnk_6c, e->mUnk_70, e->mUnk_66);
                }
                e->mUnk_78 |= b;
                if (e->mUnk_78 & 1) {
                    e->mUnk_66 = 0;
                } else {
                    e->mUnk_66 = 0x1f;
                }
                if (e->mUnk_78 & 2) {
                    e->mUnk_02 |= a;
                } else {
                    e->mUnk_02 &= ~0x10;
                }
            }
        }
    } while (++i < n);
}

void func_020d4590(void) {
    Unk020e6fd4 *e;
    s32 i;
    s32 n;
    Unk020e6fd4 **t;
    s32 r;

    t = data_0217b4f0->mUnk_134;
    n = data_0217b4f0->mUnk_174;
    r = func_020b33f4();
    if (r <= 0x168) {
        if (data_021759c0->mUnk_00c != 3) {
            if (r == -0x73) {
                func_020d3b74();
            } else if (r == 0x168) {
                func_020d3b10();
            }
        }
    }
    if (data_0217b4f0->mUnk_2b8 != 0) {
        for (i = 0; i < n; i++) {
            e = t[i];
            if (e->mUnk_0c != 0) {
                e->mUnk_0c(e);
            }
            func_020e705c(e);
            if (e->mUnk_14 != 0) {
                e->mUnk_14(e);
            }
        }
    }
    if (func_020d50b4() != 0) {
        func_020d4698();
    } else {
        func_020d47e0();
    }
    if (data_0217b4e4 != 0) {
        func_020d9f8c(data_0217b4e4);
    }
}

void func_020d4484(Unk020d4418 *p) {
    s32 i;
    s32 n;
    Unk020e6fd4 **t;
    Unk020e6fd4 *e;
    Unk02012f58 *v;
    s32 k;
    s32 j;

    v = &p->mUnk_30;
    func_020d4d44(v);
    if (data_0217b4e4 != 0) {
        func_020d9e60(data_0217b4e4, v);
    }
    i = 0;
    n = data_0217b4f0->mUnk_12a;
    t = data_0217b4f0->mUnk_068;
    for (; i < n; i++) {
        e = t[i];
        func_0208ab00();
        if (e->mUnk_0c != 0) {
            e->mUnk_0c(e);
        }
        func_020d4c28(e, v);
        if (e->mUnk_14 != 0) {
            e->mUnk_14(e);
        }
    }
    func_020e6a74();
    j = 0;
    k = data_0217b4f0->mUnk_12c;
    t = data_0217b4f0->mUnk_0c8;
    for (; j < k; j++) {
        e = t[j];
        if (e->mUnk_0c != 0) {
            e->mUnk_0c(e);
        }
        func_020d4c28(e, v);
        if (e->mUnk_14 != 0) {
            e->mUnk_14(e);
        }
    }
}

void func_020d4418(Unk020d4418 *p) {
    Unk02012f58 *v;

    v = &p->mUnk_30;
    if (data_0217b4f0->mUnk_17c != 0) {
        func_020dff88(v);
    }
    if (data_0217b4f0->mUnk_180 != 0) {
        func_020e435c(v);
    }
    if (data_0217b4f0->mUnk_184 != 0) {
        func_020e3b28(v);
    }
}

s32 func_020d41e0(Unk0206bcb0 *a, Vec3 *b, Vec3 *c) {
    Vec3 v;
    Vec3 lo;
    Vec3 hi;
    s32 q;
    s32 k;
    s32 r;
    s32 i;
    Unk020e71a0 *e;
    s32 n;
    Vec3 *p;

    v = *b;
    k = (a->mUnk_48 & 0x8000000) != 0;
    q = a->mUnk_1d0;
    r = a->mUnk_29c;
    p = data_0217b4dc;
    {
        Vec3 z1 = {0, 0, 0};
        lo = z1;
    }
    {
        Vec3 z2 = {0, 0, 0};
        hi = z2;
    }
    n = 0;
    c->x = c->y = c->z = 0;
    for (i = 0; i < data_0217b5a8; i++) {
        if (data_0217b5bc[i] & 0x2000) {
            e = data_0217b5c4[i];
            if (k != 0 && !(e->mUnk_78 & 0x10)) {
                continue;
            }
            if (func_020d3e34(&v, q, e, p) != 0) {
                if (!(e->mUnk_02 & 0x40) && func_020d69e4(r, e) != 0) {
                    lo.x = (p->x < lo.x) ? p->x : lo.x;
                    lo.y = (p->y < lo.y) ? p->y : lo.y;
                    lo.z = (p->z < lo.z) ? p->z : lo.z;
                    hi.x = (p->x > hi.x) ? p->x : hi.x;
                    hi.y = (p->y > hi.y) ? p->y : hi.y;
                    hi.z = (p->z > hi.z) ? p->z : hi.z;
                }
                data_0217b4e8[n] = e;
                n++;
                p = &data_0217b4dc[n];
                if (n >= 0x20) {
                    n = 0x1f;
                }
            }
        }
    }
    if (n != 0 && c != 0) {
        c->x = hi.x + lo.x;
        c->y = hi.y + lo.y;
        if (c->y < 0) {
            c->y = 0;
        }
        c->z = hi.z + lo.z;
    }
    return n;
}

s32 func_020d4130(Vec3 *a, s32 b, s32 c) {
    s32 n;
    Unk020e71a0 *e;
    s32 d;
    s32 f;
    s32 i;

    n = 0;
    func_020d5180(a, b, 0x2000);
    for (i = 0; i < data_0217b5a8; i++) {
        e = data_0217b5c4[i];
        if (e->mUnk_00 == c) {
            f = a->x - e->mUnk_04.x;
            d = a->z - e->mUnk_04.z;
            if ((s64) f * f + (s64) d * d < (s64) b * b) {
                data_0217b4e8[n] = e;
                n++;
            }
        }
    }
    return n;
}
