#include "03/code_021b9278.h"

#include "03/code_021b7bb4.h"

s32 func_ov003_021b94ac(void) {
    u32 value0;
    value0 = (u32) &data_ov003_021d7c50;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    return (s32) value0;
}

s32 func_ov003_021b929c(Unk021b94c4 *a) {
    u8 *p = (u8 *) a + 0x117;
    Unk021d8374 *b = &data_ov003_021d8374;
    Unk021d8374 *c = &data_ov003_021d84a4;
    Unk021d8374 *d = &data_ov003_021d85d4;
    Unk021d8374 *e = &data_ov003_021d8644;
    if (p == NULL) {
        return -1;
    }
    a->mUnk_000 = data_ov003_021d7c6c.mUnk_08 & data_ov003_021d7c6c.mUnk_0c;
    func_ov003_021b7d84(p, 0, 0x154);
    if (a->mUnk_000 & 1) {
        func_ov003_021b7d90(p, b->mUnk_30, b->mUnk_04);
        func_ov003_021b7d90(p + 6, b->mUnk_70, b->mUnk_04);
        func_ov003_021b7d90(p + 0xc, b->mUnk_b0, b->mUnk_04);
        func_ov003_021b7d90(p + 0x12, b->mUnk_f0, b->mUnk_04);
        if (func_ov003_021b9278(b->mUnk_08, func_ov003_021b7c30(b->mUnk_08)) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0x18, b->mUnk_08, func_ov003_021b7c30(b->mUnk_08));
    }
    if (a->mUnk_000 & 2) {
        func_ov003_021b7d90(p + 0x39, c->mUnk_30, c->mUnk_04);
        func_ov003_021b7d90(p + 0x47, c->mUnk_70, c->mUnk_04);
        func_ov003_021b7d90(p + 0x55, c->mUnk_b0, c->mUnk_04);
        func_ov003_021b7d90(p + 0x63, c->mUnk_f0, c->mUnk_04);
        if (func_ov003_021b9278(c->mUnk_08, func_ov003_021b7c30(c->mUnk_08)) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0x71, c->mUnk_08, func_ov003_021b7c30(c->mUnk_08));
    }
    if (a->mUnk_000 & 4) {
        if (func_ov003_021b9278(d->mUnk_30, d->mUnk_04 - 1) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0x92, d->mUnk_30, d->mUnk_04);
        if (func_ov003_021b9278(d->mUnk_08, func_ov003_021b7c30(d->mUnk_08)) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0xd2, d->mUnk_08, func_ov003_021b7c30(d->mUnk_08));
    }
    if (a->mUnk_000 & 8) {
        if (func_ov003_021b9278(e->mUnk_30, e->mUnk_04 - 1) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0xf3, e->mUnk_30, e->mUnk_04);
        if (func_ov003_021b9278(e->mUnk_08, func_ov003_021b7c30(e->mUnk_08)) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0x133, e->mUnk_08, func_ov003_021b7c30(e->mUnk_08));
    }
    a->mUnk_116 = 0;
    return 0;
fail:
    func_ov003_021b7d84(p, 0, 0x154);
    return -1;
}

s32 func_ov003_021b9278(const u8 *bytes, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        u32 value = *bytes++;
        if (value < 0x20 || value > 0x7f) {
            return -1;
        }
    }
    return 0;
}
