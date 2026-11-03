#include "code_02010c84.h"
#include "code_02147288.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"

void func_02010f74(u32 a, u32 b, u32 c) {
    data_0217029c.mUnk_94 = a | (b << 16) | ((c != 0) << 15);
}

void func_02010f50(u32 a, u32 b, u32 c) {
    data_0217029c.mUnk_98 = a | (b << 16) | ((c != 0) << 15);
}

void func_02010f24(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    data_0217029c.mUnk_9c = (f | (a | (b << 4) | (c << 6))) | (d << 24) | (e << 16);
}

Unk02012f58 *func_02010ed4(void) {
    if (!(data_0217029c.mUnk_fc & 0x8)) {
        func_0214755c(&data_0217029c.mUnk_4c, &data_0217029c.mUnk_100[0]);
        data_0217029c.mUnk_fc |= 0x8;
    }
    return &data_0217029c.mUnk_100[0];
}

void func_02010e70(void) {
    func_0214733c(&data_0217029c.mUnk_bc, &data_0217029c.mUnk_4c, &data_0217029c.mUnk_100[1]);
    func_02147914(&data_0217029c.mUnk_100[1], &data_0217029c.mUnk_100[1], data_0217029c.mUnk_ec.x, data_0217029c.mUnk_ec.y,
                  data_0217029c.mUnk_ec.z);
    func_0214755c(&data_0217029c.mUnk_100[1], &data_0217029c.mUnk_100[2]);
}

Unk02012f58 *func_02010e2c(void) {
    if (!(data_0217029c.mUnk_fc & 0x80)) {
        func_02010e70();
        data_0217029c.mUnk_fc |= 0x80;
    }
    return &data_0217029c.mUnk_100[1];
}

Unk02012f58 *func_02010de8(void) {
    if (!(data_0217029c.mUnk_fc & 0x80)) {
        func_02010e70();
        data_0217029c.mUnk_fc |= 0x80;
    }
    return &data_0217029c.mUnk_100[2];
}

u32 func_02010d98(const u8 *a, const Unk02010d98 *b) {
    switch (*a) {
        case 0x4d:
            return ((b->mUnk_18 << 1) + 0x1c) & ~3;
        case 0x4a:
        case 0x56:
            return ((b->mUnk_17 << 1) + 0x1c) & ~3;
        default:
            return 0;
    }
}

void func_02010cec(Unk02010c84 *a, const Unk02010cec_08 *b, u32 c, u32 d) {
    u32 i;

    a->mUnk_00 = 0;
    a->mUnk_08 = b;
    a->mUnk_10 = 0;
    a->mUnk_18 = 0x7f;
    a->mUnk_04 = 0x1000;
    a->mUnk_14 = d;
    for (i = 0; i < data_021617d0; i++) {
        if (b->mUnk_00 == data_021617f4[i].mUnk_00 && b->mUnk_02 == data_021617f4[i].mUnk_02) {
            data_021617f8[i].mUnk_00(a, b, c);
            return;
        }
    }
}

void func_02010c84(Unk02010c84 *a, u32 b) {
    volatile u32 z = 0;

    func_0214d018(z, a, 0x54);
    a->mUnk_0c = data_021617f0;
    a->mUnk_14 = data_021617ec;
    a->mUnk_1c = data_021617e8;
    a->mUnk_04 = b;
}
