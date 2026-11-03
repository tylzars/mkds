#include "00/code_021a574c.h"
#include "00/code_021a4000.h"
#include "00/code_021a5000.h"
#include "00/code_021a6000.h"
#include "00/code_021a6abc.h"
#include "00/unk_021b5000.h"
#include "code_02142eac.h"

#include "code_0200fc8c.h"
#include "code_02133048.h"
#include "00/code_021a5b3c.h"
#include "code_0214d018.h"

Unk021b5f50 *func_ov000_021a5b30(void) {
    return data_ov000_021b5f50;
}

void func_ov000_021a5a78(Unk021a5a78 *a, void (*b)(Unk021a586c *)) {
    u8 *p;

    if (a == NULL) {
        data_ov000_021b5f50->mUnk_226c = 3;
        data_ov000_021b5f50->mUnk_2270 = NULL;
        data_ov000_021b5f50->mUnk_2274 = 0;
        data_ov000_021b5f50->mUnk_2278 = 0;
    } else {
        data_ov000_021b5f50->mUnk_226c = a->mUnk_00 & 3;
        p = a->mUnk_04;
        if ((((4 - ((u32) p & 3)) & 3) + 0xc) > a->mUnk_08) {
            data_ov000_021b5f50->mUnk_2270 = NULL;
            data_ov000_021b5f50->mUnk_2274 = 0;
        } else {
            data_ov000_021b5f50->mUnk_2270 = (Unk021b5f50_2270 *) (((u32) p + 3) & ~3);
            data_ov000_021b5f50->mUnk_2274 = a->mUnk_08 - ((4 - ((u32) a->mUnk_04 & 3)) & 3);
            func_0214d168(data_ov000_021b5f50->mUnk_2270, 0, data_ov000_021b5f50->mUnk_2274);
        }
        data_ov000_021b5f50->mUnk_2278 = a->mUnk_0c;
    }
    data_ov000_021b5f50->mUnk_227c = b;
}

void func_ov000_021a5948(const void *a, const u8 *b, u32 c) {
    u16 v;
    s32 i;

    func_ov000_021a5b3c(c);
    data_ov000_021b5f50->mUnk_2288.mUnk_00 = data_ov000_021b5f50->mUnk_1500;
    data_ov000_021b5f50->mUnk_2288.mUnk_04 = 0x400;
    data_ov000_021b5f50->mUnk_2288.mUnk_06 = (1 << func_ov000_021a58dc(0)) >> 1;
    v = data_ov000_021b5f50->mUnk_2268;
    if (v == 0) {
        v = func_02143090();
    }
    data_ov000_021b5f50->mUnk_2288.mUnk_08 = v;
    data_ov000_021b5f50->mUnk_2288.mUnk_10 = (data_ov000_021b5f50->mUnk_2264 & 0x300000) != 0x300000;
    if (a == NULL) {
        func_0214d1fc(data_ov000_021b07bc, data_ov000_021b5f50->mUnk_2288.mUnk_0a, 6);
    } else {
        func_0214d1fc(a, data_ov000_021b5f50->mUnk_2288.mUnk_0a, 6);
    }
    if (b == NULL || b == data_ov000_021b07c4) {
        func_0214d1fc(data_ov000_021b07c4, data_ov000_021b5f50->mUnk_2288.mUnk_14, 0x20);
        data_ov000_021b5f50->mUnk_2288.mUnk_12 = 0;
    } else {
        func_0214d1fc(b, data_ov000_021b5f50->mUnk_2288.mUnk_14, 0x20);
        for (i = 0; i < 0x20; i++) {
            if (*b == 0) {
                break;
            }
            b++;
        }
        data_ov000_021b5f50->mUnk_2288.mUnk_12 = i;
    }
    data_ov000_021b5f50->mUnk_2284 = 0;
}

void func_ov000_021a5930(void) {
    data_ov000_021b5f50->mUnk_2264 = 0xaaa082;
}

u16 func_ov000_021a58dc(u16 a) {
    s32 i;
    s32 j;
    u32 f;

    i = 0;
    j = a;
    f = data_ov000_021b5f50->mUnk_2264;
    do {
        if (f & (1 << (j % 13 + 1))) {
            break;
        }
        j++;
        i++;
    } while (i < 13);
    return (a + i) % 13 + 1;
}

void func_ov000_021a58a4(u32 b, const void *c, u32 d, u32 e) {
    s16 a;

    a = data_ov000_021b5f50->mUnk_2280;
    data_ov000_021b5f50->mUnk_2280 = 0;
    func_ov000_021a586c(a, b, c, d, e);
}

void func_ov000_021a586c(s16 a, u32 b, void *c, u32 d, u32 e) {
    Unk021a586c v;

    if (data_ov000_021b5f50->mUnk_227c != NULL) {
        v.mUnk_00 = a;
        v.mUnk_02 = b;
        v.mUnk_04 = c;
        v.mUnk_08 = d;
        v.mUnk_0c = e;
        data_ov000_021b5f50->mUnk_227c(&v);
    }
}

void func_ov000_021a57fc(u32 a) {
    u32 b;

    b = func_0200fca0();
    if (data_ov000_021b5f50->mUnk_2260 == 9 && a != 9) {
        func_0200f8b8(&data_ov000_021b5f50->mUnk_22cc);
    }
    if (data_ov000_021b5f50->mUnk_2260 != 0xb) {
        data_ov000_021b5f50->mUnk_2260 = a;
    }
    if (a == 9) {
        func_0200f950(&data_ov000_021b5f50->mUnk_22cc, 0x22f5341, func_ov000_021a5794, NULL);
    }
    func_0200fcb4(b);
}

void func_ov000_021a57a8(void) {
    u32 a;

    a = func_0200fca0();
    func_0200f8b8(&data_ov000_021b5f50->mUnk_22cc);
    if (data_ov000_021b5f50->mUnk_2260 == 9) {
        func_0200f950(&data_ov000_021b5f50->mUnk_22cc, 0x22f5341, func_ov000_021a5794, NULL);
    }
    func_0200fcb4(a);
}

void func_ov000_021a5794(void *a) {
    func_ov000_021a6b54();
    func_ov000_021a57a8();
    return;
}

void func_ov000_021a574c(void) {
    if (data_ov000_021b5f50->mUnk_226b == 0) {
        data_ov000_021b5f50->mUnk_226b = 1;
        if (func_02143dd0(func_ov000_021a4bc4) != 2) {
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, NULL, 0, 0x611);
        }
    }
}
