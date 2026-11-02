#include "Main/Unknown/code_020d3ae0.h"

#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d3c7c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020d2c2c.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020d3d94.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d4104.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50b4.h"
#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d4990.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020d49e0.h"
#include "Main/Unknown/code_020d4a10.h"
#include "Main/Unknown/code_020d4a18.h"
#include "Main/Unknown/code_020d4a20.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d4bf0.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/code_020d50e0.h"

Unk0217b4f8 *func_020d50e0(void) {
    return &data_0217b4f8;
}

void func_020d50c4(void) {
    data_0217b4f8.mUnk_50 = 1;
    data_0217b4f8.mUnk_54 = 0;
}

u32 func_020d50b4(void) {
    u32 value0;
    value0 = (u32) &data_0217b4f8;
    value0 = (u32) * (const u32 *) ((value0) + (84));
    return value0;
}

void func_020d4f94(Unk020d4f94 *p) {
    s32 buf[10];

    func_02146d0c(p, buf);
    func_02146d78(&p->mUnk_24, buf, &data_0217b4f8.mUnk_08);
    data_0217b4f8.mUnk_08.x = -data_0217b4f8.mUnk_08.x;
    data_0217b4f8.mUnk_08.y = -data_0217b4f8.mUnk_08.y;
    data_0217b4f8.mUnk_08.z = -data_0217b4f8.mUnk_08.z;
    data_0217b4f8.mUnk_08.x = data_0217b4f8.mUnk_08.x << 4;
    data_0217b4f8.mUnk_08.y = data_0217b4f8.mUnk_08.y << 4;
    data_0217b4f8.mUnk_08.z = data_0217b4f8.mUnk_08.z << 4;
    data_0217b4f8.mUnk_14.x = -buf[6];
    data_0217b4f8.mUnk_14.y = -buf[7];
    data_0217b4f8.mUnk_14.z = -buf[8];
    func_02146d78(&data_0217b550.mUnk_20, buf, &data_0217b4f8.mUnk_20);
    func_02146d78(&data_0217b550.mUnk_2c, buf, &data_0217b4f8.mUnk_2c);
    func_02146d78(&data_0217b550.mUnk_38, buf, &data_0217b4f8.mUnk_38);
    func_02146d78(&data_0217b550.mUnk_44, buf, &data_0217b4f8.mUnk_44);
    if (data_0217b4f8.mUnk_50 != 0) {
        data_0217b4f8.mUnk_50 = 0;
        data_0217b4f8.mUnk_54 = 1;
    } else {
        data_0217b4f8.mUnk_54 = 0;
    }
}

u32 func_020d4f34(Vec3 *a, s32 b, s32 c, s32 d) {
    s32 x;
    s32 z;
    s32 v;
    u32 r;

    x = (a->x - data_0217b4f8.mUnk_08.x) >> 12;
    z = (a->z - data_0217b4f8.mUnk_08.z) >> 12;
    v = x * x + z * z;
    r = v & ~0xc000001f;
    if (v > d) {
        r |= data_021568f4;
    }
    return r | 3;
}

s32 func_020d4ef4(Vec3 *p) {
    s32 x;
    s32 z;

    if (p == 0) {
        return 0;
    }
    x = (p->x - data_0217b4f8.mUnk_08.x) >> 12;
    z = (p->z - data_0217b4f8.mUnk_08.z) >> 12;
    return x * x + z * z;
}

void func_020d4e28(Unk020f41c4_A *p, Vec3 *v, u32 a) {
    s32 d;

    if (a & 4) {
        if (p->mUnk_00.mUnk_34 & 1) {
            func_0210cfbc(&p->mUnk_00, 2, 1);
        }
        return;
    }
    d = data_0217b4f8.mUnk_08.y - v->y;
    if (d > -0x12c000 && d < data_0217b4f4) {
        if (!(p->mUnk_00.mUnk_34 & 1)) {
            func_0210cfbc(&p->mUnk_00, 2, 1);
        }
    } else {
        if (p->mUnk_00.mUnk_34 & 1) {
            func_0210cfbc(&p->mUnk_00, 2, 1);
        }
    }
}

s32 func_020d4ddc(Unk020e71a0 *p) {
    s32 d;

    if (p->mUnk_78 & 4) {
        return 1;
    }
    d = data_0217b4f8.mUnk_08.y - p->mUnk_04.y;
    if (p->mUnk_98->mUnk_3c < d && d < p->mUnk_98->mUnk_38) {
        return 0;
    }
    return 1;
}

s32 func_020d4d60(Unk020e71a0 *p, s32 a) {
    s32 h;
    Vec3 *v;
    Unk020e71a0_98 *q;

    v = &p->mUnk_04;
    if (a > p->mUnk_70) {
        return 1;
    }
    q = p->mUnk_98;
    h = (v->y - data_0217b4f8.mUnk_08.y) >> 12;
    if (h < q->mUnk_3c || q->mUnk_38 < h) {
        return 1;
    }
    return (func_0207a780() & p->mUnk_74) != 0;
}

void func_020d4d44(Unk02012f58 *p) {
    func_020e6df0(p);
    func_020d7bec(p);
}

void func_020d4c28(Unk020e6fd4 *p, void *a) {
    s32 i;
    Unk020e71a0 *e;
    UnkFunc *f;
    s32 n;
    void **t;
    Unk020e71a0 *b;
    s32 m;

    f = p->mUnk_10;
    n = p->mUnk_04;
    t = p->mUnk_24;
    if (f == 0) {
        return;
    }
    if (p->mUnk_1c != 0) {
        b = 0;
        for (i = 0; i < n; i++) {
            e = t[i];
            if (!(e->mUnk_02 & 0x12) && e->mUnk_66 != 0) {
                f(p, e, a, e->mUnk_66);
                if (b != 0 && (s32) (e->mUnk_78 & ~0xc000001f) > (s32) (b->mUnk_78 & ~0xc000001f)) {
                    t[m] = e;
                    t[i] = b;
                } else {
                    b = e;
                }
                m = i;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            e = t[i];
            if (!(e->mUnk_02 & 0x12) && e->mUnk_66 != 0) {
                f(p, e, a, e->mUnk_66);
            }
        }
    }
}

#pragma thumb on

void func_020d4bf0(void) {
    data_0217b4f8.mUnk_50 = 1;
    data_0217b4f8.mUnk_54 = 0;
    if ((int) data_021759c0->mUnk_00c == 2) {
        *(u32 *) &data_0217b4f4 = ((u32) 0x00258000u);
        return;
    }
    *(u32 *) &data_0217b4f4 = ((u32) 0x0012c000u);
}

#pragma thumb off

#pragma thumb on
void func_020d4a20(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    data_0217b550.mUnk_00 = e << 4;
    data_0217b4f8.mUnk_00 = e << 4;
    data_0217b550.mUnk_04 = f << 4;
    data_0217b4f8.mUnk_04 = f << 4;

    data_0217b550.mUnk_20.x = e;
    data_0217b550.mUnk_20.y = 0;
    data_0217b550.mUnk_20.z = -c;
    if ((s64) data_0217b550.mUnk_20.z * data_0217b550.mUnk_20.z +
            ((s64) data_0217b550.mUnk_20.x * data_0217b550.mUnk_20.x +
             (s64) data_0217b550.mUnk_20.y * data_0217b550.mUnk_20.y) >=
        0x10) {
        func_02039860(&data_0217b550.mUnk_20, &data_0217b550.mUnk_20);
    }
    if (data_021759c0->mUnk_57 != 0) {
        data_0217b550.mUnk_20.x = -data_0217b550.mUnk_20.x;
        data_0217b550.mUnk_20.y = -data_0217b550.mUnk_20.y;
        data_0217b550.mUnk_20.z = -data_0217b550.mUnk_20.z;
    }

    data_0217b550.mUnk_2c.x = -e;
    data_0217b550.mUnk_2c.y = 0;
    data_0217b550.mUnk_2c.z = d;
    if ((s64) data_0217b550.mUnk_2c.z * data_0217b550.mUnk_2c.z +
            ((s64) data_0217b550.mUnk_2c.x * data_0217b550.mUnk_2c.x +
             (s64) data_0217b550.mUnk_2c.y * data_0217b550.mUnk_2c.y) >=
        0x10) {
        func_02039860(&data_0217b550.mUnk_2c, &data_0217b550.mUnk_2c);
    }
    if (data_021759c0->mUnk_57 != 0) {
        data_0217b550.mUnk_2c.x = -data_0217b550.mUnk_2c.x;
        data_0217b550.mUnk_2c.y = -data_0217b550.mUnk_2c.y;
        data_0217b550.mUnk_2c.z = -data_0217b550.mUnk_2c.z;
    }

    data_0217b550.mUnk_38.x = 0;
    data_0217b550.mUnk_38.y = -e;
    data_0217b550.mUnk_38.z = a;
    if ((s64) data_0217b550.mUnk_38.z * data_0217b550.mUnk_38.z +
            ((s64) data_0217b550.mUnk_38.x * data_0217b550.mUnk_38.x +
             (s64) data_0217b550.mUnk_38.y * data_0217b550.mUnk_38.y) >=
        0x10) {
        func_02039860(&data_0217b550.mUnk_38, &data_0217b550.mUnk_38);
    }

    data_0217b550.mUnk_44.x = 0;
    data_0217b550.mUnk_44.y = e;
    data_0217b550.mUnk_44.z = -b;
    if ((s64) data_0217b550.mUnk_44.z * data_0217b550.mUnk_44.z +
            ((s64) data_0217b550.mUnk_44.x * data_0217b550.mUnk_44.x +
             (s64) data_0217b550.mUnk_44.y * data_0217b550.mUnk_44.y) >=
        0x10) {
        func_02039860(&data_0217b550.mUnk_44, &data_0217b550.mUnk_44);
    }
}
#pragma thumb off

#pragma thumb on
void func_020d4a18(Unk020e6fd4 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = 0u;
    *(u32 *) ((value0) + 0u) = value1;
    *(u16 *) ((value0) + 4u) = (u16) value1;
}
#pragma thumb off

#pragma thumb on
void func_020d4a10(Unk020e6fd4 *p, s32 a) {
    p->mUnk_04 += a;
}
#pragma thumb off

#pragma thumb on
u32 func_020d49f0(Unk020e6fd4 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = (u32) func_020364e8();
    value0 = (u32) func_020364e0((void *) value0);
    value1 = (u32) * (const u16 *) ((value4) + 4u);
    value1 = (value1 << 2);
    value0 = (u32) func_02036bec((void *) value0, value1);
    *(u32 *) ((value4) + 0u) = value0;
    value0 = 0u;
    *(u16 *) ((value4) + 4u) = (u16) value0;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020d49e0(Unk020e6fd4 *arg0, Unk020e71a0 *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) * (const u16 *) ((value0) + 4u);
    value2 = (value3) + (1u);
    *(u16 *) ((value0) + 4u) = (u16) value2;
    value2 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (value3 << 2);
    *(u32 *) ((value2) + (value0)) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_020d49d8(void *p0) {
    *(u32 *) ((u8 *) (u32) (((u32) * (const u32 *) ((u8 *) (u32) p0 + 0))) + 40) = (u32) p0;
}

#pragma thumb off

#pragma thumb on
void func_020d4990(Unk020e6fd4 *p) {
    s32 i;

    if (p->mUnk_1c != 0) {
        p->mUnk_24 = func_02036bec(func_020364e0(func_020364e8()), p->mUnk_04 * 4);
        for (i = 0; i < p->mUnk_04; i++) {
            p->mUnk_24[i] = p->mUnk_00[i];
        }
    } else {
        p->mUnk_24 = p->mUnk_00;
    }
}
#pragma thumb off

void func_020d4980(void *p0) {
    data_0217b4e4 = p0;
}

void func_020d4970(void *p0) {
    data_0217b4d8 = p0;
}

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

Unk020e71a0 *func_020d411c(u32 arg0) {
    return data_0217b4e8[arg0];
}

Vec3 *func_020d4104(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b4dc;
    value1 = 0xcu;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (Vec3 *) value0;
}

s32 func_020d3e34(Vec3 *param_1, s32 param_2, Unk020e71a0 *param_3, Vec3 *param_4) {
    s32 t;
    s32 u;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 r;
    s32 n;
    if (param_3->mUnk_02 & 1) {
        return 0;
    }
    switch (param_3->mUnk_98->mUnk_08) {
        case 1:
            t = param_2 + param_3->mUnk_58.x;
            n = -t;
            dz = param_1->z - param_3->mUnk_04.z;
            if (dz > t || dz < n) {
                r = 0;
            } else {
                dx = param_1->x - param_3->mUnk_04.x;
                if (dx > t || dx < n) {
                    r = 0;
                } else {
                    dy = param_1->y - param_3->mUnk_04.y;
                    if (dy > t || dy < n) {
                        r = 0;
                    } else {
                        r = (s64) dx * dx + (s64) dy * dy + (s64) dz * dz < (s64) t * t;
                    }
                }
            }
            if (r == 0) {
                return 0;
            }
            func_020eb3f0(param_1, &param_3->mUnk_04, t, param_4);
            return 1;
        case 2:
            t = param_2 + param_3->mUnk_58.x;
            u = param_2 + param_3->mUnk_58.y;
            n = -t;
            dz = param_1->z - param_3->mUnk_04.z;
            if (dz > t || dz < n) {
                r = 0;
            } else {
                dx = param_1->x - param_3->mUnk_04.x;
                if (dx > t || dx < n) {
                    r = 0;
                } else {
                    dy = param_1->y - param_3->mUnk_04.y;
                    if (dy > u || dy < -u) {
                        r = 0;
                    } else {
                        r = (s64) dx * dx + (s64) dz * dz < (s64) t * t;
                    }
                }
            }
            if (r == 0) {
                return 0;
            }
            func_020eb2a0(param_1, &param_3->mUnk_04, t, u, param_4);
            return 1;
        case 3:
            return func_020ead80(param_1, &param_3->mUnk_04, &param_3->mUnk_28.mUnk_00, param_3->mUnk_58.x,
                                 param_3->mUnk_58.y, param_3->mUnk_58.y, param_2, param_4) != 0;
        case 4:
            return func_020eafc4(param_1, &param_3->mUnk_04, &param_3->mUnk_28.mUnk_00, &param_3->mUnk_58,
                                 &param_3->mUnk_58, param_2, param_4) != 0;
        case 0:
            return 0;
        case 5:
            if (param_3->mUnk_98->mUnk_18 != 0) {
                return param_3->mUnk_98->mUnk_18(param_3, param_1, param_2, param_4) != 0;
            }
            return 0;
        default:
            return 0;
    }
}

s32 func_020d3e18(void) {
    return data_0217b4e4 != 0;
}

s32 func_020d3df4(s32 param_1) {
    return data_0217b4e4 != 0 ? param_1 - data_0217b4e4->mUnk_04 : 0x270f000;
}

s32 func_020d3dd8(void) {
    return data_0217b4e4 != 0 ? data_0217b4e4->mUnk_30 : 0;
}

u32 func_020d3dbc(void) {
    return data_0217b4e4 != 0 ? data_0217b4e4->mUnk_2c : 0;
}

u32 func_020d3d94(void) {
    u32 value0;
    u32 value1;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    value1 = (u32) &data_0217b4e4;
    value0 = 0u;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    compareLeft0 = value1;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
        return value0;
    }
    value1 = (u32) * (const u32 *) ((value1) + (368));
    compareLeft1 = value1;
    compareRight1 = 0u;
    if (compareLeft1 != compareRight1) {
        value0 = 1u;
    }
    return value0;
}

s32 func_020d3d48(s32 param_1) {
    if (data_0217b4e4 != 0 && data_0217b4e4->mUnk_170 != 0) {
        return param_1 - data_0217b4e4->mUnk_04;
    }
    return data_0217b4d8 != 0 ? param_1 - data_0217b4d8->mUnk_00 : 0x270f000;
}

s32 func_020d3d10(s32 param_1) {
    s32 a;
    a = 0;
    if (data_0217b4d8 != 0) {
        if (param_1 - data_0217b4d8->mUnk_00 < -0x32000) {
            a = 1;
        }
    }
    return a;
}

void func_020d3cc8(void) {
    s32 i;
    s32 n;
    Unk0217b4f0 *q;
    Unk020e6fd4 **p;
    i = 0;
    q = data_0217b4f0;
    n = q->mUnk_174;
    p = q->mUnk_134;
    for (; i < n; i++) {
        func_020e6fd4(p[i]);
    }
}

s32 func_020d3c94(Unk020e71a0 *param_1, s32 param_2, Vec3 *param_3) {
    return func_020d2c2c(&param_1->mUnk_04, &param_1->mUnk_10, param_1->mUnk_58.x, param_1->mUnk_64, param_2, param_3);
}

u32 func_020d3c7c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b4f0;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (696)) = value1;
    return value0;
}

u16 func_020d3c44(void) {
    data_0217b4c4++;
    if (data_0217b4c4 > 0x3e) {
        data_0217b4c4 = data_0217b4c8;
    }
    return data_0217b4c4;
}

u16 func_020d3c2c(void) {
    return data_0217b4d0++;
}

#pragma thumb on

u16 func_020d3bf8(u32 param_1) {
    s32 i;
    u16 a;
    a = 0;
    i = 0;
    for (; i < data_0217b4f0->mUnk_004; i++) {
        if (param_1 == data_0217b4f0->mUnk_000[i]->mUnk_00) {
            a++;
        }
    }
    return a;
}

void func_020d3b74(void) {
    s32 i;
    s32 n;
    Unk020e71a0 **p;
    Unk020e71a0 *q;
    n = data_0217b4f0->mUnk_004;
    p = data_0217b4f0->mUnk_000;
    for (i = 0; i < n; i++) {
        q = *p;
        if (q->mUnk_02 & 0x80) {
            if (q->mUnk_02 & 0x100) {
                q->mUnk_02 &= ~0x80;
            } else {
                q->mUnk_02 &= ~0xf000;
                q->mUnk_02 |= (q->mUnk_02 & 0xf) << 12;
                q->mUnk_02 |= data_021568dc;
                if (q->mUnk_64 != -1) {
                    func_020d5114(q->mUnk_64);
                }
            }
        }
        p++;
    }
}

void func_020d3b10(void) {
    s32 i;
    s32 n;
    Unk020e71a0 **p;
    Unk020e71a0 *q;
    n = data_0217b4f0->mUnk_004;
    p = data_0217b4f0->mUnk_000;
    for (i = 0; i < n; i++) {
        q = *p;
        if (q->mUnk_02 & 0x80) {
            q->mUnk_02 &= ~0x80;
            q->mUnk_02 &= ~0xf;
            q->mUnk_02 |= (q->mUnk_02 & 0xf000) >> 12;
            if (q->mUnk_64 != -1) {
                func_020d50ec(q->mUnk_64);
            }
        }
        p++;
    }
}

#pragma thumb off

#pragma thumb on

void func_020d3ae0(s32 param_1, Unk020e71a0 *param_2) {
    int v1;
    u32 v2;
    v1 = 0x2710;
    if (0x2710 <= param_1) {
        param_2->mUnk_02 = param_2->mUnk_02 | (*(u16 *) &data_021568e8);
        param_1 = (param_1 - v1) * 0x10000 >> 0x10;
    }
    v2 = func_020d2178((u32) param_1);
    param_2->mUnk_74 = v2;
}

#pragma thumb off
