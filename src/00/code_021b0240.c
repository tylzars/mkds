#include "00/code_021a8878.h"
#include "00/code_021afe5c.h"
#include "00/code_021b0014.h"
#include "00/code_021b0240.h"
#include "code_0200db4c.h"
#include "00/code_021af550.h"
#include "code_0214d018.h"
#include "00/unk_021b6000.h"
#include "03/code_021b94b8.h"
#include "00/code_021a91b4.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/code_021ae314.h"
#include "00/code_021ad754.h"

#include "code_0200fc8c.h"
#include "00/code_021adbac.h"
#include "00/unk_021b6380.h"
#include "02/unk_02180500.h"
#include "code_02133048.h"
#include "code_0200f5ac.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_02000b44.h"

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
        MemFill(data_ov000_021b6434, 0, 0x60);
        c = data_0216ff5c.mUnk_08;
        if (c != NULL) {
            do {
                d = *(Unk021b04f8 **) c->mUnk_a4;
                if (d != NULL && d->mThread != NULL) {
                    if (d->mState != 10 && d->mState != 11) {
                        d->mState = 0;
                    }
                    if (d->mUnk_04 != 0) {
                        d->mUnk_04 = 0;
                        func_0200df68(d->mThread);
                    }
                }
                c = c->mUnk_68;
            } while (c != NULL);
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

void func_ov000_021b04d0(void) {}

s32 func_ov000_021b04cc(void) {
    return 1;
}

void func_ov000_021b02fc(Unk021b5fa8 *a) {
    func_02000b44(0x2000bfc);
    if (*(u64 *) &a->mUnk_14 != 0) {
        data_ov000_021b63e0[0] = *(u64 *) &a->mUnk_14;
        data_ov000_021b63e0[1] = 0x5d588b656c078965ULL;
        data_ov000_021b63e0[2] = 0x269ec3;
    } else {
        data_ov000_021b63e0[0] = func_0200f5ac();
        data_ov000_021b63e0[1] = 0x5d588b656c078965ULL;
        data_ov000_021b63e0[2] = 0x269ec3;
    }
    if (a->mUnk_04 != NULL && a->mUnk_08 != NULL) {
        data_ov000_021b63a4 = (u8 * (*) (u32)) a->mUnk_04;
        data_ov000_021b63ac = a->mUnk_08;
    } else {
        data_ov000_021b63a4 = (u8 * (*) (u32)) func_ov000_021b04d0;
        data_ov000_021b63ac = (void (*)(void *)) func_ov000_021b04d0;
    }
    data_ov000_021b6398 = a->mUnk_00;
    if (a->mUnk_24 != 0) {
        data_ov000_021b6370 = a->mUnk_24;
    } else {
        data_ov000_021b6370 = 0x5b4;
    }
    data_ov000_021b63bc = a->mUnk_28;
    data_ov000_021b6390 = a->mUnk_2c;
    if (a->mUnk_0c != NULL) {
        data_ov000_021b6384 = a->mUnk_0c;
    } else {
        data_ov000_021b6384 = func_ov000_021b04d0;
    }
    if (a->mUnk_10 != NULL) {
        data_ov000_021b6388 = a->mUnk_10;
    } else {
        data_ov000_021b6388 = (u32(*)(void)) func_ov000_021b04cc;
    }
    data_ov000_021b63c4 = a->mUnk_1c;
    data_ov000_021b63c8 = a->mUnk_20;
    data_ov000_021b63cc = 0;
    data_ov000_021b6394 = 0;
    data_ov000_021b63e0[0] = _ll_mul(data_ov000_021b63e0[1], data_ov000_021b63e0[0]) + data_ov000_021b63e0[2];
    data_ov000_021b6374 = (_ll_mul(data_ov000_021b63e0[0] >> 32, 0xf88) >> 32) + 0x400;
    func_0200fe58(data_ov000_021b63d0);
    data_ov000_021b6368 = 0;
    func_0200e28c(&data_ov000_021b661c, (void (*)(void *)) func_ov000_021ae3a4, NULL, data_ov002_021b7ba0, 0x800,
                  data_ov000_021b4c28);
    func_0200e28c(&data_ov000_021b655c, (void (*)(void *)) func_ov000_021ad898, NULL, data_ov000_021b73a0, 0x800,
                  data_ov000_021b4c28);
    func_0200df68(&data_ov000_021b661c);
    func_0200df68(&data_ov000_021b655c);
}

s32 func_ov000_021b02bc(void) {
    u32 a;
    s32 b;

    a = IrqDisable();
    b = func_0200e070(&data_ov000_021b655c);
    if (b == 0 && data_ov000_021b63b0 == 0) {
        data_ov000_021b63b0 = 1;
        func_0200df68(&data_ov000_021b655c);
    }
    IrqRestore(a);
    return b;
}

void func_ov000_021b02b0(UnkFunc *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_ov000_021b63a8;
    *(u32 *) ((value1) + 0u) = value0;
    return;
}

void func_ov000_021b026c(void) {
    func_ov000_021b02bc();
    func_0200e084(&data_ov000_021b655c);
    func_0200e0ec(&data_ov000_021b661c);
    data_ov000_021b63c0 = NULL;
    func_ov000_021b04f8(0);
    data_ov000_021b63c4 = NULL;
    data_ov000_021b63c8 = 0;
}

void func_ov000_021b0240(s32 a) {
    data_ov000_021b4c28 = a;
    func_0200dce0(&data_ov000_021b661c, a);
    func_0200dce0(&data_ov000_021b655c, a);
}
