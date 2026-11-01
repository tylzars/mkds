#include "Main/Unknown/code_02006c2c.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_0200704c.h"
#include "Main/Unknown/code_02007034.h"
#include "Main/Unknown/code_020070b0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0214d000.h"

#pragma thumb on

s32 func_02006e74(Unk02007014 *a, u32 b, const void *c, u8 *d, u32 e, u16 f) {
    Unk02007014 *v1;
    u32 v2;
    v2 = func_0200fca0();
    if (func_02007040() == 0) {
        func_02007034((u32) a);
    } else {
        for (v1 = func_02007040(); v1->mUnk_28 != 0; v1 = v1->mUnk_28) {
        }
        v1->mUnk_28 = a;
    }
    if (d == 0) {
        a->mUnk_32 = 1;
    } else {
        a->mUnk_2c = d;
        a->mUnk_32 = 0;
    }
    a->mUnk_28 = 0;
    a->mUnk_00 = b;
    a->mUnk_04 = e;
    a->mUnk_30 = f;
    if (c != 0) {
        func_0214d1fc(c, a->mUnk_08, 0x20);
    } else {
        func_0214d168(a->mUnk_08, 0, 0x20);
    }
    func_0200fcb4(v2);
    return 1;
}

Unk02007014 *func_02006df8(u32 a) {
    Unk02007014 *v1;
    Unk02007014 *v2;
    u32 v3;
    v3 = func_0200fca0();
    v1 = func_02007040();
    if (v1 == 0) {
        func_0200fcb4(v3);
        return 0;
    }
    if (v1->mUnk_00 == a) {
        func_02007034((u32) v1->mUnk_28);
        func_0200fcb4(v3);
        return v1;
    }
    for (v2 = v1->mUnk_28; v2 != 0; v1 = v2, v2 = v2->mUnk_28) {
        if (v2->mUnk_00 == a) {
            v1->mUnk_28 = v2->mUnk_28;
            func_0200fcb4(v3);
            return v2;
        }
    }
    func_0200fcb4(v3);
    return 0;
}

u32 func_02006ddc(u16 a, void (*b)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    v1.mUnk_00 = 2;
    v1.mUnk_08 = a;
    v1.mUnk_10 = b;
    return func_0200704c(&v1);
}

u32 func_02006db0(u16 a, u32 b, const void *c, void (*d)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    v1.mUnk_00 = 6;
    v1.mUnk_08 = a;
    v1.mUnk_10 = d;
    v1.mUnk_14 = b;
    v1.mUnk_18 = 0x28;
    func_0214d02c(c, &v1.mUnk_1c, 0x40);
    return func_0200704c(&v1);
}

u32 func_02006d78(u16 a, u32 b, const void *c, u32 d, const void *e, void (*f)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    v1.mUnk_00 = 4;
    v1.mUnk_08 = a;
    v1.mUnk_10 = f;
    v1.mUnk_14 = b;
    v1.mUnk_18 = d;
    func_0214d02c(c, &v1.mUnk_1c, 0x40);
    func_0214d02c(e, &v1.mUnk_5c, 0x40);
    return func_0200704c(&v1);
}

u32 func_02006d3c(u16 a, const void *b, s32 c, void (*d)(void)) {
    Unk0216f3dc_9c v1;
    Unk0216f3dc_9c *v2;
    if (c < 0 || c > 9) {
        return 0;
    }
    v1.mUnk_00 = 10;
    v2 = &v1;
    v2->mUnk_08 = a;
    v2->mUnk_10 = (void (*)(Unk0216f3dc_9c *)) d;
    func_0214d1fc(b, &v2->mUnk_14, c);
    *((u8 *) v2 + 0x1d) = c;
    return func_0200704c(&v1);
}

s32 func_02006c2c(s32 a, s32 b) {
    Unk0216f3dc *v1;
    s32 i;
    s32 v2;
    v1 = func_020070b8();
    i = data_0216177c;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        v2 = func_02005cc8(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = func_02005d4c(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = func_02005b80(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = func_02005d08(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
    } while (i != data_0216177c);
    v2 = func_02005a30(v1, a, b);
    if (v2 != 0) {
        return v2;
    }
    v2 = func_0200589c(v1, a, b);
    if (v2 != 0) {
        return v2;
    }
    i = data_0216177c;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        v2 = func_02005bec(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
    } while (i != data_0216177c);
    for (i = 1; i < 16; i++) {
        v2 = func_02005b18(v1, i, a, b);
        if (v2 != 0) {
            return v2;
        }
    }
    return func_020068b4(a, 0xfffe, 0);
}

#pragma thumb off
