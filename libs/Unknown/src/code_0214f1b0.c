#include "code_0214f1b0.h"
#include "code_0214eed8.h"
#include "code_0214ef00.h"
#include "code_0214d5b8.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0214eef0.h"

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
