#include "03/code_021d2070.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d211c.h"
#include "03/unk_021da000.h"
#include "code_02022aa8.h"
#include "code_02023374.h"

void func_ov003_021d2094(void *param_1, s32 param_2, u32 param_3, u32 param_4, s32 param_5, u16 *param_6, s32 param_7) {
    Unk02022aa8 *a;
    u32 b;
    Unk02022c80 *c;
    s32 d;

    while (*param_6 != 0) {
        a = (Unk02022aa8 *) ((*(Unk021d1fd0 **) &data_ov003_021da2c4)->mUnk_000 + param_7 * 12);
        b = func_02022ce4(a, *param_6);
        if (b == 0xffff) {
            b = a->mUnk_00->mUnk_02;
        }
        c = func_02022c80(a, b);
        if (a->mUnk_08 != 0) {
            d = c->mUnk_00 + c->mUnk_01;
        } else {
            d = c->mUnk_02;
        }
        func_ov003_021d211c(param_1, param_2 + ((param_5 - d) >> 1), param_3, param_4, *param_6, param_7);
        param_2 += param_5;
        param_6++;
    }
}

void func_ov003_021d2070(Unk021d2188 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6,
                         u32 param_7, void *param_8) {
    func_0202428c(&param_1->mUnk_20, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
