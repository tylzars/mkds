#include "03/code_021d2d50.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2b3c.h"
#include "03/code_021d2d14.h"
#include "03/code_021d3000.h"
#include "03/unk_021da000.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_0200fd1c.h"
#include "code_0214e308.h"
#include "code_0214e6e4.h"

void func_ov003_021d2d50(void) {
    Unk0214e334 a;

    data_ov003_021da2d4 = func_ov003_021d283c(0x3a, 4);
    if (func_0214eadc(&a) == 0) {
        func_0200fd1c();
    }
    func_0214e994(&a);
    func_0214e788(0, 4, data_ov003_021da2d4->mUnk_00, 5);
    func_0214e31c(2);
    if (func_0214e308(2) != 0) {
        func_0200fd1c();
    }
    func_ov003_021d2d14();
}

void func_ov003_021d2da4(void) {
    func_ov003_021d3558(1);
    *(u32 *) ((u8 *) &data_027e0000 + 0x3ff8) |= 1;
}

void func_ov003_021d2dcc(void) {
    u16 a;

    a = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 0;
    func_0200cb1c(data_ov003_021da2ec);
    func_0200cc74(1, data_ov003_021da2e8);
}

void func_ov003_021d2dfc(void) {
    u16 a;

    data_ov003_021da2ec = *(vu32 *) 0x4000210;
    func_0200cb1c(0x40018);
    func_0200cae4(1);
    data_ov003_021da2e8 = func_0200cbe8(1);
    func_0200cc74(1, func_ov003_021d2da4);
    a = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 1;
    func_0200fc8c();
}
