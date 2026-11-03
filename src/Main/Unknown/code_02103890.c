#include "Main/Unknown/code_02103890.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_021035ac.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_0214a4dc.h"
#include "code_0212c6ac.h"

#pragma thumb on

void func_02104970(void) {
    s32 i;
    u32 *p;
    u32 *q;

    if (data_021759c0->mUnk_08 != 2) {
        return;
    }
    i = 0;
    p = data_0217c6e4;
    q = data_0217c704;
    do {
        *p++ = -1;
        *q++ = 0;
        i++;
    } while (i < 8);
}

#pragma thumb off

// non-matching: registers in the else loop only: the constants 5, 7, 3, 2 sit in r3, r12, r1, r2 instead of
// r2, r3, r0, r1, q[i][0] in r0 instead of r12, and the address and product temporaries in r0, r9, r10 instead of
// r7, r9, r10, r12. 28 words differ, sizes equal.
void func_0210465c(Unk021035ac *p) {
    s16(*q)[2];
    s32 d;
    s32 i;
    s32 k;
    u32 *r;
    s16 x;
    s16 y;

    q = p->mUnk_10;
    d = *(s32 *) data_0217c650 - *(s32 *) data_0217c648;
    if (d < 0) {
        for (i = 0; i < 4; i++) {
            p->mUnk_00[i][1] -= 2;
        }
        return;
    }
    if (d == 0 && data_0217c64c == 0 && p == (Unk021035ac *) data_0217c654) {
        r = (u32 *) func_02108e6c(6);
        func_0212c6f0((Unk0212c400 **) r, 1);
        if ((data_0217c780 & 1) != 0 && data_0217d084.mUnk_0c != 0) {
            if (*r != 0) {
                func_0212c6f0((Unk0212c400 **) r, 0);
            }
            if (*r != 0) {
                func_0212c6f0((Unk0212c400 **) r, 0);
            }
            func_0212ecc0(r, 0, 0xef);
        }
    }
    if (p->mUnk_28 != 0) {
        for (i = 0; i < 4; i++) {
            p->mUnk_00[i][0] += q[i][0];
            p->mUnk_00[i][1] += q[i][1];
            q[i][0] = (s16) (((s64) q[i][0] * 0x10cd) >> 12);
            q[i][1] = (s16) (((s64) q[i][1] * 0x10cd) >> 12);
            x = p->mUnk_00[i][0];
            if (x > 0x3ccd) {
                p->mUnk_00[i][0] = 0x3ccd;
            } else if (x < -0x3ccd) {
                p->mUnk_00[i][0] = -0x3ccd;
            }
            y = p->mUnk_00[i][1];
            if (y > 0x3ccd) {
                p->mUnk_00[i][1] = 0x3ccd;
            } else if (y < -0x3ccd) {
                p->mUnk_00[i][1] = -0x3ccd;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            x = q[i][0];
            y = q[i][1];
            if (y < 0) {
                k = y * y > x * x ? 7 : 5;
                if (i == p->mUnk_30) {
                    k += (k << 1) + ((k * d) >> 9);
                }
            } else {
                k = y * y > x * x ? 2 : 3;
            }
            p->mUnk_00[i][1] = p->mUnk_00[i][1] - (k + ((k * d) >> 8));
            if (p->mUnk_00[i][1] < -0x3ccd) {
                p->mUnk_00[i][1] = -0x3ccd;
            }
        }
    }
    p->mUnk_2c = p->mUnk_2c - 1;
    if ((p->mUnk_2c & 0xf) == 0) {
        Unk020f41c4_B *a = &data_0217561c->mUnk_498;

        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        p->mUnk_30 = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 6) >> 32);
    }
}

void func_021045a4(Unk021035ac *p) {
    s16(*q)[2] = p->mUnk_10;
    s32 i;
    s32 k;
    s16 a;
    s16 b;
    s32 v;

    k = data_0215a48c[-p->mUnk_2c];
    a = p->mUnk_20[0];
    b = p->mUnk_20[1];
    for (i = 0; i < 4; i++) {
        v = q[i][0];
        p->mUnk_00[i][0] = a + (s32) (((s64) v * k) >> 12);
        v = q[i][1];
        p->mUnk_00[i][1] = b + (s32) (((s64) v * k) >> 12);
    }
    p->mUnk_2c = p->mUnk_2c - 1;
    if (p->mUnk_2c == -13) {
        p->mUnk_24 = (void *) func_0210465c;
    }
}

void func_0210449c(Unk021035ac *p) {
    void *r;
    u32 v;

    p->mUnk_2c = p->mUnk_2c - 1;
    if (p->mUnk_2c != 0) {
        return;
    }
    p->mUnk_24 = (void *) func_021045a4;
    if (func_0203c5e4() != 0) {
        return;
    }
    v = data_0217c64c != 0 ? 0x157 : 0xee;
    if (v == 1) {
        return;
    }
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    r = func_0210e128(func_02108ea0(0));
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*(u32 *) r != 0) {
        func_0212c6f0((Unk0212c400 **) r, 0);
    }
    if (*(u32 *) r != 0) {
        func_0212c6f0((Unk0212c400 **) r, 0);
    }
    func_0212ecc0(r, 0, (u16) v);
}

// non-matching: same size; the loop over the 0x34-byte entries allocates r4-r7 differently (the original keeps
// the count pointer in r5, the index in r7 and the offset in r6).
void func_02104368(void) {
    s32 i;
    Unk0210340c *p;
    s32 n;
    u16 h;

    if (*(s32 *) data_0217c658 == 0) {
        return;
    }
    // non-matching: loop temps get swapped registers (mine i=r5/&n=r7/&table=r6/offset=r4,
    // original i=r7/&n=r5/&table=r4/offset=r6; callee also in r0 vs r1)
    for (i = 0; i < *(s32 *) data_0217c658; i++) {
        Unk021035ac *e = &((Unk021035ac *) data_0217c654)[i];

        ((void (*)(void)) e->mUnk_24)();
    }
    n = *(s32 *) data_0217c650 + 1;
    *(s32 *) data_0217c650 = n;
    if (n <= *(s32 *) data_0217c644) {
        return;
    }
    if (n & 1) {
        return;
    }
    h = data_0217c640;
    data_0217c640 = h - 1;
    h = data_0217c640;
    if (h == 0) {
        *(u32 *) data_0217c658 = 0;
        data_0217c64c = 0;
        func_0212c6f0((Unk0212c400 **) func_02108e6c(6), 1);
        return;
    }
    p = data_0217c64c != 0 ? (Unk0210340c *) data_0217c664 : (Unk0210340c *) data_0217c684;
    p->mUnk_04 = p->mUnk_04 & ~0x1f0000;
    p->mUnk_04 = p->mUnk_04 | (h << 16);
}

void func_02104144(Unk0210340c *p) {
    s32 i;

    if (*(u32 *) data_0217c658 == 0) {
        return;
    }
    if (func_0203c5e4() != 0) {
        return;
    }
    *(u16 *) 0x4000060 = (*(u16 *) 0x4000060 & ~0x3000) | 8;
    *(u32 *) 0x40004a8 = p->mUnk_08;
    *(u32 *) 0x40004ac = p->mUnk_0c;
    *(u32 *) 0x40004c0 = p->mUnk_10;
    *(u32 *) 0x40004c4 = p->mUnk_14;
    *(u32 *) 0x4000440 = 0;
    func_0214a530(data_0217c6a4);
    *(u32 *) 0x4000440 = 3;
    *(u32 *) 0x4000454 = 0;
    *(u32 *) 0x4000440 = 2;
    *(u32 *) 0x4000454 = 0;
    *(u32 *) 0x400046c = 0x64000;
    *(u32 *) 0x400046c = 0x64000;
    *(u32 *) 0x400046c = 0x64000;
    i = 0;
    if (*(s32 *) data_0217c658 <= 0) {
        return;
    }
    do {
        Unk021035ac *e = &((Unk021035ac *) data_0217c654)[i];

        *(u32 *) 0x40004a4 = p->mUnk_04 | (data_0217c63c + i) << 24;
        *(u32 *) 0x4000500 = 1;
        *(u32 *) 0x4000488 = 0;
        *(u32 *) 0x400048c = *(u32 *) &e->mUnk_00[0];
        *(u32 *) 0x400048c = 0;
        *(u32 *) 0x4000488 = (u16) ((s32) (p->mUnk_1c << 8) >> 16) << 16;
        *(u32 *) 0x4000494 = *(u32 *) &e->mUnk_00[1];
        *(u32 *) 0x4000488 = (u16) ((s32) (p->mUnk_18 << 8) >> 16) | ((u16) ((s32) (p->mUnk_1c << 8) >> 16) << 16);
        *(u32 *) 0x4000494 = *(u32 *) &e->mUnk_00[2];
        *(u32 *) 0x4000488 = (u16) ((s32) (p->mUnk_18 << 8) >> 16);
        *(u32 *) 0x4000494 = *(u32 *) &e->mUnk_00[3];
        *(u32 *) 0x4000504 = 0;
        i++;
    } while (i < *(s32 *) data_0217c658);
}

void func_02104118(void) {
    func_02104144(data_0217c64c != 0 ? (Unk0210340c *) data_0217c664 : (Unk0210340c *) data_0217c684);
}

// non-matching: the long-lived m5 and the high byte x get swapped registers
// (mine m5=ip / x=r0, original m5=r0 / x=ip); 30 words from +0x2c, all register renames
u8 func_02104000(s32 a, s32 b) {
    s32 m5;
    s32 m3;
    u8 m;
    u8 v;
    u8 x;

    m3 = (1 << (a + 1)) | (1 << (a + 2)) | (1 << (a + 3));
    m5 = m3 | (1 << a) | (1 << (a + 4));
    x = 0;
    if (b > 1) {
        m = m3 >> 3;
        v = data_0217c65c[b - 2];
        x |= v & m;
        data_0217c65c[b - 2] = v | m;
    }
    if (b > 0) {
        m = m5 >> 3;
        v = data_0217c65c[b - 1];
        x |= v & m;
        data_0217c65c[b - 1] = v | m;
    }
    m = m5 >> 3;
    v = data_0217c65c[b];
    x |= v & m;
    data_0217c65c[b] = v | m;
    if (b < 7) {
        m = m5 >> 3;
        v = data_0217c65c[b + 1];
        x |= v & m;
        data_0217c65c[b + 1] = v | m;
    }
    if (b < 6) {
        m = m3 >> 3;
        v = data_0217c65c[b + 2];
        x |= v & m;
        data_0217c65c[b + 2] = v | m;
    }
    return x;
}

// non-matching: same size; 110 words differ from +0x10: registers (the original keeps data_0217561c in r5)
// and the order of the first loads.
void func_02103db0(s32 v1, volatile s32 param_2, s32 param_3) {
    Unk0217561c *b;
    Unk020f41c4_B *a;
    Unk021035ac *e;
    s16(*q)[2];
    s16 c;
    s16 s;
    s32 t;
    s32 i;
    s16 f0;
    s16 f1;

    b = data_0217561c;
    e = &((Unk021035ac *) data_0217c654)[v1];
    a = &b->mUnk_498;
    q = e->mUnk_10;
    a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
    t = (s32) (u16) (((u64) (u32) (a->mUnk_00 >> 32)) >> 16) >> 4;
    c = data_0215d4b4[2 * t];
    s = data_0215d4b4[2 * t + 1];
    if (param_3 != 0) {
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        t = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xcd) >> 32) + 0x800;
    } else {
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        t = 0xa66 + (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x52) >> 32);
    }
    if (data_0217c64c != 0) {
        t = (s16) (((s64) t * 0x800) >> 12);
    }
    e->mUnk_2c = data_0215a47c[v1];
    t = (s16) t;
    q[0][0] = -t;
    q[0][1] = -t;
    q[1][0] = -t;
    q[1][1] = t;
    q[2][0] = t;
    q[2][1] = t;
    q[3][0] = t;
    q[3][1] = -t;
    for (i = 0; i < 4; i++) {
        f1 = q[i][1];
        f0 = q[i][0];
        q[i][0] = (f0 * s - f1 * c) >> 12;
        q[i][1] = (f0 * c + f1 * s) >> 12;
        *(u32 *) &e->mUnk_00[(u32) i] = param_2;
    }
    *(u32 *) &e->mUnk_20 = param_2;
    e->mUnk_24 = (void *) func_0210449c;
    e->mUnk_30 = -1;
    e->mUnk_28 = 0;
}

// non-matching: 0x4c4 bytes against 0x4b0. The scalings are `((u64) ... * 0x1000) >> 32` (`>> 20` gives lsr/orr, the
// original has lsl/orr). Left: the original reads the low word of a->mUnk_00 once for the scaling and the next random
// step (here again after the halfword store), and the u64 multiply-add temporaries are in other registers.
void func_02103900(s32 v1, s32 n, s32 v2) {
    volatile s16 a8;
    volatile s16 a10;
    s32 i;
    s32 j;
    s32 m;
    s32 t8;
    s32 t10;
    Unk0210340c *p;
    Unk020f41c4_B *a;

    a = &data_0217561c->mUnk_498;
    func_0207a974(v1);
    if (v1 != data_021759c0->mUnk_62) {
        return;
    }
    data_0217c638 = v1;
    if (*(s32 *) data_0217c658 != 0) {
        if (v2 != 0) {
            return;
        }
    }
    *(s32 *) data_0217c658 = 0;
    data_0217c64c = 0;
    func_0212c6f0((Unk0212c400 **) func_02108e6c(6), 1);
    data_0217c64c = v2;
    for (i = 0; i < 8; i++) {
        data_0217c65c[i] = 0;
    }
    j = 0;
    m = 1;
    for (i = 0; i < 0x10 && j < n; i++) {
        if (data_0217c64c != 0) {
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            a8 = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x1000) >> 32) * 2;
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            a10 = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xc00) >> 32) * 2;
        } else if (*(s32 *) data_0217c658 == 0) {
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            a8 = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x1000) >> 32);
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            a8 = a8 + (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x1000) >> 32);
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            a10 = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xc00) >> 32);
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            a10 = a10 + (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xc00) >> 32);
        } else {
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            a8 = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x2000) >> 32);
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            a10 = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x1800) >> 32);
        }
        t8 = a8 >> 10;
        t10 = a10 >> 10;
        if (t10 >= 3 || t8 < 3 || t8 > 4) {
            if ((data_0217c65c[t10] & (m << t8)) == 0) {
                s32 r = func_02104000(t8, t10);

                a8 = a8 - 0x1000;
                a10 = a10 - 0x600;
                func_02103db0(j, *(s32 *) &a8, r);
                j++;
            }
        }
    }
    *(s32 *) data_0217c658 = j;
    *(u32 *) data_0217c650 = 0;
    data_0217c640 = 0x1f;
    if (data_0217c64c != 0) {
        p = (Unk0210340c *) data_0217c664;
        p->mUnk_04 = p->mUnk_04 & ~0x1f0000;
        p->mUnk_04 = p->mUnk_04 | 0x1f0000;
        *(u32 *) data_0217c644 = 0x96;
        *(u32 *) data_0217c648 = 0x1e;
    } else {
        p = (Unk0210340c *) data_0217c684;
        p->mUnk_04 = p->mUnk_04 & ~0x1f0000;
        p->mUnk_04 = p->mUnk_04 | 0x1f0000;
        *(u32 *) data_0217c644 = 0x184;
        *(u32 *) data_0217c648 = 0x2d;
    }
}

void func_021038f0(u32 param_1, u32 param_2) {
    func_02103900(param_1, param_2, 0);
}

void func_02103890(int v1) {
    if (v1 != data_021759c0->mUnk_62) {
        return;
    }
    *(u32 *) data_0217c658 = 0;
    data_0217c64c = 0;
    func_0212c6f0((Unk0212c400 **) func_02108e6c(6), 1);
}
