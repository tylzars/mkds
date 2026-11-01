#include "03/code_021bb0b0.h"
#include "03/code_021bb03c.h"
#include "03/code_021bb328.h"
#include "03/code_021bcedc.h"
#include "03/code_021be3b8.h"
#include "03/code_021be418.h"
#include "Main/Unknown/code_0200db4c.h"
#include "code_0200dc3c.h"
#include "code_0214d018.h"

s32 func_ov003_021bb2d8(u8 *a, s8 b) {
    u8 *c = a;
    u8 w = b;
    s32 i;
    s32 d;
    s32 e;
    d = (w & 0xf0) >> 4;
    i = 0;
    e = w & 0xf;
    for (; i < 2; i++) {
        if (d <= 9) {
            *c++ = d + 0x30;
        } else {
            *c++ = d + 0x37;
        }
        d = e;
    }
    *c = 0;
    return c - a;
}

s32 func_ov003_021bb29c(u8 *a, const s8 *b) {
    u8 *c = a;
    s32 i;
    for (i = 0; i < 6; i++) {
        c += func_ov003_021bb2d8(c, *b++);
        if (i < 5) {
            *c++ = ':';
        }
    }
    *c = 0;
    return c - a;
}

s32 func_ov003_021bb168(u32 a, s32 b, UnkFunc *c, UnkWordFunc *d, UnkFunc *e, u32 f) {
    s32 g;
    if (data_ov003_021d8c08 >= 1 && data_ov003_021d8c08 <= 5) {
        return -10;
    }
    data_ov003_021d68bc = b;
    data_ov003_021d8c08 = 7;
    data_ov003_021d8c4c = c;
    data_ov003_021d8bd4 = d;
    data_ov003_021d8bdc = e;
    data_ov003_021d68b4 = f;
    g = func_ov003_021be418(b);
    data_ov003_021d8c44 = 1;
    if (g < 0) {
        data_ov003_021d8c48 = g;
        return g;
    }
    data_ov003_021d8c00 = (void *) data_ov003_021d8bd4(data_ov003_021d68b4);
    if (data_ov003_021d8c00 == 0) {
        data_ov003_021d8c48 = -1;
        return -1;
    }
    if (func_0200db4c() != 1) {
        data_ov003_021d8c48 = -9;
        return -9;
    }
    func_0200e28c(&data_ov003_021d8d08, (void (*)(void *)) func_ov003_021bcedc, 0,
                  (u8 *) data_ov003_021d8c00 + (data_ov003_021d68b4 & ~7), data_ov003_021d68b4, a);
    data_ov003_021d8c08 = 1;
    data_ov003_021d68b8 = func_ov003_021bb354() + 60000;
    data_ov003_021d8be0 = 0;
    __clear(&data_ov003_021d8dc8, 0xe8);
    func_ov003_021bb03c();
    func_0200df68(&data_ov003_021d8d08);
    data_ov003_021d8c34 = 1;
    return 1;
}

s32 func_ov003_021bb0b0(void) {
    s32 a;
    if (data_ov003_021d8c34 != 0) {
        a = data_ov003_021d8c08;
        data_ov003_021d8be0 = 1;
        while (data_ov003_021d8c08 >= 1 && data_ov003_021d8c08 <= 5) {
            func_0200dc3c(100);
        }
        func_0200dc3c(500);
        if (func_0200e070(&data_ov003_021d8d08) == 0) {
            do {
                func_0200df68(&data_ov003_021d8d08);
                func_0200e084(&data_ov003_021d8d08);
            } while (func_0200e070(&data_ov003_021d8d08) == 0);
        }
        if (data_ov003_021d8c00 != 0) {
            data_ov003_021d8bdc(data_ov003_021d8c00);
            data_ov003_021d8c00 = 0;
        }
        data_ov003_021d8c34 = 0;
        if (a != data_ov003_021d8c08) {
            func_ov003_021bb03c();
        }
    }
    if (data_ov003_021d8c44 > 0) {
        s32 b = func_ov003_021be3b8();
        data_ov003_021d8c44 = 0;
        return b;
    }
    return -10;
}
