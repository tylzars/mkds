#include "03/code_021bf344.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d34e0.h"
#include "03/code_021d3544.h"
#include "03/code_021bf098.h"
#include "03/code_021bf0d8.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021be610.h"

void func_ov003_021bf364(u32 param_0) {
    s32 n;
    s32 i;
    u8 *a;
    s32 b;

    n = data_ov003_021d5ecc[param_0];
    data_ov003_021da108 = func_ov003_021d283c(0x1c, 4);
    data_ov003_021da108->mUnk_16 = -2;
    data_ov003_021da108->mUnk_17 = param_0;
    i = 0;
    if (n > 0) {
        a = data_ov003_021d5edc + param_0 * 2;
        b = i;
        do {
            *(u32 *) ((u8 *) data_ov003_021da108 + b) = (u32) func_ov003_021d1be4(0, *a, 1);
            func_ov003_021d1790(*(Unk021d1770 **) ((u8 *) data_ov003_021da108 + b), -1, 1);
            a++;
            b += 4;
            i++;
        } while (i < n);
    }
    data_ov003_021da108->mUnk_08 = (u32) func_ov003_021d1be4(0, 1, 1);
    func_ov003_021d1790((Unk021d1770 *) data_ov003_021da108->mUnk_08, -1, 1);
    func_ov003_021bf258(0xc0);
    data_ov003_021da108->mUnk_0c = (Unk021d34e0 *) func_ov003_021d3544(0, func_ov003_021bf20c, 0, 0x78);
}

void func_ov003_021bf344(void) {
    data_ov003_021da108->mUnk_19 = 1;
    func_ov003_021d34e0(data_ov003_021da108->mUnk_0c, func_ov003_021bf098);
}
