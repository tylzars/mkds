#include "03/code_021ccc24.h"
#include "03/code_021cca74.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d2940.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_02147cd8.h"

void func_ov003_021ccc24(s32 param_1) {
    s32 a = data_ov003_021da268->mOffset - param_1;
    u32 b;
    u32 c;
    if (a < 0) {
        a = -a;
    }
    if (a < 2) {
        b = 0;
    } else if (a < 6) {
        b = Div32(0x7f, 6 - a);
    } else {
        b = 0x7f;
    }
    func_ov003_021cdbfc(b);
    if (a < 2) {
        c = -0x100;
    } else if (a < 6) {
        c = Div32(0x200, 6 - a) - 0x100;
    } else {
        c = 0x100;
    }
    func_ov003_021cdbe4(0xffff, c);
}

void func_ov003_021ccc90(void) {
    u16 a[2];
    s32 b;
    s32 c;
    if (func_ov003_021d2a80(&data_ov003_021d67e8) != 0) {
        func_ov003_021d2940(a);
        if (a[0] >= data_ov003_021da268->mX - 0x1e) {
            b = data_ov003_021da268->mUnk_18 + (a[1] - data_ov003_021da268->mUnk_14[1]);
            if (b < 0) {
                b = 0;
            } else {
                c = data_ov003_021da268->mUnk_19 - data_ov003_021d6630[data_ov003_021da268->mUnk_1b];
                if (b >= c) {
                    b = c;
                }
            }
            func_ov003_021ccc24(b);
            func_ov003_021cca74(b);
            data_ov003_021da268->mUnk_1d = 2;
            return;
        }
    }
    func_ov003_021cdbd0();
    data_ov003_021da268->mUnk_1c = 0;
    data_ov003_021da268->mUnk_1d = 3;
}
