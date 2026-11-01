#include "03/code_021c8ea0.h"
#include "03/code_021bf698.h"
#include "03/code_021c85a0.h"
#include "03/code_021cce58.h"
#include "03/code_021cce60.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3544.h"
#include "code_02133048.h"
#include "code_02147cd8.h"
#include "03/code_021cdc10.h"

void func_ov003_021c8ea0(void) {
    int a;
    Unk021da214 *s;
    s = data_ov003_021da214;
    if (s->mUnk_38 == 0) {
        if (s->mUnk_41 != 0) {
            s->mUnk_41--;
        }
        switch (func_ov003_021cce60()) {
            case 1:
                data_ov003_021da214->mUnk_45 = 1;
                break;
            case 2:
                if (data_ov003_021da214->mUnk_41 != 0) {
                    return;
                }
                func_ov003_021bf698();
                *(u16 *) &data_ov003_021da210 = _s32_div_f(func_ov003_021cce6c() * 0x91, 0x37);
                func_ov003_021c8b94();
                data_ov003_021da214->mUnk_41 = 4;
                break;
            case 3:
                data_ov003_021da214->mUnk_45 = 0;
                *(u16 *) &data_ov003_021da210 = _s32_div_f(func_ov003_021cce6c() * 0x91, 0x37);
                func_ov003_021cdc10(0x13);
                func_ov003_021c8b94();
                a = func_02147cd8(*(u16 *) &data_ov003_021da210, 0x1d);
                if (a == 0) {
                    func_ov003_021c812c();
                    return;
                }
                if (a < 0x10) {
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, 0, 0x78);
                } else {
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, 0, 0x78);
                }
                break;
            case 4:
                if (*(u16 *) &data_ov003_021da210 == 0) {
                    if (data_ov003_021da214->mUnk_46 != 0) {
                        return;
                    }
                    func_ov003_021cdc10(9);
                    data_ov003_021da214->mUnk_46 = 1;
                } else {
                    func_ov003_021cdc10(0x13);
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, 0, 0x78);
                }
                break;
            case 6:
                if (*(u16 *) &data_ov003_021da210 == 0x91) {
                    if (data_ov003_021da214->mUnk_46 != 0) {
                        return;
                    }
                    func_ov003_021cdc10(9);
                    data_ov003_021da214->mUnk_46 = 1;
                } else {
                    func_ov003_021cdc10(0x13);
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, 0, 0x78);
                }
                break;
            case 5:
            case 7:
                data_ov003_021da214->mUnk_46 = 0;
                break;
        }
    }
}
