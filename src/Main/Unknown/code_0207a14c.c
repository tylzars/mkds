#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218155c.h"

void func_0207a2d4(s32 a) {
    if (data_usa_021658c0 < 0 || a < data_usa_021658c0) {
        data_usa_021658c0 = a;
        data_0217ad20 = 1;
    }
}

s32 func_0207a2a8(s32 *a) {
    if (data_0217ad20 == 0) {
        return 0;
    }
    *a = data_usa_021658c0;
    return 1;
}

s32 func_0207a218(void) {
    s32 r = 1;
    s32 m = data_021759c0->mUnk_08;
    if (m == 4) {
        Unk0206bcb0 *p = &data_0217ad18[data_021759c0->mUnk_62];
        if (p->mUnk_180 != 0 || (p->mUnk_48 & 0x2000840) != 0 || (p->mUnk_44 & 0x10) == 0 ||
            (m != 4 ? 0 : func_ov001_021816b4()) != 0) {
            r = 0;
        }
    }
    return r;
}

void func_0207a14c(Unk0201290c *a, u32 b) {
    u32 c;
    u32 d;
    u32 e;
    u32 f;
    switch (b) {
        case 0: {
            u16 *p = (u16 *) gKartModels->mUnk_004;
            c = p[0];
            d = p[1];
            e = p[2];
            f = p[3];
            break;
        }
        case 2:
            d = 0;
            e = 0;
            f = 0;
            c = 0x2108;
            break;
        case 3:
            d = 0;
            e = 0;
            c = 0x2108;
            f = 0x4210;
            break;
        case 1:
            c = 0x7fff;
            d = 0x14a5;
            f = 0x2108;
            e = 0;
            break;
    }
    func_020132cc(a, c);
    func_02013284(a, d);
    func_0201323c(a, e);
    func_020131f4(a, f);
}
