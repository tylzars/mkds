#include "Main/Unknown/code_020a49d4.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02081f10.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_02062eb0.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020a2e88.h"
#include "Main/Unknown/code_020a2f0c.h"
#include "Main/Unknown/code_020a3000.h"
#include "Main/Unknown/code_020a5958.h"
#include "Main/Unknown/code_020a683c.h"
#include "Main/Unknown/code_020a69a0.h"
#include "Main/Unknown/code_020a69b4.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_020a5918(void) {
    Unk0209bfa8 *p;

    p = func_0209bfa8((u32) func_020a6ae4, 0, 0, 1, 0);
    p->mUnk_38 = 0x190000;
    p->mUnk_3c = -0x190000;
}

u32 func_020a58f4(void) {
    return func_0209bef0((u32) func_020a6aa8, (u32) func_020a69b4, (u32) func_020a6a90);
}

u32 func_020a58d0(void) {
    return func_0209bf1c((u32) func_020a69a0, (u32) func_020a683c, (u32) func_020a697c);
}

u32 func_020a58b4(void) {
    return func_0209bf48(0, (u32) func_020a5958, 0);
}

void func_020a5848(void) {
    s32 i;
    Unk020e71a0 *o;
    Unk020e6fd4 *l;

    l = func_02100138(0x6a);
    if (l == 0) {
        return;
    }
    for (i = 0; i < l->mUnk_04 && (o = l->mUnk_00[i]) != 0; i++) {
        if ((o->mUnk_02 & 0x100) == 0) {
            func_020d2398(o);
        }
    }
}

void func_020a5744(Vec3 *a, s32 b, s32 c) {
    Unk020a5958 *p;

    p = func_0209bbfc(func_02100138(0x6a));
    if (p == 0) {
        return;
    }
    if (c != 0) {
        p->mUnk_00.mUnk_04.x = a->x;
        p->mUnk_00.mUnk_04.y = a->y + 0x32000;
        p->mUnk_00.mUnk_04.z = a->z;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0x2800;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_a0 = 0;
        p->mUnk_a4 = a->y + 0x14000;
        p->mUnk_e0 = 0;
    } else {
        p->mUnk_00.mUnk_04.x = a->x;
        p->mUnk_00.mUnk_04.y = a->y + 0x14000;
        p->mUnk_00.mUnk_04.z = a->z;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_a0 = 0;
        p->mUnk_a4 = 0;
        p->mUnk_e0 = 1;
    }
    p->mUnk_a8 = 0;
    p->mUnk_c0 = 0;
    p->mUnk_c4 = b;
    p->mUnk_00.mUnk_02 &= ~1;
    p->mUnk_00.mUnk_02 &= ~0x20;
    func_020a1218(1);
    func_0210b98c(p->mUnk_00.mUnk_94, 0x138);
}

void func_020a5608(Unk0206bcb0 *a, Unk0206bcb0 *b) {
    Unk020a5958 *p;
    s32 r;
    u16 c;
    s32 n;

    p = func_0209bbfc(func_02100138(0x6a));
    if (p == 0) {
        return;
    }
    p->mUnk_00.mUnk_02 = p->mUnk_00.mUnk_02 | data_021567a0;
    p->mUnk_00.mUnk_02 &= ~0x20;
    p->mUnk_00.mUnk_04.x = a->mUnk_80.x;
    p->mUnk_00.mUnk_04.y = a->mUnk_80.y;
    p->mUnk_00.mUnk_04.z = a->mUnk_80.z;
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0x1000;
    p->mUnk_00.mUnk_10.z = 0;
    p->mUnk_c8 = a->mUnk_74;
    p->mUnk_ca = b->mUnk_74;
    p->mUnk_a0 = 0;
    p->mUnk_a4 = 0;
    p->mUnk_a8 = 0;
    p->mUnk_c0 = 0;
    p->mUnk_e0 = 3;
    p->mUnk_cc = b->mUnk_80;
    if (b == a) {
        p->mUnk_d8 = 0;
    } else {
        p->mUnk_d8 = 0x9c400;
    }
    p->mUnk_dc = 0;
    p->mUnk_c4 = -1;
    func_020a1218(1);
    r = a->mUnk_74 == data_021759c0->mUnk_62 ? 1 : 0;
    c = func_020a1180();
    n = func_020a1154(a->mUnk_74);
    func_0210b98c(p->mUnk_00.mUnk_94, func_02024974(1, r, c, n));
}

s32 func_020a5268(u16 a, u16 b) {
    Unk0206bcb0 *o;
    Unk020a3fa8_a4 *e;
    Unk020a2fe4 *f;
    Unk020a2fe4 *l;
    Vec3 v;
    s32 n;

    o = func_0207a974(a);
    func_020a2378();
    if (func_020a1154(b) >= 3 || func_020a1154(a) == 0) {
        e = (Unk020a3fa8_a4 *) func_020a2378() + a;
        f = func_020a2204(a) != 0 ? e->mUnk_10[func_020a1154(a)] : 0;
        l = func_020a1154(a) != 0 ? e->mUnk_10[func_020a1154(a) - 1] : 0;
        if (func_020a1154(a) != 0 && l != 0) {
            if (func_020a2204(a) != 0 && f != 0) {
                e->mUnk_10[func_020a1154(a)] = l;
                func_020a10f0(a, -1);
                e->mUnk_10[func_020a1154(a)] = f;
            } else {
                func_020a10f0(a, -1);
            }
        }
        if (l != 0) {
            if (a == data_021759c0->mUnk_62) {
                func_020a2ebc(l, 0);
            } else {
                v.x = o->mUnk_80.x;
                v.y = o->mUnk_80.y + func_020a23a0(o) - 0xf666;
                v.z = o->mUnk_80.z;
                l->mUnk_00.mUnk_02 &= ~4;
                l->mUnk_00.mUnk_02 &= ~2;
                l->mUnk_00.mUnk_02 &= ~8;
                l->mUnk_00.mUnk_66 = 0x1f;
                func_020a2ebc(l, &v);
            }
            func_020d26ec(o, 0x153);
            if (func_020a1154(a) == 0) {
                func_020a16d0(a);
            }
            return 0;
        }
    } else {
        e = (Unk020a3fa8_a4 *) func_020a2378() + a;
        f = func_020a2204(a) != 0 ? e->mUnk_10[func_020a1154(a)] : 0;
        l = func_020a1154(a) != 0 ? e->mUnk_10[func_020a1154(a) - 1] : 0;
        if (func_020a1154(a) != 0 && l != 0) {
            if (func_020a2204(a) != 0 && f != 0) {
                e->mUnk_10[func_020a1154(a)] = l;
                func_020a10f0(a, -1);
                e->mUnk_10[func_020a1154(a)] = f;
            } else {
                func_020a10f0(a, -1);
            }
        }
        if (l != 0) {
            e = (Unk020a3fa8_a4 *) func_020a2378() + b;
            n = func_020a1154(b);
            e->mUnk_10[n + 1] = e->mUnk_10[func_020a1154(b)];
            e->mUnk_10[func_020a1154(b)] = l;
            func_020a10f0(b, 1);
            func_020a2e68(l);
            func_020a2e58(l, b);
            if (func_020a1154(b) >= 2 && func_020a2204(b) != 0) {
                e->mUnk_34 = 4;
            }
            func_02081f10(func_0208b7bc(0x7a, &o->mUnk_80), o->mUnk_74, 0x20);
            func_02081f10(func_0208b7bc(0x7b, &o->mUnk_80), o->mUnk_74, 0x20);
            func_020d26ec(func_0207a974(b), 0x14f);
            if (func_020a1154(a) == 0) {
                func_020a16d0(a);
            }
            return 1;
        }
    }
    return 0;
}

s32 func_020a4f54(u16 a, u16 b) {
    Unk020a3fa8_a4 *v1;
    Unk020a3fa8_a4 *v2;
    Unk020a2fe4 *f;
    Unk020a2fe4 *l;
    Unk020a2fe4 *g;
    Unk020a2fe4 *m;
    Unk0210b7a8 s;
    s32 n;

    v1 = (Unk020a3fa8_a4 *) func_020a2378();
    v1 += a;
    f = func_020a2204(a) != 0 ? v1->mUnk_10[func_020a1154(a)] : 0;
    l = func_020a1154(a) != 0 ? v1->mUnk_10[func_020a1154(a) - 1] : 0;
    if (func_020a1154(a) != 0 && l != 0) {
        if (func_020a2204(a) != 0 && f != 0) {
            v1->mUnk_10[func_020a1154(a)] = l;
            func_020a10f0(a, -1);
            v1->mUnk_10[func_020a1154(a)] = f;
        } else {
            func_020a10f0(a, -1);
        }
    }
    v2 = (Unk020a3fa8_a4 *) func_020a2378();
    v2 += b;
    g = func_020a2204(b) != 0 ? v2->mUnk_10[func_020a1154(b)] : 0;
    m = func_020a1154(b) != 0 ? v2->mUnk_10[func_020a1154(b) - 1] : 0;
    if (func_020a1154(b) != 0 && m != 0) {
        if (func_020a2204(b) != 0 && g != 0) {
            v2->mUnk_10[func_020a1154(b)] = m;
            func_020a10f0(b, -1);
            v2->mUnk_10[func_020a1154(b)] = g;
        } else {
            func_020a10f0(b, -1);
        }
    }
    if (l != 0) {
        v2 = (Unk020a3fa8_a4 *) func_020a2378();
        v2 += b;
        n = func_020a1154(b);
        v2->mUnk_10[n + 1] = v2->mUnk_10[func_020a1154(b)];
        v2->mUnk_10[func_020a1154(b)] = l;
        func_020a10f0(b, 1);
        func_020a2e68(l);
        func_020a2e58(l, b);
        if (func_020a1154(b) >= 2 && func_020a2204(b) != 0) {
            v2->mUnk_34 = 4;
        }
    }
    if (m != 0) {
        v1 = (Unk020a3fa8_a4 *) func_020a2378();
        v1 += a;
        n = func_020a1154(a);
        v1->mUnk_10[n + 1] = v1->mUnk_10[func_020a1154(a)];
        v1->mUnk_10[func_020a1154(a)] = m;
        func_020a10f0(a, 1);
        func_020a2e68(m);
        func_020a2e58(m, a);
        if (func_020a1154(a) >= 2 && func_020a2204(a) != 0) {
            v1->mUnk_34 = 4;
        }
    }
    if (a == data_021759c0->mUnk_62 || b == data_021759c0->mUnk_62) {
        s.mUnk_00 = 0x14f;
        s.mUnk_04 = 0;
        s.mUnk_08 = 2;
        s.mUnk_0c = func_020d4ef4(0);
        func_0210b7a8(&s);
    }
    return 1;
}

s32 func_020a4d94(u16 a, u16 b) {
    Unk0206bcb0 *o;
    Unk020a3fa8_a4 *e;
    Unk020a2fe4 *f;
    Unk020a2fe4 *l;
    Vec3 v;

    e = (Unk020a3fa8_a4 *) func_020a2378() + a;
    f = func_020a2204(a) != 0 ? e->mUnk_10[func_020a1154(a)] : 0;
    l = func_020a1154(a) != 0 ? e->mUnk_10[func_020a1154(a) - 1] : 0;
    if (func_020a1154(a) != 0 && l != 0) {
        if (func_020a2204(a) != 0 && f != 0) {
            e->mUnk_10[func_020a1154(a)] = l;
            func_020a10f0(a, -1);
            e->mUnk_10[func_020a1154(a)] = f;
        } else {
            func_020a10f0(a, -1);
        }
    }
    if (l != 0) {
        o = func_0207a974(a);
        func_020a2378();
        if (a == data_021759c0->mUnk_62) {
            func_020a2ebc(l, 0);
        } else {
            v.x = o->mUnk_80.x;
            v.y = o->mUnk_80.y + func_020a23a0(o) - 0xf666;
            v.z = o->mUnk_80.z;
            l->mUnk_00.mUnk_02 &= ~4;
            l->mUnk_00.mUnk_02 &= ~2;
            l->mUnk_00.mUnk_02 &= ~8;
            l->mUnk_00.mUnk_66 = 0x1f;
            func_020a2ebc(l, &v);
        }
        func_020d26ec(o, 0x153);
        if (func_020a1154(a) == 0) {
            func_020a16d0(a);
        }
        return 1;
    }
    return 0;
}

void func_020a4c58(u16 a) {
    Unk020a3fa8_a4 *e;
    Unk020a2fe4 *f;
    Unk020a2fe4 *l;

    if (data_021759c0->mUnk_08 != 2) {
        return;
    }
    func_020a4d94(a, a);
    if (func_020a1154(a) == 0) {
        return;
    }
    do {
        e = (Unk020a3fa8_a4 *) func_020a2378() + a;
        f = func_020a2204(a) != 0 ? e->mUnk_10[func_020a1154(a)] : 0;
        l = func_020a1154(a) != 0 ? e->mUnk_10[func_020a1154(a) - 1] : 0;
        if (func_020a1154(a) != 0 && l != 0) {
            if (func_020a2204(a) != 0 && f != 0) {
                e->mUnk_10[func_020a1154(a)] = l;
                func_020a10f0(a, -1);
                e->mUnk_10[func_020a1154(a)] = f;
            } else {
                func_020a10f0(a, -1);
            }
        }
        if (l != 0) {
            func_020a2f0c(l, a);
        }
    } while (func_020a1154(a) != 0);
}

void func_020a4c20(void) {
    if (data_021759c0->mUnk_08 != 2) {
        return;
    }
    func_020a305c();
}

void func_020a4b70(u16 a, Vec3 *b) {
    Unk020a3fa8_a4 *e;
    Unk020a2fe4 *p;
    s32 i;
    s32 n;

    e = (Unk020a3fa8_a4 *) func_020a2378() + a;
    if (b == 0) {
        return;
    }
    n = (func_020a2204(a) != 0 ? 1 : 0) + func_020a1154(a);
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        p = e->mUnk_10[i];
        p->mUnk_00.mUnk_04.x += b->x;
        p->mUnk_00.mUnk_04.y += b->y;
        p->mUnk_00.mUnk_04.z += b->z;
        i++;
    } while (i < n);
}

void func_020a49d4(Unk020a3fa8 *a) {
    Unk021759c0 *d;
    s32 n;
    s32 i;
    Unk020a3fa8_a4 *p;
    s32 j;
    s32 w;
    s32 v;

    if (func_020d3bf8(0x6c) == 0) {
        d = data_021759c0;
        n = d->mUnk_3d0;
        if (d->mUnk_08 == 2) {
            func_020ac588(0x6c, 0x20, a);
        } else {
            func_020ac588(0x6c, 4, a);
        }
        for (i = 0; i < n; i++) {
            p = &a->mUnk_0a4[i];
            if (a->mUnk_000.mUnk_9c->mUnk_2c != 0) {
                p->mUnk_30 = a->mUnk_000.mUnk_9c->mUnk_2c;
            } else {
                switch (data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_04) {
                    case 0:
                        p->mUnk_30 = 1;
                        break;
                    case 1:
                        p->mUnk_30 = 3;
                        break;
                    default:
                        p->mUnk_30 = i;
                        break;
                }
            }
        }
        for (i = 0, w = 0; i < 8; i++, w -= 0x600) {
            for (j = 0, v = w; j < 8; j++, v += 0xc00) {
                a->mUnk_264[i][j] = v;
            }
        }
        if (func_02062ec4() != 0) {
            a->mUnk_0a0 = 0xffff;
        } else {
            a->mUnk_0a0 = 0x3c;
        }
        func_020a238c((u32) a->mUnk_0a4);
        func_020a2364((u32) func_020a5268);
        func_020a2350((u32) func_020a4f54);
        func_020a233c(func_020a4d94);
        func_020a2328(func_020a4c58);
        func_020a2314(func_020a4c20);
        func_020a2300((u32) func_020a4b70);
    } else {
        func_020d2398(&a->mUnk_000);
    }
}
