#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "code_0214259c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "Main/Unknown/unk_0216f000.h"

s32 func_02144514(Unk021425e8Func a, void *b, u32 c) {
    Unk02142aa8 *p;
    s32 r;

    p = func_02142aa8();
    r = func_02142988(1, 8);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_010, 4);
    if (p->mUnk_004->mUnk_010 == 1) {
        return 3;
    }
    if (c < 0x10) {
        return 6;
    }
    if (b == 0) {
        return 6;
    }
    func_0200ee58(b, c);
    func_02142c0c(0x11, (u32) a);
    r = func_02142ab8(0x11, 2, b, c);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02144438(Unk021425e8Func a, const void *b, void *c, u32 d) {
    Unk02142aa8 *p;
    s32 r;
    u32 w[2];

    p = func_02142aa8();
    r = func_02142988(1, 11);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_010, 4);
    if (p->mUnk_004->mUnk_010 == 0) {
        return 3;
    }
    if (d > 0x5e4) {
        return 6;
    }
    func_0200ee58(c, d);
    func_02142c0c(0x12, (u32) a);
    MemCopy(b, w, 6);
    r = func_02142ab8(0x12, 4, w[0], w[1], c, d);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_021443b0(Unk021425e8Func a) {
    Unk02142aa8 *p;
    s32 r;

    p = func_02142aa8();
    r = func_02142988(1, 11);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_010, 4);
    if (p->mUnk_004->mUnk_010 == 0) {
        return 3;
    }
    func_02142c0c(0x13, (u32) a);
    r = func_02142ab8(0x13, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02144230(Unk021425e8Func a, u32 b, s32 c, u32 d, u16 e, u16 f, u16 g, u32 h, u32 i, u32 j, u32 k) {
    Unk02142aa8 *p;
    s32 r;
    s32 w;

    p = func_02142aa8();
    r = func_02142988(2, 7, 8);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_184, 2);
    func_0200ee3c(&p->mUnk_004->mUnk_0c2, 2);
    if (p->mUnk_004->mUnk_184 != 0) {
        if (p->mUnk_004->mUnk_0c2 != 1) {
            return 3;
        }
    }
    func_0200ee3c(&p->mUnk_004->mUnk_00c, 4);
    if (p->mUnk_004->mUnk_00c == 1) {
        return 3;
    }
    if (c < func_021433b0()) {
        return 6;
    }
    if ((c & 0x3f) != 0) {
        return 6;
    }
    w = e;
    if (w < func_0214349c()) {
        return 6;
    }
    if ((w & 0x1f) != 0) {
        return 6;
    }
    func_02142c0c(0xe, (u32) a);
    r = func_02142ab8(0xe, 10, b, (u32) c >> 1, d, e, f, g, h, i, j, k);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_021441d0(Unk021425e8Func a, u32 b) {
    s32 r;

    func_02142aa8();
    r = func_02142988(1, 9);
    if (r != 0) {
        return r;
    }
    func_02142c0c(0x23, (u32) a);
    r = func_02142ab8(0x23, 1, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02144048(UnkFunc *a, void *b, void *c, s32 d, u16 e, u16 f, u16 g) {
    u16 v;
    u32 w;
    Unk02142988 *q;
    s32 r;
    s32 flag;

    w = 1;
    q = func_02142aa8()->mUnk_004;
    r = func_02142988(2, 9, 10);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&q->mUnk_18e, 2);
    v = q->mUnk_18e;
    func_0200ee3c(&q->mUnk_184, 2);
    flag = q->mUnk_184 == 0 ? w : 0;
    if (flag == 1) {
        func_0200ee3c(&q->mUnk_17e, 2);
        w = q->mUnk_17e;
        func_0200ee3c(&q->mUnk_086, 2);
    }
    if (c == 0) {
        return 6;
    }
    if (w == 0) {
        return 7;
    }
    func_0200ee3c(&q->mUnk_050, 2);
    if (c == q->mUnk_050) {
        return 6;
    }
    if (d + (flag != 0 ? 4 : 2) > v) {
        return 6;
    }
    if (d == 0) {
        return 6;
    }
    func_0200ee58(c, d);
    r = func_02142ab8(0xf, 7, c, d, e, f, g, a, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143fbc(Unk021425e8Func a) {
    Unk02142aa8 *p;
    s32 r;

    p = func_02142aa8();
    r = func_02142988(2, 9, 10);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_00c, 4);
    if (p->mUnk_004->mUnk_00c == 0) {
        return 3;
    }
    func_02142c0c(0x10, (u32) a);
    r = func_02142ab8(0x10, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143f50(Unk021425e8Func a) {
    Unk02142aa8 *p;
    s32 r;

    r = func_02142988(1, 0);
    if (r != 0) {
        return r;
    }
    func_02142c0c(3, (u32) a);
    p = func_02142aa8();
    r = func_02142ab8(3, 3, p->mUnk_000, p->mUnk_004, p->mUnk_010);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143f08(Unk021425e8Func a) {
    s32 r;

    r = func_02142988(1, 1);
    if (r != 0) {
        return r;
    }
    func_02142c0c(4, (u32) a);
    r = func_02142ab8(4, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143ec0(Unk021425e8Func a) {
    s32 r;

    r = func_02142988(1, 1);
    if (r != 0) {
        return r;
    }
    func_02142c0c(5, (u32) a);
    r = func_02142ab8(5, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143e78(Unk021425e8Func a) {
    s32 r;

    r = func_02142988(1, 2);
    if (r != 0) {
        return r;
    }
    func_02142c0c(6, (u32) a);
    r = func_02142ab8(6, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143e10(void *a, Unk021425e8Func b, u32 c) {
    Unk02142aa8 *p;
    s32 r;

    r = func_02142e78(a, c);
    if (r != 0) {
        return r;
    }
    func_02142c0c(0, (u32) b);
    p = func_02142aa8();
    r = func_02142ab8(0, 3, p->mUnk_000, p->mUnk_004, p->mUnk_010);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143dd0(Unk021425e8Func a) {
    s32 r;

    r = func_02142a30();
    if (r != 0) {
        return r;
    }
    func_02142c0c(1, (u32) a);
    r = func_02142ab8(1, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143d88(Unk021425e8Func a) {
    s32 r;

    r = func_02142988(1, 2);
    if (r != 0) {
        return r;
    }
    func_02142c0c(2, (u32) a);
    r = func_02142ab8(2, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143c80(Unk021425e8Func a, Unk02143c30 *b) {
    s32 r;

    r = func_02142988(1, 2);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    if (b->mUnk_04 != 0) {
        if (b->mUnk_00 == 0) {
            return 6;
        }
    }
    if (b->mUnk_34 + (b->mUnk_14 != 0 ? 0x2a : 0) > 0x200 || b->mUnk_36 + (b->mUnk_14 != 0 ? 6 : 0) > 0x200) {
        return 6;
    }
    func_02143c30(b);
    func_02142c0c(7, (u32) a);
    func_0200ee58(b, 0x40);
    if (b->mUnk_04 != 0) {
        func_0200ee58(b->mUnk_00, b->mUnk_04);
    }
    r = func_02142ab8(7, 1, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

u32 func_02143c30(const Unk02143c30 *a) {
    if (a->mUnk_04 > 0x70) {
        return 0;
    }
    if (a->mUnk_18 < 10 || a->mUnk_18 > 0x3e8) {
        return 0;
    }
    if (a->mUnk_32 < 1 || a->mUnk_32 > 0xe) {
        return 0;
    }
    return 1;
}

s32 func_02143bd4(Unk021425e8Func a, u32 b) {
    s32 r;

    r = func_02142988(1, 2);
    if (r != 0) {
        return r;
    }
    func_02142c0c(8, (u32) a);
    r = func_02142ab8(8, 1, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143bc4(Unk021425e8Func a) {
    return func_02143bd4(a, 1);
}

s32 func_02143b7c(Unk021425e8Func a) {
    s32 r;

    r = func_02142988(1, 7);
    if (r != 0) {
        return r;
    }
    func_02142c0c(9, (u32) a);
    r = func_02142ab8(9, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143a78(Unk021425e8Func a, Unk02143a78 *b) {
    Unk02143a78_0c *pk;
    s32 r;

    r = func_02142988(3, 2, 3, 5);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    if (b->mUnk_00 == 0) {
        return 6;
    }
    if (b->mUnk_04 < 1 || b->mUnk_04 > 0xe) {
        return 6;
    }
    func_02142c0c(0xa, (u32) a);
    pk = (Unk02143a78_0c *) func_02142aa8()->mUnk_00c;
    pk->mUnk_00 = 0xa;
    pk->mUnk_02 = b->mUnk_04;
    pk->mUnk_04 = b->mUnk_00;
    pk->mUnk_08 = b->mUnk_06;
    pk->mUnk_0a[0] = b->mUnk_08[0];
    pk->mUnk_0a[1] = b->mUnk_08[1];
    pk->mUnk_0a[2] = b->mUnk_08[2];
    pk->mUnk_0a[3] = b->mUnk_08[3];
    pk->mUnk_0a[4] = b->mUnk_08[4];
    pk->mUnk_0a[5] = b->mUnk_08[5];
    r = func_02142ab8(0xa, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_021438f0(Unk021425e8Func a, Unk021438f0 *b) {
    Unk021438f0_0c *pk;
    s32 r;
    u16 t;

    r = func_02142988(3, 2, 3, 5);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    if (b->mUnk_00 == 0) {
        return 6;
    }
    if (b->mUnk_04 > 0x400) {
        return 6;
    }
    if (b->mUnk_12 > 0x20) {
        return 6;
    }
    t = b->mUnk_10;
    if (t != 0 && t != 1 && t != 2 && t != 3) {
        return 6;
    }
    if ((u16) (t + 0xfffe) <= 1) {
        if (b->mUnk_34 > 0x20) {
            return 6;
        }
    }
    func_02142c0c(0x26, (u32) a);
    pk = (Unk021438f0_0c *) func_02142aa8()->mUnk_00c;
    pk->mUnk_00 = 0x26;
    pk->mUnk_02 = b->mUnk_06;
    pk->mUnk_04 = b->mUnk_00;
    pk->mUnk_08 = b->mUnk_04;
    pk->mUnk_0a = b->mUnk_08;
    MemCopy(b->mUnk_0a, pk->mUnk_0c, 6);
    pk->mUnk_12 = b->mUnk_10;
    pk->mUnk_36 = b->mUnk_34;
    pk->mUnk_14 = b->mUnk_12;
    MemCopy(b->mUnk_14, pk->mUnk_16, 0x20);
    r = func_02142ab8(0x26, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_021438a8(Unk021425e8Func a) {
    s32 r;

    r = func_02142988(1, 5);
    if (r != 0) {
        return r;
    }
    func_02142c0c(0xb, (u32) a);
    r = func_02142ab8(0xb, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_021437d8(Unk021425e8Func a, u16 *b, void *c, u32 d, u16 e) {
    Unk021437d8 *pk;
    s32 r;

    r = func_02142988(1, 2);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    func_0200ee58(b, b[0] * 2);
    func_02142c0c(0xc, (u32) a);
    pk = (Unk021437d8 *) func_02142aa8()->mUnk_00c;
    pk->mUnk_00 = 0xc;
    pk->mUnk_04 = b;
    if (c != 0) {
        MemCopy(c, pk->mUnk_08, 0x18);
    } else {
        MemFill(pk->mUnk_08, 0, 0x18);
    }
    pk->mUnk_20 = d;
    pk->mUnk_26 = e;
    r = func_02142ab8(0xc, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_021436d0(Unk021425e8Func a, u32 b) {
    Unk02142aa8 *p;
    s32 r;

    p = func_02142aa8();
    r = func_02142988(5, 7, 9, 8, 10, 11);
    if (r != 0) {
        return r;
    }
    if (p->mUnk_004->mUnk_000 == 7 || p->mUnk_004->mUnk_000 == 9) {
        if (b < 1 || b > 0xf) {
            return 6;
        }
        func_0200ee3c(&p->mUnk_004->mUnk_17e, 2);
        if ((p->mUnk_004->mUnk_17e & (1 << b)) == 0) {
            return 7;
        }
    } else if (b != 0) {
        return 6;
    }
    func_02142c0c(0xd, (u32) a);
    r = func_02142ab8(0xd, 1, 1 << b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_02143634(Unk021425e8Func a, u32 b) {
    Unk02142aa8 *p;
    s32 r;

    p = func_02142aa8();
    r = func_02142988(2, 7, 9);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_17e, 2);
    if ((p->mUnk_004->mUnk_17e & b & 0xfffe) == 0) {
        return 7;
    }
    func_02142c0c(0xd, (u32) a);
    r = func_02142ab8(0xd, 1, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_021435e8(Unk021425e8Func a) {
    u32 s;
    s32 r;

    s = IrqDisable();
    r = func_02142a8c();
    if (r != 0) {
        IrqRestore(s);
        return r;
    }
    func_02142aa8()->mUnk_0c0 = a;
    IrqRestore(s);
    return 0;
}

s32 func_0214358c(u32 n, UnkFunc *f, void *arg) {
    u32 s;
    s32 r;
    Unk02142aa8 *p;

    s = IrqDisable();
    r = func_02142a8c();
    if (r != 0) {
        IrqRestore(s);
        return r;
    }
    p = func_02142aa8();
    p->mUnk_0c4[n] = f;
    p->mUnk_104[n] = arg;
    IrqRestore(s);
    return 0;
}

s32 func_02143520(void *a) {
    Unk02142aa8 *p;
    s32 r;

    p = func_02142aa8();
    r = func_02142a8c();
    if (r != 0) {
        return r;
    }
    if (a == 0) {
        return 6;
    }
    func_0200ee3c(p->mUnk_004, 0x7bc);
    MemCopyWordsByBlock(p->mUnk_004, a, 0x7bc);
    return 0;
}

s32 func_0214349c(void) {
    Unk02142aa8 *p;

    p = func_02142aa8();
    if (func_02142988(2, 7, 8) != 0) {
        return 0;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_00c, 4);
    if (p->mUnk_004->mUnk_00c == 1) {
        return 0;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_18e, 4);
    return (p->mUnk_004->mUnk_18e + 0x1f) & ~0x1f;
}

s32 func_021433b0(void) {
    Unk02142aa8 *p;
    s32 f;
    u16 v;

    p = func_02142aa8();
    if (func_02142988(2, 7, 8) != 0) {
        return 0;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_00c, 4);
    if (p->mUnk_004->mUnk_00c == 1) {
        return 0;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_184, 2);
    if (p->mUnk_004->mUnk_184 == 0) {
        f = 1;
    } else {
        f = 0;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_190, 2);
    v = p->mUnk_004->mUnk_190;
    if (f != 1) {
        return ((v + 0x51) & ~0x1f) << 1;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_0f4, 2);
    return (((v + 0xc) * p->mUnk_004->mUnk_0f4 + 0x29) & ~0x1f) << 1;
}

void *func_021432ac(const Unk021432ac *a, u32 b) {
    Unk02142aa8 *p;
    u32 ptrs[16];
    s32 i;

    p = func_02142aa8();
    if (func_02142a8c() != 0) {
        return 0;
    }
    if (b < 1 || b > 0xf) {
        return 0;
    }
    func_0200ee3c(&p->mUnk_004->mUnk_17e, 2);
    if ((p->mUnk_004->mUnk_17e & (1 << b)) == 0) {
        return 0;
    }
    if (a->mUnk_04 == 0) {
        return 0;
    }
    ptrs[0] = (u32) a->mUnk_0a;
    i = 0;
    do {
        if (b == *(u16 *) (ptrs[i] + 4)) {
            return (void *) ptrs[i];
        }
        i++;
        ptrs[i] = a->mUnk_06 + ptrs[i - 1];
    } while (i < a->mUnk_04);
    return 0;
}

u16 func_02143280(void) {
    if (func_02142a8c() != 0) {
        return 0x8000;
    }
    return *(u16 *) 0x27ffcfa;
}

u16 func_021431d8(void) {
    Unk02142aa8 *p;

    p = func_02142aa8();
    if (func_02142a8c() != 0) {
        return 0;
    }
    func_0200ee3c(p->mUnk_004, 2);
    switch (p->mUnk_004->mUnk_000) {
        case 9:
            func_0200ee3c(&p->mUnk_004->mUnk_17e, 2);
            if (p->mUnk_004->mUnk_17e == 0) {
                return 0;
            }
        case 10:
        case 11:
            func_0200ee3c(&p->mUnk_004->mUnk_0b8, 2);
            return p->mUnk_004->mUnk_0b8;
        default:
            return 0;
    }
}

u16 func_02143134(void) {
    u8 buf[6];
    s32 i;
    u16 sum;

    func_0200fe58(buf);
    for (i = 0, sum = 0; i < 6; i++) {
        sum = sum + buf[i];
    }
    sum = sum + *(u32 *) 0x27ffc3c;
    sum = sum * 7;
    return sum % 20 + 200;
}

u16 func_02143090(void) {
    u8 buf[6];
    s32 i;
    u16 sum;

    func_0200fe58(buf);
    for (i = 0, sum = 0; i < 6; i++) {
        sum = sum + buf[i];
    }
    sum = sum + *(u32 *) 0x27ffc3c;
    sum = sum * 13;
    return sum % 10 + 30;
}

Unk02142f24 func_02142f24(const u16 *a) {
    Unk02142f24 s;
    const u8 *p;
    s32 i;
    u8 len;
    u8 sum;
    u8 n;

    if (a[0x1e] != 0) {
        s.mUnk_00 = 0;
        return s;
    }
    s.mUnk_00 = a[0x1f];
    if (s.mUnk_00 == 0) {
        return s;
    }
    if (s.mUnk_00 > 0x10) {
        s.mUnk_00 = 0x10;
    }
    p = (const u8 *) a + 0x40;
    len = a[0] * 2 - 0x40;
    sum = 0;
    for (i = 0; i < s.mUnk_00; i++) {
        s.mUnk_04[i].mUnk_00 = p[0];
        s.mUnk_04[i].mUnk_01 = p[1];
        s.mUnk_04[i].mUnk_04 = p + 2;
        n = s.mUnk_04[i].mUnk_01 + 2;
        sum = sum + n;
        if (sum > len) {
            s.mUnk_00 = 0;
            return s;
        }
        p = p + n;
    }
    return s;
}

u16 func_02142eac(void) {
    u32 buf[3];

    if (data_0216f06c == 0x10000) {
        func_0214e0f4();
        if (func_0214df78(buf) == 0) {
            data_0216f06c = (u16) (buf[2] + (buf[1] << 8));
        }
    }
    data_0216f06c = (u16) (data_0216f06c + 1);
    return data_0216f06c;
}
