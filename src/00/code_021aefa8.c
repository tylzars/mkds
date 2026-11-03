#include "00/code_021aefa8.h"

#include "00/code_021a9228.h"
#include "00/code_021ae0c4.h"
#include "00/code_021ae314.h"
#include "00/code_021af550.h"
#include "00/code_021b0014.h"
#include "00/code_021ae958.h"
#include "code_02133048.h"
#include "code_0200db4c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/code_021afe5c.h"
#include "00/unk_021b6000.h"
#include "code_0214d018.h"

void func_ov000_021af4d4(Unk021af3e8 *a) {
    a->mUnk_06 = 0x200;
    func_0214d1fc(a->mUnk_08, a->mUnk_12, 10);
    func_0214d1fc(data_ov000_021b63d0, a->mUnk_08, 6);
    a->mUnk_0e = (u16) (((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8));
    a->mUnk_10 = (u16) (((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8));
    func_0214d1fc(a->mUnk_12, (u8 *) a - 0xe, 6);
    func_0214d1fc(data_ov000_021b63d0, (u8 *) a - 8, 6);
    func_ov000_021affcc((u8 *) a - 0xe, 0x2a, NULL, 0);
}

void func_ov000_021af3e8(Unk021af3e8 *f, u32 g) {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;

    if (g < 0x1c) {
        return;
    }
    if (func_ov000_021b0014(f->mUnk_08, data_ov000_021b63d0) == 0) {
        return;
    }
    if (data_ov000_021b63b4 == 0) {
        return;
    }
    if (f->mUnk_00 != 0x100) {
        return;
    }
    if (f->mUnk_02 != 8) {
        return;
    }
    if (f->mUnk_04 != 0x406) {
        return;
    }
    a = (u16) ((f->mUnk_06 >> 8) | (f->mUnk_06 << 8));
    if (a != 1 && a != 2) {
        return;
    }
    e = (u32) (((u16) ((f->mUnk_0e >> 8) | (f->mUnk_0e << 8)) << 16) | (u16) ((f->mUnk_10 >> 8) | (f->mUnk_10 << 8)));
    d = data_ov000_021b63b4;
    if (e == d) {
        b = 1;
    } else {
        b = 0;
    }
    if (d ==
        (u32) (((u16) ((f->mUnk_18 >> 8) | (f->mUnk_18 << 8)) << 16) | (u16) ((f->mUnk_1a >> 8) | (f->mUnk_1a << 8)))) {
        c = 1;
    } else {
        c = 0;
    }
    if (b == 0) {
        func_ov000_021afb58((u8 *) f->mUnk_08, e, c);
    }
    if (a == 1 && c != 0) {
        func_ov000_021af4d4(f);
        return;
    }
    if (a == 2 && c != 0 && b != 0) {
        data_ov000_021b6368 = 1;
    }
}

void func_ov000_021af348(Unk021ae3f0 *d, Unk021af1e4 *e, u32 f) {
    u32 a;
    u32 b;
    u16 c;

    a = (u32) (((u16) ((d->mUnk_0c >> 8) | (d->mUnk_0c << 8)) << 16) | (u16) ((d->mUnk_0e >> 8) | (d->mUnk_0e << 8)));
    if (func_ov000_021b0094(a) != 0) {
        return;
    }
    b = func_ov000_021b00e0(a);
    if (b == 0) {
        return;
    }
    if (func_ov000_021afd00(b) == NULL) {
        func_ov000_021afc5c(b);
        return;
    }
    e->mUnk_00 = 0;
    e->mUnk_02 = 0;
    c = func_ov000_021b0188(e, f);
    e->mUnk_02 = (u16) ((c >> 8) | (c << 8));
    func_ov000_021af858(
        (u8 *) e, f, NULL, 0,
        (u32) (((u16) ((d->mUnk_0c >> 8) | (d->mUnk_0c << 8)) << 16) | (u16) ((d->mUnk_0e >> 8) | (d->mUnk_0e << 8))),
        1);
}

void func_ov000_021af2a0(Unk021ae3f0 *c, Unk021af1e4 *d, u32 e) {
    Unk0200db5c *a;
    Unk021a998c *b;

    for (a = data_0216ff5c.mUnk_08; a != NULL; a = a->mUnk_68) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b == NULL || b->mUnk_00 == NULL || b->mUnk_08 != 0xb || (u16) (u32) b->mUnk_00 != d->mUnk_04) {
            continue;
        }
        if (b->mUnk_0a != d->mUnk_06 || b->mUnk_44 != 0) {
            continue;
        }
        if (b->mUnk_1c != (u32) (((u16) ((c->mUnk_0c >> 8) | (c->mUnk_0c << 8)) << 16) |
                                 (u16) ((c->mUnk_0e >> 8) | (c->mUnk_0e << 8)))) {
            continue;
        }
        e -= 8;
        if (e > b->mUnk_3c) {
            b->mUnk_44 = b->mUnk_3c;
        } else {
            b->mUnk_44 = e;
        }
        func_0214d1fc((u8 *) d + 8, b->mUnk_40, b->mUnk_44);
        if (b->mUnk_04 == 3) {
            b->mUnk_04 = 0;
            func_0200df68(b->mUnk_00);
            return;
        }
        return;
    }
}

u32 func_ov000_021af284(int a, int b) {
    if ((((a != 0) && (a != -1)) && (b != 0)) && (b != -1)) {
        return 1;
    }
    return 0;
}

void func_ov000_021af1e4(Unk021ae3f0 *a, Unk021af1e4 *b, u32 c) {
    if (func_ov000_021b0188(b, c) == 0xffff) {
        if (func_ov000_021af284((u32) (((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) |
                                       (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8))),
                                (u32) (((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) |
                                       (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8)))) != 0) {
            switch (b->mUnk_00) {
                case 0:
                    func_ov000_021af2a0(a, b, c);
                    break;
                case 8:
                    if (data_ov000_021b4c24 != 0) {
                        func_ov000_021af348(a, b, c);
                    }
                    break;
            }
        }
    }
}

Unk021a998c *func_ov000_021af15c(const Unk021ae3f0 *c, const Unk021ae87c *d) {
    Unk021a998c *b;
    Unk0200db5c *a;

    for (a = data_0216ff5c.mUnk_08; a != NULL; a = a->mUnk_68) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b == NULL || b->mUnk_00 == NULL || b->mUnk_08 != 1 ||
            b->mUnk_0a != (u16) ((d->mUnk_02 >> 8) | (d->mUnk_02 << 8))) {
            continue;
        }
        if (b->mUnk_18 != 0 && b->mUnk_18 != (u16) ((d->mUnk_00 >> 8) | (d->mUnk_00 << 8))) {
            continue;
        }
        if (b->mUnk_1c != 0 && b->mUnk_1c != (u32) (((u16) ((c->mUnk_0c >> 8) | (c->mUnk_0c << 8)) << 16) |
                                                    (u16) ((c->mUnk_0e >> 8) | (c->mUnk_0e << 8)))) {
            continue;
        }
        return b;
    }
    return NULL;
}

u32 func_ov000_021af0dc(const Unk021ae3f0 *e, const Unk021ae87c *f, const Unk021a998c *g) {
    u32 a = 0;
    u32 c = 0;
    u32 b = 0;
    u32 d = 0;

    if (g->mUnk_08 != 0xa && g->mUnk_08 != 0xb) {
        d = 1;
    }
    if (d != 0) {
        if (g->mUnk_0a == (u16) ((f->mUnk_02 >> 8) | (f->mUnk_02 << 8))) {
            b = 1;
        }
    }
    if (b != 0) {
        if (g->mUnk_18 == (u16) ((f->mUnk_00 >> 8) | (f->mUnk_00 << 8))) {
            c = 1;
        }
    }
    if (c != 0) {
        if (g->mUnk_1c == (u32) (((u16) ((e->mUnk_0c >> 8) | (e->mUnk_0c << 8)) << 16) |
                                 (u16) ((e->mUnk_0e >> 8) | (e->mUnk_0e << 8)))) {
            a = 1;
        }
    }
    return a;
}

Unk021a998c *func_ov000_021af090(const Unk021ae3f0 *c, const Unk021ae87c *d) {
    Unk021a998c *b;
    Unk0200db5c *a;

    a = data_0216ff5c.mUnk_08;
    while (a != NULL) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b != NULL && b->mUnk_00 != NULL && func_ov000_021af0dc(c, d, b) != 0) {
            return b;
        }
        a = a->mUnk_68;
    }
    return NULL;
}

void func_ov000_021af030(const Unk021ae87c *f, Unk021a998c *g) {
    const u8 *a;
    s32 b;
    s32 c;
    s32 e;
    u8 d;

    g->mUnk_2e = 0x218;
    b = (f->mUnk_0c & 0xf0) / 4 - 0x14;
    a = (const u8 *) f + 0x14;
    c = b - 1;
    if (b != 0) {
        do {
            d = *a++;
            if (d == 0) {
                break;
            }
            if (d != 1) {
                if (d == 2) {
                    g->mUnk_2e = (a[1] << 8) | a[2];
                    a += 3;
                    c -= 3;
                } else {
                    e = a[0] - 1;
                    c -= e;
                    a += e;
                }
            }
        } while (c-- != 0);
    }
}

u32 func_ov000_021af010(u32 b) {
    u32 a;

    a = func_ov000_021b00e0(b);
    if (a == 0) {
        return 1;
    }
    return (u32) func_ov000_021afd00(a);
}

void func_ov000_021aefc0(Unk021a998c *a, u32 b, u16 c) {
    if (func_ov000_021af010(a->mUnk_1c) != 0 || data_0216ff5c.mUnk_04 != &data_ov000_021b661c) {
        func_ov000_021af550(NULL, 0, a, b, c);
    } else {
        func_ov000_021afc5c(func_ov000_021b00e0(a->mUnk_1c));
    }
}

void func_ov000_021aefb4(void *object, u16 value) {
    func_ov000_021aefc0(object, 16, value);
}

void func_ov000_021aefa8(void *object, u16 value) {
    func_ov000_021aefc0(object, 17, value);
}
