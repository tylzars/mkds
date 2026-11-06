#include "code_0200fe74.h"

#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f59c.h"
#include "code_02013740.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02170000.h"

u32 gVramBankLockedMask;
u16 gVramBankLockIds[9];

void func_020106c8(Unk020101e8_08 *a, Unk020103c0_e *b, Unk02010294 *c, Unk020106c8_0c *d) {
    u32 m;
    u32 i;
    u8 *idx;
    u32 x;
    u32 y;
    Unk020106c8_14 *n;

    idx = (u8 *) a + b->mUnk_00;
    if ((d->mUnk_00 & 0x1c000000) != 0x14000000) {
        m = c->mUnk_08 & 0xffff;
    } else {
        m = c->mUnk_18 & 0xffff;
    }
    for (i = 0; i < b->mUnk_02; i++) {
        u8 *t;
        t = (u8 *) a + 4 + a->mUnk_0a;
        n = (Unk020106c8_14 *) ((u8 *) a + *(u32 *) (t + *(u16 *) t * idx[i] + 4));
        n->mUnk_14 |= d->mUnk_00 + m;
        x = d->mUnk_04 & 0x7ff;
        y = (d->mUnk_04 >> 11) & 0x7ff;
        n->mUnk_24 = (x == n->mUnk_20) ? 0x1000 : DivFixed12(x << 12, n->mUnk_20 << 12);
        n->mUnk_28 = (y == n->mUnk_22) ? 0x1000 : DivFixed12(y << 12, n->mUnk_22 << 12);
    }
    b->mUnk_03 |= 1;
}

void func_0201063c(Unk020101e8_08 *a, Unk020103c0_e *b) {
    u8 *idx;
    u32 i;
    Unk020106c8_14 *n;

    idx = (u8 *) a + b->mUnk_00;
    for (i = 0; i < b->mUnk_02; i++) {
        u8 *t;
        t = (u8 *) a + 4 + a->mUnk_0a;
        n = (Unk020106c8_14 *) ((u8 *) a + *(u32 *) (t + *(u16 *) t * idx[i] + 4));
        n->mUnk_14 &= 0xc00f0000;
        n->mUnk_24 = 0x1000;
        n->mUnk_28 = n->mUnk_24;
    }
    b->mUnk_03 &= ~1;
}

int func_02010584(Unk020101e8 *a, Unk02010294 *b) {
    Unk020101e8_08 *s;
    Unk02010294_t *d;
    int r;
    u32 i;
    void *e;
    u8 *t;
    Unk020103c0_e *f;

    s = (Unk020101e8_08 *) ((u8 *) a + a->mUnk_08);
    d = (Unk02010294_t *) ((u8 *) s + s->mUnk_00);
    r = 1;
    for (i = 0; i < d->mUnk_01; i++) {
        t = (u8 *) d + d->mUnk_06;
        e = func_020138b4(b->mUnk_3c, (const u32 *) (t + *(u16 *) (t + 2) + i * 16));
        if (e != 0) {
            t = (u8 *) d + d->mUnk_06;
            f = (Unk020103c0_e *) (t + 4 + *(u16 *) t * i);
            if ((f->mUnk_03 & 1) == 0) {
                func_020106c8(s, f, b, e);
            }
        } else {
            r = 0;
        }
    }
    return r;
}

int func_0201050c(Unk020101e8 *a, Unk02010294 *b, const u32 *k) {
    Unk02010294_t *d;
    Unk020101e8_08 *s;
    void *e;
    Unk020103c0_e *f;

    s = (Unk020101e8_08 *) ((u8 *) a + a->mUnk_08);
    d = (Unk02010294_t *) ((u8 *) s + s->mUnk_00);
    e = func_020138b4(b->mUnk_3c, k);
    if (e != 0) {
        f = func_020138b4(d, k);
        if (f != 0 && (f->mUnk_03 & 1) == 0) {
            func_020106c8(s, f, b, e);
            return 1;
        }
    }
    return 0;
}

void func_020104a4(Unk020101e8 *a) {
    Unk020101e8_08 *s;
    Unk02010294_t *d;
    u8 *t;
    Unk020103c0_e *e;
    u32 i;

    s = (Unk020101e8_08 *) ((u8 *) a + a->mUnk_08);
    d = (Unk02010294_t *) ((u8 *) s + s->mUnk_00);
    for (i = 0; i < d->mUnk_01; i++) {
        t = (u8 *) d + d->mUnk_06;
        e = (Unk020103c0_e *) (t + 4 + *(u16 *) t * i);
        if ((e->mUnk_03 & 1) != 0) {
            func_0201063c(s, e);
        }
    }
}

u32 func_02010458(Unk020101e8 *a, const u32 *k) {
    Unk020101e8_08 *b;
    Unk020103c0_e *e;

    b = (Unk020101e8_08 *) ((u8 *) a + a->mUnk_08);
    e = func_020138b4((u8 *) b + b->mUnk_00, k);
    if (e != 0 && (e->mUnk_03 & 1) != 0) {
        func_0201063c(b, e);
        return 1;
    }
    return 0;
}

void func_020103c0(Unk020101e8_08 *a, Unk020103c0_e *e, Unk02010294 *b, Unk020103c0_d *d) {
    u8 *p;
    u32 x;
    u32 y;
    u32 i;
    u8 *r;
    Unk020103c0_o *o;

    p = (u8 *) a + e->mUnk_00;
    x = (u16) b->mUnk_2c;
    y = d->mUnk_00;
    if ((d->mUnk_02 & 1) == 0) {
        x = (x << 15) >> 16;
        y = (y << 15) >> 16;
    }
    for (i = 0; i < e->mUnk_02; i++) {
        r = (u8 *) a + 4 + a->mUnk_0a;
        o = (Unk020103c0_o *) ((u8 *) a + *(u32 *) (r + *(u16 *) r * p[i] + 4));
        o->mUnk_1c = y + x;
    }
    e->mUnk_03 |= 1;
}

u32 func_02010310(Unk020101e8 *a, Unk02010294 *b) {
    Unk020101e8_08 *c;
    Unk02010294_t *t;
    u8 *d;
    u32 i;
    u32 r;
    void *e;
    Unk020103c0_e *g;

    c = (Unk020101e8_08 *) ((u8 *) a + a->mUnk_08);
    r = 1;
    i = 0;
    t = (Unk02010294_t *) ((u8 *) c + c->mUnk_02);
    for (; i < t->mUnk_01; i++) {
        d = (u8 *) t + t->mUnk_06;
        e = func_020138b4((u8 *) b + b->mUnk_34, (u32 *) (d + ((Unk02010310_d *) d)->mUnk_02 + i * 16));
        if (e != 0) {
            d = (u8 *) t + t->mUnk_06;
            g = (Unk020103c0_e *) (d + 4 + *(u16 *) d * i);
            if ((g->mUnk_03 & 1) == 0) {
                func_020103c0(c, g, b, e);
            }
        } else {
            r = 0;
        }
    }
    return r;
}

u32 func_02010294(Unk020101e8 *a, Unk02010294 *b, const u32 *k) {
    Unk02010294_t *t;
    Unk020101e8_08 *c;
    void *e;
    Unk020103c0_e *g;

    c = (Unk020101e8_08 *) ((u8 *) a + a->mUnk_08);
    t = (Unk02010294_t *) ((u8 *) c + c->mUnk_02);
    e = func_020138b4((u8 *) b + b->mUnk_34, k);
    if (e != 0) {
        g = func_020138b4(t, k);
        if (g != 0 && (g->mUnk_03 & 1) == 0) {
            func_020103c0(c, g, b, e);
            return 1;
        }
    }
    return 0;
}

void func_0201023c(Unk020101e8 *a) {
    Unk020101e8_08 *c;
    Unk02010294_t *t;
    u8 *d;
    Unk020103c0_e *g;
    u32 i;

    c = (Unk020101e8_08 *) ((u8 *) a + a->mUnk_08);
    t = (Unk02010294_t *) ((u8 *) c + c->mUnk_02);
    for (i = 0; i < t->mUnk_01; i++) {
        d = (u8 *) t + t->mUnk_06;
        g = (Unk020103c0_e *) (d + 4 + *(u16 *) d * i);
        if ((g->mUnk_03 & 1) != 0) {
            g->mUnk_03 &= ~1;
        }
    }
}

u32 func_020101e8(Unk020101e8 *a, const u32 *k) {
    Unk020101e8_08 *c;
    Unk020103c0_e *g;

    c = (Unk020101e8_08 *) ((u8 *) a + a->mUnk_08);
    g = func_020138b4((u8 *) c + c->mUnk_02, k);
    if (g != 0 && (g->mUnk_03 & 1) != 0) {
        g->mUnk_03 &= ~1;
        return 1;
    }
    return 0;
}

u32 func_02010168(Unk02010168 *a, Unk02010294 *b) {
    u32 i;
    u32 r;
    u8 *t;
    u16 off;
    u16 st;
    Unk020101e8 *o;

    r = 1;
    i = 0;
    if (i < a->mUnk_09) {
        t = (u8 *) a + 8;
        do {
            off = a->mUnk_0e;
            st = *(u16 *) (t + off);
            o = (Unk020101e8 *) ((u8 *) a + *(u32 *) (t + off + st * i + 4));
            r &= func_02010584(o, b);
            r &= func_02010310(o, b);
            i++;
        } while (i < a->mUnk_09);
    }
    return r;
}

void func_020100fc(Unk02010168 *a) {
    u32 i;
    u8 *t;
    u16 off;
    u16 st;
    Unk020101e8 *o;

    i = 0;
    if (i < a->mUnk_09) {
        t = (u8 *) a + 8;
        do {
            off = a->mUnk_0e;
            st = *(u16 *) (t + off);
            o = (Unk020101e8 *) ((u8 *) a + *(u32 *) (t + off + st * i + 4));
            func_020104a4(o);
            func_0201023c(o);
            i++;
        } while (i < a->mUnk_09);
    }
}

void func_0201000c(Unk0201000c *p) {
    u16 a;
    u8 *b;
    u8 *d;
    u8 *e;

    b = (u8 *) 0x27ffc00;
    d = b + 0x80;
    e = (u8 *) ((u32) d + 0x74);
    a = *(vu16 *) 0x4000006;
    p->mUnk_00 = OS_GetTickLo() | (a << 16);
    p->mUnk_04 = (*(u16 *) (e + 4) << 16) ^ (u32) gTickOverflowCount;
    p->mUnk_08 = *(u32 *) (b + 0x3c) ^ ((gTickOverflowCount >> 32) ^ *(u32 *) e);
    p->mUnk_08 = p->mUnk_08 ^ *(vu32 *) 0x4000600;
    p->mUnk_0c = *(u32 *) (b + 0x1e8);
    p->mUnk_10 = *(u32 *) (b + 0x1ec);
    p->mUnk_14 = *(u32 *) (b + 0x390) ^ (*(u16 *) (b + 0x394) << 16);
    p->mUnk_18 = (*(u16 *) (b + 0x3aa) << 16) | *(u16 *) (b + 0x3ac);
    p->mUnk_1c = *(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8 | (*(u16 *) (b + 0x398) << 16);
}

void InitVramLocks(void) {
    s32 i;

    gVramBankLockedMask = 0;
    for (i = 0; i < 9; i++) {
        gVramBankLockIds[i] = 0;
    }
}

u32 TryLockVramBanks(u32 m, u16 v) {
    u32 s;
    u32 t;
    s32 k;

    s = OS_DisableInterrupts();
    t = m & gVramBankLockedMask;
    while (1) {
        k = 31 - CountLeadingZeros(t);
        if (k < 0) {
            break;
        }
        t &= ~(1 << k);
        if (v != gVramBankLockIds[k]) {
            OS_RestoreInterrupts(s);
            return 0;
        }
    }
    t = m & 0x1ff;
    while (1) {
        k = 31 - CountLeadingZeros(t);
        if (k < 0) {
            break;
        }
        t &= ~(1 << k);
        gVramBankLockIds[k] = v;
        gVramBankLockedMask |= 1 << k;
    }
    OS_RestoreInterrupts(s);
    return 1;
}

void UnlockVramBanks(u32 m, u16 v) {
    u32 t;
    u32 s;
    s32 k;

    s = OS_DisableInterrupts();
    t = m & gVramBankLockedMask & 0x1ff;
    while (1) {
        k = 31 - CountLeadingZeros(t);
        if (k < 0) {
            break;
        }
        t &= ~(1 << k);
        if (v == gVramBankLockIds[k]) {
            gVramBankLockIds[k] = 0;
            gVramBankLockedMask &= ~(1 << k);
        }
    }
    OS_RestoreInterrupts(s);
}

// clang-format off
// Counts the leading zero bits of r0.
asm u32 CountLeadingZeros(u32 a) {
    clz r0, r0
    bx lr
}
// clang-format on
