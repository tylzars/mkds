#include "00/code_0219c0f4.h"
#include "00/code_0218b64c.h"
#include "00/code_0219b000.h"
#include "00/code_0219b694.h"
#include "00/code_0219c3b0.h"
#include "00/code_0219c954.h"
#include "00/code_0219caac.h"
#include "00/code_0219d4f8.h"
#include "00/code_0219d8c8.h"
#include "00/code_0219746c.h"
#include "00/code_021971ec.h"
#include "00/code_021a1ae0.h"
#include "00/code_021a31a4.h"
#include "00/code_021a47ac.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_0219b964.h"
#include "00/code_021a2f98.h"

void func_ov000_0219c1e4(void *a, void *b, s32 c, const char *d, const char *e, s32 f, s32 g, void *h, s32 i) {
    u32 n;
    u32 m;
    data_ov000_021b54c8 = a;
    func_ov000_0219c3b0();
    data_ov000_021b54c8->mUnk_00 = 0;
    data_ov000_021b54c8->mUnk_04 = func_ov000_021a1b2c;
    data_ov000_021b54c8->mUnk_08 = func_ov000_0219b4a4;
    data_ov000_021b54c8->mUnk_0c = (s32(*)()) func_ov000_0219b27c;
    data_ov000_021b54c8->mUnk_10 = func_ov000_0219b274;
    data_ov000_021b54c8->mUnk_14 = f == 0 ? 0x2000 : f;
    data_ov000_021b54c8->mUnk_18 = g == 0 ? 0x2000 : g;
    data_ov000_021b54c8->mUnk_1c.mUnk_00 = 0;
    data_ov000_021b54c8->mUnk_20 = b;
    data_ov000_021b54c8->mUnk_24 = 0;
    data_ov000_021b54c8->mUnk_28 = 0;
    data_ov000_021b54c8->mUnk_2c = 0;
    data_ov000_021b54c8->mUnk_2d = 0;
    data_ov000_021b54c8->mUnk_2e = 0;
    data_ov000_021b54c8->mUnk_30 = 0;
    data_ov000_021b54c8->mUnk_54 = data_ov000_021b4e84;
    data_ov000_021b54c8->mUnk_58 = data_ov000_021b4f84;
    data_ov000_021b54c8->mUnk_5c = 0;
    data_ov000_021b54c8->mUnk_60 = 0;
    data_ov000_021b54c8->mUnk_64 = 0;
    data_ov000_021b54c8->mUnk_68 = 0;
    data_ov000_021b54c8->mUnk_6c = 0;
    data_ov000_021b54c8->mUnk_70 = 0;
    data_ov000_021b54c8->mUnk_74 = 0;
    data_ov000_021b54c8->mUnk_78 = 0;
    data_ov000_021b54c8->mUnk_7c = 0;
    data_ov000_021b54c8->mUnk_80 = 0;
    func_ov000_0219b964();
    func_ov000_0219caac(&data_ov000_021b54c8->mUnk_84, b, &data_ov000_021b54c8->mUnk_1c, c,
                        ((Unk02152500 *) b)->mUnk_24, func_ov000_0219b6c0, 0);
    func_ov000_0219d8c8(&data_ov000_021b54c8->mUnk_2e8, &data_ov000_021b54c8->mUnk_1c, data_ov000_021b54c8->mUnk_34, h,
                        i);
    func_ov000_021a2870(&data_ov000_021b54c8->mUnk_33c, &data_ov000_021b54c8->mUnk_1c, &data_ov000_021b54c8->mUnk_00,
                        &data_ov000_021b54c8->mUnk_04, data_ov000_021b4e84, data_ov000_021b4f84, h, i);
    func_ov000_021a31a4(&data_ov000_021b54c8->mUnk_7a0);
    if (func_0213a434((const u8 *) d) < 0x100) {
        n = func_0213a434((const u8 *) d);
    } else {
        n = 0xff;
    }
    func_0214d1fc(d, data_ov000_021b4e84, n);
    data_ov000_021b4e84[n] = 0;
    if (func_0213a434((const u8 *) e) < 0x100) {
        m = func_0213a434((const u8 *) e);
    } else {
        m = 0xff;
    }
    func_0214d1fc(e, data_ov000_021b4f84, m);
    data_ov000_021b4f84[m] = 0;
}

void func_ov000_0219c0f4(void) {
    if (data_ov000_021b54c8 != 0) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_10 != 0) {
            func_ov000_021a47ac(data_ov000_021b54c8->mUnk_33c.mUnk_10);
            data_ov000_021b54c8->mUnk_33c.mUnk_10 = 0;
        }
        data_ov000_021b54c8->mUnk_33c.mUnk_18 = 0;
        if (data_ov000_021b54c8->mUnk_33c.mUnk_e4 != 0) {
            func_ov000_0218b64c(data_ov000_021b54c8->mUnk_33c.mUnk_e4);
            data_ov000_021b54c8->mUnk_33c.mUnk_e4 = 0;
        }
        func_ov000_0219b110();
        func_ov000_02197634();
        if (data_ov000_021b54c8->mUnk_1c.mUnk_00 != 0) {
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 0, 0, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 3, 0, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 1, 0, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 2, 0, 0);
            func_ov000_0218f268(&data_ov000_021b54c8->mUnk_1c);
            func_ov000_0218f2a0(&data_ov000_021b54c8->mUnk_1c);
            data_ov000_021b54c8->mUnk_1c.mUnk_00 = 0;
        }
        func_ov000_0219c954();
        func_ov000_0219d4f8();
        func_ov000_021a1430();
        func_ov000_021a2fec();
        if (data_ov000_021b54c8->mUnk_00 != 0) {
            func_ov000_02198ab0(data_ov000_021b54c8->mUnk_00);
            data_ov000_021b54c8->mUnk_00 = 0;
        }
        data_ov000_021b54c8 = 0;
    }
}
