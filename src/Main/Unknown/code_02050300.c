#include "Main/Unknown/code_02050300.h"

#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02142eac.h"
#include "code_021445e0.h"

static inline u32 func_02050650_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void func_020515b0(u32 a) {
    data_0217aa00->mUnk_000c = 0x10;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143634(func_02051528, a) != 7) {
        return;
    }
    if (data_0217aa00->mUnk_0004 == 9) {
        if (func_02050650_inline() == 1) {
            data_0217aa00->mUnk_008a = 0;
        }
    }
    data_0217aa00->mUnk_0010 = 0;
}

void func_02051528(Unk021425e8 *a) {
    data_0217aa00->mUnk_0010 = 0;
    if (a->mUnk_02 != 0 && a->mUnk_02 != 7) {
        return;
    }
    if (func_02050650_inline() == 1) {
        switch (data_0217aa00->mUnk_0004) {
            case 8:
            case 9:
                data_0217aa00->mUnk_1eac[0] = data_0217aa00->mUnk_1eac[0] | data_0217aa00->mUnk_008a;
                break;
        }
    }
    data_0217aa00->mUnk_008a = 0;
}

void func_020514c0(void) {
    s32 r;

    data_0217aa00->mUnk_000c = 0x11;
    data_0217aa00->mUnk_0010 = 1;
    r = func_02145030(data_0217aa00->mUnk_15bc);
    data_0217aa00->mUnk_0010 = 0;
    if (r == 0) {
        return;
    }
    func_020533a0();
}

void func_0205146c(void) {
    data_0217aa00->mUnk_000c = 0x12;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143fbc(func_02051400) == 2) {
        return;
    }
    func_020533a0();
}

void func_02051400(Unk021425e8 *a) {
    Unk0217aa00 *p;

    data_0217aa00->mUnk_0010 = 0;
    data_0217aa00->mUnk_0454 &= ~1;
    if (a->mUnk_02 != 0) {
        func_020533a0();
        return;
    }
    p = data_0217aa00;
    if (p->mUnk_0004 == 0xb) {
        p->mUnk_0004 = 0xc;
    }
}

void func_020513ac(void) {
    data_0217aa00->mUnk_000c = 0x13;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143b7c(func_02051364) == 2) {
        return;
    }
    func_020533a0();
}

void func_02051364(Unk021425e8 *a) {
    data_0217aa00->mUnk_0010 = 0;
    if (a->mUnk_02 != 0) {
        func_020533a0();
    } else {
        func_02053fa8();
    }
}

void func_02051230(void) {
    s32 r;
    s32 i;
    Unk0217aa00_44 *p;
    Unk0217aa00_44_00 *e;

    r = 7;
    p = &data_0217aa00->mUnk_0044;
    switch (func_02050650_inline()) {
        case 1:
            for (i = 0, e = p->mUnk_00; i < p->mUnk_40; i++, e++) {
                if (e->mUnk_06 != 0xffff) {
                    data_0217aa00->mUnk_0044.mUnk_41 = i;
                    data_0217aa00->mUnk_000c = 0x14;
                    data_0217aa00->mUnk_0010 = 1;
                    r = func_021436d0(func_02051108, e->mUnk_06);
                    break;
                }
            }
            break;
        case 2:
            data_0217aa00->mUnk_000c = 0x14;
            data_0217aa00->mUnk_0010 = 1;
            r = func_021436d0(func_02051108, 0);
            break;
    }
    switch (r) {
        case 0:
        case 7:
            data_0217aa00->mUnk_0010 = 0;
            break;
        case 2:
            if (func_02050650_inline() == 2) {
                data_0217aa00->mUnk_0436 |= 2;
            }
            break;
        default:
            func_020533a0();
            break;
    }
}

void func_02051108(Unk021425e8 *a) {
    u16 v;

    switch (a->mUnk_02) {
        case 0:
        case 7:
            data_0217aa00->mUnk_0010 = 0;
            switch (data_0217aa00->mUnk_0000) {
                case 1:
                    v = data_0217aa00->mUnk_0044.mUnk_00[data_0217aa00->mUnk_0044.mUnk_41].mUnk_06;
                    func_02050b88(v);
                    if (func_02050650_inline() == 1) {
                        if (data_0217aa00->mUnk_0004 == 9) {
                            data_0217aa00->mUnk_1eac[0] |= 1 << v;
                        }
                    }
                    data_0217aa00->mUnk_0044.mUnk_41 = -1;
                    break;
                case 2:
                    data_0217aa00->mUnk_0436 &= ~2;
                    func_02053fa8();
                    break;
            }
            break;
        case 1:
            if ((data_0217aa00->mUnk_0436 & 2) != 0) {
                data_0217aa00->mUnk_0436 &= ~2;
                func_02053fa8();
                data_0217aa00->mUnk_0010 = 0;
            } else {
                func_020533a0();
            }
            break;
        default:
            func_020533a0();
            break;
    }
}

s32 func_020510e4(void) {
    return (data_0217aa00->mUnk_0454 & 0x40) != 0;
}

s32 func_020510c8(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline u32 func_02050ec0_inline(void) {
    return func_020510e4() != 0 && (func_020510c8() == 1 || func_020510ac() != 0);
}

s32 func_020510ac(void) {
    return *(u16 *) 0x027ffc40 == 2;
}

void func_0205108c(s32 a) {
    data_0217aa00->mUnk_000c = a;
    data_0217aa00->mUnk_0010 = 1;
}

void func_02050ec0(void) {
    Unk0217aa00 *p;
    u32 f;

    data_0217aa00->mUnk_000c = 0x15;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143d88(func_02050e80) == 2) {
        return;
    }
    p = data_0217aa00;
    f = p->mUnk_0454;
    if ((f & 0x100) != 0) {
        p->mUnk_000c = 0x26;
        data_0217aa00->mUnk_0010 = 1;
        if (func_02050ec0_inline() != 0) {
            func_0204bcec();
            data_0217aa00->mUnk_0454 &= ~0x100;
        }
        data_0217aa00->mUnk_0010 = 0;
        return;
    }
    if ((f & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    p->mUnk_000c = 2;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143dd0(func_02053348) == 2) {
        return;
    }
    data_0217aa00->mUnk_000c = 0x15;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143d88(func_02050e80) == 2) {
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x100) != 0) {
        func_02052cf4();
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    func_0205108c(2);
    if (func_02143dd0(func_02053348) == 2) {
        return;
    }
    func_02050ec0();
}

void func_02050e80(Unk021425e8 *a) {
    data_0217aa00->mUnk_0010 = 0;
    if (a->mUnk_02 != 0) {
        data_0217aa00->mUnk_0008 = 8;
        data_0217aa00->mUnk_0010 = 0;
    } else {
        data_0217aa00->mUnk_0000 = 0;
    }
}

void func_02050e60(s32 a) {
    data_0217aa00->mUnk_0008 = a;
    data_0217aa00->mUnk_0010 = 0;
}

void func_02050d80(u32 a, u8 *b, Unk0217aa00_45c *c) {
    Unk0217aa00_44 *p;

    p = &data_0217aa00->mUnk_0044;
    if (p->mUnk_40 >= 7) {
        return;
    }
    p->mUnk_00[a - 1].mUnk_06 = a;
    p->mUnk_40 += 1;
    p->mUnk_43 |= 1 << a;
    p->mUnk_00[0].mUnk_00[0] = b[0];
    p->mUnk_00[0].mUnk_00[1] = b[1];
    p->mUnk_00[0].mUnk_00[2] = b[2];
    p->mUnk_00[0].mUnk_00[3] = b[3];
    p->mUnk_00[0].mUnk_00[4] = b[4];
    p->mUnk_00[0].mUnk_00[5] = b[5];
    func_0214d1fc(c, &data_0217aa00->mUnk_045c[a], 0x14);
    data_0217aa00->mUnk_008b |= 8;
    if ((c->mUnk_014 & 1) != 0) {
        data_0217aa00->mUnk_0457 |= 1 << a;
    }
}

static inline void func_0205081c_inline2(u16 v) {
    Unk0217aa00_1608 *p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = v;
    p->mUnk_12 = 1;
}

static inline void func_0205081c_inline(u8 v) {
    u32 r = 0;
    u32 b;

    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        b = 1;
        if (func_02050650_inline() != 1) {
            if (*(u16 *) 0x027ffc40 != 2) {
                b = 0;
            }
        }
        if (b != 0) {
            r = 1;
        }
    }
    if (r == 0) {
        return;
    }
    if (func_02050650_inline() != 1) {
        return;
    }
    func_0204bcb4(v);
}

static inline void func_02050b88_inline(u16 v1) {
    u16 i;
    u32 f;

    for (i = 0; i < 8; i++) {
        if ((v1 & (1 << i)) != 0) {
            f = data_0217aa00->mUnk_0004 == 9 ? 1 : 0;
            if (func_02050650_inline() == 1) {
                data_0217aa00->mUnk_0044.mUnk_43 &= ~(1 << i);
                if (f != 0) {
                    data_0217aa00->mUnk_008a |= 1 << i;
                }
            }
            data_0217aa00->mUnk_0457 &= ~(1 << i);
        }
    }
    if (func_02050650_inline() != 1) {
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x100) == 0) {
        return;
    }
    func_0205081c_inline(data_0217aa00->mUnk_0457);
}

void func_02050b88(u32 a) {
    Unk0217aa00_44 *p;

    p = &data_0217aa00->mUnk_0044;
    if (p->mUnk_00[a - 1].mUnk_06 == 0xffff) {
        return;
    }
    p->mUnk_00[a - 1].mUnk_06 = 0xffff;
    p->mUnk_40 -= 1;
    func_02050b88_inline(1 << a);
    data_0217aa00->mUnk_008b |= 8;
    switch (data_0217aa00->mUnk_0004) {
        case 9:
            if (p->mUnk_40 < 1) {
                data_0217aa00->mUnk_0008 = 0;
                data_0217aa00->mUnk_0010 = 0;
            }
            break;
        case 7:
        case 8:
            data_0217aa00->mUnk_0008 = 0;
            data_0217aa00->mUnk_0010 = 0;
            break;
    }
}

void func_0205081c(u32 a, Unk0205081c *b) {
    switch (b->mUnk_00) {
        case 3:
            data_0217aa00->mUnk_1d54 &= ~(1 << a);
            break;
        case 4:
            data_0217aa00->mUnk_1d54 |= 1 << a;
            if (data_0217aa00->mUnk_1d54 == data_0217aa00->mUnk_0044.mUnk_43) {
                data_0217aa00->mUnk_0010 = 0;
            }
            break;
        case 5:
            data_0217aa00->mUnk_1e44 |= 2;
            data_0217aa00->mUnk_0010 = 0;
            break;
        case 1:
            data_0217aa00->mUnk_15f6 = b->mUnk_04;
            func_02050080();
            func_02058b10();
            break;
        case 2:
            if (func_02050650_inline() == 2) {
                data_0217aa00->mUnk_0457 = b->mUnk_04;
            }
            func_0205081c_inline2(1);
            break;
        case 6:
            switch (data_0217aa00->mUnk_0004) {
                case 6:
                    func_020559ec(b->mUnk_02, b->mUnk_16, b->mUnk_17);
                    break;
                case 0xa:
                    func_020597d0(b->mUnk_02, (u8) a, b->mUnk_16, b->mUnk_17);
                    break;
            }
            break;
        case 9:
            if ((data_0217aa00->mUnk_164d & (1 << b->mUnk_0a)) != 0) {
                return;
            }
            func_0214d1fc(b->mUnk_02, data_0217aa00->mUnk_045c[b->mUnk_0a].mUnk_224, 4);
            data_0217aa00->mUnk_164d |= 1 << b->mUnk_0a;
            break;
        case 7:
            func_02050b88_inline(b->mUnk_04);
            break;
        case 8:
            data_0217aa00->mUnk_1eb0 = b->mUnk_04;
            break;
    }
}

void func_02050764(Unk021425e8 *a) {
    Unk0205081c v1;

    if (a->mUnk_02 != 0) {
        return;
    }
    if (a->mUnk_0c == 0) {
        return;
    }
    if (a->mUnk_10 < 2) {
        return;
    }
    if (a->mUnk_10 > 0x18) {
        return;
    }
    func_0200ee3c(a->mUnk_0c, a->mUnk_10);
    func_0214d1fc(a->mUnk_0c, &v1, a->mUnk_10);
    if (a->mUnk_04 == 7) {
        return;
    }
    if (a->mUnk_04 == 9) {
        return;
    }
    if (a->mUnk_04 != 0x15) {
        return;
    }
    func_0205081c(a->mUnk_12, &v1);
}

s32 func_02050650(void *a, s32 b, u16 c, void *d, Unk021652a0 *e) {
    u16 n;

    n = b;
    switch (func_02050650_inline()) {
        case 1:
            if (data_0217aa00->mUnk_0044.mUnk_43 == 0) {
                return 0;
            }
            break;
        case 2:
            if (data_0217aa00->mUnk_0432 == 0xffff) {
                return 0;
            }
            break;
    }
    if (n > e->mUnk_04) {
        n = e->mUnk_04;
    }
    func_0200ee74(a, n);
    if (d == 0) {
        d = a;
    } else {
        func_0214d1fc(a, d, n);
        func_0200ee74(d, n);
    }
    if (func_02144048(e->mUnk_00, 0, d, n, c, e->mUnk_08, e->mUnk_0c) != 2) {
        return 0;
    }
    return 1;
}

s32 func_020505a8(s32 a, u16 b) {
    u16 v1;

    v1 = a;
    if ((data_0217aa00->mUnk_0454 & 1) == 0) {
        return 0;
    }
    data_0216523c.mUnk_04 = 0x18;
    data_0217aa00->mUnk_0454 &= ~1;
    if (func_02050650(&v1, 2, b, data_0217aa00->mUnk_0040, &data_0216523c) != 0) {
        return 1;
    }
    data_0217aa00->mUnk_0454 |= 1;
    return 0;
}

s32 func_020504a4(s32 a, u16 b) {
    Unk020504a4 v1;

    v1.mUnk_00 = 6;
    func_0214d1fc(&data_0217aa00->mUnk_045c[a], v1.mUnk_02, 0x14);
    v1.mUnk_16 = a;
    if (func_02050650_inline() == 1) {
        v1.mUnk_17 = data_0217aa00->mUnk_0044.mUnk_43 | 1;
    } else {
        v1.mUnk_17 = 0;
    }
    if ((data_0217aa00->mUnk_0454 & 1) == 0) {
        return 0;
    }
    data_0216523c.mUnk_04 = 0x18;
    data_0217aa00->mUnk_0454 &= ~1;
    if (func_02050650(&v1, 0x18, b, data_0217aa00->mUnk_0040, &data_0216523c) != 0) {
        return 1;
    }
    data_0217aa00->mUnk_0454 |= 1;
    return 0;
}

s32 func_020503cc(s32 a, u16 b) {
    Unk020503cc v1;

    v1.mUnk_00 = 9;
    func_0214d1fc(data_0217aa00->mUnk_045c[a].mUnk_224, v1.mUnk_02, 4);
    v1.mUnk_0a = a;
    if ((data_0217aa00->mUnk_0454 & 1) == 0) {
        return 0;
    }
    data_0216523c.mUnk_04 = 0x18;
    data_0217aa00->mUnk_0454 &= ~1;
    if (func_02050650(&v1, 0x12, b, data_0217aa00->mUnk_0040, &data_0216523c) != 0) {
        return 1;
    }
    data_0217aa00->mUnk_0454 |= 1;
    return 0;
}

s32 func_02050320(s32 a, u16 b, s32 c) {
    Unk02050320 v1;

    v1.mUnk_00 = a;
    v1.mUnk_04 = c;
    if ((data_0217aa00->mUnk_0454 & 1) == 0) {
        return 0;
    }
    data_0216523c.mUnk_04 = 0x18;
    data_0217aa00->mUnk_0454 &= ~1;
    if (func_02050650(&v1, 8, b, data_0217aa00->mUnk_0040, &data_0216523c) != 0) {
        return 1;
    }
    data_0217aa00->mUnk_0454 |= 1;
    return 0;
}

u32 func_02050300(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa00;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) + (0x400u);
    value1 = (u32) * (const u16 *) ((value0) + (84));
    value1 = (value1) | (1u);
    *(u16 *) ((value0) + (84)) = (u16) value1;
    return value0;
}
