#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36a0.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020ff344.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_020f81b8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0205a000.h"
#include "01/code_02187d14.h" // data_0217c600

#pragma thumb off

u8 *func_020ff2b0(u8 *a, Unk020ff438 *b, void *c) {
    u8 *p;

    if (b != 0 && c != 0) {
        func_020ff1b8(b->mUnk_13c, &b->mUnk_000.mUnk_000.mUnk_5c.y);
    }
    p = func_020fecdc(a, b, c);
    if (b != 0 && c == 0) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_5c.y, &b->mUnk_13c);
    }
    if (b != 0 && c != 0) {
        return func_020fe8ac(b->mUnk_000.mUnk_000.mUnk_44);
    }
    return p;
}

void func_020ff25c(Unk020ff438 *a) {
    func_020f8e78(a);
    func_020f2d98((u32) a, 0);
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 0x10000000) == 0) {
        return;
    }
    if (a->mUnk_13c == 0) {
        return;
    }
    func_021090c4(&a->mUnk_000.mUnk_000.mUnk_00, 0xda, 0x7f, 0);
}

#pragma thumb on

void func_020ff1d8(void) {
    Vec3 v;
    Unk027e00cc *p;
    Unk020ff438 *o;
    Unk020f41c4_A **e;
    s32 n;
    s32 i;

    if (data_0217bc48[3].mUnk_00 == 0) {
        return;
    }
    v = data_0216c734;
    func_02146f98(&data_0217c600, &v, 0xb50, 0xb50);
    p = &data_027e00cc[7];
    e = p->mUnk_04;
    n = p->mUnk_08;
    for (i = 0; i < n; i++) {
        o = (Unk020ff438 *) e[0];
        o->mUnk_140 = (Unk021052fc *) func_0210543c();
        o->mUnk_140->mUnk_fc = &o->mUnk_000.mUnk_000.mUnk_50;
        e++;
    }
    p->mUnk_40 = 1;
}

#pragma thumb off

void func_020ff1b8(s32 a, s32 *p) {
    if (a != 0) {
        *p |= 0x200;
    } else {
        *p &= ~0x200;
    }
}

void func_020ff1a0(s32 a, s32 *p) {
    if (a & 0x200) {
        *p = 1;
    } else {
        *p = 0;
    }
}

s32 func_020ff178(Unk020f41c4_A *p) {
    return (s16) (((s16) (u16) (p->mUnk_78 & ~0xff00) << 4) | p->mUnk_4c);
}

static inline u8 *func_020ff0b0_inline(u8 *p, volatile s32 *t, void *c, s32 n) {
    if (c != 0) {
        *p = *t >> n;
    } else {
        *t = *(s8 *) p << n;
    }
    return p + 1;
}

u8 *func_020ff0b0(u8 *a, Vec3 *b, Vec3 *q, void *c) {
    volatile s32 t[3];

    if (q != 0) {
        if (c != 0) {
            func_021484d0(q, b, (Vec3 *) t);
        }
        a = func_020ff0b0_inline(a, &t[0], c, 10);
        a = func_020ff0b0_inline(a, &t[1], c, 9);
        a = func_020ff0b0_inline(a, &t[2], c, 10);
        if (c == 0) {
            func_02148504((Vec3 *) t, b, q);
        }
    } else {
        a++;
        a = (u8 *) a + 1;
        a++;
    }
    return a;
}

u8 *func_020ff040(u8 *a, void *b, void *c) {
    volatile u8 v;

    if (b != 0) {
        if (c != 0) {
            v = func_020f36d8((Unk020f36d8 *) b);
        }
        if (c != 0) {
            *(u8 *) a = v;
        } else {
            v = *(u8 *) a;
        }
        a++;
        if (c == 0) {
            func_020f36a0(v, b);
        }
    } else {
        a++;
    }
    return a;
}

u8 *func_020fefe8(u8 *a, s32 *b, void *c) {
    volatile s32 t;

    if (b != 0) {
        if (c != 0) {
            t = *b;
        }
        if (c != 0) {
            *(u8 *) a = t >> 9;
        } else {
            t = *(s8 *) a << 9;
        }
        a++;
        if (c == 0) {
            *b = t;
        }
    } else {
        a++;
    }
    return a;
}

// non-matching: 0x29c bytes against 0x30c. The original keeps every advanced cursor as its own value
// (add r1, r0, #1 and the following fields addressed as [r1, #n]) and forms each vector component's address
// first (add r2, r0, #4 / [r2]); this compiler coalesces the advances into the cursor register and addresses the
// later fields and components as [r0, #n] / [r2, #4]; t1 is read with ldrsb where the original has ldrb.
u8 *func_020fecdc(u8 *a, void *b, void *c) {
    volatile s8 t1;
    volatile u16 t2;
    Unk020f41c4_A *e;
    void *p;
    Vec3 *v;
    Vec3 *w;

    e = b;

    if (b != 0 && c != 0) {
        a = data_0217bd6c + 1;
    }
    p = b != 0 ? &e->mUnk_4e : 0;
    if (p != 0) {
        if (c != 0) {
            t1 = *(s16 *) p;
        }
        if (c != 0) {
            *a = t1;
        } else {
            t1 = *a;
        }
        if (c == 0) {
            *(s16 *) p = t1;
        }
    }
    a++;
    p = b != 0 ? &e->mUnk_74 : 0;
    if (p != 0) {
        if (c != 0) {
            t2 = *(u32 *) p >> 12;
        }
        if (c != 0) {
            *(u16 *) a = t2;
        } else {
            t2 = *(u16 *) a;
        }
        if (c == 0) {
            *(u32 *) p = t2 << 12;
        }
    }
    a += 2;
    v = b != 0 ? &e->mUnk_50 : 0;
    if (v != 0) {
        w = b != 0 ? &e->mUnk_50 : 0;
        if (w != 0) {
            if (c != 0) {
                *(s16 *) a = w->x >> 9;
            } else {
                w->x = *(s16 *) a << 9;
            }
        }
    }
    a += 2;
    v = b != 0 ? &e->mUnk_50 : 0;
    if (v != 0) {
        w = b != 0 ? &e->mUnk_50 : 0;
        if (w != 0) {
            if (c != 0) {
                *(s16 *) a = w->y >> 9;
            } else {
                w->y = *(s16 *) a << 9;
            }
        }
    }
    a += 2;
    v = b != 0 ? &e->mUnk_50 : 0;
    if (v != 0) {
        w = b != 0 ? &e->mUnk_50 : 0;
        if (w != 0) {
            if (c != 0) {
                *(s16 *) a = w->z >> 9;
            } else {
                w->z = *(s16 *) a << 9;
            }
        }
    }
    a = func_020ff0b0(a + 2, b != 0 ? &e->mUnk_50 : 0, b != 0 ? &e->mUnk_0e4 : 0, c);
    v = b != 0 ? &e->mUnk_5c : 0;
    if (v != 0) {
        w = b != 0 ? &e->mUnk_5c : 0;
        if (w != 0) {
            if (c != 0) {
                *a = w->x >> 10;
            } else {
                w->x = *(s8 *) a << 10;
            }
        }
    }
    a++;
    v = b != 0 ? &e->mUnk_5c : 0;
    if (v != 0) {
        w = b != 0 ? &e->mUnk_5c : 0;
        if (w != 0) {
            if (c != 0) {
                *a = w->y >> 9;
            } else {
                w->y = *(s8 *) a << 9;
            }
        }
    }
    a++;
    v = b != 0 ? &e->mUnk_5c : 0;
    if (v != 0) {
        w = b != 0 ? &e->mUnk_5c : 0;
        if (w != 0) {
            if (c != 0) {
                *a = w->z >> 10;
            } else {
                w->z = *(s8 *) a << 10;
            }
        }
    }
    a++;
    p = b != 0 ? &e->mUnk_78 : 0;
    if (p != 0) {
        if (c != 0) {
            *(u16 *) a = *(u16 *) p;
        } else {
            *(u16 *) p = *(u16 *) a;
        }
    }
    return a + 2;
}

void func_020fec30(void) {
    u32 v1;
    s32 n;
    u32 v2;
    Unk0217be00 *p;

    v1 = data_0217bd60[0];
    if (v1 == 0xff) {
        return;
    }
    do {
        n = data_0217aa14->mUnk_724;
        v2 = data_0217bd80[v1][0];
        if (n < data_0217bd80[v1][1]) {
            return;
        }
        if (func_0205ad44() == 0) {
            return;
        }
        data_0217bd60[0] = v2;
        data_0217bd80[v1][0] = data_0217bd64[0];
        data_0217bd64[0] = v1;
        p = &data_0217be00[v1];
        func_0205a858(p->mUnk_14, p->mUnk_18, p, data_0217bd80[v1][1]);
        v1 = v2;
    } while (v2 != 0xff);
}

// non-matching: 0xe8 bytes against 0xec. The original reads the second byte of the row twice (ldrb r1 and ldrb r2,
// both [r3, #1]: one for the decrement, one for the test) and stores the first byte of the row through
// `lsl r2, r0, #1` / `strb r1, [r7, r2]`; this compiler reads it once and stores through [r7, r3, lsl #1]. v1, v3 and
// v4 also take other registers (the original has v1 in r10, v3 in r9, v4 in r8).
void func_020feb44(void) {
    s32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 h;
    Unk0217be00 *p;

    v1 = func_02061fb8();
    v2 = data_0217bd68[0];
    v3 = 0xff;
    while (v2 != 0xff) {
        v5 = data_0217bdc0[v2][1];
        v4 = data_0217bdc0[v2][0];
        data_0217bdc0[v2][1] = v5 - 1;
        if (v5 == 0) {
            h = data_0217bd5c[0];
            if (v3 == 0xff) {
                data_0217bd68[0] = v4;
            }
            data_0217bdc0[v2][0] = h;
            data_0217bd5c[0] = v2;
            if (v3 != 0xff) {
                data_0217bdc0[v3][0] = v4;
            }
            p = &data_0217c200[v2];
            if (p->mUnk_1c == 0 || (u32) (p->mUnk_1c + 0x100) >= (u32) v1) {
                func_020f0758(data_027e00cc + p->mUnk_14, p->mUnk_18, 0, (u8 *) p, p->mUnk_1c);
            }
        } else {
            v3 = v2;
        }
        v2 = v4;
    }
}

void func_020fea84(u32 a, u32 b, void *c, u8 d) {
    u32 v1;
    Unk0217be00 *p;

    v1 = data_0217bd64[0];
    if (v1 == 0xff) {
        return;
    }
    p = &data_0217be00[v1];
    p->mUnk_14 = a;
    p->mUnk_18 = b;
    func_0214d1fc(c, p, d);
    data_0217bd64[0] = data_0217bd80[v1][0];
    if (data_0217bd60[0] == 0xff) {
        data_0217bd60[0] = v1;
    } else {
        u32 i;
        u8 t;

        i = data_0217bd60[0];
        t = data_0217bd80[i][0];
        while (t != 0xff) {
            i = t;
            t = data_0217bd80[i][0];
        }
        data_0217bd80[i][0] = v1;
    }
    data_0217bd80[v1][0] = 0xff;
    data_0217bd80[v1][1] = d;
}

void func_020fe9d0(u32 a, u32 b, s32 c, void *d, u32 e) {
    u32 v1;
    Unk0217be00 *p;

    v1 = data_0217bd5c[0];
    if (v1 == 0xff) {
        return;
    }
    p = &data_0217c200[v1];
    p->mUnk_14 = a;
    p->mUnk_18 = b;
    p->mUnk_1c = e;
    func_0214d1fc(d, p, 0x14);
    data_0217bd5c[0] = data_0217bdc0[v1][0];
    data_0217bdc0[v1][0] = data_0217bd68[0];
    if (e != 0) {
        data_0217bdc0[v1][1] = 4;
    } else {
        data_0217bdc0[v1][1] = -c;
    }
    data_0217bd68[0] = v1;
}

u8 *func_020fe958(u32 a) {
    s32 n;

    data_0217bd6c[0] = func_02061fb8();
    n = data_0217aa14->mUnk_724;
    if (n >= 1 && func_0205ad44() != 0) {
        func_0205a858(a, 0, data_0217bd6c, 1);
    } else {
        func_020fea84(a, 0, data_0217bd6c, 1);
    }
    return data_0217bd6c;
}

u8 *func_020fe8ac(u32 a) {
    u32 b;
    s32 n;

    b = data_0217bc34[a].mUnk_4c & 0xff;
    data_0217bd6c[0] = func_02061fb8();
    n = data_0217aa14->mUnk_724;
    if (n >= (u8) (b + 1) && func_0205ad44() != 0) {
        func_0205a858(a, 0, data_0217bd6c, b + 1);
    } else {
        func_020fea84(a, 0, data_0217bd6c, b + 1);
    }
    return data_0217bd6c;
}

u8 *func_020fe828(u32 a) {
    s32 n;

    data_0217bd6c[1] = 0xff;
    data_0217bd6c[0] = func_02061fb8();
    n = data_0217aa14->mUnk_724;
    if (n >= 2 && func_0205ad44() != 0) {
        func_0205a858(a, 0, data_0217bd6c, 2);
    } else {
        func_020fea84(a, 0, data_0217bd6c, 2);
    }
    return data_0217bd6c;
}

u8 *func_020fe7a0(u32 a, u32 b, u32 c, u32 d) {
    s32 n;

    data_0217bd6c[1] = d;
    data_0217bd6c[2] = b | (c << 4);
    data_0217bd6c[0] = func_02061fb8();
    n = data_0217aa14->mUnk_724;
    if (n >= 3 && func_0205ad44() != 0) {
        func_0205a858(a, 2, data_0217bd6c, 3);
    } else {
        func_020fea84(a, 2, data_0217bd6c, 3);
    }
    return data_0217bd6c;
}

u8 *func_020fe71c(u32 a, u32 b, u32 c) {
    s32 n;

    data_0217bd6c[1] = c;
    data_0217bd6c[2] = b;
    data_0217bd6c[0] = func_02061fb8();
    n = data_0217aa14->mUnk_724;
    if (n >= 3 && func_0205ad44() != 0) {
        func_0205a858(a, 3, data_0217bd6c, 3);
    } else {
        func_020fea84(a, 3, data_0217bd6c, 3);
    }
    return data_0217bd6c;
}

u8 *func_020fe694(u32 a, u32 b, u32 c, u32 d) {
    s32 n;

    data_0217bd6c[1] = b;
    data_0217bd6c[2] = c;
    data_0217bd6c[3] = d;
    data_0217bd6c[0] = func_02061fb8();
    n = data_0217aa14->mUnk_724;
    if (n >= 4 && func_0205ad44() != 0) {
        func_0205a858(a, 3, data_0217bd6c, 4);
    } else {
        func_020fea84(a, 3, data_0217bd6c, 4);
    }
    return data_0217bd6c;
}

void func_020fe5b8(u32 a, u32 b, u8 *c, u32 d) {
    s8 v;

    v = (u8) func_02061fb8() - c[0];
    if (v >= 0) {
        func_020f0758(data_027e00cc + a, b, v, c, 0);
    } else {
        func_020fe9d0(a, b, v, c, 0);
    }
    if (a != 0xb) {
        return;
    }
    if (b != 0) {
        return;
    }
    if (c[1] == 0xff) {
        return;
    }
    func_020f81b8((u32) & (data_027e00c8)[(u16) d], 0x10);
}

void func_020fe56c(u32 a, u32 b, u32 c, void *d, u32 e) {
    u32 v;

    v = e;
    if (v == 0) {
        v = func_02061fb8();
    }
    func_020fe9d0(a, b, c, d, v);
}

void *func_020fe4c0(void *a, void *b, s32 c) {
    Unk020f41c4_A *e;
    u8 *p;
    s32 t;
    s32 n;

    e = b;
    p = func_020fecdc(a, b, (void *) c);
    if (b == 0) {
        return p;
    }
    if (c == 0) {
        return p;
    }
    t = e->mUnk_44;
    data_0217bd6c[0] = func_02061fb8();
    n = data_0217aa14->mUnk_724;
    if (n >= 0x12 && func_0205ad44() != 0) {
        func_0205a858(t, 1, data_0217bd6c, 0x12);
    } else {
        func_020fea84(t, 1, data_0217bd6c, 0x12);
    }
    return data_0217bd6c;
}

void func_020fe4b4(void *p) {
    func_020f8e78(p);
}
