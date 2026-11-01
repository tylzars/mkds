#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0208b000.h"
#include "code_02013730.h"
#include "Main/Unknown/code_020d2b78.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02012b30.h"
#include "code_02147288.h"
#include "code_0214a4dc.h"
#include "code_020172d0.h"

void func_0208e99c(Unk0208ec64 *a) {
    Unk0208ec64_08 *p;
    Unk0208ec64_08 *q;
    Unk0208ec64_08 *r;
    u32 f;

    p = func_0201733c(&a->mUnk_08, 0);
    if (p != 0) {
        do {
            q = func_0201733c(&a->mUnk_08, p);
            p->mUnk_0c = p->mUnk_0c + 1;
            if (p->mUnk_0c > data_021663e0) {
                f = 1;
            } else {
                p->mUnk_08 = p->mUnk_08 - data_021663f0;
                f = 0;
            }
            if (f != 0) {
                func_02017354(&a->mUnk_08, p);
                func_020174a4(&data_0217b08c->mUnk_18, p);
                if (q == 0) {
                    break;
                }
                p = q;
            }
            p = func_0201733c(&a->mUnk_08, p);
        } while (p != 0);
    }
    if (a->mUnk_18 == 0) {
        r = func_020172d8(&data_0217b08c->mUnk_18, 0);
        func_02017354(&data_0217b08c->mUnk_18, r);
        func_020174a4(&a->mUnk_08, r);
        data_021663ec(r, a);
        return;
    }
    if (a->mUnk_08.mUnk_08 != 0) {
        return;
    }
    func_02017354(&data_0217b08c->mUnk_00, a);
    func_020174a4(&data_0217b08c->mUnk_0c, a);
}

void func_0208e82c(const Unk02012f58 *a, Unk0208ec64_08 *b, Unk0208ec64_08 *c, Unk021663f4 *d) {
    Unk02012f58 m;
    Unk02012f58 n;

    func_02147218(&m, 0x1000, b->mUnk_08, 0x1000);
    func_02147218(&n, 0x1000, c->mUnk_08, 0x1000);
    m.mUnk_24.x = b->mUnk_10.x;
    m.mUnk_24.y = b->mUnk_10.y;
    m.mUnk_24.z = b->mUnk_10.z;
    n.mUnk_24.x = c->mUnk_10.x;
    n.mUnk_24.y = c->mUnk_10.y;
    n.mUnk_24.z = c->mUnk_10.z;
    func_0214733c(&m, a, &m);
    func_0214733c(&n, a, &n);
    *(u32 *) 0x4000500 = 1;
    func_0214a514(&m);
    *(u32 *) 0x4000488 = (u16) ((d->mUnk_1c << 8) >> 16);
    *(u32 *) 0x4000490 = 0x10000;
    *(u32 *) 0x4000488 = 0;
    *(u32 *) 0x4000490 = 0xf0000;
    func_0214a514(&n);
    *(u32 *) 0x4000488 = (u16) ((d->mUnk_20 << 8) >> 16) << 16;
    *(u32 *) 0x4000490 = 0xf0000;
    *(u32 *) 0x4000488 = (u16) ((d->mUnk_1c << 8) >> 16) | (u16) ((d->mUnk_20 << 8) >> 16) << 16;
    *(u32 *) 0x4000490 = 0x10000;
    *(u32 *) 0x4000504 = 0;
}

void func_0208e808(s32 a) {
    if (data_021759c0->mUnk_00c == 5) {
        data_021663e8 = a;
    }
}

void func_0208e570(void *a) {
    u16 i;
    void *c;
    void *d;
    void *e;
    void *f;
    Unk0216618c *x;
    Unk0216618c *y;

    if (data_021759c0->mUnk_08 == 4) {
        a = data_0217aa10->mUnk_a4;
    }
    data_0217b080 = func_02036bec(a, 0x60);
    func_02017538(&data_0217b080->mUnk_00, 0);
    for (i = 0; i < 5; i++) {
        func_02017538(&data_0217b080->mUnk_0c[i], 0);
    }
    x = data_0216618c;
    y = &data_021661b8;
    if (data_021759c0->mUnk_08 == 5) {
        x->mUnk_00 = 6;
        y->mUnk_00 = 4;
    } else {
        x->mUnk_00 = 3;
        y->mUnk_00 = 1;
    }
    if (data_021759c0->mUnk_08 == 4) {
        x->mUnk_00 = 0x14;
    }
    func_0208e2c8(&data_021661e4, 1);
    func_0208e2c8(&data_0216623c, 2);
    func_0208e23c();
    func_0208e098(a);
    c = func_02047b08(data_02166298);
    d = func_02047b08(data_021662b8);
    e = func_02047b08(data_021662d8);
    f = func_02047b08(data_021662f8);
    func_0208ddf4(a, 0, c, d, e, f);
    c = func_02047b08(data_02166318);
    d = func_02047b08(data_0216633c);
    e = func_02047b08(data_02166360);
    f = func_02047b08(data_02166384);
    func_0208ddf4(a, 1, c, d, e, f);
    func_0208ddf4(a, 2, (void *) func_020d2be8(), (void *) func_020d2bb0(), (void *) func_020d2b78(), 0);
    func_0208ddf4(a, 4, (void *) func_020d2be8(), (void *) func_020d2bb0(), (void *) func_020d2b78(), 0);
    if (data_021759c0->mUnk_00 == 0x17) {
        func_0208ddf4(a, 3, (void *) func_020d2be8(), func_02047974(data_021663a8), func_02047974(data_021663c0), 0);
    }
    data_0217b080->mUnk_5c = 10;
}

Unk0208e490 *func_0208e490(u32 a, const Vec3 *b, s32 c) {
    Unk0208e490 *p;

    p = func_020172d8(&data_0217b080->mUnk_0c[a], 0);
    if (p != 0) {
        func_02017354(&data_0217b080->mUnk_0c[a], p);
        p->mUnk_88 = 0;
        p->mUnk_74 = *b;
        p->mUnk_a8 = 0;
        p->mUnk_ac = 0;
        p->mUnk_b0 = data_0217b080->mUnk_5c;
        p->mUnk_b4 = 1;
        p->mUnk_80(p, c);
        func_020174a4(&data_0217b080->mUnk_00, p);
        data_0217b080->mUnk_5c++;
        if (data_0217b080->mUnk_5c > 0xd) {
            data_0217b080->mUnk_5c = 10;
        }
    }
    return p;
}

void func_0208e400(void) {
    Unk0208e490 *p;

    p = func_0201733c(&data_0217b080->mUnk_00, 0);
    if (p == 0) {
        return;
    }
    do {
        p->mUnk_84(p);
        p->mUnk_a8 = p->mUnk_a8 + 1;
        if (p->mUnk_88 == 1) {
            func_02017354(&data_0217b080->mUnk_00, p);
            func_020174a4(&data_0217b080->mUnk_0c[p->mUnk_8c], p);
        }
        p = func_0201733c(&data_0217b080->mUnk_00, p);
    } while (p != 0);
}

void func_0208e358(void) {
    Unk02012f58 m;
    Unk0208e490 *p;

    func_021471bc(&m);
    p = func_0201733c(&data_0217b080->mUnk_00, 0);
    if (p == 0) {
        return;
    }
    do {
        if (p->mUnk_b4 != 0) {
            m.mUnk_24.x = p->mUnk_74.x >> 4;
            m.mUnk_24.y = p->mUnk_74.y >> 4;
            m.mUnk_24.z = p->mUnk_74.z >> 4;
            func_020849c0(&p->mUnk_08, p->mUnk_b0);
            func_020849f8(&p->mUnk_08, &m, (u32 *) p->mUnk_9c);
        }
        p = func_0201733c(&data_0217b080->mUnk_00, p);
    } while (p != 0);
}

void func_0208e2c8(Unk0216618c *a, s32 b) {
    u32 x;
    u32 y;
    u32 z;

    x = func_020d2be8();
    data_0217b07c = 0;
    if (x != 0) {
        y = func_020d2bb0();
        z = func_020d2b78();
        a->mUnk_00 = b;
        if (y != 0) {
            a->mUnk_04 = 1;
        } else {
            a->mUnk_04 = 0;
        }
        if (z != 0) {
            a->mUnk_08 = 1;
        } else {
            a->mUnk_08 = 0;
        }
    } else {
        a->mUnk_00 = 0;
        a->mUnk_04 = 0;
        a->mUnk_08 = 0;
        data_0217b084[0] = -1;
        data_0217b084[1] = -1;
    }
}

void func_0208e23c(void) {
    Unk0216618c *e;
    void *x;
    void *y;

    e = &data_02166210;
    if (func_020d2be8() != 0) {
        x = func_02047974(data_02166268);
        y = func_02047974(data_02166280);
        e->mUnk_00 = 1;
        if (x != 0) {
            e->mUnk_04 = 1;
        } else {
            e->mUnk_04 = 0;
        }
        if (y != 0) {
            e->mUnk_08 = 1;
        } else {
            e->mUnk_08 = 0;
        }
    } else {
        e->mUnk_00 = 0;
        e->mUnk_04 = 0;
        e->mUnk_08 = 0;
    }
}

void func_0208e098(void *a) {
    u16 i;
    u16 j;
    Unk0216618c *g;
    Unk0208e490 *p;
    s32 v;

    for (i = 0; i < 5; i++) {
        g = &data_0216618c[i];
        if (g->mUnk_00 == 0) {
            continue;
        }
        data_0217b080->mUnk_48[i] = func_02036bec(a, g->mUnk_00 << 2);
        for (j = 0; j < g->mUnk_00; j++) {
            p = func_02036bec(a, g->mUnk_18);
            data_0217b080->mUnk_48[i][j] = p;
            if (g->mUnk_04 == 0) {
                p->mUnk_90 = 0;
            } else {
                p->mUnk_90 = func_02036bec(a, 0x38);
            }
            if (g->mUnk_08 == 0) {
                p->mUnk_94 = 0;
            } else {
                p->mUnk_94 = func_02036bec(a, 0x38);
            }
            if (g->mUnk_0c == 0) {
                p->mUnk_98 = 0;
            } else {
                p->mUnk_98 = func_02036bec(a, 0x38);
            }
            p->mUnk_8c = i;
            p->mUnk_80 = g->mUnk_10;
            p->mUnk_84 = g->mUnk_14;
            func_020174a4(&data_0217b080->mUnk_0c[i], p);
            if (i == 2) {
                v = data_021759c0->mUnk_00 == 0xc ? 0xb33 : 0x1000;
                p->mUnk_9c[0] = v;
                p->mUnk_9c[1] = v;
                p->mUnk_9c[2] = v;
            }
        }
    }
}

void func_0208ddf4(void *a, s32 b, Unk020136f0 *c, void *d, void *e, void *f) {
    u16 i;
    u8 *t;
    Unk02087d0c *o;
    Unk0201290c *h;
    Unk0208e490 *p;
    Unk0216618c *g;
    u32 k;

    g = &data_0216618c[b];
    k = 1;
    if (data_021759c0->mUnk_00 == 0x12 || data_021759c0->mUnk_00 == 0x1d) {
        k = 0;
    }
    if (g->mUnk_00 == 0) {
        return;
    }
    if (b != 3) {
        func_0208526c(&g->mUnk_1c, c, c);
    }
    if (b == 2) {
        data_0217b07c = 1;
    }
    t = (u8 *) func_02013730((u32) c);
    h = (Unk0201290c *) (t + *(u32 *) (t + *(u16 *) (t + 0xe) + 0xc));
    for (i = 0; i < g->mUnk_00; i++) {
        p = data_0217b080->mUnk_48[b][i];
        func_02084f10(&p->mUnk_08, h);
        func_02013044(p->mUnk_08.mUnk_04, k);
        o = p->mUnk_90;
        if (o != 0) {
            if (d != 0) {
                func_0208823c(0, o, &p->mUnk_08, 1, a, c);
                func_0208805c(o, d, a);
            } else {
                o->mUnk_18 = 0;
            }
            if (b == 2) {
                if (func_02087d0c(p->mUnk_90) >> 12 == 0x20) {
                    data_0217b084[0] = 0x37;
                    data_0217b084[1] = 0x38;
                } else {
                    data_0217b084[0] = 0x39;
                    data_0217b084[1] = -1;
                }
            }
        }
        o = p->mUnk_94;
        if (o != 0) {
            if (e != 0) {
                func_0208823c(4, o, &p->mUnk_08, 1, a, c);
                func_0208805c(o, e, a);
            } else {
                o->mUnk_18 = 0;
            }
        }
        o = p->mUnk_98;
        if (o != 0) {
            if (f == 0) {
                o->mUnk_18 = 0;
            } else {
                func_0208823c(1, o, &p->mUnk_08, 1, a, c);
                func_0208805c(o, f, a);
            }
        }
    }
}

void func_0208dd6c(Unk0208e490 *a, s32 b) {
    func_02087f84(a->mUnk_90, 0);
    func_02087f84(a->mUnk_94, 0);
    func_02087f84(a->mUnk_98, 0);
    a->mUnk_9c[0] = 0xab8;
    a->mUnk_9c[1] = 0xab8;
    a->mUnk_9c[2] = 0xab8;
    if (b == 0) {
        return;
    }
    func_0208b7bc(0x22, &a->mUnk_74);
    func_0208b7bc(1, &a->mUnk_74);
    func_0208b7bc(2, &a->mUnk_74);
}

void func_0208dd10(Unk0208e490 *a) {
    if (a->mUnk_a8 == 0x26) {
        func_0208b7bc(3, &a->mUnk_74);
        return;
    }
    if (a->mUnk_a8 >= 0x37) {
        a->mUnk_88 = 1;
        return;
    }
    func_02087de0(a->mUnk_90);
    func_02087de0(a->mUnk_94);
    func_02087de0(a->mUnk_98);
}

void func_0208dcbc(Unk0208e490 *a) {
    u32 x;

    x = (u32) (func_02087d0c(a->mUnk_90) << 4) >> 16;
    func_02087f84(a->mUnk_90, 0);
    a->mUnk_ac = x;
    if (a->mUnk_94 != 0) {
        func_02087f84(a->mUnk_94, 0);
    }
}

void func_0208dc50(Unk0208e490 *a) {
    a->mUnk_9c[0] = 0x3d9a;
    a->mUnk_9c[1] = 0x3d9a;
    a->mUnk_9c[2] = 0x3d9a;
    func_02087f84(a->mUnk_90, 0);
    a->mUnk_ac = 0x20;
    if (a->mUnk_94 != 0) {
        func_02087f84(a->mUnk_94, 0);
    }
    func_0208b7bc(0x424, &a->mUnk_74);
    func_0208b7bc(0x422, &a->mUnk_74);
}

void func_0208dc08(Unk0208e490 *a) {
    if (a->mUnk_a8 >= a->mUnk_ac) {
        a->mUnk_88 = 1;
        return;
    }
    func_02087de0(a->mUnk_90);
    if (a->mUnk_94 != 0) {
        func_02087de0(a->mUnk_94);
    }
}

void func_0208db94(Unk0208e490 *a, s32 b) {
    func_02087f84(a->mUnk_90, 0);
    a->mUnk_9c[0] = 0x5800;
    a->mUnk_9c[1] = 0x5800;
    a->mUnk_9c[2] = 0x5800;
    a->mUnk_ac = 0x27;
    func_02087f84(a->mUnk_94, 0);
    if (b == 0) {
        return;
    }
    func_0208b7bc(0x40, &a->mUnk_74);
    func_0208b7bc(0x41, &a->mUnk_74);
}

void func_0208db58(Unk0208e490 *a) {
    if (a->mUnk_a8 >= a->mUnk_ac) {
        a->mUnk_88 = 1;
        return;
    }
    func_02087de0(a->mUnk_90);
    func_02087de0(a->mUnk_94);
}

void func_0208dad4(Unk0208e490 *a, s32 b) {
    func_02087f84(a->mUnk_90, 0);
    func_02087f84(a->mUnk_94, 0);
    func_02087f84(a->mUnk_98, 0);
    a->mUnk_9c[0] = 0x1000;
    a->mUnk_9c[1] = 0x1000;
    a->mUnk_9c[2] = 0x1000;
    if (b == 0) {
        return;
    }
    func_0208b7bc(8, &a->mUnk_74);
    func_0208b7bc(9, &a->mUnk_74);
    func_0208b7bc(0xa, &a->mUnk_74);
}

void func_0208da94(Unk0208e490 *a) {
    if (a->mUnk_a8 >= 0x37) {
        a->mUnk_88 = 1;
        return;
    }
    func_02087de0(a->mUnk_90);
    func_02087de0(a->mUnk_94);
    func_02087de0(a->mUnk_98);
}

void func_0208d978(const Vec3 *a, s32 b) {
    Unk0208e490 *p;
    u16 i;

    if (data_0216618c[2].mUnk_00 == 0) {
        return;
    }
    i = 0;
    if (b != 0) {
        p = func_020172d8((Unk02017328 *) ((u8 *) data_0217b080->mUnk_0c + 0x18), 0);
        if (p != 0) {
            func_02017354((Unk02017328 *) ((u8 *) data_0217b080->mUnk_0c + 0x18), p);
            p->mUnk_88 = 0;
            p->mUnk_74 = *a;
            p->mUnk_a8 = 0;
            p->mUnk_ac = 0;
            p->mUnk_b0 = data_0217b080->mUnk_5c;
            p->mUnk_b4 = 1;
            p->mUnk_80(p, 0);
            func_020174a4(&data_0217b080->mUnk_00, p);
            data_0217b080->mUnk_5c++;
            if (data_0217b080->mUnk_5c > 0xd) {
                data_0217b080->mUnk_5c = 10;
            }
        }
    }
    do {
        if (data_0217b084[i] >= 0) {
            func_0208b7bc(data_0217b084[i], a);
        }
        i++;
    } while (i < 2);
}
