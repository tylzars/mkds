#include "03/code_021c9500.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/code_021bf810.h"
#include "03/code_021c209c.h"
#include "03/code_021c85a0.h"
#include "03/code_021c8e48.h"
#include "03/code_021c2000.h"
#include "03/code_021c9000.h"
#include "03/code_021d1000.h"
#include "03/code_021c91fc.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "03/code_021cc8d4.h"
#include "03/code_021d1c18.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "code_02133048.h"

void func_ov003_021c9500(void) {
    Unk021d7410 a;
    Unk021d73e0 b;
    Unk021d73f8 c;
    a = data_ov003_021d7410;
    b = data_ov003_021d73e0;
    c = data_ov003_021d73f8;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & 0x43) | 0xe18;
    func_ov003_021bf620(data_ov003_021d7460, func_0214c090);
    func_ov003_021bf620(data_ov003_021d7474, func_0214b88c);
    func_ov003_021bf620(data_ov003_021d748c, func_0214b95c);
    func_ov003_021bf620(&b, func_0214c160);
    func_ov003_021bf620(data_ov003_021d74a4, func_0214bbcc);
    data_ov003_021da214->mUnk_08 = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &a), 0, 4);
    func_ov003_021cca30(data_ov003_021da214->mUnk_08);
    func_ov003_021cc9fc();
    data_ov003_021da214->mUnk_0c[0] = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &b), 0, 4);
    data_ov003_021da214->mUnk_0c[1] = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &c), 0, 4);
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & ~0x3) | 0x3;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~0x3) | 0x3;
    *(u16 *) 0x4000008 = (*(u16 *) 0x4000008 & ~0x3) | 0x3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~0x3) | 0x2;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & ~0x3) | 0x3;
    *(u16 *) 0x400000e = (*(u16 *) 0x400000e & ~0x3) | 0x2;
}

void func_ov003_021c965c(void) {
    int a;
    int b;
    int i;
    Unk021da214 *p;
    b = func_ov003_021cdb6c();
    p = func_ov003_021d283c(0x48, 4);
    data_ov003_021da214 = p;
    p->mUnk_43 = *(u8 *) (b + 0xf6);
    data_ov003_021da214->mUnk_42 = 0xc;
    func_ov003_021c94c8();
    func_ov003_021c9500();
    if (*(u8 *) &data_ov003_021da208 == 0) {
        func_ov003_021bf43c(0x7c, data_ov003_021d6434[func_ov003_021c20d0()], *(u8 *) (b + 0xf4) + 1);
    } else {
        func_ov003_021bf43c(0x97, -1, 0);
    }
    func_ov003_021bf5ec(1);
    func_ov003_021bf83c();
    func_ov003_021ccea4(2, 0x55, 0xf1, 0x41, _s32_div_f(*(u16 *) &data_ov003_021da210 * 0x37, 0x91));
    data_ov003_021da214->mUnk_14 = func_ov003_021d2288(0, 1);
    for (i = 0; i < 7; i++) {
        data_ov003_021da214->mUnk_18[i] = func_ov003_021d1c18(0, data_ov003_021d6478[0][1]);
    }
    b += 0xe7;
    switch (*(u8 *) b) {
        case 1:
            data_ov003_021da214->mUnk_34 = func_ov003_021d1c18(0, 0x50);
            data_ov003_021da214->mUnk_34->mUnk_04 = (data_ov003_021da214->mUnk_34->mUnk_04 & ~0xc00) | 0xc00;
            break;
        case 2:
            data_ov003_021da214->mUnk_34 = func_ov003_021d1c18(0, 0x51);
            data_ov003_021da214->mUnk_34->mUnk_04 = (data_ov003_021da214->mUnk_34->mUnk_04 & ~0xc00) | 0xc00;
            break;
    }
    data_ov003_021da214->mUnk_3c = func_ov003_021d3544(1, func_ov003_021c824c, 0, 0x6e);
    data_ov003_021da214->mUnk_00 = func_ov003_021d3544(0, func_ov003_021c7e8c, 0, 0x78);
    func_ov003_021c8b94();
    func_ov003_021c81b8();
    func_ov003_021c212c(func_ov003_021c948c);
}
