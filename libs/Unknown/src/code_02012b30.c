#include "code_02012b30.h"
#include "code_02010804.h"
#include "code_02010c84.h"
#include "code_0200fe7c.h"
#include "code_020108bc.h"
#include "code_0214a748.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "code_020107e4.h"
#include "code_02010878.h"
#include "code_02010998.h"
#include "code_020109ac.h"
#include "code_02013730.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_02161000.h"
#include "registers.h"

void *func_020136f0(Unk020136f0 *a) {
    u8 *p;

    p = (u8 *) a + a->mUnk_0c;
    if (a->mUnk_0e == 1) {
        if (a->mUnk_00 == 0x30585442) {
            return (u8 *) a + *(u32 *) p;
        }
        return 0;
    }
    return (u8 *) a + *(u32 *) (p + 4);
}

void func_020136a8(Unk0201290c *a, u32 b, u32 c) {
    u8 *p;
    u8 *t;
    u8 *e;

    p = (u8 *) a + a->mUnk_08;
    t = p + 4 + *(u16 *) (p + 0xa);
    e = p + *(u32 *) (t + *(u16 *) t * b + 4);
    *(u32 *) (e + 4) = (*(u32 *) (e + 4) & -0x8000) | c;
}

void func_02013660(Unk0201290c *a, u32 b, u32 c) {
    u8 *p;
    u8 *t;
    u8 *e;

    p = (u8 *) a + a->mUnk_08;
    t = p + 4 + *(u16 *) (p + 0xa);
    e = p + *(u32 *) (t + *(u16 *) t * b + 4);
    *(u32 *) (e + 4) = (*(u32 *) (e + 4) & 0x8000ffff) | (c << 16);
}

void func_02013618(Unk0201290c *a, u32 b, u32 c) {
    u8 *p;
    u8 *t;
    u8 *e;

    p = (u8 *) a + a->mUnk_08;
    t = p + 4 + *(u16 *) (p + 0xa);
    e = p + *(u32 *) (t + *(u16 *) t * b + 4);
    *(u32 *) (e + 8) = (*(u32 *) (e + 8) & -0x8000) | c;
}

void func_020135d0(Unk0201290c *a, u32 b, u32 c) {
    u8 *p;
    u8 *t;
    u8 *e;

    p = (u8 *) a + a->mUnk_08;
    t = p + 4 + *(u16 *) (p + 0xa);
    e = p + *(u32 *) (t + *(u16 *) t * b + 4);
    *(u32 *) (e + 8) = (*(u32 *) (e + 8) & 0x8000ffff) | (c << 16);
}

void func_02013588(Unk0201290c *a, u32 b, u32 c) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    e->mUnk_0c = (e->mUnk_0c & ~0xf) | (c);
}

void func_02013540(Unk0201290c *a, u32 b, u32 c) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    e->mUnk_0c = (e->mUnk_0c & ~0x30) | (c << 4);
}

void func_020134f8(Unk0201290c *a, u32 b, u32 c) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    e->mUnk_0c = (e->mUnk_0c & ~0xc0) | (c << 6);
}

void func_020134b0(Unk0201290c *a, u32 b, u32 c) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    e->mUnk_0c = (e->mUnk_0c & ~0x3f000000) | (c << 24);
}

void func_02013468(Unk0201290c *a, u32 b, u32 c) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    e->mUnk_0c = (e->mUnk_0c & ~0x1f0000) | (c << 16);
}

void func_02013424(Unk0201290c *a, u32 b, s32 c) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    if (c != 0) {
        e->mUnk_0c |= 0x8000;
    } else {
        e->mUnk_0c &= ~0x8000;
    }
}

void func_020133e0(Unk0201290c *a, u32 b, s32 c) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    if (c != 0) {
        e->mUnk_0c |= 0x800;
    } else {
        e->mUnk_0c &= ~0x800;
    }
}

u32 func_020133ac(Unk0201290c *a, u32 b) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    return (e->mUnk_0c & 0xc0) >> 6;
}

u32 func_02013378(Unk0201290c *a, u32 b) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    return (e->mUnk_0c & 0x3f000000) >> 24;
}

u32 func_02013344(Unk0201290c *a, u32 b) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    return (e->mUnk_0c & 0x1f0000) >> 16;
}

u32 func_02013314(Unk0201290c *a, u32 b) {
    u8 *q;
    u16 *t;
    Unk0201290c_08 *e;

    q = (u8 *) a + a->mUnk_08;
    t = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
    e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) t + *t * b + 4));
    return e->mUnk_0c & 0x8000;
}

void func_020132cc(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_020136a8(a, i, b);
    }
}

void func_02013284(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_02013660(a, i, b);
    }
}

void func_0201323c(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_02013618(a, i, b);
    }
}

void func_020131f4(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_020135d0(a, i, b);
    }
}

void func_020131ac(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_02013588(a, i, b);
    }
}

void func_02013164(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_02013540(a, i, b);
    }
}

void func_0201311c(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_020134f8(a, i, b);
    }
}

void func_020130d4(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_020134b0(a, i, b);
    }
}

void func_0201308c(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_02013468(a, i, b);
    }
}

void func_02013044(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_02013424(a, i, b);
    }
}

void func_02012ffc(Unk0201290c *a, u32 b) {
    u32 i;

    for (i = 0; i < a->mUnk_18; i++) {
        func_020133e0(a, i, b);
    }
}

void func_02012f58(Unk02012f58 *a, void *b) {
    s32 m[16];

    func_01ff9234();
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_PUSH = 0;
    reg_G3_MTX_IDENTITY = 0;
    if (a != 0) {
        while (func_0214a7a4(m) != 0) {
        }
        func_02147980(m, a);
    }
    if (b != 0) {
        while (func_0214a75c(b) != 0) {
        }
    }
    reg_G3_MTX_POP = 1;
    reg_G3_MTX_MODE = 2;
}

void func_02012f24(void) {
    func_0214aa58();
    func_02011074();
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xc0000000) | 0x80000000;
}

s32 func_02012cbc(Unk020136f0 *a) {
    s32 f0;
    u32 r;
    u32 v0;
    u32 v1;
    u32 v2;
    s32 f1;
    s32 f2;

    switch (a->mUnk_00) {
        case 0x30444d42:
        case 0x30585442:
            f0 = 1;
            f1 = 1;
            f2 = 1;
            r = (u32) func_020136f0(a);
            if (r != 0) {
                v0 = func_020109b8(r);
                v1 = func_020109ac(r);
                v2 = func_02010878(r);
                if (v0 != 0) {
                    v0 = data_021619ec(v0, 0, 0);
                    if (v0 == 0) {
                        f0 = 0;
                    }
                } else {
                    v0 = 0;
                }
                if (v1 != 0) {
                    v1 = data_021619ec(v1, 1, 0);
                    if (v1 == 0) {
                        f1 = 0;
                    }
                } else {
                    v1 = 0;
                }
                if (v2 != 0) {
                    v2 = data_021619f4(v2, *(u16 *) (r + 0x20) & 0x8000, 0);
                    if (v2 == 0) {
                        f2 = 0;
                    }
                } else {
                    v2 = 0;
                }
                if (f0 == 0 || f1 == 0 || f2 == 0) {
                    data_021619f8((void *) v2);
                    data_021619f0((void *) v1);
                    data_021619f0((void *) v0);
                    return 0;
                }
                func_02010998(r, v0, v1);
                func_02010870((Unk02010804 *) r, v2);
                func_020108bc((Unk020108bc *) r, 1);
                func_02010804((Unk02010804 *) r, 1);
            }
            if (a->mUnk_00 == 0x30444d42) {
                v0 = func_02013730((u32) a);
                if (r != 0) {
                    func_02010168((Unk02010168 *) v0, (Unk02010294 *) r);
                }
            }
            return 1;
        case 0x30415642:
        case 0x30414d42:
        case 0x30414342:
        case 0x30415442:
        case 0x30505442:
            return 1;
        default:
            return 0;
    }
}

void func_02012b30(Unk020136f0 *a) {
    u32 p;
    u32 q;
    void *x;
    void *y;

    switch (a->mUnk_00) {
        case 0x30415642:
        case 0x30414d42:
        case 0x30414342:
        case 0x30415442:
        case 0x30505442:
            return;
        case 0x30444d42:
            q = func_02013730((u32) a);
            if (func_020136f0(a) != 0) {
                func_020100fc((Unk02010168 *) q);
            }
            break;
        case 0x30585442:
            break;
        default:
            return;
    }
    p = (u32) func_020136f0(a);
    if (p == 0) {
        return;
    }
    q = func_020107e4(p);
    func_02010884(p, (u32) &x, (u32) &y);
    if (q != 0) {
        data_021619f8((void *) q);
    }
    if (y != 0) {
        data_021619f0(y);
    }
    if (x != 0) {
        data_021619f0(x);
    }
}
