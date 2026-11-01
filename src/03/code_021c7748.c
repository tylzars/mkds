#include "03/code_021c7748.h"

void func_ov003_021c7748(void) {
    Unk021d7310 a;
    u8 b[5];
    s32 c;
    Unk021da1fc *d;
    a = data_ov003_021d7310;
    b[0] = data_ov003_021d7300[0];
    b[1] = data_ov003_021d7300[1];
    b[2] = data_ov003_021d7300[2];
    b[3] = data_ov003_021d7300[3];
    b[4] = data_ov003_021d7300[4];
    data_ov003_021da1fc = func_ov003_021d283c(0x18, 4);
    func_ov003_021c20dc(&c, 0);
    a.mUnk_00[c](data_ov003_021da1fc->mUnk_08);
    d = data_ov003_021da1fc;
    if (func_02134d30(d->mUnk_08, data_ov003_021d73ac, 3) != 0) {
        d->mUnk_14 = 3;
    } else {
        func_0214d168(d->mUnk_08, 0, 0xc);
        data_ov003_021da1fc->mUnk_14 = 0;
    }
    func_ov003_021c76b4();
    func_ov003_021bf86c(c + 0xb);
    func_ov003_021bf43c(b[c], -1, 0);
    func_ov003_021bf5ec(2);
    data_ov003_021da1fc->mUnk_00 = func_ov003_021d2288(0, 0);
    data_ov003_021da1fc->mUnk_04 = (Unk021da1f8_04 *) func_ov003_021d1c18(0, 0x3f);
    data_ov003_021da1fc->mUnk_04->mUnk_04 = (data_ov003_021da1fc->mUnk_04->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021c7160();
    func_ov003_021c71a0();
    func_ov003_021c212c(func_ov003_021c7678);
}
