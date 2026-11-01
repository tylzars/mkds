#include "03/code_021c6ba0.h"

void func_ov003_021c6ba0(void) {
    int a;
    Unk021da1f8 *b;
    a = func_ov003_021c0ce4();
    switch (a) {
        case 0x80:
            b = data_ov003_021da1f8;
            if (b->mUnk_29 != 0) {
                func_ov003_021cdc10(3);
                b = data_ov003_021da1f8;
                b->mUnk_29 = b->mUnk_29 - 1;
                b = data_ov003_021da1f8;
                b->mUnk_08[b->mUnk_29] = 0;
                if (data_ov003_021da1f8->mUnk_29 == 0) {
                    func_ov003_021c0cd0(0);
                }
                func_ov003_021c0cbc(1);
            }
            break;
        case 0x82:
            func_ov003_021cdc10(7);
            data_ov003_021da1f8->mUnk_2a = 0;
            func_ov003_021c212c(func_ov003_021c6b80);
            return;
        case 0x83:
            if (func_ov003_021c6764() != 0) {
                func_ov003_021cdc10(6);
                data_ov003_021da1f8->mUnk_2a = 1;
            } else {
                data_ov003_021da1f8->mUnk_2a = 2;
                func_ov003_021cdc10(9);
            }
            data_ov003_021da1f8->mUnk_04->mUnk_00 = (data_ov003_021da1f8->mUnk_04->mUnk_00 & 0xc1fffcff) | 0x200;
            func_ov003_021c212c(func_ov003_021c6b80);
            return;
        case 0:
            break;
        case 0xe01d:
        default:
            b = data_ov003_021da1f8;
            if (b->mUnk_29 != 0x20) {
                func_ov003_021cdc10(1);
                b = data_ov003_021da1f8;
                b->mUnk_08[b->mUnk_29] = a;
                b = data_ov003_021da1f8;
                b->mUnk_29 = b->mUnk_29 + 1;
                func_ov003_021c0cd0(1);
                if (data_ov003_021da1f8->mUnk_29 == 0x20) {
                    func_ov003_021c0cbc(0);
                }
            }
            break;
    }
    func_ov003_021c696c();
    func_ov003_021c6914();
}
