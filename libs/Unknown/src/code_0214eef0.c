#include "code_0214eef0.h"

#include "code_0214d5b8.h"
#include "code_0200fc8c.h"
#include "code_0214eed8.h"
#include "Main/Unknown/code_0200f000.h"

u16 data_02180410;

void func_0214f418(void) {
    if (data_02180410 != 0) {
        return;
    }
    data_02180410 = 1;
    data_02180414.mUnk_00 = 0;
    data_02180414.mUnk_04 = 0;
    func_0214d5b8();
    while (!func_0214d79c(9, 1)) {
    }
    *(u32 *) 0x27fff90 = 0;
    func_0214d7c4(9, func_0214f060);
}

u32 func_0214f2a8(Unk0214f2a8 *p, void (*fn)(), u32 arg) {
    u32 f;
    u32 v;
    u32 b;
    u8 g;

    if ((p->mUnk_04 & 0x1f) != 0) {
        return 2;
    }
    b = p->mUnk_08;
    if ((b & 0x1f) != 0) {
        return 2;
    }
    if (b == 0) {
        return 2;
    }
    if (p->mUnk_0c < 0x400) {
        return 2;
    }
    switch (p->mUnk_00) {
        case 0:
            f = 0;
            break;
        case 1:
            f = 1;
            break;
        case 2:
            f = 2;
            break;
        case 3:
            f = 3;
            break;
        case 4:
            f = 5;
            break;
        case 5:
            f = 7;
            break;
        default:
            return 2;
    }
    g = p->mUnk_10 != 0 ? (f | 0x10) & 0xff : f & 0xff;
    v = func_0200fca0();
    if (data_02180414.mUnk_00 != 0) {
        func_0200fcb4(v);
        return 1;
    }
    data_02180414.mUnk_00 = 1;
    func_0200fcb4(v);
    data_02180414.mUnk_04 = fn;
    data_02180414.mUnk_08 = arg;
    data_02180414.mUnk_10 = p->mUnk_14;
    data_02180414.mUnk_14 = p->mUnk_18;
    return func_0214ef34(p->mUnk_04, p->mUnk_08, p->mUnk_0c, g) != 0 ? 0 : 3;
}

u32 func_0214f264(Unk0214f2a8 *p) {
    data_02180414.mUnk_0c = func_0214f2a8(p, func_0214eef0, 0);
    if (data_02180414.mUnk_0c == 0) {
        func_0214eed8();
    }
    return data_02180414.mUnk_0c;
}

u32 func_0214f1f4(void (*fn)(), u32 arg) {
    u32 v = func_0200fca0();

    if (data_02180414.mUnk_00 != 0) {
        func_0200fcb4(v);
        return 1;
    }
    data_02180414.mUnk_00 = 1;
    func_0200fcb4(v);
    data_02180414.mUnk_04 = fn;
    data_02180414.mUnk_08 = arg;
    return func_0214ef00() != 0 ? 0 : 3;
}

u32 func_0214f1b0(void) {
    data_02180414.mUnk_0c = func_0214f1f4(func_0214eef0, 0);
    if (data_02180414.mUnk_0c == 0) {
        func_0214eed8();
    }
    return data_02180414.mUnk_0c;
}

u32 func_0214f1a0(void) {
    u32 value0;
    value0 = 0x27fff90u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}

void func_0214f060(u32 a, u32 b, u32 c) {
    u16 x;
    u16 k;
    u32 n;

    if (c != 0) {
        if (data_02180414.mUnk_00 != 0) {
            data_02180414.mUnk_00 = 0;
        }
        if (data_02180414.mUnk_04 != 0) {
            void (*g)() = data_02180414.mUnk_04;
            data_02180414.mUnk_04 = 0;
            g(6, data_02180414.mUnk_08);
        }
    }
    x = b & 0xff;
    k = (b & 0x7f00) >> 8;
    switch (x) {
        case 0:
            n = 0;
            break;
        case 1:
            n = 4;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 5;
            break;
        case 4:
            n = 1;
            break;
        default:
            n = 6;
            break;
    }
    if (k == 0x51) {
        if (data_02180414.mUnk_10 != 0) {
            data_02180414.mUnk_10(n, data_02180414.mUnk_14);
        }
        return;
    }
    if (k == 0x40) {
        if (data_02180414.mUnk_18 != 0) {
            *data_02180414.mUnk_18 = *(u16 *) 0x27fff94;
        }
    }
    if (data_02180414.mUnk_00 != 0) {
        data_02180414.mUnk_00 = 0;
    }
    if (data_02180414.mUnk_04 != 0) {
        void (*f)() = data_02180414.mUnk_04;
        data_02180414.mUnk_04 = 0;
        f(n, data_02180414.mUnk_08);
    }
}

u32 func_0214ef34(u32 a, u32 b, u32 c, u32 d) {
    if (func_0214d6e8(9, d | 0x2004100, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (a >> 16) | 0x10000, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (a & 0xffff) | 0x20000, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (b >> 16) | 0x30000, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (b & 0xffff) | 0x40000, 0) < 0) {
        return 0;
    }
    if (func_0214d6e8(9, (c >> 16) | 0x50000, 0) < 0) {
        return 0;
    }
    return func_0214d6e8(9, (c & 0xffff) | 0x1060000, 0) >= 0;
}

s32 func_0214ef00(void) {
    return func_0214d6e8(9, 0x3004200, 0) >= 0;
}

void func_0214eef0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_02180414;
    *(u32 *) ((value1) + (12)) = value0;
}
