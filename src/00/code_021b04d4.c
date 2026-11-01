#include "00/code_021b04d4.h"

void func_ov000_021b04f8(u32 a) {
    u32 b;
    Unk0200db5c *c;
    Unk021b04f8 *d;
    s32 i;
    Unk021b69dc *e;

    if (data_ov000_021b63b4 != 0) {
        b = 1;
    } else {
        b = 0;
    }
    data_ov000_021b637c = a;
    data_ov000_021b63b4 = 0;
    data_ov000_021b6380 = 0;
    data_ov000_021b639c = 0;
    data_ov000_021b63d8[0] = 0;
    data_ov000_021b63d8[1] = 0;
    data_ov000_021b638c = 0;
    if (b != 0) {
        func_0214d168(data_ov000_021b6434, 0, 0x60);
        c = data_0216ff5c.mUnk_08;
        if (c != 0) {
            do {
                d = *(Unk021b04f8 **) c->mUnk_a4;
                if (d != 0 && d->mUnk_00 != 0) {
                    if (d->mUnk_08 != 10 && d->mUnk_08 != 11) {
                        d->mUnk_08 = 0;
                    }
                    if (d->mUnk_04 != 0) {
                        d->mUnk_04 = 0;
                        func_0200df68(d->mUnk_00);
                    }
                }
                c = c->mUnk_68;
            } while (c != 0);
        }
        i = 0;
        e = data_ov000_021b69dc;
        for (; i < 8; i++) {
            if (e->mUnk_04 != 0) {
                data_ov000_021b63ac(e->mUnk_34);
                e->mUnk_04 = 0;
            }
            e++;
        }
        func_ov000_021a91b4();
    }
}

void func_ov000_021b04d4(void) {
    if (data_ov000_021b6390 == 0) {
        func_0200dd94();
    } else {
        func_0200dc3c(data_ov000_021b6390);
    }
}
