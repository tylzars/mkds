#include "Main/Unknown/code_020a8ed8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a9cd0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "01/code_021a2034.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/code_020a9000.h"

void func_020a9c54(void *a, Unk020a9268 *p, u32 c, u32 d) {
    u32 v;

    if (p->mUnk_12c == 0) {
        return;
    }
    if (((s32) p->mUnk_000.mUnk_78 & 0x3fffffe0) >= 1000000) {
        return;
    }
    v = p->mUnk_0e8.mUnk_030;
    if (v == 0) {
        return;
    }
    if (v > 0x1c) {
        return;
    }
    func_020e53ac(&p->mUnk_0e8, 0, c, d);
}

void func_020a9a5c(Unk020a9a5c *p) {
    s32 i;
    Unk020a9268 *o;
    u32 z0;
    u32 z1;
    u32 z2;
    u32 k;
    u16 b;
    u16 c;
    u16 a;

    if (p == 0) {
        return;
    }
    z0 = 0;
    z1 = 0;
    z2 = 0;
    k = 0x1c;
    b = data_021567ec;
    c = data_021567f0;
    a = data_021567f4;
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != 0; i++) {
        o->mUnk_000.mUnk_02 |= b;
        o->mUnk_000.mUnk_02 |= c;
        o->mUnk_000.mUnk_02 |= a;
        o->mUnk_0b4 = (o->mUnk_000.mUnk_9c->mUnk_28 * 0xa000L) / 100;
        o->mUnk_0b8 = (o->mUnk_000.mUnk_9c->mUnk_28 * 0x5000L) / 100;
        o->mUnk_0b0 = o->mUnk_0b4;
        o->mUnk_11c = o->mUnk_000.mUnk_9c->mUnk_00;
        o->mUnk_000.mUnk_04 = o->mUnk_11c;
        o->mUnk_11c.y += 0x1000;
        func_020e516c(&o->mUnk_0e8, &o->mUnk_11c, o->mUnk_000.mUnk_58.x << 1, k);
        func_020d2450(&o->mUnk_000);
        func_020d7da8(&o->mUnk_0c4, o->mUnk_000.mUnk_9c, z0);
        func_020d8918(&o->mUnk_0c4, &o->mUnk_11c, &o->mUnk_000.mUnk_10);
        o->mUnk_11c.y += 0x1000;
        func_02147fd8(o->mUnk_000.mUnk_58.x, &o->mUnk_000.mUnk_28.mUnk_0c, &o->mUnk_11c, &o->mUnk_000.mUnk_04);
        if (o->mUnk_000.mUnk_02 & 0x800) {
            o->mUnk_0a8 = (u16) o->mUnk_000.mUnk_9c->mUnk_2a;
            o->mUnk_130 = z2;
        } else {
            o->mUnk_0ac = (o->mUnk_000.mUnk_9c->mUnk_2a + 0x176f) / 6000 + 1;
            o->mUnk_130 = z1;
        }
    }
}

void func_020a9268(void *a, Unk020a9268 *p) {
    Unk02042044 *e;
    Unk020f41c4_B *q;
    s32 f;
    s32 v;
    s32 w;
    s32 i;
    s32 n;
    s32 t;
    u16 u;

    if (p->mUnk_0a8 > 0) {
        p->mUnk_0a8 -= 1;
    }
    switch (p->mUnk_130) {
        case 0:
            if (p->mUnk_000.mUnk_02 & 0x800) {
                if (p->mUnk_0a8-- > 0) {
                    return;
                }
                p->mUnk_0a8 = (u16) p->mUnk_000.mUnk_9c->mUnk_2c;
                p->mUnk_0a4 = (u16) p->mUnk_000.mUnk_9c->mUnk_2e;
                func_020d90a8(&p->mUnk_0c4, 0, 1);
                p->mUnk_130 = 1;
                return;
            }
            w = p->mUnk_0ac;
            for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
                if (func_0203c8c0((u16) i) >= w) {
                    f = 1;
                    goto found;
                }
            }
            f = 0;
        found:
            if (f == 0) {
                return;
            }
            p->mUnk_0ac = p->mUnk_0ac + 1;
            p->mUnk_0a4 = (u16) p->mUnk_000.mUnk_9c->mUnk_2e;
            func_020d90a8(&p->mUnk_0c4, 0, 1);
            p->mUnk_130 = 1;
            return;
        case 1:
            p->mUnk_0a4 -= 1;
            if (p->mUnk_0a4 > 0) {
                return;
            }
            p->mUnk_000.mUnk_02 &= ~1;
            p->mUnk_000.mUnk_02 &= ~2;
            p->mUnk_000.mUnk_02 &= ~8;
            p->mUnk_000.mUnk_66 = 0x1f;
            p->mUnk_130 = 2;
            return;
        case 2:
            break;
        default:
            return;
    }
    if (!(func_0207a780() & p->mUnk_128) && !(p->mUnk_000.mUnk_78 & 4)) {
        func_0210b874(p->mUnk_000.mUnk_94, p->mUnk_0b0);
    }
    v = p->mUnk_0b0;
    p->mUnk_0c4.mUnk_04 = v;
    p->mUnk_0c4.mUnk_10 = ((s64) v * p->mUnk_0c4.mUnk_00->mUnk_00[p->mUnk_0c4.mUnk_0c].mUnk_34) >> 12;
    if (func_020d8cc8(&p->mUnk_0c4) != 0) {
        e = p->mUnk_0c4.mUnk_1c;
        if (p->mUnk_0c4.mUnk_18 == 0) {
            if (e->mUnk_10 >= 0) {
                func_020d90a8(&p->mUnk_0c4, e->mUnk_10, 1);
                e = p->mUnk_0c4.mUnk_1c;
            } else if (p->mUnk_000.mUnk_9c->mUnk_2c != 0) {
                func_020d90a8(&p->mUnk_0c4, 0, 1);
                p->mUnk_000.mUnk_02 |= data_021567ec;
                p->mUnk_000.mUnk_02 |= data_021567f0;
                p->mUnk_000.mUnk_02 |= data_021567f4;
                p->mUnk_130 = 0;
                return;
            } else {
                func_020d2398(&p->mUnk_000);
                return;
            }
        } else if (e->mUnk_10 >= 0) {
            q = func_020d22d0();
            q->mUnk_00 = q->mUnk_08 * q->mUnk_00 + q->mUnk_10;
            u = ((u64) (u32) (q->mUnk_00 >> 32) * 5) >> 32;
            if (u != 0) {
                func_020d90a8(&p->mUnk_0c4, e->mUnk_10, 1);
                e = p->mUnk_0c4.mUnk_1c;
            }
        }
        v = e->mUnk_0e;
        if ((u16) v <= 1) {
            p->mUnk_0b0 = p->mUnk_0b4;
            p->mUnk_12c = 0;
        } else if ((u16) (s16) (v - 2) <= 1) {
            p->mUnk_0b0 = p->mUnk_0b8;
            p->mUnk_12c = 2;
        } else if (v == 10) {
            p->mUnk_0b0 = 0x8000;
            p->mUnk_12c = 2;
            p->mUnk_0bc = p->mUnk_11c.y;
            func_020d90a8(&p->mUnk_0c4, e->mUnk_0c + 1, 1);
            func_020d8918(&p->mUnk_0c4, &p->mUnk_11c, &p->mUnk_000.mUnk_10);
            p->mUnk_11c.y += 0x1000;
            p->mUnk_0bc = p->mUnk_0bc - p->mUnk_11c.y;
            p->mUnk_0c0 = 0xa000;
        } else if (v == 11) {
            p->mUnk_0b0 = 0x5000;
            p->mUnk_12c = 2;
            p->mUnk_0bc = p->mUnk_11c.y;
            func_020d90a8(&p->mUnk_0c4, e->mUnk_0c + 1, 1);
            func_020d8918(&p->mUnk_0c4, &p->mUnk_11c, &p->mUnk_000.mUnk_10);
            p->mUnk_11c.y += 0x1000;
            p->mUnk_0bc = p->mUnk_0bc - p->mUnk_11c.y;
            p->mUnk_0c0 = -0x3000;
        } else if (v >= 100) {
            p->mUnk_11c = e->mUnk_00;
            p->mUnk_000.mUnk_10.x = 0;
            p->mUnk_000.mUnk_10.y = 0;
            p->mUnk_000.mUnk_10.z = 0;
            n = ((const Unk02042044 *) e)->mUnk_0e;
            if (n < 200) {
                func_0209bfe0(n - 100);
                p->mUnk_0b0 = 0xf000;
                p->mUnk_12c = 1;
            } else if (n < 300) {
                t = n - 200;
                if (n != p->mUnk_0c4.mUnk_20->mUnk_0e) {
                    p->mUnk_0b0 = 0x1e000;
                } else {
                    func_0209753c(t);
                }
                p->mUnk_12c = 1;
            }
        }
    }
    if (p->mUnk_0c4.mUnk_1c->mUnk_0d != 0 && p->mUnk_0c4.mUnk_20->mUnk_0d != 0) {
        p->mUnk_000.mUnk_02 |= data_021567f8;
    } else {
        p->mUnk_000.mUnk_02 &= ~0x20;
    }
    if (p->mUnk_0bc > 0 || p->mUnk_0c0 != 0) {
        p->mUnk_0c0 -= 0x1000;
        p->mUnk_0bc = p->mUnk_0bc + p->mUnk_0c0;
        if (p->mUnk_0bc <= 0) {
            p->mUnk_0c0 = (s32) (((s64) p->mUnk_0c0 * -0x800) >> 12);
            if (p->mUnk_0c0 < 0x1000) {
                p->mUnk_0c0 = 0;
            } else if (!(func_0207a780() & p->mUnk_128) && !(p->mUnk_000.mUnk_78 & 4)) {
                func_0210b8bc(p->mUnk_000.mUnk_94, p->mUnk_0c0);
            }
            p->mUnk_0bc = p->mUnk_0c0;
        }
    }
    v = p->mUnk_0c4.mUnk_1c->mUnk_0e;
    if (v >= 100) {
        func_020d8918(&p->mUnk_0c4, &p->mUnk_11c, &p->mUnk_000.mUnk_10);
        p->mUnk_11c.y += 0x1000;
        w = p->mUnk_0b0 - 410;
        if (w <= 0xa000) {
            w = 0xa000;
        }
        p->mUnk_0b0 = w;
    } else if ((u16) (s16) (v - 10) <= 1) {
        func_020d8918(&p->mUnk_0c4, &p->mUnk_11c, &p->mUnk_000.mUnk_10);
        p->mUnk_11c.y += 0x1000;
    } else if (v == 0 || v == 2) {
        func_020d8bf8(&p->mUnk_0c4, &p->mUnk_11c, &p->mUnk_000.mUnk_10);
        p->mUnk_11c.y += 0x1000;
    } else {
        func_020d8918(&p->mUnk_0c4, &p->mUnk_11c, &p->mUnk_000.mUnk_10);
        p->mUnk_11c.y += 0x1000;
    }
    func_02147fd8(p->mUnk_000.mUnk_58.x, &p->mUnk_000.mUnk_28.mUnk_0c, &p->mUnk_11c, &p->mUnk_000.mUnk_04);
    p->mUnk_000.mUnk_04.y = p->mUnk_000.mUnk_04.y + p->mUnk_0bc;
    if (p->mUnk_0a0 < 0) {
        if (p->mUnk_0a0 == -1) {
            v = 0x38e;
        } else {
            v = -1;
        }
    } else {
        if (p->mUnk_0a0 != 1) {
            v = 1;
        } else {
            v = -0x38e;
        }
    }
    p->mUnk_0a0 = v;
    if (p->mUnk_12c == 2) {
        func_020e516c(&p->mUnk_0e8, &p->mUnk_11c, p->mUnk_000.mUnk_58.x << 1, 0x1c);
        p->mUnk_11c.y += 0x1000;
        p->mUnk_12c = 1;
    }
    if (p->mUnk_12c != 0) {
        if (((s32) p->mUnk_000.mUnk_78 & 0x3fffffe0) < 1000000) {
            w = (p->mUnk_0bc >> 14) - 7;
            if (w < 0) {
                v = 0x1c;
            } else if (w < 0x1c) {
                v = 0x1c - w;
            } else {
                v = 0;
            }
            p->mUnk_0e8.mUnk_030 = v;
            func_020e5634(&p->mUnk_0e8, &p->mUnk_11c);
        }
        p->mUnk_000.mUnk_02 &= ~1;
    } else {
        p->mUnk_000.mUnk_02 |= data_021567ec;
    }
}

void func_020a9224(void) {
    Unk020a9224 *p;

    p = func_0209bfa8(func_020a9de4, 0, 0, 1, 1);
    p->mUnk_38 = 0x190000;
    p->mUnk_3c = -0x1f4000;
}

u32 func_020a9204(void) {
    return func_0209bf1c(func_020a9cd0, func_020a9c54, 0);
}

u32 func_020a91e0(void) {
    return func_0209bef0(CreateIronBall, func_020a9cd4, func_020a9d98);
}

u32 func_020a91c0(void) {
    return func_0209bf48(func_020a9a5c, func_020a9268, 0);
}

void func_020a8ed8(Unk020a826c_a0 *a, Vec3 *b) {
    s32 k;
    Unk02061808 *r;
    s32 v;
    s32 n;
    s32 x;
    s32 m;

    r = func_02061808();
    switch (data_021759c0->mUnk_00) {
        case 0x14:
            if (func_0203c25c(data_021759c0->mUnk_62) != 0 || func_02062ec4() != 0) {
                k = 0x898000;
            } else {
                k = 0x834000;
            }
            v = func_02148714(r->mUnk_024.x - b->x, r->mUnk_024.z - b->z);
            if (v >= 0 && v <= 0xaaab) {
                n = ((u16) v >> 4) << 1;
                a->mUnk_10.x = b->x + (s32) (((s64) data_0215d4b4[n] * 0x5dc000) >> 12);
                a->mUnk_10.y = b->y;
                a->mUnk_10.z = b->z + (s32) (((s64) data_0215d4b4[n + 1] * 0x5dc000) >> 12);
                a->mUnk_20 = 0;
            } else if (r->mUnk_024.z > b->z && r->mUnk_024.y < b->y - 0x32000) {
                a->mUnk_10.x = b->x + (s32) (((s64) data_0215d4b4[0] * 0x5dc000) >> 12);
                a->mUnk_10.y = b->y;
                a->mUnk_10.z = b->z + (s32) (((s64) data_0215d4b4[1] * 0x5dc000) >> 12);
                v = a->mUnk_10.x - k;
                n = r->mUnk_024.x;
                if (n <= v) {
                    n = v;
                }
                a->mUnk_10.x = n;
                a->mUnk_20 = 1;
            } else {
                a->mUnk_10.x = b->x + (s32) (((s64) data_0215feb4[0x54] * 0x5dc000) >> 12);
                a->mUnk_10.y = b->y;
                a->mUnk_10.z = b->z + (s32) (((s64) data_0215feb4[0x55] * 0x5dc000) >> 12);
                a->mUnk_20 = 0;
            }
            break;
        case 0x19:
            if (func_0203c25c(data_021759c0->mUnk_62) != 0 || func_02062ec4() != 0) {
                m = 0x384000;
            } else {
                m = 0x320000;
            }
            x = b->x - m;
            if (x <= r->mUnk_024.x) {
                x = b->x + m;
                if (x >= r->mUnk_024.x) {
                    x = r->mUnk_024.x;
                }
            }
            a->mUnk_10.x = x;
            a->mUnk_10.y = b->y;
            a->mUnk_10.z = b->z;
            if (r->mUnk_024.x < b->x) {
                a->mUnk_20 = 1;
            } else {
                a->mUnk_20 = 0;
            }
            break;
    }
}
