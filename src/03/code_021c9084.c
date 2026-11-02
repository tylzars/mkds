#include "03/code_021c9084.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021c7d30.h"
#include "03/code_021c85a0.h"
#include "03/code_021c8e48.h"
#include "03/code_021c209c.h"
#include "03/code_021ccd18.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/unk_021d6000.h"

void func_ov003_021c9084(u32 param_1) {
    Unk021c8a60 *r;
    int a;
    r = (Unk021c8a60 *) func_ov003_021cdb6c();
    if (r->mUnk_f5 != param_1) {
        if (param_1 != 0) {
            if (data_ov003_021da214->mUnk_43 != 0) {
                a = 1;
            } else {
                a = 0;
            }
        } else {
            data_ov003_021da214->mUnk_43 = r->mUnk_f6;
            a = 0;
        }
        func_ov003_021cdb58(param_1);
        func_ov003_021cdb44(a);
        func_ov003_021c8b94();
    }
}

void func_ov003_021c90dc(u32 param_1) {
    if (func_ov003_021c8904(param_1) == 0) {
        func_ov003_021cdc10(9);
        return;
    }
    switch (param_1) {
        case 2:
        case 3:
            func_ov003_021cdc10(6);
            func_ov003_021c9084(((param_1 - 2) ^ 1) != 0);
            return;
        case 7:
        case 8:
            func_ov003_021cdc10(6);
            func_ov003_021c9058(((param_1 - 7) ^ 1) != 0);
            return;
    }
    data_ov003_021da214->mUnk_40 = param_1;
    if (param_1 - 0xb <= 1) {
        func_ov003_021c7ec4();
        if (func_ov003_021c7d8c() == 0) {
            func_ov003_021cdc10(9);
            func_ov003_021cefc0(0x2f, 1, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c7d58);
            return;
        }
        if (param_1 == 0xb) {
            func_ov003_021cdc10(6);
        } else {
            func_ov003_021cdc10(0xe);
        }
    } else if (param_1 == 0xd) {
        func_ov003_021c7ec4();
        func_ov003_021cdc10(7);
    } else {
        func_ov003_021cdc10(6);
        func_ov003_021c8838(0, 1, func_ov003_021c83cc(data_ov003_021d646c[param_1]));
        func_ov003_021c85a0();
    }
    func_ov003_021cce38();
    func_ov003_021c212c(func_ov003_021c8e80);
}
