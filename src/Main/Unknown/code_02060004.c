#include "Main/Unknown/code_02060004.h"

static inline s32 func_02060004_inline(s32 a, s32 b, Unk02056bc0 *c) {
    s32 r;

    if (func_02056bc0(a, b, c) != 0 && c->mUnk_18 != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

void func_02060c0c(void *a) {
    func_0214d1fc(a, (u8 *) data_0217aa08->mUnk_20 + 0x874, 0x2d0);
}

void func_02060b68(void) {
    Unk0217aa08_20_04 a;
    u8 i;

    for (i = 0; i < 60; i++) {
        func_0205ee14(i, &a);
        if (a.mUnk_22_0 == 1 && a.mUnk_22_1 == 1 &&
            func_02152a24((u8 *) data_0217aa08->mUnk_20 + 0x874 + i * 12) != 0) {
            a.mUnk_22_1 = 0;
            func_0205ee74(i, &a);
        }
    }
}

s32 func_02060b34(u8 a) {
    Unk0217aa08_20_04 b;

    func_0205ee14(a, &b);
    if (b.mUnk_22_0 == 1) {
        return 1;
    }
    return 0;
}

s32 func_02060afc(u8 a) {
    Unk0217aa08_20_04 b;

    func_0205ee14(a, &b);
    if (b.mUnk_22_0 == 1) {
        return b.mUnk_22_3;
    }
    return 0;
}

s32 func_02060ac8(u8 a) {
    Unk0217aa08_20_04 b;

    func_0205ee14(a, &b);
    if (b.mUnk_22_0 == 1) {
        return b.mUnk_00[0][0];
    }
    return -1;
}

s32 func_02060a94(u8 a) {
    Unk0217aa08_20_04 b;

    func_0205ee14(a, &b);
    if (b.mUnk_22_0 == 1) {
        return b.mUnk_00[0][1];
    }
    return -1;
}

s32 func_02060a60(u8 a) {
    Unk0217aa08_20_04 b;

    func_0205ee14(a, &b);
    if (b.mUnk_22_0 == 1) {
        return b.mUnk_00[1][0];
    }
    return -1;
}

s32 func_02060a2c(u8 a) {
    Unk0217aa08_20_04 b;

    func_0205ee14(a, &b);
    if (b.mUnk_22_0 == 1) {
        return b.mUnk_00[1][1];
    }
    return -1;
}

s32 func_020609f8(u8 a) {
    Unk0217aa08_20_04 b;

    func_0205ee14(a, &b);
    if (b.mUnk_22_0 == 1) {
        return b.mUnk_00[2][0];
    }
    return -1;
}

s32 func_020609c4(u8 a) {
    Unk0217aa08_20_04 b;

    func_0205ee14(a, &b);
    if (b.mUnk_22_0 == 1) {
        return b.mUnk_00[2][1];
    }
    return -1;
}

s32 func_02060950(u8 a, u8 *b) {
    Unk0217aa08_20_04 c;

    func_0205ee14(a, &c);
    if (c.mUnk_22_0 != 1) {
        return 0;
    }
    b[0] = c.mUnk_0c_0;
    b[1] = c.mUnk_0c_7;
    b[2] = c.mUnk_0c_11;
    return 1;
}

s32 func_020608fc(u8 a, void *b) {
    Unk0217aa08_20_04 c;

    func_0205ee14(a, &c);
    if (c.mUnk_22_0 != 1) {
        return 0;
    }
    func_0214d1fc(c.mUnk_0e, b, 0x14);
    return 1;
}

s32 func_02060880(u8 a, s32 b) {
    Unk0217aa08_20_04 c;

    func_0205ee14(a, &c);
    if (c.mUnk_22_0 == 1) {
        c.mUnk_22_3 = b != 0;
        func_0205ee74(a, &c);
        return 1;
    }
    return 0;
}

s32 func_020607b0(u8 a) {
    Unk0217aa08_20_04 b;
    s32 c;

    func_0205ee14(a, &b);
    c = b.mUnk_22_0 == 1;
    func_0214d168(&b, 0, 0x24);
    b.mUnk_22_0 = 0;
    func_0205ee74(a, &b);
    if (data_0217d384->mUnk_0008.mUnk_0e != 0) {
        func_ov000_0219d948((u8 *) data_0217aa08->mUnk_20 + 0x874 + a * 12);
    } else {
        func_0214d168((u8 *) data_0217aa08->mUnk_20 + 0x874 + a * 12, 0, 0xc);
    }
    func_0205edf8();
    return c;
}

void func_02060510(u8 a, u8 b) {
    Unk0217aa08_20_04 c;
    Unk0217aa08_20_04 d;
    Unk0217aa08_20_04 e;

    func_0205ee14(a, &c);
    func_0205ee14(b, &d);
    func_02057624((u32) &e);
    if (d.mUnk_22_1 == 0) {
        e.mUnk_00[0][0] = e.mUnk_00[0][0] + d.mUnk_00[0][0];
        e.mUnk_00[0][1] = e.mUnk_00[0][1] + d.mUnk_00[0][1];
        e.mUnk_00[1][0] = e.mUnk_00[1][0] + d.mUnk_00[1][0];
        e.mUnk_00[1][1] = e.mUnk_00[1][1] + d.mUnk_00[1][1];
        e.mUnk_00[2][0] = e.mUnk_00[2][0] + d.mUnk_00[2][0];
        e.mUnk_00[2][1] = e.mUnk_00[2][1] + d.mUnk_00[2][1];
        func_0214d1fc(d.mUnk_0e, e.mUnk_0e, 0x14);
        e.mUnk_0c_0 = d.mUnk_0c_0;
        e.mUnk_0c_7 = d.mUnk_0c_7;
        e.mUnk_0c_11 = d.mUnk_0c_11;
    }
    if (c.mUnk_22_1 == 0) {
        e.mUnk_00[0][0] = e.mUnk_00[0][0] + c.mUnk_00[0][0];
        e.mUnk_00[0][1] = e.mUnk_00[0][1] + c.mUnk_00[0][1];
        e.mUnk_00[1][0] = e.mUnk_00[1][0] + c.mUnk_00[1][0];
        e.mUnk_00[1][1] = e.mUnk_00[1][1] + c.mUnk_00[1][1];
        e.mUnk_00[2][0] = e.mUnk_00[2][0] + c.mUnk_00[2][0];
        e.mUnk_00[2][1] = e.mUnk_00[2][1] + d.mUnk_00[2][1];
        func_0214d1fc(c.mUnk_0e, e.mUnk_0e, 0x14);
        e.mUnk_0c_0 = c.mUnk_0c_0;
        e.mUnk_0c_7 = c.mUnk_0c_7;
        e.mUnk_0c_11 = c.mUnk_0c_11;
    }
    e.mUnk_22_0 = 1;
    e.mUnk_22_1 = 0;
    e.mUnk_22_2 = c.mUnk_22_2;
    e.mUnk_22_3 = c.mUnk_22_3 == 1 || d.mUnk_22_3 == 1;
    func_0205ee74(a, &e);
    func_0214d168(&d, 0, 0x24);
    d.mUnk_22_0 = 0;
    func_0205ee74(b, &d);
}

s32 func_02060468(u8 a, void *b) {
    u8 *e;
    s32 d;
    s32 g;
    Unk0217aa08_20_04 c;

    d = 0;
    func_0205ee14(a, &c);
    e = (u8 *) data_0217aa08->mUnk_20 + 0x874 + a * 12;
    if (c.mUnk_22_0 == 1 && c.mUnk_22_1 == 1 && func_021526a0(e) != 0) {
        g = 1;
    } else {
        g = 0;
    }
    if (g != 0) {
        u64 f = func_02152584(e);

        func_02152918((u32) f, (u32) (f >> 32), (u32) b);
        d = 1;
    }
    return d;
}

s32 func_02060440(s32 a, s32 b) {
    Unk02056bc0 c;

    func_02056a7c(a, b, &c);
    if (c.mUnk_18 == 0) {
        return 0;
    }
    return c.mUnk_18;
}

s32 func_02060414(s32 a, s32 b) {
    Unk02056bc0 c;

    func_02056a7c(a, b, &c);
    if (c.mUnk_18 != 0) {
        return c.mUnk_19;
    }
    return -1;
}

s32 func_020603e8(s32 a, s32 b) {
    Unk02056bc0 c;

    func_02056a7c(a, b, &c);
    if (c.mUnk_18 != 0) {
        return c.mUnk_1a;
    }
    return -1;
}

s32 func_020603bc(s32 a, s32 b) {
    Unk02056bc0 c;

    func_02056a7c(a, b, &c);
    if (c.mUnk_18 != 0) {
        return c.mUnk_1c;
    }
    return 3;
}

s32 func_02060390(s32 a, s32 b) {
    Unk02056bc0 c;

    func_02056a7c(a, b, &c);
    if (c.mUnk_18 != 0) {
        return (s8) c.mUnk_1d;
    }
    return -1;
}

s32 func_02060364(s32 a, s32 b) {
    Unk02056bc0 c;

    func_02056a7c(a, b, &c);
    if (c.mUnk_18 != 0) {
        return c.mUnk_1e;
    }
    return 9;
}

s32 func_02060318(s32 a, s32 b, void *c) {
    Unk02056bc0 d;

    func_02056a7c(a, b, &d);
    if (d.mUnk_18 == 0) {
        return 0;
    }
    func_0214d1fc(&d, c, 4);
    return 1;
}

s32 func_02060268(s32 a) {
    u8 i;
    s32 c;
    s32 d;
    Unk02056bc0 b;

    c = 1;
    d = func_0204684c(a);
    if (d == -1) {
        return c;
    }
    if (func_020573f8(d) == 0) {
        return c;
    }
    for (i = 0; i < 6; i++) {
        if (func_02060004_inline(a, i, &b)) {
            c = 0;
            break;
        }
    }
    return c;
}

s32 func_02060228(s32 a, s32 b) {
    Unk02056bc0 c;

    if (func_02056bc0(a, b, &c) != 0 && c.mUnk_18 != 0) {
        return 1;
    }
    return 0;
}

s32 func_020601e4(s32 a, s32 b) {
    Unk02056bc0 c;

    if (func_02060004_inline(a, b, &c)) {
        return c.mUnk_19;
    }
    return -1;
}

s32 func_020601a0(s32 a, s32 b) {
    Unk02056bc0 c;

    if (func_02060004_inline(a, b, &c)) {
        return c.mUnk_1a;
    }
    return -1;
}

s32 func_02060134(s32 a, s32 b, void *v1) {
    Unk02056bc0 c;
    Unk02056bc0 *d;

    if (!func_02060004_inline(a, b, &c)) {
        return 0;
    }
    d = v1;
    d->mUnk_02 = c.mUnk_02;
    d->mUnk_03 = c.mUnk_03;
    d->mUnk_00 = c.mUnk_00;
    return 1;
}

s32 func_020600d0(s32 a, s32 b, void *v1) {
    Unk02056bc0 c;

    if (!func_02060004_inline(a, b, &c)) {
        return 0;
    }
    func_0214d1fc(c.mUnk_04, v1, 0x14);
    return 1;
}

s32 func_020600b4(s32 a) {
    return func_0203b96c(func_020467d0(a));
}

void func_02060004(s32 a) {
    u8 i;
    s32 d;
    u8 e;
    s32 c;
    Unk02056bc0 b;

    c = func_0204684c(a);
    d = 0;
    if (c == -1) {
        return;
    }
    e = c;
    if (func_020573f8(e) != 0) {
        func_020573e0(e);
        d = 1;
    }
    for (i = 0; i < 6; i++) {
        func_0214d168(&b, 0, 0x20);
        func_02056c6c(a, i, &b);
    }
    if (d != 0) {
        func_020563ec();
    } else {
        func_02056408();
    }
}
