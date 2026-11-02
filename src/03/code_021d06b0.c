#include "03/code_021d06b0.h"
#include "03/code_021d0388.h"
#include "03/code_021d0680.h"
#include "03/code_021d079c.h"
#include "03/unk_021da000.h"
#include "code_021453ec.h"
#include "code_02142eac.h"

s32 func_ov003_021d06b0(void) {
    u32 a;
    s32 r;

    func_ov003_021d07b0(3);
    a = data_ov003_021da2a8->mUnk_13ac(data_ov003_021da2a8->mUnk_13c0, data_ov003_021da2a8);
    r = func_02145708((u32) func_ov003_021d0680, a, data_ov003_021da2a8->mUnk_13c0);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(9);
        return 0;
    }
    return 1;
}

void func_ov003_021d0708(Unk021425e8 *v1) {
    if (v1->mUnk_02 != 0) {
        func_ov003_021d079c(v1->mUnk_02);
        func_ov003_021d07b0(9);
        return;
    }
    if (data_ov003_021da2a8->mUnk_13ac != 0) {
        if (func_ov003_021d06b0() == 0) {
            func_ov003_021d07b0(9);
        }
    } else if (func_ov003_021d0630() == 0) {
        func_ov003_021d07b0(9);
    }
}

s32 func_ov003_021d0760(void) {
    s32 r;

    func_ov003_021d07b0(3);
    r = func_02143c80(func_ov003_021d0708, (Unk02143c30 *) data_ov003_021da2a8);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(9);
        return 0;
    }
    return 1;
}
