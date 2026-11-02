#include "00/code_021a5b3c.h"
#include "00/unk_021b5000.h"
#include "00/code_021a4000.h"
#include "00/code_021a5000.h"
#include "00/code_021a6000.h"
#include "code_02142eac.h"
#include "00/code_021a574c.h"
#include "00/code_021a54b0.h"
#include "00/code_021a666c.h"
#include "00/code_021a6d1c.h"
#include "code_0200fc8c.h"
#include "code_021453ec.h"
#include "code_0214259c.h"
#include "code_02142c24.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f6e4.h"
#include "code_0200f6f4.h"
#include "Main/Unknown/code_0200fb18.h"
#include "code_0200fb28.h"

u32 func_ov000_021a5b3c(u32 a) {
    u32 v1;
    u32 b;
    u32 v2;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    b = 0;
    g = data_ov000_021b5f50;
    v2 = g->mUnk_2264;
    if (g == 0) {
        func_0200fcb4(v1);
        return 0;
    }
    if (a & 0x8000) {
        b |= 0x3ffe;
        if ((a & 0x3ffe) == 0) {
            a |= 0xa082;
        }
    }
    if (a & 0x20000) {
        b |= 0x10000;
    }
    if (a & 0x80000) {
        b |= 0x40000;
    }
    if (a & 0x200000) {
        b |= 0x100000;
    }
    if (a & 0x800000) {
        b |= 0x400000;
    }
    g->mUnk_2264 = a | (v2 & ~b);
    func_0200fcb4(v1);
    return v2;
}

u32 func_ov000_021a5bfc(void) {
    u32 v1;
    u32 r;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    r = 0;
    g = data_ov000_021b5f50;
    if (g != 0) {
        r = g->mUnk_2260;
    }
    func_0200fcb4(v1);
    return r;
}

s32 func_ov000_021a5c24(void) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;
    Unk02142988 *p;

    v1 = func_0200fca0();
    g = data_ov000_021b5f50;
    if (g == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 13:
            func_0200fcb4(v1);
            return 2;
        case 1:
            func_0200fcb4(v1);
            return 0;
        case 6:
            func_ov000_021a57fc(0xd);
            data_ov000_021b5f50->mUnk_2280 = 9;
            func_0200fcb4(v1);
            return 3;
        case 3:
        case 9:
        case 12:
            break;
        default:
            func_0200fcb4(v1);
            return 1;
    }
    if (g->mUnk_226b == 1) {
        func_ov000_021a57fc(0xd);
        data_ov000_021b5f50->mUnk_2280 = 9;
    } else {
        p = func_0214259c();
        func_0200ee3c(p, 2);
        switch (p->mUnk_000) {
            case 0:
                r = func_02142c24();
                if (r == 0) {
                    func_ov000_021a57fc(1);
                    data_ov000_021b5f50->mUnk_2280 = 0;
                    func_0200fcb4(v1);
                    return 0;
                }
                break;
            case 1:
                r = func_02143f08(func_ov000_021a54b0);
                break;
            case 2:
                r = func_02143e78(func_ov000_021a54b0);
                break;
            default:
                data_ov000_021b5f50->mUnk_226b = 1;
                r = func_02143dd0(func_ov000_021a4bc4);
                break;
        }
        switch (r) {
            case 2:
                func_ov000_021a57fc(0xd);
                data_ov000_021b5f50->mUnk_2280 = 9;
                break;
            case 8:
                func_0200fcb4(v1);
                return 4;
            case 3:
            default:
                func_ov000_021a57fc(0xb);
                func_0200fcb4(v1);
                return 7;
        }
    }
    func_0200fcb4(v1);
    return 3;
}

s32 func_ov000_021a5db0(void) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = data_ov000_021b5f50;
    if (g == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 10:
            func_0200fcb4(v1);
            return 2;
        case 3:
            func_0200fcb4(v1);
            return 0;
        default:
            func_0200fcb4(v1);
            return 1;
        case 9:
            break;
    }
    if (g->mUnk_226b == 1) {
        func_ov000_021a57fc(0xa);
        data_ov000_021b5f50->mUnk_2280 = 6;
    } else {
        r = func_021443b0(func_ov000_021a4e28);
        switch (r) {
            case 2:
                func_ov000_021a57fc(0xa);
                data_ov000_021b5f50->mUnk_2280 = 6;
                break;
            case 8:
                func_0200fcb4(v1);
                return 4;
            case 3:
            default:
                func_ov000_021a57fc(0xb);
                func_0200fcb4(v1);
                return 7;
        }
    }
    func_0200fcb4(v1);
    return 3;
}

s32 func_ov000_021a5e84(Unk021a5e84 *a, Unk02188de4 *b, u32 c) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = data_ov000_021b5f50;
    if (g == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 3:
            if (a == 0) {
                func_0200fcb4(v1);
                return 1;
            }
            if (a->mUnk_3c != 0) {
                func_0200fcb4(v1);
                return 1;
            }
            if (b != 0) {
                if (b->mUnk_00 >= 4 || b->mUnk_01 >= 4) {
                    func_0200fcb4(v1);
                    return 1;
                }
                g->mUnk_2250 = b->mUnk_00;
                data_ov000_021b5f50->mUnk_2251 = b->mUnk_01;
                if (data_ov000_021b5f50->mUnk_2250 == 0) {
                    func_0214d168(data_ov000_021b5f50->mUnk_2200, 0, 0x50);
                } else {
                    func_0214d1fc(b->mUnk_02, data_ov000_021b5f50->mUnk_2200, 0x50);
                }
            } else {
                func_0214d168(g->mUnk_2200, 0, 0x52);
            }
            func_0214d1fc(a, data_ov000_021b5f50->mUnk_2140, 0xc0);
            data_ov000_021b5f50->mUnk_2170 = data_ov000_021b5f50->mUnk_216e | 3;
            func_ov000_021a5b3c(c);
            break;
        case 8:
            func_0200fcb4(v1);
            return 2;
        case 9:
            func_0200fcb4(v1);
            return 0;
        default:
            func_0200fcb4(v1);
            return 1;
    }
    r = func_021454c4(func_ov000_021a54b0, 0xffff, 0x50, 0xffff, 0xffff);
    switch (r) {
        case 2:
            func_ov000_021a57fc(8);
            data_ov000_021b5f50->mUnk_2280 = 5;
            break;
        case 8:
            func_0200fcb4(v1);
            return 4;
        case 3:
        default:
            func_ov000_021a57fc(0xb);
            func_0200fcb4(v1);
            return 7;
    }
    func_0200fcb4(v1);
    return 3;
}

s32 func_ov000_021a6024(void) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = data_ov000_021b5f50;
    if (g == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 6:
            func_ov000_021a57fc(7);
            data_ov000_021b5f50->mUnk_2280 = 4;
            break;
        case 7:
            func_0200fcb4(v1);
            return 2;
        case 3:
            func_0200fcb4(v1);
            return 0;
        default:
            func_0200fcb4(v1);
            return 1;
    }
    func_0200fcb4(v1);
    return 3;
}

s32 func_ov000_021a60a4(const void *a, const u8 *b, u32 c) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = data_ov000_021b5f50;
    if (g == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 5:
            func_ov000_021a5948(a, b, c);
            func_0200fcb4(v1);
            return 2;
        case 6:
            func_ov000_021a5948(a, b, c);
            func_0200fcb4(v1);
            return 0;
        default:
            func_0200fcb4(v1);
            return 1;
        case 3:
            func_ov000_021a5948(a, b, c);
            func_0200ee3c(data_ov000_021b5f50->mUnk_2288.mUnk_00, data_ov000_021b5f50->mUnk_2288.mUnk_04);
            data_ov000_021b5f50->mUnk_2284++;
            r = func_021438f0((Unk021425e8Func) func_ov000_021a52b0, &data_ov000_021b5f50->mUnk_2288);
            switch (r) {
                case 2:
                    func_ov000_021a57fc(5);
                    data_ov000_021b5f50->mUnk_2280 = 3;
                    break;
                case 8:
                    func_0200fcb4(v1);
                    return 4;
                case 3:
                default:
                    func_ov000_021a57fc(0xb);
                    func_0200fcb4(v1);
                    return 7;
            }
            func_0200fcb4(v1);
            return 3;
    }
}

s32 func_ov000_021a61c4(const void *a, const u8 *b, u32 c) {
    if (a == 0 || b == 0) {
        return func_ov000_021a6024();
    }
    return func_ov000_021a60a4(a, b, c);
}

s32 func_ov000_021a61e4(void) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = data_ov000_021b5f50;
    if (g == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 4:
            func_0200fcb4(v1);
            return 2;
        case 1:
            func_0200fcb4(v1);
            return 0;
        default:
            func_0200fcb4(v1);
            return 1;
        case 3:
            r = func_02143e78(func_ov000_021a54b0);
            switch (r) {
                case 2:
                    func_ov000_021a57fc(4);
                    data_ov000_021b5f50->mUnk_2280 = 2;
                    break;
                case 8:
                    func_0200fcb4(v1);
                    return 4;
                case 3:
                default:
                    func_ov000_021a57fc(0xb);
                    func_0200fcb4(v1);
                    return 7;
            }
            func_0200fcb4(v1);
            return 3;
    }
}

s32 func_ov000_021a629c(Unk021a5a78 *a, void (*b)(Unk021a586c *)) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = data_ov000_021b5f50;
    if (g == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 1:
            func_ov000_021a5a78(a, b);
            break;
        case 2:
            func_0200fcb4(v1);
            return 2;
        case 3:
            func_0200fcb4(v1);
            return 0;
        default:
            func_0200fcb4(v1);
            return 1;
    }
    switch (func_02142e78(data_ov000_021b5f50, (u16) data_ov000_021b5f50->mUnk_226c)) {
        case 3:
            func_ov000_021a57fc(0xb);
            func_0200fcb4(v1);
            return 7;
        case 4:
            func_0200fcb4(v1);
            return 5;
        case 1:
        case 2:
        case 5:
        case 6:
        default:
            func_ov000_021a57fc(0xb);
            func_0200fcb4(v1);
            return 7;
        case 0:
            break;
    }
    if (func_02143280() == 0) {
        if (func_02142c24() != 0) {
            func_ov000_021a57fc(0xb);
            func_0200fcb4(v1);
            return 7;
        }
        func_0200fcb4(v1);
        return 5;
    }
    if (func_021435e8(func_ov000_021a56e4) != 0) {
        func_ov000_021a57fc(0xb);
        func_0200fcb4(v1);
        return 7;
    }
    r = func_02143f50(func_ov000_021a54b0);
    switch (r) {
        case 2:
            func_ov000_021a57fc(2);
            data_ov000_021b5f50->mUnk_2280 = 1;
            break;
        case 8:
            func_ov000_021a57fc(0xc);
            func_0200fcb4(v1);
            return 1;
        case 3:
        default:
            func_ov000_021a57fc(0xb);
            func_0200fcb4(v1);
            return 7;
    }
    func_0200fcb4(v1);
    return 3;
}

s32 func_ov000_021a6428(void) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = func_0200fca0();
    g = data_ov000_021b5f50;
    if (g == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    if (g->mUnk_2260 != 1) {
        func_0200fcb4(v1);
        return 1;
    }
    data_ov000_021b5f50 = 0;
    func_0200fcb4(v1);
    return 0;
}

s32 func_ov000_021a6470(Unk021b5f50 *a, u32 b) {
    u32 v1;

    v1 = func_0200fca0();
    if (data_ov000_021b5f50 != 0) {
        func_0200fcb4(v1);
        return 1;
    }
    if (a == 0) {
        func_0200fcb4(v1);
        return 1;
    }
    if (((u32) a & 0x1f) != 0) {
        func_0200fcb4(v1);
        return 1;
    }
    if (b < sizeof(Unk021b5f50)) {
        func_0200fcb4(v1);
        return 6;
    }
    data_ov000_021b5f50 = a;
    a->mUnk_2260 = 1;
    data_ov000_021b5f50->mUnk_2280 = 0;
    data_ov000_021b5f50->mUnk_2268 = 0;
    data_ov000_021b5f50->mUnk_226a = 0;
    data_ov000_021b5f50->mUnk_226b = 0;
    data_ov000_021b5f50->mUnk_2282 = 0;
    data_ov000_021b5f50->mUnk_22f8 = 0;
    func_ov000_021a5930();
    func_ov000_021a6bdc();
    if (func_0200f6e4() == 0) {
        func_0200f6f4();
    }
    if (func_0200fb18() == 0) {
        func_0200fb28();
    }
    func_0200fb08(&data_ov000_021b5f50->mUnk_22cc);
    func_0200fcb4(v1);
    return 0;
}

void func_ov000_021a6558(Unk021b5f50_2270_0c *a) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    l = g->mUnk_2270;
    if (a != 0 && l != 0 && g->mUnk_2274 > 0xc) {
        for (e = l->mUnk_04; e != 0; e = e->mUnk_0c) {
            if (e == a) {
                if (e->mUnk_08 != 0) {
                    e->mUnk_08->mUnk_0c = e->mUnk_0c;
                } else {
                    l->mUnk_04 = e->mUnk_0c;
                }
                if (e->mUnk_0c != 0) {
                    e->mUnk_0c->mUnk_08 = e->mUnk_08;
                } else {
                    l->mUnk_08 = e->mUnk_08;
                }
                break;
            }
        }
        a->mUnk_0c = 0;
        a->mUnk_08 = l->mUnk_08;
        l->mUnk_08 = a;
        if (a->mUnk_08 != 0) {
            a->mUnk_08->mUnk_0c = a;
        } else {
            l->mUnk_04 = a;
        }
        if (e == 0) {
            a->mUnk_04 = l->mUnk_00;
            l->mUnk_00++;
        }
    }
}

Unk021b5f50_2270_0c *func_ov000_021a65d8(u32 a) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    l = g->mUnk_2270;
    e = 0;
    if (l != 0 && g->mUnk_2274 > 0xc) {
        for (e = l->mUnk_04; e != 0; e = e->mUnk_0c) {
            if (e->mUnk_04 == a) {
                break;
            }
        }
    }
    return e;
}

Unk021b5f50_2270_0c *func_ov000_021a6614(const u8 *a) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    l = g->mUnk_2270;
    e = 0;
    if (a == 0) {
        return 0;
    }
    if (l != 0 && g->mUnk_2274 > 0xc) {
        for (e = l->mUnk_04; e != 0; e = e->mUnk_0c) {
            if (func_ov000_021a6d1c((u8 *) (void *) e->mUnk_10 + 4, a) != 0) {
                break;
            }
        }
    }
    return e;
}
