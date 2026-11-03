#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_02020eb0.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200e77c.h"
#include "code_0214d5b8.h"
#include "code_02021784.h"

Unk020207ec *data_021732c8;
u32 data_021732cc;
Unk020207ec *data_021732d0;
Unk020207ec *data_021732d4;
Unk020207ec *data_021732d8;
s32 data_021732dc;
s32 data_021732e0;
s32 data_021732e4;
u32 data_021732e8;
Unk020207ec *data_021732ec[9];
Unk020217b4 data_02173320;
Unk020207ec data_021735a0[256];

u8 func_02021734(s32 a, UnkFunc *b, void *c) {
    Unk02021734 *e;

    e = &data_02174da0[a];
    e->mUnk_00 = b;
    e->mUnk_04 = c;
    e->mUnk_08++;
    return e->mUnk_08;
}

void func_020216d4(s32 a) {
    Unk02021734 *e;

    e = &data_02174da0[a & 0xff];
    if (((a >> 8) & 0xff) != e->mUnk_08) {
        return;
    }
    if (e->mUnk_00 == 0) {
        return;
    }
    e->mUnk_00(e->mUnk_04);
}

void func_020215bc(void) {
    s32 i;
    Unk020207ec *p;

    func_02020f84();
    data_021732c8 = data_021735a0;
    for (i = 0; i < 255; i++) {
        data_021735a0[i].mUnk_00 = &data_021735a0[i + 1];
    }
    data_021735a0[255].mUnk_00 = 0;
    data_021732d8 = &data_021735a0[255];
    data_021732d0 = 0;
    data_021732d4 = 0;
    data_021732e4 = 0;
    data_021732dc = 0;
    data_021732e0 = 0;
    data_021732e8 = 1;
    data_021732cc = 0;
    data_02174e00 = &data_02173320;
    func_020217b4(&data_02173320);
    p = func_020213ec(1);
    if (p == 0) {
        return;
    }
    p->mUnk_04 = 0x1d;
    p->mUnk_08 = (u32) data_02174e00;
    func_020213a4(p);
    func_020211e4(1);
}

Unk020207ec *func_02021488(u32 a) {
    u32 s;
    Unk020207ec *p;
    Unk020207ec *q;
    s32 i;

    s = func_0200fca0();
    if ((a & 1) != 0) {
        while (data_021732cc == func_02021834()) {
            func_0200fcb4(s);
            func_0200fd10(0x64);
            s = func_0200fca0();
        }
    } else if (data_021732cc == func_02021834()) {
        func_0200fcb4(s);
        return 0;
    }
    i = data_021732dc;
    p = data_021732ec[i];
    data_021732dc = i + 1;
    if (data_021732dc > 8) {
        data_021732dc = 0;
    }
    q = p;
    while (q->mUnk_00 != 0) {
        q = q->mUnk_00;
    }
    if (data_021732d8 != 0) {
        data_021732d8->mUnk_00 = p;
    } else {
        data_021732c8 = p;
    }
    data_021732d8 = q;
    data_021732e4--;
    data_021732cc++;
    func_0200fcb4(s);
    return p;
}

Unk020207ec *func_020213ec(u32 a) {
    Unk020207ec *p;

    if (func_02020eb0() == 0) {
        return 0;
    }
    p = func_02020ef8();
    if (p != 0) {
        return p;
    }
    if ((a & 1) == 0) {
        return 0;
    }
    if (func_02021020() > 0) {
        while (func_02021488(0) != 0) {
        }
        p = func_02020ef8();
        if (p != 0) {
            return p;
        }
    } else {
        func_020211e4(1);
    }
    func_02020f50();
    do {
        func_02021488(1);
        p = func_02020ef8();
    } while (p == 0);
    return p;
}

void func_020213a4(Unk020207ec *p) {
    u32 s;
    Unk020207ec *t;

    s = func_0200fca0();
    t = data_021732d4;
    if (t == 0) {
        data_021732d4 = p;
        data_021732d0 = p;
    } else {
        t->mUnk_00 = p;
        data_021732d4 = p;
    }
    p->mUnk_00 = 0;
    func_0200fcb4(s);
}

u32 func_020211e4(u32 a) {
    u32 s;

    s = func_0200fca0();
    if (data_021732d0 == 0) {
        func_0200fcb4(s);
        return 1;
    }
    if (data_021732e4 >= 8) {
        if ((a & 1) == 0) {
            func_0200fcb4(s);
            return 0;
        }
        do {
            func_02021488(1);
        } while (data_021732e4 >= 8);
    }
    func_0200ee74(data_021735a0, 0x1800);
    if (func_0214d6e8(7, (u32) data_021732d0, 0) < 0) {
        if ((a & 1) == 0) {
            func_0200fcb4(s);
            return 0;
        }
        if (func_0214d6e8(7, (u32) data_021732d0, 0) < 0) {
            do {
                func_0200fcb4(s);
                func_0200fd10(0x64);
                s = func_0200fca0();
            } while (func_0214d6e8(7, (u32) data_021732d0, 0) < 0);
        }
    }
    if ((a & 2) != 0) {
        func_02020f50();
    }
    data_021732ec[data_021732e0] = data_021732d0;
    data_021732e0++;
    if (data_021732e0 > 8) {
        data_021732e0 = 0;
    }
    data_021732d0 = 0;
    data_021732d4 = 0;
    data_021732e4++;
    data_021732e8++;
    func_0200fcb4(s);
    return 1;
}

void func_02021154(u32 a) {
    if (func_020210c0(a) != 0) {
        return;
    }
    while (func_02021488(0) != 0) {
    }
    if (func_020210c0(a) != 0) {
        return;
    }
    func_02020f50();
    if (func_020210c0(a) != 0) {
        return;
    }
    do {
        func_02021488(1);
    } while (func_020210c0(a) == 0);
}

u32 func_02021114(void) {
    u32 s;
    u32 v;

    s = func_0200fca0();
    if (data_021732d0 == 0) {
        v = data_021732cc;
    } else {
        v = data_021732e8;
    }
    func_0200fcb4(s);
    return v;
}

u32 func_020210c0(u32 a) {
    u32 s;
    u32 c;
    u32 r;

    s = func_0200fca0();
    c = data_021732cc;
    if (a > c) {
        if ((a - c) < 0x80000000u) {
            r = 0;
        } else {
            r = 1;
        }
    } else {
        if ((c - a) < 0x80000000u) {
            r = 1;
        } else {
            r = 0;
        }
    }
    func_0200fcb4(s);
    return r;
}

s32 func_02021080(void) {
    u32 s;
    Unk020207ec *p;
    s32 n;

    s = func_0200fca0();
    n = 0;
    for (p = data_021732c8; p != 0; p = p->mUnk_00) {
        n++;
    }
    func_0200fcb4(s);
    return n;
}

s32 func_02021040(void) {
    u32 s;
    Unk020207ec *p;
    s32 n;

    s = func_0200fca0();
    n = 0;
    for (p = data_021732d0; p != 0; p = p->mUnk_00) {
        n++;
    }
    func_0200fcb4(s);
    return n;
}

s32 func_02021020(void) {
    s32 a;

    a = func_02021080();
    return 0x100 - a - func_02021040();
}

void func_02020ff0(u32 a, u32 b) {
    u32 s;

    s = func_0200fca0();
    func_020216d4(b);
    func_0200fcb4(s);
}

void func_02020f84(void) {
    func_0214d7c4(7, func_02020ff0);
    if (func_02020eb0() == 0) {
        return;
    }
    if (func_0214d79c(7, 1) != 0) {
        return;
    }
    do {
        func_0200fd10(0x64);
    } while (func_0214d79c(7, 1) == 0);
}

void func_02020f50(void) {
    while (func_0214d6e8(7, 0, 0) < 0) {
    }
}

Unk020207ec *func_02020ef8(void) {
    u32 s;
    Unk020207ec *p;
    Unk020207ec *n;

    s = func_0200fca0();
    p = data_021732c8;
    if (p == 0) {
        func_0200fcb4(s);
        return 0;
    }
    n = p->mUnk_00;
    data_021732c8 = n;
    if (n == 0) {
        data_021732d8 = 0;
    }
    func_0200fcb4(s);
    return p;
}

u32 func_02020eb0(void) {
    u32 s;
    u32 v;

    if (func_0200e8fc() == 0) {
        return 1;
    }
    s = func_0200fca0();
    *(vu32 *) 0x04fff200 = 0x10;
    v = *(vu32 *) 0x04fff200;
    func_0200fcb4(s);
    return v != 0;
}
