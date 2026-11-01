#include "00/code_021a70b0.h"
#include "00/code_021a6d6c.h"
#include "00/code_021a7048.h"
#include "00/code_021a72a4.h"
#include "00/unk_021b5000.h"
#include "code_0200dc3c.h"
#include "code_0200e0ec.h"
#include "Main/Unknown/code_0200edc0.h"

u8 *func_ov000_021a7154(u8 *param_1, Unk021a7154 *param_2, Unk021a72a4 *param_3) {
    u8 *a;

    a = param_1 + func_ov000_021a72a4(param_3);
    func_0200eb90(&param_2->mUnk_00, (void **) param_1, param_3->mUnk_03);
    func_0200edc0(&param_2->mUnk_e0);
    func_0200e28c(&param_2->mUnk_20, func_ov000_021a6f18, param_2, a, param_3->mUnk_00, param_3->mUnk_02);
    func_0200df68(&param_2->mUnk_20);
    return a;
}

s32 func_ov000_021a70ec(s32 param_1) {
    s32 a;
    void **b;
    Unk021a7064 *c;
    s32 d;

    a = (param_1 * 4 + 3) & ~3;
    d = (param_1 * 0x2c + 3) & ~3;
    b = data_ov000_021b5f94->mUnk_18(d + a);
    if (b == 0) {
        return -1;
    }
    func_0200eb90(&data_ov000_021b5fdc, b, param_1);
    c = (Unk021a7064 *) ((u8 *) b + a);
    if (param_1 > 0) {
        do {
            func_ov000_021a7048(c);
            c++;
            param_1--;
        } while (param_1 > 0);
    }
    data_ov000_021b5fd8 = b;
    return 0;
}

s32 func_ov000_021a70b0(void) {
    if (data_ov000_021b5fdc.mUnk_1c < data_ov000_021b5fdc.mUnk_14) {
        return -1;
    }
    data_ov000_021b5f94->mUnk_1c(data_ov000_021b5fd8);
    data_ov000_021b5fd8 = 0;
    return 0;
}
