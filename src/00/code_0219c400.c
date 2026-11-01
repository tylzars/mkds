#include "00/code_0219c400.h"
#include "00/code_0219c000.h"
#include "00/code_0219c79c.h"
#include "00/code_0218ee1c.h"
#include "00/code_0218f130.h"
#include "00/code_021874ec.h"
#include "00/code_021a369c.h"
#include "00/code_021a1ae0.h"
#include "code_0200f5ac.h"
#include "code_02133048.h"
#include "code_021329f8.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_02152500.h"
#include "code_021526bc.h"
#include "code_021526e4.h"
#include "code_02152a7c.h"
#include "Main/Unknown/code_021526c8.h"

void func_ov000_0219c400(Unk0218f960 *a, Unk0219c400 *b, u32 f) {
    char c[0x15];
    char d[0x15];
    char e[0x15];
    Unk021b565c *p;
    if (b->mUnk_00 != 0) {
        return;
    }
    p = data_ov000_021b565c;
    if (p->mUnk_04 == 3) {
        if (b->mUnk_8e[0] == 0) {
            func_02152808(&p->mUnk_20->mUnk_04, p->mUnk_0c, c);
            if (func_ov000_0219c8dc(func_ov000_0218efa8(a, 0x705, (const s8 *) c)) == 0) {
                data_ov000_021b565c->mUnk_04 = 4;
                if (func_ov000_0219c8dc(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                    return;
                }
            }
        } else {
            func_ov000_0218f130(a);
            func_ov000_0219c67c(func_ov000_0219c80c, 0);
            data_ov000_021b565c->mUnk_04 = 1;
        }
    } else if (p->mUnk_04 == 4) {
        func_02152808(&p->mUnk_20->mUnk_04, p->mUnk_0c, d);
        if (func_0213a074((const u8 *) b->mUnk_8e, (const u8 *) d) == 0) {
            func_02152808(&data_ov000_021b565c->mUnk_40, data_ov000_021b565c->mUnk_0c, e);
            func_021525f0(data_ov000_021b565c->mUnk_20, &data_ov000_021b565c->mUnk_40, b->mUnk_04);
            func_ov000_0218f130(a);
            data_ov000_021b5660(data_ov000_021b565c->mUnk_4c, data_ov000_021b565c->mUnk_14c, data_ov000_021b5658);
        } else {
            if (func_ov000_0219c8dc(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                return;
            }
        }
    }
}

void func_ov000_0219c524(void) {
    Unk02186560 s;
    Unk0218635c x;
    Unk0218635c y;
    if (func_ov000_021863cc() == 0x14) {
        func_ov000_0218635c(&x.mUnk_000);
        func_0213a2d0(data_ov000_021b565c->mUnk_4c, x.mUnk_04a);
        func_0213a2d0(data_ov000_021b565c->mUnk_14c, x.mUnk_177);
        func_ov000_02186430();
        func_ov000_021a3704(0, (u32) data_ov000_021b565c->mUnk_28, 0);
        data_ov000_021b565c->mUnk_28 = 0;
        if (func_021526bc(data_ov000_021b565c->mUnk_20) != 0) {
            data_ov000_021b5660(data_ov000_021b565c->mUnk_4c, data_ov000_021b565c->mUnk_14c, data_ov000_021b5658);
        } else {
            func_ov000_0219c79c(data_ov000_021b565c->mUnk_4c, data_ov000_021b565c->mUnk_14c, func_ov000_0219c824, 3);
        }
    } else if (func_ov000_021863cc() != 0) {
        if ((((u64) func_0200f5ac() - *(u64 *) &data_ov000_021b565c->mUnk_2c) << 6) / 0x82ea > 0x2710) {
            func_ov000_0218635c(&y.mUnk_000);
            func_ov000_02186430();
            func_ov000_021a3704(0, (u32) data_ov000_021b565c->mUnk_28, 0);
            data_ov000_021b565c->mUnk_28 = 0;
            func_ov000_0219c990(2, y.mUnk_000);
        } else {
            func_ov000_02186430();
            func_0214d168(&s, 0, 0x2c);
            func_0213a2d0((char *) s.mUnk_15, (const u8 *) data_ov000_021b565c->mUnk_255);
            s.mUnk_24 = (void *(*) (const void *, u32)) func_ov000_021a372c;
            s.mUnk_28 = (void (*)(const void *, void *, u32)) func_ov000_021a3704;
            func_ov000_02186560(&s, data_ov000_021b565c->mUnk_28);
        }
    }
}

void func_ov000_0219c67c(void (*a)(), void *b) {
    Unk02186560 s;
    void *h;
    u64 t;
    func_0214d168(&s, 0, 0x2c);
    data_ov000_021b5660 = a;
    data_ov000_021b5658 = b;
    if (func_021526bc(data_ov000_021b565c->mUnk_20) != 0) {
        func_02152808(&data_ov000_021b565c->mUnk_20->mUnk_10, data_ov000_021b565c->mUnk_20->mUnk_24,
                      data_ov000_021b565c->mUnk_24c);
    } else {
        if (func_021526c8(&data_ov000_021b565c->mUnk_40) == 0) {
            if (func_021526e4(&data_ov000_021b565c->mUnk_20->mUnk_04) != 0) {
                data_ov000_021b565c->mUnk_40 = data_ov000_021b565c->mUnk_20->mUnk_04;
            } else {
                func_02152744(&data_ov000_021b565c->mUnk_40);
            }
        } else {
            func_02152a88(&data_ov000_021b565c->mUnk_40,
                          (u32) (((s64) func_0200f5ac() * 0x5d588b656c078965 + 0x269ec3) >> 32));
        }
        func_02152808(&data_ov000_021b565c->mUnk_40, data_ov000_021b565c->mUnk_0c, data_ov000_021b565c->mUnk_24c);
    }
    func_0213a2d0((char *) s.mUnk_15, (const u8 *) data_ov000_021b565c->mUnk_255);
    s.mUnk_24 = (void *(*) (const void *, u32)) func_ov000_021a372c;
    s.mUnk_28 = (void (*)(const void *, void *, u32)) func_ov000_021a3704;
    h = func_ov000_021a3718(0, 0x1a60, 4);
    data_ov000_021b565c->mUnk_28 = h;
    t = func_0200f5ac();
    *(u64 *) &data_ov000_021b565c->mUnk_2c = t;
    func_ov000_02186560(&s, h);
}
