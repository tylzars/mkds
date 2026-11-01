#include "03/code_021c6e38.h"

void func_ov003_021c6e38(void) {
    u8 a[2];
    s32 b;
    s32 c;
    a[0] = data_ov003_021d7278[0];
    a[1] = data_ov003_021d7278[1];
    data_ov003_021da1f8 = func_ov003_021d283c(0x2c, 4);
    func_ov003_021c20dc(&b, &c);
    if (b == 0) {
        func_ov003_021cd948((u8 *) data_ov003_021da1f8 + 8);
        data_ov003_021da1f8->mUnk_29 = func_ov003_021d3254((u8 *) data_ov003_021da1f8 + 8, 0x20);
    }
    func_ov003_021c6da4();
    func_ov003_021bf86c(b + 9);
    if (c == 1) {
        func_ov003_021bf43c(0x81, -1, 0);
    } else {
        func_ov003_021bf43c(a[b], -1, 0);
    }
    func_ov003_021bf5ec(2);
    data_ov003_021da1f8->mUnk_00 = func_ov003_021d2288(0, 0);
    data_ov003_021da1f8->mUnk_04 = (Unk021da1f8_04 *) func_ov003_021d1c18(0, 0x3e);
    data_ov003_021da1f8->mUnk_04->mUnk_04 = (data_ov003_021da1f8->mUnk_04->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021c6914();
    func_ov003_021c696c();
    func_ov003_021c212c(func_ov003_021c6d68);
}
